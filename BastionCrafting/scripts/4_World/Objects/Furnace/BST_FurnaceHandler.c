class BST_FurnaceHandler {
    private ItemBase parent;
    private bool isSmelting;

    void BST_FurnaceHandler(ItemBase parent) {
        this.parent = parent;
    }

    void ~BST_FurnaceHandler() {
        StopSmelting();
    }

    void StartSmelting() {
        if (isSmelting) { return; }
        Print("[DEBUG] Starting smelting!!!")
        isSmelting = true;
        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(this.Smelt, GetBSTServerCraftingManager().GetFurnaceConfig().GetTickRate() * 1000, true);
    }

    void StopSmelting() {
        Print("[DEBUG] Stopping smelting!!!")
        isSmelting = false;
        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Remove(this.Smelt);
    }

    void Smelt() {
        if (!parent || !parent.GetInventory()) {
            delete this;
            return;
        }
        array<EntityAI> arrCargo = new array<EntityAI>();
        map<string, int> mapBiProductsAmount = new map<string, int>();
        map<string, ref BST_FurnaceFuel> mapFuelTypes = GetBSTServerCraftingManager().GetFuelsMap();
        map<string, ref BST_FurnaceRecipe> mapRecipes = GetBSTServerCraftingManager().GetFurnaceRecipes();
        array<ref BST_FurnaceBiProduct> arrBiProducts;
        ItemBase item;
        string itemType;
        float fuelMultiplier;
        int itemQuant, fuelRemoved;
        bool foundFuel = false;

        parent.GetInventory().EnumerateInventory(InventoryTraversalType.PREORDER, arrCargo);

        Print("[DEBUG] Finding fuel!")
        for (int i = 0; i < arrCargo.Count(); i++) {
            item = ItemBase.Cast(arrCargo[i]);

            if (item) {
                itemType = item.GetType();

                itemType.ToLower();

                if (mapFuelTypes.Contains(itemType)) {
                    BST_FurnaceFuel fuel = mapFuelTypes.Get(itemType);
                    itemQuant = QuantityConversions.GetItemQuantity(item);
                    fuelMultiplier = fuel.GetMultiplier();

                    if (itemQuant > fuel.GetConsumptionRate()) {
                        fuelRemoved = fuel.GetConsumptionRate();

                        GetBSTServerCraftingManager().SetItemQuantity(item, itemQuant - fuel.GetConsumptionRate());
                    } else {
                        fuelRemoved = itemQuant;

                        GetGame().ObjectDelete(item);
                    }
                    arrBiProducts = fuel.GetBiProducts();
                    foundFuel = true;

                    Print("[DEBUG] Fuel removed=" + fuelRemoved + " | fuel consumption rate=" + fuel.GetConsumptionRate());

                    arrCargo.Remove(i);
                    break;
                }
            }
        }
        if (!foundFuel || !arrBiProducts) {
            StopSmelting();
            return;
        }
        Print("[DEBUG] Fuel found, getting bi product map! arr count=" + arrBiProducts.Count());
        mapBiProductsAmount = GetBiProductMap(mapBiProductsAmount, arrBiProducts, fuelRemoved);

        foreach (BST_FurnaceBiProduct biProduct : arrBiProducts) {
            Print("[DEBUG] bi product type= " + biProduct.GetLoweredType());
        }

        Print("[DEBUG] Searching for recipes to add bi products!")
        foreach (EntityAI ent : arrCargo) {
            if (!ent) { continue; }
            item = ItemBase.Cast(ent);

            if (item) {
                itemType = item.GetType();

                itemType.ToLower();

                if (mapRecipes.Contains(itemType)) {
                    Print("[DEBUG] foreach (EntityAI ent : arrCargo) | map contains item type=" + itemType);

                    BST_FurnaceRecipe recipe = mapRecipes.Get(itemType);
                    array<ref BST_FurnaceBiProduct> arrRecipeBiProduct = recipe.GetBiProducts();
                    int smeltRate = fuelRemoved * recipe.GetSmeltRate() * fuelMultiplier;

                    itemQuant = QuantityConversions.GetItemQuantity(item);
                    Print("[DEBUG] foreach (EntityAI ent : arrCargo) | smelt rate=" + smeltRate);

                    if (itemQuant > smeltRate) {
                        Print("[DEBUG] foreach (EntityAI ent : arrCargo) | lowering item quant=" + itemQuant + " | smelt rate=" + smeltRate);
                        GetBSTServerCraftingManager().SetItemQuantity(item, itemQuant - smeltRate);
                    } else {
                        smeltRate = fuelRemoved * itemQuant * fuelMultiplier;
                        Print("[DEBUG] foreach (EntityAI ent : arrCargo) | deleting item=" + itemQuant + " | smelt rate=" + smeltRate);

                        GetGame().ObjectDelete(item);
                    }
                    mapBiProductsAmount = GetBiProductMap(mapBiProductsAmount, arrRecipeBiProduct, smeltRate);
                }
            }
        }
        Print("[DEBUG] Spawning objects!")
        Print("[DEBUG] Filling pre-existing objects before spawning new ones!")
        // Now handle the spawning of the new object. First, check to see if the bi products are already present
        foreach (EntityAI entity : arrCargo) {
            if (!entity) { continue; }
            item = ItemBase.Cast(entity);

            if (item) {
                itemType = item.GetType();

                itemType.ToLower();

                if (mapBiProductsAmount.Contains(itemType)) {
                    Print("[DEBUG] foreach (EntityAI entity : arrCargo) | Object found in map, filling!")
                    int quantNeeded = mapBiProductsAmount.Get(itemType);
                    int itemMaxQuant = item.ConfigGetInt("varQuantityMax");
                    itemQuant = QuantityConversions.GetItemQuantity(item);
                    int quantDifference = itemMaxQuant - itemQuant;

                    if (itemQuant == itemMaxQuant) { continue; }
                    if (quantNeeded > quantDifference) {
                        GetBSTServerCraftingManager().SetItemQuantity(item, itemMaxQuant);
                        mapBiProductsAmount.Set(itemType, quantNeeded - quantDifference);
                    } else {
                        GetBSTServerCraftingManager().SetItemQuantity(item, itemQuant + quantNeeded);
                        mapBiProductsAmount.Remove(itemType);
                    }
                }
            }
        }
        Print("[DEBUG] Spawning new objects! map count=" + mapBiProductsAmount.Count());
        for (int j = 0; j < mapBiProductsAmount.Count(); j++) {
            itemType = mapBiProductsAmount.GetKey(j);

            SpawnObjectByType(itemType, mapBiProductsAmount.Get(itemType));
        }
    }

    void SpawnObjectByType(string itemType, int itemQuant) {
        Print("[DEBUG] Spawning new object! item type=" + itemType + " | quant=" + itemQuant);
        InventoryLocation il = new InventoryLocation();

        if (parent.GetInventory().FindFirstFreeLocationForNewEntity(itemType, FindInventoryLocationType.ANY, il)) {
            ItemBase item = il.GetParent().GetInventory().CreateEntityInCargoEx(itemType, il.GetIdx(), il.GetRow(), il.GetCol(), il.GetFlip());
            Print("[DEBUG] Found inventory spot, spawning object!")

            if (item) {
                int itemMaxQuant = item.ConfigGetInt("varQuantityMax");
                
                if (itemQuant <= itemMaxQuant) {
                    Print("[DEBUG] Function call to SpawnObjectByType!")
                    GetBSTServerCraftingManager().SetItemQuantity(item, itemQuant);
                } else {
                    GetBSTServerCraftingManager().SetItemQuantity(item, itemMaxQuant);
                    SpawnObjectByType(itemType, itemQuant - itemMaxQuant);
                }
            }
        }
    }

    map<string, int> GetBiProductMap(map<string, int> mapBiProductsAmount, array<ref BST_FurnaceBiProduct> arrBiProducts, int multiplier) {
        Print("[DEBUG] Function call to get bi product map! count=" + mapBiProductsAmount.Count() + " | arr count=" + arrBiProducts.Count());
        foreach (BST_FurnaceBiProduct biProduct : arrBiProducts) {
            if (!biProduct) { continue; }
            string biProductType = biProduct.GetLoweredType();
            int newCount = biProduct.GetSpawnCount() * multiplier;

            Print("[DEBUG] new count=" + newCount + " | spawn count=" + biProduct.GetSpawnCount() + " | multiplier=" + multiplier);

            if (mapBiProductsAmount.Contains(biProductType)) {
                int oldCount = mapBiProductsAmount.Get(biProductType);
                Print("[DEBUG] old count=" + oldCount);

                mapBiProductsAmount.Set(biProductType, oldCount + newCount);
            } else {
                mapBiProductsAmount.Insert(biProductType, newCount);
            }
        }
        Print("[DEBUG] AFTER=" + mapBiProductsAmount.Count() + " | spawn count=" + mapBiProductsAmount.Get(biProductType));
        return mapBiProductsAmount;
    }

    ItemBase GetParent() { return parent; }
    bool IsSmelting() { return isSmelting; }
}