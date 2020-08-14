modded class MissionServer {
    override void InvokeOnDisconnect(PlayerBase player) {
        if (player && player.GetIdentity()) {
            GetDTACServerGroupManager().RemoveUserFromGroup(player);
        }
        super.InvokeOnDisconnect(player);
    }
}