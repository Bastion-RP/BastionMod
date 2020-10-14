class BST_MCGUISurvivorSelect : BST_MCGUIScriptedMenu {
    private const int CONST_X_SURVIVOR = 477;
    private const int CONST_Y_SURVIVOR = 120;
    private const int CONST_X_INFO = 904;
    private const int CONST_Y_INFO = 522;

    protected ref BST_MCSavePlayerBasic _character;
    
    void Init(BST_MCSavePlayerBasic character) {
        _root = GetGame().GetWorkspace().CreateWidgets("BastionMod/BastionMultiCharacters/gui/layout/CharacterCreateWidget.layout", _parent);
        _pnlPlyPreview = new BST_MCGUICharPreviewWidget(_root);
        _pnlCharInfo = new BST_MCGUICharInfoWidget(_root);
        _character = character;

        _pnlPlyPreview.Init(this, CONST_X_SURVIVOR, CONST_Y_SURVIVOR);
        _pnlCharInfo.Init(this, CONST_X_INFO, CONST_Y_INFO);
        _pnlCharInfo.SetCharacter(character);
        _pnlCharInfo.ChangeButtons(0);
        _pnlPlyPreview.Show(false);
        _pnlCharInfo.Show(false);
    }
}