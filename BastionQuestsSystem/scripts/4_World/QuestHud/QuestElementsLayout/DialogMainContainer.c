class DialogMainContainer
{
	private Widget	  				m_Parent;
	private MultilineTextWidget		m_Root;

	void DialogMainContainer( Widget parent, string text )
	{
		m_Root	= GetGame().GetWorkspace().CreateWidgets("BastionMod/BastionQuestsSystem/layouts/DialogMainContent.layout", NULL);
		m_Root.SetText(text);
		parent.AddChild(m_Root);
	}
}