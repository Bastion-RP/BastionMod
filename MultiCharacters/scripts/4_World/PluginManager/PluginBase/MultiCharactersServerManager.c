class MultiCharactersServerManager : PluginBase {
    protected ref JsonSerializer jsSerializer;
    protected ref array<string> spawnPoints;
    protected ref array<string> isfSpawnPoints;
    protected string clientMemberId;

    void MultiCharactersServerManager() {
        jsSerializer = new JsonSerializer();
        spawnPoints = new array<string>();
        isfSpawnPoints = new array<string>();

        CheckDirectories();
    }

    void CheckDirectories() {
		if (!FileExist(MCConst.loadoutDir)) {
			MakeDirectory(MCConst.loadoutDir);
		}
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
        CURLCore curlCore;
        MultiCharactersCURL mcCurl;
        CURLContext ctx;
        array<MultiCharactersCharacterId> arrayCharacterData;
        map<string, string> steamData;
        string data, error;
        bool dataFound;

        curlCore = CreateCURLCore();
        mcCurl = new MultiCharactersCURL();
        ctx = curlCore.GetCURLContext("https://bastionrp.com/api/");
        if (jsSerializer.ReadFromString(steamData, ctx.GET_now(MultiCharactersCURLEndpoints.ENDPOINT_BY_STEAM_ID + sender.GetPlainId()), error) && steamData.Contains(MCCurlConst.memberId) && jsSerializer.ReadFromString(arrayCharacterData, ctx.GET_now(MultiCharactersCURLEndpoints.ENDPOINT_BY_MEMBER_ID + steamData.Get(MCCurlConst.memberId)), error) && arrayCharacterData.Count() > 0) {
            auto savePlayerArray = new array<ref SavePlayer>();
            
            foreach (MultiCharactersCharacterId characterData : arrayCharacterData) {
                if (characterData.IsActive()) {
                    SavePlayer savePlayer;
                    string savePlayerDir = MCConst.loadoutDir + "\\" + sender.GetPlainId() + "\\" + characterData.GetCharacterId() + MCConst.fileType;
                    Print(MCConst.debugPrefix + "SAVE DATA DIR | " + savePlayerDir);
                    characterData.PrintData();

                    if (FileExist(savePlayerDir)) {
                        JsonFileLoader<SavePlayer>.JsonLoadFile(savePlayerDir, savePlayer);
                    } else {
                        savePlayer = new SavePlayer();
                        savePlayer.SetDead(true);
                        savePlayer.SetCharacterClass(characterData.GetCitizenClass().ToInt());
                        savePlayer.SetCharacterId(characterData.GetCharacterId().ToInt());
                        savePlayer.SetName(characterData.GetFirstName() + " " + characterData.GetLastName());
                    }
                    savePlayerArray.Insert(savePlayer);
                }
            }
            auto params = new Param1<array<ref SavePlayer>>(savePlayerArray);

            GetGame().RPCSingleParam(null, MultiCharRPC.CLIENT_GRAB_LOADOUTS, params, true, sender);
        } else {
			GetGame().DisconnectPlayer(sender);
            GetGame().RPCSingleParam(null, MultiCharRPC.CLIENT_DISCONNECT, null, true, sender);
        }
    }

    vector GetRandomSpawnpoint() {
        return spawnPoints.GetRandomElement().ToVector();
    }

    vector GetRandomISFSpawnpoint() {
        return isfSpawnPoints.GetRandomElement().ToVector();
    }
}

MultiCharactersServerManager GetMultiCharactersServerManager() {
    return MultiCharactersServerManager.Cast(GetPlugin(MultiCharactersServerManager));
}