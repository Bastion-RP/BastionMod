class RadiationBlockMdfr : ModifierBase
{
	override void Init()
	{
		m_TrackActivatedTime 	= true;
		m_ID 					= Rad_eModifiers.MDF_RAD_BLOCK;
		m_TickIntervalInactive 	= DEFAULT_TICK_TIME_INACTIVE;
		m_TickIntervalActive 	= 1;
	}

	override void OnActivate(PlayerBase player)
	{
		if( player.GetNotifiersManager() )
			player.GetNotifiersManager().ActivateByType(eNotifiers.NTF_PILLS);
	}
	
	override void OnDeactivate(PlayerBase player)
	{
		if( player.GetNotifiersManager() )
			player.GetNotifiersManager().DeactivateByType(eNotifiers.NTF_PILLS);
	}

	override bool DeactivateCondition(PlayerBase player)
	{
		float attached_time = GetAttachedTime();
		
		if( attached_time >= RadConst.ANTIRADPILLS_EFFECT_TIME )
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}