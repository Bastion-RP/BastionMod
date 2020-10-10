class MultiCharactersServerManager : PluginBase {
    protected ref JsonSerializer jsSerializer;
    protected ref array<string> spawnPoints;
    protected ref array<string> isfSpawnGear;
    private ref BST_MCConfigSpawnPoints _configSpawnPoints;
    protected ref BST_MCConfig _config;
    protected string clientMemberId;

    void MultiCharactersServerManager() {
        jsSerializer = new JsonSerializer();
        spawnPoints = new array<string>();

        CheckDirectories();
    }

    void CheckDirectories() {
        ref BST_MCConfig config;

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
            _configSpawnPoints = new BST_MCConfigSpawnPoints();

            JsonFileLoader<BST_MCConfigSpawnPoints>.JsonSaveFile(MCConst.spawnPointDir, _configSpawnPoints);
        } else {
            JsonFileLoader<BST_MCConfigSpawnPoints>.JsonLoadFile(MCConst.spawnPointDir, _configSpawnPoints);
        }
    }

    void GetPlayerLoadouts(PlayerIdentity sender) {
        GetGame().GameScript.Call(this, "ThreadGetPlayerLoadout", sender);
    }

    void ThreadGetPlayerLoadout(PlayerIdentity sender) {
        RestApi curlCore;
        MultiCharactersCURL mcCurl;
        RestContext ctx;
        array<MultiCharactersCharacterId> arrCharacterData;
        map<string, string> steamData;
        string data, error;
        bool dataFound;

        curlCore = CreateRestApi();
        mcCurl = new MultiCharactersCURL();
        ctx = curlCore.GetRestContext("https://bastionrp.com/api/");

        if (jsSerializer.ReadFromString(steamData, ctx.GET_now(MultiCharactersCURLEndpoints.ENDPOINT_BY_STEAM_ID + sender.GetPlainId()), error)) {
            if (steamData.Contains(MCCurlConst.whitelist)) {
                string whitelistBoolean = steamData.Get(MCCurlConst.whitelist);

                whitelistBoolean.ToLower();

                if (whitelistBoolean == "true") {
                    string forumName = steamData.Get(MCCurlConst.name);
                    string gameName = sender.GetName();
                    if (NamesMatch(forumName, gameName)) {
                        if (steamData.Contains(MCCurlConst.memberId)) {
                            string memberId = steamData.Get(MCCurlConst.memberId);

                            if (jsSerializer.ReadFromString(arrCharacterData, ctx.GET_now(MultiCharactersCURLEndpoints.ENDPOINT_BY_MEMBER_ID + memberId), error)) {
                                if (arrCharacterData.Count() > 0) {
                                    array<ref BST_MCSavePlayerBasic> arrSavePlayers = new array<ref BST_MCSavePlayerBasic>();
                                    
                                    foreach (MultiCharactersCharacterId characterData : arrCharacterData) {
                                        if (!characterData || !characterData.IsActive()) { continue; }
                                        BST_MCSavePlayerBasic savePlayer;
                                        string savePlayerDir;

                                        savePlayerDir = MCConst.loadoutDir + "\\" + sender.GetPlainId() + "\\" + characterData.GetCharacterId() + MCConst.fileType;

                                        if (FileExist(savePlayerDir)) {
                                            JsonFileLoader<BST_MCSavePlayerBasic>.JsonLoadFile(savePlayerDir, savePlayer);
                                            savePlayer.PurgeInventoryItems();
                                        } 
                                        else {
                                            savePlayer = new BST_MCSavePlayerBasic();
                                            
                                            savePlayer.SetDead(true);
                                            savePlayer.SetAPIData(characterData.GetFirstName() + " " + characterData.GetLastName(), characterData.GetCharacterId().ToInt(), characterData.GetCitizenClass().ToInt());
                                        }
                                        arrSavePlayers.Insert(savePlayer);
                                    }
                                    if (arrSavePlayers.Count() > 0) {
                                        Param params = new Param1<array<ref BST_MCSavePlayerBasic>>(arrSavePlayers);
                                        Param configParams = new Param1<ref BST_MCConfig>(GetBSTMCManager().GetConfig());

                                        GetGame().RPCSingleParam(null, MultiCharRPC.CLIENT_RECEIVE_CONFIG, configParams, true, sender);
                                        GetGame().RPCSingleParam(null, MultiCharRPC.CLIENT_GRAB_LOADOUTS, params, true, sender);
                                    } else {
                                        KickPlayer(sender, BST_MCKickReasons.NO_ACTIVE_CHARACTERS);
                                    }
                                } else {
                                    KickPlayer(sender, BST_MCKickReasons.NO_CHARACTERS);
                                }
                            } else {
                                KickPlayer(sender, BST_MCKickReasons.ERROR_NO_CHARACTER);
                            }
                        } else {
                            KickPlayer(sender, BST_MCKickReasons.ERORR_NO_MEMBER_ID);
                        }
                    } else {
                        KickPlayer(sender, BST_MCKickReasons.WRONG_NICKNAME);
                    }
                } else {
                    KickPlayer(sender, BST_MCKickReasons.NO_WHITELIST);
                }
            }
        } else {
            KickPlayer(sender, BST_MCKickReasons.ERROR_STEAM_ID);
        }
        GetGame().GameScript.Release();
    }

    private void KickPlayer(PlayerIdentity sender, int reason) {
        Param params = new Param1<int>(reason);

        GetGame().RPCSingleParam(null, MultiCharRPC.CLIENT_DISCONNECT, params, true, sender);
        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(GetGame().DisconnectPlayer, 1000, false, sender);
        //GetGame().DisconnectPlayer(sender);
    }

    bool NamesMatch(string forumName, string gameName) {
        forumName.ToLower();
        gameName.ToLower();

		return forumName == gameName;
	}

    vector GetRandomSpawnByClass(int charClass) {
        return _configSpawnPoints.GetRandomSpawnPointbyClass(charClass);
    }
}

MultiCharactersServerManager GetMultiCharactersServerManager() {
    return MultiCharactersServerManager.Cast(GetPlugin(MultiCharactersServerManager));
}