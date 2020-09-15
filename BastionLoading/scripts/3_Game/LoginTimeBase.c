modded class LoginTimeBase extends UIScriptedMenu
{
	protected TextWidget m_txtDescription;
	protected TextWidget m_txtLabel;
	protected ButtonWidget m_btnLeave;
	protected bool m_IsStatic;
	protected bool m_IsRespawn;

	protected TextWidget m_RandomMessages;

	void LoginTimeBase()
	{
		g_Game.SetKeyboardHandle(this);
		m_IsStatic = false;	
		m_IsRespawn = false;
	}

	void ~LoginTimeBase()
	{
		g_Game.SetKeyboardHandle(NULL);	
	}

	ref TStringArray loadingscreens = 
	{	
		"BastionMod/BastionLoading/gui/data/loading_1.edds",
		"BastionMod/BastionLoading/gui/data/loading_1.edds"		
	};	

	ImageWidget imageWidgetBackground;
	
	override Widget Init()
	{	
		layoutRoot = GetGame().GetWorkspace().CreateWidgets("BastionMod/BastionLoading/gui/layouts/login_time.layout");
		
		m_txtDescription = TextWidget.Cast( layoutRoot.FindAnyWidget("txtDescription") );
		m_txtLabel = TextWidget.Cast( layoutRoot.FindAnyWidget("txtLabel") );
		m_btnLeave = ButtonWidget.Cast( layoutRoot.FindAnyWidget("btnLeave") );

		m_RandomMessages = TextWidget.Cast( layoutRoot.FindAnyWidget("RandomMessages") );
		
        string lscreen = loadingscreens.GetRandomElement();
        ImageWidget background = ImageWidget.Cast( layoutRoot.FindAnyWidget("Background"));
        background.LoadImageFile(0, lscreen);  		

		return layoutRoot;
	}

	override void OnShow()	
	{
		GetGame().GetUIManager().ShowUICursor(true);
		GetGame().GetUIManager().ShowCursor(true);
		GetGame().GetMission().GetHud().Show( false );
		PPEffects.SetBlurMenu(1);
	}

	override void OnHide()	
	{
		GetGame().GetUIManager().ShowCursor(false);
		GetGame().GetUIManager().ShowUICursor(false);
		GetGame().GetMission().GetHud().Show( true );
		PPEffects.SetBlurMenu(0);
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
	
	void SetTime(int time)
	{
		if (!m_IsRespawn)
			m_txtLabel.SetText("#menu_loading_in " + time.ToString() + " #dayz_game_seconds");
		else
			m_txtLabel.SetText("#dayz_game_spawning_in " + time.ToString() + " #dayz_game_seconds");
	}
		
	void SetStatus(string status)
	{
		m_txtDescription.SetText(status);
	}
	
	void SetRespawn(bool value)
	{
		m_IsRespawn = value;
	}
	
	bool IsStatic()
	{
		return m_IsStatic;
	}
	
	bool IsRespawn()
	{
		return m_IsRespawn;
	}
	
	void Leave()
	{
		g_Game.SetGameState( DayZGameState.MAIN_MENU );
		g_Game.SetLoadState( DayZLoadState.MAIN_MENU_START );
		g_Game.GetCallQueue(CALL_CATEGORY_SYSTEM).Call(GetGame().DisconnectSessionForce);
		
		Close();
	}
};