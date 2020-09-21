modded class PluginAdminLog extends PluginBase
{
	bool GrenadeLog(PlayerBase player, Object source, string ammo = "", bool is_kill = false)
	{
		if (!player || !source) return false;

		bool grenade_hit = false;
		Grenade_Base grenade;
		BRP_RemoteIED ied;
		if (Class.CastTo(grenade, source))
		{
			grenade_hit = true;
			m_Source = grenade.m_Player;
		}
		else if (Class.CastTo(ied, source))
		{
			grenade_hit = true;
			m_Source = ied.m_Player;
		}
		else
		{
			m_Source = NULL;
		}

		if (grenade_hit && m_Source && m_Source.IsPlayer() && m_Source.GetIdentity())
		{
			m_PlayerPrefix = GetPlayerPrefix(player, player.GetIdentity());
			m_PlayerPrefix2 = GetPlayerPrefix(m_Source, m_Source.GetIdentity());

			if (ammo && m_HitMessage) LogPrint(m_PlayerPrefix + " hit by " + m_PlayerPrefix2 + " with " + ammo + m_HitMessage);
			else if (is_kill) LogPrint(m_PlayerPrefix + " killed by " + m_PlayerPrefix2 + " with " + source.GetDisplayName());
			else return false;

			return true;
		}

		return false;
	}

	override void PlayerKilled(PlayerBase player, Object source)
	{
		if (!GrenadeLog(player, source, "", true)) super.PlayerKilled(player, source);
	}

	override void PlayerHitBy(TotalDamageResult damageResult, int damageType, PlayerBase player, EntityAI source, int component, string dmgZone, string ammo)
	{
		if (player && source) m_HitMessage = GetHitMessage(damageResult, component, dmgZone, ammo);
		if (!GrenadeLog(player, source, ammo, false)) super.PlayerHitBy(damageResult, damageType, player, source, component, dmgZone, ammo);
	}
}