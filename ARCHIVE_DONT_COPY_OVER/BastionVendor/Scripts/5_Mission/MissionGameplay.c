modded class MissionGameplay
{
    void MissionGameplay()
    {
        g_Settings = null;
        GetSettings();
        
        g_Trader = null;
        GetTrader();

        if (GetGame())
        {
            if (GetGame().IsServer())
            {
                g_Safezone = null;
                GetSafezone();

                for ( int i = 0; i < GetServerSettings().GetTraderSettings().TraderZones.Count(); i++ )
		        {
                    TraderZone zone = GetServerSettings().GetTraderSettings().TraderZones.Get(i);
                    if (zone)
                    {
                        GetSettings().SpawnTrader(zone.Name, zone.Position, zone.Orientation);
                    }
                }
            }
        }
    }

    override void OnInit()
	{
		super.OnInit();

        if (GetGame().IsServer())
        {
            // GetClientSettings().SetTraderSettings( GetServerSettings().GetTraderSettings() );
        }
    }
}