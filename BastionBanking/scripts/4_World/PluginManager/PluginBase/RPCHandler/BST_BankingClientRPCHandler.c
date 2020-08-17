class BST_BankingClientRPCHandler : PluginBase {
    void BST_BankingClientRPCHandler() {
        if (GetGame().IsServer() && GetGame().IsMultiplayer()) { return; }

        GetDayZGame().Event_OnRPC.Insert(OnRPC);
    }

    void ~BST_BankingClientRPCHandler() {
        GetDayZGame().Event_OnRPC.Remove(OnRPC);
    }

    void OnRPC(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx) {
        if (GetGame().IsServer() && GetGame().IsMultiplayer()) { return; }

        BST_BankingMenu menu;
        BST_BankAccount account;
        
        switch (rpc_type) {
            case BST_BankRPC.CLIENT_RECEIVE_ACCOUNT:
                {
                    Param1<BST_BankAccount> dataReceiveAccount;

                    if (!ctx.Read(dataReceiveAccount)) { return; }

                    account = dataReceiveAccount.param1;
                    menu = BST_BankingMenu.Cast(GetGame().GetUIManager().GetMenu());

                    if (menu) {
                        menu.SetBankAccount(account);
                    }
                    break;
                }
            case BST_BankRPC.CLIENT_RECEIVE_CONFIG:
                {
                    Param1<BST_BankingConfig> dataReceiveConfig;

                    if (!ctx.Read(dataReceiveConfig)) { return; }

                    GetBSTBankingConfigHandler().SetConfig(dataReceiveConfig.param1);
                    break;
                }
        }
    }
}