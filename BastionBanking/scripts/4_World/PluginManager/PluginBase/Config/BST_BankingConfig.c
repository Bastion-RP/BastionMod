class BST_BankingConfig {
    // Constants
    static const string DEFAULT_CURRENCY_CLASSNAME = "nail";
    static const string DEFAULT_ATM_CLASSNAME = "seachest";
    static const int DEFAULT_CLASS_INCOME = 0;
    static const int DEFAULT_PAY_INTERVAL = 60;
    static const int DEFAULT_FUNDS_CAP = 1000;
    static const float DEFAULT_TRANSFER_FEE = 0.25;

    private ref array<ref BST_BankingConfigClassIncome> PerClassIncome;
    private int PassivePayIntervalInMinutes, BankFundsCap;
    private float OverflowTransferFee;
    private string CurrencyClassName, ATMClassName;

    void BST_BankingConfig() {
        PerClassIncome = new array<ref BST_BankingConfigClassIncome>();
        PassivePayIntervalInMinutes = DEFAULT_PAY_INTERVAL;
        BankFundsCap = DEFAULT_FUNDS_CAP;
        OverflowTransferFee = DEFAULT_TRANSFER_FEE;
        CurrencyClassName = DEFAULT_CURRENCY_CLASSNAME;
        ATMClassName = DEFAULT_ATM_CLASSNAME;
    }

    void Validate() {
        if (PerClassIncome.Count() <= 0) {
            PerClassIncome.Insert(new BST_BankingConfigClassIncome());
        }
        if (PassivePayIntervalInMinutes < 1) {
            PassivePayIntervalInMinutes = DEFAULT_PAY_INTERVAL;
        }
        if (BankFundsCap < 1) {
            BankFundsCap = DEFAULT_FUNDS_CAP;
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

    int GetPayByClass(int classInt) {
        string classToString = typename.EnumToString(BastionClasses, classInt);
        classToString.ToLower();
        
        if (classToString.IndexOf("_") != -1) {
            classToString.Replace("_", "-");
        }
        foreach (BST_BankingConfigClassIncome classIncome : PerClassIncome) {
            if (classIncome && classIncome.GetLoweredClassName() == classToString) {
                return classIncome.GetPayRate();
            }
        }
        return 0;
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
        return BankFundsCap;
    }

    float GetOverflowTransferFee() {
        return OverflowTransferFee;
    }
}