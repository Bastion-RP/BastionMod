class BetDiceClientEventHandler
{
    void HandleEvents(BetDiceMenu betDiceMenu, PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx) {
        if (IsServerCasino() || !betDiceMenu.isMenuOpen) {
            return;
        }
        if (rpc_type == DAYZ_CASINO_RESPONSE_SHUFFEL_BET_DICE) {
            DebugMessageCasino("receive response shuffle");
            Param4<int, int, int, int> parameterShuffleResponse;
            if (ctx.Read(parameterShuffleResponse)) {
                DebugMessageCasino("has receive response for bet dice");
                betDiceMenu.winImageNumber1 = parameterShuffleResponse.param1 - 1;
                betDiceMenu.winImageNumber2 = parameterShuffleResponse.param2 - 1;
                betDiceMenu.lastWinChips = parameterShuffleResponse.param3;
                betDiceMenu.currentAmount = parameterShuffleResponse.param4;
                DebugMessageCasino("new amount is " + betDiceMenu.currentAmount);
            }
        }
        if (rpc_type == DAYZ_CASINO_RESPONSE_SHUFFEL_BET_DICE_NOT_ENOUGH_BALANCE) {
            DebugMessageCasino("receive not enough balance");
            betDiceMenu.EndGame();
        }
    }
};