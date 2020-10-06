class BST_BankingManager : PluginBase {
    ref array<ItemBase> GetMoneyInInventory(PlayerBase player) {
        ref array<ItemBase> arrayItems = new array<ItemBase>();
        array<EntityAI> enumeratedInventory = new array<EntityAI>();

        player.GetHumanInventory().EnumerateInventory(InventoryTraversalType.PREORDER, enumeratedInventory);

        foreach (EntityAI entity : enumeratedInventory) {
            ItemBase item = ItemBase.Cast(entity);

            if (item) {
                string typeName = item.GetType();
                
                typeName.ToLower();

                if (typeName == GetBSTBankingConfigHandler().GetConfig().GetCurrencyClassName()) {
                    arrayItems.Insert(item);
                }
            }
        }
        return arrayItems;
    }

    bool CanDeposit(PlayerBase player, int amount, out ref array<ItemBase> outItems) {
        ref array<ItemBase> arrayItems = GetMoneyInInventory(player);

        if (arrayItems.Count() > 0) {
            int itemCount = 0;

            foreach (ItemBase item : arrayItems) {
                itemCount += QuantityConversions.GetItemQuantity(item);
            }
            // This is for depositing all funds in inventory
            /* if (amount == -1) {
                outItems = arrayItems;
                return true;
            } */
            if (itemCount >= amount) {
                outItems = arrayItems;
                return true;
            }
        }
        return false;
    }

    void RemoveCurrency(ref array<ItemBase> arrayItems, int amount) {
        foreach (ItemBase item : arrayItems) {
            if (!item) { continue; }
            int itemQuant = QuantityConversions.GetItemQuantity(item);

            if (itemQuant <= amount) {
                amount -= itemQuant;

                GetGame().ObjectDelete(item);
            } else {
                SetItemQuantity(item, itemQuant - amount);

                amount = 0;
            }
            if (amount <= 0) {
                break;
            }
        }
    }

    void SetItemQuantity(ItemBase item, int amount) {
        Magazine magazine = Magazine.Cast(item);

        if (magazine) {
            magazine.ServerSetAmmoCount(amount);
        } else {
            item.SetQuantity(amount);
        }
    }

    int AddCurrency(PlayerBase player, int amount) {
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) { return 0; }

        ref array<ItemBase> arrayItems = GetMoneyInInventory(player);
        int itemMaxQuant = GetGame().ConfigGetInt(CFG_VEHICLESPATH + " " + GetBSTBankingConfigHandler().GetConfig().GetCurrencyClassName() + " varQuantityMax");
        int amountWithdrawn = 0;

        if (arrayItems.Count() > 0) {
            foreach (ItemBase item : arrayItems) {
                int itemQuant = item.GetQuantity();
                int gap = itemMaxQuant - itemQuant;

                if (gap > 0) {
                    if (gap <= amount) {
                        amount -= gap;
                        amountWithdrawn += gap;

                        SetItemQuantity(item, itemMaxQuant);
                    } else {
                        SetItemQuantity(item, itemQuant + amount);

                        amountWithdrawn += amount;
                        amount = 0;
                    }
                }
                if (amount == 0) {
                    break;
                }
            }
        }
        if (amount > 0) {
            int iterationAmount = Math.Ceil(amount / itemMaxQuant);

            for (int i = 0; i < iterationAmount; i++) {
                InventoryLocation il = new InventoryLocation();

                if (player.GetInventory().FindFirstFreeLocationForNewEntity(GetBSTBankingConfigHandler().GetConfig().GetCurrencyClassName(), FindInventoryLocationType.ANY, il)) {
                    ItemBase newItem = ItemBase.Cast(player.GetInventory().CreateInInventory(GetBSTBankingConfigHandler().GetConfig().GetCurrencyClassName()));
                    //ItemBase newItem = ItemBase.Cast(il.GetParent().GetInventory().CreateEntityInCargoEx(GetBSTBankingConfigHandler().GetConfig().GetCurrencyClassName(), il.GetIdx(), il.GetRow(), il.GetCol(), il.GetFlip()));
                    
                    if (!newItem) { continue; } // This will make sure the count is never added to begin with.
                    if (amount < itemMaxQuant) {
                        amountWithdrawn += amount;

                        SetItemQuantity(newItem, amount);
                    } else {
                        amountWithdrawn += itemMaxQuant;

                        SetItemQuantity(newItem, amount);
                    }
                    amount -= itemMaxQuant;
                }
                if (amount <= 0) {
                    break;
                }
            }
        }
        return amountWithdrawn;
    }
}

BST_BankingManager GetBSTBankingManager() {
    return BST_BankingManager.Cast(GetPlugin(BST_BankingManager));
}