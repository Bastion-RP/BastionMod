class DTACServerRPCHandler : PluginBase {
    void DTACServerRPCHandler() {
        GetDayZGame().Event_OnRPC.Insert(OnRPC);
    }

    void ~DTACServerRPCHandler() {
        GetDayZGame().Event_OnRPC.Remove(OnRPC);
    }

    void OnRPC(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx) {
        if (!sender) { return; }

        PlayerBase player;
        int groupId;
        Param params;
        
        switch (rpc_type) {
            case DTACRPC.SERVER_SEND_GROUP_ARRAY:
                {
                    Print("[DEBUG] DTACServerRPCHandler | OnRPC | SERVER_SEND_GROUP_ARRAY | Received RPC call");
                    player = PlayerBase.Cast(target);

                    if (player) {
                        Print("[DEBUG] DTACServerRPCHandler | OnRPC | SERVER_SEND_GROUP_ARRAY | Player found");
                        params = new Param1<array<ref DTACGroup>>(GetDTACServerGroupManager().GetGroups());

                        GetGame().RPCSingleParam(player, DTACRPC.CLIENT_RECEIVE_GROUPS, params, true, sender);
                    }
                    break;
                }
            case DTACRPC.SERVER_JOIN_GROUP:
                {
                    Param1<int> dataJoinGroup;
                    
                    if (!ctx.Read(dataJoinGroup)) { return; }
                    Print("[DEBUG] DTACServerRPCHandler | OnRPC | SERVER_JOIN_GROUP | Received RPC call");
                    player = PlayerBase.Cast(target);
                    groupId = dataJoinGroup.param1;

                    if (player) {
                        Print("[DEBUG] DTACServerRPCHandler | OnRPC | SERVER_JOIN_GROUP | Player found");
                        DTACGroupManager.dtacRemovalInvoker.Invoke(player.GetIdentity().GetId());
                        GetDTACServerGroupManager().AddUserToGroup(player, groupId);
                    }
                    break;
                }
            case DTACRPC.SERVER_LEAVE_GROUP:
                {
                    Print("[DEBUG] DTACServerRPCHandler | OnRPC | SERVER_LEAVE_GROUP | Received RPC call");
                    player = PlayerBase.Cast(target);

                    if (player) {
                        Print("[DEBUG] DTACServerRPCHandler | OnRPC | SERVER_LEAVE_GROUP | Removing player");
                        params = new Param1<array<ref DTACGroup>>(GetDTACServerGroupManager().GetGroups());

                        GetDTACServerGroupManager().RemoveUserFromGroup(player);
                        GetGame().RPCSingleParam(player, DTACRPC.CLIENT_RECEIVE_GROUPS, params, true, player.GetIdentity());
                    }
                    break;
                }
        }
    }
}