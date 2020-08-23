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
                itemCount += item.GetQuantity();
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
        foreach (ItemBase i : arrayItems) {
            int quant = i.GetQuantity();

            if (quant <= amount) {
                GetGame().ObjectDelete(i);
                amount -= quant;
            } else {
                i.AddQuantity(-amount);
                amount = 0;
            }
            if (amount <= 0) {
                break;
            }
        }
    }

    int AddCurrency(PlayerBase player, int amount) {
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) { return 0; }

        ref array<ItemBase> arrayItems = GetMoneyInInventory(player);
        int itemMaxQuant = GetGame().ConfigGetInt(CFG_VEHICLESPATH + " " + GetBSTBankingConfigHandler().GetConfig().GetCurrencyClassName() + " varQuantityMax");
        int withdrawAmount = amount;
        int amountWithdrawn = 0;

        if (arrayItems.Count() > 0) {
            foreach (ItemBase item : arrayItems) {
                int gap = itemMaxQuant - item.GetQuantity();

                if (gap > 0) {
                    if (gap <= withdrawAmount) {
                        withdrawAmount -= gap;
                        amountWithdrawn += gap;
                        
                        item.SetQuantity(itemMaxQuant);
                    } else {
                        withdrawAmount = 0;
                        amountWithdrawn += withdrawAmount;

                        item.AddQuantity(withdrawAmount);
                    }
                }
                if (withdrawAmount == 0) {
                    break;
                }
            }
        }
        if (withdrawAmount > 0) {
            int iterationAmount = Math.Ceil(withdrawAmount / itemMaxQuant);

            for (int i = 0; i < iterationAmount; i++) {
                InventoryLocation il = new InventoryLocation();

                if (player.GetInventory().FindFirstFreeLocationForNewEntity(GetBSTBankingConfigHandler().GetConfig().GetCurrencyClassName(), FindInventoryLocationType.ANY, il)) {
                    ItemBase newItem = ItemBase.Cast(il.GetParent().GetInventory().CreateEntityInCargoEx(GetBSTBankingConfigHandler().GetConfig().GetCurrencyClassName(), il.GetIdx(), il.GetRow(), il.GetCol(), il.GetFlip()));

                    if (withdrawAmount < itemMaxQuant) {
                        amountWithdrawn += withdrawAmount;

                        newItem.SetQuantity(withdrawAmount);
                    } else {
                        amountWithdrawn += itemMaxQuant;

                        newItem.SetQuantity(itemMaxQuant);
                    }
                    withdrawAmount -= itemMaxQuant;
                }
                if (withdrawAmount <= 0) {
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