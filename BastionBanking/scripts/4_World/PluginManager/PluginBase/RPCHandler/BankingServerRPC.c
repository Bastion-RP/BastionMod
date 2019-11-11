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
        int amount, amountDeposited;

        switch (rpc_type) {
            case BSTBankRPC.RPC_SERVER_GETBALANCE:
                {
                    player = PlayerBase.Cast(target);

                    if (player) {
                        bankAccount = GetBankAccountManager().GetLoggedInAccount(player.GetIdentity().GetPlainId());

                        if (bankAccount) {
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
                    Param1<int> dataDeposit;
                    if (!ctx.Read(dataDeposit)) { return; }

                    player = PlayerBase.Cast(target);
                    amount = dataDeposit.param1;

                    if (player) {
                        bankAccount = GetBankAccountManager().GetLoggedInAccount(player.GetIdentity().GetPlainId());

                        if (bankAccount) {
                            if (GetBankManager().CanDeposit(player, amount, arrayItems)) {
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
                        bankAccount = GetBankAccountManager().GetLoggedInAccount(player.GetIdentity().GetPlainId());

                        if (bankAccount) {
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
                    break;
                }
        }
    }
}