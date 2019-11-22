class BastionPlayerAccount {
    private string path, jobPosition;
    private int bankId;

    void BastionPlayerAccount(string dir, int id,) {
        path = dir;
        bankId = id;
        jobPosition = "unemployed";
    }

    void SetJobPosition(string position) {
        jobPosition = position;
    }

    string GetPath() {
        return path;
    }

    int GetId() {
        return bankId;
    }

    string GetJobPosition() {
        return jobPosition;
    }
}