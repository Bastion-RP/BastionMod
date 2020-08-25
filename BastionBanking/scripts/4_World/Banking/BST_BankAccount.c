class BST_BankAccount {
    private int funds, overflow, _timeSincePaid;

    void BST_BankAccount() {
        funds = 0;
        overflow = 0;
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

    void ClearTimeSincePay() {
        _timeSincePaid = 0;
    }

    void IncrementTimeSincePay() {
        _timeSincePaid++;
    }

    int GetFunds() { return funds; }
    int GetOverflowFunds() { return overflow; }
    int GetTimeSinceLastPay() { return _timeSincePaid; }
}