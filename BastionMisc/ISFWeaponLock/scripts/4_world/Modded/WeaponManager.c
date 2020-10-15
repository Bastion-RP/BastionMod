modded class WeaponManager
{
	ref array<int> ISFClasses = {5, 6, 7, 8, 9, 10, 11};

	override bool CanFire(Weapon_Base wpn)
	{
		if (wpn.IsISFWeapon() && !wpn.IsHacked())
		{
			PlayerBase player = PlayerBase.Cast(m_player);
			if ( player )
			{
				if ( (ISFClasses.Find(player.GetMultiCharactersPlayerClass()) != -1) )
				return super.CanFire(wpn);
			}
			if(player)
			{
				player.BSTShowNotification("Cannot fire ID locked weapon! Return to an NCC Agent immediately.");
				EffectSound sound = SEffectManager.PlaySound("ISFW_UnauthorizedAccess_SoundSet", player.GetPosition());
				sound.SetSoundAutodestroy(true);
			}
			return false;
		}
		return super.CanFire(wpn);
	}
}