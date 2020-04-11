modded class PlayerBase {
    void ~PlayerBase() {
        if (GetGame().IsServer() && GetGame().IsMultiplayer() && GetIdentity()) {
            GetDTACServerGroupManager().RemoveUserFromGroup(this);
        } else {
            if (GetIdentity()) {
                GetDTACGroupManager().dtacStatInvoker.Invoke(GetIdentity().GetId());
            }
        }
    }

    override void EEKilled(Object killer) {
        super.EEKilled(killer);

        if (GetIdentity()) {
            GetDTACServerGroupManager().RemoveUserFromGroup(this);
        }
    }
}