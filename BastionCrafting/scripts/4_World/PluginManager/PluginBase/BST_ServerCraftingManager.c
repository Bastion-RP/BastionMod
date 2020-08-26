class BST_ServerCraftingManager : PluginBase {
    private static const string CONST_FURNACE_CONFIG_DIR = BST_CraftingConst.rootDir + "FurnaceConfig.json";
    private static const string CONST_CRAFTING_CONFIG_DIR = BST_CraftingConst.rootDir + "Config.json";
    private static const string CONST_CRAFTING_BENCH_CONFIG_DIR = BST_CraftingConst.rootDir + "BenchConfig.json";
    private static const string CONST_CRAFTING_CATEGORY_CONFIG_DIR = BST_CraftingConst.rootDir + "CategoryConfig.json";

    private ref BST_FurnaceConfig cfgFurnace;
    private ref map<string, ref BST_FurnaceRecipe> mapFurnaceRecipes;
    private ref map<string, ref BST_FurnaceFuel> mapFurnaceFuels;

    void BST_ServerCraftingManager() {
        mapFurnaceRecipes = new map<string, ref BST_FurnaceRecipe>();
        mapFurnaceFuels = new map<string, ref BST_FurnaceFuel>();

        if (!FileExist(BST_CraftingConst.rootDir)) {
            MakeDirectory(BST_CraftingConst.rootDir);
        }
        if (!FileExist(BST_CraftingConst.recipeDir)) {
            MakeDirectory(BST_CraftingConst.recipeDir);
        }
        if (!FileExist(BST_CraftingConst.furnaceDir)) {
            MakeDirectory(BST_CraftingConst.furnaceDir);
        }
        if (!FileExist(BST_CraftingConst.furnaceFuelDir)) {
            MakeDirectory(BST_CraftingConst.furnaceFuelDir);
        }
        LoadConfig();
        LoadRecipes();
        LoadCategories();
        LoadFurnaceConfig();
        LoadFurnaceRecipes();
        LoadFurnaceFuels();
    }

    private void LoadConfig() {
        BST_CraftingConfig config;
        BST_CraftingBenchConfig benchConfig;

        if (!FileExist(CONST_CRAFTING_BENCH_CONFIG_DIR)) {
            GetBSTCraftingManager().SetBenchConfig(new BST_CraftingBenchConfig());
        } else {
            JsonFileLoader<BST_CraftingBenchConfig>.JsonLoadFile(CONST_CRAFTING_BENCH_CONFIG_DIR, benchConfig);
            benchConfig.Validate();
            GetBSTCraftingManager().SetBenchConfig(benchConfig);
        }
        if (!FileExist(CONST_CRAFTING_CONFIG_DIR)) {
            GetBSTCraftingManager().SetConfig(new BST_CraftingConfig());
        } else {
            JsonFileLoader<BST_CraftingConfig>.JsonLoadFile(CONST_CRAFTING_CONFIG_DIR, config);
            config.Validate();
            GetBSTCraftingManager().SetConfig(config);
        }
        JsonFileLoader<BST_CraftingConfig>.JsonSaveFile(CONST_CRAFTING_CONFIG_DIR, GetBSTCraftingManager().GetConfig());
        JsonFileLoader<BST_CraftingBenchConfig>.JsonSaveFile(CONST_CRAFTING_BENCH_CONFIG_DIR, GetBSTCraftingManager().GetBenchConfig());
    }

    private void LoadFurnaceConfig() {
        if (!FileExist(CONST_FURNACE_CONFIG_DIR)) {
            cfgFurnace = new BST_FurnaceConfig();
        } else {
            JsonFileLoader<BST_FurnaceConfig>.JsonLoadFile(CONST_FURNACE_CONFIG_DIR, cfgFurnace);
            cfgFurnace.Validate();
        }
        JsonFileLoader<BST_FurnaceConfig>.JsonSaveFile(CONST_FURNACE_CONFIG_DIR, cfgFurnace);
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
            array<ref BST_CraftingLoadedRecipe> arrayCraftingRecipes = new array<ref BST_CraftingLoadedRecipe>();

            foreach (string foundFileName : arrayFileNames) {
                if (foundFileName != string.Empty) {
                    BST_CraftingLoadedRecipe foundRecipe;

                    JsonFileLoader<BST_CraftingLoadedRecipe>.JsonLoadFile(BST_CraftingConst.recipeDir + foundFileName, foundRecipe);

                    if (foundRecipe) {
                        foundRecipe.SetFileName(foundFileName);

                        if (foundRecipe.Validate()) {
                            arrayCraftingRecipes.Insert(foundRecipe);
                        }
                        JsonFileLoader<BST_CraftingRecipe>.JsonSaveFile(BST_CraftingConst.recipeDir + foundFileName, foundRecipe);
                    }
                }
            }
            GetBSTCraftingManager().SetCraftingRecipes(arrayCraftingRecipes);
        }
    }

    private void LoadCategories() {
        BST_CraftingCategoryConfig categoryConfig;

        if (!FileExist(CONST_CRAFTING_CATEGORY_CONFIG_DIR)) {
            categoryConfig = new BST_CraftingCategoryConfig();
        } else {
            JsonFileLoader<BST_CraftingCategoryConfig>.JsonLoadFile(CONST_CRAFTING_CATEGORY_CONFIG_DIR, categoryConfig);
        }
        JsonFileLoader<BST_CraftingCategoryConfig>.JsonSaveFile(CONST_CRAFTING_CATEGORY_CONFIG_DIR, categoryConfig);
        GetBSTCraftingManager().SetCategoryConfig(categoryConfig);
    }

    private void LoadFurnaceRecipes() {
        array<string> arrayFileNames;
        FindFileHandle fileHandler;
        string filePattern;
        string fileName;
        int fileAttr, flags;

        arrayFileNames = new array<string>();
        filePattern = BST_CraftingConst.furnaceDir + "*.json";
        fileHandler = FindFile(filePattern, fileName, fileAttr, flags);

        if (fileName != string.Empty) {
            arrayFileNames.Insert(fileName);
        }
        while (FindNextFile(fileHandler, fileName, fileAttr)) {
            arrayFileNames.Insert(fileName);
        }
        if (arrayFileNames.Count() == 0) {;
            JsonFileLoader<BST_FurnaceRecipe>.JsonSaveFile(BST_CraftingConst.furnaceDir + "ExampleRecipe.json", new BST_FurnaceRecipe());
        } else {
            foreach (string foundFileName : arrayFileNames) {
                if (foundFileName != string.Empty) {
                    BST_FurnaceRecipe foundRecipe;

                    JsonFileLoader<BST_FurnaceRecipe>.JsonLoadFile(BST_CraftingConst.furnaceDir + foundFileName, foundRecipe);

                    if (foundRecipe) {
                        if (foundRecipe.Validate()) {
                            mapFurnaceRecipes.Insert(foundRecipe.GetLoweredType(), foundRecipe);
                        }
                        JsonFileLoader<BST_FurnaceRecipe>.JsonSaveFile(BST_CraftingConst.furnaceDir + foundFileName, foundRecipe);
                    }
                }
            }
        }
    }

    private void LoadFurnaceFuels() {
        array<string> arrayFileNames;
        FindFileHandle fileHandler;
        string filePattern;
        string fileName;
        int fileAttr, flags;

        arrayFileNames = new array<string>();
        filePattern = BST_CraftingConst.furnaceFuelDir + "*.json";
        fileHandler = FindFile(filePattern, fileName, fileAttr, flags);

        if (fileName != string.Empty) {
            arrayFileNames.Insert(fileName);
        }
        while (FindNextFile(fileHandler, fileName, fileAttr)) {
            arrayFileNames.Insert(fileName);
        }
        if (arrayFileNames.Count() == 0) {;
            JsonFileLoader<BST_FurnaceFuel>.JsonSaveFile(BST_CraftingConst.furnaceFuelDir + "ExampleFuel.json", new BST_FurnaceFuel());
        } else {
            foreach (string foundFileName : arrayFileNames) {
                if (foundFileName != string.Empty) {
                    BST_FurnaceFuel foundFuel;

                    JsonFileLoader<BST_FurnaceFuel>.JsonLoadFile(BST_CraftingConst.furnaceFuelDir + foundFileName, foundFuel);

                    if (foundFuel) {
                        foundFuel.Validate();
                        mapFurnaceFuels.Insert(foundFuel.GetLoweredType(), foundFuel);
                        JsonFileLoader<BST_FurnaceFuel>.JsonSaveFile(BST_CraftingConst.furnaceFuelDir + foundFileName, foundFuel);
                    }
                }
            }
        }
    }

    private void CreateExampleRecipe() {
        array<ref BST_CraftingIngredient> arrayIngredients = new array<ref BST_CraftingIngredient>();
        
        arrayIngredients.Insert(new BST_CraftingIngredient("nail", 50));
        arrayIngredients.Insert(new BST_CraftingIngredient("shovel", 1));
        arrayIngredients.Insert(new BST_CraftingIngredient("ducttape", 1));

        BST_CraftingRecipe newRecipe = new BST_CraftingRecipe(arrayIngredients);

        JsonFileLoader<BST_CraftingRecipe>.JsonSaveFile(BST_CraftingConst.recipeDir + "ExampleRecipe.json", newRecipe);
    }

    void Craft(PlayerBase player, BST_CraftingRecipe recipe, ref array<EntityAI> arrayFoundItems) {
        // These loops need to be readdressed and set to be O(n) instead of their current O(n^2) time complexity
        
        array<ref BST_CraftingIngredient> arrayIngredients = recipe.GetIngredients();
        int i;

        foreach (BST_CraftingIngredient ingredient : arrayIngredients) {
            if (!ingredient) { continue; }
            for (i = (arrayFoundItems.Count() - 1); i >= 0; i--) {
                EntityAI item = arrayFoundItems[i];

                if (item) {
                    string loweredTypeName = item.GetType();
                    loweredTypeName.ToLower();

                    if (loweredTypeName == ingredient.GetLoweredClassname()) {
                        arrayFoundItems.Remove(i);

                        if (!ingredient.IsConsumable()) { continue; }
                        string minDestroyPath = CFG_VEHICLESPATH + " " + loweredTypeName + " varQuantityDestroyOnMin";
                        int itemQuantity = QuantityConversions.GetItemQuantity(item);
                        
                        if (GetGame().ConfigIsExisting(minDestroyPath) && GetGame().ConfigGetInt(minDestroyPath) == 0 && ingredient.GetRequiredAmount() == -1) {
                            GetGame().ObjectDelete(item);
                        } else {
                            if (itemQuantity > ingredient.GetRequiredAmount()) {
                                SetItemQuantity(item, itemQuantity - ingredient.GetRequiredAmount());
                            } else {
                                GetGame().ObjectDelete(item);
                            }
                        }
                    }
                }
            }
        }
        array<ref BST_CraftingProduct> arrProducts = recipe.GetProducts();

        foreach (BST_CraftingProduct product : arrProducts) {
            EntityAI entityCrafted;
            string productClassname, maxCountPath, ammoMaxCountPath, itemMaxCountPath;
            int itemMaxCount, loopIterations, amountCreated;

            productClassname = product.GetClassname();
            ammoMaxCountPath = CFG_MAGAZINESPATH + " " + productClassname + " count";
            itemMaxCountPath = CFG_VEHICLESPATH + " " + productClassname + " varQuantityMax";
            amountCreated = 0;

            if (GetGame().ConfigIsExisting(ammoMaxCountPath)) {
                itemMaxCount = GetGame().ConfigGetInt(ammoMaxCountPath);
            } else if (GetGame().ConfigIsExisting(itemMaxCountPath)) {
                itemMaxCount = GetGame().ConfigGetInt(itemMaxCountPath);
            } else {
                itemMaxCount = 1;
            }
            loopIterations = Math.Ceil(product.GetRequiredAmount() / itemMaxCount);

            for (i = 0; i < loopIterations; i++) {
                entityCrafted = player.GetHumanInventory().CreateInInventory(productClassname);

                if (!entityCrafted) {
                    entityCrafted = GetGame().CreateObject(productClassname, player.GetPosition());

                    entityCrafted.PlaceOnSurface();
                }
                if ((loopIterations - 1) != i) {
                    amountCreated += itemMaxCount;
                    
                    SetItemQuantity(entityCrafted, itemMaxCount);
                } else {
                    SetItemQuantity(entityCrafted, (product.GetRequiredAmount() - amountCreated));
                }
            }
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
        array<ref BST_CraftingLoadedRecipe> arrayCraftingRecipes = GetBSTCraftingManager().GetCraftingRecipes();

        foreach (BST_CraftingLoadedRecipe foundRecipe : arrayCraftingRecipes) {
            if (foundRecipe && foundRecipe.GetFileName() == fileName) {
                return foundRecipe;
            }
        }
        return null;
    }

    map<string, int> GetIngredientAmountAndPurgeArray(BST_CraftingRecipe recipe, array<EntityAI> arrItems, out array<EntityAI> outArrItems) {
        map<string, int> mapRequiredIngredients = GetBSTCraftingManager().GetRecipeIngredientRequirement(recipe);
        
        for (int i = (arrItems.Count() - 1); i >= 0; i--) {
            EntityAI entity = arrItems[i];
            string entType = entity.GetType();

            entType.ToLower();

            if (mapRequiredIngredients.Contains(entType)) {
                int entCount = QuantityConversions.GetItemQuantity(entity);

                if (entCount == 0) entCount = 1;
                mapRequiredIngredients.Set(entType, mapRequiredIngredients.Get(entType) - entCount);
            } else {
                arrItems.Remove(i);
            }
        }
        outArrItems = arrItems;
        
        return mapRequiredIngredients;
    }

    bool MapContainsRequiredIngredients(BST_CraftingRecipe recipe, map<string, int> mapRequiredIngredients) {
        array<ref BST_CraftingIngredient> arrRecipeIngredients = recipe.GetIngredients();
        
        // Loop over ingredient map. Don't loop over map directly because getting a get or element in a 
        // map is O(n) complex so using that inside of a map makes it O(n^2) complex.
        // Instead loop over required ingredient array and get the values from the map, making the entire
        // loop O(n) complex.
        foreach (BST_CraftingIngredient ingredient : arrRecipeIngredients) {
            if (!ingredient) { continue; }
            string ingredientType = ingredient.GetLoweredClassname();
            
            if (mapRequiredIngredients.Contains(ingredientType)) {
                if (mapRequiredIngredients.Get(ingredientType) > 0) {
                    return false;
                }
            }
        }
        return true;
    }

    bool HasIngredientsOnPerson(PlayerBase player, BST_CraftingRecipe recipe, out array<EntityAI> arrItems) {
        if (!player || !recipe) { return false; }
        arrItems = new array<EntityAI>();

        player.GetInventory().EnumerateInventory(InventoryTraversalType.PREORDER, arrItems);
        map<string, int> mapRequiredIngredients = GetIngredientAmountAndPurgeArray(recipe, arrItems, arrItems);

        return MapContainsRequiredIngredients(recipe, mapRequiredIngredients);
    }

    bool HasIngredientsInVicinityAndPerson(PlayerBase player, BST_CraftingRecipe recipe, out array<EntityAI> arrItems) {
        if (!player || !recipe) { return false; }
        array<EntityAI> arrContainers = GetBSTVicinityItemManager().RefreshVicinityItems(player);
        arrItems = new array<EntityAI>();

        player.GetInventory().EnumerateInventory(InventoryTraversalType.PREORDER, arrItems);

        // Now to grab items in vicinity.
        // I believe this has to be O(n^2) complex. Not ideal, but shouldn't be problematic
        foreach (EntityAI container : arrContainers) {
            if (container) {
                array<EntityAI> arrTemp = new array<EntityAI>();

                container.GetInventory().EnumerateInventory(InventoryTraversalType.PREORDER, arrTemp);

                foreach (EntityAI entTemp : arrTemp) {
                    if (entTemp) {
                        arrItems.Insert(entTemp);
                    }
                }
                delete arrTemp;
            }
        }
        map<string, int> mapRequiredIngredients = GetIngredientAmountAndPurgeArray(recipe, arrItems, arrItems);

        return MapContainsRequiredIngredients(recipe, mapRequiredIngredients);
    }

    map<string, ref BST_FurnaceRecipe> GetFurnaceRecipes() { return mapFurnaceRecipes; }
    map<string, ref BST_FurnaceFuel> GetFuelsMap() { return mapFurnaceFuels; }
    BST_FurnaceConfig GetFurnaceConfig() { return cfgFurnace; }
}

BST_ServerCraftingManager GetBSTServerCraftingManager() {
    return BST_ServerCraftingManager.Cast(GetPlugin(BST_ServerCraftingManager));
}