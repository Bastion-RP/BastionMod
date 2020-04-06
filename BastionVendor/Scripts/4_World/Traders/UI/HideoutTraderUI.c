class TraderUI extends UIScriptedMenu
{
    protected string m_Search;
    protected int m_Category;
    protected int m_Quantity;
    protected bool m_Loading;

    protected BastionVendor m_Trader;
    protected ref BastionVendorItemUI m_Item;

    protected autoptr map< string, ref BastionVendorItemUI > m_Grid;
    protected autoptr array< ref BastionVendorItem > m_GridItems;

    protected GridSpacerWidget m_GridLayout;
    protected ScrollWidget m_GridScrollerLayout;
    protected XComboBoxWidget m_CategoriesLayout;

    protected RichTextWidget m_DisplayName;
    protected RichTextWidget m_DescriptionLayout;
    protected RichTextWidget m_QuantityLayout;
    protected RichTextWidget m_BalanceLayout;
    protected RichTextWidget m_PriceLayout;

    protected EditBoxWidget m_QuantityInputLayout;
    protected EditBoxWidget m_SearchInputLayout;

    protected ButtonWidget m_BuyLayout;
    protected ButtonWidget m_SellLayout;
    protected ButtonWidget m_QuitLayout;
    protected ButtonWidget m_AddQuanityLayout;
    protected ButtonWidget m_DecreaseQuantityLayout; 

    protected ItemPreviewWidget m_PreviewLayout;

    void TraderUI()
    {
        m_Loading = true;

        m_GridItems = new array< ref BastionVendorItem >;
        m_Grid = new map< string, ref BastionVendorItemUI >;
    }

    void ~TraderUI()
    {

    }

    override Widget Init()
	{
        layoutRoot = GetGame().GetWorkspace().CreateWidgets( "BastionVendor/GUI/Layout/TraderUI.layout" );

        m_GridLayout = GridSpacerWidget.Cast( layoutRoot.FindAnyWidget( "Trader_GridMenu" ) );
        m_CategoriesLayout = XComboBoxWidget.Cast( layoutRoot.FindAnyWidget( "Trader_CategorysMenu" ) );
        m_GridScrollerLayout = ScrollWidget.Cast( layoutRoot.FindAnyWidget("Trader_ItemsMenu") );

        m_BuyLayout = ButtonWidget.Cast( layoutRoot.FindAnyWidget( "Trader_BuyMenu" ) );
        m_SellLayout = ButtonWidget.Cast( layoutRoot.FindAnyWidget( "Trader_SellMenu" ) );
        m_QuitLayout = ButtonWidget.Cast( layoutRoot.FindAnyWidget( "Trader_QuitMenu" ) );
        m_AddQuanityLayout = ButtonWidget.Cast( layoutRoot.FindAnyWidget( "Trader_QuantityAddInfo" ) );
        m_DecreaseQuantityLayout = ButtonWidget.Cast( layoutRoot.FindAnyWidget( "Trader_QuantityDecreaseInfo" ) );

        m_PreviewLayout = ItemPreviewWidget.Cast( layoutRoot.FindAnyWidget( "Trader_PreviewInfo" ) );
        m_DisplayName = RichTextWidget.Cast( layoutRoot.FindAnyWidget( "Trader_TextMenu") );
        m_DescriptionLayout = RichTextWidget.Cast( layoutRoot.FindAnyWidget( "Trader_DescriptonInfo" ) );   
        m_BalanceLayout = RichTextWidget.Cast( layoutRoot.FindAnyWidget( "Trader_BalanceMenu" ) );   
        m_QuantityLayout = RichTextWidget.Cast( layoutRoot.FindAnyWidget( "Trader_QuantityInfo" ) );   
        m_QuantityInputLayout = EditBoxWidget.Cast( layoutRoot.FindAnyWidget( "Trader_QuantityInput" ) );   
        m_PriceLayout = RichTextWidget.Cast ( layoutRoot.FindAnyWidget("Trader_PriceInfo") );

        m_SearchInputLayout = EditBoxWidget.Cast( layoutRoot.FindAnyWidget( "Trader_SearchMenu" ) );   

        if ( GetGame().IsClient() || !GetGame().IsMultiplayer() )
        {
            m_BalanceLayout.SetText( GetPlayersBalance( GetGame().GetPlayer() ).ToString() + " BTC" );

            m_QuantityInputLayout.SetText("1");
            m_QuantityLayout.SetText("1");

            m_Quantity = 1;
        }

        if ( GetGame().IsMultiplayer() )
        {
            GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( Reload, 100 );
        }

        GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( Load, 100 );

        return layoutRoot;
    }

    /*
    Server bugs:

    Can't buy/sell at all, doesn't seem like RPC is executing on server at all, 
    check add rpc and log rpc in offline, if its logs in offline then check which of rpc functions causing
    issues on server

    */

    void Load( int category = 0 )
    {  
        GetRPCManager().SendRPC( "Bastion", "SetTraderCurrency", new Param1< bool >( true ), true, GetGame().GetPlayer().GetIdentity() );

        GetRPCManager().SendRPC( "Bastion", "SetTraderPlayer", new Param1< string >( m_Trader.GetType() ), true, GetGame().GetPlayer().GetIdentity() );

        m_GridScrollerLayout.VScrollToPos( 0 );

        m_Loading = true;

        if ( m_Grid )
        {
            delete m_Grid;
        }

        if ( m_GridLayout )
		{
			Widget child = m_GridLayout.GetChildren();
		
			while ( child )
			{
				Widget child_child = child.GetChildren();

				while ( child_child )
				{
					child_child.Unlink();
					child_child = child.GetSibling();
				}

				child.Unlink();
				child = m_GridLayout.GetSibling();
			}
		}

        TraderPlayerSettings traderSettings = GetClientSettings().GetPlayer();
        if (traderSettings)
        {
            m_DisplayName.SetText( traderSettings.DisplayName );

            m_CategoriesLayout.ClearAll();

            for ( int a = 0; a < traderSettings.CategoriesItems.Count(); a++ )
		    {
                m_CategoriesLayout.AddItem(traderSettings.CategoriesItems[a].Name);
            }

            m_GridItems.Clear();

            for ( int b = 0; b < traderSettings.CategoriesItems[category].Items.Count(); b++ )
		    {
                string className = traderSettings.CategoriesItems[category].Items[b].ClassName;
                int buyPrice = traderSettings.CategoriesItems[category].Items[b].BuyPrice;
                int sellPrice = traderSettings.CategoriesItems[category].Items[b].SellPrice;         
                bool vehicle = traderSettings.CategoriesItems[category].Items[b].Vehicle;

                m_GridItems.Insert( new BastionVendorItem( className, buyPrice, sellPrice, vehicle, traderSettings.CategoriesItems[category].Items[b].VehicleParts ) );
            }
        }

        m_Grid = new map< string, ref BastionVendorItemUI >;

        for ( int i = 0; i < m_GridItems.Count(); i++ )
		{
			GetItemForGrid( m_GridItems.Get(i), m_GridLayout );
		}

        BastionVendorItemUI itemUI;

        if ( m_Grid.Find( m_GridItems.Get(0).m_ClassName, itemUI ) )
		{ 
            SetSelectedItem( m_Grid.Get(m_GridItems.Get(0).m_ClassName) );
        }

        m_Category = category;

        m_Loading = false;
    }

    override bool OnChange(Widget w, int x, int y, bool finished)
    {
        m_QuantityLayout.SetText(m_QuantityInputLayout.GetText());

        if ( w == m_QuantityInputLayout )
        {
            // Load( m_CategoriesLayout.GetCurrentItem() );
        }

        if ( w == m_CategoriesLayout )
        {   
            Load( m_CategoriesLayout.GetCurrentItem() );
        }

        if ( w == m_SearchInputLayout )
        {
            m_Search = m_SearchInputLayout.GetText();

            Load( m_CategoriesLayout.GetCurrentItem() );
            
            return true;
        }

        return super.OnChange(w, x, y, finished);
    }

    override bool OnClick(Widget w, int x, int y, int button)
	{
        if ( m_Loading )
        {
            return false;
        }

        TraderPlayerSettings traderSettings = GetClientSettings().GetPlayer();

        int quantity = m_QuantityInputLayout.GetText().ToInt();
        string textQuantity;

        if ( quantity == 0 || quantity < 1 )
        {
            quantity = 1;
        }

        if ( w == m_AddQuanityLayout )
        {
            quantity = quantity + 1;
            textQuantity = quantity.ToString();

            m_QuantityInputLayout.SetText(textQuantity);
            m_QuantityLayout.SetText(textQuantity);

            if (GetSelectedItem())
            {
                GetSelectedItem().UpdateColors();
            }   

            // Load( m_CategoriesLayout.GetCurrentItem() );
        }

        if ( w == m_DecreaseQuantityLayout )
        {
            if ( quantity > 1 )
            {
                quantity = quantity - 1;
                textQuantity = quantity.ToString();

                m_QuantityInputLayout.SetText(textQuantity);
                m_QuantityLayout.SetText(textQuantity);
            }

            if (GetSelectedItem())
            {
                GetSelectedItem().UpdateColors();
            }

            // Load( m_CategoriesLayout.GetCurrentItem() );
        }

        m_Quantity = quantity;
 
        bool vehicle = m_Item.GetData().m_Vehicle;
        string className = m_Item.GetData().m_ClassName;
        vector vehiclePosition = traderSettings.VehiclePosition;
        PlayerIdentity identity = GetGame().GetPlayer().GetIdentity();
        ref array< string > vehicleParts = m_Item.GetData().m_VehicleParts;

        if ( w == m_BuyLayout )
		{
            if ( m_Item && traderSettings )
            {
                if ( m_Item.GetData() )
                {
                    // RPC
                    // Price, Quantity, Vehicle, Vehicle Position, Identity, Vehicle Parts
                    int priceBuy = m_Item.GetData().m_PriceBuy;
                
                    GetRPCManager().SendRPC( "Bastion", "BuyTraderItem", new Param7< int, int, bool, string, vector, PlayerIdentity, ref array< string > >( priceBuy, quantity, vehicle, className, vehiclePosition, identity, vehicleParts ) );
                }
            }

            m_BalanceLayout.SetText( GetPlayersBalance( GetGame().GetPlayer() ).ToString() + " BTC" );
			return true;
		}

        if ( w == m_SellLayout )
		{
            if ( m_Item && traderSettings )
            {
                if ( m_Item.GetData() )
                {
                    // RPC
                    // Price, Quantity, Vehicle, Vehicle Position, Identity, Vehicle Parts
                    int priceSell = m_Item.GetData().m_PriceSell;

                    GetRPCManager().SendRPC( "Bastion", "SellTraderItem", new Param7< int, int, bool, string, vector, PlayerIdentity, ref array< string > >( priceSell, quantity, vehicle, className, vehiclePosition, identity, vehicleParts ) );
                }
            }

            m_BalanceLayout.SetText( GetPlayersBalance( GetGame().GetPlayer() ).ToString() + " BTC" );
			return true;
		}

        if ( w == m_QuitLayout )
		{
            GetTrader().QuitUI();

            Close();

			return true;
		}

        return super.OnClick(w, x, y, button);
    }

    void SetSelectedItem( BastionVendorItemUI item )
    {
        m_Item = item;

        m_DescriptionLayout.SetText( item.GetDescriptionFromType( item.GetPreview().GetType() ) );
        m_PriceLayout.SetText( item.GetData().m_PriceBuy.ToString() + " BTC" );

        if ( item.GetPreview() && m_PreviewLayout )
        {
            Transport transportEntity;
		    if ( Class.CastTo( transportEntity, item.GetPreview() ) )
		    {
			    dBodyActive( transportEntity, ActiveState.INACTIVE );
        	    dBodyDynamic( transportEntity, false );

			    transportEntity.DisableSimulation( true );
		    }

            m_PreviewLayout.SetItem( EntityAI.Cast(item.GetPreview()) );
			m_PreviewLayout.SetModelPosition( Vector( 0, 0, 0.5 ) );
			m_PreviewLayout.SetModelOrientation( vector.Zero );
			m_PreviewLayout.SetView( EntityAI.Cast(item.GetPreview()).GetViewIndex() );
        }
    }

    void SetTraderEntity( BastionVendor trader )
    {
        m_Trader = trader;
    }

    protected int GetPlayersBalance( PlayerBase player )
    {
        GetRPCManager().SendRPC( "Bastion", "SetTraderCurrency", new Param1< bool >( true ), true, GetGame().GetPlayer().GetIdentity() );

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
                    if (itemBase.GetType() == GetClientSettings().GetCurrency())
                    {
                        balance += itemBase.GetQuantity();
                    }
                }
            }
        }

        return balance;
    }

    protected void GetItemForGrid( BastionVendorItem item, Widget category )
    {
        BastionVendorItemUI itemUI;

        if ( !m_Grid.Find( item.m_ClassName, itemUI ) )
		{
            if (category)
            {
                if (itemUI)
                {
                    delete itemUI;
                }

                itemUI = new BastionVendorItemUI(category, this);

                if (itemUI)
                {
                    itemUI.SetTraderData( item );
                    itemUI.SetTraderMenu( this );

                    string searchInput = m_Search;
                    string nameInput = itemUI.GetNameFromType( item.m_ClassName );

                    searchInput.ToLower();
                    nameInput.ToLower();

                    if ( nameInput.Contains( searchInput ) || nameInput == "" )
                    {
                        m_Grid.Insert( item.m_ClassName, itemUI );
                    }
                }
            }
        }
    }

    void Reload()
    {
        GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( Load, 100 );
    }

    BastionVendorItemUI GetSelectedItem()
    {
        return m_Item;
    }

    int GetQuantityMenu()
    {
        return m_Quantity;
    }
}