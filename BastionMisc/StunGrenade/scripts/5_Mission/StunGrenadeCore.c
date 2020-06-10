class StunGrenadeBase {

	ref StunGrenadeSettings g_ServerConfig;

	void StunGrenadeBase() {

		if (GetGame().IsServer())	{
			g_ServerConfig = StunGrenadeSettings.Load();
		}
	}
};