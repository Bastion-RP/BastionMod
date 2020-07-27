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
		m_TickIntervalInactive 	= 20;
		m_TickIntervalActive 	= 20;
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
	}

	override protected void OnDeactivate(PlayerBase player)
	{
		player.DecreaseDiseaseCount();
		player.IsHazarded = false;
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

	private void SendMessageClient(PlayerBase player, string message)
	{
		Param1<string> m_MesParam = new Param1<string>(message);
		GetGame().RPCSingleParam(player, ERPCs.RPC_USER_ACTION_MESSAGE, m_MesParam, true, player.GetIdentity());
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
			//SendMessageClient(player,m_Shock.ToString());
		}

		if(m_Shock > 100)
		{
			player.GiveShock(-100);
			m_Shock = 0;
		}
	}
};
