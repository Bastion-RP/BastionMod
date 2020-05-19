class BastionAccountManager : PluginBase {
    private ref map<PlayerBase, ref BastionActiveBankAccount> mapAccountLogins;
    private ref BastionAccountTracker accountTracker;

    void BastionAccountManager() {
        accountTracker = new BastionAccountTracker();
        mapAccountLogins = new map<PlayerBase, ref BastionActiveBankAccount>();

        //GetDayZGame().Event_OnRPC.Insert(AccountManagerRPC);
        LoadTracker();
        CheckDirectories();
        GetGame().GameScript.Call(this, "LoginTimeoutLoop", null);
    }

    void ~BastionAccountManager() {
        //GetDayZGame().Event_OnRPC.Remove(AccountManagerRPC);
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
            JsonFileLoader<BastionAccountTracker>.JsonSaveFile(BBConst.trackerDir, accountTracker);
        } else {
            JsonFileLoader<BastionAccountTracker>.JsonLoadFile(BBConst.trackerDir, accountTracker);
        }
    }

    void LoginTimeoutLoop() {
        while (true) {
            for (int i = (mapAccountLogins.Count() - 1); i >= 0; i--) {
                PlayerBase player = mapAccountLogins.GetKey(i);
                BastionActiveBankAccount bankAccount = mapAccountLogins.GetElement(i);
                
                if (!player || !bankAccount) {
                    mapAccountLogins.RemoveElement(i);
                } else {
                    int accountTimeout = bankAccount.GetTimeout();

                    if (accountTimeout <= 0) {
                        auto params = new Param2<string, string>("logintimeout", ", you have been logged out due to inactivity!");

                        GetGame().RPCSingleParam(player, BSTBankRPC.RPC_CLIENT_ERROR, params, true, player.GetIdentity());
                        mapAccountLogins.RemoveElement(i);
                        Logout(player);
                    } else {
                        bankAccount.DecrementTimeout();
                    }
                }
            }
            Sleep(1000);
        }
    }

    bool CanCreateNewAccount(PlayerBase player, out int bankId) {
        int playerIndex = player.GetMultiCharactersPlayerId();
        string playerAccountDir;
        string playerId = player.GetIdentity().GetPlainId();
        string playerDir = BBConst.playerDir + "\\" + playerId;
        BastionPlayerAccount playerAccount = player.GetBastionPlayerAccount();

        if (playerAccount) {
            string accountDir = playerAccount.GetPath();

            if (!FileExist(accountDir)) {
                bankId = playerAccount.GetId();
                return true;
            }
            return false;
        } else {
            bankId = (accountTracker.GetTotalAccounts() + 1);
        }
        return true;
    }

    void CreateAccount(PlayerBase player, string password, int id, out BastionActiveBankAccount account) {
        BastionActiveBankAccount bankAccount;
        BastionPlayerAccount playerAccount;
        int playerIndex = player.GetMultiCharactersPlayerId();
        string bankAccountDir = BBConst.accountDir + "\\" + id + BBConst.fileType;
        string playerId = player.GetIdentity().GetPlainId();
        string playerDir = BBConst.playerDir + "\\" + playerId;
        string playerAccountDir = playerDir + "\\" + player.GetMultiCharactersPlayerId() + BBConst.fileType;

        if (!FileExist(playerDir)) {
            MakeDirectory(playerDir);
        }
        bankAccount = new BastionActiveBankAccount(id, playerId, password);
        playerAccount = new BastionPlayerAccount(bankAccountDir, id);
        JsonFileLoader<BastionBankAccount>.JsonSaveFile(bankAccountDir, bankAccount);
        JsonFileLoader<BastionPlayerAccount>.JsonSaveFile(playerAccountDir, playerAccount);

        player.SetBastionPlayerAccount(playerAccount);
        accountTracker.AddAccount();
        account = bankAccount;
    }

    bool CanLogin(PlayerBase player, int accountId, string password, out BastionActiveBankAccount account) {
        string accountDir;
        
        if (accountId != -1) {
            account = GetAccountById(accountId);
        } else {
            account = GetLoggedInAccount(player);

            if (!account) {
                BastionPlayerAccount playerAccount = player.GetBastionPlayerAccount();
                account = GetAccountById(playerAccount.GetId());
            }
        }
        Print("Bank id at canlogin=" + accountId);

        if (account) {
            if (account.GetPassword() == password) {
                return true;
            }
        }
        return false;
    }

    void Login(PlayerBase player, BastionActiveBankAccount account) {
        ResetAccountTimeout(account);
        mapAccountLogins.Insert(player, account);
    }

    bool CanLogout(PlayerBase player) {
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) { return false; }

        return mapAccountLogins.Contains(player);
    }

    void Logout(PlayerBase player) {
        BastionActiveBankAccount account;

        if (mapAccountLogins.Find(player, account)) {
            delete account;
            mapAccountLogins.Remove(player);
        }
    }

    void ResetAccountTimeout(BastionActiveBankAccount account) {
        if (account) {
            account.ResetTimeout();
        }
    }

    void Deposit(BastionActiveBankAccount account, int amount) {
        string accountDir = BBConst.accountDir + "\\" + account.GetId() + BBConst.fileType;
        int funds, fundsCap, difference;

        if (FileExist(accountDir)) {
            funds = account.GetFunds();
            fundsCap = GetBBankConfig().GetConfig().GetBankFundsCap()

            if ((funds + amount) > fundsCap) {
                difference = fundsCap - funds;
                amount -= difference;

                account.Deposit(difference);
                account.DepositOverflow(amount);
            } else {
                account.Deposit(amount);
            }
            JsonFileLoader<BastionBankAccount>.JsonSaveFile(accountDir, account);
        }
    }

    void Withdraw(BastionActiveBankAccount account, int amount) {
        string accountDir = BBConst.accountDir + "\\" + account.GetId() + BBConst.fileType;

        if (FileExist(accountDir)) {
            account.Withdraw(amount);
            JsonFileLoader<BastionBankAccount>.JsonSaveFile(accountDir, account);
        }
    }

    void Transfer(BastionActiveBankAccount account, int amount) {
        string accountDir = BBConst.accountDir + "\\" + account.GetId() + BBConst.fileType;
        int transferAmount;

        if (FileExist(accountDir)) {
            transferAmount = Math.Round((amount * (1 - GetBBankConfig().GetConfig().GetOverflowTransferFee())));

            account.WithdrawOverflow(amount);
            account.Deposit(transferAmount);
            JsonFileLoader<BastionBankAccount>.JsonSaveFile(accountDir, account);
        }
    }

    bool ResetAccountPassword(BastionBankAccount account, string password) {
        if (account && password != string.Empty) {
            // log out all accounts by id
            for (int i = (mapAccountLogins.Count() - 1); i >= 0; i--) {
                BastionBankAccount checkAccount = mapAccountLogins.GetElement(i);

                if (checkAccount && checkAccount.GetId() == account.GetId()) {
                    mapAccountLogins.RemoveElement(i);
                }
            }
            account.SetPassword(password);

            string accountDir = BBConst.accountDir + "\\" + account.GetId() + BBConst.fileType;

            JsonFileLoader<BastionBankAccount>.JsonSaveFile(accountDir, account);
            return true;
        }
        return false;
    }

    int GetWageByPlayerBase(PlayerBase player) {
        BastionPlayerAccount playerAccount = player.GetBastionPlayerAccount();

        if (playerAccount) {
            string position = playerAccount.GetJobPosition();

            return GetBBankConfig().GetConfig().GetWageByJobPosition(position);
        }
        return 0;
    }

    ref map<PlayerBase, ref BastionActiveBankAccount> GetLoggedInAccounts() {
        return mapAccountLogins;
    }

    BastionActiveBankAccount GetAccountByPlayerBase(PlayerBase player) {
        if (!player) { return null; }
        BastionPlayerAccount playerAccount = player.GetBastionPlayerAccount();
        Print("GetAccountByPlayerBase | Getting player account=" + playerAccount);

        if (playerAccount) {
            Print("GetAccountByPlayerBase | player account exists");
            return GetAccountById(playerAccount.GetId());
        }
        return null;
    }

    BastionActiveBankAccount GetAccountById(int accountId) {
        BastionActiveBankAccount account;
        string accountDir = BBConst.accountDir + "\\" + accountId + BBConst.fileType;
        
        if (FileExist(accountDir)) {
            JsonFileLoader<BastionActiveBankAccount>.JsonLoadFile(accountDir, account);
            Print("GetAccountById | File exists, loading file=" + account);
        }
        return account;
    }

    BastionActiveBankAccount GetLoggedInAccount(PlayerBase player) {
        if (mapAccountLogins.Contains(player)) {
            BastionActiveBankAccount account = mapAccountLogins.Get(player);
            string accountDir = BBConst.accountDir + "\\" + account.GetId() + BBConst.fileType;

            Print("GetLoggedInAccount | Finding account=" + account);
            Print("GetLoggedInAccount | Getting account dir=" + accountDir);

            if (FileExist(accountDir)) {
                JsonFileLoader<BastionActiveBankAccount>.JsonLoadFile(accountDir, account);
                Print("GetLoggedInAccount | File exists=" + account);
                return account;
            } else {
                Logout(player);
            }
        }
        return null;
    }

    BastionAccountTracker GetStatTracker() {
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) { return null; }

        return accountTracker;
    }
}
BastionAccountManager GetBankAccountManager() {
    return BastionAccountManager.Cast(GetPlugin(BastionAccountManager));
}