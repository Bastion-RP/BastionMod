class GameHint extends UIScriptedMenu
{
    private Widget hintWidget;
    private bool isOpen  = false;
    private MultilineTextWidget message;

    override Widget Init()
    {
        if (IsServerCasino()){
            return null;
        }

        if (IsInitialized()) {
            return hintWidget;
        }

        super.Init();

        hintWidget = GetGame().GetWorkspace().CreateWidgets("BastionCasino/layouts/GameHint.layout");
        message = MultilineTextWidget.Cast( hintWidget.FindAnyWidget( "message" ));
        message.SetText("#hint_can_open_game");

        isOpen = false;
        toggleWidget();

        return hintWidget;
    }

    override void OnHide()
    {
        if (!isOpen) {
            return;
        }

        super.OnHide();

        isOpen = false;
        toggleWidget();
    }


    override void OnShow()
    {
        if (isOpen) {
            return;
        }

        super.OnShow();

        isOpen = true;
        toggleWidget();
    }


    bool IsInitialized() {
        return !!hintWidget;
    }

    private void toggleWidget() {
        DebugMessageCasino("toggle hint " + isOpen);
        hintWidget.Show(isOpen);
    }
};