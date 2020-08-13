class RadSickMdfr: ModifierBase
{
	static const int RADSICK_AGENT_THRESHOLD_ACTIVATE = 100;
	static const int RADSICK_AGENT_THRESHOLD_DEACTIVATE = 0;
	private ref array<string>m_BleedingSources = {"Head","Spine","LeftShoulder","LeftArm","RightShoulder","LeftLeg","RightLeg","LeftFoot","RightFoot"};
	float chanceVomit;
	float chanceBleeding;
	string m_DZState;

	override void Init()
	{
		m_TrackActivatedTime 		= false;
		m_ID 										= DZModifiers.MDF_DZRADSICK;
		m_TickIntervalInactive 	= 60;
		m_TickIntervalActive 		= 60;
	}

	override protected bool ActivateCondition(PlayerBase player)
	{
		if(player.GetSingleAgentCount(DZAgents.RADSICK) > RADSICK_AGENT_THRESHOLD_ACTIVATE)
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
	  //if( player.m_NotifiersManager ) player.m_NotifiersManager.AttachByType(eNotifiers.NTF_SICK);
		player.IncreaseDiseaseCount();
		chanceVomit=player.RadChanceVomit;
		chanceBleeding=player.RadChanceBleeding;

		#ifdef DZDEBUG
		GetDZLogger().LogInfo("player:"+player.GetIdentity().GetName()+"RadSickness Activated");
		#endif
	}

	override protected void OnDeactivate(PlayerBase player)
	{
		player.DecreaseDiseaseCount();

		#ifdef DZDEBUG
		GetDZLogger().LogInfo("player:"+player.GetIdentity().GetName()+"RadSickness Deactivated");
		#endif
	}

	override protected bool DeactivateCondition(PlayerBase player)
	{
		if(player.GetSingleAgentCount(DZAgents.RADSICK) < RADSICK_AGENT_THRESHOLD_DEACTIVATE)
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
		if(player.GetSingleAgentCount(DZAgents.RADSICK) < 151 )
		{
			#ifdef DZDEBUG
			m_DZState = "State 1";
			#endif
			SetLowLevelEffetOnPlayer(1, player);
		}

		if(player.GetSingleAgentCount(DZAgents.RADSICK) > 151 && player.GetSingleAgentCount(DZAgents.RADSICK) < 200)
		{
			 	#ifdef DZDEBUG
				m_DZState = "State 2";
				#endif
				SetLowLevelEffetOnPlayer(player.RadHighMultiplier, player);
				if(chanceVomit > Math.RandomFloatInclusive(0,1))
				{
					player.GetSymptomManager().QueueUpPrimarySymptom(SymptomIDs.SYMPTOM_VOMIT);
				}
		}

		if(player.GetSingleAgentCount(DZAgents.RADSICK) > 200 && player.GetSingleAgentCount(DZAgents.RADSICK) < 300)
		{
			#ifdef DZDEBUG
			m_DZState = "State 3";
			#endif
			SetLowLevelEffetOnPlayer(player.RadHighMultiplier, player);
			if(chanceBleeding > Math.RandomFloatInclusive(0,1))
			{
				player.GetBleedingManagerServer().AttemptAddBleedingSourceBySelection(m_BleedingSources.GetRandomElement());
			}
		}

		if(player.GetSingleAgentCount(DZAgents.RADSICK) > 400 && player.GetSingleAgentCount(DZAgents.RADSICK) < 500)
		{
			#ifdef DZDEBUG
			m_DZState = "State 4";
			#endif
			SetLowLevelEffetOnPlayer(player.RadHighMultiplier, player);
			player.GetSymptomManager().QueueUpSecondarySymptom(SymptomIDs.SYMPTOM_FEVERBLUR);
		}

		if(player.GetSingleAgentCount(DZAgents.RADSICK) > 500)
		{
			#ifdef DZDEBUG
			m_DZState = "State 5";
			#endif
			SetLowLevelEffetOnPlayer(player.RadHighMultiplier*2, player);
				player.GetSymptomManager().QueueUpSecondarySymptom(SymptomIDs.SYMPTOM_FEVERBLUR);
		}
		#ifdef DZDEBUG
		GetDZLogger().LogInfo("player:"+player.GetIdentity().GetName()+"Current Radiation level state"+m_DZState);
		#endif
	}

	void SetLowLevelEffetOnPlayer(float RadMultiplier, PlayerBase player)
	{
		float currenthealth = player.GetHealth("GlobalHealth", "Blood");
		player.SetHealth("GlobalHealth", "Blood" ,  currenthealth - player.RadBloodLossDamage*RadMultiplier);
		currenthealth = player.GetHealth();
		player.SetHealth(currenthealth - player.RadHealthDamage*RadMultiplier);
	}

};
