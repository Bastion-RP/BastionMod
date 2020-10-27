class BoozeAgent: AgentBase
{
	override void Init()
	{
		m_Type 					= DrunkAgent.DRUNK;
		m_Invasibility 			= 0;
		m_TransferabilityIn		= 0;
		m_TransferabilityOut	= 0;
		m_AntibioticsResistance = 1;
		m_MaxCount 				= 1000;
		m_Potency = EStatLevels.CRITICAL;
		m_DieOffSpeed = 0.9;
	}
}