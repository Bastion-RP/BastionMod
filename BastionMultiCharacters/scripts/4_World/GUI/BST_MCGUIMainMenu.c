class BST_MCGUIMainMenu : UIScriptedMenu {
    private ref BST_MCGUICharacterSelect _rootCharacterSelect;
    private ref BST_MCGUISurvivorSelect _rootSurvivorSelect;
    private ref BST_MCGUICharPreviewWidget _pnlPlyPreview;
    private ref BST_MCGUICharInfoWidget _pnlCharInfo;
    private ref ButtonWidget _btnDisconnect;
    protected Camera _camera;
    private int _loginTimer;

    override Widget Init() {
        layoutRoot = GetGame().GetWorkspace().CreateWidgets("BastionMod/BastionMultiCharacters/gui/layout/MainMenu.layout");
        _btnDisconnect = ButtonWidget.Cast(layoutRoot.FindAnyWidget("btnDisconnect"));
        _camera = Camera.Cast(GetGame().CreateObjectEx("staticcamera", vector.Zero, ECE_LOCAL));
        _rootCharacterSelect = new BST_MCGUICharacterSelect(this, layoutRoot);
        _rootSurvivorSelect = new BST_MCGUISurvivorSelect(this, layoutRoot);
        _pnlPlyPreview = new BST_MCGUICharPreviewWidget(layoutRoot);
        _pnlCharInfo = new BST_MCGUICharInfoWidget(layoutRoot);

        _camera.SetActive(true);
        _pnlPlyPreview.Init(_rootCharacterSelect, 0, 0);
        _pnlCharInfo.Init(_rootCharacterSelect, 0, 0);
        _rootCharacterSelect.Init();
        _rootSurvivorSelect.Init();
        _rootCharacterSelect.Show(true);
        _rootSurvivorSelect.Show(false);

        return layoutRoot;
    }

    override void OnShow() {
        super.OnShow();

        GetGame().GetMission().PlayerControlDisable(INPUT_EXCLUDE_ALL);
        GetGame().GetMission().GetHud().Show(false);
        GetGame().GetUIManager().ShowCursor(true);
        GetGame().GetUIManager().ScreenFadeOut(0);
    }

    override void OnHide() {
        super.OnHide();

        if (GetGame().GetMission() && GetGame().GetMission().GetHud()) {
            GetGame().GetMission().GetHud().Show(true);
        }
        GetGame().GetUIManager().ShowCursor(false);

    }

    void CreateandShowSurvivorSelector(BST_MCSavePlayerBasic character) {
        _rootSurvivorSelect.SetCharacter(character);
        _rootCharacterSelect.Show(false);
        _rootSurvivorSelect.Show(true);
    }

	override bool OnClick(Widget w, int x, int y, int button) {
        if (w == _btnDisconnect) {
            GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Call(GetGame().DisconnectSessionForce);
        }
        return super.OnClick(w, x, y, button);
    }
    
    void StartSpawnCountdown(bool isNewSurvivor = false) {
        _loginTimer = GetBSTMCManager().GetConfig().GetSpawnTimer();
        
        _rootCharacterSelect.Show(false);
        _rootSurvivorSelect.Show(false);
        _pnlPlyPreview.Show(false);
        _pnlCharInfo.Show(false);
        _btnDisconnect.Show(false);
        ShowSpawnCountdown(isNewSurvivor);
    }

    void ShowSpawnCountdown(bool isNewSurvivor = false) {
        if (_loginTimer <= 0) {
            if (isNewSurvivor) {
                GetBSTMCClientManager().ContinueSpawn(_pnlCharInfo.GetCharacterId(), _rootSurvivorSelect.GetSelectedSurvivorWidget().GetPlayer().GetType());
            } else {
                GetBSTMCClientManager().ContinueSpawn(_pnlCharInfo.GetCharacterId(), _rootCharacterSelect.GetSelectedCharacterWidget().GetCharacter().GetType());
            }
			GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Remove(this.ShowSpawnCountdown);
			GetGame().GetUIManager().ScreenFadeOut(0);
        } else {
            GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(this.ShowSpawnCountdown, 1000, false, isNewSurvivor);
			GetGame().GetUIManager().ScreenFadeIn(0, "You are spawning in " + _loginTimer + " second(s)", FadeColors.BLACK, FadeColors.WHITE);
            _loginTimer--;
        }
    }

    BST_MCGUICharPreviewWidget GetPlayerPreviewWidget() { return _pnlPlyPreview; }
    BST_MCGUICharInfoWidget GetCharacterInfoWidget() { return _pnlCharInfo; }
}