class BST_CraftingRecipe {
    private static const string DEFAULT_RECIPE_STRING = "CHANGE ME";
    private static const int DEFAULT_CRAFT_TIME = 60;

    private ref array<ref BST_CraftingIngredient> Ingredients;
    private ref array<ref BST_CraftingProduct> Products;
    private string RecipeName, RecipeDescription, RequiredCraftingBench;
    private int CraftTime, SubCategoryID;

    void BST_CraftingRecipe(array<ref BST_CraftingIngredient> Ingredients) {
        this.Ingredients = Ingredients;
        this.Products = new array<ref BST_CraftingProduct>();
        this.RecipeName = DEFAULT_RECIPE_STRING;
        this.RecipeDescription = DEFAULT_RECIPE_STRING;
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
        if (Products.Count() <= 0) {
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
    array<ref BST_CraftingProduct> GetProducts() { return Products; }
    string GetName() { return RecipeName; }
    string GetDescription() { return RecipeDescription; }
    int GetCraftTime() { return CraftTime; }
    int GetCategoryId() { return SubCategoryID; }
}