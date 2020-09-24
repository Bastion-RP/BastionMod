class RadConst
{
	static const string MOD_DIR = "$profile:Bastion\\DangerousZone"; 
	static const string RADIATION_DIR = "$profile:Bastion\\DangerousZone\\Radiation"; 
	static const string RADIATION_SUIT_DIR = "$profile:Bastion\\DangerousZone\\Radiation\\SuitsConfig";
	static const string RADIATION_ZONES_DIR = "$profile:Bastion\\DangerousZone\\Radiation\\RadioactiveZones";

	static const string RADIATION_ZONES_FILE = "RadZones.json";
	static const string RADIATION_SUITS_FILE = "Suits.json";

	static const float DECREASE_SUIT_DAMAGE_RATE = 0.05; //95% reducing koef the difference between the critical threshold and external radiation

	static const int SICKNESS_THRESHOLD_T1 = 250;
	static const int SICKNESS_THRESHOLD_T2 = 600;
	static const int SICKNESS_THRESHOLD_T3 = 1200;
	static const int SICKNESS_THRESHOLD_T4 = 2000;
}

enum RadRPCs
{
	REQUEST_DATA = -4000404,
	RESPONSE_DATA,
	SEND_RADIATION_DATA,
}