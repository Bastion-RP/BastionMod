class BST_RationSettings
{
    protected ref BST_VendingMachineLocations m_VendingMachineLocations;

    void BST_RationSettings( )
    {
        m_VendingMachineLocations = new BST_VendingMachineLocations( );

        m_VendingMachineLocations.Load( );
    }

    ref BST_VendingMachineLocations GetVendingMachineSettings( )
    {
        return m_VendingMachineLocations;
    }
}

static ref BST_RationSettings g_RationSettings;
static ref BST_RationSettings GetRationSettings( )
{
    if ( !g_RationSettings )
    {
        g_RationSettings = new ref BST_RationSettings( );
    }
    
    return g_RationSettings;
}