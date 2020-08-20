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

        array<ref BST_MCSavePlayer> savePlayerArray;

        switch (rpc_type) {
            case MultiCharRPC.CLIENT_RECEIVE_CONFIG:
                {
                    Param1<BST_MCConfig> dataReceiveConfig;

                    Print("[DEBUG] CLIENT_RECEIVE_CONFIG | Reading data");
                    if (!ctx.Read(dataReceiveConfig)) { return; }
                    Print("[DEBUG] CLIENT_RECEIVE_CONFIG | Data read=" + dataReceiveConfig.param1.GetRespawnTimer());

                    GetBSTMCManager().SetConfig(dataReceiveConfig.param1);
                    break;
                }
            case MultiCharRPC.CLIENT_GRAB_LOADOUTS:
                {
                    Param1<array<ref BST_MCSavePlayer>> dataGrabLoadouts;

                    if (!ctx.Read(dataGrabLoadouts)) { return; }
                    GetMultiCharactersClientManager().SetLoadouts(dataGrabLoadouts.param1);
                    GetMultiCharactersClientManager().HideInitMenu();
                    GetMultiCharactersClientManager().ShowSelectMenu();
                    break;
                }
            case MultiCharRPC.CLIENT_DISCONNECT:
                {
                    GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(GetGame().DisconnectSessionForce, 100, false);
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