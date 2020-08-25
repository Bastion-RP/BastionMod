class BST_BankingConfigClass {
    protected string ClassName;

    void BST_BankingConfigClass() {
        ClassName = "A";
    }

    string GetLoweredClassName() {
        string loweredString = ClassName;

        loweredString.ToLower();
        return loweredString;
    }

    string GetClassName() { return ClassName; }
}