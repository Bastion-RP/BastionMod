class BST_VendingMachine extends ItemBase
{
    string m_Ration;
    int m_Price;

    void BST_VendingMachine( )
    {

    }

    void ~BST_VendingMachine( )
    {

    }

    override void SetActions( )
	{
		super.SetActions( );

        AddAction( ActionExchange );
	}

    void SetRation( string ration )
    {
        m_Ration = ration;
    }

    void SetPrice( int price )
    {
        m_Price = price;
    }

    override bool CanPutIntoHands(EntityAI parent)
	{
        return false;
    }

    override bool CanPutInCargo(EntityAI parent)
    {
		return false;
    }
}