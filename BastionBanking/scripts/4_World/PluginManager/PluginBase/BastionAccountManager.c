class BastionAccountManager : PluginBase {
    // Don't store accounts in memory, load them when necessary.
    // Account username will be the account id
    // Password will be set by the user
    private ref map<string, ref BastionBankAccount> mapAccountLogins;
    private ref BastionAccountTracker accountTracker;

    void BastionAccountManager() {
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) { return; }

        accountTracker = new BastionAccountTracker();
        mapAccountLogins = new map<string, ref BastionBankAccount>();

        GetDayZGame().Event_OnRPC.Insert(AccountManagerRPC);
        LoadTracker();
        CheckDirectories();
    }
    // REMEMBER:::::::::::------------------------------------------------------------------------------------------------------------------------
    // FOR PASSIVE INCOME::: CREATE AN INCOME LOOP ON PLAYERBASE ON ONCONNECT AND LOAD ADD MONEY THEN SAVE FILE
    // REMEMBER:::::::::::------------------------------------------------------------------------------------------------------------------------

    void ~BastionAccountManager() {
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) { return; }

        GetDayZGame().Event_OnRPC.Remove(AccountManagerRPC);
    }

    void CheckDirectories() {
        if (!FileExist(BBConst.profileDir)) {
            MakeDirectory(BBConst.profileDir);
        }
        if (!FileExist(BBConst.modDir)) {
            MakeDirectory(BBConst.modDir);
        }
        if (!FileExist(BBConst.playerDir)) {
            MakeDirectory(BBConst.playerDir);
        }
        if (!FileExist(BBConst.accountDir)) {
            MakeDirectory(BBConst.accountDir);
        }
    }

    void LoadTracker() {
        if (!FileExist(BBConst.trackerDir)) {
            accountTracker = new BastionAccountTracker();
            JsonFileLoader<ref BastionAccountTracker>.JsonSaveFile(BBConst.trackerDir, accountTracker);
        } else {
            JsonFileLoader<ref BastionAccountTracker>.JsonLoadFile(BBConst.trackerDir, accountTracker);
        }
    }

    void AccountManagerRPC(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx) {
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) {
            delete this;
            return;
        }
        if (!sender) { return; }

        Param2<string, string> params;
        ref BastionBankAccount bankAccount;
        PlayerBase player;
        int bankId;
        string password, type, error;

        switch (rpc_type) {
            case BSTBankRPC.RPC_SERVER_REGISTERACCOUNT:
                {
                    Param1<string> dataRegister;
                    if (!ctx.Read(dataRegister)) { return; }

                    player = PlayerBase.Cast(target);
                    password = dataRegister.param1;

                    if (player) {
                        if (CanCreateNewAccount(player, bankId)) {
                            CreateAccount(player, password, bankId, bankAccount);
                            Login(player.GetIdentity().GetPlainId(), bankAccount);

                            type = "registersuccess";
                            error = bankAccount.GetId().ToString();
                        } else {
                            type = "invalid";
                            error = ", you already have an account!";
                        }
                    } else {
                        // Send rpc back to client to show error
                        type = "critical";
                        error = "Critical Error!!! Aborting!";
                    }
                    params = new Param2<string, string>(type, error);
                    GetGame().RPCSingleParam(player, BSTBankRPC.RPC_CLIENT_ERROR, params, true, player.GetIdentity());
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
                        if (mapAccountLogins.Contains(player.GetIdentity().GetPlainId())) {
                            type = "invalid";
                            error = ", you are already logged in!";
                        } else {
                            if (CanLogin(player, bankId, password, bankAccount)) {
                                Login(player.GetIdentity().GetPlainId(), bankAccount);
                                
                                type = "loginsuccess";
                                error = "" + bankAccount.GetId() + "|" + bankAccount.GetFunds() + "|" + bankAccount.GetOverflowFunds();
                            } else {
                                type = "loginfail";
                                error = "Invalid Password or AccountId";
                            }
                        }
                        params = new Param2<string, string>(type, error);
                        GetGame().RPCSingleParam(player, BSTBankRPC.RPC_CLIENT_ERROR, params, true, player.GetIdentity());
                    }
                    break;
                }
            case BSTBankRPC.RPC_SERVER_ACCOUNTLOGOUT:
                {
                    player = PlayerBase.Cast(target);

                    if (player) {
                        if (CanLogout(player.GetIdentity().GetPlainId())) {
                            error = "Goodbye, ";
                        } else {
                            error = "You are not logged in!";
                        }
                        params = new Param2<string, string>("logout", error);
                        GetGame().RPCSingleParam(player, BSTBankRPC.RPC_CLIENT_ERROR, params, true, player.GetIdentity());
                    }
                    break;
                }
        }
    }

    bool CanCreateNewAccount(PlayerBase player, out int bankId) {
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) { return false; }

        int playerIndex = player.GetIndex();
        string playerAccountDir;
        string playerId = player.GetIdentity().GetPlainId();
        string playerDir = BBConst.playerDir + "\\" + playerId;

        if (FileExist(playerDir)) {
            playerAccountDir = playerDir + "\\" + playerIndex + BBConst.fileType;

            if (FileExist(playerAccountDir)) {
                BastionPlayerAccount playerAccount;
                string accountDir;

                JsonFileLoader<BastionPlayerAccount>.JsonLoadFile(playerAccountDir, playerAccount);
                accountDir = playerAccount.GetPath();

                if (FileExist(accountDir)) {
                    return false;
                } else {
                    bankId = playerAccount.GetId();
                }
                delete playerAccount;
            } else {
                bankId = (accountTracker.GetTotalAccounts() + 1);
            }
        } else {
            MakeDirectory(playerDir);
            bankId = (accountTracker.GetTotalAccounts() + 1);
        }
        bankId = (accountTracker.GetTotalAccounts() + 1);
        return true;
    }

    void CreateAccount(PlayerBase player, string password, int id, out ref BastionBankAccount account) {
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) { return; }
        // Find their playerId and player index. Load that file, check if an account exists. If exists, don't create an account
        // if it doesn't, create account.
        ref BastionBankAccount bankAccount;
        BastionPlayerAccount playerAccount;
        int playerIndex = player.GetIndex();
        string bankAccountDir;
        string playerId = player.GetIdentity().GetPlainId();
        string playerDir = BBConst.playerDir + "\\" + playerId + "\\" + player.GetIndex() + BBConst.fileType;

        bankAccountDir = BBConst.accountDir + "\\" + id + BBConst.fileType;
        bankAccount = new BastionBankAccount(id, playerId, password);
        playerAccount = new BastionPlayerAccount(bankAccountDir, id, 1);
        JsonFileLoader<ref BastionBankAccount>.JsonSaveFile(bankAccountDir, bankAccount);
        JsonFileLoader<BastionPlayerAccount>.JsonSaveFile(playerDir, playerAccount);
        accountTracker.AddAccount();
        account = bankAccount;

        delete playerAccount;
    }

    bool CanLogin(PlayerBase player, int accountId, string password, out ref BastionBankAccount account) {
        BastionPlayerAccount playerAccount;
        ref BastionBankAccount bankAccount;
        string playerAccountDir = BBConst.playerDir + "\\" + player.GetIdentity().GetPlainId() + "\\" + player.GetIndex() + BBConst.fileType;

        if (accountId == -1) {
            if (!FileExist(playerAccountDir)) {
                return false;
            }
            JsonFileLoader<BastionPlayerAccount>.JsonLoadFile(playerAccountDir, playerAccount);
            accountId = playerAccount.GetId();
            delete playerAccount;
        }
        bankAccount = FindAccount(accountId);

        if (bankAccount) {
            if (bankAccount.GetPassword() == password) {
                account = bankAccount;
                return true;
            }
        }
        return false;
    }

    void Login(string playerId, ref BastionBankAccount account) {
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) { return; }

        account.SetTimeout(60);
        mapAccountLogins.Insert(playerId, account);
    }

    bool CanLogout(string playerId) {
        // Remove object from map containing logged in accounts
        // Send rpc to client confirming logout
        ref BastionBankAccount account;
        string error;

        if (mapAccountLogins.Find(playerId, account)) {
            delete account;
            mapAccountLogins.Remove(playerId);
            return true;
        }
        return false;
    }

    void ResetAccountTimeout(string playerId) {
        ref BastionBankAccount account = GetLoggedInAccount(playerId);

        if (account) {
            account.SetTimeout(60);
        }
    }

    void Deposit(ref BastionBankAccount account, int amount) {
        string accountDir = BBConst.accountDir + "\\" + account.GetId() + BBConst.fileType;

        if (FileExist(accountDir)) {
            account.Deposit(amount);
            JsonFileLoader<ref BastionBankAccount>.JsonSaveFile(accountDir, account);
        }
    }

    void Withdraw(ref BastionBankAccount account, int amount) {
        string accountDir = BBConst.accountDir + "\\" + account.GetId() + BBConst.fileType;

        if (FileExist(accountDir)) {
            account.Withdraw(amount);
            JsonFileLoader<ref BastionBankAccount>.JsonSaveFile(accountDir, account);
        }
    }

    // Combine this garbage into one function

    ref BastionBankAccount GetLoggedInAccount(string playerId) {
        ref BastionBankAccount account;

        mapAccountLogins.Find(playerId, account);
        return account;
    }

    ref BastionBankAccount FindAccount(int accountId) {
        ref BastionBankAccount account;
        string accountDir = BBConst.accountDir + "\\" + accountId + BBConst.fileType;

        if (FileExist(accountDir)) {
            JsonFileLoader<BastionBankAccount>.JsonLoadFile(accountDir, account);
        }
        return account;
    }

    ref BastionAccountTracker GetStatTracker() {
        return accountTracker;
    }
}
BastionAccountManager GetBankAccountManager() {
    return BastionAccountManager.Cast(GetPlugin(BastionAccountManager));
}