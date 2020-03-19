modded class MissionServer
{
    void MissionServer( )
    {
        g_RationSettings = null;
        GetRationSettings( );

        if ( GetGame( ) )
        {
            if ( GetGame( ).IsServer( ) )
            {
                for ( int i = 0; i < GetRationSettings( ).GetVendingMachineSettings( ).VendingMachineSettings.Count( ); i++ )
		        {
                    BST_VendingMachineSettings vendingMachine = GetRationSettings( ).GetVendingMachineSettings( ).VendingMachineSettings.Get( i );
                    if (vendingMachine)
                    {
                        BST_VendingMachine machine = BST_VendingMachine.Cast( GetGame( ).CreateObject( "BST_VendingMachine", vendingMachine.Position ) );
                        if ( machine )
                        {
                            machine.SetRation( vendingMachine.Ration );
                            machine.SetPrice( vendingMachine.Price );
                        }
                    }
                }
            }
        }
    }
}