const string backgroundPath = "Menu/gui/images/bastion_background.edds";
const string maskPath = "Menu/gui/images/bastion_backgroundmask.edds";
const string logoPath = "Menu/gui/images/bastionlogo.edds";


modded class LoadingScreen

	void LoadingScreen(DayZGame game) 
	{
		m_ImageBackground.LoadImageFile(0, backgroundPath);
		m_ImageBackground.LoadMaskTexture(maskPath);
		Class.CastTo(m_ImageLogoCorner, m_WidgetRoot.FindAnyWidget("ImageLogoCorner"));
		
		m_ImageLogoCorner.LoadImageFile(0, logoPath);
		m_ImageLogoMid.LoadImageFile(0, logoPath);

		m_ImageLogoCorner.SetSize(380, 100);
		m_ImageLogoMid.SetSize(380, 100);
		
		ProgressAsync.SetUserData(m_ImageBackground);
		ProgressAsync.SetUserData(m_ImageLogoCorner);
	}

modded class LoginQueueBase {
	
	override Widget Init() {
		Widget w = super.Init();
		ImageWidget imageWidgetBackground = ImageWidget.Cast( layoutRoot.FindAnyWidget("Background") );
		imageWidgetBackground.LoadImageFile(0, backgroundPath);
		imageWidgetBackground.LoadMaskTexture(maskPath);
		
		ImageWidget imageLogoCorner = ImageWidget.Cast( layoutRoot.FindAnyWidget("ImageLogoCorner"));

		imageLogoCorner.LoadImageFile(0, logoPath);
		return w;
	}
}
modded class LoginTimeBase {
	
	override Widget Init() {
		Widget w = super.Init();
		ImageWidget imageWidgetBackground = ImageWidget.Cast( layoutRoot.FindAnyWidget("Background") );
		imageWidgetBackground.LoadImageFile(0, backgroundPath);
		imageWidgetBackground.LoadMaskTexture(maskPath);
		
		ImageWidget imageLogoCorner = ImageWidget.Cast( layoutRoot.FindAnyWidget("ImageLogoCorner"));

		imageLogoCorner.LoadImageFile(0, logoPath);
		return w;
	}
	
}

