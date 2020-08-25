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

    BST_BankAccount FindAccount(string playerId, string characterId, out string accountDir) {
        if (playerId.Length() <= 0 || characterId.Length() <= 0) { return null; }

        BST_BankAccount account;
        string playerDir;

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

    void ValidateAccountFunds(BST_BankAccount account, int fundsCap) {
        int moveToOverflow;

        if (account.GetFunds() > fundsCap) {
            moveToOverflow = account.GetFunds() - fundsCap;

            account.Withdraw(moveToOverflow);
            account.DepositOverflow(moveToOverflow);
        }

    }

    void DepositFundsToAccount(BST_BankAccount account, int characterClass, int amount) {
        int difference, fundsCap, moveToOverflow;

        fundsCap = GetBSTBankingConfigHandler().GetConfig().GetFundsCapByClass(characterClass);

        ValidateAccountFunds(account, fundsCap);
        
        if ((account.GetFunds() + amount) > fundsCap) {
            difference = fundsCap - account.GetFunds();
            amount -= difference;

            account.Deposit(difference);
            account.DepositOverflow(amount);
        } else {
            account.Deposit(amount);
        }
    }

    void PayUBI(PlayerBase player) {
        string debugSuffix = player.GetMultiCharactersPlayerName() + " | id=" + player.GetMultiCharactersPlayerId() + " | class=" + player.GetMultiCharactersPlayerClass();

        Print("[BANKING DEBUG] Checking UBI on player=" + debugSuffix + " | pid=" + player.GetIdentity().GetPlainId());
        BST_BankAccount account;
        string accountDir;

        account = FindAccount(player.GetIdentity().GetPlainId(), "" + player.GetMultiCharactersPlayerId(), accountDir);
        Print("[BANKING DEBUG] Searching for account=" + account);

        if (account) {
            Print("[BANKING DEBUG] Checking time since last pay=" + account.GetTimeSinceLastPay());

            if (account.GetTimeSinceLastPay() > GetBSTBankingConfigHandler().GetConfig().GetPassivePayInterval()) {
                Print("[BANKING DEBUG] Passed time conditional");
                int payRate = GetBSTBankingConfigHandler().GetConfig().GetPayByClass(player.GetMultiCharactersPlayerClass());
                Print("[BANKING DEBUG] Grabbed pay rate=" + payRate);

                if (payRate > 0) {
                    Print("[BANKING DEBUG] Paying client!!! funds=" + account.GetFunds() + " | overflow=" + account.GetOverflowFunds());
                    DepositFundsToAccount(account, player.GetMultiCharactersPlayerClass(), payRate);
                    Print("[BANKING DEBUG] Paid client!!! funds=" + account.GetFunds() + " | overflow=" + account.GetOverflowFunds());
                    account.ClearTimeSincePay();
                }
            } else {
                Print("[BANKING DEBUG] Incrementing time since last pay!");
                account.IncrementTimeSincePay()
            }
            JsonFileLoader<BST_BankAccount>.JsonSaveFile(accountDir, account);
        }
    }

    BST_BankAccount Deposit(string playerId, string characterId, int characterClass, int amount) {
        BST_BankAccount account;
        string accountDir;

        account = FindAccount(playerId, characterId, accountDir);

        if (account && accountDir != "") {
            DepositFundsToAccount(account, characterClass, amount);
            JsonFileLoader<BST_BankAccount>.JsonSaveFile(accountDir, account);
        }
        return account;
    }
}

BST_BankingAccountManager GetBSTBankingAccountManager() {
    return BST_BankingAccountManager.Cast(GetPlugin(BST_BankingAccountManager));
}