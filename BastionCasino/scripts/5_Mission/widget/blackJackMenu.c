class BlackJackMenu extends GameBetBaseMenu
{
	private ButtonWidget holdCard;
	private ButtonWidget newGame;
	private ButtonWidget nextCard;
	private ImageWidget cards;
	private ImageWidget playerCard0;
	private ImageWidget playerCard1;
	private ImageWidget playerCard2;
	private ImageWidget playerCard3;
	private ImageWidget playerCard4;
	private ImageWidget playerCard5;
	private ImageWidget bankCard0;
	private ImageWidget bankCard1;
	private ImageWidget bankCard2;
	private ImageWidget bankCard3;
	private ImageWidget bankCard4;
	private ImageWidget bankCard5;
	private MultilineTextWidget pointPlayer;
	private MultilineTextWidget pointBank;
    private EffectSound effect_sound;
    private EffectSound lose_sound;
    private EffectSound win_sound;

    ref TIntArray usedCards;
    int cardValuePlayer;
    int cardValueBank;

	override Widget Init()
	{
		if (IsInitialized()) {
			return layoutRoot;
		}
		
        widgetPath = "BastionCasino/layouts/BlackJack.layout";
		super.Init();

		holdCard = ButtonWidget.Cast( layoutRoot.FindAnyWidget( "holdCard" ));
        WidgetEventHandler.GetInstance().RegisterOnMouseButtonDown( holdCard,  this, "OnClick" );
        usedCards = new TIntArray;

        newGame = ButtonWidget.Cast( layoutRoot.FindAnyWidget( "newGame" ));
        WidgetEventHandler.GetInstance().RegisterOnMouseButtonDown( newGame,  this, "OnClick" );

        nextCard = ButtonWidget.Cast( layoutRoot.FindAnyWidget( "nextCard" ));
        WidgetEventHandler.GetInstance().RegisterOnMouseButtonDown( nextCard,  this, "OnClick" );

        cards = ImageWidget.Cast(layoutRoot.FindAnyWidget( "cards" ));
        cards.LoadImageFile(0, "BastionCasino/data/cards/rueckseite.edds");
        cards.SetImage(0);
		
		pointBank = MultilineTextWidget.Cast( layoutRoot.FindAnyWidget("pointBank"));
		pointPlayer = MultilineTextWidget.Cast(layoutRoot.FindAnyWidget("pointPlayer"));

        bankCard0 = ImageWidget.Cast(layoutRoot.FindAnyWidget( "bankCard0" ));
        bankCard1 = ImageWidget.Cast(layoutRoot.FindAnyWidget( "bankCard1" ));
        bankCard2 = ImageWidget.Cast(layoutRoot.FindAnyWidget( "bankCard2" ));
        bankCard3 = ImageWidget.Cast(layoutRoot.FindAnyWidget( "bankCard3" ));
        bankCard4 = ImageWidget.Cast(layoutRoot.FindAnyWidget( "bankCard4" ));
        bankCard5 = ImageWidget.Cast(layoutRoot.FindAnyWidget( "bankCard5" ));
        playerCard0 = ImageWidget.Cast(layoutRoot.FindAnyWidget( "playerCard0" ));
        playerCard1 = ImageWidget.Cast(layoutRoot.FindAnyWidget( "playerCard1" ));
        playerCard2 = ImageWidget.Cast(layoutRoot.FindAnyWidget( "playerCard2" ));
        playerCard3 = ImageWidget.Cast(layoutRoot.FindAnyWidget( "playerCard3" ));
        playerCard4 = ImageWidget.Cast(layoutRoot.FindAnyWidget( "playerCard4" ));
        playerCard5 = ImageWidget.Cast(layoutRoot.FindAnyWidget( "playerCard5" ));
		effect_sound = SEffectManager.CreateSound("BastionCasino_FLIPCARD_SoundSet", player.GetPosition());
        win_sound = SEffectManager.CreateSound("BastionCasino_WIN_SoundSet", player.GetPosition());
        lose_sound = SEffectManager.CreateSound("BastionCasino_LOSE_SoundSet", player.GetPosition());
		
		maxChipsUse = casinoConfig.blackJackSettings.maxBet;
		minChipsUse = casinoConfig.blackJackSettings.minBet;

		return layoutRoot;
	}
	
	override void OnShow()
	{
		if (isMenuOpen) {
			DebugMessageCasino("Menu is already open");
			return;
		}
		
		super.OnShow();

		pointPlayer.SetText("0");
		pointBank.SetText("0");
        
		holdCard.Show(false);
		nextCard.Show(false);
		newGame.Show(true);
		
		HideCards();
	}

	override bool OnClick( Widget w, int x, int y, int button )	{
		DebugMessageCasino("on click action super");
		bool actionRuns = super.OnClick(w, x, y, button);

        if (actionRuns) {
            return actionRuns;
        } else if (w == newGame){
            DebugMessageCasino("click newGame");
            Play();
            return true;
        } else if (w == nextCard){
            DebugMessageCasino("click nextCard");
            GiveNextCard();
            return true;
        } else if (w == holdCard){
            DebugMessageCasino("click holdCard");
            HoldCardAction();
            return true;
        }

		return false;
	}

	void HideCards() {
        playerCard0.Show(false);
        playerCard1.Show(false);
        playerCard2.Show(false);
        playerCard3.Show(false);
        playerCard4.Show(false);
        playerCard5.Show(false);

        bankCard0.Show(false);
        bankCard1.Show(false);
        bankCard2.Show(false);
        bankCard3.Show(false);
        bankCard4.Show(false);
        bankCard5.Show(false);
	}

    override void Play(){
        if (CanPlayGame()) {
            super.Play();
            HideCards();
            message.Show(false);
            newGame.Show(false);

            Param2 <int, DayZPlayer> startGame = new Param2<int, DayZPlayer>(chipsValue, player);
            GetGame().RPCSingleParam(player, DAYZ_CASINO_BLACK_JACK_START_GAME, startGame, true);
        }
    }

    void SetStartCards(Card firstCardPlayer, Card secondCardPlayer, Card firstCardBank) {
        playerCard0.LoadImageFile(0, firstCardPlayer.GetImagePath());
        playerCard0.SetImage(0);
        playerCard0.Show(true);
        playerCard1.LoadImageFile(0, secondCardPlayer.GetImagePath());
        playerCard1.SetImage(0);
        playerCard1.Show(true);
        bankCard0.LoadImageFile(0, firstCardBank.GetImagePath());
        bankCard0.SetImage(0);
        bankCard0.Show(true);
        bankCard1.LoadImageFile(0, "BastionCasino/data/cards/rueckseite.edds");
        bankCard1.SetImage(0);
        bankCard1.Show(true);
        if (false == effect_sound.SoundPlay()) {
            DebugMessageCasino("give card sound not  loaded");
        }
	}

	void SetNextPlayerCard(int numberOfCard, Card nextPlayerCard) {
        switch(numberOfCard) {
            case 2:
                playerCard1.LoadImageFile(0, nextPlayerCard.GetImagePath());
                playerCard1.SetImage(0);
                playerCard1.Show(true);
                break;
            case 3:
                playerCard2.LoadImageFile(0, nextPlayerCard.GetImagePath());
                playerCard2.SetImage(0);
                playerCard2.Show(true);
                break;
            case 4:
                playerCard3.LoadImageFile(0, nextPlayerCard.GetImagePath());
                playerCard3.SetImage(0);
                playerCard3.Show(true);
                break;
            case 5:
                playerCard4.LoadImageFile(0, nextPlayerCard.GetImagePath());
                playerCard4.SetImage(0);
                playerCard4.Show(true);
                break;
            case 6:
                playerCard5.LoadImageFile(0, nextPlayerCard.GetImagePath());
                playerCard5.SetImage(0);
                playerCard5.Show(true);
                break;

            default:

                return;
        }
        if (false == effect_sound.SoundPlay()) {
            DebugMessageCasino("give card sound not loaded");
        }
	}

	void SetNextBankCard(int numberOfCard, Card nextBankCard) {
        switch(numberOfCard) {
            case 2:
                bankCard1.LoadImageFile(0, nextBankCard.GetImagePath());
                bankCard1.SetImage(0);
                bankCard1.Show(true);
                break;
            case 3:
                bankCard2.LoadImageFile(0, nextBankCard.GetImagePath());
                bankCard2.SetImage(0);
                bankCard2.Show(true);
                break;
            case 4:
                bankCard3.LoadImageFile(0, nextBankCard.GetImagePath());
                bankCard3.SetImage(0);
                bankCard3.Show(true);
                break;
            case 5:
                bankCard4.LoadImageFile(0, nextBankCard.GetImagePath());
                bankCard4.SetImage(0);
                bankCard4.Show(true);
                break;
            case 6:
                bankCard5.LoadImageFile(0, nextBankCard.GetImagePath());
                bankCard5.SetImage(0);
                bankCard5.Show(true);
                break;

            default:

                return;
        }
        if (false == effect_sound.SoundPlay()) {
            DebugMessageCasino("give card sound not loaded");
        }
	}

    void LoseGame() {
        countChips.SetText("" + currentAmount);
        lastWin.SetText("" + lastWinChips);
        if (false == lose_sound.SoundPlay()) {
            DebugMessageCasino("lose sound not loaded");
        }

        EndGame();
    }

    void WinGame() {
        countChips.SetText(currentAmount.ToString());
        lastWin.SetText(lastWinChips.ToString());
        if (false == win_sound.SoundPlay()) {
            DebugMessageCasino("win sound not loaded");
        }

        EndGame();
    }

    void RefreshPoints(string playerPoints, string bankPoints) {
        pointPlayer.SetText(playerPoints);
        pointBank.SetText(bankPoints);
    }

    override void EndGame() {
	    super.EndGame();
        holdCard.Show(false);
        nextCard.Show(false);
        newGame.Show(true);
    }

    void HidePlayButtons() {
        nextCard.Show(false);
        holdCard.Show(false);
	}

    void ShowPlayButtons() {
        nextCard.Show(true);
        holdCard.Show(true);
	}

    void HoldCardAction() {
        HidePlayButtons();
        GetGame().RPCSingleParam(player, DAYZ_CASINO_BLACK_JACK_HOLD_CARD, new Param2<ref TIntArray, DayZPlayer>(usedCards, player), true);
    }

	private void GiveNextCard() {
		if (cardValuePlayer > 21) {
			LoseGame();
		} else {
            HidePlayButtons();
			GetGame().RPCSingleParam(player, DAYZ_CASINO_BLACK_JACK_START_NEXT_CARD_PLAYER, new Param2<ref TIntArray, DayZPlayer>(usedCards, player), true);
		} 
	}

    void RefreshCardValues(array<Card> currentCardsPlayer, array<Card> currentCardsBank) {
        int maxValuePlayer = GetCurrentCardSum(currentCardsPlayer, true);
        int minValuePlayer = GetCurrentCardSum(currentCardsPlayer);

        int maxValueBank = GetCurrentCardSum(currentCardsBank, true);
        int minValueBank = GetCurrentCardSum(currentCardsBank);

        string showValuePlayer = "" + minValuePlayer + "/" + maxValuePlayer;
        cardValuePlayer = maxValuePlayer;
        if (maxValuePlayer == minValuePlayer || maxValuePlayer > 21) {
            cardValuePlayer = minValuePlayer;
            showValuePlayer = "" + minValuePlayer;
        }

        string showValueBank = "" + minValueBank + "/" + maxValueBank;
        cardValueBank = maxValueBank;
        if (minValueBank == maxValueBank || maxValueBank > 21) {
            showValueBank = "" + minValueBank;
            cardValueBank = minValueBank;
        }

        RefreshPoints(showValuePlayer, showValueBank);
    }

    private int GetCurrentCardSum(array<Card> cardsArray, bool max = false) {
        int value = 0;
        foreach(int index, Card card: cardsArray){
            DebugMessageCasino("card value is " + card.GetValue());
            value += card.GetValue();
            if (false == max && card.IsAss()) {
                value -= 10;
            }
        }

        return value;
    }

}