class RadiationManager : PluginBase
{
	private ref RadiationConfig rconfig;

	void RadiationManager()
	{
		rconfig = new RadiationConfig();

		if( !GetGame().IsMultiplayer() || GetGame().IsClient() )
		{					

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

			DebugCheck();
		}
	}

	void DebugCheck()
	{
		if (GetConfig().IsDebugEnabled())
			DebugSpawn();
	}

	void DebugSpawn()
	{
		array<ref RadiationAreaData> zones = rconfig.GetZones();
		vector centre, newPos;
		Object obj;
		int radius;
		float x,y,z;
		int count;
		foreach (RadiationAreaData zone : zones)
		{
			centre = zone.GetPos().ToVector();
			radius = zone.GetRadius();
			centre[1] = GetGame().SurfaceY(centre[0],centre[2]);
			count = 2.5 * radius;

			for (int i = 0; i < count; i++)
			{
				x = centre[0] + (radius * Math.Sin(i));
				y = centre[2] + (radius * Math.Cos(i));
				newPos = Vector(x,0,y);
				newPos[1] = GetGame().SurfaceY(x, y);
				obj = GetGame().CreateObject("Barrel_Red", newPos, false, false, false);
				obj.SetPosition(newPos + "0 10 0");
			}
		}
	}

	void InitRadiationHandler()
	{
		PlayerBase.Cast(GetGame().GetPlayer()).GetRadiationHandler().Init();
	}

	RadiationConfig GetConfig()
	{
		return rconfig;
	}

	void SetConfig(RadiationConfig conf)
	{
		rconfig = conf;
		rconfig.PushSuitsClient();
	}
}
RadiationManager GetRadiationManager()
{
	return RadiationManager.Cast(GetPlugin(RadiationManager));
}