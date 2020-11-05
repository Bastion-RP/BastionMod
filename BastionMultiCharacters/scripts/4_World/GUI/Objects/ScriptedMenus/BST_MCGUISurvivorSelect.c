class BST_MCGUISurvivorSelect : BST_MCGUIScriptedMenu {
    private const int CONST_X_SURVIVOR = 477;
    private const int CONST_Y_SURVIVOR = 120;
    private const int CONST_X_INFO = 904;
    private const int CONST_Y_INFO = 522;
    private const int CONST_MAX_CHILDREN = 4;

    private ref GridSpacerWidget _gridRoot;
    private ref ButtonWidget _btnBack;
    private ref BST_MCGUIWarningWidget _pnlConfirmation;
    private ref BST_MCSavePlayerBasic _character;
    private ref array<ref BST_MCGUIGridSurvivorWidget> _arrCharGrids;
    private ref map<Widget, BST_MCGUIPlyPreviewSmallWidget> _mapPreviewWidgets;
    private BST_MCGUIGridSurvivorWidget _activeGrid;
    private BST_MCGUIPlyPreviewSmallWidget _activeChar;

    void BST_MCGUISurvivorSelect(BST_MCGUIMainMenu rootMenu, Widget parent) {
        _arrCharGrids = new array<ref BST_MCGUIGridSurvivorWidget>();
        _mapPreviewWidgets = new map<Widget, BST_MCGUIPlyPreviewSmallWidget>();
    }
    
    void Init() {
        _root = GetGame().GetWorkspace().CreateWidgets("BastionMod/BastionMultiCharacters/gui/layout/CharacterCreateWidget.layout", _parent);
        _gridRoot = GridSpacerWidget.Cast(_root.FindAnyWidget("gridSurvivors"));
        _btnBack = ButtonWidget.Cast(_root.FindAnyWidget("btnBack"));
        _pnlConfirmation = new BST_MCGUIWarningWidget(_root);

        _root.SetHandler(this);
        _pnlConfirmation.Init(this);
        BuildCharPreviews();
    }

    void SetCharacter(BST_MCSavePlayerBasic character) {
        _character = character;

        _rootMenu.GetCharacterInfoWidget().SetCharacter(character);
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

    override void Show(bool show) {
        super.Show(show);

        if (show) {
            _rootMenu.GetPlayerPreviewWidget().GetRoot().SetHandler(this);
            _rootMenu.GetCharacterInfoWidget().GetRoot().SetHandler(this);
            _rootMenu.GetPlayerPreviewWidget().GetRoot().SetPos(CONST_X_SURVIVOR, CONST_Y_SURVIVOR);
            _rootMenu.GetCharacterInfoWidget().GetRoot().SetPos(CONST_X_SURVIVOR, CONST_Y_INFO);
            _rootMenu.GetPlayerPreviewWidget().Show(false);
            _rootMenu.GetCharacterInfoWidget().ChangeButtons(3);
        }
        _rootMenu.GetCharacterInfoWidget().Show(show);
    }

	override bool OnClick(Widget w, int x, int y, int button) {
        switch (w) {
            case _rootMenu.GetCharacterInfoWidget().GetPlayButton():
                {
                    SetFocus(null);
                    _pnlConfirmation.Show(true);
                    break;
                }
            case _pnlConfirmation.GetConfirmButton():
                {
                    _rootMenu.StartSpawnCountdown(true);
                    break;
                }
            case _pnlConfirmation.GetCancelButton():
                {
                    _pnlConfirmation.Show(false);
                    break;
                }
            case _btnBack:
                {
                    _rootMenu.ShowCharacterSelector();
                }
        }
        return true;
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
                    _rootMenu.GetPlayerPreviewWidget().SetPlayer(_activeChar.GetPlayer(), null);
                    _rootMenu.GetPlayerPreviewWidget().Show(true);
                    _rootMenu.GetCharacterInfoWidget().SetPos(CONST_X_INFO, CONST_Y_INFO);
                    _rootMenu.GetCharacterInfoWidget().ChangeButtons(0);
                } else {
                    _activeChar.Select(false);
                    _rootMenu.GetPlayerPreviewWidget().Show(false);
                    _rootMenu.GetCharacterInfoWidget().SetPos(CONST_X_SURVIVOR, CONST_Y_INFO);
                    _rootMenu.GetCharacterInfoWidget().ChangeButtons(3);

                    _activeChar = null;
                }
            }
        }
        return true;
    }

    BST_MCGUIPlyPreviewSmallWidget GetSelectedSurvivorWidget() { return _activeChar; }

    void ~BST_MCGUISurvivorSelect() {
        if (_arrCharGrids) {
            foreach (BST_MCGUIGridSurvivorWidget widget : _arrCharGrids) {
                if (!widget) { continue; }
                delete widget;
            }
        }
        delete _arrCharGrids;
        delete _mapPreviewWidgets;

        if (_gridRoot) {
            _gridRoot.Unlink();
        }
    }
}