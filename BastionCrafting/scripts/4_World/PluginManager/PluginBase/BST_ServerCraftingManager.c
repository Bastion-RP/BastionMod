// How to handle categories for crafting.... fun fun
// Probably just make them configurable and then set them in the recipe file itself and this can handle the rest.
// Or no? Idk maybe do a map or some bullshit, load the config check the categories then load the recipes and place them
// into a map with their respective category? Would make building the UI easy. That would only need to be done on the client
// server doesn't have to give a shit about categories

class BST_ServerCraftingManager : PluginBase {
    private ref array<ref BST_CraftingLoadedRecipe> arrayCraftingRecipes;

    void BST_ServerCraftingManager() {
        arrayCraftingRecipes = new array<ref BST_CraftingLoadedRecipe>();

        if (!FileExist(BST_CraftingConst.rootDir)) {
            MakeDirectory(BST_CraftingConst.rootDir);
        }
        if (!FileExist(BST_CraftingConst.recipeDir)) {
            MakeDirectory(BST_CraftingConst.recipeDir);
        }
        LoadRecipes();
        //GenerateRandomRecipes();
    }

/*     private void GenerateRandomRecipes() {
        for (int i = 0; i < 200; i++) {
            map<string, int> mapRequiredItems = new map<string, int>();
            BST_CraftingRecipe newRecipe = new BST_CraftingRecipe();

            int item1 = Math.RandomInt(1, 100);
            int item2 = Math.RandomInt(1, 100);
            int item3 = Math.RandomInt(1, 100);
            int crafttime = Math.RandomInt(30, 5000);
            int fileName = Math.RandomInt(0, 999999999)

            mapRequiredItems.Insert("nail", item1);
            mapRequiredItems.Insert("shovel", item2);
            mapRequiredItems.Insert("ducttape", item3);
            newRecipe.SetRequiredItems(mapRequiredItems);
            newRecipe.SetRecipeInfo(crafttime);
            JsonFileLoader<BST_CraftingRecipe>.JsonSaveFile(BST_CraftingConst.recipeDir + "" + fileName + ".json", newRecipe);;
        }
    } */

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

                        if (foundRecipe.Validate()) {
                            arrayCraftingRecipes.Insert(foundRecipe);
                        }
                        JsonFileLoader<BST_CraftingRecipe>.JsonSaveFile(BST_CraftingConst.recipeDir + foundFileName, foundRecipe);
                    }
                }
            }
            arrayCraftingRecipes.Debug();
        }
    }

    private void CreateExampleRecipe() {
        map<string, int> mapRequiredItems = new map<string, int>();

        mapRequiredItems.Insert("nail", 50);
        mapRequiredItems.Insert("shovel", 1);
        mapRequiredItems.Insert("ducttape", 1);

        BST_CraftingRecipe newRecipe = new BST_CraftingRecipe(mapRequiredItems);

        JsonFileLoader<BST_CraftingRecipe>.JsonSaveFile(BST_CraftingConst.recipeDir + "ExampleRecipe.json", newRecipe);
    }

    void Craft(BST_CraftingRecipe recipe, PlayerBase player, ref array<EntityAI> arrayFoundItems) {
        map<string, int> mapIngredients = recipe.GetIngredients();

        for (int i = 0; i < mapIngredients.Count(); i++) {
            string className = mapIngredients.GetKey(i);
            int requiredAmount = mapIngredients.GetElement(i);
            int amountRemaining = requiredAmount;
            int removedAmount;

            for (int j = (arrayFoundItems.Count() - 1); j >= 0; j--) {
                EntityAI item = arrayFoundItems[j];

                if (item) {
                    string loweredTypeName = item.GetType();
                    loweredTypeName.ToLower();

                    if (className == loweredTypeName) {
                        arrayFoundItems.Remove(j);

                        int itemQuantity = QuantityConversions.GetItemQuantity(item);

                        if (itemQuantity > requiredAmount) {
                            SetItemQuantity(item, itemQuantity - requiredAmount);
                        } else {
                            GetGame().ObjectDelete(item);
                        }
                    }
                }
            }
        }
        player.GetHumanInventory().CreateInInventory(recipe.GetProduct());
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
        map<string, int> mapIngredients = recipe.GetIngredients();
        arrayFoundItems = new array<EntityAI>();

        player.GetInventory().EnumerateInventory(InventoryTraversalType.PREORDER, arrayInventoryItems);
        Print("[DEBUG] Checking map " + mapIngredients.Count());

        for (int i = 0; i < mapIngredients.Count(); i++) {
            string className = mapIngredients.GetKey(i);
            int requiredAmount = mapIngredients.GetElement(i);
            int itemAmount = 0;

            className.ToLower();
            Print("[DEBUG] Iterating through map " + className);

            for (int j = (arrayInventoryItems.Count() - 1); j >= 0; j--) {
                EntityAI item = arrayInventoryItems[j];

                Print("[DEBUG] Iterating item array " + item);

                if (item) {
                    string loweredTypeName = item.GetType();
                    loweredTypeName.ToLower();

                    Print("[DEBUG] Searching for class name=" + className + " | type name=" + loweredTypeName);
                    if (className == loweredTypeName) {
                        if (itemAmount >= requiredAmount) {
                            Print("[DEBUG] Item amount already met, breaking");
                            break;
                        }
                        Print("[DEBUG] Item found, adding to array");
                        arrayFoundItems.Insert(item);
                        arrayInventoryItems.Remove(j);

                        int itemQuant = QuantityConversions.GetItemQuantity(item);

                        if (itemQuant == 0) {
                            itemAmount += 1;
                        } else {
                            itemAmount += itemQuant;
                        }
                    }
                }
            }
            if (itemAmount < requiredAmount) {
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
}

BST_ServerCraftingManager GetServerCraftingManager() {
    return BST_ServerCraftingManager.Cast(GetPlugin(BST_ServerCraftingManager));
}