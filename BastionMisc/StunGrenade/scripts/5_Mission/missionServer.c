modded class MissionServer {

	void MissionServer()
	{
		m_StunGrenadeBase = NULL;
		GetStunGrenadeBase();
	}

	void ~MissionServer() {
	}
	
	override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity)
	{
		super.InvokeOnConnect(player,identity);
		InitializeSGConfigToPlayer(player);
	}
	
	void InitializeSGConfigToPlayer(PlayerBase player)
	{
		player.SGTimerCheck=GetSGConfig().SGTimerCheck;
		for(int i=0; i<GetSGConfig().ProtectiveGearList.Count();i++)
		{
			player.AddProtectiveGear(GetSGConfig().ProtectiveGearList.Get(i).PGName,GetSGConfig().ProtectiveGearList.Get(i).PGProtection);
		}
	}
};