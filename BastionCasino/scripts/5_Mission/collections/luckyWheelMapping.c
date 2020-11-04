class LuckyWheelMapping
{
    private ref LuckyWheelWin winArray[36];
    private int chipsValue;

    void LuckyWheelMapping(CasinoGameSettingLuckyWheel casinoGameSettingLuckyWheel) {
        chipsValue = casinoGameSettingLuckyWheel.chipsBet;

        foreach (WheelNumberConfig config: casinoGameSettingLuckyWheel.wheelNumberConfigs)
        {
            winArray[config.number] = new LuckyWheelWin(config.number, chipsValue * config.quote);
        }
	}

    LuckyWheelWin GetLuckyWheelWin() {
		int luckNumber = Math.RandomIntInclusive(0, 35);

        if (DAYZ_CASINO_DEBUG_JACKPOT_WIN) {
            luckNumber = DAYZ_CASINO_LUCKY_WHEEL_JACKPOT_DEGREE / 10;
        }

        return GetLuckyWheelWinByIndex(luckNumber);
    }

    LuckyWheelWin GetLuckyWheelWinByIndex(int index) {
        return winArray[index];
    }
};