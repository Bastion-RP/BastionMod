class RadiationAreaSettings
{
	bool			IsRadiationZoneActive;
	int 			RadCheck;
	bool 			IsMsgActive;
	string 		MsgEnterZone;
	string 		MsgExitZone;
	float 		RadChanceVomit;
	float 		RadChanceBleeding;
	float 		RadBloodLossDamage;
	float			RadHealthDamage;
	float 		RadHighMultiplier;
	int 			SuitsDamage;
	int      	CriticalProtection;
	float 		ClothesQuantityMultiplier;
	float			AmountGivenAfterCriticalProtection;
	ref array<ref RadiationZoneLocation> RadiationAreaLocation;

	void RadiationAreaSettings() {
		RadiationAreaLocation = new ref array<ref RadiationZoneLocation>;
	}

	void RadiationAreaDefaultSettings()	{
		RadCheck = 60000;
		IsMsgActive=1;
		IsRadiationZoneActive=1;
		MsgEnterZone="YOU ARE IN A RADIATION AREA!";
		MsgExitZone="YOU LEFT THE RADIATION AREA!";
		RadiationAreaLocation.Insert(new ref RadiationZoneLocation("RadZone1", 	34, 1500, 1500,  300, -1, -1, -1, -1, 0));
		RadiationAreaLocation.Insert(new ref RadiationZoneLocation("Tisy", 		12, 1655, 14068, 600, -1, -1, -1, -1, 0));
		RadChanceBleeding = 0.15;
		RadChanceVomit = 0.2;
		RadBloodLossDamage=100;
		RadHealthDamage=2;
		RadHighMultiplier = 2.5;
		SuitsDamage=5;
		CriticalProtection=70;
		ClothesQuantityMultiplier=0.15;
		AmountGivenAfterCriticalProtection = 0.2;
		JsonFileLoader<RadiationAreaSettings>.JsonSaveFile(DZ_RAD_CONFIG, this);
	}

	static ref RadiationAreaSettings Load()	{
		ref RadiationAreaSettings settings = new RadiationAreaSettings();

		if ( !FileExist( DZ_CONFIG_ROOT_SERVER ) )
		{
			MakeDirectory( DZ_CONFIG_ROOT_SERVER );
			if ( !FileExist( DZ_CONFIG_DIR_SERVER ) )
			{
				MakeDirectory( DZ_CONFIG_DIR_SERVER );
			}
		}

		if (FileExist(DZ_RAD_CONFIG)) {
			JsonFileLoader<RadiationAreaSettings>.JsonLoadFile(DZ_RAD_CONFIG, settings);
		}
		else {
			settings.RadiationAreaDefaultSettings();
		}

		return settings;
	}
}
