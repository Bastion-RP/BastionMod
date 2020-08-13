modded class PlayerBase
{
	private int						traderId;
	private ref map<string, float> 	playerItems;
	private ref array<EntityAI> 	CargoItems;

	void PlayerBase()
	{
		traderId = -1;
		RegisterNetSyncVariableInt("traderId");

		// if (GetGame().IsServer())
		// {
		// 	SetAllowDamage(false);
		// }
	}

	int GetTraderId()
	{
		return traderId;
	}

	void SetTraderId(int id)
	{
		traderId = id;
		
		SetSynchDirty();
	}

	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionHumanBTraderTrade);
	}

	void SetupTrader(TraderData data)
	{
		int id;
		vector pos;
		vector ori;
		array<string> clothes;

		id = data.GetId();
		pos = data.GetPos();
		ori = data.GetOri();
		clothes = data.GetClothes();

		SetTraderId(id);
		SetPosition(pos);
		SetOrientation(ori);

		DressTrader(clothes);

		Print("Spawn trader id:"+GetTraderId()+" at "+pos);
	}

	void DressTrader(array<string> clothes)
	{
		int count;
		string cloth;
		count = clothes.Count();

		for (int i = 0; i < count; i++)
		{
			cloth = clothes.Get(i);

			if (!cloth) continue;

			GetInventory().CreateInInventory(cloth);
		}
	}


	override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		super.OnRPC(sender, rpc_type, ctx);

		if (GetGame().IsClient() || !GetGame().IsMultiplayer())
		{
			switch (rpc_type)
			{
				case BTRPC.SEND_TRADER_DATA:
					ApplyTraderData(ctx);
				break;
				case BTRPC.SEND_CONFIG:
					ApplyConfig(ctx);
				break;
				case BTRPC.REFRESH_ITEMS:
					RefreshItems();
				break;
			}	
		}
		else
		{
			switch (rpc_type)
			{
				case BTRPC.REQUEST_TRADER_DATA:
					SendTraderData(ctx);
				break;
				case BTRPC.REQUEST_TRADE:
					ApplyTrader(ctx);
				break;
			}
		}
	}

	void ApplyTraderData(ParamsReadContext ctx)
	{
		Param1<ref TraderData> data;

		if (!ctx.Read(data)) return;

		Print("PlayerBase::ApplyTraderData::data.param1 "+data.param1);
		GetBTraderManager().ApplyTraderData(data.param1);
	}

	void ApplyConfig(ParamsReadContext ctx)
	{
		Param1<ref BTraderConfig> data;

		if (!ctx.Read(data)) return;

		GetBTraderManager().SetConfig(data.param1);
	}

	void RefreshItems()
	{
		GetBTraderManager().RefreshAfterTrade();
	}

	void SendTraderData(ParamsReadContext ctx)
	{
		int Id;
		Param1<int> data;
		TraderData traderData;
		map<int, ref TraderData> tradersData;

		if (!ctx.Read(data)) return;

		Id = data.param1;
		tradersData = g_BTMS.GetTradersData();
		if (tradersData.Find(Id, traderData))
		{
			this.RPCSingleParam(BTRPC.SEND_TRADER_DATA, new Param1<ref TraderData>(traderData), true, this.GetIdentity());
			Print("PlayerBase::SendTraderData::traderData "+traderData.GetId());
		}
		else
		{
			Print("PlayerBase::SendTraderData::traderData not find");
		}
	}

	void ApplyTrader(ParamsReadContext ctx)
	{
		Param2<int, ref BTraderProductData> data;

		if (!ctx.Read(data)) return;

		BTrade(data.param1, data.param2);
	}

	override void OnConnect()
	{
		super.OnConnect();
		this.RPCSingleParam(BTRPC.SEND_CONFIG, new Param1<ref BTraderConfig>(g_BTMS.GetConfig()), true, this.GetIdentity());
	}

	void BTrade(int mdfr, ref BTraderProductData data)
	{
		int modifier;
		BTraderProductData productData;

		modifier = mdfr;
		productData = data;

		if (CheckItems(modifier, productData))
		{
			DeleteItems(modifier, productData);
			GiveResults(modifier, productData);
			SendRefreshItems();
		}
	}

	void ScanItems()
	{
		PlayerBase player = this;
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

		playerItems = new map<string, float>();
		itemsArray = new array<EntityAI>();
		player.GetInventory().EnumerateInventory(InventoryTraversalType.PREORDER, itemsArray);
		count = itemsArray.Count();
		minHealthLevel = g_BTMS.GetConfig().GetMH();
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

	bool CheckItems(int mdfr, ref BTraderProductData data)
	{
		float needQuantity;
		float itemQuantity;
		int count;
		int modifier;
		string itemType;
		array<ref DefaultItemData> products;
		DefaultItemData product;

		products = data.GetReqItems();
		count = products.Count();
		modifier = mdfr;
		ScanItems();
		for (int i = 0; i < count; i++)
		{
			product = products.Get(i);
			itemType = product.GetType();
			needQuantity = product.GetQuantity() * modifier;

			if (playerItems.Get(itemType) < needQuantity)
			{
				return false;
			}
		}

		return true;
	}

	void DeleteItems(int mdfr, BTraderProductData data)
    {
        BTraderProductData productData = data;
        ItemBase cargoItemIB;
		array<EntityAI> cargoBaseItems = new array<EntityAI>();
		array<ref DefaultItemData> products;
		DefaultItemData product;
        int cargoCount;
		int modifier;
		int count;
		string productType;
		int minHealthLevel;
		int currentHelthLevel;

		minHealthLevel = g_BTMS.GetConfig().GetMH();
		CargoItems = new array<EntityAI>();
        this.GetInventory().EnumerateInventory(InventoryTraversalType.PREORDER, cargoBaseItems);
        cargoCount = cargoBaseItems.Count();
		modifier = mdfr;
		products = productData.GetReqItems();
		count = products.Count();

        for (int k = 0; k < cargoCount; k++)
        {
            EntityAI crgEnt = cargoBaseItems.Get(k);
			currentHelthLevel = crgEnt.GetHealthLevel();
            if (crgEnt && !crgEnt.IsInherited(SurvivorBase) && (currentHelthLevel <= minHealthLevel))
            {
                CargoItems.Insert(crgEnt);
            }
        }

        for (int i = 0; i < count; i++)
        {
            product = products.Get(i);
			productType = product.GetType();
            cargoItemIB = ItemBase.Cast(GetGame().CreateObject(productType, vector.Zero, false));
            if (cargoItemIB)
            {
                if ((QuantityConversions.HasItemQuantity(cargoItemIB) == 0) || cargoItemIB.IsInherited(Magazine))
                {
                    ItemWithoutQuantity(product, modifier);
                }
                else
                {
                    ItemWithCount(product, modifier);
                }

                GetGame().ObjectDelete(cargoItemIB);
            }
        }
    }

    void ItemWithoutQuantity(DefaultItemData data, int mdfr)
    {
        int amount = data.GetQuantity() * mdfr;
        string name = data.GetType();
        int count = CargoItems.Count();
        for (int i = 0; i < count; i++)
        {
            EntityAI ent = CargoItems.Get(i);
            if (ent && (ent.GetType() == name))
            {
                ItemBase item = ItemBase.Cast(ent);
                if (item)
                {
                    GetGame().ObjectDelete(item);    

                    amount--;
                    if (!amount) break;
                }
            }
        }
    }


    void ItemWithCount(DefaultItemData data, int mdfr)
    {
        int amount = data.GetQuantity() * mdfr;
        string name = data.GetType();
        int count = CargoItems.Count();
        for (int i = 0; i < count; i++)
        {
            EntityAI ent = CargoItems.Get(i);
            if (ent && (ent.GetType() == name))
            {
                ItemBase item = ItemBase.Cast(ent);
                if (item)
                {
					if (item.GetQuantity() > amount)
					{
						item.AddQuantity(-amount);
						break;
					}
					else
					{
						amount -= item.GetQuantity();
						GetGame().ObjectDelete(item); 
					}
                }
            }
        }
    }

	void GiveResults(int mdfr, BTraderProductData data)
	{
		DefaultItemData result;
		float q_cur, q_min, q_max;
		float needQuantity;
		int stacks;
		string type;
		ItemBase reward;
		ItemBase tempIB;
		Magazine magazine_item;

		result = data.GetResult();
		stacks = mdfr;
		type = result.GetType();
		tempIB = ItemBase.Cast(GetGame().CreateObject(type, vector.Zero, false));

		QuantityConversions.GetItemQuantity(tempIB, q_cur, q_min, q_max)

		if (!q_max) q_max = 1;

		for (int i = 0; i < stacks; i++)
		{
			needQuantity = result.GetQuantity();
			while (needQuantity)
			{
				if (GetHumanInventory().CanAddEntityToInventory(tempIB))
				{
					if (q_max < needQuantity)
					{
						reward = ItemBase.Cast(this.GetInventory().CreateInInventory(type));
						needQuantity -= q_max;
					}
					else
					{
						reward = ItemBase.Cast(this.GetInventory().CreateInInventory(type));
						if (Class.CastTo(magazine_item, reward))
						{
							magazine_item.ServerSetAmmoCount(needQuantity);
						}
						else
						{
							reward.SetQuantity(needQuantity);
						}
						needQuantity = 0;
					}
				}
				else
				{
					if (q_max < needQuantity)
					{
						reward = ItemBase.Cast(GetGame().CreateObject(type, this.GetPosition(), false));
						needQuantity -= q_max;
					}
					else
					{
						reward = ItemBase.Cast(GetGame().CreateObject(type, this.GetPosition(), false));
						if (Class.CastTo(magazine_item, reward))
						{
							magazine_item.ServerSetAmmoCount(needQuantity);
						}
						else
						{
							reward.SetQuantity(needQuantity);
						}
						needQuantity = 0;
					}
				}
			}
		}
	}

	void SendRefreshItems()
	{
		this.RPCSingleParam(BTRPC.REFRESH_ITEMS, null, true, this.GetIdentity());
	}
}