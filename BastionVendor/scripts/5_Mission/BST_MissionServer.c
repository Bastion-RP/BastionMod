modded class MissionServer
{
    void MissionServer( )
    {
        g_Settings = null;
        GetSettings();

        g_Trader = null;
        GetTrader();

        g_RationSettings = null;
        GetRationSettings( );

        if ( GetGame() )
        {
            if ( GetGame().IsServer() )
            {
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

        foreach ( auto vendingMachine : GetRationSettings( ).GetVendingMachineSettings( ).VendingMachineSettings )
        {
            auto obj = BRP_AionVendor.Cast( GetGame().CreateObject( "BRP_AionVendor", vendingMachine.Position ) );

            obj.SetRation( vendingMachine.Ration );
            obj.SetPrice( vendingMachine.Price );

            obj.SetPosition( vendingMachine.Position );
            obj.SetOrientation( vendingMachine.Direction );
            obj.SetOrientation( obj.GetOrientation() );

            obj.Update();
            obj.SetAffectPathgraph( true, false );

            if ( obj.CanAffectPathgraph() ) 
                GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( GetGame().UpdatePathgraphRegionByObject, 100, false, obj );
        }
    }
}