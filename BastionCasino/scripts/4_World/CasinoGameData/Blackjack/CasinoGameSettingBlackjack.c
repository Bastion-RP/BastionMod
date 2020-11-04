class CasinoGameSettingBlackjack extends CasinoGameSetting
{
    static int GAME_TYPE = DAYZ_CASINO_TYPE_BLACKJACK_GAME;
    int minBet  = 10;
    int maxBet  = 10000;
	float winFactor = 1.5;
	float winFactorBlackJack = 2.0;

    void CasinoGameSettingBlackjack()
    {
        gamePositions = new array<ref GamePosition>;
        gamePositions.Insert(new GamePosition("8349.769531 293.181458 5976.001953", "49.000000 0.000000 0.000000"));
    }
}