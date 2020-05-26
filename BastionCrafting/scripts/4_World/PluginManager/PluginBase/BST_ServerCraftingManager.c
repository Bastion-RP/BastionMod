// How to handle categories for crafting.... fun fun
// Probably just make them configurable and then set them in the recipe file itself and this can handle the rest.
// Or no? Idk maybe do a map or some bullshit, load the config check the categories then load the recipes and place them
// into a map with their respective category? Would make building the UI easy. That would only need to be done on the client
// server doesn't have to give a shit about categories

class BST_ServerCraftingManager : PluginBase {
    private static const string CONST_CRAFTING_BENCH_CONFIG_DIR = BST_CraftingConst.rootDir + "BenchConfig.json";

    private ref array<ref BST_CraftingLoadedRecipe> arrayCraftingRecipes;
    private ref BST_CraftingBenchConfig configBenches;

    void BST_ServerCraftingManager() {
        arrayCraftingRecipes = new array<ref BST_CraftingLoadedRecipe>();

        if (!FileExist(BST_CraftingConst.rootDir)) {
            MakeDirectory(BST_CraftingConst.rootDir);
        }
        if (!FileExist(BST_CraftingConst.recipeDir)) {
            MakeDirectory(BST_CraftingConst.recipeDir);
        }
        LoadConfig();
        LoadRecipes();
        //GenerateRandomRecipes();
    }

    /* private void GenerateRandomRecipes() {
        for (int i = 0; i < 200; i++) {
            int item1 = Math.RandomInt(1, 100);
            int item2 = Math.RandomInt(1, 100);
            int item3 = Math.RandomInt(1, 100);
            int crafttime = Math.RandomInt(30, 5000);
            int fileName = Math.RandomInt(0, 999999999);

            array<ref BST_CraftingIngredient> arrayIngredients = new array<ref BST_CraftingIngredient>();
            
            arrayIngredients.Insert(new BST_CraftingIngredient("nail", 50, true));
            arrayIngredients.Insert(new BST_CraftingIngredient("shovel", 1, true));
            arrayIngredients.Insert(new BST_CraftingIngredient("ducttape", 1, false));

            BST_CraftingRecipe newRecipe = new BST_CraftingRecipe(arrayIngredients);

            newRecipe.SetRecipeInfo(crafttime);
            JsonFileLoader<BST_CraftingRecipe>.JsonSaveFile(BST_CraftingConst.recipeDir + "" + fileName + ".json", newRecipe);;
        }
    } */

    private void LoadConfig() {
        if (!FileExist(CONST_CRAFTING_BENCH_CONFIG_DIR)) {
            configBenches = new BST_CraftingBenchConfig();
        } else {
            JsonFileLoader<BST_CraftingBenchConfig>.JsonLoadFile(CONST_CRAFTING_BENCH_CONFIG_DIR, configBenches);
        }
        JsonFileLoader<BST_CraftingBenchConfig>.JsonSaveFile(CONST_CRAFTING_BENCH_CONFIG_DIR, configBenches);
    }

    private void LoadRecipes() {
        array<string> arrayFileNames;
        FindFileHandle fileHandler;
        string filePattern;
        string fileName;
        int fileAttr, flags;

        arrayFileNames = new array<string>();
        filePattern = BST_CraftingConst.recipeDir + "*.json";
        fileHandler = FindFile(filePattern, fileName, fileAttr, flags);

        if (fileName != string.Empty) {
            arrayFileNames.Insert(fileName);
        }
        while (FindNextFile(fileHandler, fileName, fileAttr)) {
            arrayFileNames.Insert(fileName);
        }
        if (arrayFileNames.Count() == 0) {
            CreateExampleRecipe();
        } else {
            foreach (string foundFileName : arrayFileNames) {
                if (foundFileName != string.Empty) {
                    BST_CraftingLoadedRecipe foundRecipe;

                    JsonFileLoader<BST_CraftingLoadedRecipe>.JsonLoadFile(BST_CraftingConst.recipeDir + foundFileName, foundRecipe);
                    Print("[DEBUG] Found file name=" + foundFileName);

                    if (foundRecipe) {
                        foundRecipe.SetFileName(foundFileName);

                        //if (foundRecipe.Validate()) {
                            arrayCraftingRecipes.Insert(foundRecipe);
                        //}
                        JsonFileLoader<BST_CraftingRecipe>.JsonSaveFile(BST_CraftingConst.recipeDir + foundFileName, foundRecipe);
                    }
                }
            }
            arrayCraftingRecipes.Debug();
        }
    }

