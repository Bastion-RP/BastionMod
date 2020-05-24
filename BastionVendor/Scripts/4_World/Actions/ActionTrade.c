class ActionTrade: ActionInteractBase
{
	private BRP_VendingMachine_Base m_TraderBase;
	private Trader m_Trader;

	void ActionTrade()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_ATTACHITEM;
	}
	
	override void CreateConditionComponents()  
	{	
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTObject(UAMaxDistances.BASEBUILDING);
	}

	override string GetText()
	{
		return "Trade";
	}

	override typename GetInputType()
	{
		return InteractActionInput;
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if ( !Class.CastTo( m_TraderBase, target.GetObject() ) )
			return false;

		if ( !Class.CastTo( m_Trader, GetTrader() ) )
			return false;

		//if ( !m_Trader.CanOpenTraderMenu() )
		//	return false;

		return true;
	}
	
	override void OnStartClient( ActionData action_data )
	{
		super.OnStartClient( action_data );

		m_Trader.ShowUI(m_TraderBase);
	}
	
	override void OnStartServer( ActionData action_data )
	{
		super.OnStartServer( action_data );

		if ( !GetGame().IsMultiplayer() )
		{
			m_Trader.ShowUI(m_TraderBase);
		}

		// m_Trader.LoadTraderData( m_TraderBase, action_data.m_Player.GetIdentity() );
	}
}