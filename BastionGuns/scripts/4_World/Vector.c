class BRP_Vector_Base : RifleBoltFree_Base
{
	void BRP_Vector_Base()
	{		
		UnfoldOpticsBRP(this);	
	}
	
	override RecoilBase SpawnRecoilObject()
	{
		return new Ump45Recoil(this);
	}
	
	override int GetWeaponSpecificCommand(int weaponAction ,int subCommand)
	{
		if ( weaponAction == WeaponActions.RELOAD)
		{
			switch (subCommand)
			{
				case WeaponActionReloadTypes.RELOADRIFLE_MAGAZINE_BULLET:
					return WeaponActionReloadTypes.RELOADSRIFLE_MAGAZINE_BULLET;
				
				case WeaponActionReloadTypes.RELOADRIFLE_NOMAGAZINE_BULLET:
					return WeaponActionReloadTypes.RELOADSRIFLE_NOMAGAZINE_BULLET;
				
				case WeaponActionReloadTypes.RELOADRIFLE_MAGAZINE_NOBULLET:
					return WeaponActionReloadTypes.RELOADSRIFLE_MAGAZINE_NOBULLET;
				
				case WeaponActionReloadTypes.RELOADRIFLE_NOMAGAZINE_NOBULLET:
					return WeaponActionReloadTypes.RELOADSRIFLE_NOMAGAZINE_NOBULLET;
				
				default:
					return subCommand;
			}
		
		}
		return subCommand;
	}
	
	override void EEItemAttached(EntityAI item, string slot_name)
	{	
		super.EEItemAttached(item,slot_name);

		if (ItemOptics.Cast(item))
		{ 
			FoldOpticsBRP(this);
		}
	}

	override void EEItemDetached(EntityAI item, string slot_name)
	{	
		super.EEItemDetached(item,slot_name);

		if (ItemOptics.Cast(item))
		{ 
			UnfoldOpticsBRP(this);
		}
	}		
};

class BRP_Vector : BRP_Vector_Base {};