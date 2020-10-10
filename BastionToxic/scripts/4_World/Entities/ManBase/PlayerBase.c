modded class PlayerBase
{
	override void OnConnect()
	{
		super.OnConnect();

		GetGame().RPCSingleParam(null, TRPCs.SYNC_DATA, new Param1<ref ToxicConfig>(GetToxicManager().GetConfig()), true, GetIdentity());
	}
}