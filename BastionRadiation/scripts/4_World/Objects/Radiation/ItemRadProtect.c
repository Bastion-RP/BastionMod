class ItemProtectionRad
{
	private string Type;
	private ref array<int> Protect;
	private float CriticalThreshold;

	string GetType() { return Type; }
	array<int> GetProtectLevels() { return Protect; }
	float GetCritical() { return CriticalThreshold; }
}

/*
	const int STATE_RUINED 		 	= 4;
	const int STATE_BADLY_DAMAGED 	= 3;
	const int STATE_DAMAGED 	  	= 2;
	const int STATE_WORN 		  	= 1;
	const int STATE_PRISTINE 	  	= 0;
*/