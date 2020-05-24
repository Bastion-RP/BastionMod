modded class WeaponManager
{
	override bool CanFire(Weapon_Base wpn)
	{
		if (wpn.IsISFWeapon())
		{
			PlayerBase player = PlayerBase.Cast(m_player);
			if ( player )
			{
				if (player.GetMultiCharactersPlayerClass() == 5)
				return super.CanFire(wpn);
			}
			return false;
		}
		return super.CanFire(wpn);
	}
}