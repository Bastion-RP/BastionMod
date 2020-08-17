class BST_BankingAccountManager : PluginBase {
    void BST_BankingAccountManager() {
        CheckDirectories();
    }

    void ~BST_BankingAccountManager() {
    }

    void CheckDirectories() {
        if (!FileExist(BST_BankingConst.profileDir)) {
            MakeDirectory(BST_BankingConst.profileDir);
        }
        if (!FileExist(BST_BankingConst.modDir)) {
            MakeDirectory(BST_BankingConst.modDir);
        }
        if (!FileExist(BST_BankingConst.playerDir)) {
            MakeDirectory(BST_BankingConst.playerDir);
        }
    }

    BST_BankAccount FindAccount(string playerId, string characterId) {
        if (playerId.Length() <= 0 || characterId.Length() <= 0) { return null; }

        BST_BankAccount account;
        string playerDir, accountDir;

        playerDir = BST_BankingConst.playerDir + "\\" + playerId;
        accountDir = playerDir + "\\" + characterId + ".json";

        if (FileExist(accountDir)) {
            JsonFileLoader<BST_BankAccount>.JsonLoadFile(accountDir, account);
        } else {
            if (!FileExist(playerDir)) {
                MakeDirectory(playerDir);
            }
            account = new BST_BankAccount();
            JsonFileLoader<BST_BankAccount>.JsonSaveFile(accountDir, account);
        }
        return account;
    }

    BST_BankAccount Deposit(string playerId, string characterId, int amount) {
        if (playerId.Length() <= 0 || characterId.Length() <= 0) { return null; }
        BST_BankAccount account;
        string accountDir;
        int funds, fundsCap, difference;

        account = FindAccount(playerId, characterId);
        accountDir = BST_BankingConst.playerDir + "\\" + playerId + "\\" + characterId + ".json";

        if (account) {
            funds = account.GetFunds();
            fundsCap = GetBSTBankingConfigHandler().GetConfig().GetBankFundsCap();

            if ((funds + amount) > fundsCap) {
                difference = fundsCap - funds;
                amount -= difference;

                account.Deposit(difference);
                account.DepositOverflow(amount);
            } else {
                account.Deposit(amount);
            }
            JsonFileLoader<BST_BankAccount>.JsonSaveFile(accountDir, account);
        }
        return account;
    }
}

BST_BankingAccountManager GetBSTBankingAccountManager() {
    return BST_BankingAccountManager.Cast(GetPlugin(BST_BankingAccountManager));
}