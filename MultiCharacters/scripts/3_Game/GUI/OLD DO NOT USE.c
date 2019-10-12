/* class DONOTUSE : UIScriptedMenu {
    protected ref Widget widgetRoot;
	protected Camera camera;
	protected string selectedSurvivor;

	void CharSelect() {
		arrayPlayerPreview = new array<ref PlayerPreviewWidget>();
		arrayDummyPlayers = new array<DayZPlayer>();
		arraySurvivorString = GetGame().ListAvailableCharacters();

		GetGame().ObjectDelete( camera );
		camera = Camera.Cast(g_Game.CreateObject("staticcamera", vector.Zero, true));
		camera.SetActive(true);
	}

	override Widget Init() {
		widgetRoot = GetGame().GetWorkspace().CreateWidgets("MultiCharacters\\scripts\\layouts\\charSelect.layout");
		widgetRoot.Show(false);
        widgetGrid = widgetRoot.FindAnyWidget("spacer");
		widgetPlayerPreview = widgetRoot.FindAnyWidget("playerPreview");

        for (int i = 0; i < arraySurvivorString.Count(); i++) {
            Widget SurvivorWidget = GetGame().GetWorkspace().CreateWidgets("MultiCharacters\\scripts\\layouts\\SurvivorWidget.layout");
			PlayerPreviewWidget preview = PlayerPreviewWidget.Cast(SurvivorWidget.FindAnyWidget("survivorPreview"));
			Object localDummy = GetGame().CreateObject(arraySurvivorString[i], vector.Zero, true);

			preview.SetPlayer(localDummy);
            widgetGrid.AddChild(SurvivorWidget);
			arrayPlayerPreview.Insert(preview);
			arrayDummyPlayers.Insert(localDummy);
        }

		return widgetRoot;
	}

	void DeleteDummies() {
		for (int i = 0; i < arrayDummyPlayers.Count(); i++) {
			g_Game.ObjectDelete(arrayDummyPlayers[i]);
		}
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
		DeleteDummies();
	}

	bool OnClick(Widget w, int x, int y, int button) {
		super.OnClick(w, x, y, button);

		if (button == MouseState.LEFT) {
			if (w.GetName() == "btnSpawn") {
				if (selectedSurvivor != "") {
					g_Game.GetUIManager().HideScriptedMenu(this);
					g_Game.SetSelectedSurvivor(selectedSurvivor);
					g_Game.ContinueSpawn();
					return true;
				}
			}
		}
		return false;
	}

	override bool OnMouseButtonUp(Widget w, int x, int y, int button) {
		PlayerPreviewWidget localPlayerPreview;
		Widget child;

		super.OnClick(w, x, y, button);
		if (button == MouseState.LEFT) {
			if (Class.CastTo(localPlayerPreview, w)) {
				child = localPlayerPreview.GetChildren();

				if (child.GetColor() == -1426128896) {return true;}

				selectedSurvivor = localPlayerPreview.GetDummyPlayer().GetType();
				child.SetColor(ARGBF(0.6667, 1, 0, 0));

				if (arrayPlayerPreview.Find(localPlayerPreview) > -1) {

					for (int i = 0; i < arrayPlayerPreview.Count(); i++) {
						if (arrayPlayerPreview[i] == localPlayerPreview) {
							widgetPlayerPreview.SetPlayer(arrayDummyPlayers[i]);
							continue;
						}
						child = arrayPlayerPreview[i].GetChildren();
						child.Show(false);
						child.SetColor(ARGBF(0.6667, 0.3333, 0.3333, 0.3333));
					}
				}
			}
			return true;
		}
		return false;
	}

	override bool OnMouseEnter(Widget w, int x, int y) {
		PlayerPreviewWidget localPlayerPreview;
		Widget child;
		
		if (Class.CastTo(localPlayerPreview, w)) {
			child = w.GetChildren();

			if (child.GetColor() == -1426128896) {return true;}

			child.Show(true);
			return true;
		}
		return false;
	}

	override bool OnMouseLeave(Widget w, Widget enterW, int x, int y) {
		PlayerPreviewWidget localPlayerPreview;
		Widget child;
		
		if (Class.CastTo(localPlayerPreview, w)) {
			child = w.GetChildren();

			if (child.GetColor() == -1426128896) {return true;}

			child.Show(false);
			return true;
		}
		return false;
	}
} */