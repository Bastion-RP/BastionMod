class RadiationRPCServer : PluginBase
{
    void RadiationRPCServer() 
	{
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) 
		{ return; }

        GetDayZGame().Event_OnRPC.Insert(OnRPC);
    }

    void ~RadiationRPCServer() 
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
			case RadRPCs.REQUEST_DATA: SendData(sender); break;
		}
	}

	void SendData(PlayerIdentity sender)
	{
		GetGame().RPCSingleParam(null, RadRPCs.RESPONSE_DATA, new Param1<ref RadiationConfig>(GetRadiationManager().GetConfig()), true, sender);
	}
}