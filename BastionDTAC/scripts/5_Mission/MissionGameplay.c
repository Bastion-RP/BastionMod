modded class MissionGameplay {
    void MissionGameplay() {
        if (GetDTACClientGroupManager()) {
            GetDTACClientGroupManager().Init();
        }
    }

    void ~MissionGameplay() {
        GetDTACClientGroupManager().DeleteCompassHUD();
    }

    override UIScriptedMenu CreateScriptedMenu(int id) {
        UIScriptedMenu menu = null;
        menu = super.CreateScriptedMenu(id);

        if (!menu) {
            switch (id) {
                case DTACMenu.CHOICE_MENU:
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
        DTACChoiceMenu dtacChoiceMenu;

        input = GetGame().GetInput();
        
        if (input.LocalPress("UAUIBack", false)) {
            dtacChoiceMenu = DTACChoiceMenu.Cast(GetGame().GetUIManager().GetMenu());

            if (dtacChoiceMenu) {
                dtacChoiceMenu.Close();
            }
        }
        if (input.LocalPress("DTACOpenChoiceMenu", false)) {
            dtacChoiceMenu = DTACChoiceMenu.Cast(GetGame().GetUIManager().GetMenu());

            if (dtacChoiceMenu) {
                dtacChoiceMenu.Close();
            } else {
                GetUIManager().EnterScriptedMenu(DTACMenu.CHOICE_MENU, null);
            }
        }
    }
}