modded class MissionGameplay {
    void MissionGameplay() {
        if (GetDTACClientGroupManager()) {
            GetDTACClientGroupManager().Init();
        }
    }

    override UIScriptedMenu CreateScriptedMenu(int id) {
        UIScriptedMenu menu = null;
        menu = super.CreateScriptedMenu(id);

        if (!menu) {
            switch (id) {
                case DTACMenu.GROUP_MENU:
                    {
                        menu = new DTACChoiceMenu();
                        break;
                    }
            }
            if (menu) {
                menu.SetID(id);
            }
        }
        return menu;
    }
    
    override void OnUpdate(float timeslice) {
        super.OnUpdate(timeslice);

        Input input;
        DTACGroupMenu dtacGroupMenu;

        input = GetGame().GetInput();
        
        if (input.LocalPress("DTACOpenGroupMenu", false)) {
            dtacGroupMenu = DTACGroupMenu.Cast(GetGame().GetUIManager().GetMenu());

            if (dtacGroupMenu) {
                dtacGroupMenu.Close();
            } else {
                GetUIManager().EnterScriptedMenu(DTACMenu.GROUP_MENU, null);
            }
        }
    }
}