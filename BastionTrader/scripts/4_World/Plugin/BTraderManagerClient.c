class BTraderManagerClient : PluginBase
{
	private ref BTraderUI					tradeUI;
	private ref BTraderConfig				config;
	private ref map<int, ref TraderData> 	AllTradersData;
	private ref map<string, float>			playerItems;

	void BTraderManagerClient()
	{
		AllTradersData = new map<int, ref TraderData>();
		playerItems = new map<string, float>();
	}

	void OpenUI(TraderData traderData)
	{
		if (tradeUI || GetGame().GetUIManager().GetMenu()) return;
		GetGame().GetMission().GetHud().ShowQuickbarUI( false );
        tradeUI = new BTraderUI(traderData);
        GetGame().GetUIManager().ShowScriptedMenu( tradeUI, NULL );
	}

	void TradeInteract(int trdId)
	{
		if (trdId == -1) return;

		int traderId;
		TraderData traderData;

		traderId = trdId;

		if (!AllTradersData.Find(traderId, traderData))
		{
			RequestTraderData(traderId);
		}

		ScanPlayerInventory();
		OpenUI(traderData);
	}

	void RequestTraderData(int Id)
	{
		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());

		if (!player) return;

		player.RPCSingleParam(BTRPC.REQUEST_TRADER_DATA, new Param1<int>(Id), true);
	}

	void ApplyTraderData(ref TraderData data)
	{
		int id = data.GetId();
		AllTradersData.Insert(id, data);
		if (tradeUI)
		{
			tradeUI.FillContent(data);
		}
	}

	void ScanPlayerInventory()
	{
		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
		array<EntityAI> itemsArray;
		ItemBase item;
		Magazine pile;
		int count;
		int minHealthLevel;
		int currentHelthLevel;
		float quantity;
		float currentQuantity;
		string type;

		if (!player) return;

		playerItems.Clear();
		itemsArray = new array<EntityAI>();
		player.GetInventory().EnumerateInventory(InventoryTraversalType.PREORDER, itemsArray);
		count = itemsArray.Count();
		minHealthLevel = GetConfig().GetMH();
		for (int i = 0; i < count; i++)
		{
			Class.CastTo(item, itemsArray.Get(i));
			if (item && !item.IsInherited(SurvivorBase))
			{
				currentHelthLevel = item.GetHealthLevel();
				if ((currentHelthLevel <= minHealthLevel))
				{
					if (item.HasQuantity())
					{
						if (Class.CastTo(pile, item))
							quantity = pile.GetAmmoCount();
						else
							quantity = item.GetQuantity();
					}
					else
					{
						quantity = 1;
					}

					type = item.GetType();

					if ( !playerItems.Contains(type)  )
					{
						playerItems.Insert(type, quantity);
					}
					else
					{
						currentQuantity = playerItems.Get(type);
						playerItems.Set(type, (quantity + currentQuantity));
					}
				}
			}
		}
	}

	void ShowMap(map<string, float> arr)
	{
		for (int i = 0; i < arr.Count(); i++)
		{
			Print( string.Format("№%1| # %2 / elem %3", i, arr.GetKey(i), arr.GetElement(i)) );
		}
	}

	void SetConfig(BTraderConfig conf)
	{
		config = conf;
	}

	BTraderConfig GetConfig()
	{
		return config;
	}

	float GetQuantityByType(string type)
	{
		float quantity = 0;

		quantity = playerItems.Get(type);

		return quantity;
	}

	string GetObjectNameByType(string type)
	{
		string name;
		string typePath = type + " displayName";

		GetGame().ConfigGetText("CfgVehicles " + typePath, name);
	
		if (!name)
		{
			GetGame().ConfigGetText("CfgAmmo " + typePath, name);
		}
		
		if (!name)
		{
			GetGame().ConfigGetText("CfgMagazines " + typePath, name);
		}
		
		if (!name)
		{
			GetGame().ConfigGetText("cfgWeapons " + typePath, name);
		}
	
		if (!name)
		{
			GetGame().ConfigGetText("CfgNonAIVehicles " + typePath, name);
		}
		
		return name;
	}

	void RequestTrade(int mdfr, ref BTraderProductData data)
	{
		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());

		if (!player) return;

		player.RPCSingleParam(BTRPC.REQUEST_TRADE, new Param2<int, ref BTraderProductData>(mdfr, data), true);

	}

	void RefreshAfterTrade()
	{
		if (tradeUI)
		{
			ScanPlayerInventory();
			tradeUI.OnResultSelect(tradeUI.GetCurrentWidget());
		}
	}
}

BTraderManagerClient GetBTraderManager()
{
	return BTraderManagerClient.Cast(GetPlugin(BTraderManagerClient));
}