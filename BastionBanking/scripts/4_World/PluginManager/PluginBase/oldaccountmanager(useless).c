/* class BastionAccountManager : PluginBase {
    // Create a save loop for the stat tracker?
    // Can track a lot more than just total accounts created, but that's enough for right now so I can create new account Id's without reusing any, causing a conflict.
    // I just realized that none of this is going to work. username == accountId which will be generated randomly. Then call to that file and grab the information from it 
    // and send it to the client.

    private ref map<string, ref array<ref BastionBankAccount>> mapPlayerBankAccounts;
    private ref BastionAccountTracker accountTracker = new BastionAccountTracker();

    void BastionAccountManager() {
        mapPlayerBankAccounts = new map<string, ref array<ref BastionBankAccount>>();
        JsonFileLoader<ref BastionAccountTracker>.JsonLoadFile("$profile:\\Bastion\\Banking\\StatTracking.bastion", accountTracker);

        auto params = new Param2<string, string>("$profile:\\Bastion\\Banking\\Players", "");
        GetGame().GameScript.Call(this, "FindAndLoadAccounts", params);
        //GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(DebugMap, 5000);
    }

    void DebugMap() {
        Print("Debugging map");
        ref array<string> debugString = new array<string>();
        ref array<array<ref BastionBankAccount>> debugAccounts = new array<array<ref BastionBankAccount>>();

        debugString = mapPlayerBankAccounts.GetKeyArray();
        debugAccounts = mapPlayerBankAccounts.GetValueArray();

        debugString.Debug();
        debugAccounts.Debug();
        foreach (array<ref BastionBankAccount> yeet : debugAccounts) {
            yeet.Debug();
        }
    }
    
    void CreateNewAccount(string playerId) {
        ref BastionBankAccount
        accountTracker.AddAccount();
    }

    void FindAndLoadAccounts(Param2<string, string> data) {
        ref array<ref BastionBankAccount> playerAccounts = new array<ref BastionBankAccount>();
        string fullDir = data.param1;
        string userId = data.param2;

        if (FileExist(fullDir)) {
            string fileName, filePattern = fullDir + "\\*";
            bool fileFound = true;
            FileAttr fileAttr;
            FindFileHandle fileSearch = FindFile(filePattern, fileName, fileAttr, FindFileFlags.ALL);

            while (fileFound) {
                //Print("fileName=" + fileName + " | filePattern=" + filePattern + " | fullDir=" + fullDir);
                string currentDir = fullDir + "\\" + fileName;

                if (fullDir == "$profile:\\Bastion\\Banking\\Players") {
                    auto params = new Param2<string, string>(currentDir, fileName);
                    GetGame().GameScript.Call(this, "FindAndLoadAccounts", params);
                } else {
                    BastionBankAccount account;
                    JsonFileLoader<BastionBankAccount>.JsonLoadFile(currentDir, account);

                    if (account) {
                        playerAccounts.Insert(account);
                    }
                }
                fileFound = FindNextFile(fileSearch, fileName, fileAttr)
            }
            CloseFindFile(fileSearch);

            if (playerAccounts.Count() > 0) {
                mapPlayerBankAccounts.Insert(userId, playerAccounts);
            }
        }
        delete playerAccounts;
    }
} */