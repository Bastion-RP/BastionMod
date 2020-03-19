class ActionExchange: ActionInteractBase
{
	private ref BastionBankAccount m_BankingAccount;

    private BST_VendingMachine m_VendingMachine;

	void ActionExchange( )
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_ATTACHITEM;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_HUDCursorIcon = CursorIcons.OpenDoors;
	}
	
	override void CreateConditionComponents( )  
	{	
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTObject(UAMaxDistances.BASEBUILDING);
	}

	override string GetText( )
	{
		return "Exchange";
	}

	override typename GetInputType( )
	{
		return InteractActionInput;
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if ( GetGame().IsMultiplayer( ) )
		{
			if ( GetGame().IsServer( ) )
			{
				m_BankingAccount = GetBankAccountManager().GetAccountByPlayerBase( player );

				if ( !m_BankingAccount )
					return false;
			}
		}

		if ( !Class.CastTo( m_VendingMachine, target.GetObject( ) ) )
			return false;

		return true;
	}
	
	override void OnStartClient( ActionData action_data )
	{
		super.OnStartClient( action_data );

		if ( !GetGame().IsMultiplayer( ) )
		{
			if ( GetGame().IsServer( ) )
			{
				Object obj = action_data.m_Player.GetInventory().CreateInInventory( m_VendingMachine.GetRation() );
				if ( !obj )
				{
					obj = GetGame().CreateObject( m_VendingMachine.GetRation(), action_data.m_Player.GetPosition() );
				}

				NotificationSystem.SendNotificationToPlayerExtended(action_data.m_Player, 5, "AION", "Bought 1 AION for" + m_VendingMachine.GetPrice() + " credits.", "set:dayz_gui image:icon_x");
			}
		}
	}
	
	override void OnStartServer( ActionData action_data )
	{
		super.OnStartServer( action_data );

		if ( GetGame().IsMultiplayer( ) )
		{
			if ( GetGame().IsServer( ) )
			{
				m_BankingAccount = GetBankAccountManager().GetAccountByPlayerBase( action_data.m_Player );

				if ( !m_BankingAccount )
					return;
			}
		}

		Object obj = action_data.m_Player.GetInventory().CreateInInventory( m_VendingMachine.GetRation() );
		if ( !obj )
		{
			obj = GetGame().CreateObject( m_VendingMachine.GetRation(), action_data.m_Player.GetPosition() );
		}

		NotificationSystem.SendNotificationToPlayerExtended(action_data.m_Player, 5, "AION", "Bought 1 AION for" + m_VendingMachine.GetPrice() + " credits.", "set:dayz_gui image:icon_x");
	}
}

