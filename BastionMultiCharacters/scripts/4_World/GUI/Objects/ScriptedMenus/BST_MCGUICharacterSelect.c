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
        _arrSmallInfoWidgets = new array<ref BST_MCGUICharInfoSmallWidget>();
        _mapSmallInfoWidgets = new map<Widget, BST_MCGUICharInfoSmallWidget>();

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

    override void Show(bool show) {
        super.Show(show);

        if (show) {
            _rootMenu.GetPlayerPreviewWidget().GetRoot().SetHandler(this);
            _rootMenu.GetCharacterInfoWidget().GetRoot().SetHandler(this);
            _rootMenu.GetPlayerPreviewWidget().GetRoot().SetPos(CONST_X_SURVIVOR, CONST_Y_SURVIVOR);
            _rootMenu.GetCharacterInfoWidget().GetRoot().SetPos(CONST_X_INFO, CONST_Y_INFO);
            _rootMenu.GetPlayerPreviewWidget().Show(false);
            _rootMenu.GetCharacterInfoWidget().Show(false);
        }
    }

	override bool OnClick(Widget w, int x, int y, int button) {
        if (w == _rootMenu.GetCharacterInfoWidget().GetPlayButton()) {
            _rootMenu.StartSpawnCountdown();
        }
        return true;
    }

    override bool OnMouseEnter(Widget w, int x, int y) {
        if (_mapSmallInfoWidgets.Contains(w)) {
            BST_MCGUICharInfoSmallWidget infoWidget = _mapSmallInfoWidgets.Get(w);

            if (infoWidget != _selectedInfoWidget) {
                infoWidget.Select(true);
            }
        }
        return true;
    }

    override bool OnMouseLeave(Widget w, Widget enterW, int x, int y) {
        if (_mapSmallInfoWidgets.Contains(w)) {
            BST_MCGUICharInfoSmallWidget infoWidget = _mapSmallInfoWidgets.Get(w);

            if (infoWidget != _selectedInfoWidget) {
                infoWidget.Select(false);
            }
        }
        return true;
    }

    override bool OnMouseButtonUp(Widget w, int x, int y, int button) {
        if (button == MouseState.LEFT) {
            if (_mapSmallInfoWidgets.Contains(w)) {
                BST_MCGUICharInfoSmallWidget infoWidget = _mapSmallInfoWidgets.Get(w);
                BST_MCSavePlayerBasic character = infoWidget.GetCharacter();

                if (_selectedInfoWidget != infoWidget) {
                    if (_selectedInfoWidget) {
                        _selectedInfoWidget.Select(false);
                    }
                    if (character.IsDead() && character.GetType() == "") {
                        GetBSTMCClientManager().GetSelectMenu().CreateandShowSurvivorSelector(infoWidget.GetCharacter());
                    } else {
                        _selectedInfoWidget = infoWidget;

                        infoWidget.GetPlayerPreview().Select(true);
                        _rootMenu.GetPlayerPreviewWidget().SetPlayer(_selectedInfoWidget.GetPlayerPreview().GetPlayer(), _selectedInfoWidget.GetPlayerPreview().GetItemInHands());
                        _rootMenu.GetCharacterInfoWidget().SetCharacter(_selectedInfoWidget.GetCharacter());
                        _rootMenu.GetPlayerPreviewWidget().Show(true);
                        _rootMenu.GetCharacterInfoWidget().Show(true);

                        if (_selectedInfoWidget.IsOnCooldown()) {
                            _rootMenu.GetCharacterInfoWidget().ChangeButtons(2);
                        } else {
                            _rootMenu.GetCharacterInfoWidget().ChangeButtons(1);
                        }
                    }
                } else {
                    _selectedInfoWidget.Select(false);
                    _rootMenu.GetPlayerPreviewWidget().Show(false);
                    _rootMenu.GetCharacterInfoWidget().Show(false);

                    _selectedInfoWidget = null;
                }
            }
        }
        return true;
    }

    BST_MCGUICharInfoSmallWidget GetSelectedCharacterWidget() { return _selectedInfoWidget; }

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