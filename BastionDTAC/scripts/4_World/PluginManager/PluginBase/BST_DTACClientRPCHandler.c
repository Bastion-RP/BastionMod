class BST_DTACClientRPCHandler : PluginBase {
    void BST_DTACClientRPCHandler() {
        GetDayZGame().Event_OnRPC.Insert(OnRPC);
    }

    void ~BST_DTACClientRPCHandler() {
        GetDayZGame().Event_OnRPC.Remove(OnRPC);
    }

    void OnRPC(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx) {
        switch (rpc_type) {
            case BST_DTACRPC.CLIENT_RECEIVE_CONFIG:
                {
                    Param1<ref BST_DTACConfig> dataConfig;

                    if (!ctx.Read(dataConfig)) { return; }
                    GetDTACClientManager().SetConfig(dataConfig.param1);
                    break;
                }
            case BST_DTACRPC.CLIENT_RECEIVE_ACTIVE_GROUP:
                {
                    Param2<ref BST_DTACGroup, array<ref BST_DTACGroup>> dataReceiveActiveGroup;

                    if (!ctx.Read(dataReceiveActiveGroup)) { return; }
                    GetDTACClientGroupManager().ReceiveActiveGroup(dataReceiveActiveGroup.param1, dataReceiveActiveGroup.param2);
                    break;
                }
            case BST_DTACRPC.CLIENT_RECEIVE_GROUPS:
                {
                    Param1<array<ref BST_DTACGroup>> dataReceiveGroups;

                    if (!ctx.Read(dataReceiveGroups)) { return; }
                    GetDTACClientGroupManager().ReceiveGroupArray(dataReceiveGroups.param1);
                    break;
                }
            case BST_DTACRPC.CLIENT_ADD_GROUP_MEMBER:
                {
                    Param1<ref BST_DTACPlayerData> dataAddMember;

                    if (!ctx.Read(dataAddMember)) { return; }
                    GetDTACClientGroupManager().AddGroupMember(dataAddMember.param1);
                    break;
                }
            case BST_DTACRPC.CLIENT_LEAVE_GROUP:
                {
                    GetDTACClientGroupManager().InitActiveGroup();
                    BST_DTACClientGroupManager.groupInvoker.Invoke();
                    break;
                }
            case BST_DTACRPC.CLIENT_REMOVE_GROUP_MEMBER:
                {
                    Param1<string> dataRemoveMember;

                    if (!ctx.Read(dataRemoveMember)) { return; }
                    GetDTACClientGroupManager().RemoveGroupMember(dataRemoveMember.param1);
                    break;
                }
            case BST_DTACRPC.CLIENT_RECEIVE_PLAYER_STAT_UPDATE:
                {
                    Param1<ref BST_DTACPlayerData> dataUpdateMember;

                    if (!ctx.Read(dataUpdateMember)) { return; }
                    GetDTACClientGroupManager().UpdateGroupMember(dataUpdateMember.param1);
                    break;
                }
        }
    }
}