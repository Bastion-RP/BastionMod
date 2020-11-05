modded class PluginAdminLog extends PluginBase
{
	override string GetPlayerPrefix(PlayerBase player, PlayerIdentity identity)
	{
		string orig = super.GetPlayerPrefix(player, identity);

		if (orig.Contains("Unknown/Dead Entity")) return orig;

		int character_id = player.GetMultiCharactersPlayerId();
		if (!character_id) character_id = 0;

		string character_name = player.GetMultiCharactersPlayerName();
		if (!character_name || character_name == "") character_name = "Unknown";

		return "Player " + m_PlayerName + " (playing as \"" + character_name + "(" + character_id + ")\") (pos=<" +  m_PosArray[0] + ", " + m_PosArray[1] + ", " + m_PosArray[2] + ">)";
	}
}