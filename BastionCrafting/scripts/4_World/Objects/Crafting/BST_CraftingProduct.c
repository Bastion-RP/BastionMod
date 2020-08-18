class BST_CraftingProduct {
    private string ItemClassname;
    private int RequiredAmount;

    void BST_CraftingProduct(string ItemClassname, int RequiredAmount) {
        this.ItemClassname = ItemClassname;
        this.RequiredAmount = RequiredAmount;
    }

    string GetLoweredClassname() {
        string loweredClassname = ItemClassname;
        
        loweredClassname.ToLower();
        return loweredClassname;
    }
    
    string GetClassname() { return ItemClassname; }
    int GetRequiredAmount() { return RequiredAmount; }
}