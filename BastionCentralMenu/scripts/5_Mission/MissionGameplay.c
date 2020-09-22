modded class MissionGameplay {
    private static const int CONST_CENTRAL_MENU_ID = 787783;

    override UIScriptedMenu CreateScriptedMenu(int id) {
        UIScriptedMenu menu = null;
        menu = super.CreateScriptedMenu(id);

        if (!menu) {
            switch (id) {
                case CONST_CENTRAL_MENU_ID:
                    {
                        menu = new BST_GUICentralMenu();

                        BST_CentralInsertMenus(menu);
                        break;
                    }
            }
            if (menu) {
                menu.SetID(id);
            }
        }
        return menu;
    }

    // Override this and call menu.InsertMenu("classname"); for each menu you want to create a button for

    void BST_CentralInsertMenus(BST_GUICentralMenu menu) { }
    
    override void OnUpdate(float timeslice) {
        super.OnUpdate(timeslice);

        Input input;
        BST_GUICentralMenu bst_CentralMenu;

        input = GetGame().GetInput();
        
        if (input.LocalPress("UAUIBack", false)) {
            bst_CentralMenu = BST_GUICentralMenu.Cast(GetGame().GetUIManager().GetMenu());

            if (bst_CentralMenu && !bst_CentralMenu.IsTyping()) {
                bst_CentralMenu.Close();
            }
        }
        if (input.LocalPress("BST_OpenCentralMenu", false)) {
            bst_CentralMenu = BST_GUICentralMenu.Cast(GetGame().GetUIManager().GetMenu());

            if (bst_CentralMenu && !bst_CentralMenu.IsTyping()) {
                bst_CentralMenu.Close();
            } else {
                GetUIManager().EnterScriptedMenu(CONST_CENTRAL_MENU_ID, null);
            }
        }
    }
}