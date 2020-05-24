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

        map<string, string> errorData = new map<string, string>();
        array<string> splitError = new array<string>();
        BastionBankingMenu menu;
        string playerName;
        string type, error;

        switch (rpc_type) {
            case BSTBankRPC.RPC_CLIENT_INIT:
                {
                    Param1<BastionBankingConfig> dataInit;

                    if (!ctx.Read(dataInit)) { return; }
                    GetBBankConfig().SetConfig(dataInit.param1);
                    break;
                }
            case BSTBankRPC.RPC_CLIENT_ERROR:
                {
                    Param2<int, map<string, string>> dataError;
                    if (!ctx.Read(dataError)) { return; }

                    Print("BankingClientRPCHandler | " + typename.EnumToString(BBRPCTypes, dataError.param1));
                    int enumType = dataError.param1;
                    errorData = dataError.param2;
                    menu = BastionBankingMenu.Cast(GetGame().GetUIManager().GetMenu());

                    if (menu) {
                        switch(enumType) {
                            case BBRPCTypes.ACCOUNT_REGISTER:
                                {
                                    menu.CreateTextGrid("Congratulations! You have successfully registered for a D2 account. Familiarize yourself with the other commands necessary for using the D2 machine below.");
                                    menu.CreateTextGrid("Your assigned account ID is: " + errorData.Get(BBConst.ACCOUNT_ID), true);
                                    menu.Help();
                                    break;
                                }
                            case BBRPCTypes.ACCOUNT_LOGIN:
                                {
                                    GetGame().GetPlayerName(playerName);
                                    menu.CreateTextGrid("Welcome back, " + playerName + "!", true);
                                    menu.CreateTextGrid("D2 Account ID: " + errorData.Get(BBConst.ACCOUNT_ID));
                                    menu.CreateTextGrid("D2 Account Credits: " + errorData.Get(BBConst.ACCOUNT_FUNDS));
                                    menu.CreateTextGrid("D2 Account Overflow: " + errorData.Get(BBConst.ACCOUNT_OVERFLOW), true);
                                    break;
                                }
                            case BBRPCTypes.ACCOUNT_LOGOUT:
                                {
                                    GetGame().GetPlayerName(playerName);
                                    menu.CreateTextGrid("Goodbye, " + playerName + "!", true);
                                    break;
                                }
                            case BBRPCTypes.ACCOUNT_GET_BALANCE:
                                {
                                    menu.CreateTextGrid("D2 Account Credits: " + errorData.Get(BBConst.ACCOUNT_FUNDS));
                                    menu.CreateTextGrid("D2 Account Overflow: " + errorData.Get(BBConst.ACCOUNT_OVERFLOW), true);
                                    break;
                                }
                            case BBRPCTypes.ACCOUNT_DEPOSIT:
                                {
                                    menu.CreateTextGrid("Credits Deposited! You have successfully deposited '" + errorData.Get(BBConst.ACCOUNT_DEPOSITED) + "' credits!", true);
                                    menu.CreateTextGrid("D2 Account Credits: " + errorData.Get(BBConst.ACCOUNT_FUNDS));
                                    menu.CreateTextGrid("D2 Account Overflow: " + errorData.Get(BBConst.ACCOUNT_OVERFLOW), true);
                                    break;
                                }
                            case BBRPCTypes.ACCOUNT_WITHDRAW:
                                {
                                    menu.CreateTextGrid("Credits Withdrew! You successfully withdrew '" + errorData.Get(BBConst.ACCOUNT_WITHDRAW) + "' credits!", true);
                                    break;
                                }
                            case BBRPCTypes.ACCOUNT_TRANSFER:
                                {
                                    menu.CreateTextGrid("Credits Transferred! You have successfully transferred '" + errorData.Get(BBConst.ACCOUNT_TRANSFER_AMOUNT) + "' credits!", true);
                                    break;
                                }
                            case BBRPCTypes.ACCOUNT_TRANSFER_CAPPED:
                                {
                                    menu.CreateTextGrid("Error! A '" + (errorData.Get(BBConst.ACCOUNT_TRANSFER_FEE).ToFloat() * 100) + "%` fee is applied to transfers!");
                                    menu.CreateTextGrid("Error! Your account can only hold '" + errorData.Get(BBConst.ACCOUNT_TRANSFER_DIFFERENCE) + "' more credits!", true);
                                    menu.CreateTextGrid("Transfer Total: '" + errorData.Get(BBConst.ACCOUNT_FUNDS) + "'");
                                    menu.CreateTextGrid("Transfer Cost: '" + (errorData.Get(BBConst.ACCOUNT_FUNDS).ToInt() - errorData.Get(BBConst.ACCOUNT_TRANSFER_AMOUNT).ToInt()) + "'", true);
                                    menu.SetConfirmation("Do you accept? (Y/N):");
                                    return;
                                    break;
                                }
                            case BBRPCTypes.ACCOUNT_RESET:
                                {
                                    menu.CreateTextGrid("Account password reset! You can now login using your new password", true);
                                    break;
                                }
                            case BBRPCTypes.ERROR_ACCEPT_TRANSFER:
                                {
                                    menu.CreateTextGrid("Error! A '" + (errorData.Get(BBConst.ACCOUNT_TRANSFER_FEE).ToFloat() * 100) + "%` fee is applied to transfers!", true);
                                    menu.CreateTextGrid("Transfer Total: '" + errorData.Get(BBConst.ACCOUNT_FUNDS) + "'");
                                    menu.CreateTextGrid("Transfer Cost: '" + (errorData.Get(BBConst.ACCOUNT_FUNDS).ToInt() - errorData.Get(BBConst.ACCOUNT_TRANSFER_AMOUNT).ToInt()) + "'", true);
                                    menu.SetConfirmation("Do you accept? (Y/N):");
                                    return;
                                    break;
                                }
                            case BBRPCTypes.ERROR_ALREADY_REGISTERED:
                                {
                                    menu.CreateTextGrid("Error! A new account could not be created! You already have a D2 account registered!");
                                    menu.CreateTextGrid("Use \"login\" to login to your account!", true);
                                    break;
                                }
                            case BBRPCTypes.ERROR_LOGGED_IN:
                                {
                                    menu.CreateTextGrid("Error! Could not log in to the D2 Banking System! You are already logged in!", true);
                                    break;
                                }
                            case BBRPCTypes.ERROR_NO_LOGIN:
                                {
                                    menu.CreateTextGrid("Error! You are not logged into a D2 account!", true);
                                    break;
                                }
                            case BBRPCTypes.ERROR_INVALID_LOGIN:
                                {
                                    menu.CreateTextGrid("Error! Could not log in to the D2 Banking System! Invalid credentials were used!", true);
                                    break;
                                }
                            case BBRPCTypes.ERROR_NO_FUNDS_DEPOSIT:
                                {
                                    menu.CreateTextGrid("Error! You do not have '" + errorData.Get(BBConst.ACCOUNT_DEPOSITED) + "' credits to deposit!", true);
                                    break;
                                }
                            case BBRPCTypes.ERROR_NO_FUNDS_WITHDRAW:
                                {
                                    menu.CreateTextGrid("Error! You do not have '" + errorData.Get(BBConst.ACCOUNT_WITHDRAW) + "' credits to withdraw!", true);
                                    menu.CreateTextGrid("D2 Account Funds: " + errorData.Get(BBConst.ACCOUNT_FUNDS));
                                    menu.CreateTextGrid("D2 Account Overflow: " + errorData.Get(BBConst.ACCOUNT_OVERFLOW), true);
                                    break;
                                }
                            case BBRPCTypes.ERROR_NO_FUNDS_TRANSFER:
                                {
                                    menu.CreateTextGrid("Error! You do not have '" + errorData.Get(BBConst.ACCOUNT_OVERFLOW) + "' to transfer!", true);
                                    break;
                                }
                            case BBRPCTypes.ERROR_ACCEPT_OVERFLOW:
                                {
                                    menu.CreateTextGrid("Error! Your main balance cannot hold any more credits!");
                                    menu.CreateTextGrid("Error! '" + errorData.Get(BBConst.ACCOUNT_TO_OVERFLOW) + "' credits will be transferred to overflow!", true);
                                    menu.SetConfirmation("Do you accept? (Y/N):");
                                    return;
                                    break;
                                }
                            case BBRPCTypes.ERROR_RESET:
                                {
                                    menu.CreateTextGrid("Error! Account password could not be reset due to an unknown error!");
                                    break;
                                }
                        }
                        menu.CreateInputGrid();
                        menu.ScrollToBottom();
                    }

                    for (int i = 0; i < errorData.Count(); i++) {
                        Print("BankingClientRPCHandler | datatype=" + errorData.GetKey(i) + " | data=" + errorData.GetElement(i));
                    }

/*                     menu = BastionBankingMenu.Cast(GetGame().GetUIManager().GetMenu());
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
                    } */
                }
        }
    }
}