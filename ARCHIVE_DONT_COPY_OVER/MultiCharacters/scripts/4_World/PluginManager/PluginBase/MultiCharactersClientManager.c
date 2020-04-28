class MultiCharactersClientManager : PluginBase {
	private ref array<ref SavePlayer> arrayLoadouts;
	private ref MultiCharactersInitMenu menuInit;
	private ref MultiCharactersMenu menuSelect;
	private int selectedSurvivorId;
	private string selectedSurvivorType;
	private bool isInitialized;

	void MultiCharactersClientManager() {
		GetDayZGame().multicharactersSpawnInvoker.Insert(InitClient);
		isInitialized = false;
		arrayLoadouts = new array<ref SavePlayer>();
	}

    void Init() {
		if (menuInit) {
			delete menuInit;
		}
		if (menuSelect) {
			delete menuSelect;
		}
		if (arrayLoadouts) {
			delete arrayLoadouts;
		}
		isInitialized = false;
		arrayLoadouts = new array<ref SavePlayer>();
    }

	ref array<ref SavePlayer> GetLoadouts() {
		return arrayLoadouts;
	}

	void SetLoadouts(ref array<ref SavePlayer> arrayLoadouts) {
		delete this.arrayLoadouts;

		this.arrayLoadouts = new array<ref SavePlayer>();
		this.arrayLoadouts = arrayLoadouts;
	}

	void InitClient() {
		Print(MCConst.debugPrefix + "MultiCharactersClientManager | InitClient | Initializing client! " + isInitialized);
		if (!menuInit) {
			menuInit = new MultiCharactersInitMenu();
		}
		menuInit.Initializing();

		if (!isInitialized) {
			Print(MCConst.debugPrefix + "MultiCharactersClientManager | InitClient | Client not initialized, sending rpc to server!");
			menuInit.Loading();
			GetDayZGame().ContinueSpawn(true);
		} else {
			Print(MCConst.debugPrefix + "MultiCharactersClientManager | InitClient | Client initialized, grabbing loadouts!");
			menuInit.DataWaiting();
			GetGame().RPCSingleParam(null, MultiCharRPC.SERVER_GRAB_LOADOUTS, null, true);
		}
	}

	void ShowSelectMenu() {
		if (!menuSelect) {
			menuSelect = new MultiCharactersMenu();
		}
		GetGame().GetUIManager().ShowScriptedMenu(menuSelect, null);
	}

	void HideInitMenu() {
		if (menuInit) {
			menuInit.Hide();
		}
	}

	void SetInitialized(bool isInitialized) {
		this.isInitialized = isInitialized;
	}

	MultiCharactersMenu GetSelectMenu() {
		return menuSelect;
	}

	bool IsInitialized() {
		return isInitialized;
	}
}

MultiCharactersClientManager GetMultiCharactersClientManager() {
    return MultiCharactersClientManager.Cast(GetPlugin(MultiCharactersClientManager));
}