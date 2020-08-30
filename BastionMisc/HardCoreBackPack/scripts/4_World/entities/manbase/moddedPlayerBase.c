modded class PlayerBase
{
	int backPackId;
	string backPackClass;
	ref array<int> attachToBackPackIds = new array<int>();
	ref array<string> attachToBackPackClassName =  new array<string>();
	
	int GetBackPackId()
	{
		return backPackId;
	}
	
	string GetBackPackClass()
	{
		return backPackClass;
	}
	
	array<int> GetAttackToBackPackIds()
	{
		return attachToBackPackIds;
	}
	
	array<string> GetSttachToBackPackClassName()
	{
		return  attachToBackPackClassName;
	}
	
	override void PredictiveMoveItemFromHandsToInventory ()
	{
		syncDebugPrint("[inv] " + GetDebugName(this) + " STS=" + GetSimulationTimeStamp() + " Stash IH=" + GetHumanInventory().GetEntityInHands());
		if (!ScriptInputUserData.CanStoreInputUserData())
		{
			Print("[inv] PredictiveMoveItemFromHandsToInventory input data not sent yet, cannot allow another input action");
			return;
		}
		
		EntityAI att_item = GetHumanInventory().GetEntityInHands();
		EntityAI parrent = att_item.m_OldLocation.GetParent();
		if(parrent)
		{
			if(!GetGame().IsServer())
			{
				if(parrent.GetInventory().IsInventoryLockedForLockType( HIDE_INV_FROM_SCRIPT ))
				{
					parrent.GetInventory().UnlockInventory(HIDE_INV_FROM_SCRIPT);	
				}
			}
		}
		//! returns item to previous location, if available
		if (GetHumanInventory().GetEntityInHands().m_OldLocation && GetHumanInventory().GetEntityInHands().m_OldLocation.IsValid())
		{
			InventoryLocation invLoc = new InventoryLocation;
			GetHumanInventory().GetEntityInHands().GetInventory().GetCurrentInventoryLocation(invLoc);
			//old location is somewhere on player
			if (GetHumanInventory().GetEntityInHands().m_OldLocation.GetParent() && GetHumanInventory().GetEntityInHands().m_OldLocation.GetParent().GetHierarchyRootPlayer())
			{
				
				if (GetHumanInventory().LocationCanMoveEntity(invLoc, GetHumanInventory().GetEntityInHands().m_OldLocation))
				{
					if (GetHumanInventory().TakeToDst(InventoryMode.PREDICTIVE,invLoc,GetHumanInventory().GetEntityInHands().m_OldLocation))
					{
						UpdateInventoryMenu();
						return;
					}
				}
			}
		}
		
		GetHumanInventory().TakeEntityToInventory(InventoryMode.PREDICTIVE, FindInventoryLocationType.ATTACHMENT | FindInventoryLocationType.CARGO, GetHumanInventory().GetEntityInHands());
		UpdateInventoryMenu();
		
		
	}
	
	override void EEItemAttached(EntityAI item, string slot_name)
	{
		super.EEItemAttached(item, slot_name);
		
		if(slot_name == "Back")
		{
			backPackId = item.GetID();
			backPackClass = item.ClassName();
			if(!GetGame().IsServer())
			{
				item.GetInventory().LockInventory(HIDE_INV_FROM_SCRIPT);
			}
			ItemBase itemAnalize;
			attachToBackPackIds = new array<int>();
			attachToBackPackClassName =  new array<string>();
			for ( int i = 0; i < item.GetInventory().GetAttachmentSlotsCount(); ++i )
			{
				itemAnalize = ItemBase.Cast( item.GetInventory().FindAttachment(item.GetInventory().GetAttachmentSlotId(i)) );
				if ( itemAnalize )
				{
					if(itemAnalize.IsInherited(Chemlight_ColorBase))
					{
						continue;
					}
					if(itemAnalize.ClassName().Contains("PersonalRadio"))
					{
						continue;
					}	
					
					if(!GetGame().IsServer())
					{
						itemAnalize.GetInventory().LockInventory(HIDE_INV_FROM_SCRIPT);
					}
					attachToBackPackIds.Insert(itemAnalize.GetID());
					attachToBackPackClassName.Insert(itemAnalize.ClassName());
					
				}
			}
		}
		
			
	}
	
	override void EEItemDetached(EntityAI item, string slot_name)
	{
		super.EEItemDetached(item, slot_name);
		
		if(slot_name == "Back")
		{
			backPackId = 0;
			backPackClass = "";
			attachToBackPackIds = new array<int>();
			if(!GetGame().IsServer())
			{
				item.GetInventory().UnlockInventory(HIDE_INV_FROM_SCRIPT);
			}
			ItemBase itemAnalize;
			for ( int i = 0; i < item.GetInventory().GetAttachmentSlotsCount(); ++i )
			{
				itemAnalize = ItemBase.Cast( item.GetInventory().FindAttachment(item.GetInventory().GetAttachmentSlotId(i)) );
				
				if ( itemAnalize )
				{
					if(itemAnalize.IsInherited(Chemlight_ColorBase))
					{
						continue;
					}
					if(itemAnalize.ClassName().Contains("PersonalRadio"))
					{
						continue;
					}	
					
					if(!GetGame().IsServer())
					{
						itemAnalize.GetInventory().UnlockInventory(HIDE_INV_FROM_SCRIPT);
					}
				}
			}
			
		}
		
		
	}
	
	override EntityAI GetQuickBarEntity(int index)
	{
		EntityAI entityAI =  super.GetQuickBarEntity(index);
		
		if(entityAI)
		{
			if(entityAI.IsInherited(Clothing))
			{
				return entityAI;
			}
			
			InventoryLocation il = new InventoryLocation;
			entityAI.GetInventory().GetCurrentInventoryLocation( il);
			EntityAI parrent = il.GetParent();
			if(parrent)
			{
				if(backPackId == parrent.GetID())
				{
					for ( int i = 0; i < parrent.GetInventory().GetAttachmentSlotsCount(); ++i )
					{
						EntityAI itemAnalize = ItemBase.Cast( parrent.GetInventory().FindAttachment(parrent.GetInventory().GetAttachmentSlotId(i)) );
						
						if ( itemAnalize )
						{
							if(itemAnalize.GetID() ==  entityAI.GetID())
							{
								if(itemAnalize.IsInherited(Chemlight_ColorBase))
								{
									return entityAI;
								}
								if(itemAnalize.ClassName().Contains("PersonalRadio"))
								{
									return entityAI;
								}	
							}
						}
					}
					
					return null;
				}
			}
		}
		
		return  entityAI;
	}
	
	override void OnInventoryMenuOpen()
	{
		super.OnInventoryMenuOpen();
		if(!GetGame().IsServer())
		{
			ItemBase  itemInSlot = ItemBase.Cast(this.FindAttachmentBySlotName("Back"));
			if(itemInSlot)
			{
				if(!itemInSlot.GetInventory().IsInventoryLockedForLockType( HIDE_INV_FROM_SCRIPT ))
					itemInSlot.GetInventory().LockInventory( HIDE_INV_FROM_SCRIPT );
				
				ItemBase itemAnalize;
				for ( int i = 0; i < itemInSlot.GetInventory().GetAttachmentSlotsCount(); ++i )
				{
					itemAnalize = ItemBase.Cast( itemInSlot.GetInventory().FindAttachment(itemInSlot.GetInventory().GetAttachmentSlotId(i)) );
					if ( itemAnalize )
					{
						if(itemAnalize.IsInherited(Chemlight_ColorBase))
						{
							continue;
						}
						if(itemAnalize.ClassName().Contains("PersonalRadio"))
						{
							continue;
						}
						if(!itemAnalize.GetInventory().IsInventoryLockedForLockType( HIDE_INV_FROM_SCRIPT ))
							itemAnalize.GetInventory().LockInventory( HIDE_INV_FROM_SCRIPT );
					}
				}
			}
		}
	}
}