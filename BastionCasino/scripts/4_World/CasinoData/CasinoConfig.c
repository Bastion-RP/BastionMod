class CasinoConfig extends BRP_CasinoBaseConfig
{
    private const static string	SETTINGSFILE = "CasinoConfigV2.json";

	ref CasinoGameSettingLuckyWheel luckyWheelSettings;
	ref CasinoGameSettingBlackjack blackJackSettings;
	ref CasinoGameSettingDice diceSettings;
	ref CasinoGameSettingRatRace ratRaceSettings;
	int configVersion = 1;
	bool enablePlayLogs = true;
	ref map <string, int> currencyValues;

    void CasinoConfig()
    {
  		if (!FileExist(CASINO_CONFIGSFOLDER + SETTINGSFILE))
		{
			diceSettings = new CasinoGameSettingDice();
			blackJackSettings = new CasinoGameSettingBlackjack();
			luckyWheelSettings = new CasinoGameSettingLuckyWheel();
            ratRaceSettings = new CasinoGameSettingRatRace();
            currencyValues = new map<string, int>;
            currencyValues.Set("BRP_CasinoChips", 1);
			Save(SETTINGSFILE);
		} else {
			Load(SETTINGSFILE);
			if (configVersion < 2) {
                configVersion = 2;
				currencyValues = new map<string, int>;
				currencyValues.Set("BRP_CasinoChips", 1);

                Save(SETTINGSFILE);
			}
		}
    }
	
	override protected void DoLoad() {
		JsonFileLoader<CasinoConfig>.JsonLoadFile(CASINO_CONFIGSFOLDER + SETTINGSFILE, this);
	}
	
	override protected void DoSave() {
		JsonFileLoader<CasinoConfig>.JsonSaveFile(CASINO_CONFIGSFOLDER + SETTINGSFILE, this);
	}
}