    private void CreateExampleRecipe() {
        array<ref BST_CraftingIngredient> arrayIngredients = new array<ref BST_CraftingIngredient>();
        
        arrayIngredients.Insert(new BST_CraftingIngredient("nail", 50, true));
        arrayIngredients.Insert(new BST_CraftingIngredient("shovel", 1, true));
        arrayIngredients.Insert(new BST_CraftingIngredient("ducttape", 1, false));

        BST_CraftingRecipe newRecipe = new BST_CraftingRecipe(arrayIngredients);

        JsonFileLoader<BST_CraftingRecipe>.JsonSaveFile(BST_CraftingConst.recipeDir + "ExampleRecipe.json", newRecipe);
    }

    void Craft(BST_CraftingRecipe recipe, PlayerBase player, ref array<EntityAI> arrayFoundItems) {
        array<ref BST_CraftingIngredient> arrayIngredients = recipe.GetIngredients();

        foreach (BST_CraftingIngredient ingredient : arrayIngredients) {
            if (!ingredient) { continue; }
            int amountRemaining = ingredient.GetRequiredAmount();
            int removedAmount = 0;

            for (int i = (arrayFoundItems.Count() - 1); i >= 0; i--) {
                EntityAI item = arrayFoundItems[i];

                if (item) {
                    string loweredTypeName = item.GetType();
                    loweredTypeName.ToLower();

                    if (loweredTypeName == ingredient.GetLoweredClassname()) {
                        arrayFoundItems.Remove(i);

                        if (!ingredient.IsConsumable()) { continue; }
                        int itemQuantity = QuantityConversions.GetItemQuantity(item);

                        if (itemQuantity > ingredient.GetRequiredAmount()) {
                            SetItemQuantity(item, itemQuantity - ingredient.GetRequiredAmount());
                        } else {
                            GetGame().ObjectDelete(item);
                        }
                    }
                }
            }
        }
        EntityAI entityCrafted = player.GetHumanInventory().CreateInInventory(recipe.GetProduct());

        if (!entityCrafted) {
            entityCrafted = GetGame().CreateObject(recipe.GetProduct(), player.GetPosition());

            entityCrafted.PlaceOnSurface();
        }
        delete arrayFoundItems;
    }

    void SetItemQuantity(ItemBase item, int quantity) {
        Magazine magItem = Magazine.Cast(item);

        if (magItem) {
            magItem.ServerSetAmmoCount(quantity);
        } else {
            item.SetQuantity(quantity);
        }
    }

    BST_CraftingLoadedRecipe FindRecipeByFileName(string fileName) {
        foreach (BST_CraftingLoadedRecipe foundRecipe : arrayCraftingRecipes) {
            if (foundRecipe && foundRecipe.GetFileName() == fileName) {
                return foundRecipe;
            }
        }
        return null;
    }
    
    bool HasIngredients(BST_CraftingRecipe recipe, PlayerBase player, out ref array<EntityAI> arrayFoundItems) {
        array<EntityAI> arrayInventoryItems = new array<EntityAI>();
        array<ref BST_CraftingIngredient> arrayIngredients = recipe.GetIngredients();
        arrayFoundItems = new array<EntityAI>();

        player.GetInventory().EnumerateInventory(InventoryTraversalType.PREORDER, arrayInventoryItems);
        Print("[DEBUG] Checking ingredient array " + arrayIngredients.Count());

        foreach (BST_CraftingIngredient ingredient : arrayIngredients) {
            if (!ingredient) { continue; }
            int itemAmount = 0;

            for (int i = (arrayInventoryItems.Count() - 1); i >= 0; i--) {
                EntityAI item = arrayInventoryItems[i];

                Print("[DEBUG] Iterating item array " + item);

                if (item) {
                    string loweredTypeName = item.GetType();
                    loweredTypeName.ToLower();

                    Print("[DEBUG] Searching for class name=" + ingredient.GetLoweredClassname() + " | type name=" + loweredTypeName);
                    if (loweredTypeName == ingredient.GetLoweredClassname()) {
                        if (itemAmount >= ingredient.GetRequiredAmount()) {
                            Print("[DEBUG] Item amount already met, breaking");
                            break;
                        }
                        Print("[DEBUG] Item found, adding to array");
                        arrayFoundItems.Insert(item);
                        arrayInventoryItems.Remove(i);

                        int itemQuant = QuantityConversions.GetItemQuantity(item);

                        if (itemQuant == 0) {
                            itemAmount += 1;
                        } else {
                            itemAmount += itemQuant;
                        }
                    }
                }
            }
            if (itemAmount < ingredient.GetRequiredAmount()) {
                Print("[DEBUG] Required item amount not found, exiting");
                return false;
            }
        }
        if (arrayFoundItems.Count() > 0) {
            return true;
        }
        return false;
    }

    ref array<ref BST_CraftingLoadedRecipe> GetCraftingRecipes() { return arrayCraftingRecipes; }
    ref BST_CraftingBenchConfig GetBenchConfig() { return configBenches; }
}

BST_ServerCraftingManager GetServerCraftingManager() {
    return BST_ServerCraftingManager.Cast(GetPlugin(BST_ServerCraftingManager));
}