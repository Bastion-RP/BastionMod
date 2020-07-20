modded class ItemBase {
    void OnInventoryExit(Man player) {
        string itemTypeLowered = GetType();

        super.OnInventoryExit(player);
        itemTypeLowered.ToLower();

        if (itemTypeLowered == BST_DTACGroupManager.CONST_DTAC_CLASSNAME) {
            if (GetGame().IsServer() && GetGame().IsMultiplayer()) {
                if (!GetDTACGroupManager().HasDTAC(player)) {
                    GetDTACServerGroupManager().RemoveUserFromGroup(PlayerBase.Cast(player));
                }
            } else {
                if (GetGame().GetPlayer() && GetGame().GetPlayer() == player && !GetDTACGroupManager().HasDTAC(GetGame().GetPlayer())) {
                    GetDTACClientGroupManager().DeleteCompassHUD();
                }
            }
        }
    }

    void OnInventoryEnter(Man player) {
        Print("Item entered inventory... " + GetType());

        string itemTypeLowered = GetType();

        super.OnInventoryEnter(player);
        itemTypeLowered.ToLower();
        
        if (GetGame().GetPlayer() && GetGame().GetPlayer().IsAlive() && GetGame().GetPlayer() == player && (!GetGame().IsServer() || !GetGame().IsMultiplayer())) {
            Print("Passed conditionals... " + BST_DTACGroupManager.CONST_DTAC_CLASSNAME);
            
            if (itemTypeLowered == BST_DTACGroupManager.CONST_DTAC_CLASSNAME) {
                if (!GetDTACClientGroupManager().GetCompassHUD()) {
                    GetDTACClientGroupManager().InitCompassHUD();
                }
            }
        }
    }
}