class BST_MCServerRPCHandler : PluginBase {
    void BST_MCServerRPCHandler() {
        GetDayZGame().Event_OnRPC.Insert(OnRPC);
    }

    void ~BST_MCServerRPCHandler() {
        GetDayZGame().Event_OnRPC.Remove(OnRPC);
    }

    void OnRPC(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx) {
        if (!sender) { return; }
        
        switch (rpc_type) {
            case BST_MCRPC.SERVER_GRAB_LOADOUTS:
                {
                    GetBSTMCServerManager().GetCharactersByPlayerId(sender);
                    break;
                }
        }
    }
}