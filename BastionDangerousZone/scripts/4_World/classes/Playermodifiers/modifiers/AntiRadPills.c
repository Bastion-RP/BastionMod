class AntiRadPillsMdfr: ModifierBase
{
	float m_RegenTime;
	const int ANTIRADPILLS_LIFETIME = 300;

	override void Init()
	{
		m_TrackActivatedTime = true;
		m_IsPersistent = true;
		m_ID 					= DZModifiers.MDF_DZANTIRADPILLS;
		m_TickIntervalInactive 	= DEFAULT_TICK_TIME_INACTIVE;
		m_TickIntervalActive 	= DEFAULT_TICK_TIME_ACTIVE;
		m_RegenTime = ANTIRADPILLS_LIFETIME;
	}

	override bool ActivateCondition(PlayerBase player)
	{
		return false;
	}

	override void OnReconnect(PlayerBase player)
	{
		OnActivate(player);
	}

	override string GetDebugText()
	{
		return (ANTIRADPILLS_LIFETIME - GetAttachedTime()).ToString();
	}


	override void OnActivate(PlayerBase player)
	{
		if( player.GetNotifiersManager() ) player.GetNotifiersManager().ActivateByType(eNotifiers.NTF_PILLS);
		player.AntiRadPillsActivated = true;
		#ifdef DZDEBUG
		GetDZLogger().LogInfo("player:"+player.GetIdentity().GetName()+"Anti_Rad_Pills Activated");
		#endif
	}

	override void OnDeactivate(PlayerBase player)
	{
		if( player.GetNotifiersManager() ) player.GetNotifiersManager().DeactivateByType(eNotifiers.NTF_PILLS);
		player.AntiRadPillsActivated = false;
		#ifdef DZDEBUG
		GetDZLogger().LogInfo("player:"+player.GetIdentity().GetName()+"Anti_Rad_Pills Deactivated");
		#endif
	}

	override bool DeactivateCondition(PlayerBase player)
	{
		float attached_time = GetAttachedTime();

		if( attached_time >= m_RegenTime )
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
			player.AntiRadPillsActivated = true;
	}
};
