class ActionRemoteAdminManageHouses : ActionInteractBase
{
	string ID;
	int type = -1;

	void ActionRemoteAdminManageHouses()
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
		if (GetGame().IsClient())
		{
			if (target.GetObject() && BRP_ATM.Cast(target.GetObject()))
			{
				string plId = player.GetMultiCharactersPlayerId().ToString();
				type = -1;
				if ((g_HM.AdminsArr.Find(plId) + 1))
				{
					ID = "Remote Admin Manage building";
					type = 4;
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
		g_HM.RequestManageBuilding(type, -1);
		
	}
};