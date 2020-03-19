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

	}

	override typename GetInputType( )
	{
		return InteractActionInput;
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		m_BankingAccount = GetBankAccountManager().GetAccountByPlayerBase( player );

		Print("1 " + GetBankAccountManager() );

		if ( !m_BankingAccount )
			return false;

		Print("2 ");

		if ( !Class.CastTo( m_VendingMachine, target.GetObject( ) ) )
			return false;

		Print("3 ");

		return true;
	}
	
	override void OnStartClient( ActionData action_data )
	{
		super.OnStartClient( action_data );
	}
	
	override void OnStartServer( ActionData action_data )
	{
		super.OnStartServer( action_data );
	}
}

