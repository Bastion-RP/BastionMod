class BST_FurnaceHandler {
    private BRP_FurnaceFireplace parent;

    void BST_FurnaceHandler(BRP_FurnaceFireplace parent) {
        this.parent = parent;
    }

    void ~BST_FurnaceHandler() {
        StopParentSmelting();
    }

    void StartSmelting() {
        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(this.Smelt, GetBSTServerCraftingManager().GetFurnaceConfig().GetTickRate() * 1000, true);
    }

    void StopSmelting() {
        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Remove(this.Smelt);
    }

    void StopParentSmelting() {
        parent.StopSmelting();
        StopSmelting();
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

                    arrCargo.Remove(i);
                    break;
                }
            }
        }
        if (!foundFuel || !arrBiProducts) {
            StopParentSmelting();
            parent.SetFuel(false);
            return;
        }
        mapBiProductsAmount = GetBiProductMap(mapBiProductsAmount, arrBiProducts, fuelRemoved);
        
        foreach (EntityAI ent : arrCargo) {
            if (!ent) { continue; }
            item = ItemBase.Cast(ent);

            if (item) {
                itemType = item.GetType();

                itemType.ToLower();

                if (mapRecipes.Contains(itemType)) {
                    BST_FurnaceRecipe recipe = mapRecipes.Get(itemType);
                    array<ref BST_FurnaceBiProduct> arrRecipeBiProduct = recipe.GetBiProducts();
                    int smeltRate = fuelRemoved * recipe.GetSmeltRate() * fuelMultiplier;
                    itemQuant = QuantityConversions.GetItemQuantity(item);

                    if (itemQuant > smeltRate) {
                        GetBSTServerCraftingManager().SetItemQuantity(item, itemQuant - smeltRate);
                    } else {
                        smeltRate = fuelRemoved * itemQuant * fuelMultiplier;

                        GetGame().ObjectDelete(item);
                    }
                    mapBiProductsAmount = GetBiProductMap(mapBiProductsAmount, arrRecipeBiProduct, smeltRate);
                }
            }
        }
        // Now handle the spawning of the new object. First, check to see if the bi products are already present
        foreach (EntityAI entity : arrCargo) {
            if (!entity) { continue; }
            item = ItemBase.Cast(entity);

            if (item) {
                itemType = item.GetType();

                itemType.ToLower();

                if (mapBiProductsAmount.Contains(itemType)) {
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
        for (int j = 0; j < mapBiProductsAmount.Count(); j++) {
            itemType = mapBiProductsAmount.GetKey(j);

            SpawnObjectByType(itemType, mapBiProductsAmount.Get(itemType));
        }
    }

    void SpawnObjectByType(string itemType, int itemQuant) {
        InventoryLocation il = new InventoryLocation();

        if (parent.GetInventory().FindFirstFreeLocationForNewEntity(itemType, FindInventoryLocationType.ANY, il)) {
            ItemBase item = il.GetParent().GetInventory().CreateEntityInCargoEx(itemType, il.GetIdx(), il.GetRow(), il.GetCol(), il.GetFlip());

            if (item) {
                Magazine magItem = Magazine.Cast(item);
                int itemMaxQuant;

                if (magItem) {
                    itemMaxQuant = magItem.GetAmmoMax();
                } else {
                    itemMaxQuant = item.ConfigGetInt("varQuantityMax");
                }
                if (itemQuant <= itemMaxQuant) {
                    GetBSTServerCraftingManager().SetItemQuantity(item, itemQuant);
                } else {
                    GetBSTServerCraftingManager().SetItemQuantity(item, itemMaxQuant);
                    SpawnObjectByType(itemType, itemQuant - itemMaxQuant);
                }
            }
        }
    }

    map<string, int> GetBiProductMap(map<string, int> mapBiProductsAmount, array<ref BST_FurnaceBiProduct> arrBiProducts, int multiplier) {
        foreach (BST_FurnaceBiProduct biProduct : arrBiProducts) {
            if (!biProduct) { continue; }
            string biProductType = biProduct.GetLoweredType();
            int newCount = biProduct.GetSpawnCount() * multiplier;

            if (mapBiProductsAmount.Contains(biProductType)) {
                int oldCount = mapBiProductsAmount.Get(biProductType);

                mapBiProductsAmount.Set(biProductType, oldCount + newCount);
            } else {
                mapBiProductsAmount.Insert(biProductType, newCount);
            }
        }
        return mapBiProductsAmount;
    }

    bool HasFuel() {
        array<EntityAI> arrCargo = new array<EntityAI>();

        parent.GetInventory().EnumerateInventory(InventoryTraversalType.PREORDER, arrCargo);
        foreach (EntityAI entity : arrCargo) {
            if (entity) {
                string entType = entity.GetType();
                entType.ToLower();

                if (GetBSTServerCraftingManager().GetFuelsMap().Contains(entType)) {
                    return true;
                }
            }
        }
        return false;
    }

    BRP_FurnaceFireplace GetParent() { return parent; }
}