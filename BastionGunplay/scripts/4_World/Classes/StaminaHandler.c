modded class StaminaHandler {	
	override void RegisterStaminaModifiers() {
        super.RegisterStaminaModifiers();
		m_StaminaModifiers.RegisterFixed(BRP_GunPlay_EStaminaModifiers.BRP_GunPlay_AIM_LOW, GameConstants.STAMINA_DRAIN_HOLD_BREATH * 0.10);
		m_StaminaModifiers.RegisterFixed(BRP_GunPlay_EStaminaModifiers.BRP_GunPlay_AIM_MED, GameConstants.STAMINA_DRAIN_HOLD_BREATH * 0.20);
		m_StaminaModifiers.RegisterFixed(BRP_GunPlay_EStaminaModifiers.BRP_GunPlay_AIM_HIGH, GameConstants.STAMINA_DRAIN_HOLD_BREATH * 0.30);
		m_StaminaModifiers.RegisterFixed(BRP_GunPlay_EStaminaModifiers.BRP_GunPlay_AIM_ULTRA, GameConstants.STAMINA_DRAIN_HOLD_BREATH * 0.40);
    };
};