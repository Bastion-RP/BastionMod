modded class MissionGameplay {
    override UIScriptedMenu CreateScriptedMenu(int id) {
        UIScriptedMenu menu = null;
        menu = super.CreateScriptedMenu(id);

        if (!menu) {
            switch (id) {
                case BST_BankMenu.MAIN_MENU_ID:
                    {
                        menu = new BST_BankingMenu();
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

        Input input = GetGame().GetInput();

        if (input.LocalPress("UAUIBack", false)) {
            BST_BankingMenu menu = BST_BankingMenu.Cast(GetGame().GetUIManager().GetMenu());

            if (menu) {
                menu.Close();
            }
        }
    }

   /*  override void OnKeyPress(int key) {
        super.OnKeyPress(key);
        m_Hud.KeyPress(key);

        if (key == KeyCode.KC_ESCAPE) {
            BST_BankingMenu menu = BST_BankingMenu.Cast(GetUIManager().GetMenu());

            if (menu) {
                menu.Close();
            }
            return;
        } else if (key == KeyCode.KC_L) {
            GetUIManager().EnterScriptedMenu(BST_BankMenu.MAIN_MENU_ID, null);
            return;
        }
    } */
}