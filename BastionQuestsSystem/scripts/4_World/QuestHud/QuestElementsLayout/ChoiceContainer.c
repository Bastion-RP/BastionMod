class ChoiceContainer
{
    private Widget	  				m_Parent;
	private MultilineTextWidget		m_Root;
	private EditBoxWidget			m_MoveToStg;
	private EditBoxWidget			m_ApplyIDStg;
	private EditBoxWidget			m_ChoiceText;
	private EditBoxWidget			m_FinishText;
	private EditBoxWidget			m_TeleportTo;

	void ChoiceContainer( Widget parent, string text, int move = 0, int apl = 0, int fin = 0, string teleportTo = "")
	{
		m_Root			= GetGame().GetWorkspace().CreateWidgets("BastionMod/BastionQuestsSystem/layouts/ChoiceWidget.layout", parent);
		m_MoveToStg		= EditBoxWidget.Cast(m_Root.FindAnyWidget("MoveToStg"));
		m_ApplyIDStg	= EditBoxWidget.Cast(m_Root.FindAnyWidget("ApplyIDStg"));
		m_ChoiceText	= EditBoxWidget.Cast(m_Root.FindAnyWidget("ChoiceText"));
		m_FinishText	= EditBoxWidget.Cast(m_Root.FindAnyWidget("FinishStg"));
		m_TeleportTo	= EditBoxWidget.Cast(m_Root.FindAnyWidget("TeleportTo"));
		m_Root.SetText(text);
		m_ChoiceText.SetText(text);
		m_MoveToStg.SetText(move.ToString());
		m_ApplyIDStg.SetText(apl.ToString());
		m_FinishText.SetText(fin.ToString());
		m_TeleportTo.SetText(teleportTo);
	}

}