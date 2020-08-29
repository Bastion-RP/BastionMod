class BST_MCGUISurvivorSelector {
    private ref Widget _root, _parent, _charFrame;
    private ref GridSpacerWidget _gridRoot;
    private ref PlayerPreviewWidget _survivorPreview;
    private ref ButtonWidget _btnSpawn;
    private ref BST_MCGUIStatsPanelWidget _selectedPanel;
    private ref map<ref Widget, ref BST_MCGUIStatsPanelWidget> _mapStatPanels;

    void BST_MCGUISurvivorSelector(Widget parent) {
        _root = GetGame().GetWorkspace().CreateWidgets("BastionMod\\BastionMultiCharacters\\gui\\layouts\\CharacterSelectWidget.layout", parent);
        _charFrame = _root.FindAnyWidget("charFrame");
        _gridRoot = GridSpacerWidget.Cast(_root.FindAnyWidget("gridPnlSurvivor"));
        _survivorPreview = PlayerPreviewWidget.Cast(_root.FindAnyWidget("plyPreview"));
        _btnSpawn = ButtonWidget.Cast(_root.FindAnyWidget("btnSpawn"));
        _mapStatPanels = new map<ref Widget, ref BST_MCGUIStatsPanelWidget>();
        _parent = parent;

        _charFrame.Show(false);
        _root.Show(true);
        InitStatPanels();
    }

    void ~BST_MCGUISurvivorSelector() {
        if (_root) {
            _root.Unlink();
        }
        for (int i = 0; i < _mapStatPanels.Count(); i++) {
            BST_MCGUIStatsPanelWidget panel = _mapStatPanels.GetElement(i);

            if (panel) {
                delete panel;
            }
        }
    }

    void Init() {
        if (_selectedPanel) {
            _selectedPanel.Deselect();

            _selectedPanel = null;
        }
        _charFrame.Show(false);
    }

    void InitStatPanels() {
        array<ref BST_MCSavePlayerBasic> arrCharacters = GetBSTMCClientManager().GetLoadouts();

        foreach (BST_MCSavePlayerBasic savePlayer : arrCharacters) {
            if (!savePlayer) { continue; }
            BST_MCGUIStatsPanelWidget newStatPanel = new BST_MCGUIStatsPanelWidget(_gridRoot, savePlayer);

            _mapStatPanels.Insert(newStatPanel.GetWidget(), newStatPanel);
        }
    }

    void OnClick(Widget w) {
        if (w == _btnSpawn && _selectedPanel.CanChoose()) {
            Hide();
            GetDayZGame().ShowCountDown();
        }
    }

    bool OnMouseButtonUp(Widget w) {
        if (_mapStatPanels.Contains(w)) {
            BST_MCGUIStatsPanelWidget statPanel = _mapStatPanels.Get(w);

            if (statPanel == _selectedPanel) {
                _selectedPanel.Deselect();
                _charFrame.Show(false);

                _selectedPanel = null;

                return false;
            } else {
                _selectedPanel = statPanel;

                if (!statPanel.GetSavePlayer().IsDead()) {
                    _survivorPreview.SetPlayer(statPanel.GetPlayer());
                    _survivorPreview.Show(true);
                    _charFrame.Show(true);
                    _selectedPanel.Select();
                } else if (statPanel.CanChoose()) {
                    _charFrame.Show(false);
                    Hide();
                }
            }
            return true;
        }
        return false;
    }

    void OnMouseEnter(Widget w) {
        if (_mapStatPanels.Contains(w)) {
            BST_MCGUIStatsPanelWidget statPanel = _mapStatPanels.Get(w);

            statPanel.OnMouseEnter();
        }
    }

    void OnMouseLeave(Widget w) {
        if (_mapStatPanels.Contains(w)) {
            BST_MCGUIStatsPanelWidget statPanel = _mapStatPanels.Get(w);

            statPanel.OnMouseLeave();
        }
    }

    void Show() {
        _root.Show(true);
        Init();
    }

    void Hide() {
        _root.Show(false);
    }

    BST_MCGUIStatsPanelWidget GetSelectedPanel() { return _selectedPanel; }
    bool IsVisible() { return _root.IsVisible(); }
}