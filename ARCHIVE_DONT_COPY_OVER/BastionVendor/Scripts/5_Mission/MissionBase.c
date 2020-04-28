modded class MissionBase
{
    override UIScriptedMenu CreateScriptedMenu(int id)
	{
        UIScriptedMenu menu = NULL; 
	
		switch (id)
		{
            case MENU_TRADER:
			    menu = new TraderUI;
			break;
        }

        if ( menu )
		{
			menu.SetID(id);
		} 
		else
		{
			menu = super.CreateScriptedMenu(id);
		}

        return menu;
    }
}