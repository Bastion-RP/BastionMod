class STCConfig
{
	bool AddTimeForEachItem;
	int DefaultTimeToSearchPlayer;
	int DefaultTimeToSearchZombie;
	int TimeForEachItem;

	void setSTCConfig(bool _AddTimeForEachItem, int _DefaultTimeToSearchPlayer, int _DefaultTimeToSearchZombie, int _TimeForEachItem)
	{
		AddTimeForEachItem = _AddTimeForEachItem;
		DefaultTimeToSearchPlayer = _DefaultTimeToSearchPlayer;
		DefaultTimeToSearchZombie = _DefaultTimeToSearchZombie;
		TimeForEachItem = _TimeForEachItem;
	}

	void STCConfig()
	{

	}
}

class STCConfigBase
{
	ref STCConfig		stcConfig;
	private const static string		SETTINGS = "$profile:\\ModConfigs\\STCConfig.json";

	ref STCConfig GetConfig()
	{
		return stcConfig;
	}
	
	void STCConfigBase()
	{
		if (GetGame().IsServer() && GetGame().IsMultiplayer())
		{
			Load();
		}
	}


	void Load()
	{
		if (GetGame().IsServer() && GetGame().IsMultiplayer())
		{
			if (FileExist(SETTINGS))
			{
				stcConfig = new ref STCConfig;
				JsonSerializer js = new JsonSerializer();
				JsonFileLoader<ref STCConfig >.JsonLoadFile(SETTINGS, stcConfig);
			}
			else
			{
				Create();
			}
		}
	}

	protected void Create()
    {
		if (GetGame().IsServer() && GetGame().IsMultiplayer())
		{
			

			if (!FileExist("$profile:\\ModConfigs"))
			{
				MakeDirectory("$profile:\\ModConfigs");
			}
			Save();
			Load();
		}
    }

    void Save()
    {
		if (GetGame().IsServer() && GetGame().IsMultiplayer())
		{
			stcConfig = new ref STCConfig;
			stcConfig.setSTCConfig(true, 10, 3, 2);

			JsonFileLoader<STCConfig >.JsonSaveFile(SETTINGS, stcConfig);
		}
	}
}