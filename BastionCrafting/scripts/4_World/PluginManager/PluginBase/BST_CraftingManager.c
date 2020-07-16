class BST_CraftingManager : PluginBase {
    private ref BST_CraftingConfig config;
    private ref BST_CraftingBenchConfig configBenches;
    private ref BST_CraftingCategoryConfig _categoryConfig;
    private ref array<ref BST_CraftingLoadedRecipe> arrayCraftingRecipes;

    void BST_CraftingManager() {
        arrayCraftingRecipes = new array<ref BST_CraftingLoadedRecipe>();
    }

    void SetConfig(BST_CraftingConfig config) {
        this.config = config;
    }

    void SetBenchConfig(BST_CraftingBenchConfig configBenches) {
        this.configBenches = configBenches;
    }

    void SetCraftingRecipes(array<ref BST_CraftingLoadedRecipe> arrayCraftingRecipes) {
        this.arrayCraftingRecipes = arrayCraftingRecipes;
    }

    void SetCategoryConfig(BST_CraftingCategoryConfig categoryConfig) {
        this._categoryConfig = categoryConfig;
    }
    
    map<string, int> GetRecipeIngredientRequirement(BST_CraftingRecipe recipe) {
        map<string, int> mapIngredients = new map<string, int>();
        array<ref BST_CraftingIngredient> arrayIngredients = recipe.GetIngredients();

        foreach (BST_CraftingIngredient ingredient : arrayIngredients) {
            if (!ingredient) { continue; }
            string ingredientClassname = ingredient.GetClassname();
            int ingredientRequirement = ingredient.GetRequiredAmount();

            ingredientClassname.ToLower();

            if (mapIngredients.Contains(ingredientClassname)) {
                mapIngredients.Set(ingredientClassname, ingredient.GetRequiredAmount() + mapIngredients.Get(ingredientClassname));
            } else {
                mapIngredients.Insert(ingredientClassname, ingredientRequirement);
            }
        }
        return mapIngredients;
    }

    BST_CraftingBenchConfig GetBenchConfig() { return configBenches; }
    BST_CraftingConfig GetConfig() { return config; }
    BST_CraftingCategoryConfig GetCategoryConfig() { return _categoryConfig; }
    array<ref BST_CraftingLoadedRecipe> GetCraftingRecipes() { return arrayCraftingRecipes; }
}

BST_CraftingManager GetBSTCraftingManager() {
    return BST_CraftingManager.Cast(GetPlugin(BST_CraftingManager));
}