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
        string playerClassFull, playerClass, apiRequest, apiPassword;
        array<string> arrPlayerClass;
        Param params;
        
        switch (rpc_type) {
            case BST_DTACRPC.SERVER_API_POST_GENERAL_RECORD:
                {
                    Param2<string, string> dataPOSTGeneral;

                    if (!ctx.Read(dataPOSTGeneral)) { return; }
                    player = PlayerBase.Cast(target);

                    if (!player || dataPOSTGeneral.param1.Length() <= 0) { return; }
                    if (!GetDTACManager().IsRequiredClass(GetDTACServerManager().GetConfig().GetRequiredAPIClasses(), player.GetMultiCharactersPlayerClass())) { return; }
                    apiCore = GetRestApi();

                    if (!apiCore) {
                        apiCore = CreateRestApi();
                    }
                    apiCTX = apiCore.GetRestContext("https://bastionrp.com/api/");
                    apiCallback = new RestCallback();
                    apiPassword = GetDTACServerManager().GetConfig().GetGeneralPassword();
                    apiRequest = "generalrecords.php?password=" + apiPassword + "&charId=" + dataPOSTGeneral.param2 + "&description=" + dataPOSTGeneral.param1 + "&creatorCharId=" + player.GetMultiCharactersPlayerId() + "&isSystem=1";

                    apiCTX.POST(apiCallback, apiRequest, "");
                    break;
                }
            case BST_DTACRPC.SERVER_API_POST_CRIMINAL_RECORD:
                {
                    Param5<string, string, string, string, string> dataPOSTCriminal;

                    if (!ctx.Read(dataPOSTCriminal)) { return; }
                    player = PlayerBase.Cast(target);

                    if (!player) { return; }
                    string txtCrime, txtCrimeDescription, txtCrimePunishment, txtCrimeDate, txtTargetId;

                    txtCrime = dataPOSTCriminal.param1.Trim();
                    txtCrimeDescription = dataPOSTCriminal.param2.Trim();
                    txtCrimePunishment = dataPOSTCriminal.param3.Trim();
                    txtCrimeDate = dataPOSTCriminal.param4.Trim();
                    txtTargetId = dataPOSTCriminal.param5;

                    if (txtCrime.Length() <= 0 || txtCrimeDescription.Length() <= 0 || txtCrimePunishment.Length() <= 0 || txtCrimeDate.Length() <= 0 || txtTargetId.Length() <= 0) { return; }
                    if (!GetDTACManager().IsRequiredClass(GetDTACServerManager().GetConfig().GetRequiredAPIClasses(), player.GetMultiCharactersPlayerClass())) { return; }
                    apiCore = GetRestApi();

                    if (!apiCore) {
                        apiCore = CreateRestApi();
                    }
                    apiCTX = apiCore.GetRestContext("https://bastionrp.com/api/");
                    apiCallback = new RestCallback();
                    apiPassword = GetDTACServerManager().GetConfig().GetCriminalPassword();
                    apiRequest = "criminalrecords.php?password=" + apiPassword + "&charId=" + txtTargetId + "&description=" + txtCrime + "&crimeCommited=" + txtCrimeDescription + "&punishment=" + txtCrimePunishment + "&dateCommited=" + txtCrimeDate + "&creatorCharId=" +  player.GetMultiCharactersPlayerId();

                    apiCTX.POST(apiCallback, apiRequest, "");
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