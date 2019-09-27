class CharSelect : UIScriptedMenu {
	ref Widget m_Root;
	ref PlayerPreviewWidget m_PlayerPreviewWidget;
	ref ImageWidget m_Background;
	ref ImageWidget m_Logo;
	ref array<ref ButtonWidget> m_SurvivorButtons;
	ref array<ref SavePlayer> m_Loadouts;
	ref ButtonWidget btn_Spawn;
	DayZPlayer m_DummyPlayer;
	const int maxHealth = 100;
	const int maxBlood = 5000;
	const int maxWater = 5000;
	const int maxEnergy = 20000;
	float x = 0.012;
	float y = 0.21;
	int screenW, screenH, screenX, screenY;
	//DayZPlayer m_DummyPlayer;
	bool m_ChoiceNCC;

	override Widget Init() {
		m_SurvivorButtons = new array<ref ButtonWidget>();
		m_Loadouts = new array<ref SavePlayer>();

		m_Root = GetGame().GetWorkspace().CreateWidgets("MultiCharacters\\scripts\\layouts\\charSelect.layout");
		m_Root.Show(false);

		m_PlayerPreviewWidget = PlayerPreviewWidget.Cast(m_Root.FindAnyWidget("plyPreview"));
		m_Background = ImageWidget.Cast(m_Root.FindAnyWidget("Background"));
		btn_Spawn = ButtonWidget.Cast(m_Root.FindAnyWidget("btnSpawn"));

		m_Logo = ImageWidget.Cast(m_Root.FindAnyWidget("imgLogo"));
		m_Logo.LoadImageFile(0, "set:bastionmulticharacters image:toplogo");

		//g_Game.PreloadObject("SurvivorF_Linda", 500.0);
		//m_DummyPlayer = DayZPlayer.Cast(GetGame().CreateObject("SurvivorF_Linda", "0 0 0", true, false));
		//m_PlayerPreviewWidget.SetPlayer(m_DummyPlayer);

		return m_Root;
	}

	override void OnShow() {
		GetGame().GetUIManager().ShowUICursor(true);
		GetGame().GetUIManager().ShowCursor(true);
		GetGame().GetInput().ChangeGameFocus(1);
        GetGame().GetMission().GetHud().Show( false );

		m_Loadouts = g_Game.GetLoadouts();
		GetScreenSize(screenW, screenH);
		BuildMenu();
		CheckWhitelisted();

		//GetGame().GetCallQueue(CALL_CATEGORY_GUI).CallLater(SetPlayerWidget, 500, false);
	}

	override void OnHide() {
		GetGame().GetInput().ResetGameFocus();
        GetGame().GetMission().GetHud().Show( true );
		ResetValues();
	}

	void ResetValues() {
		m_Loadouts = null;
		m_SurvivorButtons = null;
		x = 0.012;
		y = 0.21;
	}

	void SetImages(Widget localPnl, bool isNew = false) {
		ImageWidget localImg;

		if (isNew) {
			localImg = localPnl.FindAnyWidget("imgNewCiv");
			localImg.LoadImageFile(0, "set:bastionmulticharacters image:plus");
		} else {
			localImg = localPnl.FindAnyWidget("imgHealth");
			localImg.LoadImageFile(0, "set:bastionmulticharacters image:health");

			localImg = localPnl.FindAnyWidget("imgBlood");
			localImg.LoadImageFile(0, "set:bastionmulticharacters image:blood");

			localImg = localPnl.FindAnyWidget("imgWater");
			localImg.LoadImageFile(0, "set:bastionmulticharacters image:water");

			localImg = localPnl.FindAnyWidget("imgEnergy");
			localImg.LoadImageFile(0, "set:bastionmulticharacters image:food");

		}
	}

	void SetStats(Widget localPnl, SavePlayer player) {
		TextWidget localTxt;

		int percentHealth = (player.GetHealth()*100)/maxHealth;
		int percentBlood = (player.GetBlood()*100)/maxBlood;
		int percentWater = (player.GetWater()*100)/maxWater;
		int percentEnergy = (player.GetEnergy()*100)/maxEnergy;

		localTxt = localPnl.FindAnyWidget("txtHealth");
		localTxt.SetText(percentHealth.ToString() + "%");

		localTxt = localPnl.FindAnyWidget("txtBlood");
		localTxt.SetText(percentBlood.ToString() + "%");

		localTxt = localPnl.FindAnyWidget("txtWater");
		localTxt.SetText(percentWater.ToString() + "%");

		localTxt = localPnl.FindAnyWidget("txtEnergy");
		localTxt.SetText(percentEnergy.ToString() + "%");
	}

	void SetPos(Widget localPnl) {
		screenX = screenW * x;
		screenY = screenH * y;
		localPnl.SetPos(screenX, screenY);
		y += 0.09;
	}

	void BuildMenu() {
		Widget localWidget;
		ButtonWidget localButton;
		TextWidget localTxt;

		for (int i = 0; i < 5; i++) {
			SavePlayer player;

			for (int j = 0; j < m_Loadouts.Count(); j++) {
				if (m_Loadouts[j].GetIndex() == i) {
					player = m_Loadouts[j];
					break;
				}
			}

			if(!player) {
				localWidget = GetGame().GetWorkspace().CreateWidgets("MultiCharacters\\scripts\\layouts\\pnlNewSurvivor.layout", m_Root);
				SetPos(localWidget);
				SetImages(localWidget, true);

				localButton = localWidget.FindAnyWidget("btnNewCiv");
				m_SurvivorButtons.Insert(localButton);
				continue;
			}

			localWidget = GetGame().GetWorkspace().CreateWidgets("MultiCharacters\\scripts\\layouts\\pnlSurvivor.layout", m_Root);
			SetImages(localWidget);
			SetPos(localWidget);
			SetStats(localWidget, player);

			localTxt = localWidget.FindAnyWidget("txtSurvivor");
			localTxt.SetText("Survivor " + (i + 1));

			localButton = localWidget.FindAnyWidget("btnSelect");
			m_SurvivorButtons.Insert(localButton);
		}
	}

	void CheckWhitelisted() {
		Widget localWidget;
		ButtonWidget localButton;
		TextWidget localTxt;
		SavePlayer player;

		if (!g_Game.IsWhitelisted()) return;

		for (int i = 0; i < m_Loadouts.Count(); i++) {
			if (m_Loadouts[i].GetIndex() == 5) {
				player = m_Loadouts[i];
				break;
			}
		}

		if(!player) {
			localWidget = GetGame().GetWorkspace().CreateWidgets("MultiCharacters\\scripts\\layouts\\pnlNewSurvivor.layout", m_Root);
			SetPos(localWidget);
			SetImages(localWidget, true);

			localButton = localWidget.FindAnyWidget("btnNewCiv");
			m_SurvivorButtons.Insert(localButton);
			return;
		}

		localWidget = GetGame().GetWorkspace().CreateWidgets("MultiCharacters\\scripts\\layouts\\pnlSurvivor.layout", m_Root);
		SetImages(localWidget);
		SetPos(localWidget);
		SetStats(localWidget, player);

		localTxt = localWidget.FindAnyWidget("txtSurvivor");
		localTxt.SetText("NCC Survivor");

		localButton = localWidget.FindAnyWidget("btnSelect");
		m_SurvivorButtons.Insert(localButton);
	}

	/* 	void SetPlayerWidget() {
			m_PlayerPreviewWidget.SetPlayer(m_DummyPlayer);
			m_PlayerPreviewWidget.SetModelPosition("0 0 0.605");
		} */

	override bool OnClick(Widget w, int x, int y, int button) {
		super.OnClick(w, x, y, button);

		if (button == MouseState.LEFT) {
			if (w) {
				int i;

				if (m_SurvivorButtons.Find(w) > -1) {
					w.GetParent().SetColor(ARGBF(1, 1, 0, 0));
					for (i = 0; i < m_SurvivorButtons.Count(); i++) {
						if (m_SurvivorButtons[i] == w) continue;

						m_SurvivorButtons[i].SetState(false);
						m_SurvivorButtons[i].GetParent().SetColor(ARGBF(1, 1, 1, 1));
					}
				} else if (w == btn_Spawn) {
					SavePlayer selectedPlayer = null;
					int btnSelected = -1;

					for (i = 0; i < m_SurvivorButtons.Count(); i++) {
						if (m_SurvivorButtons[i].GetState()) {
							btnSelected = i;
							Print("Button selected found | " + i);
							break;
						}
					}

					if (btnSelected > -1) {
						Print("Button selected | " + btnSelected);
						g_Game.SetBtnSelected(btnSelected);
						g_Game.ShowCountDown();
						g_Game.GetUIManager().HideScriptedMenu(this);
					}
				}
			}

			return true;
		}
		return false;
	}

	void UpdateScale() { }
}