enum eBRPModifiers : eModifiers
{
	MDF_DEADLYWATER,
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
		player.GetSymptomManager().QueueUpSecondarySymptom(BRP_SymptomIDs.BRP_SYMPTOM_DEAD_BY_WATER);
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
		
	}

	override void OnTick(PlayerBase player, float deltaT)
	{
		player.GetSymptomManager().QueueUpPrimarySymptom(SymptomIDs.SYMPTOM_FREEZE);
	}
}