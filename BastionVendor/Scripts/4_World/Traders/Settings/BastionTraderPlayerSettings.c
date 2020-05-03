class BastionVendorItems
{
    string ClassName;
    int SellPrice;
    int BuyPrice;
    bool Vehicle;

    ref array< string > VehicleParts;

    void BastionVendorItems( string className, int sellPrice, int buyPrice, bool vehicle, ref array< string > vehicleParts )
	{
        if (!VehicleParts)
        {
            VehicleParts = new array < string >;
        }

		ClassName = className;
        SellPrice = sellPrice;
        BuyPrice = buyPrice;
        Vehicle = vehicle;
        VehicleParts = vehicleParts;
	}
}

class BastionVendorCattegories
{
    string Name;
    ref array< ref BastionVendorItems > Items;

    void BastionVendorCattegories( string name, ref array< ref BastionVendorItems> items )
    {
        if (!Items)
        {
            Items = new array< ref BastionVendorItems >;
        }

        Items = items;
        Name = name;
    }
}

class TraderVendorSettings
{
    vector VehiclePosition;
    
    string TraderName;
    string DisplayName;

    ref array< ref BastionVendorCattegories > CategoriesItems;

    [NonSerialized()]
    ref array< string > VehicleParts;

    [NonSerialized()]
    ref array< ref BastionVendorItems > TraderItems;

    string GetFileName()
    {
        return "";
    }

    void TraderVendorSettings()
    {
        VehicleParts = new array < string >;

		TraderItems = new array< ref BastionVendorItems >;
        CategoriesItems = new array< ref BastionVendorCattegories >;
    }

    void Defaults()
    {
        DisplayName = "Default Trader";

        VehicleParts.Insert("");

        TraderItems.Clear();

        TraderItems.Insert( new ref BastionVendorItems( "Bandana_RedPattern", 1, 1, false, VehicleParts ) );
        TraderItems.Insert( new ref BastionVendorItems( "Bandana_BlackPattern", 1, 1, false, VehicleParts ) );
        TraderItems.Insert( new ref BastionVendorItems( "Bandana_PolkaPattern", 1, 1, false, VehicleParts ) );
        TraderItems.Insert( new ref BastionVendorItems( "Bandana_Greenpattern", 1, 1, false, VehicleParts ) );
        TraderItems.Insert( new ref BastionVendorItems( "Bandana_CamoPattern", 1, 1, false, VehicleParts ) );
        CategoriesItems.Insert( new ref BastionVendorCattegories( "Bandanas", TraderItems ) );

        TraderItems = new array< ref BastionVendorItems >;

        TraderItems.Insert( new ref BastionVendorItems( "Bandana_BlackPattern", 1, 1, false, VehicleParts ) );
        TraderItems.Insert( new ref BastionVendorItems( "Bandana_PolkaPattern", 1, 1, false, VehicleParts ) );
        TraderItems.Insert( new ref BastionVendorItems( "Bandana_Greenpattern", 1, 1, false, VehicleParts ) );
        TraderItems.Insert( new ref BastionVendorItems( "Bandana_CamoPattern", 1, 1, false, VehicleParts ) );
        TraderItems.Insert( new ref BastionVendorItems( "Bandana_RedPattern", 1, 1, false, VehicleParts ) );     
        CategoriesItems.Insert( new ref BastionVendorCattegories( "Something", TraderItems ) );

        VehiclePosition = "0 0 0";
        
        string className = ClassName();
        className.Replace("Settings", "");
        TraderName = className;
		
        if ( !FileExist( "$profile:Bastion\\Vendors\\Traders\\" ) )
		{
			MakeDirectory( "$profile:Bastion\\Vendors\\Traders\\" );
		}

		JsonFileLoader<TraderVendorSettings>.JsonSaveFile( "$profile:Bastion\\Vendors\\Traders\\" + GetFileName(), this );
    }

    void Load()
	{
		if ( FileExist( "$profile:Bastion\\Vendors\\Traders\\" + GetFileName() ) )
		{
			JsonFileLoader<TraderVendorSettings>.JsonLoadFile( "$profile:Bastion\\Vendors\\Traders\\" + GetFileName(), this );
		} 
		else 
		{
			Defaults();
		}
	}
}