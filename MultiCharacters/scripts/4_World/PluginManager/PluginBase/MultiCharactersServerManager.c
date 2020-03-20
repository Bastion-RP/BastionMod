class MultiCharactersServerManager : PluginBase {
    protected ref JsonSerializer jsSerializer;
    protected string clientMemberId;

    void MultiCharactersServerManager() {
        jsSerializer = new JsonSerializer();

        CheckDirectories();
    }

    void CheckDirectories() {
		if (!FileExist(MCConst.loadoutDir)) {
			MakeDirectory(MCConst.loadoutDir);
		}
		if (!FileExist(MCConst.spawnPointDir)) {
			JsonFileLoader<array<vector>>.JsonSaveFile(MCConst.spawnPointDir, DefaultSpawns());
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

        curlCore = CreateCURLCore();
        mcCurl = new MultiCharactersCURL();
        ctx = curlCore.GetCURLContext("https://bastionrp.com/api/");
        data = ctx.GET_now(MultiCharactersCURLEndpoints.ENDPOINT_BY_STEAM_ID + sender.GetPlainId());

        if (jsSerializer.ReadFromString(curlData, data, error)) {
            Print("First read from string: " + curlData);
            if (curlData.Contains(MCCurlConst.memberId)) {
                data = ctx.GET_now(MultiCharactersCURLEndpoints.ENDPOINT_BY_MEMBER_ID + curlData.Get(MCCurlConst.memberId));

                if (jsSerializer.ReadFromString(arrayCurlData, data, error)) {
                    auto savePlayerArray = new array<ref SavePlayer>();
                    
                    foreach (MultiCharactersCharacterId characterData : arrayCurlData) {
                        if (characterData.IsActive()) {
                            SavePlayer savePlayer;
                            string savePlayerDir = MCConst.loadoutDir + "\\" + sender.GetPlainId() + "\\" + characterData.GetCharacterId() + MCConst.fileType;
                            Print("[DEBUG] SAVE DATA DIR | " + savePlayerDir);
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
                        auto params = new Param1<array<ref SavePlayer>>(savePlayerArray);
		                //PlayerBase newPlayer = PlayerBase.Cast(GetGame().CreatePlayer(sender, "SurvivorF_Gabi", "0 0 0", 0, "NONE"));

                        GetGame().RPCSingleParam(null, MultiCharRPC.CLIENT_GRAB_LOADOUTS, params, true, sender);
		                //GetGame().SelectPlayer(sender, newPlayer);
                    } else {
                        GetGame().RPCSingleParam(null, MultiCharRPC.CLIENT_DISCONNECT, null, true, sender);
                    }
                }
            }
            Print("Found web member, " + data);

        }
    }

/*     void ProcessCURLData(string data) {
        Print("[DEBUG] Processing CURL data");
        array<MultiCharactersCharacterId> arrayWebCharacters;
        MultiCharactersPlayerId webMember;
        string error;

        if (jsSerializer.ReadFromString(webMember, data, error)) {
            Print("[DEBUG] Found member by steam id! " + error);
            if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) {
                clientMemberId
            }
            SendMultiCharactersCURLRequest(MultiCharactersCURLEndpoints.ENDPOINT_BY_MEMBER_ID, webMember.GetMemberId());
        } else if (jsSerializer.ReadFromString(arrayWebCharacters, data, error)) {
            Print("[DEBUG] Found characters by member id! " + error);
            GetPlayerLoadouts(arrayWebCharacters);
        }
    }

    void GetPlayerLoadouts(array<MultiCharactersCharacterId> arrayWebCharacters) {
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) {
            array<string> characterIds = new array<string>();
            auto rpc_params = new array<ref Param>();
            string memberId;
            Print("[DEBUG] Getting player loadouts!");

            foreach (MultiCharactersCharacterId webCharacter : arrayWebCharacters) {
                webCharacter.PrintData();
                characterIds.Insert(webCharacter.GetCharacterId());
            }
            RPCSingleParam(null, MultiCharRPC.SERVER_GRAB_LOADOUTS, params, true);
        }
    }

    int GetWebMemberIdBySteamId(string steam64Id) {
    } */
}

MultiCharactersServerManager GetMultiCharactersServerManager() {
    return MultiCharactersServerManager.Cast(GetPlugin(MultiCharactersServerManager));
}