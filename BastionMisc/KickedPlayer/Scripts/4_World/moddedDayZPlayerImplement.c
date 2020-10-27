modded class DayZPlayerImplement
{
	override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		super.OnRPC(sender, rpc_type, ctx);

		switch(rpc_type)
		{
			case BRP_KickPlayer_RPC.SendKickPlayer :
				GetGame().GetMission().Continue();	
				GetGame().GetMission().AbortMission();
			break;
		}
		
	}
}