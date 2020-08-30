class MultiCharactersClientRPCHandler : PluginBase {
    void MultiCharactersClientRPCHandler() {
        if (GetGame().IsServer() && GetGame().IsMultiplayer()) { return; }

        GetDayZGame().Event_OnRPC.Insert(ClientRPCHandler);
    }

    void ~MultiCharactersClientRPCHandler() {
        GetDayZGame().Event_OnRPC.Remove(ClientRPCHandler);
    }

    void ClientRPCHandler(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx) {
        if (GetGame().IsServer() && GetGame().IsMultiplayer()) { return; }

        switch (rpc_type) {
            case MultiCharRPC.CLIENT_RECEIVE_CONFIG:
                {
                    Param1<ref BST_MCConfig> dataReceiveConfig;

                    if (!ctx.Read(dataReceiveConfig)) { return; }

                    GetBSTMCManager().SetConfig(dataReceiveConfig.param1);
                    break;
                }
            case MultiCharRPC.CLIENT_GRAB_LOADOUTS:
                {
                    Param1<array<ref BST_MCSavePlayerBasic>> dataGrabLoadouts;

                    if (!ctx.Read(dataGrabLoadouts)) { return; }
                    GetMultiCharactersClientManager().SetLoadouts(dataGrabLoadouts.param1);
                    GetMultiCharactersClientManager().HideInitMenu();
                    GetMultiCharactersClientManager().ShowSelectMenu();
                    break;
                }
            case MultiCharRPC.CLIENT_DISCONNECT:
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
            case MultiCharRPC.CLIENT_SPAWN_MAG:
                {
                    Param1<int> magCount;
                    if (!ctx.Read(magCount)) { return; }
                    
                    int magsRemoved = magCount.param1;
                    //NotificationSystem.AddNotification(NotificationType.NOTIFICATIONS_END, 10, "" + magsRemoved + " mag(s) were removed from your weapon(s)\n and placed into your inventory!" );
                    NotificationSystem.AddNotificationExtended(10, "Mags Moved!", "" + magsRemoved + " mag(s) were removed from your weapon(s)\n and placed into your inventory!");
                    break;
                }
            case MultiCharRPC.CLIENT_RECEIVE_PLAYER_API_DATA:
                {
                    Param3<int, string, int> dataAPI;
                    if (!ctx.Read(dataAPI)) { return; }

                    PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());

                    if (player) {
                        player.SetMultiCharacterStats(dataAPI.param1, dataAPI.param2, dataAPI.param3);
                    }
                    break;
                }
        }
    }
}