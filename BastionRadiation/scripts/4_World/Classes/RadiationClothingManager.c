typedef map<int, float> TItemSlotDamageKoefMap;

class RadiationClothingManager
{
	private PlayerBase player;
	private ref TItemSlotDamageKoefMap itemDamageMap;
	private ref map <string, ref ItemProtectionRad> SuitProtectLevels;
	private const int slotMask = InventorySlots.MASK;
	private const ref array<int> clothingSlots = {
		InventorySlots.HEADGEAR,
		InventorySlots.GLOVES,
		InventorySlots.BODY,
		InventorySlots.VEST,
		InventorySlots.BACK,
		InventorySlots.LEGS,
		InventorySlots.FEET
	};

	private const ref array<int> allClothingSlots = {
		InventorySlots.MASK,
		InventorySlots.HEADGEAR,
		InventorySlots.GLOVES,
		InventorySlots.BODY,
		InventorySlots.VEST,
		InventorySlots.BACK,
		InventorySlots.LEGS,
		InventorySlots.FEET
	};

	void RadiationClothingManager(PlayerBase player)
	{
		this.player = player;
	}

	float CalculateInnerRadiation(float externalRadiation)
	{
		float afterClothingCalculateRadiation;
		float result;
		SuitProtectLevels = GetRadiationManager().GetConfig().GetSuitsLevels();

		RequestDamagePlayerSuit(externalRadiation);

		afterClothingCalculateRadiation = externalRadiation * (1 - GetPercentProtectSuit());
		if (GetGasMaskThreshold() > afterClothingCalculateRadiation)
			result = 1;
		else
			result = afterClothingCalculateRadiation * (1 - GetPercentProtectGasMask());
		
		return result;
	}

	float GetPercentProtectGasMask()
	{
		EntityAI item;
		float protect;
		item = player.GetInventory().FindAttachment(slotMask);
		if (item)
		{
			protect = GetRadiationProtectByItem(item);
		}

		return 0;
	}

	float GetGasMaskThreshold()
	{
		EntityAI item;
		float threshold;
		item = player.GetInventory().FindAttachment(slotMask);
		if (item)
		{
			threshold = GetRadiationProtectByItem(item);
		}

		return threshold;
	}

	float GetPercentProtectSuit()
	{
		float protect = 0;
		int slot;
		bool hasMask;
		EntityAI item;

		for (int i = 0; i < clothingSlots.Count(); i++)
		{
			slot = clothingSlots.Get(i);
			item = player.GetInventory().FindAttachment(slot);
			if (item)
			{
				protect += GetRadiationProtectByItem(item);
			}
		}

		Print("GetPercentProtectSuit "+protect);

		if (protect > 1)
			protect = 1;

		return protect;
	}

	float GetRadiationProtectByItem(EntityAI item)
	{
		float protect;
		int itemHealthLevel;
		string itemType;
		ItemProtectionRad itemConfig;
		array<float> protectLevels;
		
		itemHealthLevel = item.GetHealthLevel();
		itemType = item.GetType();
		itemConfig = SuitProtectLevels.Get(itemType);

		if (!itemConfig)
			return protect;

		protectLevels = itemConfig.GetProtectLevels();
		protect = protectLevels[itemHealthLevel];

		return protect;
	}

	float GetCriticalTresholdByItem(EntityAI item)
	{
		float criticalThreshold;
		string itemType;
		ItemProtectionRad itemConfig;
		
		itemType = item.GetType();
		itemConfig = SuitProtectLevels.Get(itemType);

		if (!itemConfig)
			return criticalThreshold;

		criticalThreshold = itemConfig.GetCritical();

		return criticalThreshold;
	}

	//=========================================
	//collect player inventory slots to send to the server which will reduce their HP
	//=========================================
	void InsertClothForServer(int itemSlot, float radiation, float criticalThreshold)
	{
		float damageKoef = RadiationMisc.GetCriticalThresholdDamageKoef(criticalThreshold, radiation);
		itemDamageMap.Insert(itemSlot, damageKoef);
	}

	void CollectData(float externalRadiation)
	{
		float criticalThreshold;
		EntityAI item;
		foreach (int slot : allClothingSlots)
		{
			item = player.GetInventory().FindAttachment(slot);
			if (item)
			{
				criticalThreshold = GetCriticalTresholdByItem(item);
				if (criticalThreshold)
					InsertClothForServer(slot, externalRadiation, criticalThreshold);
			}
		}
	}

	void PrepareCollectData()
	{
		if (itemDamageMap)
			delete itemDamageMap;
		itemDamageMap = new TItemSlotDamageKoefMap;
	}

	TItemSlotDamageKoefMap GetPlayerClothing()
	{
		return itemDamageMap;
	}

	void RequestDamagePlayerSuit(float externalRadiation)
	{
		PrepareCollectData();
		CollectData(externalRadiation);
	}

	void Debug()
	{
		Print("\nRadiationClothingManager Debug \n");
		for (int i = 0; i < itemDamageMap.Count(); i++)
		{
			Print(string.Format("idx:%1, elem:%2", itemDamageMap.GetKey(i), itemDamageMap.GetElement(i)));
		}
	}
}