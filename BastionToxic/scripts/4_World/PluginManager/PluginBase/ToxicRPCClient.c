class ToxicRPCClient : PluginBase
{
	void ToxicRPCClient() 
	{
        if (GetGame().IsServer() && GetGame().IsMultiplayer())
		{ return; }

        GetDayZGame().Event_OnRPC.Insert(OnRPC);
    }

    void ~ToxicRPCClient() 
	{
        GetDayZGame().Event_OnRPC.Remove(OnRPC);
    }

    void OnRPC(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx) 
	{
        if (GetGame().IsServer() && GetGame().IsMultiplayer()) 
			return;

		switch (rpc_type)
		{
			case TRPCs.SYNC_DATA: ApplyData(ctx); break;
		}
	}

	void ApplyData(ParamsReadContext ctx)
	{
		Param1<ref ToxicConfig> data;
		if (!ctx.Read(data))
			return;

		GetToxicManager().SetConfig(data.param1);
		GetToxicManager().InitToxicHandler();
	}
}