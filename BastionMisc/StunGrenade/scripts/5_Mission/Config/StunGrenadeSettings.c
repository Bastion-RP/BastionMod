class StunProtectiveGear
{
	string PGName;
	int PGProtection;
	
	void StunProtectiveGear(string pgname, int pgprotection)
	{
		PGName=pgname;
		PGProtection=pgprotection;
	}
}

class StunGrenadeSettings
{
	int SGTimerCheck;
	ref array<ref StunProtectiveGear>ProtectiveGearList;

    void StunGrenadeSettings(){
		ProtectiveGearList = new ref array<ref StunProtectiveGear>;
    }

    private void StunGrenadeDefaultSettings()
    {
		SGTimerCheck=10;
		ProtectiveGearList.Insert(new ref StunProtectiveGear("GP5GasMask",0));
		ProtectiveGearList.Insert(new ref StunProtectiveGear("GasMask",0));
		ProtectiveGearList.Insert(new ref StunProtectiveGear("SurgicalMask",34));
		JsonFileLoader<StunGrenadeSettings>.JsonSaveFile(SG_CONFIG, this);
    }
	
	static ref StunGrenadeSettings Load()	{
		ref StunGrenadeSettings settings = new StunGrenadeSettings();
		
		if ( !FileExist( SG_CONFIG_ROOT_SERVER ) )
		{
			MakeDirectory( SG_CONFIG_ROOT_SERVER );
		}

		if (FileExist(SG_CONFIG)) {
			JsonFileLoader<StunGrenadeSettings>.JsonLoadFile(SG_CONFIG, settings);
			Print("file found !");
		}
		else {
			settings.StunGrenadeDefaultSettings();
		}

		return settings;
	}

}