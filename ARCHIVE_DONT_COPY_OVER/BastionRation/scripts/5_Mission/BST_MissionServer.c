modded class MissionServer
{
    void MissionServer( )
    {
        g_RationSettings = null;
        GetRationSettings( );

        foreach ( auto vendingMachine : GetRationSettings( ).GetVendingMachineSettings( ).VendingMachineSettings )
        {
            auto obj = NCC_AionVendor.Cast( GetGame().CreateObject( "NCC_AionVendor", vendingMachine.Position ) );
            obj.SetRation( vendingMachine.Ration );
            obj.SetPrice( vendingMachine.Price );
            obj.SetPosition( vendingMachine.Position );
            obj.SetOrientation( vendingMachine.Direction );
            obj.SetOrientation( obj.GetOrientation() );
            obj.Update();
            obj.SetAffectPathgraph( true, false );
            if( obj.CanAffectPathgraph() ) GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( GetGame().UpdatePathgraphRegionByObject, 100, false, obj );
        }
    }
}