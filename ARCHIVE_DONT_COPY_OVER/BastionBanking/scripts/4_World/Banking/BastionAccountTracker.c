class BastionAccountTracker {
    private int TotalAccounts;

    void BastionAccountTracker() {
        TotalAccounts = 0;
    }

    void AddAccount() {
        TotalAccounts++;
        SaveTracker();
    }

    void SaveTracker() {
        JsonFileLoader<BastionAccountTracker>.JsonSaveFile(BBConst.trackerDir, this);
    }

    int GetTotalAccounts() {
        return TotalAccounts;
    }
}