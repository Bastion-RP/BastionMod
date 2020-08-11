class BST_DTACServerRPCHandler : PluginBase {
    void BST_DTACServerRPCHandler() {
        GetDayZGame().Event_OnRPC.Insert(OnRPC);
    }

    void ~BST_DTACServerRPCHandler() {
        GetDayZGame().Event_OnRPC.Remove(OnRPC);
    }

    void OnRPC(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx) {
        if (!sender) { return; }

        RestApi apiCore;
        RestContext apiCTX;
        RestCallback apiCallback;
        PlayerBase player;
        int groupId;
        string playerClassFull, playerClass, apiRequest;
        array<string> arrPlayerClass;
        Param params;
        
        switch (rpc_type) {
            case BST_DTACRPC.SERVER_API_POST_GENERAL_RECORD:
                {
                    Param2<string, string> dataPOSTGeneral;

                    if (!ctx.Read(dataPOSTGeneral)) { return; }
                    player = PlayerBase.Cast(target);

                    if (player && dataPOSTGeneral.param1.Length() > 0) {
                        if (GetDTACManager().IsRequiredClass(GetDTACServerManager().GetConfig().GetRequiredAPIClasses(), player.GetMultiCharactersPlayerClass())) {
                            apiCore = GetRestApi();

                            if (!apiCore) {
                                apiCore = CreateRestApi();
                            }
                            apiCTX = apiCore.GetRestContext("https://bastionrp.com/api/");
                            apiCallback = new RestCallback();
                            apiRequest = "generalrecords.php?password=" + GetDTACServerManager().GetConfig().GetGeneralPassword() + "&charId=" + dataPOSTGeneral.param2 + "&description=" + dataPOSTGeneral.param1 + "&creatorCharId=" + player.GetMultiCharactersPlayerId() + "&isSystem=1";

                            apiCTX.POST(apiCallback, apiRequest, "");
                        }
                    }
                    break;
                }
            case BST_DTACRPC.SERVER_SEND_GROUP_ARRAY:
                {
                    player = PlayerBase.Cast(target);

                    if (player) {
                        params = new Param1<array<ref BST_DTACGroup>>(GetDTACServerGroupManager().GetGroups());

                        GetGame().RPCSingleParam(player, BST_DTACRPC.CLIENT_RECEIVE_GROUPS, params, true, sender);
                    }
                    break;
                }
            case BST_DTACRPC.SERVER_JOIN_GROUP:
                {
                    Param1<int> dataJoinGroup;
                    
                    if (!ctx.Read(dataJoinGroup)) { return; }
                    player = PlayerBase.Cast(target);
                    groupId = dataJoinGroup.param1;

                    if (player) {
                        BST_DTACGroupManager.dtacRemovalInvoker.Invoke(player.GetIdentity().GetId());
                        GetDTACServerGroupManager().AddUserToGroup(player, groupId);
                    }
                    break;
                }
            case BST_DTACRPC.SERVER_LEAVE_GROUP:
                {
                    player = PlayerBase.Cast(target);

                    if (player) {
                        params = new Param1<array<ref BST_DTACGroup>>(GetDTACServerGroupManager().GetGroups());

                        GetDTACServerGroupManager().RemoveUserFromGroup(player);
                        GetGame().RPCSingleParam(player, BST_DTACRPC.CLIENT_RECEIVE_GROUPS, params, true, player.GetIdentity());
                    }
                    break;
                }
        }
    }
}