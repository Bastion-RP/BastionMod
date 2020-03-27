class MultiCharactersMenu : UIScriptedMenu {
    private ref MultiCharactersSurvivorSelector wSurvivorSelector;
    private ref MultiCharactersSurvivorCreator wSurvivorCreator;

    protected ref Widget wRoot;
    protected ref Widget wSurvivorSelectRoot;
    protected Camera playerCamera;
    protected int characterId;

    void ~MultiCharactersMenu() {
        Print("!!!!!!!!!!---DELETING MULTICHARACTERS MENU---!!!!!!!!!!!!!");
        if (wSurvivorCreator) {
            delete wSurvivorCreator;
        }
        if (wSurvivorSelector) {
            delete wSurvivorSelector;
        }
    }

    override Widget Init() {
        Print("CREATING SELECT MENU");
        InitScene();
        
        wRoot = GetGame().GetWorkspace().CreateWidgets("MultiCharacters\\gui\\layouts\\CharacterMenu.layout");
        wSurvivorCreator = new MultiCharactersSurvivorCreator(wRoot);
        wSurvivorSelector = new MultiCharactersSurvivorSelector(wRoot);

        return wRoot;
    }

    void InitScene() {
        playerCamera = Camera.Cast(GetGame().CreateObject("staticcamera", vector.Zero, true, false, false));
        playerCamera.SetActive(true);
        /* string rootPath, scenePath, childName;
        int count, index;
        float fov, pos_x, pos_z, pos_y;
        vector target, camDir, position;

        rootPath = "cfgCharacterScenes " + GetGame().GetWorldName();
        count = g_Game.ConfigGetChildrenCount(rootPath);
        index = Math.RandomInt(0, count - 1);

        GetGame().ConfigGetChildName(rootPath, index, childName);
        GetGame().ObjectDelete(playerCamera);

        scenePath = rootPath + " " + childName;
        position = SwapYZ(GetGame().ConfigGetVector(scenePath + " position"));
        target = SwapYZ(GetGame().ConfigGetVector(scenePath + " target"));
        playerCamera = Camera.Cast(GetGame().CreateObject("staticcamera", SnapToGround(position), true, false, false));

        playerCamera.SetActive(true);
        playerCamera.LookAt(target);
        Print("SETTING POSITIONS | camera pos=" + position); */
    }

    override bool OnClick(Widget w, int x, int y, int button) {
        if (wSurvivorCreator.IsVisible()) {
            wSurvivorCreator.OnClick(w);
        } else if (wSurvivorSelector.IsVisible()) {
            wSurvivorSelector.OnClick(w);
        }
        return true;
    }

    override bool OnMouseButtonUp(Widget w, int x, int y, int button) {
        if (wSurvivorCreator.IsVisible()) {
            wSurvivorCreator.OnMouseButtonUp(w);

            if (wSurvivorCreator.GetBackButton() == w) {
                wSurvivorSelector.Show();
            }
        } else if (wSurvivorSelector.IsVisible()) {
            MultiCharactersPlayerStatPanel statPanel = wSurvivorSelector.GetStatPanel(w);

            wSurvivorSelector.OnMouseButtonUp(w);

            if (statPanel && statPanel.GetSavePlayer().IsDead()) {
                wSurvivorCreator.Show();
            }
        }
        return true;
    }

    override bool OnMouseEnter(Widget w, int x, int y) {
        if (wSurvivorCreator.IsVisible()) {
            wSurvivorCreator.OnMouseEnter(w);
        } else if (wSurvivorSelector.IsVisible()) {
            wSurvivorSelector.OnMouseEnter(w);
        }
        return true;
    }

    override bool OnMouseLeave(Widget w, Widget enterW, int x, int y) {
        if (wSurvivorCreator.IsVisible()) {
            wSurvivorCreator.OnMouseLeave(w);
        } else if (wSurvivorSelector.IsVisible()) {
            wSurvivorSelector.OnMouseLeave(w);
        }
        return true;
    }

/*     vector GetCameraPosition() {
        return playerCamera.GetPosition();
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


        GetGame().GetUIManager().ShowCursor(false);
        GetGame().GetMission().PlayerControlEnable(true);
        GetGame().GetMission().GetHud().Show(true);
    }
}