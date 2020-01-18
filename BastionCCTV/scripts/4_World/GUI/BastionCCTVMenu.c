class BastionCCTVMenu : UIScriptedMenu {
    autoptr array<ref CCTVCamera> cameras;
    protected int currentCameraIndex = 0;

    override Widget Init() {
        m_id = BastionCCTVEnum.CCTVMenu;

        cameras = new array<ref CCTVCamera>();
        // Should somehow get the locations from the server back to the clients probably
        cameras.Insert( new CCTVCamera("5025.65 20 2363.44", 0, true) );
        cameras.Insert( new CCTVCamera("6025.65 50 4363.44", 90, false) );
        cameras.Insert( new CCTVCamera("6018.26 50 10256.4", 0, true) );

        layoutRoot = GetGame().GetWorkspace().CreateWidgets("BastionCCTV\\gui\\layouts\\BastionCCTV.layout");
        return layoutRoot;
    }
    
    void switchCamera(int delta) {
        CCTVCamera oldCamera = cameras.Get( currentCameraIndex );
        int newIndex = currentCameraIndex + delta;
        if (newIndex < 0) {
            newIndex = cameras.Count() + newIndex;
        }
        currentCameraIndex = newIndex % cameras.Count();
        CCTVCamera camera = cameras.Get( currentCameraIndex );

        if ( !oldCamera.GetCanRotate() && camera.GetCanRotate() ) {
            GetGame().GetMission().PlayerControlEnable( true );
            GetGame().GetUIManager().ShowCursor( false );
            GetGame().GetUIManager().ShowUICursor( false );
            GetGame().GetInput().ResetGameFocus();
            GetGame().GetMission().GetHud().Show( true );
        }

		GetRPCManager().SendRPC( "BastionCCTV", "SwitchCCTV", new Param2<vector, int>( camera.GetPosition(), camera.GetStartingAngle() ), true, NULL, GetPlayer() );

        if ( !camera.GetCanRotate() ) {
            GetGame().GetMission().PlayerControlDisable( INPUT_EXCLUDE_INVENTORY );
            GetGame().GetUIManager().ShowCursor( true );
            GetGame().GetUIManager().ShowUICursor( true );
            GetGame().GetInput().ChangeGameFocus( 1 );
            GetGame().GetMission().GetHud().Show( false );
        }
    }

    override bool OnKeyPress(Widget w, int x, int y, int key) {
        auto prev = super.OnKeyPress( w, x, y, key );
        if (key == KeyCode.KC_ESCAPE) {
            GetGame().GetUIManager().HideScriptedMenu( this );
            return true;
        } else if (key == KeyCode.KC_LEFT) {
            switchCamera(-1);
            return true;
        } else if (key == KeyCode.KC_RIGHT) {
            switchCamera(1);
            return true;
        }
        return prev;
    }

    override bool OnClick(Widget w, int x, int y, int button) {
        super.OnClick( w, x, y, button );

        if ( button == MouseState.LEFT ) {
            switch ( w.GetName() ) {
                case "btnClose":
                    GetGame().GetUIManager().HideScriptedMenu( this );
                break;
                case "btnPrevious":
                    switchCamera(-1);
                break;
                case "btnNext":
                    switchCamera(1);
                break;
            }
        }

        return false;
    }

    override void OnShow() {
        super.OnShow();
        CCTVCamera camera = cameras.Get( currentCameraIndex );
        GetRPCManager().SendRPC( "BastionCCTV", "EnterCCTV", new Param2<vector, int>( camera.GetPosition(), camera.GetStartingAngle() ), true, NULL, GetPlayer() );

        if (!camera.GetCanRotate()) {
            GetGame().GetMission().PlayerControlDisable( INPUT_EXCLUDE_INVENTORY );
            GetGame().GetUIManager().ShowCursor( true );
            GetGame().GetUIManager().ShowUICursor( true );
            GetGame().GetInput().ChangeGameFocus( 1 );
            GetGame().GetMission().GetHud().Show( false );
        }
    }

    override void OnHide() {
        super.OnHide();
        GetRPCManager().SendRPC( "BastionCCTV", "LeaveCCTV", new Param, true, NULL, GetPlayer() );

        GetGame().GetMission().PlayerControlEnable( true );
        GetGame().GetUIManager().ShowCursor( false );
        GetGame().GetUIManager().ShowUICursor( false );
        GetGame().GetInput().ResetGameFocus();
        GetGame().GetMission().GetHud().Show( true );
    }
}