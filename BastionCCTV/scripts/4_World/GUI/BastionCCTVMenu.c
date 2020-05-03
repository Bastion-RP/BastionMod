class BastionCCTVMenu : UIScriptedMenu {
    protected int currentCameraIndex = 0;
    protected bool controlsEnabled = true;
    Material chromAber;

    protected TextWidget m_title;
	protected TextListboxWidget m_cameraList;
	protected EditBoxWidget m_search;
    protected ref array<int> m_listboxIndexes = new array<int>;

    override Widget Init() {
        m_id = BastionCCTVEnum.CCTVMenu;

        chromAber = GetGame().GetWorld().GetMaterial("graphics/materials/postprocess/chromaber");
        layoutRoot = GetGame().GetWorkspace().CreateWidgets("BastionMod\\BastionCCTV\\gui\\layouts\\BastionCCTV.layout");

		m_title = TextWidget.Cast( layoutRoot.FindAnyWidget( "title" ) );
		m_cameraList = TextListboxWidget.Cast( layoutRoot.FindAnyWidget( "cameras" ) );
		m_search = EditBoxWidget.Cast( layoutRoot.FindAnyWidget( "search" ) );

        return layoutRoot;
    }

    void DisableControls() {
        controlsEnabled = false;
        GetGame().GetMission().PlayerControlDisable( INPUT_EXCLUDE_INVENTORY );
        GetGame().GetUIManager().ShowCursor( true );
        GetGame().GetUIManager().ShowUICursor( true );
        GetGame().GetInput().ChangeGameFocus( 1 );
        GetGame().GetMission().GetHud().Show(false);
    }

    void EnableControls() {
        controlsEnabled = true;
        GetGame().GetPlayer().GetInputController().SetDisabled( false );
        GetGame().GetMission().PlayerControlEnable( true );
        GetGame().GetUIManager().ShowCursor( false );
        GetGame().GetUIManager().ShowUICursor( false );
        GetGame().GetInput().ResetGameFocus();
        GetGame().GetMission().GetHud().Show(true);
    }

    void RPCClose() {
        GetRPCManager().SendRPC( "BastionCCTV", "LeaveCCTV", new Param, true, NULL, GetGame().GetPlayer() );
    }

    void switchToCurrentIndex() {
        CCTVCamera camera = BastionCCTV.m_cameras.Get( currentCameraIndex );

		GetRPCManager().SendRPC( "BastionCCTV", "SwitchCCTV", new Param2<vector, vector>( camera.GetPosition(), camera.GetDirection() ), true, NULL, GetGame().GetPlayer() );

        if ( camera.GetCanRotate() ) {
            EnableControls();
        } else {
            DisableControls();
        }

        m_title.SetText( camera.GetName() );
    }

    void switchCamera(int delta) {
        int cameraCount = BastionCCTV.m_cameras.Count();
        if (cameraCount == 0) {
            RPCClose();
            GetGame().GetUIManager().HideScriptedMenu( this );
        }

        int newIndex = currentCameraIndex + delta;
        if (newIndex < 0) {
            newIndex = cameraCount + newIndex;
        }
        currentCameraIndex = newIndex % cameraCount;
        switchToCurrentIndex();
    }

    void quickSwitch() {
        if ( m_listboxIndexes.Count() > 0 ) {
            currentCameraIndex = m_listboxIndexes.Get( m_cameraList.GetSelectedRow() );
            switchToCurrentIndex();

            m_search.SetText("");
            UpdateFilter("");
        }
    }

    void UpdateFilter( string filter ) {
        m_cameraList.ClearItems();
        m_listboxIndexes.Clear();
		filter.ToLower();

		for ( int i = 0; i < BastionCCTV.m_cameras.Count(); i++ ) {
            auto camera = BastionCCTV.m_cameras.Get(i);
            string name = camera.GetName();
            name.ToLower();

            if ( !name.Contains( filter ) ) {
                continue;
            }

            m_listboxIndexes.Insert(i);
            m_cameraList.AddItem( camera.GetName(), NULL, 0 );
		}

        if (m_listboxIndexes.Count() > 0) {
            m_cameraList.SelectRow(0);
        }
    }

    void OnKeyPress(int key) {
        switch ( key ) {
            case KeyCode.KC_ESCAPE:
                if ( controlsEnabled ) {
                    DisableControls();
                } else {
                    RPCClose();
                    GetGame().GetUIManager().HideScriptedMenu( this );
                }
            break;
            case KeyCode.KC_LEFT:
                switchCamera(-1);
            break;
            case KeyCode.KC_RIGHT:
                switchCamera(1);
            break;
            case KeyCode.KC_TAB:
                quickSwitch();
            break;
        }
    }

	override bool OnChange( Widget w, int x, int y, bool finished )
    {
        if ( w == m_search )
        {
            UpdateFilter( m_search.GetText() );
            return true;
        }
        return false;
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
                case "btnSwitch":
                    quickSwitch();
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

        switchCamera(0);
        UpdateFilter("");
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