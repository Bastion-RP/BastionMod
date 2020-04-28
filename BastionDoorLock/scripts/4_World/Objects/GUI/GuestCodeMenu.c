class GuestCodeMenu extends UIScriptedMenu
{
	protected   Widget              w_Root;
	protected   TextWidget          txt_EditPin;
	protected   EditBoxWidget       box_EditPin;
	protected   ButtonWidget        btn_EnterPin;
	protected   ButtonWidget        btn_CancelPin;
    protected   ButtonWidget        btn_Remove;
    protected   ButtonWidget        btn_ChangePin;

    protected   vector              m_BuildingPos;
    protected   int                 m_DoorIndex;
    protected   string              m_PlainText;
	
	void GuestCodeMenu() {}
    
	void ~GuestCodeMenu() {}
	
	override Widget Init()
	{
        w_Root = GetGame().GetWorkspace().CreateWidgets("BastionDoorLock\\scripts\\layouts\\guestComboCode.layout");
        w_Root.Show( false );

        txt_EditPin     = TextWidget.Cast(w_Root.FindAnyWidget("txtEnterPin"));
        box_EditPin     = EditBoxWidget.Cast(w_Root.FindAnyWidget("edtPinCode"));
        btn_EnterPin    = ButtonWidget.Cast(w_Root.FindAnyWidget("btnEnterPin"));
        btn_CancelPin   = ButtonWidget.Cast(w_Root.FindAnyWidget("btnCancelPin"));

        return w_Root;
	}

    override bool OnClick( Widget w, int x, int y, int button )
    {
        super.OnClick( w, x, y, button );
        
        if ( button == MouseState.LEFT )
        {
            if ( w == btn_CancelPin )
                GetGame().GetUIManager().HideScriptedMenu( this );
            else if ( w == btn_EnterPin )
            {
                PlayerBase player = GetGame().GetPlayer();
                param_EnterCode data = new param_EnterCode( m_BuildingPos, m_DoorIndex, player.GetIdentity().GetId(), m_PlainText );
                GetGame().RPCSingleParam( player, BASTRPC.RPC_SERVER_ENTERPASSCODE, data, true, player.GetIdentity() );
            }
            
            return true;
        }

        return false;
    }
    
    override bool OnKeyPress( Widget w, int x, int y, int key )
    {
        // Limits input to 6 digits.
        if (w == box_EditPin) 
        {
            string boxText = box_EditPin.GetText();

            if (boxText.Length() >= 6) 
            {
                box_EditPin.SetText(boxText);
                return true;
            }
        }

        return false;
    }

    override bool OnChange( Widget w, int x, int y, bool finished )
    {
        super.OnChange( w, x, y, finished );
        if ( w == box_EditPin )
        {
            string boxText = box_EditPin.GetText();
            int boxLength = boxText.Length();
            int passPlainLength = m_PlainText.Length();

            if ( boxLength > passPlainLength )
                m_PlainText += boxText.Substring( passPlainLength, 1 );
            else 
                m_PlainText = m_PlainText.Substring( 0, boxLength );

            box_EditPin.SetText( BSTGlobalFunctions.ConvertToStars( boxText ) );

            return true;
        }

        return false;
    }

    override void OnShow() 
    {
        box_EditPin.SetText( "" );
        m_PlainText     = "";

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
}