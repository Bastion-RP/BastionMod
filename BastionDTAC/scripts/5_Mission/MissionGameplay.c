modded class MissionGameplay {
    void MissionGameplay() {
        if (GetDTACClientGroupManager()) {
            GetDTACClientGroupManager().Init();
        }
    }

    void ~MissionGameplay() {
        GetDTACClientGroupManager().DeleteCompassHUD();
    }

    override void BST_CentralInsertMenus(BST_GUICentralMenu menu) {
        super.BST_CentralInsertMenus(menu);

        if (GetDTACManager() && GetDTACClientManager() && GetGame().GetPlayer()) {
            if (GetDTACGroupManager().HasDTAC(GetGame().GetPlayer()) && GetDTACManager().IsRequiredClass(GetDTACClientManager().GetConfig().GetRequiredAPIClasses(), PlayerBase.Cast(GetGame().GetPlayer()).GetMultiCharactersPlayerClass())) {
                menu.InsertMenu("BST_DTACGroupMenu");
                menu.InsertMenu("BST_DTACLookupMenu");
            }
        }
    }
}