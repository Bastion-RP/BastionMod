modded class PluginManager {
	ref array<string> bankingPluginList;

	void PluginManager() {
		bankingPluginList = new array<string>();
	}

	override void Init() {
		super.Init();

		bankingPluginList.Insert("BankingClientRPC");
		bankingPluginList.Insert("BankingServerRPC");
		bankingPluginList.Insert("BastionBankManager");
		bankingPluginList.Insert("BastionAccountManager");
		bankingPluginList.Insert("BastionConfigHandler");
		//----------------------------------------------------------------------
		// Register modules
		//----------------------------------------------------------------------
		//				Module Class Name 						Client	Server
		//----------------------------------------------------------------------
		RegisterPlugin("BankingClientRPC", true, false);
		RegisterPlugin("BankingServerRPC", false, true);
		RegisterPlugin("BastionBankManager", true, true);
		RegisterPlugin("BastionAccountManager", false, true);
		RegisterPlugin("BastionConfigHandler", true, true);
	}
	
	//=================================
	// RegisterPlugin Except this one fucking works
	//=================================
	protected void RegisterPlugin(string plugin_class_name, bool reg_on_client, bool reg_on_server, bool reg_on_release = true) {
		if (bankingPluginList.Find(plugin_class_name) != -1) {
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