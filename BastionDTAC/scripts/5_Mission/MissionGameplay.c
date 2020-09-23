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
                case BST_DTACMenu.CHOICE_MENU:
                    {
                        menu = new BST_DTACChoiceMenu();
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
        BST_DTACChoiceMenu dtacChoiceMenu;

        input = GetGame().GetInput();
        
        if (input.LocalPress("UAUIBack", false)) {
            dtacChoiceMenu = BST_DTACChoiceMenu.Cast(GetGame().GetUIManager().GetMenu());

            if (dtacChoiceMenu) {
                dtacChoiceMenu.Close();
            }
        }
        if (input.LocalPress("DTACOpenChoiceMenu", false)) {
            dtacChoiceMenu = BST_DTACChoiceMenu.Cast(GetGame().GetUIManager().GetMenu());

            if (dtacChoiceMenu && !dtacChoiceMenu.IsShowingRecord()) {
                dtacChoiceMenu.Close();
            } else {
                GetUIManager().EnterScriptedMenu(BST_DTACMenu.CHOICE_MENU, null);
            }
        }
    }
}