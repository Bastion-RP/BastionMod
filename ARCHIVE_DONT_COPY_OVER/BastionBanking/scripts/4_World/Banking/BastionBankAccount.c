class BastionBankAccount {
    // Create a inherited class of this so I can store logintimeout without saving it to json
    private string ownerId, password;
    private int bankId, funds, overflow;
    
    void BastionBankAccount(int id, string playerId, string pass) {
        bankId = id;
        ownerId = playerId;
        password = pass;
    }

    void Deposit(int amount) {
        funds += amount;
    }

    void DepositOverflow(int amount) {
        overflow += amount;
    }

    void Withdraw(int amount) {
        funds -= amount;
    }

    void WithdrawOverflow(int amount) {
        overflow -= amount;
    }

    string GetPassword() {
        return password;
    }
    
    string GetOwnerId() {
        return ownerId;
    }

    int GetFunds() {
        return funds;
    }

    int GetOverflowFunds() {
        return overflow;
    }

    int GetId() {
        return bankId;
    }
}