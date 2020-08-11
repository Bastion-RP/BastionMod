modded class PlayerBase {
    void ~PlayerBase() {
        if (GetGame().IsServer() && GetGame().IsMultiplayer() && GetIdentity()) {
            GetDTACServerGroupManager().RemoveUserFromGroup(this);
        } else {
            if (GetIdentity() && GetDTACGroupManager() && GetDTACGroupManager().dtacStatInvoker) {
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

    override void OnPlayerLoaded() {
        super.OnPlayerLoaded();

        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) {
            if (GetGame().GetMission() && GetGame().GetPlayer() && GetGame().GetPlayer().IsAlive() && GetGame().GetPlayer() == this) {
                if (GetDTACGroupManager().HasDTAC(this)) {
                    GetDTACClientGroupManager().InitCompassHUD();
                } else {
                    GetDTACClientGroupManager().DeleteCompassHUD();
                }
            }
        }
    }

    override void OnConnect() {
        super.OnConnect();

        Param params = new Param1<ref BST_DTACConfig>(GetDTACServerManager().GetConfig());

        GetGame().RPCSingleParam(this, BST_DTACRPC.CLIENT_RECEIVE_CONFIG, params, true, GetIdentity());
    }
}