modded class PluginManager {
	ref array<string> bst_BankingPluginList;

	void PluginManager() {
		bst_BankingPluginList = new array<string>();
	}

	override void Init() {
		super.Init();

		bst_BankingPluginList.Insert("BST_BankingClientRPCHandler");
		bst_BankingPluginList.Insert("BST_BankingServerRPCHandler");
		bst_BankingPluginList.Insert("BST_BankingManager");
		bst_BankingPluginList.Insert("BST_BankingAccountManager");
		bst_BankingPluginList.Insert("BST_BankingConfigHandler");
		//----------------------------------------------------------------------
		// Register modules
		//----------------------------------------------------------------------
		//				Module Class Name 						Client	Server
		//----------------------------------------------------------------------
		RegisterPlugin("BST_BankingClientRPCHandler", true, false);
		RegisterPlugin("BST_BankingServerRPCHandler", false, true);
		RegisterPlugin("BST_BankingManager", true, true);
		RegisterPlugin("BST_BankingAccountManager", false, true);
		RegisterPlugin("BST_BankingConfigHandler", true, true);
	}
	
	//=================================
	// RegisterPlugin Except this one fucking works
	//=================================
	protected void RegisterPlugin(string plugin_class_name, bool reg_on_client, bool reg_on_server, bool reg_on_release = true) {
		if (bst_BankingPluginList.Find(plugin_class_name) != -1) {
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