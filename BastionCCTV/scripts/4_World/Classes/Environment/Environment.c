modded class Environment
{
	protected bool IsWaterContact()
	{
    if (m_Player) {
      bool isInCamera = BastionCCTV.m_CCTVUsers.Contains( m_Player.GetIdentity().GetId() );
      return !isInCamera && m_IsInWater;
    }
    return super.IsWaterContact();
	}
}