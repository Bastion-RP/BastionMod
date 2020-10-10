class ToxicManager : PluginBase
{
	private ref ToxicConfig config;
	private ref ToxGeneralSetting settings;
	private ref ToxicHandler toxicHandler;

	void ToxicManager()
	{
		if (GetGame().IsServer())
		{
			PrepareData();
		}
	}

	void PrepareData()
	{
		config = new ToxicConfig();
		CreateDirectories();
		LoadZones();
		LoadMasksSettings();
		LoadSettings();
		SpawnParticles();
	}

	void CreateDirectories()
	{
		if (!FileExist(ToxicConsts.TOXIC_DIR))
		{MakeDirectory(ToxicConsts.TOXIC_DIR)}
	}

	void LoadZones()
	{
		string path = ToxicConsts.TOXIC_ZONES_FILENAME;
		array<ref ToxicAreaData> defaultData;

		if (!FileExist(path))
		{
			defaultData = new array<ref ToxicAreaData>();
			array<ref ParticlesData> tempData = new array<ref ParticlesData>();
			tempData.Insert(new ParticlesData("GreenSpore", "0 0 0"));
			tempData.Insert(new ParticlesData("WeirdGreenSpore", "0 0 0"));
			tempData.Insert(new ParticlesData("WeirdGreenSpore2", "0 0 0"));
			tempData.Insert(new ParticlesData("PurpleSpore", "0 0 0"));
			tempData.Insert(new ParticlesData("BlueSpore", "0 0 0"));
			tempData.Insert(new ParticlesData("RedSpore", "0 0 0"));
			tempData.Insert(new ParticlesData("WhiteSpore", "0 0 0"));
			defaultData.Insert(new ToxicAreaData("100 0 100", 10, tempData));
			JsonFileLoader<array<ref ToxicAreaData>>.JsonSaveFile( path, defaultData );
		}
		else
		{
			JsonFileLoader<array<ref ToxicAreaData>>.JsonLoadFile( path, defaultData );
		}

		config.SetAreas(defaultData);
	}

	void LoadMasksSettings()
	{
		string path = ToxicConsts.TOXIC_SUIT_FILENAME;
		array<string> defaultData;

		if (!FileExist(path))
		{
			defaultData = new array<string>();
			defaultData.Insert("GasMask");
			defaultData.Insert("GP5GasMask");
			JsonFileLoader<array<string>>.JsonSaveFile( path, defaultData );
		}
		else
		{
			JsonFileLoader<array<string>>.JsonLoadFile( path, defaultData );
		}

		config.SetProtectableMaskList(defaultData);
	}

	void LoadSettings()
	{
		string path = ToxicConsts.TOXIC_SETTINGS_FILENAME;
		if (!FileExist(path))
		{
			settings = new ToxGeneralSetting(0.1, 0.1, 0.1);
			JsonFileLoader<ToxGeneralSetting>.JsonSaveFile( path, settings );
		}
		else
		{
			JsonFileLoader<ToxGeneralSetting>.JsonLoadFile( path, settings );
		}
	}

	void SpawnParticles()
	{
		array<ref ToxicAreaData> toxicDatas = GetConfig().GetZones();
		vector pos;
		string type;
		foreach (ToxicAreaData toxicData : toxicDatas)
		{
			array<ref ParticlesData> particlesArr = toxicData.GetPTCArray();
			foreach (ParticlesData ptcData : particlesArr)
			{
				type = ptcData.GetType();
				pos = ptcData.GetPos();
				GetGame().CreateObject(type, pos, false);
			}
		}
	}

	void InitToxicHandler()
	{
		if (!toxicHandler)
		{
			toxicHandler = new ToxicHandler();
			toxicHandler.Init();
		}
	}

	void SetConfig(ToxicConfig config)
	{
		this.config = config;
	}

	ToxicConfig GetConfig()
	{
		return config;
	}

	ToxGeneralSetting GetSettings()
	{
		return settings;
	}
}
ToxicManager GetToxicManager()
{
	return ToxicManager.Cast(GetPlugin(ToxicManager));
}