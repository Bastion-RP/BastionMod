class BastionVendorItem
{
    string m_ClassName;
	int m_PriceBuy;
	int m_PriceSell;
	bool m_Vehicle;

    ref array< string > m_VehicleParts;

    void BastionVendorItem( string className, int priceBuy, int priceSell, bool vehicle, ref array< string > vehicleParts )
	{
		if (!m_VehicleParts)
        {
            m_VehicleParts = new array < string >;
        }

		m_ClassName = className;
		m_PriceBuy = priceBuy;
		m_PriceSell = priceSell;
		m_Vehicle = vehicle;
        m_VehicleParts = vehicleParts;
	}
}

class TraderZone
{
	string Name;
    vector Position;
	vector Orientation;

    void TraderZone( string name, vector position, vector orientation )
	{
        this.Name = name;
		this.Position = position;
		this.Orientation = orientation;
    }
}

class TraderSettings
{
    bool Enabled;
	string Currency;

    ref array< ref TraderZone > TraderZones;

	[NonSerialized()]
	ref array< ref TraderVendorSettings > m_Traders;

    void TraderSettings()
    {
		TraderZones = new array< ref TraderZone >;
		
		m_Traders = new array< ref TraderVendorSettings >;
		m_Traders.Insert( new ref BRP_MedicalVendor1_BloodySettings() );
		m_Traders.Insert( new ref BRP_MedicalVendor1Settings() );
		m_Traders.Insert( new ref BRP_PackStationSettings() );

		for ( int i = 0; i < m_Traders.Count(); i++ )
		{	
			m_Traders.Get(i).Load();
		}
    }

    void Defaults()
    {
        Enabled = true;
		Currency = "NCC_CopperCoin";
        
		// DART 
        TraderZones.Insert( new TraderZone( "BRP_MedicalVendor1", Vector(4434, 10.392, 4706.8), Vector(0, 0, 0) ) );

		// ISF 
        TraderZones.Insert( new TraderZone( "BRP_MedicalVendor1_Bloody", Vector(4437, 10.405, 4697), Vector(0, 0, 0) ) );

        if ( !FileExist( "$profile:Bastion\\Vendors\\" ) )
		{
			MakeDirectory( "$profile:Bastion\\Vendors\\" );
		}

		JsonFileLoader<TraderSettings>.JsonSaveFile( "$profile:Bastion\\Vendors\\Trader.json", this );
    }

    void Load()
	{
		if ( FileExist( "$profile:Bastion\\Vendors\\Trader.json" ) )
		{
			JsonFileLoader<TraderSettings>.JsonLoadFile( "$profile:Bastion\\Vendors\\Trader.json", this );
		} 
		else 
		{
			Defaults();
		}
	}

	ref TraderVendorSettings GetTraderByName( string name )
	{
		for ( int i = 0; i < m_Traders.Count(); i++ )
		{
			if ( m_Traders.Get(i).TraderName == name )
			{
				return m_Traders.Get(i);
			}
		}
		return NULL;
	}
}