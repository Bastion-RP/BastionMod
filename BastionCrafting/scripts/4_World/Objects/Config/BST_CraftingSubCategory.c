class BST_CraftingSubCategory : BST_CraftingCategory {
    private int ParentCategoryID;

    void BST_CraftingSubCategory() {
        this.ParentCategoryID = -1;
    }

    int GetParentId() {
        return ParentCategoryID;
    }
}