modded class MissionGameplay {
    override UIScriptedMenu CreateScriptedMenu(int id) {
        UIScriptedMenu menu = null;
        menu = super.CreateScriptedMenu(id);

        if (!menu) {
            switch (id) {
                case BSTBankMenu.BankingMenu:
                    {
                        menu = new BastionBankingMenu();
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

        if (key == KeyCode.KC_ESCAPE) {
            CloseBankingMenu();
            return;
        } else if (key == KeyCode.KC_RETURN || key == KeyCode.KC_NUMPADENTER) {
            HandleBankingEnter();
            return;
        }
    }

    private void CloseBankingMenu() {
        BastionBankingMenu menu = BastionBankingMenu.Cast(GetUIManager().GetMenu());

        if (menu) {
            GetUIManager().HideScriptedMenu(menu);
        }
    }

    private void HandleBankingEnter() {
        BastionBankingMenu menu = BastionBankingMenu.Cast(GetUIManager().GetMenu());

        if (menu) {
            menu.HandleEnterKey();
        }
    }
}