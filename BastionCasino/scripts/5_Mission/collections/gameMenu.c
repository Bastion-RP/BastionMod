class GameMenu
{
	private ref BetDiceMenu betDiceMenu;
	private ref BlackJackMenu blackJackMenu;
	private ref LuckyWheelMenu luckyWheelMenu;
	private ref RatRaceMenu ratRaceMenu;
	private ref GameHint gameHint;
	private CasinoConfig casinoConfig;
	
	void GameMenu(CasinoConfig casinoConfigExt) {
		DebugMessageCasino("Load GameMenu");
		casinoConfig = casinoConfigExt;
		DebugMessageCasino("check config dice menu" + casinoConfig.diceSettings.GAME_TYPE);
	}

    BetDiceMenu GetBetDiceMenu() {
        if (!betDiceMenu) {
            DebugMessageCasino("create bet dice menu");
            betDiceMenu = new BetDiceMenu();
			betDiceMenu.SetConfig(casinoConfig);
			betDiceMenu.SetWinFactor(casinoConfig.diceSettings.diceWinFactor);
        }

	    return betDiceMenu;
	}

    LuckyWheelMenu GetLuckyWheelMenu() {
        if (!luckyWheelMenu) {
            DebugMessageCasino("create lucky wheel menu");
            luckyWheelMenu = new LuckyWheelMenu();
            luckyWheelMenu.SetConfig(casinoConfig);
        }

	    return luckyWheelMenu;
	}

    BlackJackMenu GetBlackJackMenu() {
        if (!blackJackMenu) {
            DebugMessageCasino("create black jack menu");
            blackJackMenu = new BlackJackMenu();
			blackJackMenu.SetConfig(casinoConfig);
        }

	    return blackJackMenu;
	}
	
	RatRaceMenu GetRatRaceMenu() {
        if (!ratRaceMenu) {
            DebugMessageCasino("create rate race menu");
            ratRaceMenu = new RatRaceMenu();
			ratRaceMenu.SetConfig(casinoConfig);
        }

	    return ratRaceMenu;
	}

    GameHint GetGameHintMenu() {
        if (!gameHint) {
            DebugMessageCasino("create game hint menu");
            gameHint = new GameHint();
        }

	    return gameHint;
	}
	
	BaseMenu GetGameMenu(DayZPlayer player) {
		vector posPlayer = player.GetPosition();
		
		if (casinoConfig.diceSettings.enabled) {
			foreach(GamePosition position1: casinoConfig.diceSettings.gamePositions) {
				if (vector.Distance(position1.pos, posPlayer) <= DAYZ_CASINO_DISTANCE_TO_GAME){
					DebugMessageCasino("in near of bet dice");
					
					return GetBetDiceMenu();
				}
			}	
		}  
		if (casinoConfig.blackJackSettings.enabled) {
			foreach(GamePosition position2: casinoConfig.blackJackSettings.gamePositions) {
				if (vector.Distance(position2.pos, posPlayer) <= DAYZ_CASINO_DISTANCE_TO_GAME){
					DebugMessageCasino("in near of black jack");
					
					return GetBlackJackMenu();
				}
			}	
		} 
		if (casinoConfig.luckyWheelSettings.enabled) {
			foreach(GamePosition position3: casinoConfig.luckyWheelSettings.gamePositions) {
				if (vector.Distance(position3.pos, posPlayer) <= DAYZ_CASINO_DISTANCE_TO_GAME){
					DebugMessageCasino("in near of lucky wheel");
					
					return GetLuckyWheelMenu();
				}
			}	
		}
		if (casinoConfig.ratRaceSettings.enabled) {
			foreach(GamePosition position4: casinoConfig.ratRaceSettings.gamePositions) {
				if (vector.Distance(position4.pos, posPlayer) <= DAYZ_CASINO_DISTANCE_TO_GAME){
					DebugMessageCasino("in near of rat race");
					
					return GetRatRaceMenu();
				}
			}	
		}
		
		return null;
	}
	
	

	bool CanOpenHintToOpenGameMenu(DayZPlayer player) {
        vector posPlayer = player.GetPosition();
		
		if (casinoConfig.diceSettings.enabled) {
			foreach(GamePosition position1: casinoConfig.diceSettings.gamePositions) {
				if (vector.Distance(position1.pos, posPlayer) <= DAYZ_CASINO_DISTANCE_TO_GAME){
					return true;
				}
			}	
		}
		if (casinoConfig.blackJackSettings.enabled) {
			foreach(GamePosition position2: casinoConfig.blackJackSettings.gamePositions) {
				if (vector.Distance(position2.pos, posPlayer) <= DAYZ_CASINO_DISTANCE_TO_GAME){
					return true;
				}
			}	
		}
		if (casinoConfig.luckyWheelSettings.enabled) {
			foreach(GamePosition position3: casinoConfig.luckyWheelSettings.gamePositions) {
				if (vector.Distance(position3.pos, posPlayer) <= DAYZ_CASINO_DISTANCE_TO_GAME){
					return true;
				}
			}	
		}
		if (casinoConfig.ratRaceSettings.enabled) {
			foreach(GamePosition position4: casinoConfig.ratRaceSettings.gamePositions) {
				if (vector.Distance(position4.pos, posPlayer) <= DAYZ_CASINO_DISTANCE_TO_GAME){
					return true;
				}
			}	
		}
        
        return false;
	}
	
	void CloseAllMenu(){
		if (betDiceMenu) {
			betDiceMenu.Close();
		}
		if (blackJackMenu) {
			blackJackMenu.Close();
		}
		if (luckyWheelMenu) {
            luckyWheelMenu.Close();
		}
		if (ratRaceMenu) {
            ratRaceMenu.Close();
		}
	}
}