modded class OptionsMenuGame extends ScriptedWidgetEventHandler
{
	string GetLayoutName()
	{
		#ifdef PLATFORM_CONSOLE
			return "BastionMod/BastionMenu/gui/layouts/new_ui/options/xbox/game_tab.layout";
		#else
		#ifdef PLATFORM_WINDOWS
			return "BastionMod/BastionMenu/gui/layouts/new_ui/options/pc/game_tab.layout";
		#endif
		#endif
	}
}
