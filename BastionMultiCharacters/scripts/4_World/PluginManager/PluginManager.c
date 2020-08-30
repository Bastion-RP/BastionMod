modded class PluginManager {
	ref array<string> _arrBSTMCPluginList;

	void PluginManager() {
		_arrBSTMCPluginList = new array<string>();
	}

	override void Init() {
		super.Init();

		_arrBSTMCPluginList.Insert("BST_MCClientManager");
		_arrBSTMCPluginList.Insert("BST_MCServerManager");
		_arrBSTMCPluginList.Insert("BST_MCServerRPCHandler");
		_arrBSTMCPluginList.Insert("BST_LibTimestamp");
		_arrBSTMCPluginList.Insert("BST_MCManager");
		_arrBSTMCPluginList.Insert("BST_MCClientRPCHandler");
		//----------------------------------------------------------------------
		// Register modules
		//----------------------------------------------------------------------
		//				Module Class Name 						Client	Server
		//----------------------------------------------------------------------
		RegisterPlugin("BST_LibTimestamp", true, true);
		RegisterPlugin("BST_MCManager", true, true);
		RegisterPlugin("BST_MCServerManager", false, true);
		RegisterPlugin("BST_MCClientManager", true, false);
		RegisterPlugin("BST_MCServerRPCHandler", false, true);
		RegisterPlugin("BST_MCClientRPCHandler", true, false);
	}
	
	//=================================
	// RegisterPlugin Except this one fucking works
	//=================================
	protected void RegisterPlugin(string plugin_class_name, bool reg_on_client, bool reg_on_server, bool reg_on_release = true) {
		if (_arrBSTMCPluginList.Find(plugin_class_name) != -1) {
			if (!reg_on_client) {
				if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) { return; }
			}
			if (!reg_on_server) {
				if (GetGame().IsServer() && GetGame().IsMultiplayer()) { return; }
			}
			if (!reg_on_release) {
				if (!GetGame().IsDebug()) { return; }
			}
			m_PluginRegister.Insert(plugin_class_name.ToType());
		} else {
			super.RegisterPlugin(plugin_class_name, reg_on_client, reg_on_server, reg_on_release);
		}
	}
}