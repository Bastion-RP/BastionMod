class HazardSickMdfr: ModifierBase
{
	static const int HAZARDSICK_AGENT_THRESHOLD_ACTIVATE = 100;
	static const int HAZARDSICK_AGENT_THRESHOLD_DEACTIVATE = 0;
	float chanceShock;
	float chanceCough;
	float hazardshockvalue;
	int 	m_Shock=0;

	override void Init()
	{
		m_TrackActivatedTime 	= false;
		m_ID 					= DZModifiers.MDF_DZHAZARDSICK;
		m_TickIntervalInactive 	= 60;
		m_TickIntervalActive 	= 60;
	}

	override protected bool ActivateCondition(PlayerBase player)
	{
		if(player.GetSingleAgentCount(DZAgents.HAZARDSICK) > HAZARDSICK_AGENT_THRESHOLD_ACTIVATE)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	override protected void OnActivate(PlayerBase player)
	{
		player.IncreaseDiseaseCount();
		player.IsHazarded = true;
		player.IsUnprotected = false;
		chanceCough = player.HazardChanceCough;
		chanceShock = player.HazardChanceShock;
		hazardshockvalue = player.HazardShockValue;
		#ifdef DZDEBUG
		GetDZLogger().LogInfo("player:"+player.GetIdentity().GetName()+"HazardSickness Activated");
		#endif
	}

	override protected void OnDeactivate(PlayerBase player)
	{
		player.DecreaseDiseaseCount();
		player.IsHazarded = false;
		#ifdef DZDEBUG
		GetDZLogger().LogInfo("player:"+player.GetIdentity().GetName()+"HazardSickness Deactivated");
		#endif
	}

	override protected bool DeactivateCondition(PlayerBase player)
	{
		if(player.GetSingleAgentCount(DZAgents.HAZARDSICK) < HAZARDSICK_AGENT_THRESHOLD_DEACTIVATE)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	override protected void OnTick(PlayerBase player, float deltaT)
	{
		if( chanceCough > Math.RandomFloatInclusive(0,1))
		{
			player.GetSymptomManager().QueueUpPrimarySymptom(SymptomIDs.SYMPTOM_COUGH);
		}

		if( player.IsUnconscious() == true)
		{
			player.SetHealth(0);
		}

		if(chanceShock > Math.RandomFloatInclusive(0,1))
		{
			m_Shock += hazardshockvalue;
		}

		if(m_Shock > 100)
		{
			player.GiveShock(-100);
			m_Shock = 0;
		}

		#ifdef DZDEBUG
		GetDZLogger().LogInfo("player:"+player.GetIdentity().GetName()+"shockvalue:"+m_Shock.ToString());
		#endif
	}
};
