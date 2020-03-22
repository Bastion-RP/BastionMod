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

        array<ref SavePlayer> savePlayerArray;

        switch (rpc_type) {
            case MultiCharRPC.CLIENT_GRAB_LOADOUTS:
                {
                    Print(MCConst.debugPrefix + "MultiCharactersClientRPCHandler | CLIENT_GRAB_LOADOUTS | Received!");
                    Param1<array<ref SavePlayer>> dataGrabLoadouts;

                    if (!ctx.Read(dataGrabLoadouts)) { return; }
                    Print(MCConst.debugPrefix + "MultiCharactersClientRPCHandler | CLIENT_GRAB_LOADOUTS | Data read!");
                    GetMultiCharactersClientManager().SetLoadouts(dataGrabLoadouts.param1);
                    GetGame().GetUIManager().HideMenu(MultiCharMenu.MENU_WAIT);
                    GetGame().GetUIManager().EnterScriptedMenu(MultiCharMenu.MENU_SPAWN, null);
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
        }
    }
}