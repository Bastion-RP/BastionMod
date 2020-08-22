class BRP_ACR_Base : RifleBoltLock_Base
{ 
	void BRP_ACR_Base()
	{	
		EntityAI ParentItem = this;		
		UnfoldOpticsBRP(ParentItem);	
	}
	
	override RecoilBase SpawnRecoilObject()
	{
		return new M4a1Recoil(this);
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

class BRP_ACR_Tan : BRP_ACR_Base {};