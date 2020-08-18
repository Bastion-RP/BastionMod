class BST_BankAccount {
    private int funds, overflow;

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

    int GetFunds() {
        return funds;
    }

    int GetOverflowFunds() {
        return overflow;
    }
}