modded class MissionGameplay 
{
	private ref GameMenu gameMenu;
	private ref CasinoConfig casinoConfig;
	private ref BlackJackClientEventHandler blackJackClientEventHandler;
	private ref BetDiceClientEventHandler betDiceClientEventHandler;
	private ref LuckyWheelClientEventHandler luckyWheelClientEventHandler;
	private ref RatRaceClientEventHandler ratRaceClientEventHandler;

	void MissionGameplay() {
		DebugMessageCasino("init Mission MissionGameplay");
		
		GetDayZGame().Event_OnRPC.Insert(HandleEventsCasino);
        Param1<DayZPlayer> paramGetConfig = new Param1<DayZPlayer>(GetGame().GetPlayer());
	    GetGame().RPCSingleParam(paramGetConfig.param1, DAYZ_CASINO_GET_CASINO_CONFIG, paramGetConfig, true);
	}
	
	void ~MissionGameplay() {
		GetDayZGame().Event_OnRPC.Remove(HandleEventsCasino);
	}
	
	void HandleEventsCasino(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx) {
		if (rpc_type == DAYZ_CASINO_GET_CASINO_CONFIG_RESPONSE) {
			DebugMessageCasino("player receive config");
			Param1 <ref CasinoConfig> casinoConfigParam;
			if (ctx.Read(casinoConfigParam)){
				casinoConfig = casinoConfigParam.param1;
				DebugMessageCasino("player load config");
				gameMenu = new GameMenu(casinoConfig);
				Man player = GetGame().GetPlayer();
				PlayerBase playerPB = PlayerBase.Cast(GetGame().GetPlayer());
				if(casinoConfig && playerPB)
					playerPB.casinoConfig = casinoConfig;
                blackJackClientEventHandler = new BlackJackClientEventHandler();
                betDiceClientEventHandler = new BetDiceClientEventHandler();
                luckyWheelClientEventHandler = new LuckyWheelClientEventHandler();
				ratRaceClientEventHandler = new RatRaceClientEventHandler();
			}
		} else if (HasClientEventHandler()) {
            blackJackClientEventHandler.HandleEvents(gameMenu.GetBlackJackMenu(), sender, target, rpc_type, ctx);
            betDiceClientEventHandler.HandleEvents(gameMenu.GetBetDiceMenu(), sender, target, rpc_type, ctx);
            luckyWheelClientEventHandler.HandleEvents(gameMenu.GetLuckyWheelMenu(), sender, target, rpc_type, ctx);
            ratRaceClientEventHandler.HandleEvents(gameMenu.GetRatRaceMenu(), sender, target, rpc_type, ctx);
		} else {
            DebugMessageCasino("NO game event handler registered");
		}
	}
	
	override void OnUpdate(float timeslice)
	{
		super.OnUpdate(timeslice);
		ref PlayerBase player = GetGame().GetPlayer();
		
        if(player) {
        	if(!player.casinoConfig)
        	{
        		if(gameMenu.GetCasinoConfig())
        		{
        			player.casinoConfig = gameMenu.GetCasinoConfig();
        		}
        	}
            /*UAInput localInput = GetUApi().GetInputByName("UAInputPlayCasinoGame");
            if (localInput && localInput.LocalClick()){*/
        	Print("playerPB.actionOpenCasinoMenu = " + player.GetActionOpenCasinoMenu());
        	if (player.GetActionOpenCasinoMenu())
        	{
				BaseMenu currentGameMenu = gameMenu.GetGameMenu(player);
				if (currentGameMenu && !currentGameMenu.isMenuOpen && player.IsAlive()) {
					DebugMessageCasino("key press open");
                    currentGameMenu.Init();
					currentGameMenu.OnShow();
					player.SetActionOpenCasinoMenu(false);
				}
			}
			
			if (!player.IsAlive() && gameMenu){
				gameMenu.CloseAllMenu();
			}

			/*if (gameMenu && gameMenu.CanOpenHintToOpenGameMenu(player)){
                //gameMenu.GetGameHintMenu().Init();
                //gameMenu.GetGameHintMenu().OnShow();
			} else if (gameMenu) {
                //gameMenu.GetGameHintMenu().OnHide();
			}*/
		}
	}

	private bool HasClientEventHandler() {
	    return null != blackJackClientEventHandler && null != betDiceClientEventHandler && null != luckyWheelClientEventHandler && null != ratRaceClientEventHandler;
	}
}