class BST_MCGUISurvivorCreator {
    private ref Widget _root, _parent, _btnBack;
    private ref ButtonWidget _btnSpawn;
    private ref PlayerPreviewWidget _survivorPreview;
    private ref GridSpacerWidget _gridPreviewWidgets;
    private ref BST_MCGUISurvivorPreviewWidget _selectedWidget;
    private ref array<ref BST_MCGUISurvivorPreviewWidget> _arrPreviewWidgets;
    private ref map<ref Widget, ref BST_MCGUISurvivorPreviewWidget> _mapPreviewWidgets;
    private ref array<string> _arrSurvivorTypes;

    void BST_MCGUISurvivorCreator(Widget parent) {
        array<string> arrSurvivorTypes;

        _root = GetGame().GetWorkspace().CreateWidgets("BastionMod\\BastionMultiCharacters\\gui\\layouts\\CharacterCreateWidget.layout", parent);
        _btnBack = _root.FindAnyWidget("previousMenu");
        _survivorPreview = PlayerPreviewWidget.Cast(_root.FindAnyWidget("playerPreview"));
        _gridPreviewWidgets = GridSpacerWidget.Cast(_root.FindAnyWidget("spacer"));
        _btnSpawn = ButtonWidget.Cast(_root.FindAnyWidget("btnCreateSpawn"));
        _parent = parent;
        _mapPreviewWidgets = new map<ref Widget, ref BST_MCGUISurvivorPreviewWidget>();
        arrSurvivorTypes = GetGame().ListAvailableCharacters();

        Init();
        InitPreviewWidgets(arrSurvivorTypes);
        _survivorPreview.Show(false);
        _btnSpawn.Show(false);
        _root.Show(false);
    }

    void ~BST_MCGUISurvivorCreator() {
        if (_root) {
            _root.Unlink();
        }
        for (int i = 0; i < _mapPreviewWidgets.Count(); i++) {
            BST_MCGUISurvivorPreviewWidget previewWidget = _mapPreviewWidgets.GetElement(i);

            if (previewWidget) {
                delete previewWidget;
            }
        }
        delete _mapPreviewWidgets;
    }

    void Init() {
        if (_selectedWidget) {
            _selectedWidget.Deselect();

            _selectedWidget = null;
        }
        _btnBack.SetColor(BST_MCColors.COLOR_YELLOW);
        _survivorPreview.Show(false);
        _btnSpawn.Show(false);
    }

    void InitPreviewWidgets(array<string> arrSurvivorTypes) {
        foreach (string type : arrSurvivorTypes) {
            BST_MCGUISurvivorPreviewWidget newPreviewWidget = new BST_MCGUISurvivorPreviewWidget(_gridPreviewWidgets, type);

            _mapPreviewWidgets.Insert(newPreviewWidget.GetPreviewWidget(), newPreviewWidget);
        }
    }

    void OnClick(Widget w) {
        if (w == _btnSpawn) {
            Hide();
            GetDayZGame().ShowCountDown();
            return;
        }
    }

    void OnMouseButtonUp(Widget w) {
        if (w == _btnBack) {
            Hide();
        } else {
            if (_mapPreviewWidgets.Contains(w)) {
                BST_MCGUISurvivorPreviewWidget previewWidget = _mapPreviewWidgets.Get(w);

                _selectedWidget.Deselect();

                if (previewWidget == _selectedWidget) {
                    _selectedWidget = null;

                    _survivorPreview.Show(false);
                } else {
                    _selectedWidget = previewWidget;

                    _survivorPreview.SetPlayer(previewWidget.GetPlayer());
                    _survivorPreview.Show(true);
                    previewWidget.Select();
                }
            }
        }
        if (_selectedWidget) {
            _btnSpawn.Show(true);
        } else {
            _survivorPreview.Show(false);
            _btnSpawn.Show(false);
        }
    }

    void OnMouseEnter(Widget w) {
        if (w == _btnBack) {
            _btnBack.SetColor(BST_MCColors.COLOR_DARK_YELLOW);
        } else {
            if (_mapPreviewWidgets.Contains(w)) {
                BST_MCGUISurvivorPreviewWidget previewWidget = _mapPreviewWidgets.Get(w);

                previewWidget.OnMouseEnter();
            }
        }
    }

    void OnMouseLeave(Widget w) {
        if (w == _btnBack) {
            _btnBack.SetColor(BST_MCColors.COLOR_YELLOW);
        } else {
            if (_mapPreviewWidgets.Contains(w)) {
                BST_MCGUISurvivorPreviewWidget previewWidget = _mapPreviewWidgets.Get(w);

                previewWidget.OnMouseLeave();
            }
        }
    }

    void Show() {
        _root.Show(true);
        Init();
    }

    void Hide() {
        _root.Show(false);
    }

    Widget GetBackButton() { return _btnBack; }
    ButtonWidget GetSpawnButton() { return _btnSpawn; }
    BST_MCGUISurvivorPreviewWidget GetSelectedWidget() { return _selectedWidget; }
    bool IsVisible() { return _root.IsVisible(); }
}