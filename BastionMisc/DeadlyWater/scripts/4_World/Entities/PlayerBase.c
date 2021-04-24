modded class PlayerBase
{
	private float				m_VignetteValue;
	private bool				m_ShouldKillCharacter;
	private bool				m_DeadByWaterActive;

	const private int			ACTIVATE_DEADBYWATEREFFECT = -776243;
	const private int			DEACTIVATE_DEADBYWATEREFFECT = -776242;
	const private int			KILL_CHARACTER = -776241;

	void PlayerBase()
	{
		m_VignetteValue				= 0;
		m_ShouldKillCharacter		= false;
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

	void SendKillRequest()
	{
		this.RPCSingleParam(KILL_CHARACTER, null, true);
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
			if (rpc_type == KILL_CHARACTER)
			{
				m_ShouldKillCharacter = true;
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

		PPEffects.SetVignette(m_VignetteValue, 0, 0, 0, 1);

		if (m_VignetteValue < 0)
		{
			m_VignetteValue = 0;
			GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).Remove( DeadByWaterEffect);
		}
		else if (m_VignetteValue > 2)
		{
			m_VignetteValue = 2;
			SendKillRequest();
		}
	}

	bool ShouldKillCharacter()
	{
		return m_ShouldKillCharacter;
	}

	override void CheckDeath()
	{
		if( IsPlayerSelected() && !IsAlive() )
		{
			if(GetGame().IsClient())
			{
				PPEffects.ResetAll();
				GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).Remove( DeadByWaterEffect);
			}
		}
		super.CheckDeath();
	}

	bool HasWetsuit()
	{
		Wetsuit_Base suit;
		if (Class.CastTo(suit, GetItemOnSlot("Body")))
			return true;
		return false;
	}
}
