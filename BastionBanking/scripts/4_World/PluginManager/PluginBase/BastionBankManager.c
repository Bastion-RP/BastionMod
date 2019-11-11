class BastionBankManager : PluginBase {
    ref array<ItemBase> GetMoneyInInventory(PlayerBase player) {
        ref array<ItemBase> arrayItems = new array<ItemBase>();
        array<EntityAI> enumeratedInventory = new array<EntityAI>();

        player.GetHumanInventory().EnumerateInventory(InventoryTraversalType.PREORDER, enumeratedInventory);

        foreach (EntityAI entity : enumeratedInventory) {
            ItemBase item = ItemBase.Cast(entity);
            if (item) {
                string typeName = item.GetType();
                typeName.ToLower();

                if (typeName == "nail") {
                    arrayItems.Insert(item);
                }
            }
        }
        return arrayItems;
    }

    bool CanDeposit(PlayerBase player, int amount, out ref array<ItemBase> outItems) {
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) { return false; }

        ref array<ItemBase> arrayItems = GetMoneyInInventory(player);

        if (arrayItems.Count() > 0) {
            int itemCount = 0;

            foreach (ItemBase item : arrayItems) {
                itemCount += item.GetQuantity();
            }
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

    void AddCurrency(PlayerBase player, int amount) {
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) { return; }

        ref array<ItemBase> arrayItems = GetMoneyInInventory(player);
        int itemMaxQuant = GetGame().ConfigGetInt(CFG_VEHICLESPATH + " nail" + " varQuantityMax");
        int withdrawAmount = amount;

        if (arrayItems.Count() > 0) {
            foreach (ItemBase item : arrayItems) {
                int gap = itemMaxQuant - item.GetQuantity();

                if (gap > 0) {
                    if (gap <= withdrawAmount) {
                        item.SetQuantity(itemMaxQuant);
                        withdrawAmount -= gap;
                    } else {
                        item.AddQuantity(withdrawAmount);
                        withdrawAmount = 0;
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

                if (player.GetInventory().FindFirstFreeLocationForNewEntity("nail", FindInventoryLocationType.ANY, il)) {
                    ItemBase newItem = il.GetParent().GetInventory().CreateEntityInCargoEx("nail", il.GetIdx(), il.GetRow(), il.GetCol(), il.GetFlip());

                    if (withdrawAmount < itemMaxQuant) {
                        newItem.SetQuantity(withdrawAmount);
                    } else {
                        newItem.SetQuantity(itemMaxQuant);
                    }
                    withdrawAmount -= itemMaxQuant;
                }
                if (withdrawAmount <= 0) {
                    break;
                }
            }
        }
    }

    void Transfer(PlayerBase player, int amount) {
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) { return; }

    }
}

BastionBankManager GetBankManager() {
    return BastionBankManager.Cast(GetPlugin(BastionBankManager))
}