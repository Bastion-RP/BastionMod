class ActionRemoteAdminManageHouses : ActionInteractBase
{
	string ID = "";
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

	// override typename GetInputType()
	// {
	// 	return ContinuousInteractActionInput;
	// }

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
			Barrel_ColorBase barrel;
			if( Class.CastTo(barrel, target.GetObject()) ) //TODO: change to terminal
			{
				string plId = player.GetIdentity().GetId();
				type = -1;
				if (barrel && ((g_HM.AdminsArr.Find(player.GetIdentity().GetId()) + 1)))
				{
					ID = "Remote Admin Manage building.";
					type = 5;
				}
				return true;
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