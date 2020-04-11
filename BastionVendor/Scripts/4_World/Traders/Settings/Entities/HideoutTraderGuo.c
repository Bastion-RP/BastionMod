class BastionVendorGuoSettings: TraderPlayerSettings
{
    override void Defaults()
    {
        DisplayName = "DART Vendor";

        VehicleParts.Insert("");
        
        Loadout.Insert("QuiltedJacket_Black");
        Loadout.Insert("SlacksPants_Black");
        Loadout.Insert("HikingBoots_Black");

        TraderItems.Clear();

        // Classname, sell price (ignore), price, vehicle (ignore), vehicle parts (ignore)
        TraderItems.Insert( new ref BastionVendorItems( "BastionRP_ISF_CarrierRig", 1, 0, false, VehicleParts ) );
        TraderItems.Insert( new ref BastionVendorItems( "TacticalGloves_Black", 1, 0, false, VehicleParts ) );
        TraderItems.Insert( new ref BastionVendorItems( "BRP_Tactical_Jacket_Black", 1, 0, false, VehicleParts ) );
        TraderItems.Insert( new ref BastionVendorItems( "BastionRP_ISF_DART_Helmet", 1, 0, false, VehicleParts ) );
        TraderItems.Insert( new ref BastionVendorItems( "MilitaryBoots_Black ", 1, 0, false, VehicleParts ) );
        TraderItems.Insert( new ref BastionVendorItems( "BastionRP_ISF_DART_Pants", 1, 0, false, VehicleParts ) );   
        TraderItems.Insert( new ref BastionVendorItems( "ISF_MolleBelt", 1, 0, false, VehicleParts ) );   
        TraderItems.Insert( new ref BastionVendorItems( "Flashbang", 1, 0, false, VehicleParts ) );
        TraderItems.Insert( new ref BastionVendorItems( "M18SmokeGrenade_White", 1, 0, false, VehicleParts ) );
        TraderItems.Insert( new ref BastionVendorItems( "BandageDressing", 1, 0, false, VehicleParts ) );
        TraderItems.Insert( new ref BastionVendorItems( "SalineBagIV", 1, 0, false, VehicleParts ) );
        TraderItems.Insert( new ref BastionVendorItems( "BastionRP_AION", 1, 0, false, VehicleParts ) );
        TraderItems.Insert( new ref BastionVendorItems( "Morphine", 1, 0, false, VehicleParts ) );
        TraderItems.Insert( new ref BastionVendorItems( "Handcuffs", 1, 0, false, VehicleParts ) );
        TraderItems.Insert( new ref BastionVendorItems( "HandcuffKeys", 1, 0, false, VehicleParts ) );
        TraderItems.Insert( new ref BastionVendorItems( "StunBaton", 1, 0, false, VehicleParts ) );
        TraderItems.Insert( new ref BastionVendorItems( "Battery9V", 1, 0, false, VehicleParts ) );
        TraderItems.Insert( new ref BastionVendorItems( "BastionRPGuns_CSR556", 1, 0, false, VehicleParts ) );
        TraderItems.Insert( new ref BastionVendorItems( "Mag_STANAG_30Rnd", 1, 0, false, VehicleParts ) );
        TraderItems.Insert( new ref BastionVendorItems( "M68Optic", 1, 0, false, VehicleParts ) );
        TraderItems.Insert( new ref BastionVendorItems( "ACOGOptic", 1, 0, false, VehicleParts ) );
        CategoriesItems.Insert( new ref BastionVendorCattegories( "Loadout", TraderItems ) );

        TraderItems = new array< ref BastionVendorItems >;

        TraderItems.Insert( new ref BastionVendorItems( "BastionRPGuns_P226", 1, 0, false, VehicleParts ) );
        TraderItems.Insert( new ref BastionVendorItems( "Mag_P226_10Rnd", 1, 0, false, VehicleParts ) );    
        TraderItems.Insert( new ref BastionVendorItems( "TLRLight", 1, 0, false, VehicleParts ) ); 
        TraderItems.Insert( new ref BastionVendorItems( "BastionRPGuns_CSC45", 1, 0, false, VehicleParts ) );
        TraderItems.Insert( new ref BastionVendorItems( "Magazine_CSC45_30Rnd", 1, 0, false, VehicleParts ) );    
        TraderItems.Insert( new ref BastionVendorItems( "BastionRP_microt1", 1, 0, false, VehicleParts ) );    
        CategoriesItems.Insert( new ref BastionVendorCattegories( "Weapons", TraderItems ) );

        TraderItems = new array< ref BastionVendorItems >;

        TraderItems.Insert( new ref BastionVendorItems( "TetracyclineAntibiotics", 1, 0, false, VehicleParts ) );
        TraderItems.Insert( new ref BastionVendorItems( "Epinephrine", 1, 0, false, VehicleParts ) );
        CategoriesItems.Insert( new ref BastionVendorCattegories( "Medical", TraderItems ) );

        TraderItems = new array< ref BastionVendorItems >;

        TraderItems.Insert( new ref BastionVendorItems( "NVGoggles", 1, 0, false, VehicleParts ) );
        TraderItems.Insert( new ref BastionVendorItems( "AviatorGlasses", 1, 0, false, VehicleParts ) );
        TraderItems.Insert( new ref BastionVendorItems( "BalaclavaMask_Black", 1, 0, false, VehicleParts ) );
        TraderItems.Insert( new ref BastionVendorItems( "SportGlasses_Black", 1, 0, false, VehicleParts ) );
        CategoriesItems.Insert( new ref BastionVendorCattegories( "Apparel", TraderItems ) );

        VehiclePosition = "0 0 0";
        
        string className = ClassName();
        className.Replace("Settings", "");
        TraderName = className;
		
        if ( !FileExist( "$profile:Bastion\\Vendors\\Traders\\" ) )
		{
			MakeDirectory( "$profile:Bastion\\Vendors\\Traders\\" );
		}

		JsonFileLoader<TraderPlayerSettings>.JsonSaveFile( "$profile:Bastion\\Vendors\\Traders\\" + GetFileName(), this );
    }

    override string GetFileName()
    {
        return "BastionVendorGuo.json";
    }
}