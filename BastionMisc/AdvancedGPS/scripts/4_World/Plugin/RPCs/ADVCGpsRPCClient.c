class ADVCGpsPCClient : PluginBase
{
	void ADVCGpsPCClient() 
	{
        if (GetGame().IsServer() && GetGame().IsMultiplayer()) 
			return;

        GetDayZGame().Event_OnRPC.Insert(OnRPC);
    }

    void ~ADVCGpsPCClient() 
	{
        GetDayZGame().Event_OnRPC.Remove(OnRPC);
    }

    void OnRPC(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx) 
	{
        if (GetGame().IsServer() && GetGame().IsMultiplayer()) 
			return;

		switch (rpc_type)
		{
			case -999777722: SetConfig(ctx); break;
		}

	}

	void SetConfig(ParamsReadContext ctx)
	{
		Param1<ref GpsConfig> data;
		if (!ctx.Read(data))
			return;
		GetADVCGps().SetConfig(data.param1);
	}

}