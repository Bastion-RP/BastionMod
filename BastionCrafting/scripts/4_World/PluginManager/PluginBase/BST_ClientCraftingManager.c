class BST_ClientCraftingManager : PluginBase {
    map<string, int> GetIngredientAmountFromArray(BST_CraftingRecipe recipe, array<EntityAI> arrEntities) {
        map<string, int> mapRequiredCount = GetBSTCraftingManager().GetRecipeIngredientRequirement(recipe);
        
        // This should be O(n) complexity
        // I'm not sure whether or not map.Set is O(n) complex or constant-time.
        foreach (EntityAI entity : arrEntities) {
            if (!entity) continue;
            string entityClassname = entity.GetType();

            entityClassname.ToLower();

            if (mapRequiredCount.Contains(entityClassname)) {
                int entityCount = QuantityConversions.GetItemQuantity(entity);

                if (entityCount == 0) entityCount = 1;
                mapRequiredCount.Set(entityClassname, mapRequiredCount.Get(entityClassname) - entityCount);
            }
        }
        return mapRequiredCount;
    }

    map<string, int> GetIngredientAmountOnPlayer(BST_CraftingRecipe recipe) {
        PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
        array<EntityAI> arrayInventory = new array<EntityAI>();

        if (!player) { return null; }
        player.GetInventory().EnumerateInventory(InventoryTraversalType.PREORDER, arrayInventory);

        return GetIngredientAmountFromArray(recipe, arrayInventory);
    }

    map<string, int> GetIngredientAmountInVicinityandPlayer(BST_CraftingRecipe recipe, array<EntityAI> arrayVicinityContainers) {
        array<EntityAI> arrayItems = new array<EntityAI>();
        PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());

        if (!player) { return null; }
        player.GetInventory().EnumerateInventory(InventoryTraversalType.PREORDER, arrayItems);

        // This has to be nested... I do believe. O(n^2) complex :(
        // Realistically arrays will be nice and small in dayz so this won't be a problem
        foreach (EntityAI container : arrayVicinityContainers) {
            if (container) {
                array<EntityAI> tempArray = new array<EntityAI>();

                container.GetInventory().EnumerateInventory(InventoryTraversalType.PREORDER, tempArray);

                // Idk how array.Copy works...
                foreach (EntityAI tempEntity : tempArray) {
                    if (tempEntity) {
                        arrayItems.Insert(tempEntity);
                    }
                }
            }
        }
        return GetIngredientAmountFromArray(recipe, arrayItems);
    }
}

BST_ClientCraftingManager GetBSTClientCraftingManager() {
    return BST_ClientCraftingManager.Cast(GetPlugin(BST_ClientCraftingManager));
}