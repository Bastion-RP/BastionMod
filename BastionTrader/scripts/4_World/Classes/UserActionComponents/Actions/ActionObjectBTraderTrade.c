class ActionObjectBTraderTrade : ActionInteractBase
{
	private int traderId;

	void ActionObjectBTraderTrade()
	{
		traderId = -1;

		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_HUDCursorIcon = CursorIcons.LootCorpse;
	}

	override string GetText()
	{
		return "Trade";
	}

	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTObject(UAMaxDistances.DEFAULT);
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		BuildingBase traderObj = BuildingBase.Cast( target.GetObject() );
		if (traderObj && (traderObj.GetTraderId() > 0) )
		{
			traderId = traderObj.GetTraderId();
			return true;
		}
		return false;
	}
	
	override void OnExecuteClient( ActionData action_data )
	{
		//PlayerBase ntarget = PlayerBase.Cast( action_data.m_Target.GetObject() );
		GetBTraderManager().TradeInteract(traderId);
	}

}