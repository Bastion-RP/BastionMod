/* modded class MissionServer {
    private int m_PlayerIndex;
    // Only load the file when a new character is created. There's literally no other reason to load from a file. 
    // The game stores shit in a database for a reason.

    void MissionServer() {
        if (!FileExist(BBConst.profileDir)) {
            MakeDirectory(BBConst.profileDir);
        }
        if (!FileExist(BBConst.profileDir + BBConst.modFolder)) {
            MakeDirectory(BBConst.profileDir + BBConst.modFolder);
        }
        if (!FileExist(BBConst.profileDir + BBConst.modFolder + BBConst.playerFolder)) {
            MakeDirectory(BBConst.profileDir + BBConst.modFolder + BBConst.playerFolder);
        }
    }

    override void OnEvent(EventType eventTypeId, Param params) {
        super.OnEvent(eventTypeId, params);

        switch (eventTypeId) {
            case ClientNewEventTypeID:
                {
                    ClientNewEventParams newParams;
                    Class.CastTo(newParams, params);

                    LoadPlayerBanking();
                }
        }
    }

    private void LoadPlayerBanking() {
        string playerId = m_player.GetIdentity().GetPlainId();
        string profileDir = BBConst.playerDir + playerId;
        string clientDir = profileDir + "\\" + m_PlayerIndex + BBConst.fileType;
        map<string, int> mapBanking = new map<string, int>();

        if (!FileExist(profileDir)) {
            MakeDirectory(profileDir);
        }
        if (!FileExist(clientDir)) {
            mapBanking.Insert(BBConst.mapStored, 0);
            mapBanking.Insert(BBConst.mapOverflow, 0);
            JsonFileLoader<map<string, int>>.JsonSaveFile(clientDir, mapBanking);
        } else {
            JsonFileLoader<map<string, int>>.JsonLoadFile(clientDir, mapBanking);
        }

        m_player.LoadPlayerBankAccount(mapBanking);
        m_player.StartWageTimer();
    }

    PlayerBase OnClientNewEvent(PlayerIdentity identity, vector pos, ParamsReadContext ctx) {
        super.OnClientNewEvent(identity, pos, ctx);

        string playerId = identity.GetPlainId();
        string profileDir = BBConst.playerDir + playerId;
        string clientDir = profileDir + "\\" + m_PlayerIndex + BBConst.fileType;
        map<string, int> mapBanking = new map<string, int>();

        if (!FileExist(profileDir)) {
            MakeDirectory(profileDir);
        }
        if (!FileExist(clientDir)) {
            mapBanking.Insert(BBConst.mapStored, 0);
            mapBanking.Insert(BBConst.mapOverflow, 0);
            JsonFileLoader<map<string, int>>.JsonSaveFile(clientDir, mapBanking);
        } else {
            JsonFileLoader<map<string, int>>.JsonLoadFile(clientDir, mapBanking);
        }

        m_player.LoadPlayerBankAccount(mapBanking);
        m_player.StartWageTimer();

        return m_player;
    }
} */