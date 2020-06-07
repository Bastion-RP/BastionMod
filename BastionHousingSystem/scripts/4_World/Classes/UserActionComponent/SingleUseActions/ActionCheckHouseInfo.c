class ActionShowDoorInfo : ActionInteractBase
{
	string ID = "-1";
	int type = -1;
	int doorIndex;

	void ActionShowDoorIndex()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_OPENDOORFW;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_HUDCursorIcon = CursorIcons.OpenDoors;
	}

	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTNone;
	}

	override typename GetInputType()
	{
		return ContinuousInteractActionInput;
	}

	override string GetText()
	{
		return ID;
	}

	override bool HasProgress()
	{
		return false;
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if( !target ) return false;
		if( !IsBuilding(target) ) return false;

		if (GetGame().IsClient())
		{
			BRP_House building;
			if( Class.CastTo(building, target.GetObject()) )
			{
				doorIndex = building.GetDoorIndex(target.GetComponentIndex());
				string plId = player.GetIdentity().GetId();
				if ( doorIndex != -1 ) // add check owner
				{
					if (player.CanSyncHouseData() /*&& !g_HM.GetHudIsOpen()*/)
					{
						building.RequestHouseData();
						player.SetSyncHouseData();
					}
					ID = "Door Id : ["+doorIndex.ToString()+"]";
					type = -1;
					if (!building.m_HouseData && ((g_HM.AdminsArr.Find(player.GetIdentity().GetId()) + 1)))
					{
						ID += " Admin Manage building.";
						type = 0;
					}
					else if (building.m_HouseData && !building.m_HouseData.MainOwner.HashID && g_HM.IsDoorAllow(doorIndex, building))
					{
						ID += " Show rental conditions.";
						type = 1;
					}
					else if (building.m_HouseData && building.m_HouseData.MainOwner.HashID == plId && g_HM.IsDoorAllow(doorIndex, building))
					{
						ID += " Show info.";
						type = 2;
					}
					else if (building.m_HouseData && building.m_HouseData.MainOwner.HashID && g_HM.IsDoorAllow(doorIndex, building))
					{
						ID += " Show rent info.";
						type = 3;
					}
					return true;
				}
			}
			return false;
		}
		return true;
	}
	
	override void OnEndClient( ActionData action_data  )
	{
		if (type == -1) return;
		BRP_House building;
		if( Class.CastTo(building, action_data.m_Target.GetObject()) )
		{
			g_HM.SetBuilding(building);
			g_HM.RequestManageBuilding(type, doorIndex);
		}
	}
};