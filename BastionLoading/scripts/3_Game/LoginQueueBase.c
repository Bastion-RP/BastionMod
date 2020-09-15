modded class LoginQueueBase extends UIScriptedMenu
{
	protected TextWidget m_txtPosition;
	protected TextWidget m_txtNote;
	protected ButtonWidget m_btnLeave;
	
	protected int m_iPosition;
	protected bool m_IsStatic;

	protected TextWidget m_RandomMessages;
	
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
		"BastionMod/BastionLoading/gui/data/loading_1.edds",
		"BastionMod/BastionLoading/gui/data/loading_1.edds"			
	};	

	ImageWidget imageWidgetBackground;
	
	override Widget Init()
	{	
		layoutRoot = GetGame().GetWorkspace().CreateWidgets("BastionMod/BastionLoading/gui/layouts/queue_position.layout");
		
		m_txtPosition = TextWidget.Cast( layoutRoot.FindAnyWidget("txtPosition") );
		m_txtNote = TextWidget.Cast( layoutRoot.FindAnyWidget("txtNote") );
		m_btnLeave = ButtonWidget.Cast( layoutRoot.FindAnyWidget("btnLeave") );

		m_RandomMessages = TextWidget.Cast( layoutRoot.FindAnyWidget("RandomMessages") );

        string lscreen = loadingscreens.GetRandomElement();
        ImageWidget background = ImageWidget.Cast( layoutRoot.FindAnyWidget("Background"));
        background.LoadImageFile(0, lscreen);  	

		return layoutRoot;
	}
};