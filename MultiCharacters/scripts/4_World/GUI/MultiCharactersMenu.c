class MultiCharactersMenu : UIScriptedMenu {
    private ref MultiCharactersSurvivorSelector wSurvivorSelector;
    private ref MultiCharactersSurvivorCreator wSurvivorCreator;

    protected ref Widget wRoot;
    protected ref Widget wSurvivorSelectRoot;
    protected Camera playerCamera;
    protected int characterId;

    override Widget Init() {
        wRoot = GetGame().GetWorkspace().CreateWidgets("MultiCharacters\\gui\\layouts\\CharacterMenu.layout");
        wSurvivorCreator = new MultiCharactersSurvivorCreator(wRoot);
        wSurvivorSelector = new MultiCharactersSurvivorSelector(wRoot);

        InitCamera();
        wRoot.Show(false);
        return wRoot;
    }

    void InitCamera() {
        GetGame().ObjectDelete(playerCamera);
        playerCamera = Camera.Cast(g_Game.CreateObject("staticcamera", vector.Zero, true));
        playerCamera.SetActive(true);
    }

    override bool OnClick(Widget w, int x, int y, int button) {
        if (wSurvivorCreator.IsVisible()) {
            wSurvivorCreator.OnClick(w);
        } else if (wSurvivorSelector.IsVisible()) {
            wSurvivorSelector.OnClick(w);
        }
        return true;
    }

    override bool OnMouseButtonUp(Widget w, int x, int y, int button) {
        if (wSurvivorCreator.IsVisible()) {
            wSurvivorCreator.OnMouseButtonUp(w);

            if (wSurvivorCreator.GetBackButton() == w) {
                wSurvivorSelector.Show();
            }
        } else if (wSurvivorSelector.IsVisible()) {
            MultiCharactersPlayerStatPanel statPanel = wSurvivorSelector.GetStatPanel(w);

            wSurvivorSelector.OnMouseButtonUp(w);
            
            if (statPanel && statPanel.GetSavePlayer().IsDead()) {
                wSurvivorCreator.Show();
            }
        }
        return true;
    }

    override bool OnMouseEnter(Widget w, int x, int y) {
        if (wSurvivorCreator.IsVisible()) {
            wSurvivorCreator.OnMouseEnter(w);
        } else if (wSurvivorSelector.IsVisible()) {
            wSurvivorSelector.OnMouseEnter(w);
        }
        return true;
    }

    override bool OnMouseLeave(Widget w, Widget enterW, int x, int y) {
        if (wSurvivorCreator.IsVisible()) {
            wSurvivorCreator.OnMouseLeave(w);
        } else if (wSurvivorSelector.IsVisible()) {
            wSurvivorSelector.OnMouseLeave(w);
        }
        return true;
    }

    override void OnShow() {
        super.OnShow();

        GetGame().GetMission().PlayerControlDisable(INPUT_EXCLUDE_ALL);
        GetGame().GetUIManager().ShowCursor(true);
        GetGame().GetMission().GetHud().Show(false);
        GetGame().GetUIManager().ScreenFadeOut(0);
    }

    override void OnHide() {
        super.OnHide();

        GetGame().GetUIManager().ShowCursor(false);
        GetGame().GetMission().PlayerControlEnable(true);
        GetGame().GetMission().GetHud().Show(true);
    }
}