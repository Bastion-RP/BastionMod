class BRP_House extends Building
{
	ref HouseData					m_HouseData;
	private int 					low, high;
	private int						m_DoorsCount;
	static ref array<ref BRP_House> Houses = new array<ref BRP_House>();

	bool							isDebug = true;
	
	void BRP_House()
	{
		Houses.Insert(this);
		m_DoorsCount = 0;
		GetNetworkID(low, high);
		//Print("low:"+low.ToString()+" | high:"+high.ToString()+ " | loaded after "+(GetGame().GetTickTime()/1000).ToString());
		GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( CloseAllDoors, 5000, false);
	}

	void ~BRP_House()
	{
		int idx = BRP_House.Houses.Find(this);
		if (idx != -1) BRP_House.Houses.Remove(idx);
	}

	void CloseAllDoors()
	{
		for (int i = 0; i < 300; i++)
		{
			int doorIndex = this.GetDoorIndex(i);
			if ( doorIndex != -1 )
			{
				this.CloseDoor(doorIndex);
				m_DoorsCount++;
			}
		}
	}

	int GetDoorsCount()
	{
		return m_DoorsCount;
	}

	void RequestHouseData()
	{
		this.RPCSingleParam(HRPC.REQUEST_HOUSE_DATA, new Param2<int,int>(low, high), true, null);
	}

	override void OnRPC(PlayerIdentity sender, int rpc_type,ParamsReadContext  ctx) 
	{
		super.OnRPC(sender, rpc_type,ctx);
		if (GetGame().IsServer())
		{HandleRPCServer(sender, rpc_type, ctx);}
		else if (GetGame().IsClient())
		{HandleRPCClient(sender, rpc_type, ctx);}
	}

	void HandleRPCServer(PlayerIdentity sender, int rpc_type,ParamsReadContext  ctx) 
	{
		switch (rpc_type)
		{
			case HRPC.REQUEST_HOUSE_DATA:
				handleRequestHouseData(sender, ctx);
			break;
			case HRPC.REQUEST_ADD_HOUSE_INFO:
				handleAddHouseInfo(ctx);
			break;
			case HRPC.REQUEST_RENT_HOUSE:
				handleRequestRentHouse(sender, ctx);
			break;
			case HRPC.REQUEST_APPROVAL_LEASE:
				handleApplySuggestion(sender, ctx);
			break;
			case HRPC.REQUEST_EVICT_PLAYER:
				handleEvictPlayer(ctx);
			break;
			case HRPC.REQUEST_ADD_DOOR_GUEST:
				handleAddDoorGuest(ctx);
			break;
			case HRPC.REQUEST_REMOVE_REQUEST:
				handleRemoveRequest(ctx);
			break;
			case HRPC.REQUEST_EDIT_DOOR_INFO:
				handleEditDoorInfo(ctx);
			break;
			case HRPC.REQUEST_ADD_GUEST_TO_DOOR:
				handleAddGuestToDoor(ctx, sender);
			break;
		}
	}

	void HandleRPCClient(PlayerIdentity sender, int rpc_type,ParamsReadContext  ctx) 
	{
		switch (rpc_type)
		{
			case HRPC.SEND_HOUSE_DATA:
				handleApplyHouseData(ctx);
			break;
		}
	}

	HouseData GetHouseDataServerByBits(int low, int high)
	{
		for (int i = 0; i < g_HSL.m_GenHosData.HousesData.Count(); i++)
		{
			ref HouseData hd = g_HSL.m_GenHosData.HousesData.Get(i);
			if ( (hd.Low == low) && (hd.High == high) )
			{
				return hd;
			}
		}

		return NULL;
	}

	void handleRequestHouseData(PlayerIdentity sender, ParamsReadContext  ctx)
	{
		Param2<int,int> rpb;
		if (!ctx.Read(rpb)) return;
		ref HouseData hd = GetHouseDataServerByBits(rpb.param1, rpb.param2);
		if (hd)
		{
			this.RPCSingleParam(HRPC.SEND_HOUSE_DATA, new Param1<ref HouseData>(hd), true, sender);
		}
		else
		{
			this.RPCSingleParam(HRPC.SEND_HOUSE_DATA, new Param1<ref HouseData>(null), true, sender);	
		}
	}

	void handleApplyHouseData(ParamsReadContext  ctx)
	{
		Param1<ref HouseData> rpb;
		if (!ctx.Read(rpb)) return;
		m_HouseData = rpb.param1;
		Print(m_HouseData);
	}

	void handleAddHouseInfo(ParamsReadContext  ctx)
	{
		Param1<ref HouseData> rpb;
		if (!ctx.Read(rpb)) return;

		ref HouseData hd = rpb.param1;
		Print(hd);

		int idx = g_HSL.m_GenHosData.HousesData.Find(hd);
		if (idx == -1)
		{
			g_HSL.m_GenHosData.HousesData.Insert(hd);
		}
		else
		{
			g_HSL.m_GenHosData.HousesData[idx] = hd;
		}
		SaveHouseDataServer();
	}

	void handleRequestRentHouse(PlayerIdentity sender, ParamsReadContext  ctx)
	{
		Param2<int,int> rpb;
		if (!ctx.Read(rpb)) return;
		ref HouseData hd = GetHouseDataServerByBits(rpb.param1, rpb.param2);
		if (hd)
		{
			FillRenterInfo(hd, sender);
		}
	}

	void FillRenterInfo(ref HouseData hd, PlayerIdentity sender)
	{
		PlayerBase player = GetPlayerByIdentity(sender);

		if (player)
		{
			hd.MainOwner.Name = player.GetIdentity().GetName();
			//hd.MainOwner.Name = player.GetMultiCharactersPlayerName();
			//hd.MainOwner.MilticharacterID = player.GetMultiCharactersPlayerId().ToString();
			hd.MainOwner.SteamID = player.GetIdentity().GetPlainId();
			hd.MainOwner.HashID = player.GetIdentity().GetId();
			hd.MainOwner.Date = HouseManager.GetBastionDate();
			//hd.MainOwner.BastionClass = player.GetMultiCharactersPlayerClass().ToString();
			//hd.MainOwner.BankAccountId = 0;
			hd.MainOwner.RentTimeLeft = (hd.LeaseTime * 60);
		}
		int idx = g_HSL.m_GenHosData.HousesData.Find(hd);
		if (idx != -1)
		{
			g_HSL.m_GenHosData.HousesData[idx] = hd;
			SaveHouseDataServer();
		}
	}

	void SaveHouseDataServer()
	{
		HouseStorageLoader.SaveData(g_HSL);
	}

	PlayerBase GetPlayerByIdentity(PlayerIdentity sender)
	{
		int	low	 =	0;
		int	high =	0;
		GetGame().GetPlayerNetworkIDByIdentityID( sender.GetPlayerId(), low, high );
		return PlayerBase.Cast( GetGame().GetObjectByNetworkId(low, high ));
	}

	void handleApplySuggestion(PlayerIdentity sender, ParamsReadContext  ctx)
	{
		Param2<int,int> rpb;
		if (!ctx.Read(rpb)) return;
		ref HouseData hd = GetHouseDataServerByBits(rpb.param1, rpb.param2);
		if (hd)
		{
			ref RentSuggestion rs = new RentSuggestion();
			PlayerBase player = GetPlayerByIdentity(sender);
			rs.Name = player.GetIdentity().GetName();
			//rs.Name = player.GetMultiCharactersPlayerName();
			//rs.MilticharacterID = player.GetMultiCharactersPlayerId().ToString();
			rs.SteamID = player.GetIdentity().GetPlainId();
			rs.HashID = player.GetIdentity().GetId();
			rs.Date = HouseManager.GetBastionDate();
			rs.BastionClass = "B";
			rs.Approved = false;
			rs.Checked = false;

			if (!HasDuplicateSuggestion(rs, hd))
			{
				hd.RentSuggestions.Insert(rs);
			}
			SaveHouseDataServer();
		}
	}

	bool HasDuplicateSuggestion(ref RentSuggestion rs, ref HouseData hd)
	{
		return (hd.RentSuggestions.Find(rs) + 1);
	}

	static void DeleteOwnerHouse(HouseData hd)
	{
		for (int i = 0; i < hd.DoorsData.Count(); i++)
		{
			hd.DoorsData.Get(i).Renters.Clear();
			hd.DoorsData.Get(i).RentSuggestions.Clear();
		}
		hd.MainOwner = new HousePersonData;
	}

	void handleEvictPlayer(ParamsReadContext ctx)
	{
		Param4<int, int, int, int> rpb;
		if (!ctx.Read(rpb)) return;
		ref HouseData hd = GetHouseDataServerByBits(rpb.param1, rpb.param2);
		if (hd && hd.DoorsData.Get(rpb.param3).Renters.Get(rpb.param4))
		{
			Print(hd.DoorsData.Get(rpb.param3).Renters.Get(rpb.param4));
			hd.DoorsData.Get(rpb.param3).Renters.Remove(rpb.param4);
			SaveHouseDataServer();
		}
	}

	void handleAddDoorGuest(ParamsReadContext ctx)
	{
		Param4<int, int, int, int> rpb;
		if (!ctx.Read(rpb)) return;
		ref HouseData hd = GetHouseDataServerByBits(rpb.param1, rpb.param2);
		int dIdx = rpb.param3;
		int gIdx = rpb.param4;
		if (hd && hd.DoorsData.Get(dIdx).RentSuggestions.Get(gIdx))
		{
			ref RentSuggestion rs = hd.DoorsData.Get(dIdx).RentSuggestions.Get(gIdx);
			ref HousePersonData hpd = new HousePersonData;
			hpd.Name = rs.Name;
			hpd.MilticharacterID = rs.MilticharacterID;
			hpd.SteamID = rs.SteamID;
			hpd.HashID = rs.HashID;
			hpd.Date = rs.Date
			hpd.BastionClass = rs.BastionClass;
			hd.DoorsData.Get(dIdx).Renters.Insert(hpd);
			hd.DoorsData.Get(dIdx).RentSuggestions.Remove(gIdx);
			SaveHouseDataServer();
		}
	}

	void handleRemoveRequest(ParamsReadContext ctx)
	{
		Param4<int, int, int, int> rpb;
		if (!ctx.Read(rpb)) return;
		ref HouseData hd = GetHouseDataServerByBits(rpb.param1, rpb.param2);
		int dIdx = rpb.param3;
		int gIdx = rpb.param4;
		if (hd && hd.DoorsData.Get(dIdx).RentSuggestions.Get(gIdx))
		{
			hd.DoorsData.Get(dIdx).RentSuggestions.Remove(gIdx);
			SaveHouseDataServer();
		}
	}

	void handleEditDoorInfo(ParamsReadContext ctx)
	{
		Param4<ref HouseDoorData, int, int, int> rpb;
		if (!ctx.Read(rpb)) return;
		ref HouseDoorData tempHdd = rpb.param1;
		int dIdx = rpb.param2;
		ref HouseData hd = GetHouseDataServerByBits(rpb.param3, rpb.param4);
		if (hd && hd.DoorsData.Get(dIdx))
		{
			ref HouseDoorData hdd = hd.DoorsData.Get(dIdx);
			if (hdd)
			{
				hdd.Name = tempHdd.Name;
				hdd.Description = tempHdd.Description;
				hdd.RentPrice = tempHdd.RentPrice;
				hdd.LeaseTime = tempHdd.LeaseTime;
				SaveHouseDataServer();
			}
		}

	}

	void handleAddGuestToDoor(ParamsReadContext  ctx, PlayerIdentity sender)
	{
		Param3<int,int,int> rpb;
		if (!ctx.Read(rpb)) return;
		ref HouseData hd = GetHouseDataServerByBits(rpb.param1, rpb.param2);
		int dIdx = rpb.param3;
		for (int i = 0; i < hd.DoorsData.Count(); i++)
		{
			HouseDoorData hdd = hd.DoorsData.Get(i);
			if (hdd.Index == dIdx)
			{
				PlayerBase player = GetPlayerByIdentity(sender);
				RentSuggestion rs = new RentSuggestion;
				rs.Name = sender.GetName();
				//rs.MilticharacterID
				rs.SteamID = sender.GetPlainId();
				rs.HashID = sender.GetId();
				rs.Date = HouseManager.GetBastionDate();
				//rs.BastionClass
				rs.Approved = false;
				rs.Checked = false;
				hdd.RentSuggestions.Insert(rs);
				SaveHouseDataServer();
			}
		}
	}
}

class Land_House_2B03 : BRP_House {};
class Land_House_2W04 : BRP_House {};
