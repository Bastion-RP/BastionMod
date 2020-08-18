class InfectedAreaSettings
{
	bool			IsInfectedZoneActive;
	int 			InfectedCheck;
	ref array<ref InfectedZoneLocation> InfectedAreaLocation;

	void InfectedAreaSettings() {
		InfectedAreaLocation = new ref array<ref InfectedZoneLocation>;
	}

	void InfectedAreaDefaultSettings()	{
		InfectedCheck = 900000;
		IsInfectedZoneActive=1;
		InfectedAreaLocation.Insert(new ref InfectedZoneLocation("InfectedZone1", 15, 7890, 14697, 150));
		InfectedAreaLocation.Get(0).AddCreatureToList("Animal_CanisLupus_Grey",7);
		InfectedAreaLocation.Get(0).AddCreatureToList("Animal_UrsusArctos",1);
		InfectedAreaLocation.Get(0).AddCreatureToList("ZmbM_HermitSkinny_Green",15);
		InfectedAreaLocation.Get(0).AddCreatureToList("ZmbM_FarmerFat_Brown",1);
		InfectedAreaLocation.Get(0).AddCreatureToList("ZmbM_FarmerFat_Blue",5);
		InfectedAreaLocation.Get(0).AddCreatureToList("ZmbM_HermitSkinny_Beige",9);
		InfectedAreaLocation.Insert(new ref InfectedZoneLocation("InfectedZone2", 30, 7500, 7500, 250));
		InfectedAreaLocation.Get(1).AddCreatureToList("Animal_CanisLupus_Grey",7);
		InfectedAreaLocation.Get(0).AddCreatureToList("ZmbM_HermitSkinny_Green",6);
		InfectedAreaLocation.Get(0).AddCreatureToList("ZmbM_FarmerFat_Brown",17);
		InfectedAreaLocation.Get(0).AddCreatureToList("ZmbM_FarmerFat_Blue",5);
		InfectedAreaLocation.Get(0).AddCreatureToList("ZmbM_HermitSkinny_Beige",9);
		InfectedAreaLocation.Insert(new ref InfectedZoneLocation("InfectedZone3", 50, 8000, 10000, 300));
		InfectedAreaLocation.Get(2).AddCreatureToList("Animal_CanisLupus_Grey",7);
		InfectedAreaLocation.Get(0).AddCreatureToList("ZmbM_HermitSkinny_Green",10);
		InfectedAreaLocation.Get(0).AddCreatureToList("ZmbM_FarmerFat_Brown",6);
		InfectedAreaLocation.Get(0).AddCreatureToList("ZmbM_FarmerFat_Blue",9);
		InfectedAreaLocation.Get(0).AddCreatureToList("ZmbM_HermitSkinny_Beige",5);
		JsonFileLoader<InfectedAreaSettings>.JsonSaveFile(DZ_INFECTED_CONFIG, this);
	}

	static ref InfectedAreaSettings Load()	{
		ref InfectedAreaSettings settings = new InfectedAreaSettings();

		if ( !FileExist( DZ_CONFIG_ROOT_SERVER ) )
		{
			MakeDirectory( DZ_CONFIG_ROOT_SERVER );
			if ( !FileExist( DZ_CONFIG_DIR_SERVER ) )
			{
				MakeDirectory( DZ_CONFIG_DIR_SERVER );
			}
		}

		if (FileExist(DZ_INFECTED_CONFIG)) {
			JsonFileLoader<InfectedAreaSettings>.JsonLoadFile(DZ_INFECTED_CONFIG, settings);
		}
		else {
			settings.InfectedAreaDefaultSettings();
		}

		return settings;
	}
}
