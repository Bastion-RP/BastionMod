modded class PlayerConstants {
	static const float SHOCK_REFILL_CONSCIOUS_SPEED			= 1.75;		//shock refill speed when the player is conscious

	// adjust this to make player wake up slower or faster
	static const float SHOCK_REFILl_UNCONSCIOUS_SPEED		= 1.0;		//shock refill speed when the player is unconscious

	
	///--- HP display image levels
	static const float SL_HEALTH_CRITICAL = 40;
	static const float SL_HEALTH_LOW = 80;
	static const float SL_HEALTH_NORMAL = 120;
	static const float SL_HEALTH_HIGH = 160;	


	// health regen, can be increased to make player regen faster
	static const float HEALTH_REGEN_MIN						= 0.005;	//health regen rate at BLOOD_THRESHOLD_FATAL blood level
	static const float HEALTH_REGEN_MAX						= 0.31;		//health regen rate at MAXIMUM blood level
}