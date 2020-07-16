class BRP_NameTagsSrv_NameTagsHandler {



    void BRP_NameTagsSrv_NameTagsHandler () {

        // start position updates
        //GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(SendPosUpdate, 10000, true);
    };

    ref map<string, vector> BRP_NameTagsSrv_NameTags_t_MapPlayers;

    void SendPosUpdate () {
        delete BRP_NameTagsSrv_NameTags_t_MapPlayers;
        
        array<Man> BRP_NameTagsSrv_NameTags_t_Players = new array<Man>;
        GetGame().GetWorld().GetPlayerList(BRP_NameTagsSrv_NameTags_t_Players);

        BRP_NameTagsSrv_NameTags_t_MapPlayers = new map<string, vector>;

		for ( int i = 0; i < BRP_NameTagsSrv_NameTags_t_Players.Count(); i++ ) {
            Man BRP_NameTagsSrv_NameTags_t_Man = BRP_NameTagsSrv_NameTags_t_Players.Get(i);

            BRP_NameTagsSrv_NameTags_t_MapPlayers.Insert(BRP_NameTagsSrv_NameTags_t_Man.GetIdentity().GetId(), BRP_NameTagsSrv_NameTags_t_Man.GetPosition());
        };

        GetRPCManager().SendRPC("BRP_NameTags", "UpdatePositionsRPC", new Param1<ref map<string, vector>>(BRP_NameTagsSrv_NameTags_t_MapPlayers), true, NULL);
    };

};