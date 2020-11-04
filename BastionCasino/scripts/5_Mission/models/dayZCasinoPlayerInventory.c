class BastionCasinoPlayerInventory
{
	private map<string, int> currencyValues;
	
	void BastionCasinoPlayerInventory(map<string, int> currencyValues) {
		this.currencyValues = currencyValues;
	}
	
    bool PlayerHasEnoughChips(DayZPlayer player, int betSumme) {
        int amount = GetPlayerChipsAmount(player);
        DebugMessageCasino("Has amount of " + amount);

        return betSumme <= amount;
    }

    int GetPlayerChipsAmount(DayZPlayer player)
    {
        if (!player) {
            DebugMessageCasino("can not get chips, no player set");
            return 0;
        }

        DebugMessageCasino("GetPlayerChipsAmount");
        int currencyAmount = 0;

        array<EntityAI> itemsArray = new array<EntityAI>;
        player.GetInventory().EnumerateInventory(InventoryTraversalType.PREORDER, itemsArray);

        ItemBase item;
        for (int i = 0; i < itemsArray.Count(); i++)
        {
            Class.CastTo(item, itemsArray.Get(i));
			
            if(item && item.GetType()) {
				int value = currencyValues.Get(item.GetType());
				if (value) {
					currencyAmount += value * item.GetQuantity();
				}
			}
        }

        return currencyAmount;
    }

    int AddChipsToPlayer(DayZPlayer player, float chipsCount) {
        array<EntityAI> itemsArray = new array<EntityAI>;
        player.GetInventory().EnumerateInventory(InventoryTraversalType.PREORDER, itemsArray);

        ItemBase item;
		int currencyAmount = 0;
        for (int i = 0; i < itemsArray.Count(); i++)
        {
            Class.CastTo(item, itemsArray.Get(i));
			
            if(item && item.GetType()) {
				int value = currencyValues.Get(item.GetType());
				if (value) {
					currencyAmount += value * item.GetQuantity();
					GetGame().ObjectDelete(item);
				}
			}
        }
		
		currencyAmount = currencyAmount + chipsCount;

        if (currencyAmount > 0) {
            currencyAmount = AddNewChipsItemToInventory(player, currencyAmount);
        }

        return currencyAmount;
    }

    private int AddNewChipsItemToInventory(DayZPlayer player, float chipsCount) {
        InventoryLocation inventoryLocation = new InventoryLocation;
		
		int selectedValue = 0;
        string selectedType = "";
        foreach(string type, int value: currencyValues) {
            if (chipsCount >= value && selectedValue < value) {
                selectedValue = value;
                selectedType = type;
				DebugMessageCasino("set optimal type" + selectedType + " " + selectedValue.ToString());
            }
        }

		if (selectedValue == 0) {
		    return 0;
		}
		
		DebugMessageCasino("use optimal type" + selectedType);
		EntityAI chipsEntity;
        if (player.GetInventory().FindFirstFreeLocationForNewEntity(selectedType, FindInventoryLocationType.ANY, inventoryLocation)) {
			DebugMessageCasino("spawn chips in inventory");
            chipsEntity = player.GetHumanInventory().CreateInInventory(selectedType);
		}
		
		if (!chipsEntity && !player.GetHumanInventory().GetEntityInHands()) {
			DebugMessageCasino("spawn chips in hands");
            chipsEntity = player.GetHumanInventory().CreateInHands(selectedType);
		} 
		
		if (!chipsEntity) {
			DebugMessageCasino("spawn chips on ground");
            chipsEntity = player.SpawnEntityOnGroundPos(selectedType, player.GetPosition());
		}
		
		if (!chipsEntity) {
			Print("[BastionCasino] Chips entity from type: " + selectedType + " can not created, can not spawn");
			GetGame().AdminLog("[BastionCasino] Chips entity from type: " + selectedType + " can not created, can not spawn");
			return 0;
		}
		
        chipsCount = AddChips(selectedValue, chipsCount, chipsEntity);

        if(chipsCount) {
            chipsCount = AddNewChipsItemToInventory(player, chipsCount);
        }

        return chipsCount;
    }

    private int AddChips(int factor, float chipsToAdd, EntityAI entity) {
		
		
        ItemBase item;
        ItemBase.CastTo(item, entity);
		DebugMessageCasino("old chipsToAdd value " + chipsToAdd.ToString());

        int maxAmount = item.GetQuantityMax();
		
		int countAddFromType = Math.Floor(chipsToAdd / factor);
		DebugMessageCasino("must add from type " + countAddFromType.ToString());
		
        if (countAddFromType > maxAmount) {
			DebugMessageCasino("Add full chips stack");
            chipsToAdd -= maxAmount * factor;
            item.SetQuantity(maxAmount);
        } else {
			DebugMessageCasino("Add chips to stack");
            item.SetQuantity(countAddFromType);
            chipsToAdd -= countAddFromType * factor;
        }
		
		DebugMessageCasino("chipsValue is " + chipsToAdd.ToString());
		if (chipsToAdd < 1) {
			chipsToAdd = 0;
		}
        
		DebugMessageCasino("new chipsToAdd value " + chipsToAdd.ToString());
		return chipsToAdd;
    }
};