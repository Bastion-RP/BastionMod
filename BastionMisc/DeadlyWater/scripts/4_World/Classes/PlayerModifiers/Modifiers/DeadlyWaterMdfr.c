enum eBRPModifiers
{
	MDF_DEADLYWATER = 50,
}


class DeadlyWaterMdfr : ModifierBase
{
	private const float WATER_DEPTH = 0.75;

	override void Init()
	{
		m_TrackActivatedTime 	= false;
		m_ID 					= eBRPModifiers.MDF_DEADLYWATER;
		m_TickIntervalInactive 	= DEFAULT_TICK_TIME_INACTIVE;
		m_TickIntervalActive 	= DEFAULT_TICK_TIME_ACTIVE;
	}

	override bool ActivateCondition(PlayerBase player)
	{
		if (IsActive())
		{
			return false;
		}

		vector water_info = HumanCommandSwim.WaterLevelCheck( player, player.GetPosition() );
		if (GetPlayer().IsInWater() && (water_info[1] > WATER_DEPTH))
		{
			return true;
		}
		return false;
	}

	override void OnActivate(PlayerBase player)
	{
		player.GetStatHeatComfort().Set(player.GetStatHeatComfort().GetMin());
		player.RequestActivateClientEffects();
	}

	override bool DeactivateCondition(PlayerBase player)
	{
		if (IsActive() && !GetPlayer().IsInWater())
		{
			return true;
		}
		return false;
	}

	override void OnDeactivate(PlayerBase player)
	{
		player.RequestDeactivateClientEffects();
		player.SetHealth("GlobalHealth", "Shock", 100);
	}

	override void OnTick(PlayerBase player, float deltaT)
	{
		player.GetStatHeatComfort().Set(player.GetStatHeatComfort().GetMin());
		player.GetSymptomManager().QueueUpPrimarySymptom(SymptomIDs.SYMPTOM_FREEZE);
		player.AddHealth("GlobalHealth", "Health", -1);
		if (player.ShouldLoseConsciousness())
		{
			player.SetHealth("GlobalHealth", "Shock", 0);
		}
	}
}