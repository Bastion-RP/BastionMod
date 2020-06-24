modded class PlayerBase
{
	private bool		m_AlreadyInWater;

	void PlayerBase()
	{
		m_AlreadyInWater = false;
	}
	override void SetInWater(bool pState)
	{
		super.SetInWater(pState);
		Print("PlayerBase::SetInWater = "+pState.ToString());
		if (pState)
		{
			//RequestSoundEvent(EPlayerSoundEventID.TAKING_DMG_LIGHT);
			StartProccesWaterDamage();
		}
		else
		{
			StopProccesWaterDamage();
		}
	}

	void StartProccesWaterDamage()
	{
		GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( this.ProcessWaterDamage, 500, true);
	}

	void StopProccesWaterDamage()
	{
		GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).Remove( this.ProcessWaterDamage );
	}

	void ProcessWaterDamage()
	{
		float currenthealth = GetHealth("GlobalHealth", "Health");
		float heat = GetStatHeatComfort().Get();
		if (heat > GetStatHeatComfort().GetMin())
		{
			heat--;
			GetStatHeatComfort().Set(heat);
		}
		SetHealth("GlobalHealth","Health" , currenthealth - 0.1 );
		AddHealth("GlobalHealth","Shock", -1);
	}
}