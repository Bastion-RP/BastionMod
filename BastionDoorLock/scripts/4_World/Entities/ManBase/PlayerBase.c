modded class PlayerBase
{
	override void OnConnect() 
	{
        super.OnConnect();
        if (GetGame().IsServer() && GetGame().IsMultiplayer()) 
		{
            GetGame().RPCSingleParam(this, LockDoorRPCs.SEND_CONFIG, new Param1<ref LockDoorConfig>(GetLockedDoorsConfigHandler().GetConfig()), true, GetIdentity());
        }
    }
}