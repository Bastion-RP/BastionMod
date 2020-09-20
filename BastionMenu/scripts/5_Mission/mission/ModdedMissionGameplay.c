modded class MissionGameplay extends MissionBase
{
	override void CreateLogoutMenu(UIMenuPanel parent)
	{
		if (!m_Logout) super.CreateLogoutMenu(parent);	
	}
}