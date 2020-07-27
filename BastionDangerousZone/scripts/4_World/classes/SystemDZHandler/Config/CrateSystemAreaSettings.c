class DZCrateSystemAreaSettings
{
	ref array<ref DZListLootConfig>ListLoots;
	ref array<ref DZ_CSArea>AreaLocation;
	int 			TimerLoot;
	bool 			IsCrateSystemActive;

	void CrateSystemAreaSettings() {
		AreaLocation = new ref array<ref DZ_CSArea>;
		ListLoots = new ref array<ref DZListLootConfig>;
	}

	void DZCrateSystemDefaultSettings()	{
		IsCrateSystemActive = 0;
		TimerLoot=2700000;
		AreaLocation = new ref array<ref DZ_CSArea>;
		AreaLocation.Insert(new ref DZ_CSArea("Zone1",1,"Animal_CanisLupus_Grey",7));
		AreaLocation.Get(0).AddCratePosition(10,"SeaChest","Army1",Vector(1396.162231, 464.568634, 14420.077148),Vector(115.000000, 0.000000, -0.000000));
		AreaLocation.Insert(new ref DZ_CSArea("Zone2",2,"Animal_CanisLupus_Grey",7));
		AreaLocation.Get(1).AddCratePosition(10,"SeaChest","Army1",Vector(1386.162231, 464.568634, 14422.077148),Vector(115.000000, 0.000000, -0.000000));
		AreaLocation.Insert(new ref DZ_CSArea("Zone3",2,"Animal_CanisLupus_Grey",7));
		AreaLocation.Get(2).AddCratePosition(10,"SeaChest","Army1",Vector(1286.162231, 464.568634, 14422.077148),Vector(115.000000, 0.000000, -0.000000));
		ListLoots = new ref array<ref DZListLootConfig>;
		ListLoots.Insert(new ref DZListLootConfig("Army1"));
		ListLoots.Get(0).AddLootConfig("AKM",0.6);
		ListLoots.Get(0).Loots.Get(0).AddAttachmentsToItem("Mag_AKM_30Rnd",0.5);
		ListLoots.Get(0).Loots.Get(0).AddAttachmentsToItem("PSO1Optic",0.5);
		ListLoots.Get(0).Loots.Get(0).AddAttachmentsToItem("Mag_AKM_Drum75Rnd",0.2);
		ListLoots.Get(0).Loots.Get(0).AddAttachmentsToItem("AK_Suppressor",0.3);
		ListLoots.Get(0).Loots.Get(0).AddAttachmentsToItem("AK_PlasticHndgrd",0.85);
		ListLoots.Get(0).Loots.Get(0).AddAttachmentsToItem("AK_RailHndgrd_Black",0.85);
		ListLoots.Get(0).Loots.Get(0).AddAttachmentsToItem("AK_Bayonet",0.4);
		ListLoots.Get(0).Loots.Get(0).AddAttachmentsToItem("AK_FoldingBttstck_Black",0.6);
		ListLoots.Get(0).AddLootConfig("M4A1",0.6);
		ListLoots.Get(0).Loots.Get(1).AddAttachmentsToItem("Mag_STANAG_30Rnd",0.5);
		ListLoots.Get(0).Loots.Get(1).AddAttachmentsToItem("Mag_STANAGCoupled_30Rnd",0.3);
		ListLoots.Get(0).Loots.Get(1).AddAttachmentsToItem("ACOGOptic",0.4);
		ListLoots.Get(0).Loots.Get(1).AddAttachmentsToItem("M4_CarryHandleOptic",0.6);
		ListLoots.Get(0).Loots.Get(1).AddAttachmentsToItem("M4_CQBBttstck",0.7);
		ListLoots.Get(0).Loots.Get(1).AddAttachmentsToItem("M4_MPBttstck",0.4);
		ListLoots.Get(0).Loots.Get(1).AddAttachmentsToItem("M4_MPHndgrd",0.7);
		ListLoots.Get(0).Loots.Get(1).AddAttachmentsToItem("M4_RISHndgrd",0.5);
		ListLoots.Get(0).Loots.Get(1).AddAttachmentsToItem("M4_Suppressor",0.4);
		ListLoots.Get(0).AddLootConfig("SVD",0.4);
		ListLoots.Get(0).Loots.Get(2).AddAttachmentsToItem("PSO1Optic",0.35);
		ListLoots.Get(0).Loots.Get(2).AddAttachmentsToItem("Mag_SVD_10Rnd",0.5);
		ListLoots.Get(0).AddLootConfig("AK74",0.6);
		ListLoots.Get(0).Loots.Get(3).AddAttachmentsToItem("AK_RailHndgrd_Black",0.7);
		ListLoots.Get(0).Loots.Get(3).AddAttachmentsToItem("AK74_WoodBttstck",0.7);
		ListLoots.Get(0).Loots.Get(3).AddAttachmentsToItem("AK_Bayonet",0.6);
		ListLoots.Get(0).Loots.Get(3).AddAttachmentsToItem("AK_FoldingBttstck_Black",0.7);
		ListLoots.Get(0).Loots.Get(3).AddAttachmentsToItem("AK_Suppressor",0.45);
		ListLoots.Get(0).Loots.Get(3).AddAttachmentsToItem("Mag_AK74_30Rnd",0.6);
		ListLoots.Insert(new ref DZListLootConfig("Army2"));
		ListLoots.Get(1).AddLootConfig("FAL",0.3);
		ListLoots.Get(1).Loots.Get(0).AddAttachmentsToItem("Fal_FoldingBttstck",0.85);
		ListLoots.Get(1).Loots.Get(0).AddAttachmentsToItem("Fal_OeBttstck",0.75);
		ListLoots.Get(1).Loots.Get(0).AddAttachmentsToItem("Mag_FAL_20Rnd",0.6);
		ListLoots.Get(1).Loots.Get(0).AddAttachmentsToItem("ACOGOptic",0.45);
		ListLoots.Get(1).AddLootConfig("AmmoBox_545x39_20Rnd",0.8);
		ListLoots.Get(1).AddLootConfig("AmmoBox_556x45_20Rnd",0.8);
		JsonFileLoader<DZCrateSystemAreaSettings>.JsonSaveFile(DZ_CS_CONFIG, this);
	}

	static ref DZCrateSystemAreaSettings Load()	{
		ref DZCrateSystemAreaSettings settings = new DZCrateSystemAreaSettings();

		if ( !FileExist( DZ_CONFIG_ROOT_SERVER ) )
		{
			MakeDirectory( DZ_CONFIG_ROOT_SERVER );
			if ( !FileExist( DZ_CONFIG_DIR_SERVER ) )
			{
				MakeDirectory( DZ_CONFIG_DIR_SERVER );
			}
		}

		if (FileExist(DZ_CS_CONFIG)) {
			JsonFileLoader<DZCrateSystemAreaSettings>.JsonLoadFile(DZ_CS_CONFIG, settings);
		}
		else {
			settings.DZCrateSystemDefaultSettings();
		}

		return settings;
	}
}
