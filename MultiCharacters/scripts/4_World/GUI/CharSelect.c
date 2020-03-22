/* class CharSelect : UIScriptedMenu {
	// Globals
	private ref Widget widgetRoot;
	private ref Widget widgetCharSelect;
	private ref Widget widgetCharCreation;
	private ref ImageWidget bstLogo;
	private Camera playerCamera;
	private const int maxHealth = 100;
	private const int maxBlood = 5000;
	private const int maxWater = 5000;
	private const int maxEnergy = 20000;
	private float x, y;
	private int screenW, screenH, screenX, screenY;

	// Character Creation variables
	private ref Widget widgetSpawnPanelCC;
    private ref GridSpacerWidget widgetGridCC;
	private ref PlayerPreviewWidget widgetPlayerPreviewCC;
	private ref array<ref PlayerPreviewWidget> arrayPlayerPreviewCC;
	private ref array<DayZPlayer> arrayDummyPlayersCC;
	private ref array<string> arraySurvivorTypesCC;
	private string selectedSurvivor;

	// Character Selection Variables
	private ref array<ref ButtonWidget> survivorButtonsCS;
	private ref array<ref SavePlayer> savePlayerArrayCS;
	private ref map<int, DayZPlayer> survivorMapCS;
	private ref array<DayZPlayer> survivorArrayCS;
	private ref Widget widgetPlayerPreviewFrameCS;
	private ref GridSpacerWidget gridPnlSurvivorCS;
	private ref PlayerPreviewWidget widgetPlayerPreviewCS;
	private int btnSelectedCS = -1;

	void CharSelect() {
		// Globals
		x = 0.012;
		y = 0.21;

		// Character Selection Initalization
		survivorButtonsCS = new array<ref ButtonWidget>();
		savePlayerArrayCS = new array<ref SavePlayer>();
		survivorMapCS = new map<int, DayZPlayer>();

		// Character Creation Initalization
		arraySurvivorTypesCC = GetGame().ListAvailableCharacters();
		arrayPlayerPreviewCC = new array<ref PlayerPreviewWidget>();
		arrayDummyPlayersCC = new array<DayZPlayer>();

	}

	void ~CharSelect() {
		if (survivorMapCS) {
			Cleanup();
		}
	}

	override Widget Init() {
		widgetRoot = GetGame().GetWorkspace().CreateWidgets("MultiCharacters\\gui\\layouts\\CharSelect.layout");
		widgetCharSelect = widgetRoot.FindAnyWidget("charSelectFrame");
		widgetCharCreation = widgetRoot.FindAnyWidget("charCreateFrame");
		bstLogo = ImageWidget.Cast(widgetRoot.FindAnyWidget("imgLogo"));
		bstLogo.LoadImageFile(0, "set:bastionmulticharacters image:toplogo");

		// Char Selection Widgets
		widgetPlayerPreviewFrameCS = widgetCharSelect.FindAnyWidget("charFrame");
		widgetPlayerPreviewCS = PlayerPreviewWidget.Cast(widgetCharSelect.FindAnyWidget("plyPreview"));
		gridPnlSurvivorCS = widgetCharSelect.FindAnyWidget("gridPnlSurvivor");

		// Char Creation Widget
		widgetGridCC = widgetCharCreation.FindAnyWidget("spacer");
		widgetPlayerPreviewCC = widgetCharCreation.FindAnyWidget("playerPreview");
		widgetSpawnPanelCC = widgetCharCreation.FindAnyWidget("pnlCreateSpawn");

		savePlayerArrayCS = g_Game.GetLoadouts();
		GetScreenSize(screenW, screenH);
		BuildCSMenu(gridPnlSurvivorCS, survivorButtonsCS);
		BuildCCMenu();
		InitCamera();
		InitsurvivorMapCS();

		widgetRoot.Show(false);
		widgetCharSelect.Show(true);
		widgetPlayerPreviewFrameCS.Show(false);
		return widgetRoot;
	}

	void BuildCSMenu(GridSpacerWidget widget, array<ref ButtonWidget> buttons) {
		Widget localWidget;
		ButtonWidget localButton;
		TextWidget localTxt;

		for (int i = 0; i < 5; i++) {
			SavePlayer player;

			for (int j = 0; j < savePlayerArrayCS.Count(); j++) {
				if (savePlayerArrayCS[j].GetIndex() == i) {
					player = savePlayerArrayCS[j];
					break;
				}
			}

			if (!player) {
				localWidget = GetGame().GetWorkspace().CreateWidgets("MultiCharacters\\gui\\layouts\\pnlNewSurvivor.layout", widgetCharSelect);
				localButton = ButtonWidget.Cast(localWidget.FindAnyWidget("btnNewCiv"));

				SetImages(localWidget, true);
			} else {
				localWidget = GetGame().GetWorkspace().CreateWidgets("MultiCharacters\\gui\\layouts\\pnlSurvivor.layout", widgetCharSelect);
				localTxt = TextWidget.Cast(localWidget.FindAnyWidget("txtSurvivor"));
				localTxt.SetText("Survivor " + (i + 1));
				localButton = ButtonWidget.Cast(localWidget.FindAnyWidget("btnSelect"));

				SetImages(localWidget);
				SetStats(localWidget, player);
			}
			buttons.Insert(localButton);
			widget.AddChild(localWidget);
		}
	}

	void BuildCCMenu() {
        for (int i = 0; i < arraySurvivorTypesCC.Count(); i++) {
            Widget SurvivorWidget = GetGame().GetWorkspace().CreateWidgets("MultiCharacters\\gui\\layouts\\SurvivorWidget.layout");
			PlayerPreviewWidget preview = PlayerPreviewWidget.Cast(SurvivorWidget.FindAnyWidget("survivorPreview"));
			Object localDummy = GetGame().CreateObject(arraySurvivorTypesCC[i], vector.Zero, true);

			preview.SetPlayer(localDummy);
            widgetGridCC.AddChild(SurvivorWidget);
			arrayPlayerPreviewCC.Insert(preview);
			arrayDummyPlayersCC.Insert(localDummy);
        }
	}

	void ResetCCMenu() {
		widgetPlayerPreviewCC.Show(false);
		widgetSpawnPanelCC.Show(false);

		for (int i = 0; i < arrayPlayerPreviewCC.Count(); i++) {
			Widget child;
			child = arrayPlayerPreviewCC[i].GetChildren();
			child.Show(false);
			child.SetColor(ARGBF(0.6667, 0.3333, 0.3333, 0.3333));
		}
	}

	void InitCamera() {
		GetGame().ObjectDelete( playerCamera );
		playerCamera = Camera.Cast(g_Game.CreateObject("staticcamera", vector.Zero, true));
		playerCamera.SetActive(true);
	}

	void InitsurvivorMapCS() {
		for (int i = 0; i < savePlayerArrayCS.Count(); i++) {
			DayZPlayer localSurvivor;
			SavePlayer localSavePlayer = savePlayerArrayCS[i];

			localSurvivor = DayZPlayer.Cast(GetGame().CreateObject(localSavePlayer.GetType(), vector.Zero, true));
			survivorMapCS.Insert(localSavePlayer.GetIndex(), localSurvivor);
			CreateSurvivorInventory(localSurvivor, localSavePlayer);
		}
	}

	void CreateSurvivorInventory(DayZPlayer survivor, SavePlayer savePlayer) {
		array<ref SaveObject> inventoryArray = savePlayer.GetInventory();

		for (int i = 0; i < inventoryArray.Count(); i++) {
			SaveObject localSaveObject = inventoryArray[i];
			string objectType = localSaveObject.GetType();
			
			survivor.GetHumanInventory().CreateInInventory(objectType);

			/* if (localSaveObject.IsInHands()) {
				Print(MCConst.debugPrefix + "Object in hands");
				EntityAI objectInHands = survivor.GetHumanInventory().CreateInHands(objectType);
			} else {
				survivor.GetHumanInventory().CreateInInventory(objectType);
			}
		}
	}

	void Cleanup() {
		Object survivor;
		int i;

		Print(MCConst.debugPrefix + "Deleting all dummy players");
		if (arrayDummyPlayersCC) {
			Print(MCConst.debugPrefix + "Deleting CC dummies");
			for(i = 0; i < arrayDummyPlayersCC.Count(); i++) {
				survivor = arrayDummyPlayersCC[i];
				GetGame().ObjectDelete(survivor);
				GetGame().ObjectRelease(survivor);
			}
		}

		if (survivorMapCS) {
			Print(MCConst.debugPrefix + "Deleting CS dummies");
			survivorArrayCS = survivorMapCS.GetValueArray();
			
			for (i = 0; i < survivorArrayCS.Count(); i++) {
				survivor = survivorArrayCS[i];
				GetGame().ObjectDelete(survivor);
				GetGame().ObjectRelease(survivor);
			}
		}

		if (arrayPlayerPreviewCC) {
			Print(MCConst.debugPrefix + "Unlinking New Survivor Buttons");

			for (i = 0; i < arrayPlayerPreviewCC.Count(); i++) {
				arrayPlayerPreviewCC[i].Unlink();
			}
		}

		if (survivorButtonsCS) {
			Print(MCConst.debugPrefix + "Unlinking Survivor Buttons");

			for (i = 0; i < survivorButtonsCS.Count(); i++) {
				survivorButtonsCS[i].Unlink();
			}
		}
		
		widgetGridCC.Unlink();
		widgetCharCreation.Unlink();
		widgetCharSelect.Unlink();

		delete survivorArrayCS;
		delete survivorMapCS;
		delete savePlayerArrayCS;
		delete survivorButtonsCS;

		delete arrayPlayerPreviewCC;
		delete arrayDummyPlayersCC;
		delete arraySurvivorTypesCC;
	}

	override void OnShow() {
		GetGame().GetUIManager().ShowUICursor(true);
		GetGame().GetUIManager().ShowCursor(true);
		GetGame().GetInput().ChangeGameFocus(1);
		GetGame().GetMission().GetHud().Show(false);
	}

	override void OnHide() {
		GetGame().GetInput().ResetGameFocus();
		GetGame().GetMission().GetHud().Show(true);
		if (survivorMapCS) {
			Cleanup();
		}
	}

	void SetImages(Widget localPnl, bool isNew = false) {
		ImageWidget localImg;

		if (isNew) {
			localImg = ImageWidget.Cast(localPnl.FindAnyWidget("imgNewCiv"));
			localImg.LoadImageFile(0, "set:bastionmulticharacters image:plus");
		} else {
			localImg = ImageWidget.Cast(localPnl.FindAnyWidget("imgHealth"));
			localImg.LoadImageFile(0, "set:bastionmulticharacters image:health");

			localImg = ImageWidget.Cast(localPnl.FindAnyWidget("imgBlood"));
			localImg.LoadImageFile(0, "set:bastionmulticharacters image:blood");

			localImg = ImageWidget.Cast(localPnl.FindAnyWidget("imgWater"));
			localImg.LoadImageFile(0, "set:bastionmulticharacters image:water");

			localImg = ImageWidget.Cast(localPnl.FindAnyWidget("imgEnergy"));
			localImg.LoadImageFile(0, "set:bastionmulticharacters image:food");

		}
	}

	void SetStats(Widget localPnl, SavePlayer player) {
		TextWidget localTxt;

		int percentHealth = (player.GetHealth() * 100) / maxHealth;
		int percentBlood = (player.GetBlood() * 100) / maxBlood;
		int percentWater = (player.GetWater() * 100) / maxWater;
		int percentEnergy = (player.GetEnergy() * 100) / maxEnergy;

		localTxt = TextWidget.Cast(localPnl.FindAnyWidget("txtHealth"));
		localTxt.SetText(percentHealth.ToString() + "%");

		localTxt = TextWidget.Cast(localPnl.FindAnyWidget("txtBlood"));
		localTxt.SetText(percentBlood.ToString() + "%");

		localTxt = TextWidget.Cast(localPnl.FindAnyWidget("txtWater"));
		localTxt.SetText(percentWater.ToString() + "%");

		localTxt = TextWidget.Cast(localPnl.FindAnyWidget("txtEnergy"));
		localTxt.SetText(percentEnergy.ToString() + "%");
	}

	override bool OnClick(Widget w, int x, int y, int button) {
		super.OnClick(w, x, y, button);

		if (button == MouseState.LEFT) {
			if (w) {
				DayZPlayer localSurvivor;
				int i;
				
				if (survivorButtonsCS.Find(w) > -1) {
					w.GetParent().SetColor(ARGBF(1, 1, 0, 0));
					for (i = 0; i < survivorButtonsCS.Count(); i++) {
						if (survivorButtonsCS[i] == w) {
							btnSelectedCS = i;
							if (survivorMapCS.Find(i, localSurvivor)) {
								widgetPlayerPreviewCS.SetPlayer(localSurvivor);
								widgetPlayerPreviewFrameCS.Show(true);
							} else {
								survivorButtonsCS[i].SetState(false);
								survivorButtonsCS[i].GetParent().SetColor(ARGBF(1, 1, 1, 1));
								widgetPlayerPreviewFrameCS.Show(false);
								widgetCharSelect.Show(false);
								widgetCharCreation.Show(true);
							}
							continue;
						}

						survivorButtonsCS[i].SetState(false);
						survivorButtonsCS[i].GetParent().SetColor(ARGBF(1, 1, 1, 1));
					}
				} else if (w.GetName() == "btnSelectSpawn" || w.GetName() == "btnCreateSpawn") {
					SavePlayer selectedPlayer = null;

					if (btnSelectedCS > -1) {
						Print(MCConst.debugPrefix + "Button selected | " + btnSelectedCS);
						g_Game.SetSurvivorIndex(btnSelectedCS);
						g_Game.SetSelectedSurvivor(selectedSurvivor);
						g_Game.ShowCountDown();
						g_Game.GetUIManager().HideScriptedMenu(this);
					}
				}
			}
			return true;
		}
		return false;
	}

	override bool OnMouseButtonUp(Widget w, int x, int y, int button) {
		if (widgetCharCreation.IsVisible()) {
			OnMouseButtonUpCC(w, button);
			return true;
		}
		return false;
	}

	override bool OnMouseEnter(Widget w, int x, int y) {
		if (widgetCharCreation.IsVisible()) {
			OnMouseEnterCC(w);
			return true;
		}
		return false;
	}

	override bool OnMouseLeave(Widget w, Widget enterW, int x, int y) {
		if (widgetCharCreation.IsVisible()) {
			OnMouseLeaveCC(w);
			return true;
		}
		return false;
	}

	void OnMouseButtonUpCC(Widget w, int button) {
		PlayerPreviewWidget localPlayerPreview;
		Widget child;

		super.OnClick(w, x, y, button);
		if (button == MouseState.LEFT) {
			if (Class.CastTo(localPlayerPreview, w)) {
				if (!widgetSpawnPanelCC.IsVisible()) {
					widgetSpawnPanelCC.Show(true);
				}

				child = localPlayerPreview.GetChildren();

				if (child.GetColor() == -1426128896) {return;}

				selectedSurvivor = localPlayerPreview.GetDummyPlayer().GetType();
				child.SetColor(ARGBF(0.6667, 1, 0, 0));

				if (arrayPlayerPreviewCC.Find(localPlayerPreview) > -1) {

					for (int i = 0; i < arrayPlayerPreviewCC.Count(); i++) {
						if (arrayPlayerPreviewCC[i] == localPlayerPreview) {
							if (!widgetPlayerPreviewCC.IsVisible()) {
								widgetPlayerPreviewCC.Show(true);
							}
							widgetPlayerPreviewCC.SetPlayer(arrayDummyPlayersCC[i]);
							continue;
						}
						child = arrayPlayerPreviewCC[i].GetChildren();
						child.Show(false);
						child.SetColor(ARGBF(0.6667, 0.3333, 0.3333, 0.3333));
					}
				}
			} else if (w.GetName() == "previousMenu") {
				w.SetColor(ARGBF(1, 1, 1, 0.086));
				widgetCharSelect.Show(true);
				widgetCharCreation.Show(false);
				ResetCCMenu();
			}
		}
	}

	void OnMouseEnterCC(Widget w) {
		PlayerPreviewWidget localPlayerPreview;
		Widget child;
		
		if (Class.CastTo(localPlayerPreview, w)) {
			child = w.GetChildren();

			if (child.GetColor() == -1426128896) {return;}

			child.Show(true);
		} else if (w.GetName() == "previousMenu") {
			w.SetColor(ARGBF(1, 0.839, 0.851, 0.071));
		}
	}

	void OnMouseLeaveCC(Widget w) {
		PlayerPreviewWidget localPlayerPreview;
		Widget child;
		
		if (Class.CastTo(localPlayerPreview, w)) {
			child = w.GetChildren();

			if (child.GetColor() == -1426128896) {return;}

			child.Show(false);
		} else if (w.GetName() == "previousMenu") {
			w.SetColor(ARGBF(1, 1, 1, 0.086));
		}
	}
} */