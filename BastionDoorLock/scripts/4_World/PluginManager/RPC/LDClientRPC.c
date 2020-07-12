class LockedDoorsClientRPC : PluginBase
{
	void LockedDoorsClientRPC() 
	{
        if (GetGame().IsServer() && GetGame().IsMultiplayer()) 
		{ return; }

        GetDayZGame().Event_OnRPC.Insert(LockedDoorsClientRPCRPCHandler);
    }

    void ~LockedDoorsClientRPC() 
	{
        GetDayZGame().Event_OnRPC.Remove(LockedDoorsClientRPCRPCHandler);
    }

	void LockedDoorsClientRPCRPCHandler(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx) 
	{
        if (GetGame().IsServer() && GetGame().IsMultiplayer()) 
		{
            delete this;
            return;
        }

		if (rpc_type == LockDoorRPCs.SEND_CONFIG)
		{
			Param1<ref LockDoorConfig> rpb;
			if (!ctx.Read(rpb)) return;
			GetLockedDoorsConfigHandler().SetConfig(rpb.param1);
		}
	}
}