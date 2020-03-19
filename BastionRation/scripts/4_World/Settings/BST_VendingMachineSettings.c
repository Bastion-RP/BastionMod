class BST_VendingMachineSettings
{
    vector Position;
    string Ration;
    int Price;

    void BST_VendingMachineSettings( vector position, string ration, int price )
	{
        this.Position = position;
		this.Ration = ration;
		this.Price = price;
    }
}

class BST_VendingMachineLocations
{
    ref array< ref BST_VendingMachineSettings > VendingMachineSettings;

    void BST_VendingMachineLocations( )
    {
        VendingMachineSettings = new array< ref BST_VendingMachineSettings >;
    }

    void Defaults( )
    {
        VendingMachineSettings.Insert( new BST_VendingMachineSettings( Vector( 11900, 140, 12485 ), "Apple", 1 ) );

        if ( !FileExist( "$profile:Bastion\\Rations\\" ) )
		{
			MakeDirectory( "$profile:Bastion\\Rations\\" );
		}

		JsonFileLoader< BST_VendingMachineLocations >.JsonSaveFile( "$profile:Bastion\\Rations\\VendingMachines.json", this );
    }

    void Load( )
	{
		if ( FileExist( "$profile:Bastion\\Rations\\VendingMachines.json" ) )
		{
			JsonFileLoader< BST_VendingMachineLocations >.JsonLoadFile( "$profile:Bastion\\Rations\\VendingMachines.json", this );
		} 
		else 
		{
			Defaults( );
		}
	}
}