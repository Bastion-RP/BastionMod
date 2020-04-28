class BastionVendorItemUI: ScriptedWidgetEventHandler
{
    protected static ref set< BastionVendorItemUI > m_Grid = new set< BastionVendorItemUI >;

    protected Widget m_RootLayout;

    protected ButtonWidget m_SelectLayout;
    
    protected ImageWidget m_BackgroundLayout;
    protected ItemPreviewWidget m_PreviewLayout;

    protected RichTextWidget m_ItemNameLayout;
    protected RichTextWidget m_ItemPriceLayout;
    protected RichTextWidget m_ItemPriceSellLayout;

    protected Trader m_Trader;
    protected Object m_Preview;

    protected BastionVendorItem m_Data;
    protected ref TraderUI m_Menu;

    void BastionVendorItemUI(Widget parent, TraderUI menu)
    {
        m_Grid.Insert( this );

        if (parent)
        {
            m_RootLayout = GetGame().GetWorkspace().CreateWidgets( "BastionVendor/GUI/Layout/TraderUIMenu.layout", parent );

            m_RootLayout.SetHandler( this );

            m_Menu = TraderUI.Cast(menu);

            Init();
        }
    }

    void ~BastionVendorItemUI()
    {
        int i = m_Grid.Find( this );
		if ( i >= 0 )
		{
			m_Grid.Remove( i );
		}

        if (m_RootLayout)
        {
            m_RootLayout.Unlink();
        }
        
        if ( m_Preview )
		{
			GetGame().ObjectDelete( m_Preview );
		}
    }

    void Init()
    {
        if (!GetGame().GetUIManager().IsMenuOpen(MENU_TRADER))
            return;

        if (!m_Menu || m_Menu == NULL)
            return;

        m_SelectLayout = ButtonWidget.Cast( m_RootLayout.FindAnyWidget( "Trader_ItemButton" ) );

        m_ItemNameLayout = RichTextWidget.Cast( m_RootLayout.FindAnyWidget( "Trader_ItemNameText" ) );
        m_ItemPriceLayout = RichTextWidget.Cast( m_RootLayout.FindAnyWidget( "Trader_ItemPrice" ) );
        m_ItemPriceSellLayout = RichTextWidget.Cast( m_RootLayout.FindAnyWidget( "Trader_ItemSell" ) );
        m_BackgroundLayout = ImageWidget.Cast(m_RootLayout.FindAnyWidget( "TraderItemBackground" ));
		m_PreviewLayout = ItemPreviewWidget.Cast( m_RootLayout.FindAnyWidget( "Trader_ItemPreview" ) );

        m_RootLayout.Show( true );
    }

    void SetTraderMenu( ref TraderUI menu )
    {
        m_Menu = menu;
    }

    void SetTraderData( ref BastionVendorItem data )
    {   
        m_Data = data;
		if ( !m_Data )
			return;

		m_Preview = GetGame().CreateObject( m_Data.m_ClassName, vector.Zero, true, false );

        GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( OnUpdatePreview, 250 );

		m_ItemNameLayout.SetText( GetNameFromType( m_Data.m_ClassName ) );
        m_ItemPriceLayout.SetText( m_Data.m_PriceBuy.ToString() + " CREDITS" );
        m_ItemPriceSellLayout.SetText( m_Data.m_PriceSell.ToString() + " CREDITS" );

        UpdateColors();
    }

    void UpdateColors()
    {
        array< ItemBase > currencies = new array< ItemBase >;
        array< EntityAI > items = new array< EntityAI >;
        array< ItemBase > sell = new array< ItemBase >;

        if (currencies)
        {
            currencies.Clear();
        }

        if (items)
        {
            items.Clear();
        }

        if (sell)
        {
            sell.Clear();
        }

        PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
        if (player)
        {
            int total;

            int quantityMenu = m_Menu.GetQuantityMenu();

            player.GetInventory().EnumerateInventory( InventoryTraversalType.PREORDER, items );

            for ( int i = 0; i < items.Count(); i++ )
		    {
                ItemBase currency = ItemBase.Cast(items[i]);
                if (currency)
                {
                    if (currency.GetType() == GetClientSettings().GetCurrency())
                    {
                        currencies.Insert( currency );

                        total += currency.GetQuantity();
                    }
                }
            }	

            for ( int a = 0; a < items.Count(); a++ )
		    {
                ItemBase item = ItemBase.Cast(items[a]);
                if (item)
                {
                    if (item.GetType() == m_Data.m_ClassName)
                    {  
                        // if (quantityMenu <= 1)
                        {
                            sell.Insert( item );
                        }
                    }
                }
            }	

            int reserved;

            for ( int b = 0; b < sell.Count(); b++ )
		    {
                ItemBase currentItem = sell[b];
                if (currentItem)
                {
                    if (currentItem.GetQuantityMax() == 0)
                    {
                        reserved += 1;
                    }
                    else
                    {
                        reserved += currentItem.GetQuantity();
                    }
                }
            }

            if (reserved >= quantityMenu)
            {
                m_ItemPriceSellLayout.SetColor( ARGB(255, 0, 255, 64) );
            }
            else
            {
                m_ItemPriceSellLayout.SetColor( ARGB(255, 255, 0, 0) );
            } 

            if ( total < ( m_Data.m_PriceBuy * quantityMenu ) )
            {
                m_ItemPriceLayout.SetColor( ARGB(255, 255, 0, 0) );
            }
		    else
		    {
		    	m_ItemPriceLayout.SetColor( ARGB(255, 0, 255, 64) );
		    }

            m_ItemPriceSellLayout.Update();
            m_ItemPriceLayout.Update();
        }   
    }

    void OnUpdatePreview()
    {
        if ( m_Preview && m_PreviewLayout )
        {
            Transport transportEntity;
		    if ( Class.CastTo( transportEntity, m_Preview ) )
		    {
			    dBodyActive( transportEntity, ActiveState.INACTIVE );
        	    dBodyDynamic( transportEntity, false );

			    transportEntity.DisableSimulation( true );
		    }

            m_PreviewLayout.SetItem( EntityAI.Cast(m_Preview) );
			m_PreviewLayout.SetModelPosition( Vector( 0, 0, 0.5 ) );
			m_PreviewLayout.SetModelOrientation( vector.Zero );
			m_PreviewLayout.SetView( EntityAI.Cast(m_Preview).GetViewIndex() );
        }
    }

    BastionVendorItem GetData()
    {
        return m_Data;
    }

    Object GetPreview()
    {
        return m_Preview;
    }

    Widget GetLayoutRoot()
	{
		return m_RootLayout;
	}

    override bool OnClick(Widget w, int x, int y, int button)
	{
        if ( w == m_SelectLayout )
		{
            m_Menu.SetSelectedItem( this );

			return true;
		}

        return super.OnClick(w, x, y, button);
    }

    string GetDescriptionFromType( string type_name )
    {
	    string cfg_des;
	    string cfg_des_path;
	
	    if ( GetGame().ConfigIsExisting( CFG_WEAPONSPATH + " " + type_name ) )
	    {
		    cfg_des_path = CFG_WEAPONSPATH + " " + type_name + " descriptionShort";
		    GetGame().ConfigGetText( cfg_des_path, cfg_des );
		    return cfg_des;
	    } 
	
	    if ( GetGame().ConfigIsExisting( CFG_VEHICLESPATH + " " + type_name ) )
	    {
	    	cfg_des_path = CFG_VEHICLESPATH + " " + type_name + " descriptionShort";
	    	GetGame().ConfigGetText( cfg_des_path, cfg_des );
	    	return cfg_des;
	    } 
	
	    if ( GetGame().ConfigIsExisting( CFG_MAGAZINESPATH + " " + type_name ) )
	    {
	    	cfg_des_path = CFG_MAGAZINESPATH + " " + type_name + " descriptionShort";
	    	GetGame().ConfigGetText( cfg_des_path, cfg_des );
	    	return cfg_des;
	    }
	
	    return cfg_des_path;
    }

    string GetNameFromType( string type_name )
    {
	    string cfg_name;
	    string cfg_name_path;
	
	    if ( GetGame().ConfigIsExisting( CFG_WEAPONSPATH + " " + type_name ) )
	    {
		    cfg_name_path = CFG_WEAPONSPATH + " " + type_name + " displayName";
		    GetGame().ConfigGetText( cfg_name_path, cfg_name );
		    return cfg_name;
	    } 
	
	    if ( GetGame().ConfigIsExisting( CFG_VEHICLESPATH + " " + type_name ) )
	    {
		    cfg_name_path = CFG_VEHICLESPATH + " " + type_name + " displayName";
		    GetGame().ConfigGetText( cfg_name_path, cfg_name );
		    return cfg_name;
	    } 
	
	    if ( GetGame().ConfigIsExisting( CFG_MAGAZINESPATH + " " + type_name ) )
	    {
		    cfg_name_path = CFG_MAGAZINESPATH + " " + type_name + " displayName";
		    GetGame().ConfigGetText( cfg_name_path, cfg_name );
		    return cfg_name;
	    }
	
	    return type_name;
    }
}