class ActionTakeBodyBagKit: ActionInteractBase
{
	string m_ToolTipText;
	void ActionTakeBodyBagKit()
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
		return "Take Body Bag Kit";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if( !target ) return false;

		if(!IsInReach(player, target, UAMaxDistances.DEFAULT)) return false;
		
		BRP_CartonBox_BodyBagKits box = BRP_CartonBox_BodyBagKits.Cast(target.GetObject());		
		if(box)
			return true;

		return false;
	}

	override void OnStartServer( ActionData action_data )
	{		
		vector playerPos = action_data.m_Player.GetPosition();
		EntityAI item;
		BRP_CartonBox_BodyBagKits box = BRP_CartonBox_BodyBagKits.Cast(action_data.m_Target.GetObject());
		if(box)
		    item = EntityAI.Cast(GetGame().CreateObject(BastionBodyBagConst.bodyBagKitItem, playerPos));

		if(item)
		{
            if ( !GetGame().IsMultiplayer() )
            {
                action_data.m_Player.PredictiveTakeEntityToHands(item);
            }
            else
            {
                action_data.m_Player.ServerTakeEntityToHands(item);
            }
		}
	}
};