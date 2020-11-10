class BaseMenu extends UIScriptedMenu
{
    protected bool isDebug = DAYZ_CASINO_DEBUG;
	protected ButtonWidget info;
	protected ButtonWidget steam;
	protected ButtonWidget donate;
	protected ButtonWidget closeInfo;
	protected Widget infoWidget;
	protected DayZPlayer player;
    protected ButtonWidget cancel;
    protected MultilineTextWidget lastWin;
    protected MultilineTextWidget message;
    protected MultilineTextWidget countChips;
	protected CasinoConfig casinoConfig;
	bool isMenuOpen = false;
	protected map<string, int> currencyValues;
    ref protected BastionCasinoPlayerInventory inventory;
    int lastWinChips;
    int currentAmount;
    protected string widgetPath;
	
	void SetConfig(CasinoConfig casinoConfigExt) {
        casinoConfig = casinoConfigExt;
		inventory = new BastionCasinoPlayerInventory(casinoConfig.currencyValues);
	}

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
		
        
		player = GetGame().GetPlayer();

        layoutRoot = GetGame().GetWorkspace().CreateWidgets(widgetPath);

        cancel = ButtonWidget.Cast( layoutRoot.FindAnyWidget( "cancel" ));
        WidgetEventHandler.GetInstance().RegisterOnMouseButtonDown(cancel,  this, "OnClick");

        countChips = MultilineTextWidget.Cast( layoutRoot.FindAnyWidget("countChips"));
        lastWin = MultilineTextWidget.Cast( layoutRoot.FindAnyWidget("lastWin"));
        message = MultilineTextWidget.Cast( layoutRoot.FindAnyWidget("message"));

        layoutRoot.Show(false);
		
		info = ButtonWidget.Cast( layoutRoot.FindAnyWidget( "info" ));
		
		WidgetEventHandler.GetInstance().RegisterOnMouseButtonDown( info,  this, "OnClick" );
		
		infoWidget = GetGame().GetWorkspace().CreateWidgets("BastionMod/BastionCasino/layouts/Info.layout");
		infoWidget.Show(false);
		
		closeInfo = ButtonWidget.Cast( infoWidget.FindAnyWidget( "closeInfo" ));
		steam = ButtonWidget.Cast( infoWidget.FindAnyWidget( "steam" ));
		donate = ButtonWidget.Cast( infoWidget.FindAnyWidget( "donate" ));
		WidgetEventHandler.GetInstance().RegisterOnMouseButtonDown( closeInfo,  this, "OnClick" );
		WidgetEventHandler.GetInstance().RegisterOnMouseButtonDown( steam,  this, "OnClick" );
		WidgetEventHandler.GetInstance().RegisterOnMouseButtonDown( donate,  this, "OnClick" );
		layoutRoot.AddChild(infoWidget);

        return layoutRoot;
    }

    override bool OnClick( Widget w, int x, int y, int button )	{
        bool actionRuns = super.OnClick(w, x, y, button);

        if (actionRuns) {
            return actionRuns;
        }

        if (w == cancel){
            DebugMessageCasino("click cancel");
            CloseMenu();
            return true;
        } else if (w == info){
            infoWidget.Show(true);
            return true;
        } else if (w == closeInfo){
            infoWidget.Show(false);
            return true;
        } else if (w == donate){
            GetGame().OpenURL("https://www.paypal.com/pools/c/8idQvmteIO");
            return true;
        } else if (w == steam){
            GetGame().OpenURL("https://steamcommunity.com/sharedfiles/filedetails/?id=1940425039");
            return true;
        }

        return false;
    }
	
	override void OnHide()
	{
		if (!isMenuOpen) {
			return;
		}
		
		DebugMessageCasino("hide action");
		super.OnHide();

		PPEffects.SetBlurMenu(0);

		GetGame().GetUIManager().ShowCursor(false);
		GetGame().GetUIManager().ShowUICursor(false);
		GetGame().GetInput().ResetGameFocus();
		GetGame().GetMission().PlayerControlEnable(true);
		GetGame().GetUIManager().Back();
		GetGame().GetMission().GetHud().Show( true );

		Close();
		isMenuOpen = false;
	}
	
		
	override void OnShow()
	{
		if (isMenuOpen) {
			DebugMessageCasino("Menu is already open");
			return;
		}
		
		super.OnShow();
				
		DebugMessageCasino("show action");
		
		PPEffects.SetBlurMenu(0.5);

		SetFocus( layoutRoot );
		layoutRoot.Show(true);

		GetGame().GetMission().PlayerControlDisable(INPUT_EXCLUDE_INVENTORY);
		GetGame().GetUIManager().ShowUICursor(true);
		GetGame().GetUIManager().ShowCursor(true);
		GetGame().GetInput().ChangeGameFocus( 1 );
		GetGame().GetMission().GetHud().Show( false );
		isMenuOpen = true;
        currentAmount =  inventory.GetPlayerChipsAmount(player);
        countChips.SetText(currentAmount.ToString());
        lastWin.SetText("0");
	}

    void Play() {
        cancel.Show(false);
		message.Show(false);
    }

    void EndGame() {
        cancel.Show(true);
    }
	
	protected bool CanPlayGame() {
        return player && isMenuOpen;
    }
	
	void CloseMenu(){
		DebugMessageCasino("check is open");
		if(isMenuOpen){
			DebugMessageCasino("try close menu");
			SetFocus(NULL);
			OnHide();
			layoutRoot.Show(false);
			isMenuOpen = false;
		}	
	}
	
	bool IsInitialized() {
		return !!layoutRoot;
	}

}