modded class InGameMenu extends UIScriptedMenu
{
	string m_ServerInfoText;
	
	protected Widget			m_ContinueButton;
	protected Widget			m_ExitButton;
	protected Widget			m_RestartButton;
	protected Widget			m_RestartDeadButton;
	protected Widget			m_OptionsButton;
	protected Widget 			m_ServerInfoPanel;
	protected Widget 			m_FavoriteButton;
	protected Widget 			m_FavoriteImage;
	protected Widget 			m_UnfavoriteImage;
	protected Widget 			m_CopyInfoButton;

	protected Widget    		m_Forums;
	
	protected ref TextWidget	m_ModdedWarning;
	protected ref TextWidget 	m_ServerIP;
	protected ref TextWidget 	m_ServerPort;
	protected ref TextWidget 	m_ServerName;
	
	protected ref UiHintPanel m_HintPanel;
	
	void ~InGameMenu()
	{
		HudShow( true );
	}

	override Widget Init()
	{
		layoutRoot = GetGame().GetWorkspace().CreateWidgets("BastionMod/BastionMenu/gui/layouts/day_z_ingamemenu.layout");
				
		m_ContinueButton	= layoutRoot.FindAnyWidget( "continuebtn" );
		m_ExitButton		= layoutRoot.FindAnyWidget( "exitbtn" );
		m_RestartButton		= layoutRoot.FindAnyWidget( "restartbtn" );
		m_RestartDeadButton	= layoutRoot.FindAnyWidget( "restartdeadbtn" );
		m_OptionsButton		= layoutRoot.FindAnyWidget( "optionsbtn" );
		m_Forums			= layoutRoot.FindAnyWidget( "forumsbtn");

		m_ModdedWarning		= TextWidget.Cast( layoutRoot.FindAnyWidget( "ModdedWarning" ) );
		m_HintPanel			= new UiHintPanel(layoutRoot.FindAnyWidget( "hint_frame" ));
		m_ServerInfoPanel 	= layoutRoot.FindAnyWidget( "server_info" );
		m_ServerIP 			= TextWidget.Cast( layoutRoot.FindAnyWidget( "server_ip" ) );
		m_ServerPort 		= TextWidget.Cast( layoutRoot.FindAnyWidget( "server_port" ) );
		m_ServerName 		= TextWidget.Cast( layoutRoot.FindAnyWidget( "server_name" ) );
		m_FavoriteImage 	= layoutRoot.FindAnyWidget( "favorite_image" );
		m_UnfavoriteImage 	= layoutRoot.FindAnyWidget( "unfavorite_image" );
		m_CopyInfoButton 	= layoutRoot.FindAnyWidget( "copy_button" );
		
		if (GetGame().IsMultiplayer())
		{
			ButtonSetText(m_RestartButton, "#main_menu_respawn");
		}
		else
		{
			ButtonSetText(m_RestartButton, "#main_menu_restart");
		}		

		HudShow( false );
		m_ModdedWarning.Show (false);
		
		return layoutRoot;
	}

	override bool OnClick(Widget w, int x, int y, int button)
	{
		super.OnClick(w, x, y, button);
		
		if ( w == m_ContinueButton )
		{
			OnClick_Continue();
			return true;
		}
		else if ( w == m_RestartButton || w == m_RestartDeadButton )
		{
			OnClick_Restart();
			return true;
		}
		else if ( w == m_OptionsButton )
		{
			OnClick_Options();
			return true;
		}
		else if ( w == m_ExitButton )
		{
			OnClick_Exit();
			return true;
		}
		else if ( w == m_CopyInfoButton )
		{
			GetGame().CopyToClipboard(m_ServerInfoText);
		}
		else if ( w == m_Forums )
		{
			GetGame().OpenURL("https://bastionrp.com/forums/");
			return true;
		}

		return false;
	}

	void OnShow()
	{
		super.OnShow();
		PPEffects.SetBlurInventory(0.3);
	}

	void OnHide()
	{
		super.OnHide();
		PPEffects.SetBlurInventory(0);
	}

	protected void ColorHighlight( Widget w )
	{
		if( !w )
			return;
		
		ButtonSetColor(w, ARGB(255, 0, 0, 0));
		ButtonSetTextColor(w, ARGB(255, 255, 168, 0));
	}
}
