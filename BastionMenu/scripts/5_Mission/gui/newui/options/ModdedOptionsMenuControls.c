modded class OptionsMenuControls extends ScriptedWidgetEventHandler
{
	string GetLayoutName()
	{
		#ifdef PLATFORM_CONSOLE
			return "BastionMod/BastionMenu/gui/layouts/new_ui/options/xbox/controls_tab.layout";
		#else
		#ifdef PLATFORM_WINDOWS
			return "BastionMod/BastionMenu/gui/layouts/new_ui/options/pc/controls_tab.layout";
		#endif
		#endif
	}
}