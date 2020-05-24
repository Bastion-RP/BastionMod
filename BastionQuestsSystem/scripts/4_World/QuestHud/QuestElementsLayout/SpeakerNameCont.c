class SpeakerNameContainer
{
	private Widget	  				m_Parent;
	private TextWidget				m_Root;
	private TextWidget				m_TestGreen;
	private TextWidget				m_TestBrown;

	void SpeakerNameContainer( Widget parent, string text, int type)
	{
		m_Root	= GetGame().GetWorkspace().CreateWidgets("BastionMod/BastionQuestsSystem/layouts/SpeakerName.layout", parent);
		m_TestGreen = TextWidget.Cast(m_Root.FindAnyWidget("TextTestGreen"));
		m_TestBrown	= TextWidget.Cast(m_Root.FindAnyWidget("TextTestBrown"));
		m_Root.SetText(text);

		switch (type)
		{
			case 0:
				m_Root.SetColor(-6323928); // brown
			break;
			case 1:
				m_Root.SetColor(-16744416); // green
			break;
		}

	}
}