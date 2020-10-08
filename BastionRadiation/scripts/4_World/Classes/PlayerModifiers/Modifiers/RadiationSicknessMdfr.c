class RadiationSicknessMdfr : ModifierBase
{
	override void Init()
	{
		m_TrackActivatedTime 	= true;
		m_ID 					= Rad_eModifiers.MDF_RAD_SICKNESS;
		m_TickIntervalInactive 	= DEFAULT_TICK_TIME_INACTIVE;
		m_TickIntervalActive 	= 1;
	}

	override bool ActivateCondition(PlayerBase player)
	{
		float innerRad = player.GetRadiationLevel();
		if ( innerRad >= RadConst.SICKNESS_THRESHOLD_T1 )
		{
			return true;
		}
		return false;
	}

	override void OnActivate(PlayerBase player)
	{
	}


	override bool DeactivateCondition(PlayerBase player)
	{
		float innerRad = player.GetRadiationLevel();
		if ( innerRad < RadConst.SICKNESS_THRESHOLD_T1 )
		{
			return true;
		}
		return false;
	}

	override void OnTick(PlayerBase player, float deltaT)
	{
		float innerRad = player.GetRadiationLevel();
		float sickTierModifier = 0;
		float dmg;
		if (innerRad >= RadConst.SICKNESS_THRESHOLD_T1)
		{
			if (innerRad < RadConst.SICKNESS_THRESHOLD_T2)
				sickTierModifier = RadConst.SICKNESS_HEALTH_DECREASE_MDFR_T1;
			else if (innerRad < RadConst.SICKNESS_THRESHOLD_T3)
				sickTierModifier = RadConst.SICKNESS_HEALTH_DECREASE_MDFR_T2;
			else if (innerRad < RadConst.SICKNESS_THRESHOLD_T4)
				sickTierModifier = RadConst.SICKNESS_HEALTH_DECREASE_MDFR_T3;
			else
				sickTierModifier = RadConst.SICKNESS_HEALTH_DECREASE_MDFR_T4;
		}
		dmg = -1 * (RadConst.SICKNESS_HEALTH_DECREASE_RATE * sickTierModifier);
		player.AddHealth("","",dmg);

		if (((int)(GetAttachedTime()) % RadConst.SICKNESS_EFFECT_COOLDOWN) == 0)
			InvokeSickEffect(player, sickTierModifier);
	}

	void InvokeSickEffect(PlayerBase player, float sickTierModifier)
	{
		int effChance = Math.RandomIntInclusive(0, (20 - sickTierModifier));
		if (effChance == 1)
		{
			player.GetBleedingManagerServer().AttemptAddBleedingSourceBySelection("Spine2");
		}
	}
};