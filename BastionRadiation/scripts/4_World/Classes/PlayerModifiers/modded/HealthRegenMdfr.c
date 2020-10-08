// ====================
// disable health regen
// ====================
modded class HealthRegenMdfr
{
	override void OnTick(PlayerBase player, float deltaT)
	{	
		float innerRad = player.GetRadiationLevel();
		if (innerRad >= RadConst.SICKNESS_THRESHOLD_T1)
			return;
		super.OnTick(player, deltaT);
	}
};