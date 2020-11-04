class GameBetBaseMenu extends BaseMenu
{

    protected ButtonWidget sub1ChipsBet;
    protected ButtonWidget sub10ChipsBet;
    protected ButtonWidget sub100ChipsBet;
    protected ButtonWidget sub1000ChipsBet;
    protected ButtonWidget add1ChipsBet;
    protected ButtonWidget add10ChipsBet;
    protected ButtonWidget add100ChipsBet;
    protected ButtonWidget add1000ChipsBet;
    protected TextWidget chipsBet;
    protected int chipsValue = 10;
    protected int maxChipsUse;
    protected int minChipsUse;

    override Widget Init()
    {
        if (IsServerCasino()){
            DebugMessageCasino("can not init, is server");
            return null;
        }

        if (IsInitialized()) {
            return layoutRoot;
        }

        super.Init();

        sub1ChipsBet = ButtonWidget.Cast( layoutRoot.FindAnyWidget( "sub1ChipsBet" ));
        WidgetEventHandler.GetInstance().RegisterOnMouseButtonDown( sub1ChipsBet,  this, "OnClick" );
        sub10ChipsBet = ButtonWidget.Cast( layoutRoot.FindAnyWidget( "sub10ChipsBet" ));
        WidgetEventHandler.GetInstance().RegisterOnMouseButtonDown( sub10ChipsBet,  this, "OnClick" );
        sub100ChipsBet = ButtonWidget.Cast( layoutRoot.FindAnyWidget( "sub100ChipsBet" ));
        WidgetEventHandler.GetInstance().RegisterOnMouseButtonDown( sub100ChipsBet,  this, "OnClick" );
        sub1000ChipsBet = ButtonWidget.Cast( layoutRoot.FindAnyWidget( "sub1000ChipsBet" ));
        WidgetEventHandler.GetInstance().RegisterOnMouseButtonDown( sub1000ChipsBet,  this, "OnClick" );
        add1ChipsBet = ButtonWidget.Cast( layoutRoot.FindAnyWidget( "add1ChipsBet" ));
        WidgetEventHandler.GetInstance().RegisterOnMouseButtonDown( add1ChipsBet,  this, "OnClick" );
        add10ChipsBet = ButtonWidget.Cast( layoutRoot.FindAnyWidget( "add10ChipsBet" ));
        WidgetEventHandler.GetInstance().RegisterOnMouseButtonDown( add10ChipsBet,  this, "OnClick" );
        add100ChipsBet = ButtonWidget.Cast( layoutRoot.FindAnyWidget( "add100ChipsBet" ));
        WidgetEventHandler.GetInstance().RegisterOnMouseButtonDown( add100ChipsBet,  this, "OnClick" );
        add1000ChipsBet = ButtonWidget.Cast( layoutRoot.FindAnyWidget( "add1000ChipsBet" ));
        WidgetEventHandler.GetInstance().RegisterOnMouseButtonDown( add1000ChipsBet,  this, "OnClick" );
		
		chipsBet = TextWidget.Cast(layoutRoot.FindAnyWidget("chipsBet"));
		chipsBet.SetText(chipsValue.ToString());

        return layoutRoot;
    }

    override bool OnClick( Widget w, int x, int y, int button )	{
        bool actionRuns = super.OnClick(w, x, y, button);

        if (actionRuns) {
			DebugMessageCasino("action has allready run");
            return actionRuns;
        }

        if (w == sub1ChipsBet){
            UpdateCurrenBet(-1);
            return true;
        } else if (w == sub10ChipsBet){
            UpdateCurrenBet(-10);
            return true;
        } else if (w == sub100ChipsBet){
            UpdateCurrenBet(-100);
            return true;
        } else if (w == sub1000ChipsBet){
            UpdateCurrenBet(-1000);
            return true;
        } else if (w == add1ChipsBet){
            UpdateCurrenBet(1);
            return true;
        } else if (w == add10ChipsBet){
            UpdateCurrenBet(10);
            return true;
        } else if (w == add100ChipsBet){
            UpdateCurrenBet(100);
            return true;
        } else if (w == add1000ChipsBet){
            UpdateCurrenBet(1000);
            return true;
        }

        return false;
    }

	protected void UpdateCurrenBet(int addBet) {
		DebugMessageCasino("increase bet " + addBet.ToString() + " old value " + chipsValue.ToString());
        chipsValue = chipsValue + addBet;
		
		DebugMessageCasino("new chipsValue " + chipsValue.ToString());
		DebugMessageCasino("min use" + minChipsUse.ToString());
		DebugMessageCasino("max use" + maxChipsUse.ToString());

        if (chipsValue < minChipsUse) {
            chipsValue = minChipsUse;
        } else if (chipsValue > maxChipsUse) {
            chipsValue = maxChipsUse;
        } else if (chipsValue > currentAmount && currentAmount != 0) {
            chipsValue = currentAmount;
        } else if (chipsValue > currentAmount && currentAmount == 0) {
            chipsValue = minChipsUse;
			
        }

        chipsBet.SetText(chipsValue.ToString());
    }

    int GetCurrenBet() {
        return chipsValue;
    }


    override protected bool CanPlayGame() {
        if (super.CanPlayGame()) {
            int currentAmountLocal = inventory.GetPlayerChipsAmount(GetGame().GetPlayer());
            if (0 == currentAmountLocal || chipsValue > currentAmountLocal) {
                countChips.SetText(currentAmountLocal.ToString());
                message.SetText("#Not_enough_chips_available");
                message.Show(true);

                return false;
            }
            return true;
        }

        return false;
    }

    override void Play() {
        super.Play();
        sub1ChipsBet.Show(false);
        sub10ChipsBet.Show(false);
        sub100ChipsBet.Show(false);
        sub1000ChipsBet.Show(false);
        add1ChipsBet.Show(false);
        add10ChipsBet.Show(false);
        add100ChipsBet.Show(false);
        add1000ChipsBet.Show(false);
    }

    override void EndGame() {
        super.EndGame();
        sub1ChipsBet.Show(true);
        sub10ChipsBet.Show(true);
        sub100ChipsBet.Show(true);
        sub1000ChipsBet.Show(true);
        add1ChipsBet.Show(true);
        add10ChipsBet.Show(true);
        add100ChipsBet.Show(true);
        add1000ChipsBet.Show(true);
    }

}