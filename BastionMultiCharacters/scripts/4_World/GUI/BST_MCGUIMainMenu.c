class BST_MCGUIMainMenu : UIScriptedMenu {
    private ref BST_MCGUIScriptedMenu _rootCharacterSelect;
    private ref BST_MCGUIScriptedMenu _rootSurvivorSelect;
    private ref ButtonWidget _btnDisconnect;
    protected Camera _camera;

    override Widget Init() {
        layoutRoot = GetGame().GetWorkspace().CreateWidgets("BastionMod/BastionMultiCharacters/gui/layout/MainMenu.layout");
        _btnDisconnect = ButtonWidget.Cast(layoutRoot.FindAnyWidget("btnDisconnect"));
        _rootCharacterSelect = new BST_MCGUICharacterSelect(layoutRoot);
        _rootSurvivorSelect = new BST_MCGUISurvivorSelect(layoutRoot);
        _camera = Camera.Cast(GetGame().CreateObjectEx("staticcamera", vector.Zero, ECE_LOCAL));

        _camera.SetActive(true);
        _rootCharacterSelect.Init();
        _rootSurvivorSelect.Init();
        _rootSurvivorSelect.Show(false);

        return layoutRoot;
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
}