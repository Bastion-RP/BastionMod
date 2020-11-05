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

		PlayerBase player = PlayerBase.Cast(target);

		switch (rpc_type)
		{
			case RadRPCs.REQUEST_DATA: SendData(sender); break;
			case RadRPCs.SEND_RADIATION_DATA: ApplyData(player, ctx); break;
		}
	}

	void SendData(PlayerIdentity sender)
	{
		GetGame().RPCSingleParam(null, RadRPCs.RESPONSE_DATA, new Param1<ref RadiationConfig>(GetRadiationManager().GetConfig()), true, sender);
	}

	void ApplyData(PlayerBase player, ParamsReadContext ctx)
	{
		Param2<TItemSlotDamageKoefMap, float> data;
		if (!ctx.Read(data))
			return;
		
		TItemSlotDamageKoefMap suitMap = data.param1;
		float radiation = data.param2;

		DamageSuit(player, suitMap);
		player.AddRadiationLevel(radiation);
	}

	void DamageSuit(PlayerBase player, TItemSlotDamageKoefMap suitMap)
	{
		EntityAI item;
		foreach (int slotItem, float koef : suitMap)
		{
			item = player.GetInventory().FindAttachment(slotItem);
			if (item)
			{
				item.DecreaseHealthCoef(koef, false);
			}
		}
	}
}