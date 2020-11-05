modded class LoginQueueBase extends UIScriptedMenu
{
	protected TextWidget m_txtPosition;
	protected TextWidget m_txtNote;
	protected ButtonWidget m_btnLeave;
	
	protected int m_iPosition; // position in login queue
	protected bool m_IsStatic;

	protected TextWidget m_RandomMessages;
	protected ImageWidget imageWidgetBackground;
	
	void LoginQueueBase()
	{
		m_iPosition = -1;
		m_IsStatic = false;
		g_Game.SetKeyboardHandle(this);	
	}

	void ~LoginQueueBase()
	{
		g_Game.SetKeyboardHandle(NULL);	
	}

	ref TStringArray loadingscreens = 
	{	
		"BastionMod/BastionMenu/gui/data/loading_1.edds",
		"BastionMod/BastionMenu/gui/data/loading_1.edds"			
	};	
	
	override Widget Init()
	{	
		layoutRoot = GetGame().GetWorkspace().CreateWidgets("BastionMod/BastionMenu/gui/layouts/dialog_queue_position.layout");
		
		m_txtPosition = TextWidget.Cast( layoutRoot.FindAnyWidget("txtPosition") );
		m_txtNote = TextWidget.Cast( layoutRoot.FindAnyWidget("txtNote") );
		m_btnLeave = ButtonWidget.Cast( layoutRoot.FindAnyWidget("btnLeave") );

		m_RandomMessages = TextWidget.Cast( layoutRoot.FindAnyWidget("RandomMessages") );

        string lscreen = loadingscreens.GetRandomElement();
        ImageWidget background = ImageWidget.Cast( layoutRoot.FindAnyWidget("Background"));
        background.LoadImageFile(0, lscreen);  	
		#ifdef PLATFORM_CONSOLE
		m_btnLeave.Show(false);
		layoutRoot.FindAnyWidget("toolbar_bg").Show(true);
		#ifdef PLATFORM_PS4
			string back = "circle";
			if( GetGame().GetInput().GetEnterButton() == GamepadButton.A )
			{
				back = "circle";
			}
			else
			{
				back = "cross";
			}
			ImageWidget toolbar_b = layoutRoot.FindAnyWidget( "BackIcon" );
			toolbar_b.LoadImageFile( 0, "set:playstation_buttons image:" + back );
		#endif
		#endif
		return layoutRoot;
	}
	
	override void Update(float timeslice)
	{
		if ( GetGame().GetInput().LocalPress("UAUIBack", false) )
		{
			Leave();
		}
	}
	
	override bool OnClick(Widget w, int x, int y, int button)
	{
		super.OnClick(w, x, y, button);
		if ( w == m_btnLeave )
		{
			Leave();
			return true;
		}
		return false;
	}
	
	void Show()
	{
		if (layoutRoot)
			layoutRoot.Show(true);
	}
	
	void Hide()
	{
		if (layoutRoot)
			layoutRoot.Show(false);
	}
	
	void SetPosition(int position)
	{
		if ( position != m_iPosition )
		{
			m_iPosition = position;
			m_txtPosition.SetText(position.ToString());
		}
	}
	
	bool IsStatic()
	{
		return m_IsStatic;
	}
	
	void Leave()
	{
		g_Game.SetGameState( DayZGameState.MAIN_MENU );
		g_Game.SetLoadState( DayZLoadState.MAIN_MENU_START );
		g_Game.GetCallQueue(CALL_CATEGORY_SYSTEM).Call(GetGame().DisconnectSessionForce);
		
		Close();
	}
};

modded class LoginQueueStatic extends LoginQueueBase
{
	void LoginQueueStatic()
	{
		Init();
		//! hide leave button and show note text
		#ifndef PLATFORM_CONSOLE
		m_btnLeave.Show(false);
		m_txtNote.Show(true);
		#endif
		
		m_IsStatic = true;
	}
	
	void ~LoginQueueStatic()
	{
	}
};