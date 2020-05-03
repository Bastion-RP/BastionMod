class ActionExchange: ActionInteractBase
{
	private int m_Ammount;

    private BRP_AionVendor m_VendingMachine;

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
		return "Buy AION";
	}

	override typename GetInputType( )
	{
		return InteractActionInput;
	}

    protected void GetCurrencyItems( out array<ItemBase> currencies, PlayerBase player )
    {
        array< EntityAI > items = new array< EntityAI >;
	   	player.GetInventory().EnumerateInventory( InventoryTraversalType.PREORDER, items );

        foreach ( auto item : items )
        {
            ItemBase currency = ItemBase.Cast(item);
            if (currency)
            {
                string type = currency.GetType();
                type.ToLower();
                if (type == GetBBankConfig().GetConfig().GetCurrencyClassName())
                {
                    currencies.Insert( currency );
                }
            }
        }
    }

	protected int GetPlayersBalance( PlayerBase player )
    {
        int balance = 0;

        array< ItemBase > currencies = new array< ItemBase >;
        GetCurrencyItems( currencies, player );

        foreach ( auto item : currencies )
		{
            balance += item.GetQuantity();
        }

        return balance;
    }
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if ( !Class.CastTo( m_VendingMachine, target.GetObject( ) ) )
			return false;

		return true;
	}
	
	override void OnStartServer( ActionData action_data )
	{
		super.OnStartServer( action_data );
        if ( !m_VendingMachine )
        {
            m_VendingMachine = BRP_AionVendor.Cast( action_data.m_Target.GetObject() );
        }

		int price = m_VendingMachine.GetPrice();
        int balance = GetPlayersBalance(action_data.m_Player);
		if ( balance < price )
		{
			NotificationSystem.SendNotificationToPlayerExtended(action_data.m_Player, 5, "AION", "You don't have enough credits (" + price + " needed!).", "set:dayz_gui image:icon_x");
			return;
		}

        if (price < 0)
        {
            NotificationSystem.SendNotificationToPlayerExtended(action_data.m_Player, 5, "AION", "Unknown error occurred", "set:dayz_gui image:icon_x");
        }
        array< ItemBase > currencies = new array< ItemBase >;
        GetCurrencyItems( currencies, action_data.m_Player );

        int toPay = price;
        bool complete = false;
        foreach ( auto item : currencies )
        {
            if ( toPay == 0 )
                break;
            
            int oldQuantity = item.GetQuantity();
            int newQuantity = oldQuantity - toPay;

            if (newQuantity < 0)
                newQuantity = 0;

            item.SetQuantity(newQuantity, true, true);
            toPay -= oldQuantity - newQuantity;
        }

        if ( !action_data.m_Player.GetInventory().CreateInInventory( m_VendingMachine.GetRation() ) )
        {
            GetGame().CreateObject( m_VendingMachine.GetRation(), action_data.m_Player.GetPosition() );
        }

        NotificationSystem.SendNotificationToPlayerExtended(action_data.m_Player, 5, "AION", "Purchased 1 AION for " + m_VendingMachine.GetPrice() + " credits.", "set:dayz_gui image:iconHungry0");
	}
};