class BastionClientSettings
{
    protected ref TraderVendorSettings m_Player;

    protected string m_Currency;

    void BastionClientSettings()
    {
        GetRPCManager().AddRPC( "Bastion", "SyncTraderCurrency", this, SingeplayerExecutionType.Both );
        GetRPCManager().AddRPC( "Bastion", "SyncTraderPlayer", this, SingeplayerExecutionType.Both );
    }

    void ~BastionClientSettings()
    {
        
    }

    void SyncTraderCurrency(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
	{
		Param1< string > data;
		if ( !ctx.Read( data ) )
			return;

		if ( type == CallType.Client )
		{
			m_Currency = data.param1;
		}
	}

    void SyncTraderPlayer(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
	{
		Param1< ref TraderVendorSettings > data;
		if ( !ctx.Read( data ) )
			return;

		if ( type == CallType.Client )
		{
			m_Player = TraderVendorSettings.Cast(data.param1);
		}
	}

    ref TraderVendorSettings GetPlayer()
    {
        return m_Player;
    }

    string GetCurrency()
    {
        return m_Currency;
    }
}

class BastionServerSettings
{
    protected autoptr array< vector > m_Traders;

    protected ref TraderSettings m_TraderSettings;

    void BastionServerSettings()
    {
        BRP_PackStation trader;

        GetRPCManager().AddRPC( "Bastion", "SetTraderCurrency", this, SingeplayerExecutionType.Both );
        GetRPCManager().AddRPC( "Bastion", "SetTraderPlayer", this, SingeplayerExecutionType.Both );

        m_TraderSettings = new TraderSettings();

        m_TraderSettings.Load();

        m_Traders = new array< vector >;

        for ( int i = 0; i < m_TraderSettings.TraderZones.Count(); i++ )
		{
            TraderZone zone = m_TraderSettings.TraderZones.Get(i);
            if (zone)
            {
                if ( !m_Traders.Find( zone.Position ) )
		        {
                    trader = GetSettings().SpawnTrader(zone.Name, zone.Position, zone.Orientation);

                    if (trader)
                    {
                        m_Traders.Insert( zone.Position );
                    }
                }
            }
        }
    }

    void ~BastionServerSettings()
    {

    }

    void SetTraderCurrency(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
	{
		Param1< bool > data;
		if ( !ctx.Read( data ) )
			return;

		if ( type == CallType.Server )
		{
			GetRPCManager().SendRPC( "Bastion", "SyncTraderCurrency", new Param1< string >( m_TraderSettings.Currency ), true, sender );
		}
	}

    void SetTraderPlayer(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
	{
		Param1< string > data;
		if ( !ctx.Read( data ) )
			return;

		if ( type == CallType.Server )
		{
			GetRPCManager().SendRPC( "Bastion", "SyncTraderPlayer", new Param1< ref TraderVendorSettings >( GetTraderSettings().GetTraderByName( data.param1 ) ), true, sender );
		}
	}

    ref TraderSettings GetTraderSettings()
    {
        return m_TraderSettings;
    }
}

class BastionSettings
{
    protected ref TraderSettings m_TraderSettings;

    void BastionSettings()
    {
        if (GetGame())
        {
            if (GetGame().IsClient() || !GetGame().IsMultiplayer())
            {
                delete g_ClientSettings;
                GetClientSettings();
            }

            if (GetGame().IsServer())
            {
                delete g_ServerSettings;
                GetServerSettings();
            }
        }
    }

    void ~BastionSettings()
    {

    }

    ref TraderSettings GetTraderSettings()
    {
        return m_TraderSettings;
    }

    BRP_PackStation SpawnTrader( string type, vector position, vector orientation )
    {
	    BRP_PackStation trader = BRP_PackStation.Cast( GetGame().CreateObject( type, position, false, false, true ) );

	    if ( trader )
	    {
		    trader.SetPosition( position );
		    trader.SetOrientation( orientation );
	    }

	    return trader;
    }
}

static ref BastionSettings g_Settings;
static ref BastionSettings GetSettings()
{
    if ( !g_Settings )
    {
        g_Settings = new ref BastionSettings();
    }
    
    return g_Settings;
}

static ref BastionServerSettings g_ServerSettings;
static ref BastionServerSettings GetServerSettings()
{
    if ( !g_ServerSettings )
    {
        g_ServerSettings = new ref BastionServerSettings();
    }
    
    return g_ServerSettings;
}

static ref BastionClientSettings g_ClientSettings;
static ref BastionClientSettings GetClientSettings()
{
    if ( !g_ClientSettings )
    {
        g_ClientSettings = new ref BastionClientSettings();
    }
    
    return g_ClientSettings;
}