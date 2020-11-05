class BlackJackServerEventHandler
{
    private ref BastionCasinoPlayerInventory inventory;
    private ref CardCollection cardCollection;
	CasinoGameSettingBlackjack config;
	private bool enableLogs = false;

    void BlackJackServerEventHandler(CasinoGameSettingBlackjack config, bool enableLogs, map<string, int> currencyValues) {
        inventory = new BastionCasinoPlayerInventory(currencyValues);
        cardCollection = new CardCollection();
        DebugMessageCasino("Register BJSEH");
        GetDayZGame().Event_OnRPC.Insert(HandleEvents);
		this.config = config;
		this.enableLogs = enableLogs;
    }

    void ~BlackJackServerEventHandler() {
        GetDayZGame().Event_OnRPC.Remove(HandleEvents);
    }

    void HandleEvents(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx) {
        if (!IsServerCasino()) {
            return;
        } else if (rpc_type == DAYZ_CASINO_BLACK_JACK_START_GAME) {
            Param2<int, DayZPlayer> startGame;
            if (ctx.Read(startGame)) {
                DayZPlayer player = startGame.param2;
                if (inventory.PlayerHasEnoughChips(player, startGame.param1)) {
                    inventory.AddChipsToPlayer(player, startGame.param1 * - 1);
                    TIntArray cardAllreadyUsedServer = new TIntArray;
                    int firstCardPlayerServer = cardCollection.GetRandomCardIndex(cardAllreadyUsedServer);
                    cardAllreadyUsedServer.Insert(firstCardPlayerServer);
                    int secondCardPlayerServer = cardCollection.GetRandomCardIndex(cardAllreadyUsedServer);
                    cardAllreadyUsedServer.Insert(secondCardPlayerServer);
                    int firstCardBankServer = cardCollection.GetRandomCardIndex(cardAllreadyUsedServer);
                    cardAllreadyUsedServer.Insert(firstCardBankServer);

                    DebugMessageCasino("client first card is " + firstCardPlayerServer);

                    GetGame().RPCSingleParam(player, DAYZ_CASINO_BLACK_JACK_START_GAME_RESPONSE, new
                    Param3<int, int, int>(firstCardPlayerServer, secondCardPlayerServer, firstCardBankServer), true, player.GetIdentity());
                } else {
                    GetGame().RPCSingleParam(player, DAYZ_CASINO_BLACK_JACK_NOT_ENOUGH_CHIPS, new
                    Param1<bool>(true), true, player.GetIdentity());
                }
            }
        } else if (rpc_type == DAYZ_CASINO_BLACK_JACK_START_NEXT_CARD_PLAYER) {
            Param2 <ref TIntArray, DayZPlayer> nextCardParam;
            if (ctx.Read(nextCardParam)) {
                DayZPlayer playerNextCard = nextCardParam.param2;

                DebugMessageCasino("receive next card" + nextCardParam.param1);

                TIntArray cardUsedCollection = TIntArray.Cast(nextCardParam.param1);

                int newPlayerCard = cardCollection.GetRandomCardIndex(cardUsedCollection);

                DebugMessageCasino("new card server is " + newPlayerCard);

                GetGame().RPCSingleParam(playerNextCard, DAYZ_CASINO_BLACK_JACK_START_NEXT_CARD_PLAYER_RESPONSE, new
                Param1<int>(newPlayerCard), true, playerNextCard.GetIdentity());
            }
        } else if (rpc_type == DAYZ_CASINO_BLACK_JACK_HOLD_CARD) {
            Param2 < ref TIntArray, DayZPlayer > holdCardParam;
            if (ctx.Read(holdCardParam)) {
                DayZPlayer playerHoldCard = holdCardParam.param2;

                DebugMessageCasino("receive new bank card" + holdCardParam.param1);

                TIntArray cardUsedCollectionBank = TIntArray.Cast(holdCardParam.param1);

                int newBankCard = cardCollection.GetRandomCardIndex(cardUsedCollectionBank);

                DebugMessageCasino("new card server is " + newPlayerCard);

                GetGame().RPCSingleParam(playerHoldCard, DAYZ_CASINO_BLACK_JACK_HOLD_CARD_RESPONSE, new
                Param1<int>(newBankCard), true, playerHoldCard.GetIdentity());
            }
        } else if (rpc_type == DAYZ_CASINO_BLACK_JACK_LOOSE_PLAYER) {
            EndGame(DAYZ_CASINO_BLACK_JACK_LOOSE_PLAYER_RESPONSE, -1, ctx, false);
        } else if (rpc_type == DAYZ_CASINO_BLACK_JACK_BANK_LOSE) {
            EndGame(DAYZ_CASINO_BLACK_JACK_BANK_LOSE_RESPONSE, config.winFactor, ctx, true);
        } else if (rpc_type == DAYZ_CASINO_BLACK_JACK_PLAYER_HAS_BLACKJACK) {
            EndGame(DAYZ_CASINO_BLACK_JACK_PLAYER_HAS_BLACKJACK_RESPONSE, config.winFactorBlackJack, ctx, true);
        } else if (rpc_type == DAYZ_CASINO_BLACK_JACK_DRAW_GAME) {
            EndGame(DAYZ_CASINO_BLACK_JACK_DRAW_GAME_RESPONSE, 1, ctx, true, false);
        }

    }

    private void EndGame(int EVENT_RESPONSE, float chipsAddFactor, ParamsReadContext ctx, bool addMoney, bool drawGame = false) {
        Param2<int, DayZPlayer> winGameParam;
        if (ctx.Read(winGameParam)) {
            DayZPlayer playerWin = winGameParam.param2;
            float winSum = winGameParam.param1 * chipsAddFactor;

            if (addMoney) {
                inventory.AddChipsToPlayer(playerWin, winSum);
            }

            if (drawGame) {
                winSum = 0;
            }

            DebugMessageCasino("receive game end " + winSum);
			if (enableLogs) {
				BRP_CasinoLogPlay(playerWin, winSum, "BlackJack");
			}

            GetGame().RPCSingleParam(playerWin, EVENT_RESPONSE, new
            Param2<int, int>(inventory.GetPlayerChipsAmount(playerWin), winSum), true, playerWin.GetIdentity());
        }
    }
};