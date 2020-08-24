modded class PluginManager
{
	override void Init() 
	{
		super.Init();
		//----------------------------------------------------------------------
		// Register modules
		//----------------------------------------------------------------------
		//				Module Class Name 						Client	Server
		//----------------------------------------------------------------------
		RegisterPlugin("SellerManager", 							true, true);
		RegisterPlugin("SellerConfig", 								true, true);
	}
}