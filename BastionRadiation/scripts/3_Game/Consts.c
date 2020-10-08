class RadConst
{
	static const string MOD_DIR = "$profile:Bastion\\DangerousZone"; 
	static const string RADIATION_DIR = "$profile:Bastion\\DangerousZone\\Radiation"; 
	static const string RADIATION_SUIT_DIR = "$profile:Bastion\\DangerousZone\\Radiation\\SuitsConfig";
	static const string RADIATION_ZONES_DIR = "$profile:Bastion\\DangerousZone\\Radiation\\RadioactiveZones";

	static const string RADIATION_ZONES_FILE = "RadZones.json";
	static const string RADIATION_SUITS_FILE = "Suits.json";

	static const float DECREASE_SUIT_DAMAGE_RATE = 0.05; //95% reducing koef the difference between the critical threshold and external radiation

	// WARNING!
	// Starting from the first tier of the sickness
	// health regeneration is disabled

	static const int SICKNESS_THRESHOLD_T1 = 250;
	static const int SICKNESS_THRESHOLD_T2 = 600;
	static const int SICKNESS_THRESHOLD_T3 = 1200;
	static const int SICKNESS_THRESHOLD_T4 = 2000;

	static const float SICKNESS_HEALTH_DECREASE_MDFR_T1 = 1;
	static const float SICKNESS_HEALTH_DECREASE_MDFR_T2 = 2;
	static const float SICKNESS_HEALTH_DECREASE_MDFR_T3 = 2;
	static const float SICKNESS_HEALTH_DECREASE_MDFR_T4 = 3;

	// health lose
	// SICKNESS_HEALTH_DECREASE_MDFR_T4 * SICKNESS_HEALTH_DECREASE_RATE = 0.087
	// etc...

	static const float SICKNESS_HEALTH_DECREASE_RATE = 0.027;

	//every SICKNESS_EFFECT_COOLDOWN seconds there is a chance that the player will bleed or the like
	static const int SICKNESS_EFFECT_COOLDOWN = 60;

	static const int ANTIRADPILLS_EFFECT_TIME = 120; // in sec
	static const int ANTIRADPILLS_COOLDOWN = 300; // in sec

	static const int SICKNESS_VOMIT_EFFECT_TIME = 120;

	// Medicine how much item decrease inner rad level
	static const float RAD_PILLS_POWER = 5;
}

enum RadRPCs
{
	REQUEST_DATA = -4000404,
	RESPONSE_DATA,
	SEND_RADIATION_DATA,
}