class ItemProtectionRad
{
	private string Type;
	private ref array<float> Protect;
	private float CriticalThreshold;
	private float RadiationThreshold;

	string GetType() { return Type; }
	array<float> GetProtectLevels() { return Protect; }
	float GetCritical() { return CriticalThreshold; }
	float GetRadiation() { return RadiationThreshold; }
}

/*
	const int STATE_RUINED 		 	= 4;
	const int STATE_BADLY_DAMAGED 	= 3;
	const int STATE_DAMAGED 	  	= 2;
	const int STATE_WORN 		  	= 1;
	const int STATE_PRISTINE 	  	= 0;
*/