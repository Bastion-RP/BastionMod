
static ref StunGrenadeBase m_StunGrenadeBase;
static ref StunGrenadeBase GetStunGrenadeBase() {
	if ( !m_StunGrenadeBase ) {
		m_StunGrenadeBase = new ref StunGrenadeBase;
	}
	return m_StunGrenadeBase;
}

static ref StunGrenadeSettings GetSGConfig()	{
	return GetStunGrenadeBase().g_ServerConfig;
}