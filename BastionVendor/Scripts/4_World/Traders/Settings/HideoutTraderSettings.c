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
	ref array< ref TraderPlayerSettings > m_Traders;

    void TraderSettings()
    {
		TraderZones = new array< ref TraderZone >;
		
		m_Traders = new array< ref TraderPlayerSettings >;
		m_Traders.Insert( new ref BastionVendorBorisSettings() );
		m_Traders.Insert( new ref BastionVendorCyrilSettings() );
		m_Traders.Insert( new ref BastionVendorDenisSettings() );
		m_Traders.Insert( new ref BastionVendorEliasSettings() );
		m_Traders.Insert( new ref BastionVendorFrancisSettings() );
		m_Traders.Insert( new ref BastionVendorFridaSettings() );
		m_Traders.Insert( new ref BastionVendorGabiSettings() );
		m_Traders.Insert( new ref BastionVendorGuoSettings() );
		m_Traders.Insert( new ref BastionVendorHassanSettings() );
		m_Traders.Insert( new ref BastionVendorHelgaSettings() );
		m_Traders.Insert( new ref BastionVendorIndarSettings() );
		m_Traders.Insert( new ref BastionVendorIrenaSettings() );
		m_Traders.Insert( new ref BastionVendorJoseSettings() );
		m_Traders.Insert( new ref BastionVendorJudySettings() );
		m_Traders.Insert( new ref BastionVendorKaitoSettings() );
		m_Traders.Insert( new ref BastionVendorKeikoSettings() );
		m_Traders.Insert( new ref BastionVendorLewisSettings() );
		m_Traders.Insert( new ref BastionVendorLinaSettings() );
		m_Traders.Insert( new ref BastionVendorLindaSettings() );
		m_Traders.Insert( new ref BastionVendorManuaSettings() );
		m_Traders.Insert( new ref BastionVendorMariaSettings() );
		m_Traders.Insert( new ref BastionVendorMirekSettings() );
		m_Traders.Insert( new ref BastionVendorNaomiSettings() );
		m_Traders.Insert( new ref BastionVendorNikiSettings() );
		m_Traders.Insert( new ref BastionVendorOliverSettings() );
		m_Traders.Insert( new ref BastionVendorPeterSettings() );
		m_Traders.Insert( new ref BastionVendorQuinnSettings() );
		m_Traders.Insert( new ref BastionVendorRolfSettings() );
		m_Traders.Insert( new ref BastionVendorSethSettings() );
		m_Traders.Insert( new ref BastionVendorTaikiSettings() );

		for ( int i = 0; i < m_Traders.Count(); i++ )
		{	
			m_Traders.Get(i).Load();
		}
    }

    void Defaults()
    {
        Enabled = true;
		Currency = "NCC_CopperCoin";
        
		// Civilian 
        TraderZones.Insert( new TraderZone( "BastionVendorGuo", Vector(4652, 10.23, 4221.4), Vector(139, 0, 0) ) );

		// ISF 
        TraderZones.Insert( new TraderZone( "BastionVendorBoris", Vector(4437, 10.405, 4697), Vector(0, 0, 0) ) );

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

	ref TraderPlayerSettings GetTraderByName( string name )
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