class RadiationRPCClient : PluginBase
{
    void RadiationRPCClient() 
	{
        if (GetGame().IsServer() && GetGame().IsMultiplayer())
		{ return; }

        GetDayZGame().Event_OnRPC.Insert(OnRPC);
    }

    void ~RadiationRPCClient() 
	{
        GetDayZGame().Event_OnRPC.Remove(OnRPC);
    }

    void OnRPC(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx) 
	{
        if (GetGame().IsServer() && GetGame().IsMultiplayer()) 
			return;

		switch (rpc_type)
		{
			case RadRPCs.RESPONSE_DATA: ApplyData(ctx); break;
		}
	}

	void ApplyData(ParamsReadContext ctx)
	{
		//Print("Apply data");
		Param1<ref RadiationConfig> data;
		if (!ctx.Read(data))
			return;

		GetRadiationManager().SetConfig(data.param1);
		GetRadiationManager().InitRadiationHandler();
	}
}