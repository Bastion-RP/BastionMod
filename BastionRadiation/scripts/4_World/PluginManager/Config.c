class RadiationConfig
{
	private ref map <string, ref ItemProtectionRad> SuitProtectLevels;
	private ref map <string, ref RadiationAreaData> RadiationZones;

	void RadiationConfig()
	{
		SuitProtectLevels = new map <string, ref ItemProtectionRad>();
		RadiationZones = new map <string, ref RadiationAreaData>();
	}

	void SetSuits(array<ref ItemProtectionRad> defaultData)
	{
		foreach (ref ItemProtectionRad item : defaultData)
		{
			SuitProtectLevels.Insert(item.GetType(), item);
		}
	}

	void SetZones(array<ref RadiationAreaData> defaultData)
	{
		foreach (ref RadiationAreaData item : defaultData)
		{
			RadiationZones.Insert(item.GetPos(), item);
		}
	}

	map <string, ref ItemProtectionRad> GetSuitsLevels() { return SuitProtectLevels; }
	map <string, ref RadiationAreaData> GetZones() { return RadiationZones; }
}