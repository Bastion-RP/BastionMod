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
		RegisterPlugin( "ToxicManager",						true, 	true );
		RegisterPlugin( "ToxicRPCServer",					false, 	true );
		RegisterPlugin( "ToxicRPCClient",					true, 	false );
	}
}