class BRP_KickedPlayerConfig
{
	private const static string					SETTINGS = "$profile:\\ModConfigs\\KickedPlayerConfig.json";
	ref BRP_KickedPlayerConfigData				kickedPlayerConfigData;

	void BRP_KickedPlayerConfig()
	{
		if (GetGame().IsServer() && GetGame().IsMultiplayer())
		{
			Load();
		}
	}

	ref BRP_KickedPlayerConfigData GetConfig()
	{
		return kickedPlayerConfigData;
	}
	
	void Load()
	{
		if (GetGame().IsServer() && GetGame().IsMultiplayer())
		{
			if (FileExist(SETTINGS))
			{
				
				kickedPlayerConfigData = new BRP_KickedPlayerConfigData();
				JsonSerializer js = new JsonSerializer();
		
				string js_error = "";
				string line_content = "";
				string content = "";
				JsonFileLoader<BRP_KickedPlayerConfigData>.JsonLoadFile(SETTINGS, kickedPlayerConfigData);
				
			}
			else
			{
				Create();
			}
		}
	}

	void Create()
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
			kickedPlayerConfigData = new BRP_KickedPlayerConfigData();
			kickedPlayerConfigData.InActiveTimeToKick = 30;

			JsonFileLoader< ref BRP_KickedPlayerConfigData >.JsonSaveFile(SETTINGS, kickedPlayerConfigData);
			
		}
	}
}

class BRP_KickedPlayerConfigData
{
	int InActiveTimeToKick;
}