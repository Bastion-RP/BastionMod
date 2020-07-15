class BST_CraftingCategoryConfig {
    private ref array<ref BST_CraftingCategory> ParentCategories;
    private ref array<ref BST_CraftingSubCategory> SubCategories;

    void BST_CraftingCategoryConfig() {
        ParentCategories = new array<ref BST_CraftingCategory>();
        SubCategories = new array<ref BST_CraftingSubCategory>();

        ParentCategories.Insert(new BST_CraftingCategory());
        SubCategories.Insert(new BST_CraftingSubCategory());
    }

    array<ref BST_CraftingCategory> GetParentCategories() {
        return ParentCategories;
    }

    array<ref BST_CraftingSubCategory> GetSubCategories() {
        return SubCategories;
    }
}