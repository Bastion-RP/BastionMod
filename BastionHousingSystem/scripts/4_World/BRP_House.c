class BRP_House extends Building
{
	ref HouseData					m_HouseData;
	private int 					low, high;
	private int						m_DoorsCount;
	static ref array<ref BRP_House> Houses = new array<ref BRP_House>();
	
	void BRP_House()
	{
		Houses.Insert(this);
		m_DoorsCount = 0;
		GetNetworkID(low, high);
		//Print("low:"+low.ToString()+" | high:"+high.ToString()+ " | loaded after "+GetGame().GetTickTime().ToString());
		GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( CloseAllDoors, 1000, false);


		if (GetGame().IsServer())
		{
			if (!g_HSL)
			{
				g_HSL	= new HouseStorageLoader();
				//g_HSL	= HouseStorageLoader.LoadData();
			}
			GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( InitHouse, 5000, false);
			//Init();
		}
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
				m_DoorsCount++;
				// if (GetGame().IsServer())
				// {this.CloseDoor(doorIndex);}
			}
		}
	}

	void InitHouse()
	{
		HouseData hd = GetHouseDataServerByBits(low, high);
		if (hd) return;
		hd = new HouseData;
		hd.Low = low;
		hd.High = high;
		hd.BuldingName = this.GetType();
		hd.BuildingPos = this.GetPosition().ToString();
		hd.BuildingType = this.GetType();
		hd.TotalDoors = this.m_DoorsCount;
		hd.BuildingSector = -1;
		g_HSL.m_GenHosData.HousesData.Insert(hd);
		SaveHouseDataServer(hd);
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
				handleAddGuestToGroup(ctx, sender);
			break;
			case HRPC.REQUEST_CANCEL_LEASE:
				handleCancelLease(ctx);
			break;
			case HRPC.REQUEST_ADD_NEW_GROUP:
				handleAddNewGroup(ctx);
			break;
			case HRPC.REQUEST_EDIT_GROUP_INFO:
				handleSaveGroupEditInfo(ctx);
			break;
			case HRPC.REQUEST_DELETE_GROUP:
				handleDeleteGroup(ctx);
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
		// else
		// {
		// 	this.RPCSingleParam(HRPC.SEND_HOUSE_DATA, new Param1<ref HouseData>(null), true, sender);	
		// }
	}

	void handleApplyHouseData(ParamsReadContext  ctx)
	{
		Param1<ref HouseData> rpb;
		if (!ctx.Read(rpb)) return;
		m_HouseData = rpb.param1;
		Print(m_HouseData);
	}

	void handleAddHouseInfo(ParamsReadContext ctx)
	{
		Param1<ref HouseData> rpb;
		if (!ctx.Read(rpb)) return;

		ref HouseData hd = rpb.param1;
		bool isNew = true;
		for (int i = 0; i < g_HSL.m_GenHosData.HousesData.Count(); i++)
		{
			if (hd.BuildingPos == g_HSL.m_GenHosData.HousesData.Get(i).BuildingPos)
			{
				g_HSL.m_GenHosData.HousesData[i] = hd;
				isNew = false;
				break;
			}
		}
		if (isNew)
		{
			g_HSL.m_GenHosData.HousesData.Insert(hd);
		}
		SaveHouseDataServer(hd);
	}

	void handleRequestRentHouse(PlayerIdentity sender, ParamsReadContext  ctx)
	{
		Param2<int,int> rpb;
		if (!ctx.Read(rpb)) return;
		ref HouseData hd = GetHouseDataServerByBits(rpb.param1, rpb.param2);
		if (hd && !hd.MainOwner.Name)
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
			hd.MainOwner.SteamID = sender.GetPlainId();
			hd.MainOwner.HashID = sender.GetId();
			hd.MainOwner.Date = HouseManager.GetBastionDate();
			//hd.MainOwner.BastionClass = player.GetMultiCharactersPlayerClass().ToString();
			//hd.MainOwner.BankAccountId = 0;
			hd.MainOwner.RentTimeLeft = (hd.LeaseTime * 60);
		}
		int idx = g_HSL.m_GenHosData.HousesData.Find(hd);
		if (idx != -1)
		{
			g_HSL.m_GenHosData.HousesData[idx] = hd;
			SaveHouseDataServer(hd);
		}
	}

	void SaveHouseDataServer(HouseData hd)
	{
		g_HSL.SaveData(hd);
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
			rs.Name = sender.GetName();
			//rs.Name = player.GetMultiCharactersPlayerName();
			//rs.MilticharacterID = player.GetMultiCharactersPlayerId().ToString();
			rs.SteamID = sender.GetPlainId();
			rs.HashID = sender.GetId();
			rs.Date = HouseManager.GetBastionDate();
			rs.BastionClass = "B";
			rs.Approved = false;
			rs.Checked = false;

			if (!HasDuplicateSuggestion(rs, hd))
			{
				hd.RentSuggestions.Insert(rs);
				SaveHouseDataServer(hd);
			}
		}
	}

	bool HasDuplicateSuggestion(ref RentSuggestion rs, ref HouseData hd = null, ref HouseGroupData hdd = null)
	{
		if (hd)
		{
			for (int i = 0; i < hd.RentSuggestions.Count(); i++)
			{
				RentSuggestion Rs = hd.RentSuggestions.Get(i);
				if (rs.HashID == Rs.HashID) // TODO: change for multicharID
				{return true;}
			}
			return false;
		}
		else if (hdd)
		{
			for (int j = 0; j < hdd.RentSuggestions.Count(); j++)
			{
				RentSuggestion RRs = hdd.RentSuggestions.Get(j);
				if (rs.HashID == RRs.HashID) // TODO: change for multicharID
				{return true;}
			}
			return false;
		}
		else
		{
			return false;
		}
	}

	bool IsGuestAlreadyOwnerDoor(array<ref HousePersonData> Renters, ref RentSuggestion rs)
	{
		for (int i = 0; i < Renters.Count(); i++)
		{
			if (rs.HashID == Renters.Get(i).HashID)
			{return true;}
		}
		return false;
	}


	static void DeleteOwnerHouse(HouseData hd)
	{
		for (int i = 0; i < hd.GroupsData.Count(); i++)
		{
			hd.GroupsData.Get(i).Renters.Clear();
			hd.GroupsData.Get(i).RentSuggestions.Clear();
		}
		hd.MainOwner = new HousePersonData;
	}

	void handleEvictPlayer(ParamsReadContext ctx)
	{
		Param4<int, int, int, int> rpb;
		if (!ctx.Read(rpb)) return;
		ref HouseData hd = GetHouseDataServerByBits(rpb.param1, rpb.param2);
		if (hd && hd.GroupsData.Get(rpb.param3).Renters.Get(rpb.param4))
		{
			Print(hd.GroupsData.Get(rpb.param3).Renters.Get(rpb.param4));
			hd.GroupsData.Get(rpb.param3).Renters.Remove(rpb.param4);
			SaveHouseDataServer(hd);
		}
	}

	void handleAddDoorGuest(ParamsReadContext ctx)
	{
		Param4<int, int, int, int> rpb;
		if (!ctx.Read(rpb)) return;
		ref HouseData hd = GetHouseDataServerByBits(rpb.param1, rpb.param2);
		int dIdx = rpb.param3;
		int gIdx = rpb.param4;
		if (hd && hd.GroupsData.Get(dIdx).RentSuggestions.Get(gIdx))
		{
			ref RentSuggestion rs = hd.GroupsData.Get(dIdx).RentSuggestions.Get(gIdx);
			ref HousePersonData hpd = new HousePersonData;
			hpd.Name = rs.Name;
			hpd.MilticharacterID = rs.MilticharacterID;
			hpd.SteamID = rs.SteamID;
			hpd.HashID = rs.HashID;
			hpd.Date = rs.Date
			hpd.BastionClass = rs.BastionClass;
			if (!IsGuestAlreadyOwnerDoor(hd.GroupsData.Get(dIdx).Renters, rs))
			{
				hd.GroupsData.Get(dIdx).Renters.Insert(hpd);
			}
			hd.GroupsData.Get(dIdx).RentSuggestions.Remove(gIdx);
			SaveHouseDataServer(hd);
		}
	}

	void handleRemoveRequest(ParamsReadContext ctx)
	{
		Param4<int, int, int, int> rpb;
		if (!ctx.Read(rpb)) return;
		ref HouseData hd = GetHouseDataServerByBits(rpb.param1, rpb.param2);
		int dIdx = rpb.param3;
		int gIdx = rpb.param4;
		if (hd && hd.GroupsData.Get(dIdx).RentSuggestions.Get(gIdx))
		{
			hd.GroupsData.Get(dIdx).RentSuggestions.Remove(gIdx);
			SaveHouseDataServer(hd);
		}
	}

	void handleEditDoorInfo(ParamsReadContext ctx)
	{
		Param4<ref HouseGroupData, int, int, int> rpb;
		if (!ctx.Read(rpb)) return;
		ref HouseGroupData tempHdd = rpb.param1;
		int dIdx = rpb.param2;
		ref HouseData hd = GetHouseDataServerByBits(rpb.param3, rpb.param4);
		if (hd && hd.GroupsData.Get(dIdx))
		{
			ref HouseGroupData hdd = hd.GroupsData.Get(dIdx);
			if (hdd)
			{
				hdd.Name = tempHdd.Name;
				hdd.Description = tempHdd.Description;
				hdd.RentPrice = tempHdd.RentPrice;
				hdd.LeaseTime = tempHdd.LeaseTime;
				SaveHouseDataServer(hd);
			}
		}

	}

	void handleAddGuestToGroup(ParamsReadContext  ctx, PlayerIdentity sender)
	{
		Param3<int,int,int> rpb;
		if (!ctx.Read(rpb)) return;
		ref HouseData hd = GetHouseDataServerByBits(rpb.param1, rpb.param2);
		int dIdx = rpb.param3;
		for (int i = 0; i < hd.GroupsData.Count(); i++)
		{
			ref HouseGroupData hdd = hd.GroupsData.Get(i);
			if (hdd.Indexes.Find(dIdx) + 1)
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
				if (!HasDuplicateSuggestion(rs, null, hdd))
				{
					hdd.RentSuggestions.Insert(rs);
					SaveHouseDataServer(hd);
				}
			}
		}
	}

	void handleCancelLease(ParamsReadContext  ctx)
	{
		Param2<int,int> rpb;
		if (!ctx.Read(rpb)) return;
		ref HouseData hd = GetHouseDataServerByBits(rpb.param1, rpb.param2);
		if (hd)
		{
			DeleteOwnerHouse(hd);
		}
	}

	void handleAddNewGroup(ParamsReadContext  ctx)
	{
		Param4<int, int, ref HouseGroupData, ref array<int>> rpb;
		if (!ctx.Read(rpb)) return;
		ref HouseGroupData hdd = rpb.param3;
		ref array<int> idxs = rpb.param4;
		ref HouseData hd = GetHouseDataServerByBits(rpb.param1, rpb.param2);
		if (hd)
		{
			HouseGroupData tHdd = new HouseGroupData;
			tHdd.Name = hdd.Name;
			tHdd.RentPrice = hdd.RentPrice;
			tHdd.LeaseTime = hdd.LeaseTime;
			tHdd.Description = hdd.Description;
			tHdd.Indexes = idxs;
			hd.GroupsData.Insert(tHdd);
			SaveHouseDataServer(hd);
		}
	}

	void handleSaveGroupEditInfo(ParamsReadContext  ctx)
	{
		Param4<int, int, ref HouseGroupData, int> rpb;
		if (!ctx.Read(rpb)) return;
		ref HouseData hd = GetHouseDataServerByBits(rpb.param1, rpb.param2);
		ref HouseGroupData data = rpb.param3;
		if (hd)
		{
			HouseGroupData hgd = hd.GroupsData.Get(rpb.param4);
			if (!hgd)
			{
				Print("BastionHousing::BRP_HOUSE::handleSaveGroupEditInfo ERROR, group data is corrupted!");
				return;
			}
			hgd.Name = data.Name;
			hgd.RentPrice = data.RentPrice;
			hgd.LeaseTime = data.LeaseTime;
			hgd.Description = data.Description;
			hgd.Indexes = data.Indexes;
			SaveHouseDataServer(hd);
		}
	}

	void handleDeleteGroup(ParamsReadContext  ctx)
	{
		Param3<int, int, int> rpb;
		if (!ctx.Read(rpb)) return;
		ref HouseData hd = GetHouseDataServerByBits(rpb.param1, rpb.param2);
		if (hd)
		{
			if (!hd.GroupsData.Get(rpb.param3))
			{
				Print("BastionHousing::BRP_HOUSE::handleSaveGroupEditInfo ERROR, group data is corrupted!");
				return;
			}
			hd.GroupsData.Remove(rpb.param3);
			SaveHouseDataServer(hd);
		}
	}
}

class Land_House_2B03 : BRP_House {};
class Land_House_2W04 : BRP_House {};
class Land_Tenement_Big : BRP_House {};
class Land_Tenement_Small : BRP_House {};


//E:\Games\Steam\steamapps\common\DayZServer\@Bastion\Addons