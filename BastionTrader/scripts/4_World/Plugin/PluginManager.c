modded class PluginManager
{
	//=================================
	// Init
	//=================================
	override void Init()
	{	
		super.Init();
		//----------------------------------------------------------------------
		// Register modules
		//----------------------------------------------------------------------
		//				Module Class Name 						Client	Server
		//----------------------------------------------------------------------
		RegisterPlugin( "BTraderManagerClient",					true, 	false );
	}
}