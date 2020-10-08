class BST_MCClientRPCHandler : PluginBase {
    void BST_MCClientRPCHandler() {
        Print("[DEBUG] Creating client RPC Handler!");
        GetDayZGame().Event_OnRPC.Insert(OnRPC);
    }

    void ~BST_MCClientRPCHandler() {
        GetDayZGame().Event_OnRPC.Remove(OnRPC);
    }

    void OnRPC(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx) {
        switch (rpc_type) {
            case BST_MCRPC.CLIENT_RELOAD_MAG:
                {
                    Param1<Magazine> dataReloadMag;
                    Print("[DEBUG] Received reload mag RPC");
                    if (!ctx.Read(dataReloadMag)) { return; }
                    Print("[DEBUG] Data read");

                    Magazine magToReload = dataReloadMag.param1;

                    PlayerBase.Cast(GetGame().GetPlayer()).LocalDropEntity(magToReload);
                    PlayerBase.Cast(GetGame().GetPlayer()).GetWeaponManager().AttachMagazine(magToReload);
                    break;
                }
            case BST_MCRPC.CLIENT_RECEIVE_CONFIG:
                {
                    Param1<ref BST_MCConfig> dataReceiveConfig;

                    if (!ctx.Read(dataReceiveConfig)) { return; }

                    GetBSTMCManager().SetConfig(dataReceiveConfig.param1);
                    break;
                }
            case BST_MCRPC.CLIENT_RECEIVE_CHARACTERS:
                {
                    Print("[DEBUG] RECEIVED LOADOUTS");
                    Param1<array<ref BST_MCSavePlayerBasic>> dataGrabLoadouts;

                    if (!ctx.Read(dataGrabLoadouts)) { return; }
                    Print("[DEBUG] RECEIVED LOADOUTS");
                    GetBSTMCClientManager().SetCharacters(dataGrabLoadouts.param1);
                    GetBSTMCClientManager().HideInitMenu();
                    GetBSTMCClientManager().ShowSelectMenu();
                    break;
                }
            case BST_MCRPC.CLIENT_DISCONNECT:
                {
                    Param1<int> dataDisconnect;

                    if (ctx.Read(dataDisconnect)) {
                        string notificationText, notificationTitle;

                        switch (dataDisconnect.param1) {
                            case BST_MCKickReasons.ERROR_STEAM_ID:
                                {
                                    notificationTitle = "Error: SteamID";
                                    notificationText = "No profile with your SteamID could be found!";
                                    break;
                                }
                            case BST_MCKickReasons.ERORR_NO_MEMBER_ID:
                                {
                                    notificationTitle = "Error: Member ID";
                                    notificationText = "Member ID not found! Notify an admin immediately!";
                                    break;
                                }
                            case BST_MCKickReasons.ERROR_NO_CHARACTER:
                                {
                                    notificationTitle = "Error: No Character";
                                    notificationText = "There was an issue looking for your characters!";
                                    break;
                                }
                            case BST_MCKickReasons.NO_WHITELIST:
                                {
                                    notificationTitle = "Not Whitelisted";
                                    notificationText = "You are not whitelisted! Apply for whitelist at BastionRP.com!";
                                    break;
                                }
                            case BST_MCKickReasons.NO_CHARACTERS:
                                {
                                    notificationTitle = "No Character";
                                    notificationText = "You do not have any characters! You must have a character to play!";
                                    break;
                                }
                            case BST_MCKickReasons.NO_ACTIVE_CHARACTERS:
                                {
                                    notificationTitle = "No Active Character";
                                    notificationText = "You do not have any active characters!";
                                    break;
                                }
                            case BST_MCKickReasons.WRONG_NICKNAME:
                                {
                                    notificationTitle = "Wrong In-Game-Name";
                                    notificationText = "Your DayZ In-Game-Name and your BastionRP Forum Name must match!";
                                    break;
                                }
                        }
                        NotificationSystem.AddNotificationExtended(10, notificationTitle, notificationText);
                    }
		            //GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Call(GetGame().DisconnectSessionForce);
                    break;
                }
            case BST_MCRPC.CLIENT_SPAWN_MAG:
                {
                    Param1<int> magCount;
                    if (!ctx.Read(magCount)) { return; }
                    
                    int magsRemoved = magCount.param1;
                    //NotificationSystem.AddNotification(NotificationType.NOTIFICATIONS_END, 10, "" + magsRemoved + " mag(s) were removed from your weapon(s)\n and placed into your inventory!" );
                    NotificationSystem.AddNotificationExtended(10, "Mags Moved!", "" + magsRemoved + " mag(s) were removed from your weapon(s)\n and placed into your inventory!");
                    break;
                }
            case BST_MCRPC.CLIENT_RECEIVE_PLAYER_API_DATA:
                {
                    Param3<int, string, int> dataAPI;
                    if (!ctx.Read(dataAPI)) { return; }

                    PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());

                    if (player) {
                        player.BSTMCSetCharData(dataAPI.param1, dataAPI.param2, dataAPI.param3);
                    }
                    break;
                }
        }
    }
}