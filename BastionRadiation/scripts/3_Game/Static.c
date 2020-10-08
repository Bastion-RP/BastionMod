class RadiationMisc
{
	static float GetCriticalThresholdDamageKoef(float criticalThreshold, float radiation)
	{
		float koef;
		float overflow = radiation - criticalThreshold;
		if (overflow <= 0)
			return 0;

		koef = overflow * RadConst.DECREASE_SUIT_DAMAGE_RATE / 100;
		return koef;
	}
}