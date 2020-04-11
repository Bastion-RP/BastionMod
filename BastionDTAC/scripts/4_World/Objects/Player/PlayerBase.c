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

        GetGame().RPCSingleParam(this, DTACRPC.CLIENT_RECEIVE_PLAYER_API_DATA, params, true, GetIdentity());
    }

    string GetMultiCharactersPlayerName() {
        return multicharactersPlayerName;
    }
}