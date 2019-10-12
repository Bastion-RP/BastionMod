modded class MissionBase extends MissionBaseWorld {


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
						menu = new CharSelect();
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