class BastionPlayerAccount {
    string path;
    int bankId;
    int income;

    void BastionPlayerAccount(string dir, int id, int i) {
        path = dir;
        bankId = id;
        income = i;
    }

    string GetPath() {
        return path;
    }

    int GetId() {
        return bankId;
    }

    int GetIncome() {
        return income;
    }
}