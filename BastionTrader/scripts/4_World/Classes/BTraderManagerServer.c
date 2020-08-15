class BTraderManagerServer
{
	private ref map<int, ref TraderData> AllTradersData;
	private ref BTraderConfig	config;


	void BTraderManagerServer()
	{
		if (GetGame().IsClient() || !GetGame().IsMultiplayer())
		{
			delete this;
		}

		AllTradersData = new map<int, ref TraderData>();

		CheckDirectories();

		LoadAndSpawnTraders();

		LoadConfig();
	}

	void CheckDirectories()
	{
		if (!FileExist(BTrdConst.MOD_DIR))
		{
			MakeDirectory(BTrdConst.MOD_DIR);
		}
		if (!FileExist(BTrdConst.TRADER_DATA_DIR))
		{
			MakeDirectory(BTrdConst.TRADER_DATA_DIR);
		}
	}

	void LoadAndSpawnTraders()
	{
		string fileName;
		FileAttr fileAttr;
		string path;

		path = BTrdConst.TRADER_DATA_DIR + "/*.json";
		FindFileHandle traderDataFile = FindFile(path, fileName, fileAttr, 0);
		
		if (!traderDataFile)
			return;

		InsertTraderData(fileName);

		while(FindNextFile(traderDataFile, fileName, fileAttr))
		{
			InsertTraderData(fileName);
		}

		CloseFindFile(traderDataFile);
	}

	void InsertTraderData(string filename)
	{
		TraderData traderData;
		string path;
		bool isValidData;
		int traderId;

		path = BTrdConst.TRADER_DATA_DIR + "\\" + filename;
		traderData = new TraderData();
		isValidData = false;

		JsonFileLoader<ref TraderData>.JsonLoadFile( path, traderData );

		traderId = traderData.GetId();
		isValidData = traderId;

		if (isValidData)
		{
			AllTradersData.Insert(traderId, traderData);
			SpawnTrader(traderData);
		}
	}

	void SpawnTrader(TraderData data)
	{
		string type;
		Object obj;
		PlayerBase traderPlayer;
		BuildingBase traderObject;

		type = data.GetType();

		obj = GetGame().CreateObject(type, vector.Zero, false, false);

		if (!obj) return;

		if (Class.CastTo(traderPlayer, obj))
		traderPlayer.SetupTrader(data);
		else if (Class.CastTo(traderObject, obj))
		traderObject.SetupTrader(data);
	}

	map<int, ref TraderData> GetTradersData() { return AllTradersData; }
	ref BTraderConfig GetConfig() { return config; }

	void LoadConfig()
	{
		if (!FileExist(BTrdConst.CONFIG_DIR))
		{
			config = new BTraderConfig();
			config.Validate();
			JsonFileLoader<ref BTraderConfig>.JsonSaveFile( BTrdConst.CONFIG_DIR, config );
		}
		else
		{
			JsonFileLoader<ref BTraderConfig>.JsonLoadFile( BTrdConst.CONFIG_DIR, config );
			config.Validate();
		}
	}
}

ref BTraderManagerServer g_BTMS;