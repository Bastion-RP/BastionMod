class RatRaceClientEventHandler
{
    void HandleEvents(RatRaceMenu rateRaceMenu, PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx) {
        if (IsServerCasino() || !rateRaceMenu.isMenuOpen) {
			//DebugMessageCasino("Is server or menu is not open " + rateRaceMenu.isMenuOpen);
            return;
        } else if (rpc_type == DAYZ_CASINO_RESPONSE_NEW_RAT_RACE) {
			DebugMessageCasino("receive new race event");
            Param1<ref Race> startRace;
            if (ctx.Read(startRace)) {
				rateRaceMenu.ResetGame(Race.Cast(startRace.param1));
			}
		} else if (rpc_type == DAYZ_CASINO_RESPONSE_START_RAT_RACE) {
            DebugMessageCasino("receive response rate race start");
            Param3<int, int, ref Race> parameterShuffleResponse;
            if (ctx.Read(parameterShuffleResponse)) {
                DebugMessageCasino("has receive response for rate race");
                rateRaceMenu.lastWinChips = parameterShuffleResponse.param1;
                rateRaceMenu.currentAmount = parameterShuffleResponse.param2;
				rateRaceMenu.AnimateRace(parameterShuffleResponse.param3);
            }
        } else if (rpc_type == DAYZ_CASINO_RESPONSE_RAT_RACE_NOT_ENOUGH_BALANCE) {
            DebugMessageCasino("receive not enough balance");
            rateRaceMenu.EndGame();
        }
    }
};