modded class MissionGameplay {
    override UIScriptedMenu CreateScriptedMenu(int id) {
        UIScriptedMenu menu = null;
        menu = super.CreateScriptedMenu(id);

        if (!menu) {
            switch (id) {
                case BST_CraftingConst.CONST_CRAFTING_MENU_ID:
                    {
                        menu = new BST_CraftingMenu();
                        break;
                    }
            }
            if (menu) {
                menu.SetID(id);
            }
        }
        return menu;
    }
    
    override void BST_CentralInsertMenus(BST_GUICentralMenu menu) {
        super.BST_CentralInsertMenus(menu);

        menu.InsertMenu(BST_CraftingMenuWidget);
    }
    
    override void OnUpdate(float timeslice) {
        super.OnUpdate(timeslice);

        Input input;
        BST_CraftingMenu bstCraftingMenu;
        BST_GUICentralMenu bstCentralMenu;

        input = GetGame().GetInput();
        
        if (input.LocalPress("UAUIBack", false)) {
            bstCraftingMenu = BST_CraftingMenu.Cast(GetGame().GetUIManager().GetMenu());

            if (bstCraftingMenu && !bstCraftingMenu.IsTyping()) {
                bstCraftingMenu.Close();
            }
        }
        if (input.LocalPress("BST_OpenCraftingMenu", false)) {
            bstCentralMenu = BST_GUICentralMenu.Cast(GetGame().GetUIManager().GetMenu());

            if (!bstCentralMenu) {
                bstCentralMenu = BST_GUICentralMenu.Cast(GetUIManager().EnterScriptedMenu(CONST_CENTRAL_MENU_ID, null));

                bstCentralMenu.OpenMenuByType(BST_CraftingMenuWidget);
            }
        }
    }
}