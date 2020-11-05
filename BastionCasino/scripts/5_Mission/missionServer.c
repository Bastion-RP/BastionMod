modded class MissionServer {

	private ref CasinoConfig casinoConfig;
	private ref BlackJackServerEventHandler blackJackServerEventHandler;
	private ref RatRaceServerEventHandler ratRaceServerEventHandler;
	private ref BetDiceServerEventHandler betDiceServerEventHandler;
	private ref LuckyWheelServerEventHandler luckyWheelServerEventHandler;
	private ref Jackpot jackpot;

	void MissionServer()
	{
		casinoConfig = new CasinoConfig();

        if (casinoConfig.diceSettings.enabled) {
			foreach(GamePosition position: casinoConfig.diceSettings.gamePositions) {
				PlaceGame(position.pos, position.orientation, casinoConfig.diceSettings.gameObject);
			}
            
            betDiceServerEventHandler = BetDiceServerEventHandler(casinoConfig.currencyValues);
			betDiceServerEventHandler.SetConfig(casinoConfig.enablePlayLogs, casinoConfig.diceSettings);
        }
        if (casinoConfig.blackJackSettings) {
			foreach(GamePosition position1: casinoConfig.blackJackSettings.gamePositions) {
				PlaceGame(position1.pos, position1.orientation, casinoConfig.blackJackSettings.gameObject);
			}
            blackJackServerEventHandler = BlackJackServerEventHandler(casinoConfig.blackJackSettings, casinoConfig.enablePlayLogs, casinoConfig.currencyValues);
        }
        if (casinoConfig.ratRaceSettings.enabled) {
			foreach(GamePosition position2: casinoConfig.ratRaceSettings.gamePositions) {
				PlaceGame(position2.pos, position2.orientation, casinoConfig.ratRaceSettings.gameObject);
			}
            ratRaceServerEventHandler = RatRaceServerEventHandler(casinoConfig.currencyValues);
			ratRaceServerEventHandler.SetConfig(casinoConfig.ratRaceSettings, casinoConfig.enablePlayLogs);
        }
        if (casinoConfig.luckyWheelSettings) {
			foreach(GamePosition position3: casinoConfig.luckyWheelSettings.gamePositions) {
				PlaceGame(position3.pos, position3.orientation, casinoConfig.luckyWheelSettings.gameObject);
			}
            luckyWheelServerEventHandler = LuckyWheelServerEventHandler(casinoConfig.enablePlayLogs, casinoConfig.currencyValues);
            luckyWheelServerEventHandler.SetConfig(casinoConfig.luckyWheelSettings);
            jackpot = Jackpot(casinoConfig.luckyWheelSettings.minJackpot);
            luckyWheelServerEventHandler.SetJackpot(jackpot);
        }

        GetDayZGame().Event_OnRPC.Insert(HandleEventsCasino);
		DebugMessageCasino("loaded");
	}

	void ~MissionServer() {
		GetDayZGame().Event_OnRPC.Remove(HandleEventsCasino);
	}
	
	void HandleEventsCasino(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx) {
		if (rpc_type == DAYZ_CASINO_GET_CASINO_CONFIG) {
			DebugMessageCasino("receive get config");
			autoptr Param1<PlayerBase> paramGetConfig;
			if (ctx.Read(paramGetConfig)){
                GetGame().RPCSingleParam(paramGetConfig.param1, DAYZ_CASINO_GET_CASINO_CONFIG_RESPONSE, new Param1<ref CasinoConfig>(casinoConfig), true, sender);
			}
		}
	}

    private void PlaceGame(vector pos, vector orientation, string gameObjectName) {
        DebugMessageCasino("create object " + gameObjectName);
        House game_obj = Building.Cast(GetGame().CreateObject(gameObjectName, pos));
        game_obj.SetPosition( pos );
        game_obj.SetOrientation( orientation );
        game_obj.SetOrientation( game_obj.GetOrientation() ); //Collision fix
        game_obj.Update();
        game_obj.SetAffectPathgraph( true, false );
        if( game_obj.CanAffectPathgraph() ) {
            GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( GetGame().UpdatePathgraphRegionByObject, 100, false, game_obj );
        }
    }
};