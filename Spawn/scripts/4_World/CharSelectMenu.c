class CharSelect : UIScriptedMenu {
	ref Widget m_Root;
	ref PlayerPreviewWidget m_PlayerPreviewWidget;
	ref ImageWidget m_Background;
	ref ImageWidget m_Logo;
	ref array<ref ButtonWidget> m_SurvivorButtons;
	ref array<ref SavePlayer> m_Loadouts;
	ref ButtonWidget btn_Spawn;
	const int maxHealth = 100;
	const int maxBlood = 5000;
	const int maxWater = 5000;
	const int maxEnergy = 20000;
	//DayZPlayer m_DummyPlayer;
	bool m_ChoiceNCC;

	override Widget Init() {
		m_SurvivorButtons = new array<ref ButtonWidget>();
		m_Loadouts = new array<ref SavePlayer>();

		m_Root = GetGame().GetWorkspace().CreateWidgets("Spawn\\scripts\\layouts\\charSelect.layout");
		m_Root.Show(false);

		m_PlayerPreviewWidget = PlayerPreviewWidget.Cast(m_Root.FindAnyWidget("CharacterPanelWidget"));
		m_Background = ImageWidget.Cast(m_Root.FindAnyWidget("Background"));
		btn_Spawn = ButtonWidget.Cast(m_Root.FindAnyWidget("btnSpawn"));

		m_Logo = ImageWidget.Cast(m_Root.FindAnyWidget("imgLogo"));
		m_Logo.LoadImageFile(0, "set:bastionmulticharacters image:toplogo");

		/* 	g_Game.PreloadObject("SurvivorM_Mirek", 1000.0);
			m_DummyPlayer = PlayerBase.Cast(GetGame().CreateObject("SurvivorM_Mirek", "0 0 0", true, false));
			m_DummyPlayer.PlaceOnSurface(); */

		return m_Root;
	}

	override void OnShow() {
		GetGame().GetUIManager().ShowUICursor(true);
		GetGame().GetUIManager().ShowCursor(true);
		GetGame().GetInput().ChangeGameFocus(1);

		m_Loadouts = g_Game.GetLoadouts();
		SetImages();
		SetText();

		//GetGame().GetCallQueue(CALL_CATEGORY_GUI).CallLater(SetPlayerWidget, 500, false);
	}

	override void OnHide() {
		GetGame().GetInput().ResetGameFocus();
	}

	void SetImages() {
		ImageWidget localImg;
		int i;
		for (i = 0; i < 5; i++) {
			localImg = m_Root.FindAnyWidget("imgHealth" + i);
			localImg.LoadImageFile(0, "set:bastionmulticharacters image:health");

			localImg = m_Root.FindAnyWidget("imgBlood" + i);
			localImg.LoadImageFile(0, "set:bastionmulticharacters image:blood");

			localImg = m_Root.FindAnyWidget("imgWater" + i);
			localImg.LoadImageFile(0, "set:bastionmulticharacters image:water");

			localImg = m_Root.FindAnyWidget("imgEnergy" + i);
			localImg.LoadImageFile(0, "set:bastionmulticharacters image:food");

			localImg = m_Root.FindAnyWidget("imgNewCiv" + i);
			localImg.LoadImageFile(0, "set:bastionmulticharacters image:plus");
		}
	}

	void SetText() {
		Widget localWidget;
		RichTextWidget localTxt;
		ButtonWidget localButton;

		for (int i = 0; i < 5; i++) {
			SavePlayer player;

			for (int j = 0; j < m_Loadouts.Count(); j++)
			{
				if (m_Loadouts[j].GetIndex() == i)
				{
					player = m_Loadouts[j];
					break;
				}
			}

			if(!player || player.IsDead())
			{
				localButton = m_Root.FindAnyWidget("btnNewCiv" + i);
				m_SurvivorButtons.Insert(localButton);

				localWidget = m_Root.FindAnyWidget("pnlNewCiv" + i);
				localWidget.Show(true);
				Print("Player not found!");
				continue;
			}

			localButton = m_Root.FindAnyWidget("btnSelect" + i);
			m_SurvivorButtons.Insert(localButton);

			localWidget = m_Root.FindAnyWidget("pnlCiv" + i);
			localWidget.Show(true);

			int percentHealth = (player.GetHealth()*100)/maxHealth
			localTxt = m_Root.FindAnyWidget("txtHealth" + i);
			localTxt.SetText(percentHealth.ToString() + "%");

			int percentBlood = (player.GetBlood()*100)/maxBlood
			localTxt = m_Root.FindAnyWidget("txtBlood" + i);
			localTxt.SetText(percentBlood.ToString() + "%");

			int percentWater = (player.GetWater()*100)/maxWater
			localTxt = m_Root.FindAnyWidget("txtWater" + i);
			localTxt.SetText(percentWater.ToString() + "%");

			int percentEnergy = (player.GetEnergy()*100)/maxEnergy
			localTxt = m_Root.FindAnyWidget("txtEnergy" + i);
			localTxt.SetText(percentEnergy.ToString() + "%");
		}
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
							break;
						}
					}

					if (btnSelected > -1) {
						g_Game.GetUIManager().HideScriptedMenu(this);
						g_Game.ContinueSpawn(btnSelected);
					}
				}
			}

			return true;
		}
		return false;
	}

	void UpdateScale() { }
}