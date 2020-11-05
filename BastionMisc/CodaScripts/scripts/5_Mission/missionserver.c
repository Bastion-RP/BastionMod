modded class MissionServer
{
    ref CodaFramework m_CodaFramework;

    private ref CodaFramework GetCodaFramework()
	{
		if ( !m_CodaFramework ) {
			m_CodaFramework = new ref CodaFramework;
		}

		return m_CodaFramework;
	}

	override void OnClientRespawnEvent(PlayerIdentity identity, PlayerBase player)
	{
		//Do nothing here instead of what normally happens
	}

    override void HandleBody(PlayerBase player)
	{
        // originally emptied this function as well, but realized it left a husk of a body so this fixes that
        if ( player.IsAlive() )
		{
			player.Delete();
		}
	}

	override void OnInit() 
    {
	    super.OnInit();
        GetCodaFramework();
	}

};
