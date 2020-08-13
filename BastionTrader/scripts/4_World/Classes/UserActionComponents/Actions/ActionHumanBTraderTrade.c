class ActionHumanBTraderTrade : ActionInteractBase
{
	private int traderId;

	void ActionHumanBTraderTrade()
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
		m_ConditionTarget = new CCTMan(5);
		m_ConditionItem = new CCINone;
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		PlayerBase trader = PlayerBase.Cast(  target.GetObject() );

		if(trader && (trader.GetTraderId() > 0))
		{
			traderId = trader.GetTraderId();
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