modded class PlayerBase
{
	private float				m_VignetteValue;
	private bool				m_ShouldLoseConsciousness;
	private bool				m_DeadByWaterActive;

	const private int			ACTIVATE_DEADBYWATEREFFECT = -776243;
	const private int			DEACTIVATE_DEADBYWATEREFFECT = -776242;
	const private int			ACTIVATE_UNCONSCIOUS = -776241;

	void PlayerBase()
	{
		m_VignetteValue				= 0;
		m_ShouldLoseConsciousness	= false;
		m_DeadByWaterActive			= false;
	}

	void RequestActivateClientEffects()
	{
		this.RPCSingleParam(ACTIVATE_DEADBYWATEREFFECT, null, true, this.GetIdentity());
	}

	void RequestDeactivateClientEffects()
	{
		this.RPCSingleParam(DEACTIVATE_DEADBYWATEREFFECT, null, true, this.GetIdentity());
	}

	void SendUnconscious()
	{
		this.RPCSingleParam(ACTIVATE_UNCONSCIOUS, null, true);
	}

	override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		super.OnRPC(sender, rpc_type, ctx);
		if (GetGame().IsClient())
		{
			switch( rpc_type )
			{
				case ACTIVATE_DEADBYWATEREFFECT:
					ActivateClientEffect();
				break;
				case DEACTIVATE_DEADBYWATEREFFECT:
					DeactivateClientEffect();
				break;
			}
		}
		if (GetGame().IsServer())
		{
			if (rpc_type == ACTIVATE_UNCONSCIOUS)
			{
				m_ShouldLoseConsciousness = true;
			}
		}
	}

	void ActivateClientEffect()
	{
		m_DeadByWaterActive = true;
		GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( DeadByWaterEffect, 100, true );
	}

	void DeactivateClientEffect()
	{
		m_DeadByWaterActive = false;
	}

	void DeadByWaterEffect()
	{
		if (m_DeadByWaterActive)
		{
			m_VignetteValue += 0.005;
		}
		else
		{
			m_VignetteValue -= 0.005;
		}

		PPEffects.SetVignette(m_VignetteValue, 0, 0, 0);

		if (m_VignetteValue < 0)
		{
			m_VignetteValue = 0;
			GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).Remove( DeadByWaterEffect);
		}
		else if (m_VignetteValue > 2)
		{
			m_VignetteValue = 2;
			SendUnconscious();
		}
	}

	bool ShouldLoseConsciousness()
	{
		return m_ShouldLoseConsciousness;
	}
}