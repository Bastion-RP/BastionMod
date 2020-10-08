enum BST_Agents
{
	RADIATION = 256,
}

modded class PluginTransmissionAgents
{
	void PluginTransmissionAgents()
	{
		RegisterAgent(new RadAgent);
	}
}

class RadAgent : AgentBase
{
	override void Init()
	{
		m_Type 					= BST_Agents.RADIATION;
		m_Invasibility 			= 0;//increase the agent count by this number per second if potent enough to grow
		m_TransferabilityIn		= 0;//to the player
		m_TransferabilityOut	= 0;//from the player
		m_AntibioticsResistance = 1;//[0..1], 0 means antibiotics have full effect, 1 means no effect
		m_MaxCount 				= int.MAX;
		m_Potency 				= -1;//grow when player's immune system is at this level or lower
		m_DieOffSpeed 			= 0;//how fast the agent dies off when not potent enough to grow(per sec)
		m_Digestibility 		= 0;
	}
}

modded class PlayerAgentPool
{
	override void GrowAgents(float deltaT)
	{
		if ( !IsPluginManagerExists() )//check if modules are running
			return;
		
		EStatLevels immunity_level = m_Player.GetImmunityLevel();
		
		m_TotalAgentCount = 0;
		for(int i = 0; i < m_VirusPool.Count(); i++)
		{	
			int agent_id = m_VirusPool.GetKey(i);

			if (agent_id == BST_Agents.RADIATION)
				continue;

			int max_count = m_PluginTransmissionAgents.GetAgentMaxCount( agent_id );
			EStatLevels agent_potency = m_PluginTransmissionAgents.GetPotency( agent_id );
			
			float grow_delta;
			
			if( agent_potency <= immunity_level )
			{
				float invasibility = m_PluginTransmissionAgents.GetAgentInvasibility( agent_id );
				grow_delta = invasibility * deltaT;
			}
			else
			{
				float dieoff_speed = m_PluginTransmissionAgents.GetDieOffSpeed( agent_id );
				grow_delta = -dieoff_speed * deltaT;
			}
			
			float old_count = m_VirusPool.Get( agent_id );
			float new_count = old_count + grow_delta;
			new_count = Math.Clamp(new_count, 0,max_count);
			
			m_TotalAgentCount += new_count;
			SetAgentCount(agent_id, new_count);
		}
	}

	void DecreaseAgent(int agent, float amount)
	{
		float currentAgent = GetSingleAgentCount(agent);
		Print("current Agent "+currentAgent);
		SetAgentCount(agent, (currentAgent - amount));
		Print("rewrite Agent "+GetSingleAgentCount(agent));
	}
}