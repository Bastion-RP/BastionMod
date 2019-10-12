modded class DayZGame {
	protected ref FileSerializer m_FileSerializer = new FileSerializer();
	protected ref array<ref SavePlayer> m_Loadouts;
	protected ref array<string> m_Whitelist;
	protected ref CharSelect mcMainMenu;
	protected bool m_CheckedDirs;
	protected int m_BtnSelected;
	protected string selectedSurvivor;

	void DayZGame() {
		m_CheckedDirs = false;
		m_Whitelist = new array<string>();
	}

	ref array<ref SavePlayer> GetLoadouts() {
		return m_Loadouts;
	}

	void GetLoadouts(PlayerIdentity sender) {
		for (int i = 0; i < 6; i++) {
			string dir = m_LoadoutDir + "\\" + sender.GetPlainId() + "\\" + i + m_BSTFileType;
			if (FileExist(dir)) {
				ref SavePlayer player;
				JsonFileLoader<ref SavePlayer>.JsonLoadFile(dir, player);
				loadoutParam param = new loadoutParam(player);
				RPCSingleParam(null, MultiCharRPC.CLIENT_GRAB_LOADOUTS, param, true, sender);
			}
		}
		LoadWhitelist();
		bool isWhitelisted = IsWhitelisted(sender.GetPlainId());

		Print(m_DebugPrefix + "Sending whitelist bool to client playerId=" + sender.GetPlainId() + " | value=" + isWhitelisted);
		
		Param2<bool, string> whitelistParam = new Param2<bool, string>(isWhitelisted, sender.GetPlainId());
		
		RPCSingleParam(null, MultiCharRPC.CLIENT_SHOW_MENU, whitelistParam, true, sender);
	}

	void SetSelectedSurvivor(string survivor) {
		selectedSurvivor = survivor;
	}

	override void CheckDir() {
		super.CheckDir();

		m_CheckedDirs = true;

		if (!IsServer() || !IsMultiplayer()) return;

		if (!FileExist(m_LoadoutDir)) {
			MakeDirectory(m_LoadoutDir);
		}

		if (!FileExist(m_SpawnPointDir)) {
			JsonFileLoader<array<vector>>.JsonSaveFile(m_SpawnPointDir, DefaultSpawns());
		}

		if (!FileExist(m_NCCSpawnPointDir)) {
			JsonFileLoader<array<vector>>.JsonSaveFile(m_NCCSpawnPointDir, NCCSpawns());
		}
	}

	override void StoreLoginData() {
		m_Loadouts = new array<ref SavePlayer>();
		RPCSingleParam(null, MultiCharRPC.SERVER_GRAB_LOADOUTS, null, true);
		GetUIManager().EnterScriptedMenu(MultiCharMenu.MENU_WAIT, null);
	}
	
	override void CancelLoginTimeCountdown()
	{
		Print(m_DebugPrefix + "Cancelling login countdown!");
		super.CancelLoginTimeCountdown();
		ContinueSpawn();
	}

	void ShowCountDown() {
		Print(m_DebugPrefix + "Showing login timer!");
		if (m_LoginTime <= 0) {
			m_LoginTime = 5;
		}

		GetUIManager().ScreenFadeIn(0, "You are spawning in " + m_LoginTime + " second(s)", FadeColors.BLACK, FadeColors.WHITE);
		GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(SpawnCountdown, 1000, true);
	}

	void SpawnCountdown() {
		m_LoginTime--
		if (m_LoginTime <= 0) {
			GetCallQueue(CALL_CATEGORY_SYSTEM).Remove(this.SpawnCountdown);
			GetGame().GetUIManager().ScreenFadeOut(0);
			ContinueSpawn();
		} else {
			GetUIManager().ScreenFadeIn(0, "You are spawning in " + m_LoginTime + " second(s)", FadeColors.BLACK, FadeColors.WHITE);
		}
	}

	override void OnRespawnEvent(int time) {
		if (time > 0) {
			m_LoginTime = time;
		}
		return;
	}

	void ShowMenu() {
		Print(m_DebugPrefix + "Showing character selection menu!");

	/* 	if (!mcMainMenu) {
			mcMainMenu = new CharSelect();
			mcMainMenu.SetID(MultiCharMenu.MENU_SPAWN);
		} */
		GetUIManager().HideMenu(MultiCharMenu.MENU_WAIT);
		GetUIManager().EnterScriptedMenu(MultiCharMenu.MENU_SPAWN, null);
		//GetUIManager().EnterScriptedMenu(MultiCharMenu.MENU_CHAR_SELECT, null);
	}

	void ContinueSpawn() {
		Print(m_DebugPrefix + "Continuing spawn!");
		ref array<ref Param> params = new array<ref Param>;

		ref Param playerIndex = new Param1<int>(m_BtnSelected);
		params.Insert(playerIndex);

		ref Param survivor = new Param1<string>(selectedSurvivor);
		params.Insert(survivor);

		StoreLoginData(params);
	}

	void SetBtnSelected(int selected) {
		m_BtnSelected = selected;
	}

	override void OnRPC(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx) {
		super.OnRPC(sender, target, rpc_type, ctx);

		switch (rpc_type) {
			case MultiCharRPC.SERVER_GRAB_LOADOUTS:
			{
				if (!m_CheckedDirs)
					CheckDir();

				GetLoadouts(sender);
				break;
			}
			case MultiCharRPC.CLIENT_GRAB_LOADOUTS:
			{
				loadoutParam data;
				ctx.Read(data);

				m_Loadouts.Insert(data.param1);
				break;
			}
			case MultiCharRPC.CLIENT_SHOW_MENU:
			{
				Param2<bool, string> whitelistData;
				ctx.Read(whitelistData);

				m_BSTIsWhitelisted = whitelistData.param1;
				m_PlayerIdMenu = new PlayerIdMenu(whitelistData.param2);
				ShowMenu();
				break;
			}
		}
	}
}