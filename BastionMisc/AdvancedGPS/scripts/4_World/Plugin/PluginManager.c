modded class PluginManager
{
	override void Init()
	{
		super.Init();
		RegisterPlugin("ADVCGps", true, true);
		RegisterPlugin("ADVCGpsPCServer", false, true);
		RegisterPlugin("ADVCGpsPCClient", true, false);
	}
}