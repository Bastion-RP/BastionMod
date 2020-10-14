class BST_MCGUICharacterSelect : BST_MCGUIScriptedMenu {
    private const int CONST_X_SURVIVOR = 461;
    private const int CONST_Y_SURVIVOR = 120;
    private const int CONST_X_INFO = 892;
    private const int CONST_Y_INFO = 156;

    private ref GridSpacerWidget _gridCharacters;
    private BST_MCGUICharInfoSmallWidget _selectedInfoWidget;
    private ref array<ref BST_MCGUICharInfoSmallWidget> _arrSmallInfoWidgets;
    private ref map<Widget, BST_MCGUICharInfoSmallWidget> _mapSmallInfoWidgets;

    void Init() {
        _root = GetGame().GetWorkspace().CreateWidgets("BastionMod/BastionMultiCharacters/gui/layout/CharacterMenu.layout", _parent);
        _gridCharacters = GridSpacerWidget.Cast(_root.FindAnyWidget("gridCharacters"));
        _pnlPlyPreview = new BST_MCGUICharPreviewWidget(_root);
        _pnlCharInfo = new BST_MCGUICharInfoWidget(_root);
        _arrSmallInfoWidgets = new array<ref BST_MCGUICharInfoSmallWidget>();
        _mapSmallInfoWidgets = new map<Widget, BST_MCGUICharInfoSmallWidget>();

        _pnlPlyPreview.Init(this, CONST_X_SURVIVOR, CONST_Y_SURVIVOR);
        _pnlCharInfo.Init(this, CONST_X_INFO, CONST_Y_INFO);
        _pnlPlyPreview.Show(false);
        _pnlCharInfo.Show(false);
        _root.SetHandler(this);
        BuildWidgets();
    }

    void BuildWidgets() {
        array<ref BST_MCSavePlayerBasic> arrCharacters = GetBSTMCClientManager().GetCharacters();

        foreach (BST_MCSavePlayerBasic character : arrCharacters) {
            if (!character) { continue; }

            for (int i = 0; i < 6; i++) {
                BST_MCGUICharInfoSmallWidget newWidget = new BST_MCGUICharInfoSmallWidget(_gridCharacters);

                newWidget.Init(this, character);
                _arrSmallInfoWidgets.Insert(newWidget);
                _mapSmallInfoWidgets.Insert(newWidget.GetRoot(), newWidget);
            }
        }
    }
    
	override bool OnMouseButtonUp(Widget w, int x, int y, int button) {
        if (button == MouseState.LEFT) {
            if (_mapSmallInfoWidgets.Contains(w)) {
                BST_MCGUICharInfoSmallWidget infoWidget = _mapSmallInfoWidgets.Get(w);
                BST_MCSavePlayerBasic character = infoWidget.GetCharacter();

                Print("REEEE " + infoWidget.GetRoot().GetName());

                if (_selectedInfoWidget != infoWidget) {
                    if (_selectedInfoWidget) {
                        _selectedInfoWidget.Select(false);
                    }
                    Print("REEEE NOT SELECTED" + infoWidget.GetRoot().GetName());
                    if (character.IsDead() && character.GetType() == "") {
                        GetBSTMCClientManager().GetSelectMenu().CreateandShowSurvivorSelector(infoWidget.GetCharacter());
                    } else {
                        _selectedInfoWidget = infoWidget;

                        infoWidget.GetPlayerPreview().Select(true);
                        _pnlPlyPreview.SetPlayer(_selectedInfoWidget.GetPlayerPreview().GetPlayer(), _selectedInfoWidget.GetPlayerPreview().GetItemInHands());
                        _pnlCharInfo.SetCharacter(_selectedInfoWidget.GetCharacter());
                        _pnlPlyPreview.Show(true);
                        _pnlCharInfo.Show(true);

                        if (_selectedInfoWidget.IsOnCooldown()) {
                            _pnlCharInfo.ChangeButtons(2);
                        } else {
                            _pnlCharInfo.ChangeButtons(1);
                        }
                    }
                } else {
                    Print("REEEE SELECTED" + infoWidget.GetRoot().GetName());
                    _selectedInfoWidget.Select(false);
                    _pnlPlyPreview.Show(false);
                    _pnlCharInfo.Show(false);

                    _selectedInfoWidget = null;
                }
            }
        }
        return true;
    }

    void ~BST_MCGUICharacterSelect() {
        if (_arrSmallInfoWidgets) {
            foreach (BST_MCGUICharInfoSmallWidget widget : _arrSmallInfoWidgets) {
                if (!widget) { continue; }
                delete widget;
            }
        }
        delete _arrSmallInfoWidgets;
        delete _mapSmallInfoWidgets;

        if (_gridCharacters) {
            _gridCharacters.Unlink();
        }
    }
}