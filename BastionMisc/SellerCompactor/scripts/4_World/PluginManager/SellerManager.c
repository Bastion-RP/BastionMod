class SellerManager : PluginBase
{
	private ref SellerConfig	config;

	void SellerManager()
	{
		if (GetGame().IsServer())
		{
			LoadConfig();
		}
	}

	void LoadConfig()
	{
		if (!FileExist(SellerConst.MOD_DIR))
		{MakeDirectory(SellerConst.MOD_DIR)}

		if (!FileExist(SellerConst.CONFIG_DIR))
		{
			config = new SellerConfig();
			config.Validate();
			JsonFileLoader<SellerConfig>.JsonSaveFile(SellerConst.CONFIG_DIR, config);
		}
		else
		{
			JsonFileLoader<SellerConfig>.JsonLoadFile(SellerConst.CONFIG_DIR, config);
		}

		//config.TransferData();
	}

	SellerConfig GetConfig() { return config; }

	void SetConfig(SellerConfig cong) { config = cong; }

	bool CanSellItem(string type)
	{
		if (GetItemData(type))
		{
			return true;
		}

		return false;
	}

	ref SellItemData GetItemData(string type)
	{
		array<ref SellItemData> allData = config.GetDataArray();
		foreach (SellItemData data : allData)
		{
			if (data.GetClassname() == type)
			return data;
		}

		return NULL;
	}

	int GetTotalSum(ItemBase itm, out int delQuant)
	{
		ItemBase item;
		Magazine pile;
		SellItemData sellData;
		string type;
		int maxSellStacks;
		int quantityType;
		int price;
		int itemHealthLevel;
		int totalSum;
		int tempSum;
		float quantity;
		float sellQuantity;
		float decreasePercent;

		item = itm;
		type = item.GetType();
		itemHealthLevel = item.GetHealthLevel();
		sellData = GetItemData(type);

		sellQuantity = sellData.GetQuantity();
		price = sellData.GetPrice();
		quantityType = QuantityConversions.HasItemQuantity(item);
		decreasePercent = (float)(GetConfig().GetPPDBHL() / 100);

		if (quantityType == 0 || quantityType == 2)
		{
			quantity = 1;
		}
		else
		{
			if (Class.CastTo(pile, item))
			{
				quantity = pile.GetAmmoCount();
			}
			else
			{
				quantity = item.GetQuantity();
			}
		}

		if (quantity > 1)
		{
			maxSellStacks = quantity / sellQuantity;

			if (maxSellStacks == 0)
			{
				delQuant = 0;
				return 0;
			}

			delQuant = maxSellStacks * sellQuantity;
		}
		else
		{
			maxSellStacks = 1;
			delQuant = 1;
		}

		tempSum = maxSellStacks * price;

		totalSum = tempSum - (tempSum * (decreasePercent * itemHealthLevel));

		return totalSum;
	}

	void SellItem(ItemBase itm, BRP_Compactor compactor)
	{
		ItemBase item;
		Magazine pile;

		int quantityType;

		int price;
		int deleteCount;

		item = itm;

		quantityType = QuantityConversions.HasItemQuantity(item);

		pile = Magazine.Cast(item);
		price = GetTotalSum(item, deleteCount);

		if (quantityType == 0 || quantityType == 2)
		{
			item.Delete();
		}
		else
		{
			if (pile)
			{
				pile.ServerAddAmmoCount(-deleteCount);
				if (pile.GetAmmoCount() == 0) pile.Delete();
			}
			else
			{
				item.AddQuantity(-deleteCount);
			}
		}

		PayCredits(price, compactor);
	}

	void PayCredits(int sum, BRP_Compactor compactor)
	{
		ItemBase money;
		vector spawnPoint;
		string moneyType;
		int quantMax;
		int spawnIterations;
		int finishSum;
		int lastSum;

		moneyType = GetBSTBankingConfigHandler().GetConfig().GetCurrencyClassName();
		finishSum = sum;
		spawnPoint = compactor.GetPosition() + (compactor.GetDirection() * 1.5);
		money = ItemBase.Cast( GetGame().CreateObject(moneyType, vector.Zero, false) );
		quantMax = money.GetQuantityMax();
		spawnIterations = sum / quantMax;
		lastSum = sum % quantMax;

		money.Delete();

		money = compactor.GetInventory().CreateEntityInCargo(moneyType);

		if (money == null)
		{
			money = ItemBase.Cast( GetGame().CreateObject(moneyType, spawnPoint, false) );
		}

		if (spawnIterations == 0)
		{
			money.SetQuantity(lastSum, true);
		}

		while (spawnIterations > 0)
		{
			money = null;

			money = compactor.GetInventory().CreateEntityInCargo(moneyType);

			if (money == null)
			{
				money = ItemBase.Cast( GetGame().CreateObject(moneyType, spawnPoint, false) );
			}

			if (spawnIterations == 1)
			{
				money.SetQuantity(lastSum, true);
			}

			spawnIterations--;
		}

		compactor.SoundSynchRemote();
	}

}

SellerManager GetSellerManager()
{
	return SellerManager.Cast(GetPlugin(SellerManager));
}