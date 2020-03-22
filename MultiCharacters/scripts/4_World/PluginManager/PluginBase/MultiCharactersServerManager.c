class MultiCharactersServerManager : PluginBase {
    protected ref JsonSerializer jsSerializer;
    protected ref array<string> spawnPoints;
    protected string clientMemberId;

    void MultiCharactersServerManager() {
        jsSerializer = new JsonSerializer();
        spawnPoints = new array<string>();

        CheckDirectories();
    }

    void CheckDirectories() {
		if (!FileExist(MCConst.loadoutDir)) {
			MakeDirectory(MCConst.loadoutDir);
		}
		if (!FileExist(MCConst.spawnPointDir)) {
			JsonFileLoader<array<string>>.JsonSaveFile(MCConst.spawnPointDir, MultiCharactersDefaultSpawns());
		} else {
			JsonFileLoader<array<string>>.JsonLoadFile(MCConst.spawnPointDir, spawnPoints);
        }
    }

    void GetPlayerLoadouts(PlayerIdentity sender) {
        GetGame().GameScript.Call(this, "ThreadGetPlayerLoadout", sender);
    }

    void ThreadGetPlayerLoadout(PlayerIdentity sender) {
        CURLCore curlCore;
        MultiCharactersCURL mcCurl;
        CURLContext ctx;
        array<MultiCharactersCharacterId> arrayCurlData;
        map<string, string> curlData;
        string data, error;
        bool dataFound;

        curlCore = CreateCURLCore();
        mcCurl = new MultiCharactersCURL();
        ctx = curlCore.GetCURLContext("https://bastionrp.com/api/");
        data = ctx.GET_now(MultiCharactersCURLEndpoints.ENDPOINT_BY_STEAM_ID + sender.GetPlainId());

        if (jsSerializer.ReadFromString(curlData, data, error)) {
            Print(MCConst.debugPrefix + "First read from string: " + curlData);
            if (curlData.Contains(MCCurlConst.memberId)) {
                data = ctx.GET_now(MultiCharactersCURLEndpoints.ENDPOINT_BY_MEMBER_ID + curlData.Get(MCCurlConst.memberId));

                if (jsSerializer.ReadFromString(arrayCurlData, data, error)) {
                    auto savePlayerArray = new array<ref SavePlayer>();
                    
                    foreach (MultiCharactersCharacterId characterData : arrayCurlData) {
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
                                savePlayer.SetCharacterId(characterData.GetCharacterId().ToInt());
                                savePlayer.SetName(characterData.GetFirstName() + " " + characterData.GetLastName());
                            }
                            savePlayerArray.Insert(savePlayer);
                        }
                    }
                    if (savePlayerArray.Count() > 0) {
                        dataFound = true;
                        auto params = new Param1<array<ref SavePlayer>>(savePlayerArray);
		                //PlayerBase newPlayer = PlayerBase.Cast(GetGame().CreatePlayer(sender, "SurvivorF_Gabi", "0 0 0", 0, "NONE"));

                        GetGame().RPCSingleParam(null, MultiCharRPC.CLIENT_GRAB_LOADOUTS, params, true, sender);
		                //GetGame().SelectPlayer(sender, newPlayer);
                    } else {
                    }
                }
            }
        }
        if (!dataFound) {
			GetGame().DisconnectPlayer(sender);
            GetGame().RPCSingleParam(null, MultiCharRPC.CLIENT_DISCONNECT, null, true, sender);
        }
    }

    vector GetRandomSpawnpoint() {
        return spawnPoints.GetRandomElement().ToVector();
    }
}

MultiCharactersServerManager GetMultiCharactersServerManager() {
    return MultiCharactersServerManager.Cast(GetPlugin(MultiCharactersServerManager));
}