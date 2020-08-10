modded class PluginManager {
	ref array<string> _bstDTACPluginList;

	void PluginManager() {
		_bstDTACPluginList = new array<string>();
	}

	override void Init() {
		super.Init();

		// For groups
		_bstDTACPluginList.Insert("BST_DTACClientRPCHandler");
		_bstDTACPluginList.Insert("BST_DTACServerGroupManager");
		_bstDTACPluginList.Insert("BST_DTACServerRPCHandler");
		_bstDTACPluginList.Insert("BST_DTACClientGroupManager");
		_bstDTACPluginList.Insert("BST_DTACGroupManager");
		
		// For base DTAC
		_bstDTACPluginList.Insert("BST_DTACServerManager");
		_bstDTACPluginList.Insert("BST_DTACClientManager");
		_bstDTACPluginList.Insert("BST_DTACManager");
		//----------------------------------------------------------------------
		// Register modules
		//----------------------------------------------------------------------
		//				Module Class Name 						Client	Server
		//----------------------------------------------------------------------
		// For groups
		RegisterPlugin("BST_DTACGroupManager", true, true);
		RegisterPlugin("BST_DTACClientRPCHandler", true, false);
		RegisterPlugin("BST_DTACServerGroupManager", false, true);
		RegisterPlugin("BST_DTACServerRPCHandler", false, true);
		RegisterPlugin("BST_DTACClientGroupManager", true, false);

		// For base DTAC
		RegisterPlugin("BST_DTACServerManager", false, true);
		RegisterPlugin("BST_DTACClientManager", true, false);
		RegisterPlugin("BST_DTACManager", true, true);
	}
	//=================================
	// RegisterPlugin Except this one fucking works
	//=================================
	protected void RegisterPlugin(string plugin_class_name, bool reg_on_client, bool reg_on_server, bool reg_on_release = true) {
		if (_bstDTACPluginList.Find(plugin_class_name) != -1) {
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