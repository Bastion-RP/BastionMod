class HouseManager
{
	ref array<string> 		AdminsArr;
	BRP_House				m_House;
	ref HousingHud			m_HousingHud;
	private bool			HudIsOpen;
	int						m_DoorsCount;
	ref array<ref BstNot>	BstNotifications;

	Widget					m_BstNotStg;

	void HouseManager()
	{
		AdminsArr 			= new array<string>();
		m_DoorsCount 		= 0;
		HudIsOpen	 		= false;
		BstNotifications	= new array<ref BstNot>();
	}

	void OnRPC(PlayerIdentity sender, int rpc_type,ParamsReadContext  ctx)
	{
		switch (rpc_type)
		{
			case HRPC.SEND_ADMINS_ID:
				handleApplyAminsIDS(ctx);
			break;
		}
	}

	void handleApplyAminsIDS(ParamsReadContext  ctx)
	{
		Param1<ref array<string>> rpb;
		if (!ctx.Read(rpb)) return;
		AdminsArr = rpb.param1;
	}

	void OnKeyPress(int key)
	{
		switch (key)
        {
            case KeyCode.KC_ESCAPE:
				CloseMenu();
            break;
        }
	}

	void SetBuilding(BRP_House val)
	{
		m_House = val;
	}

	void RequestManageBuilding(int type, int dIdx = -1)
	{
		if (m_HousingHud || GetGame().GetUIManager().GetMenu()) return;
		GetGame().GetMission().GetHud().ShowQuickbarUI( false );
        m_HousingHud = new HousingHud(type, dIdx);
        GetGame().GetUIManager().ShowScriptedMenu( m_HousingHud, NULL );
		HudIsOpen = true;
	}

	void CloseMenu()
	{
		if ( GetGame().GetUIManager().GetMenu() && m_HousingHud)
		{
			HudIsOpen = false;
			GetGame().GetUIManager().Back();
			GetGame().GetMission().GetHud().ShowQuickbarUI( true );
		}
	}

	bool GetHudIsOpen()
	{
		return HudIsOpen;
	}

	static void SelfChatMessage( string message )
	{ 
        GetGame().GetMission().OnEvent(ChatMessageEventTypeID, new ChatMessageEventParams(0, "", message, "")); 
    }

	void TryRentBuilding()
	{
		int low,high;
		m_House.GetNetworkID( low, high );
		// проверка хватает ли денег
		m_House.RPCSingleParam(HRPC.REQUEST_RENT_HOUSE, new Param2<int,int>(low, high), true, NULL);
		CloseMenu();
	}

	bool IsDoorHaveOwner(PlayerBase player, BRP_House building, int doorIndex)
	{
		for (int i = 0; i < building.m_HouseData.GroupsData.Count(); i++)
		{
			HouseGroupData hdd = building.m_HouseData.GroupsData.Get(i);
			if ((hdd.Indexes.Find(doorIndex) + 1) )
			{
				for (int j = 0; j < hdd.Renters.Count(); j++)
				{
					if (hdd.Renters[j].HashID)
					{return true;}
				}
			}
		}
		return false;
	}

	bool IsDoorOwner(PlayerBase player, BRP_House building, int doorIndex)
	{
		string pId = player.GetIdentity().GetId();// TODO change to milticharID
		for (int i = 0; i < building.m_HouseData.GroupsData.Count(); i++)
		{
			HouseGroupData hdd = building.m_HouseData.GroupsData.Get(i);
			if ((hdd.Indexes.Find(doorIndex) + 1) )
			{
				for (int j = 0; j < hdd.Renters.Count(); j++)
				{
					if (pId == hdd.Renters[j].HashID)
					{
						return true;
					}
				}
			}
		}
		return false;
	}

	bool IsDoorAllow(int idx, BRP_House building)
	{
		HouseData hd = building.m_HouseData;
		if ((hd.AllowDoors.Find(idx) + 1))
		{return true;}
		return false;
	}

	void SendHouseRentRequest()
	{
		if (m_House)
		{
			int low,high;
			m_House.GetNetworkID(low,high);
			m_House.RPCSingleParam(HRPC.REQUEST_APPROVAL_LEASE, new Param2<int,int>(low,high), true, NULL);
		}
	}

	void RequestEvictPlayer(int dIdx, int gIdx)
	{
		int low,high;
		m_House.GetNetworkID(low,high);
		m_House.RPCSingleParam(HRPC.REQUEST_EVICT_PLAYER, new Param4<int, int, int, int>(low, high, dIdx, gIdx), true, NULL);
	}

	void RequestAddGuestToDoor(int dIdx, int gIdx)
	{
		int low,high;
		m_House.GetNetworkID(low,high);
		m_House.RPCSingleParam(HRPC.REQUEST_ADD_DOOR_GUEST, new Param4<int, int, int, int>(low, high, dIdx, gIdx), true, NULL);
	}

	void LocalAddGuest(int dIdx, int gIdx)
	{
		HouseData hd = m_House.m_HouseData;
		if (hd.GroupsData.Get(dIdx).RentSuggestions.Get(gIdx))
		{
			ref RentSuggestion rs = hd.GroupsData.Get(dIdx).RentSuggestions.Get(gIdx);
			ref HousePersonData hpd = new HousePersonData;
			hpd.Name = rs.Name;
			hpd.MilticharacterID = rs.MilticharacterID;
			hpd.SteamID = rs.SteamID;
			hpd.HashID = rs.HashID;
			hpd.Date = rs.Date
			hpd.BastionClass = rs.BastionClass;
			hd.GroupsData.Get(dIdx).Renters.Insert(hpd);
			hd.GroupsData.Get(dIdx).RentSuggestions.Remove(gIdx);
		}
	}

	void RequestRemoveRequest(int dIdx, int gIdx)
	{
		HouseData hd = m_House.m_HouseData;
		if (hd.GroupsData.Get(dIdx).RentSuggestions.Get(gIdx))
		{
			hd.GroupsData.Get(dIdx).RentSuggestions.Remove(gIdx);
			int low,high;
			m_House.GetNetworkID(low,high);
			m_House.RPCSingleParam(HRPC.REQUEST_REMOVE_REQUEST, new Param4<int, int, int, int>(low, high, dIdx, gIdx), true, NULL);
		}
	}

	static string GetBastionDate()
	{
		string temp;
		int year, month, day;
		GetYearMonthDay(year, month, day);
		temp = day.ToString() + "/" + month.ToString() + "/" + (year + 20).ToString();
		return temp;
	}

	void SaveDoorInfo(ref HouseGroupData hdd, int dIdx)
	{
		int low, high;
		m_House.GetNetworkID(low,high);
		m_House.RPCSingleParam(HRPC.REQUEST_EDIT_DOOR_INFO, new Param4<ref HouseGroupData, int, int, int>(hdd, dIdx, low, high), true, NULL);
	}

	static void CalcRightHeight(Widget w, int len)
	{
		float width, height;
		w.GetSize(width, height);
		height = ((len / 70 + 1) * height);
		w.SetSize(width, height);
	}

	void SendRequestGroup(int dIdx)
	{
		int low, high;
		m_House.GetNetworkID(low,high);
		m_House.RPCSingleParam(HRPC.REQUEST_ADD_GUEST_TO_DOOR, new Param3<int, int, int>(low, high, dIdx), true, NULL);
	}

	void RequestCancelLease()
	{
		int low, high;
		m_House.GetNetworkID(low,high);
		m_House.RPCSingleParam(HRPC.REQUEST_CANCEL_LEASE, new Param2<int,int>(low,high), true, NULL);
	}

	bool HasDuplicateSuggestion(string HashID, ref array<ref RentSuggestion> RentSuggestions)
	{
		for (int i = 0; i < RentSuggestions.Count(); i++)
		{
			if (HashID == RentSuggestions.Get(i).HashID)
			{return true;}
		}
		return false;
	}

	Widget GetBstNotStg()
	{
		if (!m_BstNotStg)
		{
			m_BstNotStg = GetGame().GetWorkspace().CreateWidgets("BastionMod/BastionHousingSystem/layouts/BastNotStg.layout");
		}
		return m_BstNotStg;
	}

	void ShowBastionNotification(string text)
	{
		new BstNot(text);
	}

	void RequestAddNewGroup(ref HouseGroupData data, ref array<int> idxs)
	{
		int low, high;
		m_House.GetNetworkID(low,high);
		m_House.RPCSingleParam(HRPC.REQUEST_ADD_NEW_GROUP, new Param4<int,int, ref HouseGroupData, ref array<int>>(low,high,data,idxs), true, NULL);
	}

	array<int> GetFreeDoors(HouseData hd)
	{
		ref array<int> result = hd.AllowDoors;
		for (int i = 0; i < hd.GroupsData.Count(); i++)
		{
			HouseGroupData hgd = hd.GroupsData.Get(i);

			for (int j = 0; j < hgd.Indexes.Count(); j++)
			{
				int idx = result.Find(hgd.Indexes.Get(j));
				if (idx >= 0) result.Remove(idx);
			}
		}
		return result;
	}

	int GetGroupIdxByDoorIndex(int dIdx)
	{
		for (int i = 0; i < m_House.m_HouseData.GroupsData.Count(); i++)
		{
			HouseGroupData hgd = m_House.m_HouseData.GroupsData.Get(i);
			if ((hgd.Indexes.Find(dIdx)+1))
			{return i;}
		}
		return -1;
	}

	void RequestEditGroupInfo(ref HouseGroupData data, int gIdx)
	{
		int low, high;
		m_House.GetNetworkID(low,high);
		m_House.RPCSingleParam(HRPC.REQUEST_EDIT_GROUP_INFO, new Param4<int,int,ref HouseGroupData,int>(low,high,data,gIdx), true, NULL);
	}

	void RequestRemoveGroup(int gIdx)
	{
		int low, high;
		m_House.GetNetworkID(low,high);
		m_House.RPCSingleParam(HRPC.REQUEST_DELETE_GROUP, new Param3<int,int,int>(low,high,gIdx), true, NULL);
	}
}
ref HouseManager g_HM;