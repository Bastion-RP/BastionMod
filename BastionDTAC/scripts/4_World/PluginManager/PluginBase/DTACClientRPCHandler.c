class DTACClientRPCHandler : PluginBase {
    void DTACClientRPCHandler() {
        GetDayZGame().Event_OnRPC.Insert(OnRPC);
    }

    void ~DTACClientRPCHandler() {
        GetDayZGame().Event_OnRPC.Remove(OnRPC);
    }

    void OnRPC(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx) {
        switch (rpc_type) {
            case DTACRPC.CLIENT_RECEIVE_PLAYER_API_DATA:
                {
                    Print("[DEBUG] DTACClientRPCHandler | OnRPC | CLIENT_RECEIVE_PLAYER_API_DATA | Reading data");
                    Param3<int, string, int> dataAPI;

                    if (!ctx.Read(dataAPI)) { return; }
                    Print("[DEBUG] DTACClientRPCHandler | OnRPC | CLIENT_RECEIVE_PLAYER_API_DATA | Data read");
                    Print("[DEBUG] DTACClientRPCHandler | OnRPC | CLIENT_RECEIVE_PLAYER_API_DATA | param1=" + dataAPI.param1 + " | param3=" + dataAPI.param3);
                    Print("[DTAC DEBUG] 1=" + dataAPI.param1 + " 2=" + dataAPI.param2 + " 3=" + dataAPI.param3);

                    PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());

                    if (player) {
                        player.SetBastionAPIID(dataAPI.param1);
                        player.SetBastionAPIClass(dataAPI.param3);
                        player.SetBastionAPIName(dataAPI.param2);

                        Print("[DTAC DEBUG] id=" + player.GetMultiCharactersPlayerId() + " class=" + player.GetMultiCharactersPlayerClass() + " name=" + player.GetMultiCharactersPlayerName());
                    }
                    break;
                }
            case DTACRPC.CLIENT_RECEIVE_ACTIVE_GROUP:
                {
                    Print("[DEBUG] DTACClientRPCHandler | OnRPC | CLIENT_RECEIVE_ACTIVE_GROUP | Reading data");
                    Param2<ref DTACGroup, array<ref DTACGroup>> dataReceiveActiveGroup;

                    if (!ctx.Read(dataReceiveActiveGroup)) { return; }
                    Print("[DEBUG] DTACClientRPCHandler | OnRPC | CLIENT_RECEIVE_ACTIVE_GROUP | Data read");
                    GetDTACClientGroupManager().ReceiveActiveGroup(dataReceiveActiveGroup.param1, dataReceiveActiveGroup.param2);
                    break;
                }
            case DTACRPC.CLIENT_RECEIVE_GROUPS:
                {
                    Print("[DEBUG] DTACClientRPCHandler | OnRPC | CLIENT_RECEIVE_GROUPS | Reading data");
                    Param1<array<ref DTACGroup>> dataReceiveGroups;

                    if (!ctx.Read(dataReceiveGroups)) { return; }
                    Print("[DEBUG] DTACClientRPCHandler | OnRPC | CLIENT_RECEIVE_GROUPS | Data read");
                    GetDTACClientGroupManager().ReceiveGroupArray(dataReceiveGroups.param1);
                    break;
                }
            case DTACRPC.CLIENT_ADD_GROUP_MEMBER:
                {
                    Print("[DEBUG] DTACClientRPCHandler | OnRPC | CLIENT_ADD_GROUP_MEMBER | Reading data");
                    Param1<ref DTACPlayerData> dataAddMember;

                    if (!ctx.Read(dataAddMember)) { return; }
                    Print("[DEBUG] DTACClientRPCHandler | OnRPC | CLIENT_ADD_GROUP_MEMBER | Data read");
                    GetDTACClientGroupManager().AddGroupMember(dataAddMember.param1);
                    break;
                }
            case DTACRPC.CLIENT_LEAVE_GROUP:
                {
                    Print("[DEBUG] DTACClientRPCHandler | OnRPC | CLIENT_LEAVE_GROUP | Reading data");
                    GetDTACClientGroupManager().InitActiveGroup();
                    DTACClientGroupManager.groupInvoker.Invoke();
                    break;
                }
            case DTACRPC.CLIENT_REMOVE_GROUP_MEMBER:
                {
                    Print("[DEBUG] DTACClientRPCHandler | OnRPC | CLIENT_REMOVE_GROUP_MEMBER | Reading data");
                    Param1<string> dataRemoveMember;

                    if (!ctx.Read(dataRemoveMember)) { return; }
                    Print("[DEBUG] DTACClientRPCHandler | OnRPC | CLIENT_REMOVE_GROUP_MEMBER | Data read");
                    GetDTACClientGroupManager().RemoveGroupMember(dataRemoveMember.param1);
                    break;
                }
            case DTACRPC.CLIENT_RECEIVE_PLAYER_STAT_UPDATE:
                {
                    Print("[DEBUG] DTACClientRPCHandler | OnRPC | CLIENT_RECEIVE_PLAYER_STAT_UPDATE | Reading data");
                    Param1<ref DTACPlayerData> dataUpdateMember;

                    if (!ctx.Read(dataUpdateMember)) { return; }
                    Print("[DEBUG] DTACClientRPCHandler | OnRPC | CLIENT_REMOVE_GROUP_MEMBER | Data read");
                    GetDTACClientGroupManager().UpdateGroupMember(dataUpdateMember.param1);
                    break;
                }
        }
    }
}