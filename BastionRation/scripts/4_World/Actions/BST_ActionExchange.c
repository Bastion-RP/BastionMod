class ActionExchange: ActionInteractBase
{
	private int m_Ammount;

    private NCC_AionVendor m_VendingMachine;

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

	protected int GetPlayersBalance( PlayerBase player )
    {
        int balance = 0;

        array< EntityAI > items = new array< EntityAI >;
	   	player.GetInventory().EnumerateInventory( InventoryTraversalType.PREORDER, items );

        for ( int i = 0; i < items.Count(); i++ )
		{
            EntityAI item = items.Get(i);
            if (item)
            {
                ItemBase itemBase = ItemBase.Cast( item );
                if (itemBase)
                {
                    if (itemBase.GetType() == GetBBankConfig().GetConfig().GetCurrencyClassName())
                    {	
                        balance += itemBase.GetQuantity();
                    }
                }
            }
        }

        return balance;
    }
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if ( !Class.CastTo( m_VendingMachine, target.GetObject( ) ) )
			return false;
		
		if ( GetPlayersBalance(player) < m_VendingMachine.GetPrice() )
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
				if ( GetPlayersBalance(action_data.m_Player) < m_VendingMachine.GetPrice() )
				{
					NotificationSystem.SendNotificationToPlayerExtended(action_data.m_Player, 5, "AION", "You don't have enough funds to complete the purchase", "set:dayz_gui image:icon_x");
					return;
				}

				int price = m_VendingMachine.GetPrice();

        		if (price > 0)
        		{
					array< ItemBase > currencies = new array< ItemBase >;
            		array< EntityAI > items = new array< EntityAI >;
	   	   			action_data.m_Player.GetInventory().EnumerateInventory( InventoryTraversalType.PREORDER, items );

            		for ( int i = 0; i < items.Count(); i++ )
		    		{
						ItemBase currency = ItemBase.Cast(items[i]);
                		if (currency)
                		{
                    		if (currency.GetType() == GetBBankConfig().GetConfig().GetCurrencyClassName())
                    		{
                    	    	currencies.Insert( currency );
                    		}
                		}
					}

					int reserved;

            		for ( int a = 0; a < currencies.Count(); a++ )
		    		{
                		ItemBase currentCurrency = currencies[a];
                		if (currentCurrency)
                		{
                		    reserved += currentCurrency.GetQuantity();
                		}
           			}

            		int payed;

            		if (reserved >= price)
            		{
						bool complete = false;

                		for ( int b = 0; b < currencies.Count(); b++ )
		        		{
                    		ItemBase reservedCurrency = currencies[b];
                    		if (reservedCurrency)
                    		{
                        		payed += reservedCurrency.GetQuantity() - price;
                        		if ( payed >= price ) // >= if more then refund
                        		{
                            		if (!complete)
                            		{
                            		    reservedCurrency.SetQuantity(payed);
                            		}
                            
                            		complete = true;
                        		}
                    		}
                		}
					}
					else 
					{
						NotificationSystem.SendNotificationToPlayerExtended(action_data.m_Player, 5, "AION", "You don't have enough funds to complete the purchase", "set:dayz_gui image:icon_x");
						return;
					}

					Object obj = action_data.m_Player.GetInventory().CreateInInventory( m_VendingMachine.GetRation() );
					if ( !obj )
					{
						obj = GetGame().CreateObject( m_VendingMachine.GetRation(), action_data.m_Player.GetPosition() );
					}

					NotificationSystem.SendNotificationToPlayerExtended(action_data.m_Player, 5, "AION", "Purchased 1 AION for " + m_VendingMachine.GetPrice() + " credits.", "set:dayz_gui image:iconHungry0");

					if (items)
            		{
            		    items.Clear();
            		}

            		if (currencies)
            		{
            		    currencies.Clear();
            		}
				}

			}
		}
	}
	
	override void OnStartServer( ActionData action_data )
	{
		super.OnStartServer( action_data );

		if ( GetPlayersBalance(action_data.m_Player) < m_VendingMachine.GetPrice() )
		{
			NotificationSystem.SendNotificationToPlayerExtended(action_data.m_Player, 5, "AION", "You don't have enough funds to complete the purchase", "set:dayz_gui image:icon_x");
			return;
		}

		int price = m_VendingMachine.GetPrice();

        if (price > 0)
        {
			array< ItemBase > currencies = new array< ItemBase >;
            array< EntityAI > items = new array< EntityAI >;
	   	    action_data.m_Player.GetInventory().EnumerateInventory( InventoryTraversalType.PREORDER, items );

            for ( int i = 0; i < items.Count(); i++ )
		    {
				ItemBase currency = ItemBase.Cast(items[i]);
                if (currency)
                {
                    if (currency.GetType() == GetBBankConfig().GetConfig().GetCurrencyClassName())
                    {
                        currencies.Insert( currency );
                    }
                }
			}

			int reserved;

            for ( int a = 0; a < currencies.Count(); a++ )
		    {
                ItemBase currentCurrency = currencies[a];
                if (currentCurrency)
                {
                    reserved += currentCurrency.GetQuantity();
                }
            }

            int payed;

            if (reserved >= price)
            {
				bool complete = false;

                for ( int b = 0; b < currencies.Count(); b++ )
		        {
                    ItemBase reservedCurrency = currencies[b];
                    if (reservedCurrency)
                    {
                        payed += reservedCurrency.GetQuantity() - price;
                        if ( payed >= price ) // >= if more then refund
                        {
                            if (!complete)
                            {
                                reservedCurrency.SetQuantity(payed);
                            }
                            
                            complete = true;
                        }
                    }
                }
			}
			else 
			{
				NotificationSystem.SendNotificationToPlayerExtended(action_data.m_Player, 5, "AION", "You don't have enough funds to complete the purchase", "set:dayz_gui image:icon_x");
				return;
			}

			Object obj = action_data.m_Player.GetInventory().CreateInInventory( m_VendingMachine.GetRation() );
			if ( !obj )
			{
				obj = GetGame().CreateObject( m_VendingMachine.GetRation(), action_data.m_Player.GetPosition() );
			}

			NotificationSystem.SendNotificationToPlayerExtended(action_data.m_Player, 5, "AION", "Purchased 1 AION for " + m_VendingMachine.GetPrice() + " credits.", "set:dayz_gui image:iconHungry0");

			if (items)
            {
                items.Clear();
            }

            if (currencies)
            {
                currencies.Clear();
            }
		}
	}
}

