static const string m_ModDir = "$profile:\\Bastion";
static const string m_LoadoutDir = "$profile:\\Bastion\\Loadouts";
static const string m_SpawnPointDir = "$profile:\\Bastion\\SpawnPoints.json";
static const string m_FileType = ".json";
typedef Param1<ref SavePlayer> loadoutParam;

static array<vector> DefaultSpawns()
{
	return {"760 0 1880", "570 0 1700", "1760 0 2080", "2120 0 2380", "1850 0 3400", "2220 0 3470", "3480 0 2120",
        "3760 0 2500", "5270 0 2400", "4800 0 2450", "4350 0 2390", "4300 0 2560", "4776 0 2750", "5980 0 3250",
        "6150 0 3050", "6430 0 3180", "6640 0 3640", "6597 0 3419", "6220 0 2109", "7086 0 2477", "6830 0 2920",
        "7920 0 3400", "8226 0 2800", "8311 0 2406", "6030 0 4872", "7041 0 4432", "7545 0 5159", "7930 0 4079",
        "8250 0 6870", "8645 0 6593", "9653 0 2105", "10331 0 2367", "10674 0 2130", "10140 0 5325", "10022 0 5675",
        "11512 0 4986", "11981 0 3428", "13488 0 2838", "13600 0 3207", "13229 0 3221", "13045 0 5950", "13524 0 6077",
        "13308 0 6447", "13124 0 6245", "11109 0 6608", "9589 0 6577", "11840 0 8858", "11831 0 9391", "12482 0 9259",
        "11799 0 9793", "13221 0 10479", "12223 0 10763", "11134 0 12010", "8572 0 12807", "7316 0 12655", "10462 0 14184",
        "9279 0 14425", "7724 0 14553", "8117 0 14856", "12530 0 14580", "14035 0 14958", "14020 0 12970", "13670 0 13433",
        "8626 0 11811", "4547 0 12799", "3139 0 13009", "4928 0 14876", "6561 0 14674", "7471 0 13297", "8552 0 13810",
        "7790 0 14479", "1910 0 7160", "4325 0 11009", "4749 0 9268", "4174 0 8813", "6025 0 7927", "6388 0 7626",
        "7032 0 7806", "7274 0 7699", "9538 0 8638", "6906 0 11373", "2945 0 5440", "2569 0 5589", "2849 0 10093",
        "4045 0 11622", "1650 0 14410", "1600 0 13578", "9313 0 11189", "5686 0 10415", "4055 0 7835", "3958 0 13211", "6445 0 8391"};
}

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

		if (!FileExist(m_SpawnPointDir)) {
			JsonFileLoader<array<vector>>.JsonSaveFile(m_SpawnPointDir, DefaultSpawns());
		}
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