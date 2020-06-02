class DialogMainContainer
{
	private Widget	  				m_Parent;
	private MultilineTextWidget		m_Root;

	float width,height;
	void DialogMainContainer( Widget parent, string text )
	{
		m_Root	= GetGame().GetWorkspace().CreateWidgets("BastionMod/BastionQuestsSystem/layouts/DialogMainContent.layout", NULL);
		m_Root.SetText(text);
		m_Root.GetSize(width,height);
		SetActualHeight(text.Length());
		parent.AddChild(m_Root);
	}

	void SetActualHeight(int len)
	{
		int cnt = len / 75;
		float h = height + cnt * 0.04;
		m_Root.SetSize(width, h);
	}
}