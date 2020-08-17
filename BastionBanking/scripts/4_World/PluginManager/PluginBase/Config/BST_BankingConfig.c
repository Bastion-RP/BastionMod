class BST_BankingConfig {
    // Constants
    static const string DEFAULT_JOB_POSITION = "Unemployed";
    static const string DEFAULT_CURRENCY_CLASSNAME = "nail";
    static const string DEFAULT_ATM_CLASSNAME = "seachest";
    static const int DEFAULT_JOB_INCOME = 0;
    static const int DEFAULT_PAY_INTERVAL = 60;
    static const int DEFAULT_FUNDS_CAP = 1000;
    static const float DEFAULT_TRANSFER_FEE = 0.25;

    private ref map<string, int> PerJobPassiveIncome;
    private string DefaultJobPosition;
    private int DefaultJobIncome, PassivePayInterval, BankFundsCap;
    private float OverflowTransferFee;
    private string CurrencyClassName, ATMClassName;

    void BST_BankingConfig() {
        this.PerJobPassiveIncome = new map<string, int>();
        this.DefaultJobPosition = DEFAULT_JOB_POSITION;
        this.DefaultJobIncome = DEFAULT_JOB_INCOME;
        this.PassivePayInterval = DEFAULT_PAY_INTERVAL;
        this.BankFundsCap = DEFAULT_FUNDS_CAP;
        this.OverflowTransferFee = DEFAULT_TRANSFER_FEE;
        this.CurrencyClassName = DEFAULT_CURRENCY_CLASSNAME;
        this.ATMClassName = DEFAULT_ATM_CLASSNAME;
        this.PerJobPassiveIncome.Insert(DefaultJobPosition, DefaultJobIncome);
    }

    void Validate() {
        if (DefaultJobPosition == string.Empty) {
            DefaultJobPosition = DEFAULT_JOB_POSITION;
        }
        if (DefaultJobIncome < 0) {
            DefaultJobIncome = DEFAULT_JOB_INCOME;
        }
        if (PerJobPassiveIncome.Count() <= 0) {
            PerJobPassiveIncome.Insert(DefaultJobPosition, DefaultJobIncome);
        }
        if (PassivePayInterval < 1) {
            PassivePayInterval = DEFAULT_PAY_INTERVAL;
        }
        if (BankFundsCap < 1) {
            BankFundsCap = DEFAULT_FUNDS_CAP;
        }
        if (OverflowTransferFee < 0.01) {
            OverflowTransferFee = DEFAULT_TRANSFER_FEE;
        }
        if (CurrencyClassName == string.Empty) {
            CurrencyClassName = DEFAULT_CURRENCY_CLASSNAME;
        }
        if (ATMClassName == string.Empty) {
            ATMClassName = DEFAULT_ATM_CLASSNAME;
        }
    }
    // Jobs have yet to be implemented so I'm not sure how this will be done
    
    int GetWageByJobPosition(string position) {
        if (PerJobPassiveIncome.Contains(position)) {
            return PerJobPassiveIncome.Get(position);
        }
        return 0;
    }

    string GetDefaultJobPosition() {
        return DefaultJobPosition;
    }

    string GetCurrencyClassName() {
        string loweredName = CurrencyClassName;

        loweredName.ToLower();
        return loweredName;
    }

    string GetATMClassName() {
        string loweredName = ATMClassName;

        loweredName.ToLower();
        return loweredName;
    }

    int GetPassivePayInterval() {
        return PassivePayInterval;
    }

    int GetBankFundsCap() {
        return BankFundsCap;
    }

    float GetOverflowTransferFee() {
        return OverflowTransferFee;
    }
}