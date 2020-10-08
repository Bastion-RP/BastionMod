class RadiationBlockCooldownMdfr : ModifierBase
{
	override void Init()
	{
		m_TrackActivatedTime 	= true;
		m_ID 					= Rad_eModifiers.MDF_RAD_BLOCK_COOLDOWN;
		m_TickIntervalInactive 	= DEFAULT_TICK_TIME_INACTIVE;
		m_TickIntervalActive 	= 1;
	}

	override bool DeactivateCondition(PlayerBase player)
	{
		float attached_time = GetAttachedTime();
		
		if( attached_time >= RadConst.ANTIRADPILLS_COOLDOWN )
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}