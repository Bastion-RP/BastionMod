class ActionExchange: ActionInteractBase
{
	private int m_Ammount;

	private ref array< ItemBase > m_Items;

	private ref BastionBankAccount m_BankingAccount;

    private BST_VendingMachine m_VendingMachine;

	void ActionExchange( )
	{
		m_Items = new ref array< ItemBase >;

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
				Print("ActionCondition::1");

				m_BankingAccount = GetBankAccountManager().GetAccountByPlayerBase( player );

				Print("ActionCondition::2 " + m_BankingAccount);

				if ( !m_BankingAccount )
					return false;

				Print("ActionCondition::3");

				if ( m_BankingAccount.GetFunds() < m_VendingMachine.GetPrice() )
				{
					Print("ActionCondition::4");
					
					NotificationSystem.SendNotificationToPlayerExtended(player, 5, "AION", "You don't have enough funds to complete the purchase", "set:dayz_gui image:icon_x");
					return false;
				}
			}
		}

		Print("ActionCondition::5");

		if ( !Class.CastTo( m_VendingMachine, target.GetObject( ) ) )
			return false;

		Print("ActionCondition::6");

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

				NotificationSystem.SendNotificationToPlayerExtended(action_data.m_Player, 5, "AION", "Purchased 1 AION for " + m_VendingMachine.GetPrice() + " credits.", "set:dayz_gui image:iconHungry0");
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
				Print("OnStartServer::1");

				m_Items.Clear();

				m_BankingAccount = GetBankAccountManager().GetAccountByPlayerBase( action_data.m_Player );
				
				Print("OnStartServer::2 " + m_BankingAccount);

				if ( !m_BankingAccount )
					return;

				Print("OnStartServer::3");

				if ( GetBankManager().CanDeposit( action_data.m_Player, m_VendingMachine.GetPrice(), m_Items, m_Ammount ) )
				{
					Print("OnStartServer::4::I");

					GetBankManager().RemoveCurrency( m_Items, m_VendingMachine.GetPrice() );
				}
				else
				{
					Print("OnStartServer::4::E");

					NotificationSystem.SendNotificationToPlayerExtended(action_data.m_Player, 5, "AION", "You don't have enough funds to complete the purchase", "set:dayz_gui image:icon_x");
					return;
				}
			}
		}

		Print("OnStartServer::5");

		Object obj = action_data.m_Player.GetInventory().CreateInInventory( m_VendingMachine.GetRation() );
		if ( !obj )
		{
			Print("OnStartServer::6");

			obj = GetGame().CreateObject( m_VendingMachine.GetRation(), action_data.m_Player.GetPosition() );
		}

		Print("OnStartServer::7");

		NotificationSystem.SendNotificationToPlayerExtended(action_data.m_Player, 5, "AION", "Purchased 1 AION for " + m_VendingMachine.GetPrice() + " credits.", "set:dayz_gui image:iconHungry0");
	}
}

