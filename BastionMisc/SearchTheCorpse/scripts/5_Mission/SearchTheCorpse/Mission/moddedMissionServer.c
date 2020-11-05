modded class MissionServer
{
	float dea_updateTimeMax = 10;
	float dea_updateTime = dea_updateTimeMax;

	override void OnEvent(EventType eventTypeId, Param params) 
	{
		super.OnEvent(eventTypeId, params);

		PlayerIdentity identity;
		PlayerBase player;
		int counter = 0;

		switch(eventTypeId)
		{
			case ClientReadyEventTypeID: 
			
				ClientReadyEventParams readyParams;
				Class.CastTo(readyParams, params);
				
				identity = readyParams.param1;
				Class.CastTo(player, readyParams.param2);
				if(player)
				{
					STCConfigBase stcConfigBase = new STCConfigBase();
					Param1<ref STCConfig> crpClr = new Param1<ref STCConfig>>(stcConfigBase.GetConfig());
					GetGame().RPCSingleParam(player, STC_rpc_type.RPC_SetClientSTCConfig, crpClr, true, player.GetIdentity());
					player.stcConfig = stcConfigBase.GetConfig();
					
				}
			break;
			
		}
	}

	override void OnUpdate(float timeslice)
	{
		super.OnUpdate(timeslice);
		

		dea_updateTime += timeslice;
		if (dea_updateTime >= dea_updateTimeMax)
		{
			dea_updateTime = 0;
			STCConfigBase stcConfigBase = new STCConfigBase();
			for (int j = 0; j < m_Players.Count(); j++)
			{
				PlayerBase player = PlayerBase.Cast(m_Players.Get(j));
				
				if ( !player )
					continue;
				
				Param1<ref STCConfig> crpClr = new Param1<ref STCConfig>>(stcConfigBase.GetConfig());
				GetGame().RPCSingleParam(player, STC_rpc_type.RPC_SetClientSTCConfig, crpClr, true, player.GetIdentity());
				player.stcConfig = stcConfigBase.GetConfig();
			}
			
		}
	}
}