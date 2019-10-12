class MenuWaitForServer : UIScriptedMenu {
	ref Widget m_Root;
	ref PlayerPreviewWidget m_PlayerPreviewWidget;

	override Widget Init() {
		m_Root = GetGame().GetWorkspace().CreateWidgets("MultiCharacters\\scripts\\layouts\\layoutwaitforserver.layout");
		m_Root.Show(false);

		return m_Root;
	}

	override void OnShow() { }

	override void OnHide() { }
}