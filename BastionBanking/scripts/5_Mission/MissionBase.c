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

    override void OnKeyPress(int key) {
        super.OnKeyPress(key);
        m_Hud.KeyPress(key);

        if (key == KeyCode.KC_L) {
            BST_BankingMenu menu = BST_BankingMenu.Cast(GetUIManager().GetMenu());

            if (menu) {
                menu.Close();
            } else {
                GetUIManager().EnterScriptedMenu(BST_BankMenu.MAIN_MENU_ID, null);
            }
            return;
        }
    }
}