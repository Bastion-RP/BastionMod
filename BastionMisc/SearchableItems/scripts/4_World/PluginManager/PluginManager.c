modded class PluginManager
{		
	override void Init()
	{	
		super.Init();
		//----------------------------------------------------------------------
		//				Module Class Name 						Client	Server
		//----------------------------------------------------------------------
		RegisterPlugin( "SearchManager",						false, 	true );
	}
}