class LuckyWheelServerEventHandler
{
    private ref BastionCasinoPlayerInventory inventory;
    private ref LuckyWheelMapping luckyWheelMapping;
    private int chipsBet;
    private Jackpot jackpot;
	private bool enableLogs;

    void LuckyWheelServerEventHandler(bool enableLogs, map<string, int> currencyValues) {
        inventory = new BastionCasinoPlayerInventory(currencyValues);
		this.enableLogs = enableLogs;

        DebugMessageCasino("Register LWSEH");
        GetDayZGame().Event_OnRPC.Insert(HandleEvents);
    }

    void ~LuckyWheelServerEventHandler() {
        GetDayZGame().Event_OnRPC.Remove(HandleEvents);
    }

    void HandleEvents(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx) {
        if (!IsServerCasino()) {
            return;
        } else if (rpc_type == DAYZ_CASINO_LUCKY_WHEEL_START) {
            Param1<DayZPlayer> parameterRotate;
            if (ctx.Read(parameterRotate)) {
                DayZPlayer player = parameterRotate.param1;
                DebugMessageCasino("Check Player has chips");
                if (inventory.PlayerHasEnoughChips(player, chipsBet)){
                    LuckyWheelWin win = luckyWheelMapping.GetLuckyWheelWin();

                    int winAmmount = win.GetWinAmmount();
                    bool isJackpot = DAYZ_CASINO_LUCKY_WHEEL_JACKPOT_DEGREE == win.GetLuckyDegree();

                    if (isJackpot) {
                        winAmmount = jackpot.GetJackpotLuckyWheel();
                        jackpot.UpdateLuckyWheelJackpot(0);
                    }

                    if (winAmmount == 0) {
                        winAmmount = chipsBet * -1;
                        jackpot.UpdateLuckyWheelJackpot(chipsBet / 2 + jackpot.GetJackpotLuckyWheel());
                    }

                    inventory.AddChipsToPlayer(player, winAmmount);

					if (enableLogs) {
						BRP_CasinoLogPlay(player, winAmmount, "LuckyWheel");
					}
                    int currentChips = inventory.GetPlayerChipsAmount(player);
                    DebugMessageCasino("server: player has " + currentChips);

                    GetGame().RPCSingleParam(player, DAYZ_CASINO_LUCKY_WHEEL_START_RESPONSE, new Param5<int, int, int, int, bool>(win.GetLuckyDegree(), winAmmount, currentChips, jackpot.GetJackpotLuckyWheel(), isJackpot), true, player.GetIdentity());
                    DebugMessageCasino("has message send to player");
                } else {
                    GetGame().RPCSingleParam(player, DAYZ_CASINO_LUCKY_WHEEL_NOT_ENOUGH_CHIPS, new Param1<bool>(true), true,  player.GetIdentity());
                }
            }
        } else if (rpc_type == DAYZ_CASINO_LUCKY_WHEEL_GET_JACKPOT) {
            Param1<DayZPlayer> parameterGetJackpot;
            if (ctx.Read(parameterGetJackpot)) {
                DayZPlayer playerJackpot = parameterGetJackpot.param1;
                GetGame().RPCSingleParam(playerJackpot, DAYZ_CASINO_LUCKY_WHEEL_GET_JACKPOT_RESPONSE, new Param1<int>(jackpot.GetJackpotLuckyWheel()), true);
            }
        }

    }

    void SetConfig(CasinoGameSettingLuckyWheel settings) {
        chipsBet = settings.chipsBet;
        luckyWheelMapping = new LuckyWheelMapping(settings);
    }

    void SetJackpot(Jackpot jackpotex) {
        jackpot = jackpotex;
    }
};