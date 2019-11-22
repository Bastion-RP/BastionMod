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

        ref BastionBankAccount bankAccount;
        ref array<ItemBase> arrayItems;
        Param2<string, string> params;
        PlayerBase player;
        string error, type;
        int amount, transferAmount, outAmount, amountDeposited, bankFunds, fundsCap, overflowFunds, difference;
        float transferFee;
        bool isConfirmed;

        switch (rpc_type) {
            case BSTBankRPC.RPC_SERVER_GETBALANCE:
                {
                    player = PlayerBase.Cast(target);

                    if (player) {
                        bankAccount = GetBankAccountManager().GetLoggedInAccount(player);

                        if (bankAccount) {
                            GetBankAccountManager().ResetAccountTimeout(bankAccount);

                            type = "balance";
                            error = "Funds: " + bankAccount.GetFunds() + " || Overflow: " + bankAccount.GetOverflowFunds();
                        } else {
                            type = "notloggedin";
                            error = "You are not logged into an account!";
                        }
                        params = new Param2<string, string>(type, error);
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
                            GetBankAccountManager().ResetAccountTimeout(bankAccount);

                            if (GetBankManager().CanDeposit(player, amount, arrayItems, outAmount)) {
                                if (amount == -1) {
                                    amount = outAmount;
                                }
                                if (!isConfirmed) {
                                    bankFunds = bankAccount.GetFunds();
                                    fundsCap = GetBBankConfig().GetFundsCap()

                                    if (bankFunds + amount > fundsCap) {
                                        difference = fundsCap - bankFunds;
                                        amount -= difference;
                                        type = "depositoverflow";
                                        error = "" + amount;
                                        params = new Param2<string, string>(type, error);

                                        GetGame().RPCSingleParam(player, BSTBankRPC.RPC_CLIENT_ERROR, params, true, player.GetIdentity());
                                        return;
                                    }
                                }
                                GetBankManager().RemoveCurrency(arrayItems, amount);
                                GetBankAccountManager().Deposit(bankAccount, amount);
                                type = "deposit";
                                error = "Rations Successfully Deposited: " + amount;
                            } else {
                                type = "invalid";
                                error = "You do not have '" + amount + "' rations!";
                            }
                        } else {
                            type = "notloggedin";
                            error = "You are not logged into an account!";
                        }
                        params = new Param2<string, string>(type, error);
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
                            GetBankAccountManager().ResetAccountTimeout(bankAccount);

                            if (bankAccount.GetFunds() < amount) {
                                type = "invalid";
                                error = "There is not " + amount + " rations in the account!";
                            } else {
                                GetBankManager().AddCurrency(player, amount);
                                GetBankAccountManager().Withdraw(bankAccount, amount);
                                type = "withdraw";
                                error = "Rations Successfully Withdrew: " + amount;
                            }
                        } else {
                            type = "notloggedin";
                            error = "You are not logged into an account!";
                        }
                        params = new Param2<string, string>(type, error);
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
                            fundsCap = GetBBankConfig().GetFundsCap()
                            transferFee = GetBBankConfig().GetTransferFee()
                            Print("amount=" + amount);
                            Print("transferFee=" + transferFee)
                            Print("transferAmount=" + Math.Round((amount * (1 - transferFee))))
                            transferAmount = Math.Round((amount * (1 - transferFee)));
                            difference = fundsCap - bankFunds;

                            GetBankAccountManager().ResetAccountTimeout(bankAccount);

                            if (overflowFunds < amount) {
                                type = "transferinvalid";
                                error = "There is not " + amount + " rations in the account!";
                            } else {
                                if (!isConfirmed) {
                                    if ((bankFunds + transferAmount) > fundsCap) {
                                        amount = Math.Round((difference / (1 - transferFee)));
                                        transferAmount = Math.Round((amount * (1 - transferFee)));
                                        type = "transferoverflow";
                                        error = "" + transferFee + " " + transferAmount + " " + amount + " " + difference;
                                    } else {
                                        type = "transferconfirm";
                                        error = "" + transferFee + " " + transferAmount + " " + amount;
                                    }
                                } else {
                                    if ((bankFunds + transferAmount) > fundsCap) {
                                        amount = Math.Round((difference / (1 - transferFee)));
                                        error = "" + difference + " rations sucessfully deposited to balance!";
                                    } else {
                                        error = "" + transferAmount + " rations sucessfully deposited to balance!";
                                    }
                                    type = "transfersuccess";
                                    GetBankAccountManager().Transfer(bankAccount, amount);
                                }
                            }
                        } else {
                            type = "notloggedin";
                            error = "You are not logged into an account!";
                        }
                        params = new Param2<string, string>(type, error);
                        GetGame().RPCSingleParam(player, BSTBankRPC.RPC_CLIENT_ERROR, params, true, player.GetIdentity());
                    }
                    break;
                }
        }
    }
}