class RadiationConfig
{
	private ref RadiationSetting RadiationSettings;
	private ref map <string, ref ItemProtectionRad> SuitProtectLevelsMap;
	private ref array<ref RadiationAreaData> RadiationZones;
	private ref array<ref ItemProtectionRad> SuitProtectLevels;

	void RadiationConfig()
	{
		RadiationSettings = new RadiationSetting();
		SuitProtectLevelsMap = new map <string, ref ItemProtectionRad>();
		SuitProtectLevels = new array<ref ItemProtectionRad>();
		RadiationZones = new array<ref RadiationAreaData>();
	}

	void SetSettings(RadiationSetting sett)
	{
		RadiationSettings = sett;
	}

	void SetSuits(array<ref ItemProtectionRad> defaultData)
	{
		SuitProtectLevels = defaultData;
	}

	void SetZones(array<ref RadiationAreaData> defaultData)
	{
		RadiationZones = defaultData;
	}

	void PushSuitsClient()
	{
		foreach (ref ItemProtectionRad item : SuitProtectLevels)
		{
			SuitProtectLevelsMap.Insert(item.GetType(), item);
		}
	}

	RadiationSetting GetSettings() { return RadiationSettings; }
	map <string, ref ItemProtectionRad> GetSuitsLevels() { return SuitProtectLevelsMap; }
	array<ref RadiationAreaData> GetZones() { return RadiationZones; }
}