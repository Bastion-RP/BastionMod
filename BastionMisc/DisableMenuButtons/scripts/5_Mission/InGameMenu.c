modded class InGameMenu
{
	override void SetServerInfoVisibility(bool show)
	{
		super.SetServerInfoVisibility(show);
		m_RestartButton.Enable(false);
	}
}