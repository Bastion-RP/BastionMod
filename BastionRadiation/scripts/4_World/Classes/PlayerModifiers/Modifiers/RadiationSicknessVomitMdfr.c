class RadiationSicknessVomitMdfr : ModifierBase
{
	override void Init()
	{
		m_TrackActivatedTime 	= true;
		m_ID 					= Rad_eModifiers.MDF_RAD_SICKNESS_VOMIT;
		m_TickIntervalInactive 	= DEFAULT_TICK_TIME_INACTIVE;
		m_TickIntervalActive 	= 5;
	}

	override bool ActivateCondition(PlayerBase player)
	{
		return false;
	}

	override void OnActivate(PlayerBase player)
	{
	}


	override bool DeactivateCondition(PlayerBase player)
	{
		float attached_time = GetAttachedTime();
		
		if( attached_time >= RadConst.SICKNESS_VOMIT_EFFECT_TIME )
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	override void OnTick(PlayerBase player, float deltaT)
	{
		int attached_time = (int)(GetAttachedTime());
		if ((attached_time % 60) == 0)
		{
			if (Math.RandomInt(0,2) == 1)
				InvokeVomit(player);
		}
	}

	void InvokeVomit(PlayerBase player)
	{
		SymptomBase symptom = player.GetSymptomManager().QueueUpPrimarySymptom(SymptomIDs.SYMPTOM_VOMIT);
		if( symptom )
			symptom.SetDuration(Math.RandomIntInclusive(4,8));
	}
}