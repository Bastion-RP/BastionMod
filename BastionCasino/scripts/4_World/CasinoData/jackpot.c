class Jackpot extends BRP_CasinoBaseConfig
{
    private const static string	SETTINGSFILE = "dayZCasinoJackpot.json";

    private int currentJackpotLuckyWheel = 0;
    private int minJackpotLuckyWheel;

    void Jackpot(int minJackpotLuckyWheelExt) {
        if (!FileExist(CASINO_CONFIGSFOLDER + SETTINGSFILE)) {
            minJackpotLuckyWheel = minJackpotLuckyWheelExt;

            if (currentJackpotLuckyWheel < minJackpotLuckyWheel) {
                currentJackpotLuckyWheel = minJackpotLuckyWheel;
            }

            Save(SETTINGSFILE);
        } else {
            Load(SETTINGSFILE);
        }
    }

    int GetJackpotLuckyWheel() {
        return currentJackpotLuckyWheel;
    }

    void UpdateLuckyWheelJackpot(int newJackpotLuckyWheel) {
        currentJackpotLuckyWheel = newJackpotLuckyWheel;

        if (currentJackpotLuckyWheel < minJackpotLuckyWheel) {
            currentJackpotLuckyWheel = minJackpotLuckyWheel;
        }

        Save(SETTINGSFILE);
    }
	
	override protected void DoLoad() {
		JsonFileLoader<Jackpot>.JsonLoadFile(CASINO_CONFIGSFOLDER + SETTINGSFILE, this);
	}
	
	override protected void DoSave() {
		JsonFileLoader<Jackpot>.JsonSaveFile(CASINO_CONFIGSFOLDER + SETTINGSFILE, this);
	}
};