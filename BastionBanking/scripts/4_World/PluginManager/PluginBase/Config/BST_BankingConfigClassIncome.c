class BST_BankingConfigClassIncome {
    private string _className;
    private int _payRate;

    void BST_BankingConfigClassMap() {
        _className = "A";
        _payRate = 0;
    }

    void Lower() {
        _className.ToLower();
    }

    string GetLoweredClassName() {
        string loweredString = _className;

        loweredString.ToLower();
        return loweredString;
    }

    string GetClassName() { return _className; }
    int GetPayRate() { return _payRate; }
}