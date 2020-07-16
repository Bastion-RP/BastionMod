modded class BloodLoss {

	override void OnUpdateClient(PlayerBase player, float deltatime) {

        // reset effect on main menu
		if (GetGame().IsMissionMainMenu()) {
			PPEffects.SetBloodSaturation(1);
			return;
		};

		// if gettransfer values doesn't exist, exit
		if (!player.GetTransferValues()) {
			return;
		};

		// get blood
		float BRP_Shock_t_Blood = player.GetTransferValues().GetBlood();

		// add .25 to the normalized blood, this will make it not get as B/W and go B/W a little later
		// clamp the blood so it never goes over 1 or below 0
		BRP_Shock_t_Blood = Math.Clamp((BRP_Shock_t_Blood + 0.25), 0, 1);

		// if the set blood effect needs an update, update it
		if (BRP_Shock_t_Blood != m_BloodSet) {
            m_BloodSet = BRP_Shock_t_Blood;
            PPEffects.SetBloodSaturation(m_BloodSet);
		};
	};
};
