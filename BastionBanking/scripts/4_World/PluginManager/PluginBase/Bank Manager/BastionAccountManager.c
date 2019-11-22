class BastionAccountManager : PluginBase {
    // Don't store accounts in memory, load them when necessary.
    // Account username will be the account id
    // Password will be set by the user
    private ref map<ref PlayerBase, ref BastionBankAccount> mapAccountLogins;
    private ref map<string, int> mapJobWages;
    private ref BastionAccountTracker accountTracker;

    void BastionAccountManager() {
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) { return; }

        accountTracker = new BastionAccountTracker();
        mapAccountLogins = new map<ref PlayerBase, ref BastionBankAccount>();
        mapJobWages = new map<string, int>();

        GetDayZGame().Event_OnRPC.Insert(AccountManagerRPC);
        LoadTracker();
        LoadWages();
        CheckDirectories();
        GetGame().GameScript.Call(this, "LoginTimeoutLoop", null);
    }
    // REMEMBER:::::::::::------------------------------------------------------------------------------------------------------------------------
    // FOR PASSIVE INCOME::: CREATE AN INCOME LOOP ON PLAYERBASE ON ONCONNECT AND LOAD ADD MONEY THEN SAVE FILE
    // REMEMBER:::::::::::------------------------------------------------------------------------------------------------------------------------

    void ~BastionAccountManager() {
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) { return; }

        GetDayZGame().Event_OnRPC.Remove(AccountManagerRPC);
    }

    void CheckDirectories() {
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) { return; }

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

    void LoadWages() {
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) { return; }

        if (!FileExist(BBConst.wagesDir)) {
            mapJobWages.Insert("unemployed", 1);
            mapJobWages.Insert("example1", 2);
            mapJobWages.Insert("example2", 3);
            JsonFileLoader<ref map<string, int>>.JsonSaveFile(BBConst.wagesDir, mapJobWages);
        } else {
            JsonFileLoader<ref map<string, int>>.JsonLoadFile(BBConst.wagesDir, mapJobWages);
        }
    }

    void LoadTracker() {
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) { return; }

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
                            Login(player, bankAccount);

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
                        if (mapAccountLogins.Contains(player)) {
                            type = "invalid";
                            error = ", you are already logged in!";
                        } else {
                            if (CanLogin(player, bankId, password, bankAccount)) {
                                Login(player, bankAccount);

                                type = "loginsuccess";
                                error = "" + bankAccount.GetId() + " " + bankAccount.GetFunds() + " " + bankAccount.GetOverflowFunds();
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
                        if (CanLogout(player)) {
                            Logout(player);
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

    void LoginTimeoutLoop() {
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) { return; }

        ref array<BastionBankAccount> accountArray = new array<BastionBankAccount>();
        PlayerBase localPlayer;
        int accountTimeout;

        while (true) {
            accountArray = mapAccountLogins.GetValueArray();

            foreach (BastionBankAccount account : accountArray) {
                accountTimeout = account.GetTimeout();

                if (accountTimeout <= 0) {
                    localPlayer = mapAccountLogins.GetKeyByValue(account);

                    if (localPlayer) {
                        Logout(localPlayer);

                        auto params = new Param2<string, string>("logintimeout", ", you have been logged out due to inactivity!");
                        GetGame().RPCSingleParam(localPlayer, BSTBankRPC.RPC_CLIENT_ERROR, params, true, localPlayer.GetIdentity());
                        delete account;
                        continue;
                    }
                }
                account.SetTimeout(accountTimeout - 1);
            }
            Sleep(1000);
        }
    }

    bool CanCreateNewAccount(PlayerBase player, out int bankId) {
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) { return false; }

        int playerIndex = player.GetIndex();
        string playerAccountDir;
        string playerId = player.GetIdentity().GetPlainId();
        string playerDir = BBConst.playerDir + "\\" + playerId;
        ref BastionPlayerAccount playerAccount = player.GetBastionPlayerAccount();

        if (playerAccount) {
            string accountDir = playerAccount.GetPath();

            if (!FileExist(accountDir)) {
                bankId = playerAccount.GetId();
                return true;
            }
            return false;
        }
        bankId = (accountTracker.GetTotalAccounts() + 1);
        return true;
    }

    void CreateAccount(PlayerBase player, string password, int id, out ref BastionBankAccount account) {
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) { return; }

        ref BastionBankAccount bankAccount;
        ref BastionPlayerAccount playerAccount;
        int playerIndex = player.GetIndex();
        string bankAccountDir = BBConst.accountDir + "\\" + id + BBConst.fileType;
        string playerId = player.GetIdentity().GetPlainId();
        string playerDir = BBConst.playerDir + "\\" + playerId;
        string playerAccountDir = playerDir + "\\" + player.GetIndex() + BBConst.fileType;

        if (!FileExist(playerDir)) {
            MakeDirectory(playerDir);
        }
        bankAccount = new BastionBankAccount(id, playerId, password);
        playerAccount = new BastionPlayerAccount(bankAccountDir, id);
        JsonFileLoader<BastionBankAccount>.JsonSaveFile(bankAccountDir, bankAccount);
        JsonFileLoader<BastionPlayerAccount>.JsonSaveFile(playerDir, playerAccount);

        player.SetBastionPlayerAccount(playerAccount);
        accountTracker.AddAccount();
        account = bankAccount;
    }

    bool CanLogin(PlayerBase player, int accountId, string password, out ref BastionBankAccount account) {
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) { return false; }

        ref BastionBankAccount bankAccount = FindAccount(player, accountId);

        if (bankAccount) {
            if (bankAccount.GetPassword() == password) {
                account = bankAccount;
                return true;
            }
        }
        return false;
    }

    void Login(ref PlayerBase player, ref BastionBankAccount account) {
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) { return; }

        ResetAccountTimeout(account);
        mapAccountLogins.Insert(player, account);
    }

    bool CanLogout(ref PlayerBase player) {
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) { return false; }

        return mapAccountLogins.Contains(player);
    }

    void Logout(ref PlayerBase player) {
        ref BastionBankAccount account;

        if (mapAccountLogins.Find(player, account)) {
            delete account;
            mapAccountLogins.Remove(player);
        }
    }

    void ResetAccountTimeout(ref BastionBankAccount account) {
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) { return; }

        if (account) {
            account.SetTimeout(GetBBankConfig().GetLoginTimeout());
        }
    }

    void Deposit(ref BastionBankAccount account, int amount) {
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) { return; }

        string accountDir = BBConst.accountDir + "\\" + account.GetId() + BBConst.fileType;
        int funds, fundsCap, difference;

        if (FileExist(accountDir)) {
            funds = account.GetFunds();
            fundsCap = GetBBankConfig().GetFundsCap()

            if ((funds + amount) > fundsCap) {
                difference = fundsCap - funds;
                amount -= difference;

                account.Deposit(difference);
                account.DepositOverflow(amount);
            } else {
                account.Deposit(amount);
            }
            JsonFileLoader<ref BastionBankAccount>.JsonSaveFile(accountDir, account);
        }
    }

    void Withdraw(ref BastionBankAccount account, int amount) {
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) { return; }

        string accountDir = BBConst.accountDir + "\\" + account.GetId() + BBConst.fileType;

        if (FileExist(accountDir)) {
            account.Withdraw(amount);
            JsonFileLoader<ref BastionBankAccount>.JsonSaveFile(accountDir, account);
        }
    }

    void Transfer(ref BastionBankAccount account, int amount) {
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) { return; }

        string accountDir = BBConst.accountDir + "\\" + account.GetId() + BBConst.fileType;
        int transferAmount;

        if (FileExist(accountDir)) {
            transferAmount = Math.Round((amount * (1 - GetBBankConfig().GetTransferFee())));

            account.WithdrawOverflow(amount);
            account.Deposit(transferAmount);
            JsonFileLoader<ref BastionBankAccount>.JsonSaveFile(accountDir, account);
        }
    }

    int GetWageByPlayerBase(ref PlayerBase player) {
        BastionPlayerAccount playerAccount = player.GetBastionPlayerAccount();
        string playerAccountDir = BBConst.playerDir + "\\" + player.GetIdentity().GetPlainId() + "\\" + player.GetIndex() + BBConst.fileType;
        string position;
        int wage;

        LoadWages();

        if (playerAccount) {
            position = playerAccount.GetJobPosition();
            mapJobWages.Find(position, wage);
        }
        return wage;
    }

    ref BastionBankAccount FindAccount(ref PlayerBase player, int accountId = -1) {
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) { return null; }

        ref BastionBankAccount bankAccount;

        bankAccount = GetLoggedInAccount(player);
        if (bankAccount) {
            return bankAccount;
        }
        if (accountId == -1) {
            bankAccount = GetAccountByPlayerBase(player);
            return bankAccount;
        } else {
            bankAccount = GetAccountById(accountId)
        }
        return bankAccount;
    }

    ref BastionBankAccount GetAccountByPlayerBase(ref PlayerBase player) {
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) { return null; }

        ref BastionPlayerAccount playerAccount = player.GetBastionPlayerAccount();
        ref BastionBankAccount bankAccount;
        int accountId;

        if (playerAccount) {
            accountId = playerAccount.GetId();
            bankAccount = GetAccountById(accountId);
        }
        return bankAccount;
    }

    ref BastionBankAccount GetLoggedInAccount(ref PlayerBase player) {
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) { return null; }

        ref BastionBankAccount account;
        string accountDir;

        if (mapAccountLogins.Find(player, account)) {
            accountDir = BBConst.accountDir + "\\" + account.GetId() + BBConst.fileType;

            if (FileExist(accountDir)) {
                JsonFileLoader<BastionBankAccount>.JsonLoadFile(accountDir, account);
            } else {
                Logout(player);
            }
        }
        return account;
    }

    ref BastionBankAccount GetAccountById(int accountId) {
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) { return null; }

        ref BastionBankAccount account;
        string accountDir = BBConst.accountDir + "\\" + accountId + BBConst.fileType;

        if (FileExist(accountDir)) {
            JsonFileLoader<BastionBankAccount>.JsonLoadFile(accountDir, account);
        }
        return account;
    }

    ref BastionAccountTracker GetStatTracker() {
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) { return null; }

        return accountTracker;
    }
}
BastionAccountManager GetBankAccountManager() {
    return BastionAccountManager.Cast(GetPlugin(BastionAccountManager));
}