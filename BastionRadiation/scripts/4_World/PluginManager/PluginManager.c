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
		RegisterPlugin( "RadiationManager",						true, 	true );
		RegisterPlugin( "RadiationRPCServer",					false, 	true );
		RegisterPlugin( "RadiationRPCClient",					true, 	false );
	}
}