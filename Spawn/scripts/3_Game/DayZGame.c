static const string m_ModDir = "$profile:\\Bastion";
static const string m_LoadoutDir = "$profile:\\Bastion\\Loadouts";
static const string m_FileType = ".json";
typedef Param1<ref SavePlayer> loadoutParam;

modded class DayZGame {
	ref FileSerializer m_FileSerializer = new FileSerializer();
	ref array<ref SavePlayer> m_Loadouts;
	ref array<string> m_Whitelist;
	bool m_CheckedDirs;

	void DayZGame() {
		m_CheckedDirs = false;
		m_Whitelist = new array<string>();
	}

	ref array<ref SavePlayer> GetLoadouts() {
		return m_Loadouts;
	}

	void CheckDir() {
		m_CheckedDirs = true;

		if (!IsServer() || !IsMultiplayer()) return;

		if (!FileExist(m_ModDir))
			MakeDirectory(m_ModDir);

		if (!FileExist(m_LoadoutDir))
			MakeDirectory(m_LoadoutDir);
	}

	override void StoreLoginData() {
		m_Loadouts = new array<ref SavePlayer>();
		RPCSingleParam(null, MultiCharRPC.SERVER_GRAB_LOADOUTS, null, true);
		GetUIManager().EnterScriptedMenu(MultiCharMenu.MENU_WAIT, null);
	}

	void ShowMenu() {
		GetUIManager().HideMenu(MultiCharMenu.MENU_WAIT);
		GetUIManager().EnterScriptedMenu(MultiCharMenu.MENU_SPAWN, null);
	}

	void ContinueSpawn(int index) {
		ref array<ref Param> params = new array<ref Param>;

		ref Param playerIndex = new Param1<int>(index);
		params.Insert(playerIndex);

		StoreLoginData(params);
	}

	override void OnRPC(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx) {
		super.OnRPC(sender, target, rpc_type, ctx);

		switch (rpc_type) {
			case MultiCharRPC.SERVER_GRAB_LOADOUTS:
				{
					if (!m_CheckedDirs)
						CheckDir();

					GetLoadouts(sender);
					//RPCSingleParam( null, 9119111912, null, true, sender );
					break;
				}
			case MultiCharRPC.CLIENT_GRAB_LOADOUTS:
				{
					loadoutParam data;
					ctx.Read(data);

					m_Loadouts.Insert(data.param1);
					m_Loadouts.Debug();
					break;
				}
			case MultiCharRPC.CLIENT_SHOW_MENU:
				{
					ShowMenu();
					break;
				}
		}
	}

	void GetLoadouts(PlayerIdentity sender) {
		for (int i = 0; i < 5; i++) {
			string dir = m_LoadoutDir + "\\" + sender.GetPlainId() + "\\" + i + m_FileType;
			if (FileExist(dir)) {
				ref SavePlayer player;
				JsonFileLoader<ref SavePlayer>.JsonLoadFile(dir, player);
				loadoutParam param = new loadoutParam(player);
				RPCSingleParam(null, MultiCharRPC.CLIENT_GRAB_LOADOUTS, param, true, sender);
			}
		}
		RPCSingleParam(null, MultiCharRPC.CLIENT_SHOW_MENU, null, true, sender);
	}
}