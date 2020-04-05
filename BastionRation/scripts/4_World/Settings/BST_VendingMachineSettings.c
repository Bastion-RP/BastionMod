class BST_VendingMachineSettings
{
    vector Position;
    vector Direction;
    string Ration;
    int Price;

    void BST_VendingMachineSettings( vector position, vector direction, string ration, int price )
	{
        this.Position = position;
        this.Direction = direction;
		this.Ration = ration;
		this.Price = price;
    }
}

class BST_VendingMachineLocations
{
    ref array< ref BST_VendingMachineSettings > VendingMachineSettings;
    string m_defaultRation;
    int m_defaultPrice;

    void BST_VendingMachineLocations( )
    {
        VendingMachineSettings = new array< ref BST_VendingMachineSettings >;
    }
}