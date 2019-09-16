class SetCodeMenu extends UIScriptedMenu
{
	protected   Widget              w_Root;
    protected   TextWidget          txt_SetPin;
	protected   EditBoxWidget       box_EditPin;
	protected   ButtonWidget        btn_EnterPin;
	protected   ButtonWidget        btn_CancelPin;

    protected   vector              m_BuildingPos;
    protected   int                 m_DoorIndex;
    protected   string              m_PlainText;
    protected   string              m_SetPin;
    protected   bool                m_ChangeCode;
	
	void SetCodeMenu() {}
    
	void ~SetCodeMenu() {}
	
	override Widget Init()
	{
        w_Root = GetGame().GetWorkspace().CreateWidgets("BastionDoorLock\\scripts\\layouts\\setComboCode.layout");
        w_Root.Show( false );

        txt_SetPin = TextWidget.Cast(w_Root.FindAnyWidget( "txtSetPin" ) );
        box_EditPin = EditBoxWidget.Cast(w_Root.FindAnyWidget( "edtPinCode" ) );
        btn_EnterPin = ButtonWidget.Cast(w_Root.FindAnyWidget( "btnEnterPin" ) );
        btn_CancelPin = ButtonWidget.Cast(w_Root.FindAnyWidget( "btnCancelPin" ) );

        return w_Root;
	}

    override bool OnClick( Widget w, int x, int y, int button ) 
    {
        super.OnClick( w, x, y, button );
        
        if ( button == MouseState.LEFT && w == btn_CancelPin )
        {
            GetGame().GetUIManager().HideScriptedMenu( this );
            return true;
        }

        if ( button == MouseState.LEFT && w == btn_EnterPin )
        {
            CheckState();
            return true;
        }

        return false;
    }

    override bool OnKeyPress( Widget w, int x, int y, int key )
    {
        if ( w == box_EditPin ) 
        {
            string boxText = box_EditPin.GetText();

            if ( boxText.Length() >= 6 ) 
            {
                box_EditPin.SetText( boxText );
                return true;
            }
        }

        return false;
    }

    override bool OnChange(Widget w, int x, int y, bool finished)
    {
        super.OnChange( w, x, y, finished );
        if ( w == box_EditPin )
        {
            string boxText              = box_EditPin.GetText();
            int boxLength               = boxText.Length();
            int plainTextLength         = m_PlainText.Length();

            if ( boxLength > plainTextLength )
                m_PlainText += boxText.Substring( plainTextLength, 1 );
            else 
                m_PlainText = m_PlainText.Substring( 0, boxLength );

            box_EditPin.SetText( OVTGlobalFunctions.ConvertToStars( boxText ) );

            return true;
        }

        return false;
    }

    void CheckState()
    {
        string boxText = box_EditPin.GetText();

        if ( boxText.Length() < 3 )
        {
            TooShort();
            return;
        }

        if ( m_SetPin == "" )
        {
            m_SetPin = m_PlainText;
            m_PlainText = "";
            confirmCode();
            return;
        }

        if ( m_PlainText == m_SetPin )
        {
            PlayerBase player = GetGame().GetPlayer();

            param_SetCode data = new param_SetCode( m_BuildingPos, m_DoorIndex, player.GetIdentity().GetId(), m_PlainText, m_ChangeCode );
            GetGame().RPCSingleParam( player, BASTRPC.RPC_SERVER_SETPASSCODE, data, true, player.GetIdentity() );

            GetGame().GetUIManager().HideScriptedMenu( this );
        }
        else if ( m_PlainText != m_SetPin )
        {
            noMatch();
        }
    }

    void TooShort()
    {
        txt_SetPin.SetText( "TOO SHORT" );
    }

    void confirmCode()
    {
        txt_SetPin.SetText( "CONFIRM PASSCODE" );
        box_EditPin.SetText( "" );
    }

    void noMatch()
    {
        txt_SetPin.SetText( "DOES NOT MATCH" );
    }

    override void OnShow() 
    {
        box_EditPin.SetText( "" );
        m_PlainText     = "";
        m_SetPin        = "";

		PPEffects.SetBlurInventory(0.5);
        SetFocus( box_EditPin );
        GetGame().GetMission().PlayerControlDisable( INPUT_EXCLUDE_ALL );
        GetGame().GetUIManager().ShowUICursor( true );
        GetGame().GetMission().GetHud().Show( false );
    }

    override void OnHide() 
    {
		PPEffects.SetBlurInventory(0);
        GetGame().GetMission().PlayerControlEnable();
        GetGame().GetInput().ResetGameFocus();
        GetGame().GetUIManager().ShowUICursor( false );
        GetGame().GetMission().GetHud().Show( true );
    }

    // Sets local variables
    void SetDoorIndex( int doorIndex )
    {
        m_DoorIndex = doorIndex;
    }

    void SetBuildingPos( vector buildingPos )
    {
        m_BuildingPos = buildingPos;
    }

    void SetChangeCode( bool changeCode = false )
    {
        m_ChangeCode = changeCode;
    }
}