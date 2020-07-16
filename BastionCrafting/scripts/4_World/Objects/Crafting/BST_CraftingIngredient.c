class BST_CraftingIngredient {
    private string ItemClassname;
    private int RequiredAmount;
    private bool IsConsumable;

    void BST_CraftingIngredient(string ItemClassname, int RequiredAmount, bool IsConsumable) {
        this.ItemClassname = ItemClassname;
        this.RequiredAmount = RequiredAmount;
        this.IsConsumable = IsConsumable;
    }

    string GetLoweredClassname() {
        string loweredClassname = ItemClassname;
        
        loweredClassname.ToLower();
        return loweredClassname;
    }
    
    string GetClassname() { return ItemClassname; }
    int GetRequiredAmount() { return RequiredAmount; }
    bool IsConsumable() { return IsConsumable; }
}