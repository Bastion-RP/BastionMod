modded class MissionGameplay {
    protected autoptr BastionCCTV m_bastionCCTV;

    void MissionGameplay() {
        m_bastionCCTV = new BastionCCTV();
    }

    override UIScriptedMenu CreateScriptedMenu(int id) {
        UIScriptedMenu menu = super.CreateScriptedMenu(id);
        if ( !menu ) {
            switch ( id ) {
                case BastionCCTVEnum.CCTVMenu:
                    menu = new BastionCCTVMenu();
                break;
            }
            if  ( menu ) {
                menu.SetID(id);
            }
        }
        return menu;
    }
}

modded class MissionServer {
    protected autoptr BastionCCTV m_bastionCCTV;
    void MissionServer() {
        m_bastionCCTV = new BastionCCTV();
    }
}