class BST_ClientCraftingManager : PluginBase {
    private ref BST_CraftingBenchConfig configBenches;
    private ref array<ref BST_CraftingLoadedRecipe> arrayCraftingRecipes;

    void BST_ClientCraftingManager() {
        arrayCraftingRecipes = new array<ref BST_CraftingLoadedRecipe>();
    }

    void SetCraftingRecipes(array<ref BST_CraftingLoadedRecipe> arrayCraftingRecipes) {
        this.arrayCraftingRecipes = arrayCraftingRecipes;
        arrayCraftingRecipes.Debug();
    }

    void SetBenchConfig(BST_CraftingBenchConfig configBenches) {
        this.configBenches = configBenches;

        Print("[DEBUG] CONFIG BENCHES..." + configBenches);
    }

    map<string, int> GetIngredientAmount(array<ref BST_CraftingIngredient> arrayIngredients) {
        array<EntityAI> arrayInventoryItems = new array<EntityAI>();
        map<string, int> mapIngredientAmount = new map<string, int>();

        if (!PlayerBase.Cast(GetGame().GetPlayer())) { return null; }

        PlayerBase.Cast(GetGame().GetPlayer()).GetInventory().EnumerateInventory(InventoryTraversalType.PREORDER, arrayInventoryItems);

        foreach (BST_CraftingIngredient ingredient : arrayIngredients) {
            Print("[DEBUG] BST_ClientCraftingManager | GetIngredientAmount | Iterating ingredient list " + ingredient + " | " + ingredient.GetClassname());
            if (!ingredient) { continue; }
            int totalItemCount = 0;

            for (int i = (arrayInventoryItems.Count() - 1); i >= 0; i--) {
                EntityAI entity = arrayInventoryItems[i];

                if (!entity) { continue; }
                string itemType = entity.GetType();

                itemType.ToLower();

                if (itemType == ingredient.GetLoweredClassname()) {
                    int itemCount = QuantityConversions.GetItemQuantity(entity);

                    if (itemCount == 0) {
                        totalItemCount += 1;
                    } else {
                        totalItemCount += itemCount;
                    }
                }
            }
            mapIngredientAmount.Insert(ingredient.GetClassname(), totalItemCount);
        }
        return mapIngredientAmount;
    }

    array<ref BST_CraftingLoadedRecipe> GetRecipes() { return arrayCraftingRecipes; }
    BST_CraftingBenchConfig GetBenchConfig() { return configBenches; }
}
BST_ClientCraftingManager GetClientCraftingManager() {
    return BST_ClientCraftingManager.Cast(GetPlugin(BST_ClientCraftingManager));
}