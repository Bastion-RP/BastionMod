class BST_CraftingCategory {
    private string CategoryName;
    private int CategoryID;

    void BST_CraftingCategory() {
        this.CategoryName = "New Category";
        this.CategoryID = -1;
    }

    string GetName() {
        return CategoryName;
    }

    int GetId() {
        return CategoryID;
    }
}