class ADVCGps : PluginBase
{
	private ref GpsUI gpsUI;
	private bool showGps;
	private ref GpsConfig config;

	void ADVCGps()
	{
		showGps = false;
		if (GetGame().IsServer())
		{
			LoadConfig();
		}
	}

	void ~ADVCGps()
	{
		if (GetGame() && GetGame().IsClient() && gpsUI)
		{
			SaveGPSSettings();
		}
	}

	void LoadConfig()
	{
		if (!FileExist(GpsConsts.MOD_DIR))
			MakeDirectory(GpsConsts.MOD_DIR);
		if (FileExist(GpsConsts.SET_DIR))
			JsonFileLoader<GpsConfig>.JsonLoadFile( GpsConsts.SET_DIR, config );
		else {
			config = new GpsConfig();
			config.Default();
			JsonFileLoader<GpsConfig>.JsonSaveFile( GpsConsts.SET_DIR, config );
		}
	}

	void OnUpdate()
	{
		float mdfr = 1;
		Input input = GetGame().GetInput();

		if (input.LocalPress("ADVGPSTOGGLE", false))
			TryToogleGPS();
		
		if (!gpsUI || !gpsUI.IsVisible())
			return;

		if (input.LocalPress("ADVGPSZOOMIN", false))
			gpsUI.UpdateScale(-0.1);
		if (input.LocalPress("ADVGPSZOOMOUT", false))
			gpsUI.UpdateScale(0.1);

		if (input.LocalHold("UATurbo", false))
			mdfr = 10;

		if (config.IsDebug())
		{
			if (input.LocalPress("ADVGPSMOVEHORUP", false) || input.LocalHold("ADVGPSMOVEHORUP", false))
				gpsUI.ChangeScaleX(1);
			if (input.LocalPress("ADVGPSMOVEHORDW", false) || input.LocalHold("ADVGPSMOVEHORDW", false))
				gpsUI.ChangeScaleX(-1);
			if (input.LocalPress("ADVGPSMOVEVERTUP", false) || input.LocalHold("ADVGPSMOVEVERTUP", false))
				gpsUI.ChangeScaleY(-1);
			if (input.LocalPress("ADVGPSMOVEVERTDW", false) || input.LocalHold("ADVGPSMOVEVERTDW", false))
				gpsUI.ChangeScaleY(1);
		} else {
			if (input.LocalPress("ADVGPSMOVEHORUP", false) || input.LocalHold("ADVGPSMOVEHORUP", false))
				gpsUI.Move(1 * mdfr, 0);
			if (input.LocalPress("ADVGPSMOVEHORDW", false) || input.LocalHold("ADVGPSMOVEHORDW", false))
				gpsUI.Move(-1 * mdfr, 0);
			if (input.LocalPress("ADVGPSMOVEVERTUP", false) || input.LocalHold("ADVGPSMOVEVERTUP", false))
				gpsUI.Move(0, -1 * mdfr);
			if (input.LocalPress("ADVGPSMOVEVERTDW", false) || input.LocalHold("ADVGPSMOVEVERTDW", false))
				gpsUI.Move(0, 1 * mdfr);
		}
	}


	void ToogleGPS(bool val)
	{
		if (!gpsUI)
			gpsUI = new GpsUI();
		
		showGps = val;//!showGps;

		gpsUI.Show(showGps);
	}

	void TryToogleGPS()
	{
		array<EntityAI> itemsArray;
		GpsBase gpsItem;
		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
		if (showGps)
		{
			ToogleGPS(false);
		} else 
		{
			if (player)
			{
				if (player.GetGpsState())
					ToogleGPS(true);
			}
		}
	}

	static void Mess(string text)
	{
		GetGame().GetMission().OnEvent(ChatMessageEventTypeID, new ChatMessageEventParams(CCDirect, "", text, ""));
	}

	void SaveGPSSettings()
	{
		GpsData data = new GpsData();
		data.SetData(gpsUI.GetSettings());
		JsonFileLoader<GpsData>.JsonSaveFile( GpsConsts.CONFIG_DIR, data );
	}

	void DestroyUI()
	{
		if (gpsUI)
			delete gpsUI;
	}

	GpsConfig GetConfig() { return config; }
	void SetConfig(GpsConfig cfg) 
	{ 
		config = cfg;
		OnConfigReceived();
	}

	void OnConfigReceived()
	{
		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
		if (player)
		{
			player.SetGpsState(0);
			ToogleGPS(false);
		}
	}
}
ADVCGps GetADVCGps()
{
	return ADVCGps.Cast(GetPlugin(ADVCGps));
}