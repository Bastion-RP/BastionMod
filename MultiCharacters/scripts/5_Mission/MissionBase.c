modded class MissionBase {
	override UIScriptedMenu CreateScriptedMenu(int id) {
		UIScriptedMenu menu = null;
		menu = super.CreateScriptedMenu(id);

		if (!menu) {
			switch (id) {
				case MultiCharMenu.MENU_WAIT:
					{
						menu = new MenuWaitForServer();
						break;
					}
				case MultiCharMenu.MENU_SPAWN:
					{
						menu = new MultiCharactersMenu();
						break;
					}
			}
			if (menu) {
				menu.SetID(id);
			}
		}
		return menu;
	}
}