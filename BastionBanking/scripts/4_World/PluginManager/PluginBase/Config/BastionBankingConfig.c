class BastionBankingConfig {
    private int LoginTimeout, PassivePayInterval, BankFundsCap;
    private float OverflowTransferFee;

    void BastionBankingConfig() {
        LoginTimeout = 60;
        PassivePayInterval = 60;
        BankFundsCap = 1000;
        OverflowTransferFee = 0.25;
    }

    void Validate() {
        if (LoginTimeout < 1) {
            LoginTimeout = 60;
        }
        if (PassivePayInterval < 1) {
            PassivePayInterval = 60;
        }
        if (BankFundsCap < 1) {
            BankFundsCap = 1000;
        }
        if (OverflowTransferFee < 0.01) {
            OverflowTransferFee = 0.25
        }
    }
    
    int LoginTimeout() {
        return LoginTimeout;
    }

    int PassivePayInterval() {
        return PassivePayInterval;
    }

    int BankFundsCap() {
        return BankFundsCap;
    }

    float OverflowTransferFee() {
        return OverflowTransferFee;
    }
}