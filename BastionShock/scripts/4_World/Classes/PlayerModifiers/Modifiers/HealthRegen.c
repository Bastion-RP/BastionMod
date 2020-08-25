modded class HealthRegenMdfr {

	//--- stop player from healing HP Health when low on food or bleeding
	override void OnTick(PlayerBase player, float deltaT) {	

		// only add health if player has water and energy left
		float energy = player.GetStatEnergy().Get();
		float water = player.GetStatWater().Get();

		if ( energy <= PlayerConstants.LOW_ENERGY_THRESHOLD || water <= PlayerConstants.LOW_WATER_THRESHOLD ) {
			return;
		};
		
		// only add health if player is NOT bleeding
		if (player.IsBleeding()) {
			return;
		};


		super.OnTick(player,deltaT);
	};
};