//People get sick less often and recover quicker from the flu
/*modded class InfluenzaAgent
{
	override void Init()
	{
		super.Init();
		m_TransferabilityIn		= 0.05;
		m_TransferabilityOut	= 0.05;
		m_MaxCount 				= 250;
		m_AutoinfectProbability = CalculateAutoinfectProbability( 0.65 )*0.05;
		m_TransferabilityAirOut = 0.05;
		m_DieOffSpeed 			= 2;
	}

	override bool CanAutoinfectPlayer(PlayerBase player)
	{
		return ( player.GetStatHeatComfort().Get() < INFLUENZA_AGENT_AUTOINFECT_THRESHOLD_HC*0.05 );
	}
}*/