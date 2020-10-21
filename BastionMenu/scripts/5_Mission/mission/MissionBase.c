modded class MissionBase
{
    override UIScriptedMenu CreateScriptedMenu(int id)
    {
        UIScriptedMenu menu = NULL;

        if (id == mainmenu)
        {
            menu = new MainMenu;
            if (menu)
            {
                menu.SetID(id);
            }
        }
        else
        {
            menu = super.CreateScriptedMenu(id);
        }
        
        return menu;
    }
}