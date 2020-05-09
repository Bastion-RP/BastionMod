modded class PlayerBase {
    private int bstAPIPlayerClass;

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
        Print("[DTAC DEBUG] player id=" + multicharactersPlayerId + " class=" + multicharactersPlayerClass + " name=" + multicharactersPlayerName);
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
    
    void SetBastionAPIID(int multicharactersPlayerId) {
        this.multicharactersPlayerId = multicharactersPlayerId;
    }
    
    void SetBastionAPIClass(int multicharactersPlayerClass) {
        this.bstAPIPlayerClass = multicharactersPlayerClass;
    }
    
    void SetBastionAPIName(string multicharactersPlayerName) {
        this.multicharactersPlayerName = multicharactersPlayerName;
    }
    
    // Fix this fucking mess.. This is just dumb at this point
    override int GetMultiCharactersPlayerClass() {
        if (GetGame().IsMultiplayer() && GetGame().IsServer()) {
            return multicharactersPlayerClass;
        }
		return bstAPIPlayerClass;
	}

    string GetMultiCharactersPlayerName() {
        return multicharactersPlayerName;
    }
}