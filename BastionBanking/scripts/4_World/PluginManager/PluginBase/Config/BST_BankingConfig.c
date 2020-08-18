class BST_BankingConfig {
    // Constants
    static const string DEFAULT_CURRENCY_CLASSNAME = "nail";
    static const string DEFAULT_ATM_CLASSNAME = "seachest";
    static const int DEFAULT_CLASS_INCOME = 0;
    static const int DEFAULT_PAY_INTERVAL = 60;
    static const int DEFAULT_FUNDS_CAP = 1000;
    static const float DEFAULT_TRANSFER_FEE = 0.25;

    private ref array<ref BST_BankingConfigClassIncome> PerClassIncome;
    private ref array<ref BST_BankingConfigClassFundsCap> PerClassFundsCap;
    private int PassivePayIntervalInMinutes, DefaultBankFundsCap;
    private float OverflowTransferFee;
    private string CurrencyClassName, ATMClassName;

    void BST_BankingConfig() {
        PerClassIncome = new array<ref BST_BankingConfigClassIncome>();
        PerClassFundsCap = new array<ref BST_BankingConfigClassFundsCap>();
        PassivePayIntervalInMinutes = DEFAULT_PAY_INTERVAL;
        DefaultBankFundsCap = DEFAULT_FUNDS_CAP;
        OverflowTransferFee = DEFAULT_TRANSFER_FEE;
        CurrencyClassName = DEFAULT_CURRENCY_CLASSNAME;
        ATMClassName = DEFAULT_ATM_CLASSNAME;
    }

    void Validate() {
        if (PerClassIncome.Count() <= 0) {
            PerClassIncome.Insert(new BST_BankingConfigClassIncome());
        }
        if (PerClassFundsCap.Count() <= 0) {
            PerClassFundsCap.Insert(new BST_BankingConfigClassFundsCap());
        }
        if (PassivePayIntervalInMinutes < 1) {
            PassivePayIntervalInMinutes = DEFAULT_PAY_INTERVAL;
        }
        if (DefaultBankFundsCap < 1) {
            DefaultBankFundsCap = DEFAULT_FUNDS_CAP;
        }
        if (OverflowTransferFee < 0.0) {
            OverflowTransferFee = DEFAULT_TRANSFER_FEE;
        }
        if (CurrencyClassName == "") {
            CurrencyClassName = DEFAULT_CURRENCY_CLASSNAME;
        }
        if (ATMClassName == "") {
            ATMClassName = DEFAULT_ATM_CLASSNAME;
        }
    }

    string GetClassStringByInt(int classInt) {
        string classToString = typename.EnumToString(BastionClasses, classInt);
        classToString.ToLower();
        
        if (classToString.IndexOf("_") != -1) {
            classToString.Replace("_", "-");
        }
        return classToString;
    }

    int GetPayByClass(int classInt) {
        string classToString = GetClassStringByInt(classInt);
        
        foreach (BST_BankingConfigClassIncome classIncome : PerClassIncome) {
            if (classIncome && classIncome.GetLoweredClassName() == classToString) {
                return classIncome.GetPayRate();
            }
        }
        return 0;
    }

    int GetFundsCapByClass(int classInt) {
        string classToString = GetClassStringByInt(classInt);
        
        foreach (BST_BankingConfigClassFundsCap fundsCap : PerClassFundsCap) {
            if (fundsCap && fundsCap.GetLoweredClassName() == classToString) {
                return fundsCap.GetFundsCap();
            }
        }
        return DefaultBankFundsCap;
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
        return PassivePayIntervalInMinutes;
    }

    int GetBankFundsCap() {
        return DefaultBankFundsCap;
    }

    float GetOverflowTransferFee() {
        return OverflowTransferFee;
    }
}