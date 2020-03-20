class MultiCharactersServerRPCHandler : PluginBase {
    void MultiCharactersServerRPCHandler() {
        GetDayZGame().Event_OnRPC.Insert(ServerRPCHandler);
    }

    void ~MultiCharactersServerRPCHandler() {
        GetDayZGame().Event_OnRPC.Remove(ServerRPCHandler);
    }

    void ServerRPCHandler(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx) {
        if (!sender) { return; }
        
        Print("RECEIVED RPC " + rpc_type);

        switch (rpc_type) {
            case MultiCharRPC.SERVER_GRAB_LOADOUTS:
                {
                    Print(MCConst.debugPrefix + "Server Grab Loadouts");
                    GetMultiCharactersServerManager().GetPlayerLoadouts(sender);
                    Print("YEET");
                    break;
                }
        }
    }
}