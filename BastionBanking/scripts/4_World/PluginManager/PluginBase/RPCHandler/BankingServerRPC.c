// Fee forumla so I don't forget
// Depositing Known: amount being deposited(difference) total=amount/(1-%fee)
// Depositing Known: total, find amount deposited amount=total(1-%fee)

class BankingServerRPC : PluginBase {
    void BankingServerRPC() {
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) { return; }

        GetDayZGame().Event_OnRPC.Insert(BankingServerRPCHandler);
    }

    void ~BankingServerRPC() {
        GetDayZGame().Event_OnRPC.Remove(BankingServerRPCHandler);
    }

    void BankingServerRPCHandler(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx) {
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) {
            delete this;
            return;
        }
        if (!sender) { return; }

        ref BastionActiveBankAccount bankAccount;
        ref array<ItemBase> arrayItems;
        map<string, string> errorData = new map<string, string>();
        Param2<int, map<string, string>> params;
        PlayerBase player;
        int enumType, amount, transferAmount, outAmount, amountDeposited, bankFunds, fundsCap, overflowFunds, difference, bankId;
        float transferFee;
        bool isConfirmed;
        string password;

        switch (rpc_type) {
            case BSTBankRPC.RPC_SERVER_REGISTERACCOUNT:
                {
                    Param1<string> dataRegister;
                    if (!ctx.Read(dataRegister)) { return; }

                    player = PlayerBase.Cast(target);
                    password = dataRegister.param1;

                    if (player) {
                        if (GetBankAccountManager().CanCreateNewAccount(player, bankId)) {
                            enumType = BBRPCTypes.ACCOUNT_REGISTER;

                            GetBankAccountManager().CreateAccount(player, password, bankId, bankAccount);
                            GetBankAccountManager().Login(player, bankAccount);
                            errorData.Insert(BBConst.ACCOUNT_ID, "" + bankAccount.GetId());
                        } else {
                            enumType = BBRPCTypes.ERROR_ALREADY_REGISTERED;
                        }
                        params = new Param2<int, map<string, string>>(enumType, errorData);
                        GetGame().RPCSingleParam(player, BSTBankRPC.RPC_CLIENT_ERROR, params, true, player.GetIdentity());
                    }
                    break;
                }
            case BSTBankRPC.RPC_SERVER_ACCOUNTLOGIN:
                {
                    Param2<int, string> dataLogin;
                    if (!ctx.Read(dataLogin)) { return; }

                    player = PlayerBase.Cast(target);
                    bankId = dataLogin.param1;
                    password = dataLogin.param2;

                    if (player) {
                        if (GetBankAccountManager().GetLoggedInAccounts().Contains(player)) {
                            enumType = BBRPCTypes.ERROR_LOGGED_IN;
                        } else {
                            if (GetBankAccountManager().CanLogin(player, bankId, password, bankAccount)) {
                                enumType = BBRPCTypes.ACCOUNT_LOGIN;

                                GetBankAccountManager().Login(player, bankAccount);
                                errorData.Insert(BBConst.ACCOUNT_ID, "" + bankAccount.GetId());
                                errorData.Insert(BBConst.ACCOUNT_FUNDS, "" + bankAccount.GetFunds());
                                errorData.Insert(BBConst.ACCOUNT_OVERFLOW, "" + bankAccount.GetOverflowFunds());
                            } else {
                                enumType = BBRPCTypes.ERROR_INVALID_LOGIN;
                            }
                        }
                        params = new Param2<int, map<string, string>>(enumType, errorData);
                        GetGame().RPCSingleParam(player, BSTBankRPC.RPC_CLIENT_ERROR, params, true, player.GetIdentity());
                    }
                    break;
                }
            case BSTBankRPC.RPC_SERVER_ACCOUNTLOGOUT:
                {
                    player = PlayerBase.Cast(target);

                    if (player) {
                        if (GetBankAccountManager().CanLogout(player)) {
                            enumType = BBRPCTypes.ACCOUNT_LOGOUT;

                            GetBankAccountManager().Logout(player);
                        } else {
                            enumType = BBRPCTypes.ERROR_NO_LOGIN;
                        }
                        params = new Param2<int, map<string, string>>(enumType, errorData);
                        GetGame().RPCSingleParam(player, BSTBankRPC.RPC_CLIENT_ERROR, params, true, player.GetIdentity());
                    }
                    break;
                }
            case BSTBankRPC.RPC_SERVER_GETBALANCE:
                {
                    player = PlayerBase.Cast(target);

                    if (player) {
                        bankAccount = GetBankAccountManager().GetLoggedInAccount(player);

                        if (bankAccount) {
                            enumType = BBRPCTypes.ACCOUNT_GET_BALANCE;

                            bankAccount.ResetTimeout();
                            errorData.Insert(BBConst.ACCOUNT_FUNDS, "" + bankAccount.GetFunds());
                            errorData.Insert(BBConst.ACCOUNT_OVERFLOW, "" + bankAccount.GetOverflowFunds());
                        } else {
                            enumType = BBRPCTypes.ERROR_NO_LOGIN;
                        }
                        params = new Param2<int, map<string, string>>(enumType, errorData);
                        GetGame().RPCSingleParam(player, BSTBankRPC.RPC_CLIENT_ERROR, params, true, player.GetIdentity());
                    }
                    break;
                }
            case BSTBankRPC.RPC_SERVER_DEPOSIT:
                {
                    Param2<int, bool> dataDeposit;
                    if (!ctx.Read(dataDeposit)) { return; }

                    player = PlayerBase.Cast(target);
                    amount = dataDeposit.param1;
                    isConfirmed = dataDeposit.param2;

                    if (player) {
                        bankAccount = GetBankAccountManager().GetLoggedInAccount(player);

                        if (bankAccount) {
                            bankAccount.ResetTimeout();

                            if (GetBankManager().CanDeposit(player, amount, arrayItems, outAmount)) {
                                if (amount == -1) {
                                    amount = outAmount;
                                }
                                if (!isConfirmed) {
                                    bankFunds = bankAccount.GetFunds();
                                    fundsCap = GetBBankConfig().GetConfig().GetBankFundsCap();

                                    if (bankFunds + amount > fundsCap) {
                                        difference = fundsCap - bankFunds;
                                        amount -= difference;

                                        errorData.Insert(BBConst.ACCOUNT_TO_OVERFLOW, "" + amount);

                                        params = new Param2<int, map<string, string>>(BBRPCTypes.ERROR_ACCEPT_OVERFLOW, errorData);

                                        GetGame().RPCSingleParam(player, BSTBankRPC.RPC_CLIENT_ERROR, params, true, player.GetIdentity());
                                        return;
                                    }
                                }
                                GetBankManager().RemoveCurrency(arrayItems, amount);
                                GetBankAccountManager().Deposit(bankAccount, amount);
                                enumType = BBRPCTypes.ACCOUNT_DEPOSIT;

                                errorData.Insert(BBConst.ACCOUNT_FUNDS, "" + bankAccount.GetFunds());
                                errorData.Insert(BBConst.ACCOUNT_OVERFLOW, "" + bankAccount.GetOverflowFunds());
                                errorData.Insert(BBConst.ACCOUNT_DEPOSITED, "" + amount);
                            } else {
                                enumType = BBRPCTypes.ERROR_NO_FUNDS_DEPOSIT;
                                errorData.Insert(BBConst.ACCOUNT_DEPOSITED, "" + amount);
                            }
                        } else {
                            enumType = BBRPCTypes.ERROR_NO_LOGIN;
                        }
                        params = new Param2<int, map<string, string>>(enumType, errorData);
                        GetGame().RPCSingleParam(player, BSTBankRPC.RPC_CLIENT_ERROR, params, true, player.GetIdentity());
                    }
                    break;
                }
            case BSTBankRPC.RPC_SERVER_WITHDRAW:
                {
                    Param1<int> dataWithdraw;
                    if (!ctx.Read(dataWithdraw)) { return; }

                    player = PlayerBase.Cast(target);
                    amount = dataWithdraw.param1;

                    if (player) {
                        bankAccount = GetBankAccountManager().GetLoggedInAccount(player);

                        if (bankAccount) {
                            bankAccount.ResetTimeout();

                            if (bankAccount.GetFunds() < amount) {
                                enumType = BBRPCTypes.ERROR_NO_FUNDS_WITHDRAW;

                                errorData.Insert(BBConst.ACCOUNT_FUNDS, "" + bankAccount.GetFunds());
                                errorData.Insert(BBConst.ACCOUNT_OVERFLOW, "" + bankAccount.GetOverflowFunds());
                                errorData.Insert(BBConst.ACCOUNT_WITHDRAW, "" + amount);
                            } else {
                                GetBankManager().AddCurrency(player, amount);
                                GetBankAccountManager().Withdraw(bankAccount, amount);

                                enumType = BBRPCTypes.ACCOUNT_WITHDRAW;
                                errorData.Insert(BBConst.ACCOUNT_WITHDRAW, "" + amount);
                            }
                        } else {
                            enumType = BBRPCTypes.ERROR_NO_LOGIN;
                        }
                        params = new Param2<int, map<string, string>>(enumType, errorData);
                        GetGame().RPCSingleParam(player, BSTBankRPC.RPC_CLIENT_ERROR, params, true, player.GetIdentity());
                    }
                    break;
                }
            case BSTBankRPC.RPC_SERVER_TRANSFER:
                {
                    Param2<int, bool> dataTransfer;
                    if (!ctx.Read(dataTransfer)) { return; }

                    player = PlayerBase.Cast(target);
                    amount = dataTransfer.param1;
                    isConfirmed = dataTransfer.param2;

                    if (player) {
                        bankAccount = GetBankAccountManager().GetLoggedInAccount(player);

                        if (bankAccount) {
                            overflowFunds = bankAccount.GetOverflowFunds();
                            bankFunds = bankAccount.GetFunds();
                            fundsCap = GetBBankConfig().GetConfig().GetBankFundsCap();
                            transferFee = GetBBankConfig().GetConfig().GetOverflowTransferFee();
                            transferAmount = Math.Round((amount * (1 - transferFee)));
                            difference = fundsCap - bankFunds;

                            bankAccount.ResetTimeout();

                            if (overflowFunds < amount) {
                                enumType = BBRPCTypes.ERROR_NO_FUNDS_TRANSFER;
                                errorData.Insert(BBConst.ACCOUNT_OVERFLOW, "" + amount);
                            } else {
                                if (!isConfirmed) {
                                    if ((bankFunds + transferAmount) > fundsCap) {
                                        amount = Math.Round((difference / (1 - transferFee)));
                                        transferAmount = Math.Round((amount * (1 - transferFee)));
                                        enumType = BBRPCTypes.ACCOUNT_TRANSFER_CAPPED;

                                        errorData.Insert(BBConst.ACCOUNT_TRANSFER_FEE, "" + transferFee);
                                        errorData.Insert(BBConst.ACCOUNT_TRANSFER_AMOUNT, "" + transferAmount);
                                        errorData.Insert(BBConst.ACCOUNT_TRANSFER_DIFFERENCE, "" + difference);
                                        errorData.Insert(BBConst.ACCOUNT_FUNDS, "" + amount);
                                    } else {
                                        enumType = BBRPCTypes.ERROR_ACCEPT_TRANSFER;

                                        errorData.Insert(BBConst.ACCOUNT_TRANSFER_FEE, "" + transferFee);
                                        errorData.Insert(BBConst.ACCOUNT_TRANSFER_AMOUNT, "" + transferAmount);
                                        errorData.Insert(BBConst.ACCOUNT_FUNDS, "" + amount);
                                    }
                                } else {
                                    enumType = BBRPCTypes.ACCOUNT_TRANSFER;

                                    if ((bankFunds + transferAmount) > fundsCap) {
                                        amount = Math.Round((difference / (1 - transferFee)));

                                        errorData.Insert(BBConst.ACCOUNT_TRANSFER_AMOUNT, "" + difference);
                                    } else {
                                        errorData.Insert(BBConst.ACCOUNT_TRANSFER_AMOUNT, "" + transferAmount);
                                    }
                                    GetBankAccountManager().Transfer(bankAccount, amount);
                                }
                            }
                        } else {
                            enumType = BBRPCTypes.ERROR_NO_LOGIN;
                        }
                        params = new Param2<int, map<string, string>>(enumType, errorData);
                        GetGame().RPCSingleParam(player, BSTBankRPC.RPC_CLIENT_ERROR, params, true, player.GetIdentity());
                    }
                    break;
                }
        }
    }
}