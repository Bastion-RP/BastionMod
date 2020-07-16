modded class StaminaHandler {	
	override void RegisterStaminaModifiers() {
        super.RegisterStaminaModifiers();
		m_StaminaModifiers.RegisterFixed(BRP_GunPlay_EStaminaModifiers.BRP_GunPlay_AIM_LOW, GameConstants.STAMINA_DRAIN_HOLD_BREATH_START  * 0.10);
		m_StaminaModifiers.RegisterFixed(BRP_GunPlay_EStaminaModifiers.BRP_GunPlay_AIM_MED, GameConstants.STAMINA_DRAIN_HOLD_BREATH_START  * 0.20);
		m_StaminaModifiers.RegisterFixed(BRP_GunPlay_EStaminaModifiers.BRP_GunPlay_AIM_HIGH, GameConstants.STAMINA_DRAIN_HOLD_BREATH_START  * 0.30);
		m_StaminaModifiers.RegisterFixed(BRP_GunPlay_EStaminaModifiers.BRP_GunPlay_AIM_ULTRA, GameConstants.STAMINA_DRAIN_HOLD_BREATH_START  * 0.40);
    };
	
	override void DepleteStamina(EStaminaModifiers modifier, float dT = -1)	{
		super.DepleteStamina(modifier,dT);
		
		StaminaModifier sm = m_StaminaModifiers.GetModifierData(modifier);

		if (modifier == EStaminaModifiers.HOLD_BREATH) {
            GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).Remove(BRP_Gunplay_FixHoldBreathReset);
			GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( BRP_Gunplay_FixHoldBreathReset, (sm.GetCooldown() * 1000), false);
		};

	};

	void BRP_Gunplay_FixHoldBreathReset () {

		ResetCooldown(EStaminaModifiers.HOLD_BREATH);
	};
};