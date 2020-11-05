class BST_MCServerManager : PluginBase {
    protected ref JsonSerializer _jsSerializer;
    private ref map<string, ref array<ref BST_APICharacterId>> _mapPlayerAPIData;
    private ref map<string, ref array<string>> _mapSpawnPoints;
    private ref BST_MCSpawnConfig _spawnConfig;

    void BST_MCServerManager() {
        _jsSerializer = new JsonSerializer();
        _mapPlayerAPIData = new map<string, ref array<ref BST_APICharacterId>>();
        _mapSpawnPoints = new map<string, ref array<string>>();

        CheckDirectories();
    }

    void CheckDirectories() {
        ref BST_MCConfig config;

        if (!FileExist(BST_MCConst.modDir)) {
            MakeDirectory(BST_MCConst.modDir);
        }
        if (!FileExist(BST_MCConst.loadoutDir)) {
            MakeDirectory(BST_MCConst.loadoutDir);
        }
        if (!FileExist(BST_MCConst.configDir)) {
            config = new BST_MCConfig();
        } else {
            JsonFileLoader<BST_MCConfig>.JsonLoadFile(BST_MCConst.configDir, config);
        }
        if (!FileExist(BST_MCConst.spawnConfigDir)) {
            _spawnConfig = new BST_MCSpawnConfig();
        } else {
            JsonFileLoader<BST_MCSpawnConfig>.JsonLoadFile(BST_MCConst.spawnConfigDir, _spawnConfig);
            _spawnConfig.Validate();
        }
        _mapSpawnPoints = _spawnConfig.GetSpawnGroupMap();

        JsonFileLoader<BST_MCSpawnConfig>.JsonSaveFile(BST_MCConst.spawnConfigDir, _spawnConfig);
        JsonFileLoader<BST_MCConfig>.JsonSaveFile(BST_MCConst.configDir, config);
        GetBSTMCManager().SetConfig(config);
    }

    void GetCharactersByPlayerId(PlayerIdentity sender) {
        GetGame().GameScript.Call(this, "ThreadGetCharactersByPlayerId", sender);
    }

    void ThreadGetCharactersByPlayerId(PlayerIdentity sender) {
        array<ref BST_APICharacterId> arrCharacterData;
        map<string, string> mapData;
        RestApi core;
        RestContext ctx;
        string error, boolWhitelisted, nameForum, nameGame, memberId;
        bool dataFound;

        core = GetRestApi();

        if (!core) {
            core = CreateRestApi();
        }
        ctx = core.GetRestContext("https://bastionrp.com/api/");
        dataFound = _jsSerializer.ReadFromString(mapData, ctx.GET_now(BST_MCAPIEndpoints.STEAM_ID + sender.GetPlainId()), error);

        if (dataFound) {
            if (mapData.Contains(BST_APIConst.memberId)) {
                boolWhitelisted = mapData.Get(BST_APIConst.whitelist);

                boolWhitelisted.ToLower();

                if (boolWhitelisted == "true") {
                    if (mapData.Contains(BST_APIConst.name)) {
                        nameForum = mapData.Get(BST_APIConst.name);
                        nameGame = sender.GetName();

                        if (NamesMatch(nameForum, nameGame)) {
                            if (mapData.Contains(BST_APIConst.memberId)) {
                                memberId = mapData.Get(BST_APIConst.memberId);
                                dataFound = _jsSerializer.ReadFromString(arrCharacterData, ctx.GET_now(BST_MCAPIEndpoints.MEMBER_ID + memberId), error);

                                if (dataFound) {
                                    if (arrCharacterData.Count() > 0) {
                                        array<ref BST_MCSavePlayerBasic> arrSavePlayers = new array<ref BST_MCSavePlayerBasic>();

                                        foreach (BST_APICharacterId characterData : arrCharacterData) {
                                            if (!characterData || !characterData.IsActive()) { continue; }
                                            BST_MCSavePlayerBasic savePlayer;
                                            string savePlayerDir;

                                            savePlayerDir = BST_MCConst.loadoutDir + "\\" + sender.GetPlainId() + "\\" + characterData.GetCharacterId() + ".json";

                                            if (FileExist(savePlayerDir)) {
                                                JsonFileLoader<BST_MCSavePlayerBasic>.JsonLoadFile(savePlayerDir, savePlayer);
                                                savePlayer.PurgeInventoryItems();
                                            } else {
                                                savePlayer = new BST_MCSavePlayerBasic();

                                                savePlayer.SetDead(true);
                                            }
                                            savePlayer.SetAPIData(characterData.GetFirstName() + " " + characterData.GetLastName(), characterData.GetCharacterId().ToInt(), characterData.GetCitizenClass().ToInt());
                                            arrSavePlayers.Insert(savePlayer);
                                        }
                                        if (arrSavePlayers.Count() > 0) {
                                            Param params = new Param1<array<ref BST_MCSavePlayerBasic>>(arrSavePlayers);
                                            Param configParams = new Param1<ref BST_MCConfig>(GetBSTMCManager().GetConfig());

                                            if (_mapPlayerAPIData.Contains(sender.GetPlainId())) {
                                                _mapPlayerAPIData.Set(sender.GetPlainId(), arrCharacterData);
                                            } else {
                                                _mapPlayerAPIData.Insert(sender.GetPlainId(), arrCharacterData);
                                            }
                                            GetGame().RPCSingleParam(null, BST_MCRPC.CLIENT_RECEIVE_CONFIG, configParams, true, sender);
                                            GetGame().RPCSingleParam(null, BST_MCRPC.CLIENT_RECEIVE_CHARACTERS, params, true, sender);
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
                                KickPlayer(sender, -1);
                            }
                        } else {
                            KickPlayer(sender, BST_MCKickReasons.WRONG_NICKNAME);
                        }
                    } else {
                        KickPlayer(sender, -1);
                    }
                } else {
                    KickPlayer(sender, BST_MCKickReasons.NO_WHITELIST);
                }
            } else {
                KickPlayer(sender, -1);
            }
        } else {
            KickPlayer(sender, BST_MCKickReasons.ERROR_STEAM_ID);
        }
    }

    private bool NamesMatch(string forumName, string gameName) {
        forumName.ToLower();
        gameName.ToLower();

        return forumName == gameName;
    }

    private void KickPlayer(PlayerIdentity sender, int reason) {
        if (reason != -1) {
            Param params = new Param1<int>(reason);

            GetGame().RPCSingleParam(null, BST_MCRPC.CLIENT_DISCONNECT, params, true, sender);
        }
        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(GetGame().DisconnectPlayer, 1000, false, sender);
    }

    void RemoveAPIDataById(string identity) {
        _mapPlayerAPIData.Remove(identity);
    }

    bool HasAPIData(string identity) {
        if (_mapPlayerAPIData.Contains(identity)) {
            return true;
        }
        return false;
    }

    vector GetRandomSpawnPointByClass(int charClass) {
        string strCharClass;
        array<string> arrSpawns;

        strCharClass = GetBSTAPIHandler().GetClassNameFromInt(charClass);

        strCharClass.ToUpper();

        if (_mapSpawnPoints.Contains(strCharClass)) {
            return _mapSpawnPoints.Get(strCharClass).GetRandomElement().ToVector();
        } else {
            return _mapSpawnPoints.Get(BST_MCSpawnGroup.CONST_DEFAULT_CLASS).GetRandomElement().ToVector();
        }
    }

    BST_APICharacterId GetAPIDataById(string identity, string charId) {
        array<ref BST_APICharacterId> arrCharData = _mapPlayerAPIData.Get(identity);

        if (arrCharData) {
            foreach (BST_APICharacterId data : arrCharData) {
                if (!data) { continue; }
                if (data.GetCharacterId() == charId) {
                    return data;
                }
            }
        }
        return null;
    }
}

BST_MCServerManager GetBSTMCServerManager() {
    return BST_MCServerManager.Cast(GetPlugin(BST_MCServerManager));
}