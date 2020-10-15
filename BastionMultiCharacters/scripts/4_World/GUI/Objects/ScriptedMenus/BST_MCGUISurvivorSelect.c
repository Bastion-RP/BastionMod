class BST_MCGUISurvivorSelect : BST_MCGUIScriptedMenu {
    private const int CONST_X_SURVIVOR = 477;
    private const int CONST_Y_SURVIVOR = 120;
    private const int CONST_X_INFO = 904;
    private const int CONST_Y_INFO = 522;
    private const int CONST_MAX_CHILDREN = 4;

    private ref GridSpacerWidget _gridRoot;
    private ref BST_MCSavePlayerBasic _character;
    private ref array<ref BST_MCGUIGridSurvivorWidget> _arrCharGrids;
    private ref map<Widget, BST_MCGUIPlyPreviewSmallWidget> _mapPreviewWidgets;
    private BST_MCGUIGridSurvivorWidget _activeGrid;
    private BST_MCGUIPlyPreviewSmallWidget _activeChar;

    void BST_MCGUISurvivorSelect(Widget parent) {
        _arrCharGrids = new array<ref BST_MCGUIGridSurvivorWidget>();
        _mapPreviewWidgets = new map<Widget, BST_MCGUIPlyPreviewSmallWidget>();
    }
    
    void Init() {
        _root = GetGame().GetWorkspace().CreateWidgets("BastionMod/BastionMultiCharacters/gui/layout/CharacterCreateWidget.layout", _parent);
        _gridRoot = GridSpacerWidget.Cast(_root.FindAnyWidget("gridSurvivors"));
        _pnlPlyPreview = new BST_MCGUICharPreviewWidget(_root);
        _pnlCharInfo = new BST_MCGUICharInfoWidget(_root);

        _pnlPlyPreview.Init(this, CONST_X_SURVIVOR, CONST_Y_SURVIVOR);
        _pnlCharInfo.Init(this, CONST_X_SURVIVOR, CONST_Y_INFO);
        _pnlCharInfo.ChangeButtons(3);
        _pnlPlyPreview.Show(false);
        _pnlCharInfo.Show(true);
        BuildCharPreviews();
    }

    void SetCharacter(BST_MCSavePlayerBasic character) {
        _character = character;

        _pnlCharInfo.SetCharacter(character);
    }

    void BuildCharPreviews() {
        array<string> arrCharTypes = GetGame().ListAvailableCharacters();

        foreach (string str : arrCharTypes) {
            if (str == "") { continue; }
            CheckCurrentGrid();

            BST_MCGUIPlyPreviewSmallWidget newPreview = _activeGrid.CreateChild(str);

            _mapPreviewWidgets.Insert(newPreview.GetRoot(), newPreview);
        }
    }

    private void CheckCurrentGrid() {
        if (!_activeGrid || _activeGrid.ChildCount() >= CONST_MAX_CHILDREN) {
            BST_MCGUIGridSurvivorWidget newGrid = new BST_MCGUIGridSurvivorWidget(_gridRoot);
            _activeGrid = newGrid;
            
            newGrid.Init(this);
            _arrCharGrids.Insert(newGrid);
        }
    }

	override bool OnMouseEnter(Widget w, int x, int y) {
        if (_mapPreviewWidgets.Contains(w)) {
            BST_MCGUIPlyPreviewSmallWidget previewWidget = _mapPreviewWidgets.Get(w);

            if (previewWidget != _activeChar) {
                previewWidget.Select(true);
            }
        }
        return true;
    }

	override bool OnMouseLeave(Widget w, Widget enterW, int x, int y) {
        if (_mapPreviewWidgets.Contains(w)) {
            BST_MCGUIPlyPreviewSmallWidget previewWidget = _mapPreviewWidgets.Get(w);

            if (previewWidget != _activeChar) {
                previewWidget.Select(false);
            }
        }
        return true;
    }
    
	override bool OnMouseButtonUp(Widget w, int x, int y, int button) {
        if (button == MouseState.LEFT) {
            if (_mapPreviewWidgets.Contains(w)) {
                BST_MCGUIPlyPreviewSmallWidget previewWidget = _mapPreviewWidgets.Get(w);

                if (_activeChar != previewWidget) {
                    if (_activeChar) {
                        _activeChar.Select(false);
                    }
                    _activeChar = previewWidget;

                    previewWidget.Select(true);
                    _pnlPlyPreview.SetPlayer(_activeChar.GetPlayer(), null);
                    _pnlPlyPreview.Show(true);
                    _pnlCharInfo.SetPos(CONST_X_INFO, CONST_Y_INFO);
                    _pnlCharInfo.ChangeButtons(0);
                } else {
                    _activeChar.Select(false);
                    _pnlPlyPreview.Show(false);
                    _pnlCharInfo.SetPos(CONST_X_SURVIVOR, CONST_Y_INFO);
                    _pnlCharInfo.ChangeButtons(3);

                    _activeChar = null;
                }
            }
        }
        return true;
    }
}