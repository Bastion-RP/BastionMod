modded class PluginManager {
	override void Init() {
		super.Init();
		//----------------------------------------------------------------------
		// Register modules
		//----------------------------------------------------------------------
		//				Module Class Name 						Client	Server
		//----------------------------------------------------------------------
		RegisterPlugin("BankingClientRPC", true, false);
		RegisterPlugin("BankingServerRPC", false, true);
		RegisterPlugin("BastionBankManager", true, true);
		RegisterPlugin("BastionAccountManager", false, true);
		RegisterPlugin("BastionConfigHandler", false, true);
	}
}