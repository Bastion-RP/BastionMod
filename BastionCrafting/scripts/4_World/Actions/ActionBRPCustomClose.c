class ActionBRPCustomClose: ActionInteractBase
{
	void ActionBRPCustomClose()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_OPENDOORFW;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_HUDCursorIcon = CursorIcons.CloseDoors;
	}

	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTNone;
	}

	override string GetText()
	{
		return "#close";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if( !target ) return false;

		if(!IsInReach(player, target, UAMaxDistances.DEFAULT)) return false;
		
		BRP_Openable_Base openable = BRP_Openable_Base.Cast(target.GetObject());
		if(openable)			
			return openable.IsOpen();
		/* 
		BRP_Greenhouse greenhouse = BRP_Greenhouse.Cast(target.GetObject());
		string selection = target.GetObject().GetActionComponentName(target.GetComponentIndex());
		if(greenhouse && selection && selection == "doors1")
			return greenhouse.IsOpen(); */
			
		return false;
	}

	override void OnStartServer( ActionData action_data )
	{
		BRP_Openable_Base openable = BRP_Openable_Base.Cast(action_data.m_Target.GetObject());
		if(openable)
			openable.Close();
	}
};