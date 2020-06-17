class BstModal
{
	private Widget						m_ModalWrap;
	private ButtonWidget				m_ModalBtnYes;
	private ButtonWidget				m_ModalBtnNo;

	private ref HousingHud				m_ParentClass;
	private string						m_FuncNameCB;

	void BstModal(Widget parent)
	{
		m_ModalWrap		=	Widget.Cast(parent.FindAnyWidget("ModalWrap"));
		m_ModalBtnYes	=	ButtonWidget.Cast(parent.FindAnyWidget("ModalBtnYes"));
		m_ModalBtnNo	=	ButtonWidget.Cast(parent.FindAnyWidget("ModalBtnNo"));
	}

	void Show()
	{
		m_ModalWrap.Show(true);
	}

	void Hide()
	{
		m_ModalWrap.Show(false);
	}

	void RequestConfirm(string callback, HousingHud parentClass = null)
	{
		m_FuncNameCB 	= 	callback;
		m_ParentClass	=	parentClass;
		Show();
	}
	
	void OnClick(bool yes)
	{
		if (yes)
		{
			if (m_ParentClass)
			GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallByName(m_ParentClass,m_FuncNameCB);
			else
			GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallByName(g_HM,m_FuncNameCB);
		}

		m_FuncNameCB = "";
		Hide();
	}
}