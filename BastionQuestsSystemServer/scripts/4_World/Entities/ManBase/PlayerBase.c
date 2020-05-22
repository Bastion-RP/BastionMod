modded class PlayerBase
{
	private ref PersonalQuestManager	m_PersonQuestManag;

	void PlayerBase()
	{
	}

    override void OnConnect()
    {
        super.OnConnect();

		if (GetGame().IsServer() && GetIdentity())
		{
			m_PersonQuestManag = new PersonalQuestManager(this);
		}
		
		m_PersonQuestManag.OnConnect();
    }

	override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		super.OnRPC(sender, rpc_type, ctx);
		m_PersonQuestManag.OnRPC(sender, rpc_type, ctx);
    }

}