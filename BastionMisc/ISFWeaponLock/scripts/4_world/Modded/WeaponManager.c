modded class WeaponManager
{
	ref array<int> ISFClasses = {5, 6, 7, 8, 9, 10};

	override bool CanFire(Weapon_Base wpn)
	{
		Print("Can Fire");
		if (wpn.IsISFWeapon() && !wpn.IsHacked())
		{
			PlayerBase player = PlayerBase.Cast(m_player);
			if ( player )
			{
				if ( (ISFClasses.Find(player.GetMultiCharactersPlayerClass()) != -1) )
				return super.CanFire(wpn);
			}
			return false;
		}
		return super.CanFire(wpn);
	}
}