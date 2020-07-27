class HazardAreaSettings
{
	bool 				IsHazardZoneActive;
	bool 				IsMsgActive;
	string 				MsgEnterZone;
	string 				MsgExitZone;
	int 				HazardCheck;
	float 				HazardShockValue;
	float 				HazardChanceCough;
	float       		HazardChanceShock;
	int 				NbSickGivenForHazard;
	float 				GasMaskDamage;
	ref array<ref HazardZoneLocation> HazardAreaLocation;

	void HazardAreaSettings() {
		HazardAreaLocation = new ref array<ref HazardZoneLocation>;
	}

	void HazardAreaDefaultSettings()	{
		GasMaskDamage=20;
		IsHazardZoneActive=1;
		HazardCheck = 45000;
		IsMsgActive=1;
		MsgEnterZone="YOU ARE IN A Hazard AREA!";
		MsgExitZone="YOU LEFT THE Hazard AREA!";
		HazardAreaLocation.Insert(new ref HazardZoneLocation(0,"Kamenks", 7890, 14697, 300, -1,-1,-1,-1));
		HazardAreaLocation.Get(0).AddParticlePosition("GreenSpore",Vector(8010, 0, 14625));
		HazardAreaLocation.Get(0).AddParticlePosition("GreenSpore",Vector(7794, 0, 14788));
		HazardAreaLocation.Get(0).AddParticlePosition("GreenSpore",Vector(7871, 0, 14700));
		HazardAreaLocation.Get(0).AddParticlePosition("GreenSpore",Vector(7691, 0, 14855));
		HazardAreaLocation.Get(0).AddParticlePosition("GreenSpore",Vector(7904, 0, 14585));
		HazardAreaLocation.Get(0).AddParticlePosition("GreenSpore",Vector(7814, 0, 14542));
		HazardAreaLocation.Get(0).AddParticlePosition("GreenSpore",Vector(7766, 0, 14639));
		HazardAreaLocation.Get(0).AddParticlePosition("GreenSpore",Vector(7725, 0, 14706));
		HazardAreaLocation.Get(0).AddParticlePosition("GreenSpore",Vector(8019, 0, 14758));
		HazardAreaLocation.Get(0).AddParticlePosition("GreenSpore",Vector(7644, 0, 14750));
		HazardAreaLocation.Get(0).AddParticlePosition("GreenSpore",Vector(7910, 0, 14724));
		HazardAreaLocation.Get(0).AddParticlePosition("GreenSpore",Vector(7916, 0, 14627));
		HazardAreaLocation.Get(0).AddParticlePosition("GreenSpore",Vector(8115, 0, 14563));
		HazardAreaLocation.Get(0).AddParticlePosition("GreenSpore",Vector(8161, 0, 14706));
		HazardAreaLocation.Get(0).AddParticlePosition("GreenSpore",Vector(8003, 0, 14538));
		HazardAreaLocation.Insert(new ref HazardZoneLocation(1,"Hazard2", 3000, 12000, 600,-1,-1,-1,-1));
		NbSickGivenForHazard=34;
		HazardShockValue=5;
		HazardChanceCough=0.1;
		HazardChanceShock=0.2;
		JsonFileLoader<HazardAreaSettings>.JsonSaveFile(DZ_HAZARD_CONFIG, this);
	}

	static ref HazardAreaSettings Load()	{
		ref HazardAreaSettings settings = new HazardAreaSettings();

		if ( !FileExist( DZ_CONFIG_ROOT_SERVER ) )
		{
			MakeDirectory( DZ_CONFIG_ROOT_SERVER );
			if ( !FileExist( DZ_CONFIG_DIR_SERVER ) )
			{
				MakeDirectory( DZ_CONFIG_DIR_SERVER );
			}
		}

		if (FileExist(DZ_HAZARD_CONFIG)) {
			JsonFileLoader<HazardAreaSettings>.JsonLoadFile(DZ_HAZARD_CONFIG, settings);
		}
		else {
			settings.HazardAreaDefaultSettings();
		}

		return settings;
	}
}
