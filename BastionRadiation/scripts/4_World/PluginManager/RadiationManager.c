class RadiationManager : PluginBase
{
	private ref RadiationConfig rconfig;

	void RadiationManager()
	{
		rconfig = new RadiationConfig();

		if( !GetGame().IsMultiplayer() || GetGame().IsClient() )
		{					
			Print("RadiationManager client");
			GrabDataFromServer();
		}
		else //Server
		{
			CheckDirectories();
			LoadSuits();
			LoadZones();
		}
	}

	void CheckDirectories()
	{
		if (!FileExist(RadConst.MOD_DIR))
		{MakeDirectory(RadConst.MOD_DIR)}

		if (!FileExist(RadConst.RADIATION_DIR))
		{MakeDirectory(RadConst.RADIATION_DIR)}

		if (!FileExist(RadConst.RADIATION_SUIT_DIR))
		{MakeDirectory(RadConst.RADIATION_SUIT_DIR)}

		if (!FileExist(RadConst.RADIATION_ZONES_DIR))
		{MakeDirectory(RadConst.RADIATION_ZONES_DIR)}
	}

	void LoadSuits()
	{
		string path = RadConst.RADIATION_SUIT_DIR + "\\" + RadConst.RADIATION_SUITS_FILE;
		array<ref ItemProtectionRad> defaultData;

		if (!FileExist(path))
		{
			JsonFileLoader<array<ref ItemProtectionRad>>.JsonSaveFile( path, defaultData );
		}
		else
		{
			JsonFileLoader<array<ref ItemProtectionRad>>.JsonLoadFile( path, defaultData );

			rconfig.SetSuits(defaultData);

			ShowMap(rconfig.GetSuitsLevels());
		}
	}

	void ShowMap(map<string, ref ItemProtectionRad> arr)
	{
		Print("ShowMap ItemProtectionRad");
		for (int i = 0; i < arr.Count(); i++)
		{
			Print(string.Format("idx:%1, elem:%2", arr.GetKey(i), arr.GetElement(i)));
		}
	}

	void LoadZones()
	{
		string path = RadConst.RADIATION_ZONES_DIR + "\\" + RadConst.RADIATION_ZONES_FILE;
		array<ref RadiationAreaData> defaultData;

		if (!FileExist(path))
		{
			JsonFileLoader<array<ref RadiationAreaData>>.JsonSaveFile( path, defaultData );
		}
		else
		{
			JsonFileLoader<array<ref RadiationAreaData>>.JsonLoadFile( path, defaultData );

			rconfig.SetZones(defaultData);
		}

		ShowMapArea(rconfig.GetZones());
	}

	void ShowMapArea(map<string, ref RadiationAreaData> arr)
	{
		Print("ShowMap radzones");
		for (int i = 0; i < arr.Count(); i++)
		{
			Print(string.Format("idx:%1, elem:%2", arr.GetKey(i), arr.GetElement(i)));
		}
	}

	void GrabDataFromServer()
	{
		if (NeedGrabData())
		{
			Print("GrabData client");
			GetGame().RPCSingleParam(null, RadRPCs.REQUEST_DATA, null, true, null);
		}
	}

	bool NeedGrabData()
	{
		if ((GetConfig().GetZones().Count() == 0) || (GetConfig().GetSuitsLevels().Count() == 0))
			return true;
		return false;
	}

	RadiationConfig GetConfig()
	{
		return rconfig;
	}

	void SetConfig(RadiationConfig conf)
	{
		rconfig = conf;
	}

}
RadiationManager GetRadiationManager()
{
	return RadiationManager.Cast(GetPlugin(RadiationManager));
}