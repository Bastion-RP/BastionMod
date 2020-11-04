class CasinoGameSettingLuckyWheel extends CasinoGameSetting
{
 	int chipsBet = 50;
    int minJackpot = 500;
    int maxJackpot = 10000;
	ref array<ref WheelNumberConfig> wheelNumberConfigs;
	
    static int GAME_TYPE = DAYZ_CASINO_TYPE_LUCKY_WHEEL_GAME;

    void CasinoGameSettingLuckyWheel()
    {
        gamePositions = new array<ref GamePosition>;
        gamePositions.Insert(new GamePosition("8349.441406 293.181458 5973.501953", "97.000015 0.000000 0.000000"));
		wheelNumberConfigs = new array<ref WheelNumberConfig>;
		CreateNumbers();
    }
	
	void CreateNumbers() {
		int i = 0;
        while (i < 36)
        {
            wheelNumberConfigs.Insert(new WheelNumberConfig(i, 0));
            i += 2;
        }

        i = 1;
        // 1,7,13,19,25
        while (i < 36)
        {
            wheelNumberConfigs.Insert(new WheelNumberConfig(i, 1.5));
            i += 6;
        }

        wheelNumberConfigs.Insert(new WheelNumberConfig(5, 5));
        wheelNumberConfigs.Insert(new WheelNumberConfig(3, 0));
        wheelNumberConfigs.Insert(new WheelNumberConfig(9, 2));
        wheelNumberConfigs.Insert(new WheelNumberConfig(23, 3));
        wheelNumberConfigs.Insert(new WheelNumberConfig(15, 0));
        wheelNumberConfigs.Insert(new WheelNumberConfig(33, 99));
        wheelNumberConfigs.Insert(new WheelNumberConfig(11, 0));
        wheelNumberConfigs.Insert(new WheelNumberConfig(17, 0));
        wheelNumberConfigs.Insert(new WheelNumberConfig(21, 2));
        wheelNumberConfigs.Insert(new WheelNumberConfig(27, 0));
        wheelNumberConfigs.Insert(new WheelNumberConfig(29, 2));
        wheelNumberConfigs.Insert(new WheelNumberConfig(31, 0));
        wheelNumberConfigs.Insert(new WheelNumberConfig(35, 2));
	}
	
	
}