class BastionActiveBankAccount : BastionBankAccount {
    private int loginTimeout;
    
    void BastionActiveBankAccount(int id, string playerId, string pass) {
        loginTimeout = GetBBankConfig().GetConfig().GetLoginTimeout();
    }

    void ResetTimeout() {
        Print("BastionActiveBankAccount | Resetting account timeout!!! = " + GetBBankConfig().GetConfig().GetLoginTimeout());
        loginTimeout = GetBBankConfig().GetConfig().GetLoginTimeout();
    }

    void DecrementTimeout() {
        loginTimeout--;
    }

    int GetTimeout() {
        return loginTimeout;
    }
}