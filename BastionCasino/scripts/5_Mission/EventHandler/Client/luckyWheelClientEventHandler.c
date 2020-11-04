class LuckyWheelClientEventHandler
{
    void HandleEvents(LuckyWheelMenu luckyWheelMenu, PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx) {
        if (IsServerCasino() || !luckyWheelMenu.isMenuOpen) {
            return;
        } else if (rpc_type == DAYZ_CASINO_LUCKY_WHEEL_START_RESPONSE) {
            DebugMessageCasino("receive response wheel");
            Param5<int, int, int, int, bool> parameterShuffleResponse;
            if (ctx.Read(parameterShuffleResponse)) {
                DebugMessageCasino("has receive response for lucky wheel");
                luckyWheelMenu.winDegree = parameterShuffleResponse.param1;
                luckyWheelMenu.lastWinChips = parameterShuffleResponse.param2;
                luckyWheelMenu.currentAmount = parameterShuffleResponse.param3;
                DebugMessageCasino("new current amount" + luckyWheelMenu.currentAmount);
                luckyWheelMenu.jackpot = parameterShuffleResponse.param4;
                luckyWheelMenu.jackpotWin = parameterShuffleResponse.param5;
                DebugMessageCasino("new amount is " + luckyWheelMenu.currentAmount);
                DebugMessageCasino("win degree " + parameterShuffleResponse.param1);
            }
        } else if (rpc_type == DAYZ_CASINO_LUCKY_WHEEL_GET_JACKPOT_RESPONSE) {
            Param1<int> parameterJackpotResponse;
            if (ctx.Read(parameterJackpotResponse)) {
                luckyWheelMenu.UpdateJackpot(parameterJackpotResponse.param1);
            }
        } else if (rpc_type == DAYZ_CASINO_RESPONSE_SHUFFEL_BET_DICE_NOT_ENOUGH_BALANCE) {
            DebugMessageCasino("receive not enough balance");
            luckyWheelMenu.EndGame();
        }
    }
};