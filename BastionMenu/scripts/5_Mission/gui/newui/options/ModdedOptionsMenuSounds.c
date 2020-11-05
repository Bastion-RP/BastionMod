modded class OptionsMenuSounds extends ScriptedWidgetEventHandler
{
	string GetLayoutName()
	{
		#ifdef PLATFORM_CONSOLE
			return "BastionMod/BastionMenu/gui/layouts/new_ui/options/xbox/sound_tab.layout";
		#else
		#ifdef PLATFORM_WINDOWS
			return "BastionMod/BastionMenu/gui/layouts/new_ui/options/pc/sound_tab.layout";
		#endif
		#endif
	}
}