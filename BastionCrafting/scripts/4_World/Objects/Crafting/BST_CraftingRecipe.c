class BST_CraftingRecipe {
    private static const string DEFAULT_RECIPE_STRING = "CHANGE ME";
    private static const int DEFAULT_CRAFT_TIME = 60;

    private ref array<ref BST_CraftingIngredient> Ingredients;
    private string RecipeName, RecipeDescription, ProductClassName, RequiredCraftingBench;
    private int CraftTime, SubCategoryID;

    void BST_CraftingRecipe(array<ref BST_CraftingIngredient> Ingredients) {
        this.Ingredients = Ingredients;
        this.RecipeName = DEFAULT_RECIPE_STRING;
        this.RecipeDescription = DEFAULT_RECIPE_STRING;
        this.ProductClassName = DEFAULT_RECIPE_STRING;
        this.CraftTime = DEFAULT_CRAFT_TIME;
        this.RequiredCraftingBench = string.Empty;
        this.SubCategoryID = -1;
    }

    bool Validate() {
        if (RecipeName == string.Empty) {
            RecipeName = DEFAULT_RECIPE_STRING;
        }
        if (RecipeDescription == string.Empty) {
            RecipeDescription = DEFAULT_RECIPE_STRING;
        }
        if (CraftTime < 0) {
            CraftTime = DEFAULT_CRAFT_TIME;
        }
        if (ProductClassName == string.Empty) {
            ProductClassName = DEFAULT_RECIPE_STRING;
            return false;
        } else if (ProductClassName == DEFAULT_RECIPE_STRING) {
            return false;
        }
        return true;
    }

    string GetLoweredName() {
        string loweredName = RecipeName;

        loweredName.ToLower();
        return loweredName;
    }

    string GetRequiredBench() {
        string loweredType = RequiredCraftingBench;

        loweredType.ToLower();
        return loweredType;
    }

    array<ref BST_CraftingIngredient> GetIngredients() { return Ingredients; }
    string GetName() { return RecipeName; }
    string GetDescription() { return RecipeDescription; }
    string GetProduct() { return ProductClassName; }
    int GetCraftTime() { return CraftTime; }
}