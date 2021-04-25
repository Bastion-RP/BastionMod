class BST_MCClientManager : PluginBase {
	static ref ScriptInvoker _initInvoker;

	private ref array<ref BST_MCSavePlayerBasic> _arrCharacters;
	private ref MultiCharactersInitMenu _menuInit;
	private ref BST_MCGUIMainMenu _menuCharSelect;
	private bool _isInitialized;

	void BST_MCClientManager() {
		_initInvoker = new ScriptInvoker();

		Init();
		GetDayZGame().BST_MCSpawnInvoker.Insert(InitClient);
	}

	void ~BST_MCClientManager() {
		GetDayZGame().BST_MCSpawnInvoker.Remove(InitClient);
		delete _initInvoker;
	}

	void Init() {
		if (_menuInit) {
			delete _menuInit;
		}
		if (_menuCharSelect) {
			delete _menuCharSelect;
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
		if (!_menuCharSelect) {
			_menuCharSelect = new BST_MCGUIMainMenu();
		}
		GetGame().GetUIManager().ShowScriptedMenu(_menuCharSelect, null);
	}

	void HideInitMenu() {
		if (_menuInit) {
			_menuInit.Hide();
		}
	}

	void SetInitialized(bool isInitialized) {
		_isInitialized = isInitialized;
	}

	void ContinueSpawn(int characterId, string survivorType) {

		ScriptReadWriteContext ctx = new ScriptReadWriteContext;
		ctx.GetWriteContext().Write(characterId);
		ctx.GetWriteContext().Write(survivorType);

		GetDayZGame().StoreLoginData(ctx.GetWriteContext());
	}

	array<ref BST_MCSavePlayerBasic> GetCharacters() { return _arrCharacters; }
	BST_MCGUIMainMenu GetSelectMenu() { return _menuCharSelect; }
	bool IsInitialized() { return _isInitialized; }
}

BST_MCClientManager GetBSTMCClientManager() {
	return BST_MCClientManager.Cast(GetPlugin(BST_MCClientManager));
}