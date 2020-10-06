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

                        BST_CentralInsertMenus(BST_GUICentralMenu.Cast(menu));
                        break;
                    }
            }
            if (menu) {
                menu.SetID(id);
            }
        }
        return menu;
    }

    // Override this and call menu.InsertMenu(classname); for each menu you want to create a button for
    /*
        Support for per-menu hotkeys is also available.
        If you want a menu to be opened with the central menu through a keybind, you can use OpenMenuByType(typename)
        Example below
    */

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

        /* 
            Example from BastionCrafting
            Check to see if the central menu is open through custom keybind
            If not open, open it and use OpenMenuByType(classname) to open the crafting menu
        
        
        if (input.LocalPress("BST_OpenCraftingMenu", false)) {
            bstCentralMenu = BST_GUICentralMenu.Cast(GetGame().GetUIManager().GetMenu());

            if (!bstCentralMenu) {
                bstCentralMenu = BST_GUICentralMenu.Cast(GetUIManager().EnterScriptedMenu(CONST_CENTRAL_MENU_ID, null));

                bstCentralMenu.OpenMenuByType(BST_CraftingMenuWidget); <--- This will open the crafting menu
            }
        } */
    }
}