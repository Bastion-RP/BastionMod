class BRP_SCARH_Base : RifleBoltFree_Base
{
	void BRP_SCARH_Base()
	{
		EntityAI ParentItem = this;		
		UnfoldOpticsBRP(ParentItem);
	}
	
	override RecoilBase SpawnRecoilObject()
	{
		return new FALRecoil(this);
	}
	
	override void EEItemAttached(EntityAI item, string slot_name)
	{	
		super.EEItemAttached(item,slot_name);

		if (ItemOptics.Cast(item))
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
};

class BRP_SCARH_Black : BRP_SCARH_Base {};