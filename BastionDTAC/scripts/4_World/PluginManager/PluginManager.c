modded class PluginManager {
	ref array<string> clanPluginList;

	void PluginManager() {
		clanPluginList = new array<string>();
	}

	override void Init() {
		super.Init();

		clanPluginList.Insert("BST_DTACClientRPCHandler");
		clanPluginList.Insert("BST_DTACServerGroupManager");
		clanPluginList.Insert("BST_DTACServerRPCHandler");
		clanPluginList.Insert("BST_DTACClientGroupManager");
		clanPluginList.Insert("BST_DTACGroupManager");
		//----------------------------------------------------------------------
		// Register modules
		//----------------------------------------------------------------------
		//				Module Class Name 						Client	Server
		//----------------------------------------------------------------------
		RegisterPlugin("BST_DTACGroupManager", true, true);
		RegisterPlugin("BST_DTACClientRPCHandler", true, false);
		RegisterPlugin("BST_DTACServerGroupManager", false, true);
		RegisterPlugin("BST_DTACServerRPCHandler", false, true);
		RegisterPlugin("BST_DTACClientGroupManager", true, false);
	}
	//=================================
	// RegisterPlugin Except this one fucking works
	//=================================
	protected void RegisterPlugin(string plugin_class_name, bool reg_on_client, bool reg_on_server, bool reg_on_release = true) {
		if (clanPluginList.Find(plugin_class_name) != -1) {
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