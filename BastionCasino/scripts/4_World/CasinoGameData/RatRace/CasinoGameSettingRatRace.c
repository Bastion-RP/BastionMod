class CasinoGameSettingRatRace extends CasinoGameSetting
{
    int minBet  = 10;
    int maxBet  = 10000;
    int maxWinQouta = 5;
    static int GAME_TYPE = DAYZ_CASINO_TYPE_RAT_RACE_GAME;


    void CasinoGameSettingRatRace()
    {
        gamePositions = new array<ref GamePosition>;
        gamePositions.Insert(new GamePosition("8349.441406 293.181458 5971.501953", "97.000015 0.000000 0.000000"));
    }
}