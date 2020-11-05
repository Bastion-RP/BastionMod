class BetDiceServerEventHandler
{
    ref BastionCasinoPlayerInventory inventory;
	private CasinoGameSettingDice casinoGameSettingDice;
	private bool enableLogs = false;

    void BetDiceServerEventHandler(map<string, int> currencyValues) {
        inventory = new BastionCasinoPlayerInventory(currencyValues);
        DebugMessageCasino("Register BDSEH");
        GetDayZGame().Event_OnRPC.Insert(HandleEvents);
    }

    void ~BetDiceServerEventHandler() {
        GetDayZGame().Event_OnRPC.Remove(HandleEvents);
    }

    void HandleEvents(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx) {
        if (!IsServerCasino()) {
            return;
        }

        if (rpc_type == DAYZ_CASINO_SHUFFEL_BET_DICE) {
            Param3<int, int, DayZPlayer> parameterShuffle;
            if (ctx.Read(parameterShuffle)) {
                DayZPlayer player = parameterShuffle.param3;
                DebugMessageCasino("Check Player has chips");
                if (inventory.PlayerHasEnoughChips(player, parameterShuffle.param1)){
                    int luckNumber1 = Math.RandomIntInclusive(1, 6);
                    int luckNumber2 = Math.RandomIntInclusive(1, 6);

                    if (DAYZ_CASINO_DEBUG) {
                        luckNumber1 = 1;
                        luckNumber2 = 1;
                    }
    
                    int winSum = 0;
    
                    if (parameterShuffle.param2 == luckNumber1 + luckNumber2) {
                        DebugMessageCasino("Win");
                        winSum = casinoGameSettingDice.diceWinFactor * parameterShuffle.param1;
    
                    } else {
                        DebugMessageCasino("lose");
                        winSum = -1 * parameterShuffle.param1;
                    }

                    inventory.AddChipsToPlayer(player, winSum);
                    int currentChips = inventory.GetPlayerChipsAmount(player);
                    DebugMessageCasino("server: player has " + currentChips);

					if (enableLogs) {
						BRP_CasinoLogPlay(player, winSum, "DiceGame");
					}
                    
                    GetGame().RPCSingleParam(player, DAYZ_CASINO_RESPONSE_SHUFFEL_BET_DICE, new Param4<int, int, int, int>(luckNumber1,luckNumber2, winSum, currentChips), true, player.GetIdentity());
                    DebugMessageCasino("has message send to player");
                } else {
                    GetGame().RPCSingleParam(player, DAYZ_CASINO_RESPONSE_SHUFFEL_BET_DICE_NOT_ENOUGH_BALANCE, new Param1<bool>(true), true,  player.GetIdentity());
                }
            }
        }
    }
	
    void SetConfig(bool enableLogs, CasinoGameSettingDice casinoGameSettingDiceParam) {
        casinoGameSettingDice = casinoGameSettingDiceParam;
        this.enableLogs = enableLogs;
    }

};