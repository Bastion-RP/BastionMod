class RadConst
{
	static const string MOD_DIR = "$profile:Bastion\\DangerousZone"; 
	static const string RADIATION_DIR = "$profile:Bastion\\DangerousZone\\Radiation"; 
	static const string RADIATION_SUIT_DIR = "$profile:Bastion\\DangerousZone\\Radiation\\SuitsConfig";
	static const string RADIATION_ZONES_DIR = "$profile:Bastion\\DangerousZone\\Radiation\\RadioactiveZones";

	static const string RADIATION_ZONES_FILE = "RadZones.json";
	static const string RADIATION_SUITS_FILE = "Suits.json";

	static const float DECREASE_SUIT_DAMAGE_RATE = 0.05; //95% reducing koef the difference between the critical threshold and external radiation
}

enum RadRPCs
{
	REQUEST_DATA = -4000404,
	RESPONSE_DATA,
}