class PersonalQuestManager 
{
	private ref array<ItemBase> 		playerCargo;
	private ref map<string,int>			existItems;

	PlayerBase							m_Player;

	ref QuestStorageLoader				m_QuestStorageLoader;

	void PersonalQuestManager(PlayerBase player)
	{
		m_Player				= player;
		playerCargo				= new array<ItemBase>();
		existItems				= new map<string,int>();
		m_QuestStorageLoader	= new QuestStorageLoader();
		m_QuestStorageLoader	= QuestStorageLoader.LoadData(m_Player.GetMultiCharactersPlayerId().ToString());
		//m_QuestStorageLoader	= QuestStorageLoader.LoadData(m_Player.GetIdentity().GetPlainId());
		//Print("[QUEST]m_QuestStorageLoader load data id= "+m_Player.GetMultiCharactersPlayerId().ToString());
	}

	void OnConnect()
	{
		g_QND.SendAllData(m_Player);
		g_QD.SendQuestsData(m_Player);
		SendData();
	}

	void SendData()
	{
		m_Player.RPCSingleParam(QRPC.SEND_SYNC_QUEST, new Param1<ref QuestManagerStg>(m_QuestStorageLoader.m_QuestManagerStg), true, m_Player.GetIdentity());
	}

	void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		switch (rpc_type)
        {
            case QRPC.REQUEST_GIVE_ITEMS:
				handleGiveShipment(ctx);
            break;
			case QRPC.REQUEST_DELIVERY_ITEMS:
				handleDeliveryItems(ctx);
			break;
			case QRPC.REQUEST_SYNC_DATA:
				handleSyncData(ctx);
			break;
			case QRPC.REQUEST_SPAWN_ITEM:
				handleSpawnItems(ctx);
			break;
        }
	}

	void handleSyncData(ParamsReadContext ctx)
	{
		Param1<ref QuestManagerStg> rpb;
		if (!ctx.Read(rpb)) return;
		m_QuestStorageLoader.m_QuestManagerStg = rpb.param1;
		//QuestStorageLoader.SaveData(m_QuestStorageLoader, m_Player.GetIdentity().GetPlainId());
		QuestStorageLoader.SaveData(m_QuestStorageLoader, m_Player.GetMultiCharactersPlayerId().ToString());
	}

	void handleGiveShipment(ParamsReadContext ctx)
    {
        Param1<ref array<ref Shipment>> rpb;
        if (!ctx.Read(rpb)) return;
        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(handleGiveShipmentDelay, 50, false, rpb.param1);
    }

	void handleGiveShipmentDelay(ref array<ref Shipment> arr)
	{
		for (int i = 0; i < arr.Count(); i++)
		{
			Shipment sm = arr.Get(i);
			OverflowCountSpawn(sm.Classname, sm.Count);
		}
	}

	void GiveItemPlayer(string type, int count = 0)
    {
        ItemBase entTemp = ItemBase.Cast(GetGame().CreateObject(type,vector.Zero,false));
        ItemBase ent;
        Magazine mgzn;
        if (m_Player.GetHumanInventory().CanAddEntityToInventory(entTemp) || m_Player.GetHumanInventory().CanAddEntityInHands(entTemp))
        {
            ent = ItemBase.Cast(m_Player.GetHumanInventory().CreateInInventory(type));
            if (!ent)
            {
                ent = ItemBase.Cast(GetGame().CreateObject(type,m_Player.GetPosition(),false));
            }
        }
        else
        {
            ent = ItemBase.Cast(GetGame().CreateObject(type,m_Player.GetPosition(),false));
        }
        if (QuantityConversions.HasItemQuantity(ent))
        {
            if (Magazine.Cast(ent))
            {
                mgzn = Magazine.Cast(ent);
                mgzn.ServerSetAmmoCount(count);
            } 
            else
            {
                ent.SetQuantity(count);
            }
        }
        GetGame().ObjectDelete(entTemp);
    }

	void handleDeliveryItems(ParamsReadContext ctx)
    {
        Param2<ref array<ref Shipment>, int> rpb;
        if (!ctx.Read(rpb)) return;
        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(handleDeliveryShipmentDelay, 50, false, rpb.param1, rpb.param2);
	}

	void SearchAllItems()
	{
		array<EntityAI> itemsArray = new array<EntityAI>;
		ItemBase item;
		m_Player.GetInventory().EnumerateInventory(InventoryTraversalType.PREORDER, itemsArray);
		
		for (int i = 0; i < itemsArray.Count(); i++)
		{
			Class.CastTo(item, itemsArray.Get(i));
			if (item && !item.IsInherited(SurvivorBase))	
			playerCargo.Insert(item);
		}
	}
	
	void handleDeliveryShipmentDelay(ref array<ref Shipment> arr, int questID)
    {
		if (CheckFraud(arr))
		{
			SearchAllItems();
			ItemBase cargoItemIB;
			for (int i = 0; i < arr.Count(); i++)
			{
				Shipment sh = arr.Get(i);
				cargoItemIB = ItemBase.Cast(GetGame().CreateObject(sh.Classname, vector.Zero, true));
				if (cargoItemIB)
				{
					if ((QuantityConversions.HasItemQuantity(cargoItemIB) == 0) || cargoItemIB.IsInherited(Magazine))
					{
						ItemWithoutQuantity(sh);
					}
					else
					{
						ItemWithCount(sh);
					}

					GetGame().ObjectDelete(cargoItemIB);
				}
			}
			playerCargo.Clear();
			PayRewards(questID);
		}
		else
		{
			Print("[QUESTCHEAT][Name:"+m_Player.GetIdentity().GetName()+"|ID:"+m_Player.GetIdentity().GetPlainId()+"] tried to cheat the system");
		}
    }

    void ItemWithoutQuantity(Shipment sh)
    {
        int amount = sh.Count;
        string name = sh.Classname;
        int count = playerCargo.Count();
        for (int i = 0; i < count; i++)
        {
            if (playerCargo.Get(i) && (playerCargo.Get(i).GetType() == name))
            {
                ItemBase item = playerCargo.Get(i);
                if (item)
                {
                    GetGame().ObjectDelete(item);    

                    amount--;
                    if (!amount) break;
                }
            }
        }
    }


    void ItemWithCount(Shipment sh)
    {
        int amount = sh.Count;
        string name = sh.Classname;
        int count = playerCargo.Count() - 1;
        for (int i = count; i > -1; i--)
        {
            if (playerCargo.Get(i) && (playerCargo.Get(i).GetType() == name))
            {
                ItemBase item = playerCargo.Get(i);
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
				playerCargo.Remove(i);
            }
        }
    }

	void PayRewards(int questID)
	{
		for (int i = 0; i < g_QD.m_QuestsLoader.AllQuests.Count(); i++)
		{
			Quest qt = g_QD.m_QuestsLoader.AllQuests.Get(i);
			if (qt && qt.QuestID == questID)
			{
				handleGiveRewards(qt.Rewards);
			}
		}
	}

	void ScanItems() //to avoid fraud
    {
        if (!m_Player)
        {
            return;
        }

		array<EntityAI> itemsArray = new array<EntityAI>;
		m_Player.GetInventory().EnumerateInventory(InventoryTraversalType.PREORDER, itemsArray);
		
        int quant;
        
        for (int c = 0; c < itemsArray.Count(); c++)
        {
            ItemBase cargoItemIB;
			if ( Class.CastTo(cargoItemIB, itemsArray.Get(c)) && cargoItemIB.IsItemBase() )
            {
                if (cargoItemIB.IsRuined()) continue;
                if (cargoItemIB.HasQuantity())
                {
                    quant = cargoItemIB.GetQuantity();
                }
                else
                {
                    quant = 1;
                }

                if (!existItems.Contains(cargoItemIB.GetType()))
                {
                    existItems.Insert(cargoItemIB.GetType(), quant);
                }
                else
                {
                    int nowQuant = existItems.Get(cargoItemIB.GetType());
                    existItems.Set(cargoItemIB.GetType(), (nowQuant + quant));
                }
            }
        }
    }

	bool CheckFraud(ref array<ref Shipment> arr)
	{
		ScanItems();
		for (int i = 0; i < arr.Count(); i++)
        {
            Shipment sh = arr.Get(i);
            int count = existItems.Get(sh.Classname);
            if ( count < sh.Count )
            {
				existItems.Clear();
				return false;
			}
        }
		existItems.Clear();
		return true;
	}

	void handleGiveRewards(ref array<ref Reward> arr)
	{
		for (int i = 0; i < arr.Count(); i++)
		{
			Reward rw = arr.Get(i);
			OverflowCountSpawn(rw.Classname, rw.Count);
		}
	}

	void OverflowCountSpawn(string name, int count, bool onGround = false, vector pos = "0 0 0", vector ori = "0 0 0")
	{
		ItemBase 	tempItm = ItemBase.Cast(GetGame().CreateObject(name, vector.Zero, true));
		ItemBase	spawnItem;
		Magazine 	mgzn;
		Magazine 	pile;
		int 		fullStackCount;
		int 		fin;

		float height = GetGame().SurfaceY(pos[0], pos[2]);
		if (height > pos[1])
		{
			pos[1] = height;
		}

		if (Class.CastTo(mgzn, tempItm))	//for ammo
		{
			if (count > mgzn.GetAmmoMax())
			{
				fullStackCount = count / mgzn.GetAmmoMax();
				for (int j = 0; j < fullStackCount; j++)
				{
					if (onGround)
					{
						pile = Magazine.Cast(GetGame().CreateObject(name, vector.Zero, false));
						pile.SetPosition(pos);
						pile.SetOrientation(ori);
						pile.ServerSetAmmoMax();
					}
					else
					{
						GiveItemPlayer(name, mgzn.GetAmmoMax());
					}
				}
				fin = count - (fullStackCount * mgzn.GetAmmoMax());
				if (onGround)
				{
					pile = Magazine.Cast(GetGame().CreateObject(name, vector.Zero, false));
					pile.SetPosition(pos);
					pile.SetOrientation(ori);
					pile.ServerSetAmmoCount(fin);
				}
				else
				{
					GiveItemPlayer(name, fin);
				}
			}
			else
			{
				if (onGround)
				{
					pile = Magazine.Cast(GetGame().CreateObject(name, vector.Zero, false));
					pile.SetPosition(pos);
					pile.SetOrientation(ori);
					pile.ServerSetAmmoCount(count);
				}
				else
				{
					GiveItemPlayer(name, count);
				}
			}
			GetGame().ObjectDelete(mgzn);
		}
		else if (tempItm)
		{
			if (count > tempItm.GetQuantityMax() && (tempItm.GetQuantityMax() != 0) )
			{
				fullStackCount = count / tempItm.GetQuantityMax();
				for (int k = 0; k < fullStackCount; k++)
				{
					if (onGround)
					{
						spawnItem = ItemBase.Cast(GetGame().CreateObject(name, vector.Zero, false));
						spawnItem.SetPosition(pos);
						spawnItem.SetOrientation(ori);
						spawnItem.SetQuantity(spawnItem.GetQuantityMax());
					}
					else
					{
						GiveItemPlayer(name, tempItm.GetQuantityMax());
					}
				}
				fin = count - (fullStackCount * tempItm.GetQuantityMax());
				if (onGround)
				{
					spawnItem = ItemBase.Cast(GetGame().CreateObject(name, vector.Zero, false));
					spawnItem.SetPosition(pos);
					spawnItem.SetOrientation(ori);
					spawnItem.SetQuantity(fin);
				}
				else
				{
					GiveItemPlayer(name, fin);
				}
			}
			else
			{
				if (onGround)
				{
					spawnItem = ItemBase.Cast(GetGame().CreateObject(name, vector.Zero, false));
					spawnItem.SetPosition(pos);
					spawnItem.SetOrientation(ori);
					spawnItem.SetQuantity(count);
				}
				else
				{
					GiveItemPlayer(name, count);
				}
			}
			GetGame().ObjectDelete(tempItm);
		}
	}

	void handleSpawnItems(ParamsReadContext ctx)
	{
		Param1<ref Shipment> rpb;
		if (!ctx.Read(rpb)) return;
		ref Shipment sh = rpb.param1;
		OverflowCountSpawn(sh.Classname, sh.Count, true, sh.PackagePos, sh.PackageOri);		
	}



	void KilledSomething(Object target)
	{
		bool needSave = false;
		bool needSync = false;
		for (int i = 0; i < m_QuestStorageLoader.m_QuestManagerStg.QuestStatusArr.Count(); i++)
		{
			AppliedQuestStatus qs = m_QuestStorageLoader.m_QuestManagerStg.QuestStatusArr.Get(i);
			if (qs.Type == "KillSomething")
			{
				for (int j = 0; j < qs.SaveCountKilledSomething.Count(); j++)
				{
					QKillTgt qkt = qs.SaveCountKilledSomething.Get(j);
					if (IsRightTarget(target, qkt.Classname))
					{
						needSave = true;
						qkt.KillCount += 1;
						if (IsKillQuestComplete(qs)) 
						needSync = true;
					}
				}
			}
		}
		if (needSave)
		{
			//QuestStorageLoader.SaveData(m_QuestStorageLoader, m_Player.GetIdentity().GetPlainId());
			QuestStorageLoader.SaveData(m_QuestStorageLoader, m_Player.GetMultiCharactersPlayerId().ToString());
		}
		if (needSync)
		{
			SendData();
		}
	}

	bool IsKillQuestComplete(AppliedQuestStatus qs)
	{
		for (int i = 0; i < qs.SaveCountKilledSomething.Count(); i++)
		{
			QKillTgt qkt = qs.SaveCountKilledSomething.Get(i);
			if (qkt.Count > qkt.KillCount)
			return false;
		}
		return true;
	}

	bool IsRightTarget(Object obj, string tgtName)
	{
		if (tgtName == "Zombie" && obj.IsInherited(ZombieBase))
		{
			return true;
		}
		if (tgtName == "Animal" && obj.IsInherited(Animal))
		{
			return true;
		}
		if (obj.GetType() == tgtName)
		{
			return true;
		}
		return false;
	}
}