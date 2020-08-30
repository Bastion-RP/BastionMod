class BST_MCGUISurvivorPreviewWidget {
    private ref Widget _root, _parent, _pnlBG;
    private ref PlayerPreviewWidget _survivorPreview;
    private DayZPlayer _survivor;
    private bool _isSelected;

    void BST_MCGUISurvivorPreviewWidget(Widget parent, string type) {
        vector cameraPos, characterPos;

        _root = GetGame().GetWorkspace().CreateWidgets("BastionMod\\BastionMultiCharacters\\gui\\layouts\\SurvivorPreviewWidget.layout", parent);
        _survivorPreview = PlayerPreviewWidget.Cast(_root.FindAnyWidget("survivorPreview"));
        _pnlBG = _root.FindAnyWidget("pnlBG");
        _survivor = DayZPlayer.Cast(GetGame().CreateObject(type, vector.Zero, true));
        _parent = parent;

        _survivorPreview.SetPlayer(_survivor);
        _pnlBG.Show(false);

        //cameraPos = GetBSTMCClientManager().GetSelectMenu().GetCameraPosition()
        //characterPos = ("" + cameraPos[0] + " " + (cameraPos[1] + 3) + " " + cameraPos[2]).ToVector();
        //dayzPlayer = GetGame().CreateObject(survivorType, characterPos, true);
        //Print(BST_MCConst.debugPrefix + " | inactive pos=" + characterPos);
        //dayzPlayer.SetPosition(characterPos);
    }

    void ~BST_MCGUISurvivorPreviewWidget() {
        if (_root) {
            _root.Unlink();
        }
        if (_survivor) {
            GetGame().ObjectDelete(_survivor);
            GetGame().ObjectRelease(_survivor);
        }
    }

    void Select() {
        _isSelected = true;

        _pnlBG.SetColor(BST_MCColors.COLOR_TRANS_RED);
        _pnlBG.Show(true);
    }

    void Deselect() {
        _isSelected = false;

        _pnlBG.Show(false);
    }

    void OnMouseEnter() {
        if (!_isSelected) {
            _pnlBG.SetColor(BST_MCColors.COLOR_TRANS_DARK_GRAY);
            _pnlBG.Show(true);
        }
    }

    void OnMouseLeave() {
        if (!_isSelected) {
            _pnlBG.Show(false);
        }
    }

    Widget GetWidget() { return _root; }
    PlayerPreviewWidget GetPreviewWidget() { return _survivorPreview; }
    DayZPlayer GetPlayer() { return _survivor; }
}