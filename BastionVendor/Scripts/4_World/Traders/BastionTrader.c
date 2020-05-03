class Trader
{
    void Trader()
    {
        GetRPCManager().AddRPC( "Bastion", "BuyTraderItem", this, SingeplayerExecutionType.Both );
        GetRPCManager().AddRPC( "Bastion", "SellTraderItem", this, SingeplayerExecutionType.Both );
    }

    void ~Trader()
    {

    } 

    void ShowUI(BRP_VendingMachine_Base trader)
    {
        GetGame().GetMission().PlayerControlDisable(INPUT_EXCLUDE_ALL);

        GetUApi().GetInputByName("UAWalkRunTemp").ForceEnable(true);
        GetUApi().UpdateControls();

        GetGame().GetUIManager().ShowUICursor( true );

        PlayerBase player = GetGame().GetPlayer();
        if (player)
        {
            HumanInputController hic = player.GetInputController();
            if (hic)
            {
                hic.LimitsDisableSprint(true);
            }
        }

        GetGame().GetUIManager().EnterScriptedMenu( MENU_TRADER, NULL );

        TraderUI m_Menu = TraderUI.Cast( GetGame().GetUIManager().GetMenu() );
        if (m_Menu)
        {
            m_Menu.SetTraderEntity(trader);
        }
    }

    void QuitUI()
    {
        GetGame().GetMission().PlayerControlEnable(true);

        GetUApi().GetInputByName("UAWalkRunTemp").ForceEnable(false); 
		GetUApi().UpdateControls(); 

        GetGame().GetUIManager().ShowUICursor(false);
		GetGame().GetInput().ResetGameFocus( );

        PlayerBase player = GetGame().GetPlayer();
        if (player)
        {
            HumanInputController hic = player.GetInputController();
            if (hic)
            {
                hic.LimitsDisableSprint(false);
            }
        }
    }

    void BuyTraderItem(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
	{
        // Price, Quantity, Vehicle, Class Name, Vehicle Position, Identity, Vehicle Parts
		Param7< int, int, bool, string, vector, PlayerIdentity, ref array< string > > data;
		if ( !ctx.Read( data ) ) return;
		
		if( type == CallType.Server )
    	{
            PlayerBase player;
		    if ( !Class.CastTo( player, GetPlayerFromPID( sender.GetPlayerId() ) ) && GetGame().IsMultiplayer() )
			    return;

            if ( !GetGame().IsMultiplayer() )
                player = PlayerBase.Cast(GetGame().GetPlayer());

            if (player)
            {
                int price = data.param1;

                if (price > 0)
                {
                    if (data.param2 > 0)
                    {
                        price = price * data.param2;
                    }

                    array< ItemBase > currencies = new array< ItemBase >;
                    array< EntityAI > items = new array< EntityAI >;
	   	            player.GetInventory().EnumerateInventory( InventoryTraversalType.PREORDER, items );

                    for ( int i = 0; i < items.Count(); i++ )
		            {
                        ItemBase currency = ItemBase.Cast(items[i]);
                        if (currency)
                        {
                            if (currency.GetType() == GetServerSettings().GetTraderSettings().Currency)
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
                        NotificationSystem.SendNotificationToPlayerExtended(player, 5, "Trader", "You don't have enough funds to complete the purchase", "set:dayz_gui image:icon_x");
                        return;
                    }   
                }

                bool vehicle = data.param3;

                if ( !vehicle )
                {
                    Object obj = player.GetInventory().CreateInInventory( data.param4 );
				    if ( !obj )
				    {
					    obj = GetGame().CreateObject( data.param4, player.GetPosition() );
				    }

                    ItemBase item;
                    if ( Class.CastTo( item, obj ) )
				    {
                        int quantity = data.param2;

                        if (quantity > 1 || item.IsKindOf("Ammunition_Base") || item.IsKindOf("Magazine_Base") )
                        {
                            if ( !item.HasEnergyManager() || !item.HasEnergyManager() || !item.IsLiquidContainer() || !item.IsInherited(Edible_Base) || !item.IsKindOf("SodaCan_ColorBase") )
                            {
                                if ( item.IsKindOf("Ammunition_Base") || item.IsKindOf("Magazine_Base") )
                                {
                                    if ( item.IsInherited( Magazine ) )
                                    {
                                        Magazine magAmmo = Magazine.Cast( item );
                                        if (magAmmo)
                                        {
                                            int toSpawn;

                                            toSpawn = quantity;

                                            if ( quantity > magAmmo.GetAmmoMax() )
                                            {
                                                magAmmo.ServerSetAmmoCount( quantity );

                                                toSpawn -= magAmmo.GetAmmoMax();

                                                int remaing = toSpawn / magAmmo.GetAmmoMax();

                                                for (int t = -1; t < remaing; t++) 
                                                {
                                                    Object tobj = player.GetInventory().CreateInInventory( data.param4 );
				                                    if ( !tobj )
				                                    {
					                                    tobj = GetGame().CreateObject( data.param4, player.GetPosition() );
				                                    }

                                                    ItemBase titem;
                                                    if ( Class.CastTo( titem, tobj ) )
				                                    {
                                                        Magazine tmagAmmo = Magazine.Cast( item );
                                                        if (tmagAmmo)
                                                        {
                                                            int needToSpawn = 0;

                                                            if (toSpawn > magAmmo.GetAmmoMax())
                                                            {
                                                                needToSpawn = magAmmo.GetAmmoMax();

                                                                toSpawn -= magAmmo.GetAmmoMax();
                                                            }
                                                            else
                                                            {
                                                                needToSpawn = toSpawn;

                                                                toSpawn = 0;
                                                            }

                                                            if ( needToSpawn > 0 )
                                                            {
                                                                tmagAmmo.ServerSetAmmoCount( needToSpawn );
                                                            }
                                                            else 
                                                            {
                                                                GetGame().ObjectDelete( tmagAmmo );
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                            else
                                            {
                                                magAmmo.ServerSetAmmoCount( quantity );
                                            }
                                        }
                                    }
                                }
                                else
                                {
                                    item.SetQuantity(quantity);
                                }
                            }
                        }

                        if ( item.GetQuantity() == 0 || item.HasEnergyManager() || item.IsLiquidContainer() || item.IsInherited(Edible_Base) || item.IsKindOf("SodaCan_ColorBase") )
                        {
                            if (quantity > 1)
                            {
                                for (int e = 1; e < quantity; e++) 
                                { 
                                    Object obj_q = player.GetInventory().CreateInInventory( data.param4 );
				                    if ( !obj_q )
				                    {
					                    obj_q = GetGame().CreateObject( data.param4, player.GetPosition() );
				                    }

                                    if ( item.IsLiquidContainer() || item.IsKindOf("SodaCan_ColorBase") )
                                    {
                                        item.SetQuantity( item.GetQuantityMax() );
                                    }
                                }   
                            }
                        }
                    }

                    if (data.param2 > 1)
                    {
                        NotificationSystem.SendNotificationToPlayerExtended(player, 5, "Trader", "You have bought the items", "set:dayz_gui image:icon_circle");
                    }
                    else
                    {
                        NotificationSystem.SendNotificationToPlayerExtended(player, 5, "Trader", "You have bought an item", "set:dayz_gui image:icon_circle");
                    }
                }
                else 
                {
                    ref array< string > vehicleParts = data.param7;

                    Car car = Car.Cast( GetGame().CreateObject( data.param4, data.param5, false, false ) );
                    if ( car )
                    {
                        for (int j = 0; j < vehicleParts.Count(); j++) 
                        { 
                            car.GetInventory().CreateAttachment( vehicleParts.Get(j) ); 
                        }

		                car.Fill( CarFluid.FUEL, 1000 );
		                car.Fill( CarFluid.OIL, 1000 );
		                car.Fill( CarFluid.BRAKE, 1000 );
		                car.Fill( CarFluid.COOLANT, 1000 );

                        NotificationSystem.SendNotificationToPlayerExtended(player, 5, "Trader", "You have bought a vehicle", "set:dayz_gui image:stance_car");
                    }
                }

                if (vehicleParts)
                {
                    vehicleParts.Clear();
                }

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

    void SellTraderItem(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
	{
        // Price, Quantity, Vehicle, Class Name, Vehicle Position, Identity, Vehicle Parts
		Param7< int, int, bool, string, vector, PlayerIdentity, ref array< string > > data;
		if ( !ctx.Read( data ) ) return;
		
		if( type == CallType.Server )
    	{
            PlayerIdentity id = PlayerIdentity.Cast(data.param6);
            if ( !id && GetGame().IsMultiplayer() )
                return;

            PlayerBase player;
		    if ( !Class.CastTo( player, GetPlayerFromPID( sender.GetPlayerId() ) ) && GetGame().IsMultiplayer() )
			    return;

            if ( !GetGame().IsMultiplayer() )
                player = PlayerBase.Cast(GetGame().GetPlayer());

            array< ItemBase > sell = new array< ItemBase >;
            array< EntityAI > items = new array< EntityAI >;
	   	    player.GetInventory().EnumerateInventory( InventoryTraversalType.PREORDER, items );

            for ( int i = 0; i < items.Count(); i++ )
		    {
                ItemBase item = ItemBase.Cast(items[i]);
                if (item)
                {
                    if (item.GetType() == data.param4)
                    {
                        sell.Insert( item );
                    }
                }
            }

            int reserved;

            for ( int a = 0; a < sell.Count(); a++ )
		    {
                ItemBase currentItem = sell[a];
                if (currentItem)
                {
                    if ( currentItem.GetQuantityMax() == 0 || currentItem.HasEnergyManager() || currentItem.IsLiquidContainer() || currentItem.IsInherited(Edible_Base) || currentItem.IsKindOf("SodaCan_ColorBase") )
                    {
                        reserved += 1;
                    }
                    else
                    {
                        if ( currentItem.IsKindOf("Ammunition_Base") || currentItem.IsKindOf("Magazine_Base") )
                        {
                            if ( currentItem.IsInherited( Magazine ) )
                            {
                                Magazine magAmmo = Magazine.Cast( currentItem );
                                if (magAmmo)
                                {
                                    reserved += magAmmo.GetAmmoCount();
                                }
                            }
                        }
                        else
                        {
                            reserved += currentItem.GetQuantity();
                        }
                    }
                }
            }

            int sold;

            int result = 0;

            int bought = data.param2;

            if (reserved >= data.param2)
            {
                for ( int b = 0; b < sell.Count(); b++ )
		        {
                    ItemBase reservedItem = sell[b];
                    if (reservedItem)
                    {
                        if ( reservedItem.IsKindOf("Ammunition_Base") || reservedItem.IsKindOf("Magazine_Base") )
                        {
                            if ( reservedItem.IsInherited( Magazine ) )
                            {
                                Magazine magSellAmmo = Magazine.Cast( reservedItem );
                                if (magSellAmmo)
                                {
                                    if (bought > 0)
                                    {
                                        if (reserved == bought)
                                        {
                                            GetGame().ObjectDelete(reservedItem);
                                        }
                                        else 
                                        {
                                            if (bought > magSellAmmo.GetAmmoMax()) 
                                            {
                                                bought -= magSellAmmo.GetAmmoMax();

                                                magSellAmmo.ServerSetAmmoCount( 0 );

                                                GetGame().ObjectDelete( magSellAmmo );
                                            }
                                            else
                                            {
                                                magSellAmmo.ServerSetAmmoCount( magSellAmmo.GetAmmoCount() - bought );

                                                bought = 0;

                                                if ( magSellAmmo.GetAmmoCount() <= bought )
                                                {
                                                    GetGame().ObjectDelete( magSellAmmo );
                                                }
                                            }
                                        }
                                    }

                                    if (magSellAmmo.GetAmmoCount() == 0)
                                    {
                                        GetGame().ObjectDelete(reservedItem);
                                    }

                                    result = 1 * data.param2;
                                }
                            }
                        }
                        else 
                        {
                            if (sold < data.param2)
                            {
                                if ( reservedItem.GetQuantityMax() == 0 || reservedItem.HasEnergyManager() || reservedItem.IsLiquidContainer() || reservedItem.IsInherited(Edible_Base) || reservedItem.IsKindOf("SodaCan_ColorBase") )
                                {
                                    sold += 1;
                                }
                                else
                                {
                                    sold += reservedItem.GetQuantity() - data.param2;
                                }
                                
                                if ( reservedItem.GetQuantityMax() == 0 || reservedItem.HasEnergyManager() || reservedItem.IsLiquidContainer() || reservedItem.IsInherited(Edible_Base) || reservedItem.IsKindOf("SodaCan_ColorBase") )
                                {
                                    result = 1 * data.param2;

                                    GetGame().ObjectDelete(reservedItem);
                                }
                                else
                                {
                                    result = 1;

                                    reservedItem.SetQuantity(reservedItem.GetQuantity() - data.param2);
                                }
                            }
                        }
                    }
                }
            }

            if (sold <= 0)
            {
                NotificationSystem.SendNotificationToPlayerExtended(player, 5, "Trader", "You don't have enough items in inventory", "set:dayz_gui image:icon_x");
            }

            if (result >= 1)
            {
                Object obj = player.GetInventory().CreateInInventory( GetServerSettings().GetTraderSettings().Currency );
				if ( !obj )
				{
					obj = GetGame().CreateObject( GetServerSettings().GetTraderSettings().Currency, player.GetPosition() );
				}

                ItemBase currencyItem;
                if ( Class.CastTo( currencyItem, obj ) )
				{
                    int quantity = result;
                    if (quantity >= 1)
                    {
                        currencyItem.SetQuantity(quantity);
                    }
                }

                if (data.param2 > 1)
                {
                    NotificationSystem.SendNotificationToPlayerExtended(player, 5, "Trader", "You have sold the items", "set:dayz_gui image:icon_circle");
                }
                else
                {
                    NotificationSystem.SendNotificationToPlayerExtended(player, 5, "Trader", "You have sold an item", "set:dayz_gui image:icon_circle");
                }
            }
    	}
	}

    DayZPlayer GetPlayerFromPID(int id)
    {
        int networkIdLowBits;
        int networkIdHighBits;

        if (GetGame().IsMultiplayer()) 
        {
            GetGame().GetPlayerNetworkIDByIdentityID( id, networkIdLowBits, networkIdHighBits );

            return DayZPlayer.Cast( GetGame().GetObjectByNetworkId( networkIdLowBits, networkIdHighBits ) );
        }
        
       return DayZPlayer.Cast( GetGame().GetPlayer() );
    }
}

static ref Trader g_Trader;
static ref Trader GetTrader()
{
    if ( !g_Trader )
    {
        g_Trader = new ref Trader();
    }
    
    return g_Trader;
}