class BstNot
{
	private Widget					m_Root;
	private MultilineTextWidget		m_MTW;
	private ProgressBarWidget		m_PB;
	private ref WidgetFadeTimer 	m_FadeTimer;

	void BstNot(string text)
	{
		m_FadeTimer	= new WidgetFadeTimer;
		m_Root		= GetGame().GetWorkspace().CreateWidgets("BastionMod/BastionHousingSystem/layouts/BastNot.layout", g_HM.GetBstNotStg());
		m_MTW		= MultilineTextWidget.Cast(m_Root.FindAnyWidget("MTW"));
		m_PB		= ProgressBarWidget.Cast(m_Root.FindAnyWidget("PB"));


		m_MTW.SetText(text);

		if (text.Length() <= 9)
		{
			m_MTW.SetSize(0.98, 0.35);
		}

		g_HM.BstNotifications.Insert(this);
		m_FadeTimer.FadeIn(m_Root, 1);
		GetGame().GetCallQueue( CALL_CATEGORY_GUI ).CallLater( this.UpdatePB, 10, true);
		// GetGame().GetCallQueue( CALL_CATEGORY_GUI ).CallLater( this.NotificationFadeOut, 3000, false);
	}

	void UpdatePB()
	{
		float progress = m_PB.GetCurrent();
		progress -= 0.33;
		if (progress <= 0)
		{
			NotificationFadeOut();
			GetGame().GetCallQueue( CALL_CATEGORY_GUI ).Remove( this.UpdatePB );
			// m_FadeTimer.Stop();
			// if (this) 
			// {
			// 	delete this;
			// }
		}
		m_PB.SetCurrent(progress);
	}

	void ~BstNot()
	{
		this.Destroy();
		// GetGame().GetCallQueue( CALL_CATEGORY_GUI ).Remove( this.UpdatePB );
		int idx = g_HM.BstNotifications.Find(this);
		if (idx != -1)
		{g_HM.BstNotifications.Remove(idx);}
	}

	void Destroy()
	{
		if (m_Root)
		{m_Root.Unlink();}
	}

	void NotificationFadeOut()
	{
		m_FadeTimer.FadeOut(m_Root, 0.7);
		GetGame().GetCallQueue( CALL_CATEGORY_GUI ).CallLater( DeleteThis, 705, false, this);
	}

	void DeleteThis()
	{
		m_FadeTimer.Stop();
		if (this) 
		{
			delete this;
		}
	}
}

//GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Call(GetGame().ObjectDelete, this);