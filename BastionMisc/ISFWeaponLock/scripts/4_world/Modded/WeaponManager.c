modded class WeaponManager
{
	ref array<int> ISFClasses = {5, 6, 7, 8, 9, 10, 11};
	bool		   soundStart;

	override bool CanFire(Weapon_Base wpn)
	{
		/*if (wpn.IsISFWeapon() && !wpn.IsHacked())
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
		}*/
		return super.CanFire(wpn);
	}
	
	override void Fire(Weapon_Base wpn)
	{
		if (wpn.IsISFWeapon() && !wpn.IsHacked())
		{
			PlayerBase player = PlayerBase.Cast(m_player);
			if ( player )
			{
				if ( (ISFClasses.Find(player.GetMultiCharactersPlayerClass()) != -1) )
				{
					super.Fire(wpn);
					return;
				}
				else
				{
					if(!soundStart)
					{
						soundStart = true;
						player.BSTShowNotification("Cannot fire ID locked weapon! Return to an NCC Agent immediately.");
						EffectSound sound = SEffectManager.PlaySoundOnObject("ISFW_UnauthorizedAccess_SoundSet", player);
						sound.SetSoundAutodestroy(true);
						GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(DisableSoundStart, 6500, false);
					}
					return;
				}
			}
		}
		
		super.Fire(wpn);
	}
	
	void DisableSoundStart()
	{
		soundStart = false;
	}
}