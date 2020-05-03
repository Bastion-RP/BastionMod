class BST_RationSettings
{
    protected ref BST_VendingMachineLocations m_VendingMachineLocations;

    void BST_RationSettings( )
    {
        Load();
    }

    void Defaults( )
    {
        m_VendingMachineLocations = new BST_VendingMachineLocations( );
        auto defaultMachine = new BST_VendingMachineSettings( "4765.925781 10.628984 4240.184082", "44.417702 0.000000 0.000000", BastionRationConst.defaultRation, BastionRationConst.defaultPrice );
        m_VendingMachineLocations.VendingMachineSettings.Insert( defaultMachine );
        m_VendingMachineLocations.m_defaultRation = BastionRationConst.defaultRation;
        m_VendingMachineLocations.m_defaultPrice = BastionRationConst.defaultPrice;

        if ( !FileExist( BastionRationConst.baseDir ) )
		{
			MakeDirectory( BastionRationConst.baseDir );
		}
        if ( !FileExist( BastionRationConst.configDir ) )
		{
			MakeDirectory( BastionRationConst.configDir );
		}

		JsonFileLoader< BST_VendingMachineLocations >.JsonSaveFile( BastionRationConst.config, m_VendingMachineLocations );
    }

    void Load( )
	{
        if ( !GetGame().IsServer() ) return;

		if ( FileExist( BastionRationConst.config ) )
		{
			JsonFileLoader< BST_VendingMachineLocations >.JsonLoadFile( BastionRationConst.config, m_VendingMachineLocations );
		} 
		else 
		{
			Defaults( );
		}
	}

    ref BST_VendingMachineLocations GetVendingMachineSettings( )
    {
        return m_VendingMachineLocations;
    }
};

static ref BST_RationSettings g_RationSettings;
static ref BST_RationSettings GetRationSettings( )
{
    if ( !g_RationSettings )
    {
        g_RationSettings = new ref BST_RationSettings( );
    }
    
    return g_RationSettings;
};