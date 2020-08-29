class BST_MCClientManager : PluginBase {
	static ref ScriptInvoker _initInvoker;

	private ref array<ref BST_MCSavePlayerBasic> _arrCharacters;
	private ref MultiCharactersInitMenu _menuInit;
	private ref BST_MCGUICharactersMenu _menuSpawn;
	private bool _isInitialized;

	void BST_MCClientManager() {
		g_Game.BST_MCInitInvoker.Insert(InitClient);
		g_Game.BST_MCSpawnInvoker.Insert(ContinueSpawn);
		_initInvoker = new ScriptInvoker();

		Init();
	}

	void ~BST_MCClientManager() {
		g_Game.BST_MCInitInvoker.Remove(InitClient);
		g_Game.BST_MCSpawnInvoker.Remove(ContinueSpawn);
	}

	void Init() {
		if (_menuInit) {
			delete _menuInit;
		}
		if (_menuSpawn) {
			delete _menuSpawn;
		}
		if (_arrCharacters) {
			delete _arrCharacters;
		}
		_isInitialized = false;
		_arrCharacters = new array<ref BST_MCSavePlayerBasic>();
	}

	void SetCharacters(ref array<ref BST_MCSavePlayerBasic> arrCharacters) {
		if (_arrCharacters) {
			delete _arrCharacters;
		}
		_arrCharacters = arrCharacters;
	}

	void InitClient() {
		if (!_menuInit) {
			_menuInit = new MultiCharactersInitMenu();
		}
		//_menuInit.Initializing();

		/* if (!isInitialized) {
			_menuInit.Loading();
			GetDayZGame().ContinueSpawn(true);
		} else { */
		_menuInit.DataWaiting();
		GetGame().RPCSingleParam(null, BST_MCRPC.SERVER_GRAB_LOADOUTS, null, true);
		//}
	}

	void ShowSelectMenu() {
		if (!_menuSpawn) {
			_menuSpawn = new BST_MCGUICharactersMenu();
		}
		GetGame().GetUIManager().ShowScriptedMenu(_menuSpawn, null);
	}

	void HideInitMenu() {
		if (_menuInit) {
			_menuInit.Hide();
		}
	}

	void SetInitialized(bool isInitialized) {
		_isInitialized = isInitialized;
	}

	void ContinueSpawn() {

	}

	array<ref BST_MCSavePlayerBasic> GetLoadouts() { return _arrCharacters; }
	BST_MCGUICharactersMenu GetSelectMenu() { return _menuSpawn; }
	bool IsInitialized() { return _isInitialized; }
}

BST_MCClientManager GetBSTMCClientManager() {
	return BST_MCClientManager.Cast(GetPlugin(BST_MCClientManager));
}