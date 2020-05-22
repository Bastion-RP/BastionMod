modded class PluginManager {
	ref array<string> craftingPluginList;

	void PluginManager() {
		craftingPluginList = new array<string>();
	}

	override void Init() {
		super.Init();

		craftingPluginList.Insert("BST_ServerCraftingManager");
		craftingPluginList.Insert("BST_ServerRPCHandler");
		//----------------------------------------------------------------------
		// Register modules
		//----------------------------------------------------------------------
		//				Module Class Name 						Client	Server
		//----------------------------------------------------------------------
		RegisterPlugin("BST_ServerCraftingManager", false, true);
		RegisterPlugin("BST_ServerRPCHandler", false, true);
	}
	
	//=================================
	// RegisterPlugin Except this one fucking works
	//=================================
	protected void RegisterPlugin(string plugin_class_name, bool reg_on_client, bool reg_on_server, bool reg_on_release = true) {
		if (craftingPluginList.Find(plugin_class_name) != -1) {
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