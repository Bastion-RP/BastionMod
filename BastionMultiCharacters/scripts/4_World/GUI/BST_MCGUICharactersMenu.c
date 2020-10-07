class BST_MCGUICharactersMenu : UIScriptedMenu {
    private ref BST_MCGUISurvivorSelector _survivorSelector;
    private ref BST_MCGUISurvivorCreator _survivorCreator;
    protected ref Widget _root;
    protected ref ButtonWidget _btnDisconnect;
    protected Camera _camera;
    protected int _charId;

    void ~BST_MCGUICharactersMenu() {
        if (_survivorCreator) {
            delete _survivorCreator;
        }
        if (_survivorSelector) {
            delete _survivorSelector;
        }
        _root.Unlink();
    }

    override Widget Init() {
        InitScene();

        _root = GetGame().GetWorkspace().CreateWidgets("BastionMod\\BastionMultiCharacters\\gui\\layouts\\CharacterMenu.layout");
        _survivorSelector = new BST_MCGUISurvivorSelector(_root);
        _survivorCreator = new BST_MCGUISurvivorCreator(_root);
        _btnDisconnect = ButtonWidget.Cast(_root.FindAnyWidget("btnDisconnect"));

        return _root;
    }

    void InitScene() {
        _camera = Camera.Cast(GetGame().CreateObject("staticcamera", vector.Zero, true, false, false));
        _camera.SetActive(true);
        /* string rootPath, scenePath, childName;
        int count, index;
        float fov, pos_x, pos_z, pos_y;
        vector target, camDir, position;

        rootPath = "cfgCharacterScenes " + GetGame().GetWorldName();
        count = g_Game.ConfigGetChildrenCount(rootPath);
        index = Math.RandomInt(0, count - 1);

        GetGame().ConfigGetChildName(rootPath, index, childName);
        GetGame().ObjectDelete(_camera);

        scenePath = rootPath + " " + childName;
        position = SwapYZ(GetGame().ConfigGetVector(scenePath + " position"));
        target = SwapYZ(GetGame().ConfigGetVector(scenePath + " target"));
        _camera = Camera.Cast(GetGame().CreateObject("staticcamera", SnapToGround(position), true, false, false));

        _camera.SetActive(true);
        _camera.LookAt(target);
        Print("SETTING POSITIONS | camera pos=" + position); */
    }

    override bool OnClick(Widget w, int x, int y, int button) {
        if (w == _btnDisconnect) {
            GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Call(GetGame().DisconnectSessionForce);
        } else {
            if (_survivorCreator.IsVisible()) {
                _survivorCreator.OnClick(w);
            } else if (_survivorSelector.IsVisible()) {
                _survivorSelector.OnClick(w);
            }
        }
        return super.OnClick(w, x, y, button);
    }

    override bool OnMouseButtonUp(Widget w, int x, int y, int button) {
        if (_survivorCreator.IsVisible()) {
            _survivorCreator.OnMouseButtonUp(w);

            if (_survivorCreator.GetBackButton() == w) {
                _survivorSelector.Show();
            }
        } else if (_survivorSelector.IsVisible()) {
            if (_survivorSelector.OnMouseButtonUp(w)) {
                BST_MCGUIStatsPanelWidget statPanel = _survivorSelector.GetSelectedPanel();

                if (statPanel && statPanel.GetSavePlayer().IsDead() && statPanel.CanChoose()) {
                    _survivorCreator.Show();
                }
            }
        }
        return super.OnMouseButtonUp(w, x, y, button);
    }

    override bool OnMouseEnter(Widget w, int x, int y) {
        if (_survivorCreator.IsVisible()) {
            _survivorCreator.OnMouseEnter(w);
        } else if (_survivorSelector.IsVisible()) {
            _survivorSelector.OnMouseEnter(w);
        }
        return super.OnMouseEnter(w, x, y);
    }

    override bool OnMouseLeave(Widget w, Widget enterW, int x, int y) {
        if (_survivorCreator.IsVisible()) {
            _survivorCreator.OnMouseLeave(w);
        } else if (_survivorSelector.IsVisible()) {
            _survivorSelector.OnMouseLeave(w);
        }
        return super.OnMouseLeave(w, enterW, x, y);
    }

    /*     vector GetCameraPosition() {
            return _camera.GetPosition();
        }

        protected vector SwapYZ(vector vec) {
            vector tmp;
            tmp[0] = vec[0];
            tmp[1] = vec[2];
            tmp[2] = vec[1];

            return tmp;
        }

        protected vector SnapToGround(vector pos) {
            float pos_x = pos[0];
            float pos_z = pos[2];
            float pos_y = GetGame().SurfaceY(pos_x, pos_z);
            vector tmp_pos = Vector(pos_x, pos_y, pos_z);
            tmp_pos[1] = tmp_pos[1] + pos[1];

            return tmp_pos;
        } */

    override void OnShow() {
        super.OnShow();

        GetGame().GetMission().PlayerControlDisable(INPUT_EXCLUDE_ALL);
        GetGame().GetUIManager().ShowCursor(true);
        GetGame().GetMission().GetHud().Show(false);
        GetGame().GetUIManager().ScreenFadeOut(0);
    }

    override void OnHide() {
        super.OnHide();

        if (!GetGame()) {
            return;
        }
        GetGame().GetUIManager().ShowCursor(false);

        if (!GetGame().GetMission()) {
            return;
        }
        GetGame().GetMission().PlayerControlEnable(true);

        if (!GetGame().GetMission().GetHud()) {
            return;
        }
        GetGame().GetMission().GetHud().Show(true);
    }

    BST_MCGUISurvivorSelector GetSurvivorSelector() { return _survivorSelector; }
    BST_MCGUISurvivorCreator GetSurvivorCreator() { return _survivorCreator; }
}