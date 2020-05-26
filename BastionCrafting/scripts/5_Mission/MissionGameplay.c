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
    
    override void OnUpdate(float timeslice) {
        super.OnUpdate(timeslice);

        Input input;
        BST_CraftingMenu craftingMenu;

        input = GetGame().GetInput();
        
        if (input.LocalPress("UAUIBack", false)) {
            craftingMenu = BST_CraftingMenu.Cast(GetGame().GetUIManager().GetMenu());

            if (craftingMenu) {
                craftingMenu.Close();
            }
        }
        if (input.LocalPress("BST_OpenCraftingMenu", false)) {
            craftingMenu = BST_CraftingMenu.Cast(GetGame().GetUIManager().GetMenu());

            if (craftingMenu) {
                craftingMenu.Close();
            } else {
                GetUIManager().EnterScriptedMenu(BST_CraftingConst.CONST_CRAFTING_MENU_ID, null);
            }
        }
    }
}