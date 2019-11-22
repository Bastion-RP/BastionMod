class BankingClientRPC : PluginBase {
    void BankingClientRPC() {
        if (GetGame().IsServer() && GetGame().IsMultiplayer()) { return; }

        GetDayZGame().Event_OnRPC.Insert(BankingClientRPCHandler);
    }

    void ~BankingClientRPC() {
        GetDayZGame().Event_OnRPC.Remove(BankingClientRPCHandler);
    }

    void BankingClientRPCHandler(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx) {
        if (GetGame().IsServer() && GetGame().IsMultiplayer()) {
            delete this;
            return;
        }

        array<string> splitError = new array<string>();
        BastionBankingMenu menu;
        string playerName;
        string type, error;

        switch (rpc_type) {
            case BSTBankRPC.RPC_CLIENT_ERROR:
                {
                    Param2<string, string> dataError;
                    if (!ctx.Read(dataError)) { return; }

                    menu = BastionBankingMenu.Cast(GetGame().GetUIManager().GetMenu());
                    type = dataError.param1;
                    error = dataError.param2;
                    GetGame().GetPlayerName(playerName);

                    if (menu) {
                        switch (type) {
                            case "loginsuccess":
                                {
                                    error.Split(" ", splitError);
                                    menu.CreateTextGrid("Welcome back, " + playerName + "!", true);
                                    menu.CreateTextGrid("Account Id: " + splitError[0]);
                                    menu.CreateTextGrid("Funds: " + splitError[1]);
                                    menu.CreateTextGrid("Overflow Funds: " + splitError[2], true);
                                    break;
                                }
                            case "invalid":
                                {
                                    menu.CreateTextGrid(error, true);
                                    break;
                                }
                            case "depositoverflow":
                                {
                                    menu.CreateTextGrid(error + " rations will be deposited to overflow!");
                                    menu.SetConfirmation("Do you want to deposit '" + error + "' rations? (Y/N):");
                                    return;
                                    break;
                                }
                            case "transferconfirm":
                                {
                                    error.Split(" ", splitError);
                                    menu.CreateTextGrid("Transferring charges a fee of '" + (splitError[0].ToFloat() * 100) + "%'!", true);
                                    menu.CreateTextGrid("Transfer total: '" + splitError[2] + "'");
                                    menu.CreateTextGrid("Transfer Cost: '" + (splitError[2].ToInt() - splitError[1].ToInt()) + "'", true);
                                    menu.SetConfirmation("Do you want to tranfer '" + splitError[2] + "' rations? (Y/N):");
                                    return;
                                    break;
                                }
                            case "transferoverflow":
                                {
                                    error.Split(" ", splitError);
                                    menu.CreateTextGrid("Transferring charges a fee of '" + (splitError[0].ToFloat() * 100) + "%'!");
                                    menu.CreateTextGrid("Your account can only hold '" + splitError[3] + "' more rations!", true);
                                    menu.CreateTextGrid("Transfer total: '" + splitError[2] + "'");
                                    menu.CreateTextGrid("Transfer Cost: '" + (splitError[2].ToInt() - splitError[1].ToInt()) + "'", true);
                                    menu.SetConfirmation("Do you want to tranfer '" + splitError[1] + "' rations? (Y/N):");
                                    return;
                                    break;
                                }
                            default:
                                {
                                    menu.CreateTextGrid(error, true);
                                    break;
                                }
                        }
                        menu.CreateInputGrid();
                        menu.ScrollToBottom();
                    }
                }
        }
    }
}