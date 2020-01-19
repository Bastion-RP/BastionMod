class BastionCCTVMenu : UIScriptedMenu {
    autoptr array<ref CCTVCamera> cameras;
    protected int currentCameraIndex = 0;
    Material chromAber;

    override Widget Init() {
        m_id = BastionCCTVEnum.CCTVMenu;
        chromAber = GetGame().GetWorld().GetMaterial("graphics/materials/postprocess/chromaber");

        cameras = new array<ref CCTVCamera>();
        // Should somehow get the locations from the server back to the clients probably
        cameras.Insert( new CCTVCamera("5025.65 20 2363.44", 0, 0, 0, true) );
        cameras.Insert( new CCTVCamera("6025.65 250 4363.44", 270, -20, 0, false) );
        cameras.Insert( new CCTVCamera("6018.26 300 10256.4", 270, -10, 0, true) );

        layoutRoot = GetGame().GetWorkspace().CreateWidgets("BastionCCTV\\gui\\layouts\\BastionCCTV.layout");
        return layoutRoot;
    }

    void DisableControls() {
        GetGame().GetMission().PlayerControlDisable( INPUT_EXCLUDE_INVENTORY );
        GetGame().GetUIManager().ShowCursor( true );
        GetGame().GetUIManager().ShowUICursor( true );
        GetGame().GetInput().ChangeGameFocus( 1 );
    }

    void EnableControls() {
        GetGame().GetPlayer().GetInputController().SetDisabled( false );
        GetGame().GetMission().PlayerControlEnable( true );
        GetGame().GetUIManager().ShowCursor( false );
        GetGame().GetUIManager().ShowUICursor( false );
        GetGame().GetInput().ResetGameFocus();
    }
    void RPCClose() {
        GetRPCManager().SendRPC( "BastionCCTV", "LeaveCCTV", new Param, true, NULL, GetPlayer() );
    }

    void switchCamera(int delta) {
        CCTVCamera oldCamera = cameras.Get( currentCameraIndex );
        int newIndex = currentCameraIndex + delta;
        if (newIndex < 0) {
            newIndex = cameras.Count() + newIndex;
        }
        currentCameraIndex = newIndex % cameras.Count();
        CCTVCamera camera = cameras.Get( currentCameraIndex );

        vector direction = vector.Zero;
        direction[0] = camera.GetStartingAngle();
        direction[1] = camera.GetPitch();
        direction[2] = camera.GetRoll();

		GetRPCManager().SendRPC( "BastionCCTV", "SwitchCCTV", new Param2<vector, vector>( camera.GetPosition(), direction ), true, NULL, GetPlayer() );

        if ( camera.GetCanRotate() ) {
            EnableControls();
        } else {
            DisableControls();
        }
    }

    void OnKeyPress(int key) {
        switch ( key ) {
            case KeyCode.KC_ESCAPE:
                RPCClose();
                GetGame().GetUIManager().HideScriptedMenu( this );
            break;
            case KeyCode.KC_LEFT:
                switchCamera(-1);
            break;
            case KeyCode.KC_RIGHT:
                switchCamera(1);
            break;
        }
    }

    override bool OnClick(Widget w, int x, int y, int button) {
        super.OnClick( w, x, y, button );

        if ( button == MouseState.LEFT ) {
            switch ( w.GetName() ) {
                case "btnClose":
                    RPCClose();
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

		HumanInputController input = GetGame().GetPlayer().GetInputController();

        input.OverrideMovementSpeed( true, 0 );
        input.OverrideRaise( true, false );
        input.OverrideAimChangeX( true, 0 );
        input.OverrideAimChangeY( true, 0 );

        chromAber.SetParam( "PowerX", 0.008 );
        chromAber.SetParam( "PowerY", 0.008 );
        // PPEffects.SetVignette( 0.06, -100, -100, -100 );

        switchCamera(0);
    }

    override void OnHide() {
        super.OnHide();

		HumanInputController input = GetGame().GetPlayer().GetInputController();
        
        chromAber = GetGame().GetWorld().GetMaterial("graphics/materials/postprocess/chromaber");
        chromAber.SetParam( "PowerX", 0.0 );
        chromAber.SetParam( "PowerY", 0.0 );
        PPEffects.ResetAll();
        
        input.OverrideMovementSpeed( false, 0 );
        input.OverrideRaise( false, false );
        input.OverrideAimChangeX( false, 0 );
        input.OverrideAimChangeY( false, 0 );
        EnableControls();
    }
}