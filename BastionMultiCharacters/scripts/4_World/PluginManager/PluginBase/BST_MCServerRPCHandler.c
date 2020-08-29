class BST_MCServerRPCHandler : PluginBase {
    void BST_MCServerRPCHandler() {
        GetDayZGame().Event_OnRPC.Insert(ServerRPCHandler);
    }

    void ~BST_MCServerRPCHandler() {
        GetDayZGame().Event_OnRPC.Remove(ServerRPCHandler);
    }

    void ServerRPCHandler(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx) {
        if (!sender) { return; }
        
        switch (rpc_type) {
            case BST_MCRPC.SERVER_GRAB_LOADOUTS:
                {
                    Print(MCConst.debugPrefix + "ServerRPCHandler | SERVER_GRAB_LOADOUTS | Grabbing loadouts!");
                    GetBSTMCServerManager().ThreadGetPlayerLoadout(sender);
                    break;
                }
        }
    }
}