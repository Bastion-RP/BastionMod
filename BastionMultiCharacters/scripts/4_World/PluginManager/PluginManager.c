modded class PluginManager {
	ref array<string> mcPluginList;

	void PluginManager() {
		mcPluginList = new array<string>();
	}

	override void Init() {
		super.Init();

		mcPluginList.Insert("MultiCharactersClientManager");
		mcPluginList.Insert("MultiCharactersServerManager");
		mcPluginList.Insert("MultiCharactersServerRPCHandler");
		mcPluginList.Insert("BST_LibTimestamp");
		mcPluginList.Insert("BST_MCManager");
		mcPluginList.Insert("MultiCharactersClientRPCHandler");
		//----------------------------------------------------------------------
		// Register modules
		//----------------------------------------------------------------------
		//				Module Class Name 						Client	Server
		//----------------------------------------------------------------------
		RegisterPlugin("BST_LibTimestamp", true, true);
		RegisterPlugin("BST_MCManager", true, true);
		RegisterPlugin("MultiCharactersServerManager", true, true);
		RegisterPlugin("MultiCharactersClientManager", true, false);
		RegisterPlugin("MultiCharactersServerRPCHandler", false, true);
		RegisterPlugin("MultiCharactersClientRPCHandler", true, false);
	}
	
	//=================================
	// RegisterPlugin Except this one fucking works
	//=================================
	protected void RegisterPlugin(string plugin_class_name, bool reg_on_client, bool reg_on_server, bool reg_on_release = true) {
		if (mcPluginList.Find(plugin_class_name) != -1) {
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