class BTrdConst
{
	static const string MOD_DIR = "$profile:\\Bastion\\BTrader";
	static const string TRADER_DATA_DIR = "$profile:\\Bastion\\BTrader\\Traders";
	static const string CONFIG_DIR = "$profile:\\Bastion\\BTrader\\Config.json";
}

enum BTRPC
{
	REQUEST_TRADER_DATA = 701153,
	SEND_TRADER_DATA,
	SEND_CONFIG,
	REQUEST_TRADE,
	REFRESH_ITEMS,
}