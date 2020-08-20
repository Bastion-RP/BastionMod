class BRP_AR15Hunting_Base : RifleBoltFree_Base
{
	void BRP_AR15Hunting_Base()
	{	
		EntityAI ParentItem = this;		
		UnfoldOpticsBRP(ParentItem);	
	}
	
	override void EEItemAttached(EntityAI item, string slot_name)
	{	
		super.EEItemAttached(item,slot_name);

		if (ItemOptics.Cast(item) && ItemOptics.Cast(item).!IsKindOf("BUISOptic") && ItemOptics.Cast(item).!IsKindOf("M4_CarryHandleOptic"))
		{ 
			EntityAI ParentItem = this;
			FoldOpticsBRP(ParentItem);
		}
	}

	override void EEItemDetached(EntityAI item, string slot_name)
	{	
		super.EEItemDetached(item,slot_name);

		if (ItemOptics.Cast(item))
		{ 
			EntityAI ParentItem = this;
			UnfoldOpticsBRP(ParentItem);
		}
	}			
	
	override RecoilBase SpawnRecoilObject()
	{
		return new M4a1Recoil(this);
	}
	
	override int GetWeaponSpecificCommand(int weaponAction ,int subCommand)
	{
		if ( weaponAction == WeaponActions.RELOAD)
		{
			switch (subCommand)
			{
				case WeaponActionReloadTypes.RELOADSRIFLE_MAGAZINE_BULLET:
					return WeaponActionReloadTypes.RELOADRIFLE_MAGAZINE_BULLET;
				
				case WeaponActionReloadTypes.RELOADSRIFLE_NOMAGAZINE_BULLET:
					return WeaponActionReloadTypes.RELOADRIFLE_NOMAGAZINE_BULLET;
				
				case WeaponActionReloadTypes.RELOADSRIFLE_MAGAZINE_NOBULLET:
					return WeaponActionReloadTypes.RELOADRIFLE_MAGAZINE_NOBULLET;
				
				case WeaponActionReloadTypes.RELOADSRIFLE_NOMAGAZINE_NOBULLET:
					return WeaponActionReloadTypes.RELOADRIFLE_NOMAGAZINE_NOBULLET;
				
				default:
					return subCommand;
			}
		
		}
		return subCommand;
	}
	
	override void SetActions()
	{
		super.SetActions();

		AddAction(FirearmActionDetachMagazine);	
	}	
};

class BRP_AR15Hunting : BRP_AR15Hunting_Base {};