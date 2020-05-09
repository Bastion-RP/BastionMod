modded class PlayerBase {
    void ~PlayerBase() {
        if (GetGame().IsServer() && GetGame().IsMultiplayer() && GetIdentity()) {
            GetDTACServerGroupManager().RemoveUserFromGroup(this);
        } else {
            if ( GetIdentity() && GetDTACGroupManager() && GetDTACGroupManager().dtacStatInvoker ) {
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

    override void OnConnect() {
        Param params = new Param3<int, string, int>(multicharactersPlayerId, multicharactersPlayerName, multicharactersPlayerClass);

        super.OnConnect();
        GetGame().RPCSingleParam(this, DTACRPC.CLIENT_RECEIVE_PLAYER_API_DATA, params, true, GetIdentity());
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

    string GetMultiCharactersPlayerName() {
        return multicharactersPlayerName;
    }
}