class BST_CraftingRecipe {
    private static const string DEFAULT_RECIPE_STRING = "CHANGE ME";
    private static const int DEFAULT_CRAFT_TIME = 60;

    private ref map<string, int> Ingredients;
    private string RecipeName, RecipeDescription, ProductClassName;
    private int CraftTime;

    void BST_CraftingRecipe(map<string, int> Ingredients) {
        this.Ingredients = Ingredients;
        this.RecipeName = DEFAULT_RECIPE_STRING;
        this.RecipeDescription = DEFAULT_RECIPE_STRING;
        this.ProductClassName = DEFAULT_RECIPE_STRING;
        this.CraftTime = DEFAULT_CRAFT_TIME;
    }

    void SetRequiredItems(map<string, int> Ingredients) {
        if (GetGame().IsServer() && GetGame().IsMultiplayer()) {
            this.Ingredients = Ingredients;
        }
    }

    // Remove this later, using only for testing
    void SetRecipeInfo(int CraftTime) {
        this.CraftTime = CraftTime;
        Validate();
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

    map<string, int> GetIngredients() { return Ingredients; }
    string GetName() { return RecipeName; }
    string GetDescription() { return RecipeDescription; }
    string GetProduct() { return ProductClassName; }
    int GetCraftTime() { return CraftTime; }
}