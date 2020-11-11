class ADVCGpsPCServer : PluginBase
{
    void ADVCGpsPCServer() 
	{
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) 
			return;

        GetDayZGame().Event_OnRPC.Insert(OnRPC);
    }

    void ~ADVCGpsPCServer() 
	{
        GetDayZGame().Event_OnRPC.Remove(OnRPC);
    }

    void OnRPC(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx) 
	{
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) 
			return;

        if (!sender) 
			return;

		switch (rpc_type)
		{
			case -999777723: SendDeviceChildren(ctx, sender); break;
		}
	}

	void SendDeviceChildren(ParamsReadContext ctx, PlayerIdentity sender)
	{
		Param1<GpsBase> data;
		if (!ctx.Read(data))
			return;
		GpsBase gps = data.param1;
		if (gps)
			GetGame().RPCSingleParam(null, -999777724, new Param2<GpsBase, array<int>>(gps, gps.GetChildrenBits()), true, sender);
	}

}