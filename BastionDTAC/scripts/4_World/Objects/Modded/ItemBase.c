modded class ItemBase {
    void OnInventoryExit(Man player) {
        super.OnInventoryExit(player);
        
        if (!GetDTACClientManager() || !GetDTACClientManager().GetConfig()) { return; }
        string itemTypeLowered = GetType();
        string requiredItemType = GetDTACClientManager().GetConfig().GetPhoneClassname();

        itemTypeLowered.ToLower();
        requiredItemType.ToLower();

        if (itemTypeLowered == requiredItemType) {
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
        super.OnInventoryEnter(player);

        if (!GetDTACClientManager() || !GetDTACClientManager().GetConfig()) { return; }
        string itemTypeLowered = GetType();
        string requiredItemType = GetDTACClientManager().GetConfig().GetPhoneClassname();

        itemTypeLowered.ToLower();
        requiredItemType.ToLower();
        
        if (GetGame().GetPlayer() && GetGame().GetPlayer().IsAlive() && GetGame().GetPlayer() == player && (!GetGame().IsServer() || !GetGame().IsMultiplayer())) {
            if (itemTypeLowered == requiredItemType) {
                if (!GetDTACClientGroupManager().GetCompassHUD()) {
                    GetDTACClientGroupManager().InitCompassHUD();
                }
            }
        }
    }
}