class NCC_AionVendor extends ItemBase
{
    string m_Ration;
    int m_Price;

    void NCC_AionVendor( )
    {
        if ( GetGame().IsServer() ) {
            auto settings = GetRationSettings().GetVendingMachineSettings();
            m_Ration = settings.m_defaultRation;
            m_Price = settings.m_defaultPrice;
        }
    }

    void ~NCC_AionVendor( )
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

    int GetPrice()
    {
        return m_Price;
    }

    string GetRation()
    {
        return m_Ration;
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