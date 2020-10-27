//Functionality for getting drunk
class DrunkModifier: ModifierBase
{
	static const int AGENT_THRESHOLD_ACTIVATE = 200;
	static const int AGENT_THRESHOLD_DEACTIVATE = 50;
	protected int DrunkState;

	protected float drunkVin;
	protected float vinMin = 0.7;
	protected float vinMax = 1;
	protected float vinState;
	protected float drunkAdd;

	override void Init()
	{
		m_TrackActivatedTime	= false;
		m_ID 					= ScarlettModifiers.SCARLETT_DRUNK;
		m_TickIntervalInactive 	= DEFAULT_TICK_TIME_INACTIVE;
		m_TickIntervalActive 	= DEFAULT_TICK_TIME_INACTIVE;
		DrunkState = 0;
	}

	override protected bool ActivateCondition(PlayerBase player)
	{
		if (player.GetSingleAgentCount(DrunkAgent.DRUNK) > AGENT_THRESHOLD_ACTIVATE) 
		{
			return true;
		}
		return false;	
	}

	override protected void OnActivate(PlayerBase player)
	{
		if (player.GetNotifiersManager()) player.GetNotifiersManager().ActivateByType(eNotifiers.NTF_PILLS);

		m_Player.m_InjuryHandler.m_ForceInjuryAnimMask = m_Player.m_InjuryHandler.m_ForceInjuryAnimMask | eInjuryOverrides.PAIN_KILLERS_LVL0;
	}

	override protected void OnDeactivate(PlayerBase player)
	{
		if (player.GetNotifiersManager()) player.GetNotifiersManager().DeactivateByType(eNotifiers.NTF_PILLS);
		m_Player.m_InjuryHandler.m_ForceInjuryAnimMask = m_Player.m_InjuryHandler.m_ForceInjuryAnimMask & ~eInjuryOverrides.PAIN_KILLERS_LVL0;
		m_Player.m_InjuryHandler.m_ForceInjuryAnimMask = m_Player.m_InjuryHandler.m_ForceInjuryAnimMask & ~eInjuryOverrides.PAIN_KILLERS_LVL1;
	}

	override protected bool DeactivateCondition(PlayerBase player)
	{
		if(player.GetSingleAgentCount(DrunkAgent.DRUNK) < AGENT_THRESHOLD_DEACTIVATE) 
		{
			return true;
		}
		return false;
	}

	protected void KOPlayer(PlayerBase player)
	{
		player.SetHealth("", "Shock", 0);
	}

	override protected void OnTick(PlayerBase player, float deltaT)
	{
		float drank = player.GetSingleAgentCount(DrunkAgent.DRUNK);
		eInjuryHandlerLevels injury_level = player.m_InjuryHandler.GetInjuryValue(injury_level);

		if (player.IsUnconscious() || player.GetCommand_Vehicle() )
		{
			return;
		}

		if (drank < 300)
		{
			player.ForceUpdateInjuredState();
			DrunkState = 0;
			drunkVin = 0;
		}

		else if (drank >= 300 && drank <= 749)
		{
			if(DrunkState != 1)
			{
				player.GetCommandModifier_Additives().SetInjured(eInjuryHandlerLevels.WORN, false);
				player.m_InjuryHandler.SendValue( eInjuryHandlerLevels.WORN );
            	player.m_InjuryHandler.m_ChangedStateInvoker.Invoke( eInjuryHandlerLevels.WORN );
            	player.m_InjuryHandler.Synchronize( eInjuryHandlerLevels.WORN );

			}

			if(drunkVin <= vinMin)
			{
				drunkAdd = drunkVin
				drunkVin = drunkAdd + 0.1;
			}

			PPEffects.SetUnconsciousnessVignette(drunkVin);
			DrunkState = 1;
		}

		else if (drank >= 750 && drank <= 999)
		{
			if (Math.RandomFloat01() < 1 / 25)  // play with this if you want to puke more or less
			{
				player.GetSymptomManager().QueueUpPrimarySymptom(SymptomIDs.SYMPTOM_VOMIT);
			}

			if(DrunkState != 2)
			{
				player.GetCommandModifier_Additives().SetInjured(eInjuryHandlerLevels.DAMAGED, false);
				player.m_InjuryHandler.SendValue( eInjuryHandlerLevels.DAMAGED );
            	player.m_InjuryHandler.m_ChangedStateInvoker.Invoke( eInjuryHandlerLevels.DAMAGED );
            	player.m_InjuryHandler.Synchronize( eInjuryHandlerLevels.DAMAGED );
				vinState = 1;
			}

			if(drunkVin <= vinMin)
			{
				vinState = 1;
			}
			else if(drunkVin >= vinMax)
			{
				vinState = 2;
			}

			if(drunkVin <= vinMax && vinState == 1)
			{
				drunkVin = drunkVin + 0.01;
			}

			if(drunkVin >= vinMin  && vinState == 2)
			{
				drunkVin = drunkVin - 0.01;
			}

			PPEffects.SetUnconsciousnessVignette(drunkVin);
			DrunkState = 2;
		}

		else if (drank == 1000)
		{
			if(DrunkState != 3)
			{
				DrunkState = 3;
				GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater( KOPlayer, 120000, false, player );
			}
		}
	}
};