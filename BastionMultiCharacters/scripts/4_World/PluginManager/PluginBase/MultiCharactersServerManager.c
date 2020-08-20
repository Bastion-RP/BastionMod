class MultiCharactersServerManager : PluginBase {
    protected ref JsonSerializer jsSerializer;
    protected ref array<string> spawnPoints;
    protected ref array<string> isfSpawnPoints;
    protected ref array<string> isfSpawnGear;
    protected ref BST_MCConfig _config;
    protected string clientMemberId;

    void MultiCharactersServerManager() {
        jsSerializer = new JsonSerializer();
        spawnPoints = new array<string>();
        isfSpawnPoints = new array<string>();

        CheckDirectories();
    }

    void CheckDirectories() {
        BST_MCConfig config;

        if (!FileExist(MCConst.modDir)) {
            MakeDirectory(MCConst.modDir);
        }
        if (!FileExist(MCConst.loadoutDir)) {
            MakeDirectory(MCConst.loadoutDir);
        }
        if (!FileExist(MCConst.configDir)) {
            config = new BST_MCConfig();

            JsonFileLoader<BST_MCConfig>.JsonSaveFile(MCConst.configDir, config);
        } else {
            JsonFileLoader<BST_MCConfig>.JsonLoadFile(MCConst.configDir, config);
        }
        GetBSTMCManager().SetConfig(config);

        if (!FileExist(MCConst.spawnPointDir)) {
            spawnPoints = MultiCharactersDefaultSpawns();
            JsonFileLoader<array<string>>.JsonSaveFile(MCConst.spawnPointDir, spawnPoints);
        } else {
            JsonFileLoader<array<string>>.JsonLoadFile(MCConst.spawnPointDir, spawnPoints);
        }
        if (!FileExist(MCConst.isfSpawnPointDir)) {
            isfSpawnPoints = MultiCharactersDefaultISFSpawns();
            JsonFileLoader<array<string>>.JsonSaveFile(MCConst.isfSpawnPointDir, isfSpawnPoints);
        } else {
            JsonFileLoader<array<string>>.JsonLoadFile(MCConst.isfSpawnPointDir, isfSpawnPoints);
        }
    }

    void GetPlayerLoadouts(PlayerIdentity sender) {
        GetGame().GameScript.Call(this, "ThreadGetPlayerLoadout", sender);
    }

    void ThreadGetPlayerLoadout(PlayerIdentity sender) {
        RestApi curlCore;
        MultiCharactersCURL mcCurl;
        RestContext ctx;
        array<MultiCharactersCharacterId> arrayCharacterData;
        map<string, string> steamData;
        string data, error;
        bool dataFound;

        curlCore = CreateRestApi();
        mcCurl = new MultiCharactersCURL();
        ctx = curlCore.GetRestContext("https://bastionrp.com/api/");
        if (jsSerializer.ReadFromString(steamData, ctx.GET_now(MultiCharactersCURLEndpoints.ENDPOINT_BY_STEAM_ID + sender.GetPlainId()), error) && steamData.Contains(MCCurlConst.memberId) && jsSerializer.ReadFromString(arrayCharacterData, ctx.GET_now(MultiCharactersCURLEndpoints.ENDPOINT_BY_MEMBER_ID + steamData.Get(MCCurlConst.memberId)), error) && arrayCharacterData.Count() > 0) {
            auto savePlayerArray = new array<ref BST_MCSavePlayer>();

            foreach (MultiCharactersCharacterId characterData : arrayCharacterData) {
                if (characterData.IsActive()) {
                    BST_MCSavePlayer savePlayer;
                    string savePlayerDir = MCConst.loadoutDir + "\\" + sender.GetPlainId() + "\\" + characterData.GetCharacterId() + MCConst.fileType;
                    Print(MCConst.debugPrefix + "SAVE DATA DIR | " + savePlayerDir);
                    characterData.PrintData();

                    if (FileExist(savePlayerDir)) {
                        JsonFileLoader<BST_MCSavePlayer>.JsonLoadFile(savePlayerDir, savePlayer);
                    } else {
                        savePlayer = new BST_MCSavePlayer();
                        savePlayer.SetDead(true);
                        savePlayer.SetCharacterClass(characterData.GetCitizenClass().ToInt());
                        savePlayer.SetCharacterId(characterData.GetCharacterId().ToInt());
                        savePlayer.SetName(characterData.GetFirstName() + " " + characterData.GetLastName());
                    }
                    savePlayerArray.Insert(savePlayer);
                }
            }
            auto params = new Param1<array<ref BST_MCSavePlayer>>(savePlayerArray);

            GetGame().RPCSingleParam(null, MultiCharRPC.CLIENT_GRAB_LOADOUTS, params, true, sender);
        } else {
            GetGame().DisconnectPlayer(sender);
            GetGame().RPCSingleParam(null, MultiCharRPC.CLIENT_DISCONNECT, null, true, sender);
        }
        GetGame().GameScript.Release();
    }

    array<string> GetISFSpawnGear() { return isfSpawnGear; }
    vector GetRandomSpawnpoint() { return spawnPoints.GetRandomElement().ToVector(); }
    vector GetRandomISFSpawnpoint() { return isfSpawnPoints.GetRandomElement().ToVector(); }
}

MultiCharactersServerManager GetMultiCharactersServerManager() {
    return MultiCharactersServerManager.Cast(GetPlugin(MultiCharactersServerManager));
}