class BRP_Furnace extends Fence {
	override string GetConstructionKitType() {
		return "BRP_FurnaceKit";
	}

	bool CanUpgrade() {
		ItemBase metal, nails;
		int slot_id;

		slot_id = InventorySlots.GetSlotIdFromString("Material_MetalSheets");
		metal = ItemBase.Cast(GetInventory().FindAttachment(slot_id));
		slot_id = InventorySlots.GetSlotIdFromString("Material_Nails");
		nails = ItemBase.Cast(GetInventory().FindAttachment(slot_id));

		Print("[DEBUG] BRP_Furnace | CanUpgrade nails=" + nails + " | metal=" + metal);
		if (metal && nails && QuantityConversions.GetItemQuantity(metal) >= 5 && QuantityConversions.GetItemQuantity(nails) >= 20) {
			return true;
		}
		return false;
	}

	//CONSTRUCTION EVENTS
	//Build
	void OnPartBuiltServer(string part_name, int action_id) {
		ConstructionPart constrution_part = GetConstruction().GetConstructionPart(part_name);

		//check base state
		if (constrution_part.IsBase()) {
			SetBaseState(true);

			//spawn kit
			//CreateConstructionKit();
		}
		//check gate state
		if (constrution_part.IsGate()) {
			SetGateState(true);
		}

		//register constructed parts for synchronization
		RegisterPartForSync(constrution_part.GetId());

		//register action that was performed on part
		RegisterActionForSync(constrution_part.GetId(), action_id);

		//synchronize
		SynchronizeBaseState();

		if (GetGame().IsMultiplayer() && GetGame().IsServer())
			SetPartFromSyncData(constrution_part); // server part of sync, client will be synced from SetPartsFromSyncData

		//reset action sync data
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(ResetActionSyncData, 100, false, this);
	}

	override void OnPartDismantledServer(notnull Man player, string part_name, int action_id) {
		ConstructionPart constrution_part = GetConstruction().GetConstructionPart(part_name);

		//check gate state
		if (constrution_part.IsBase()) {
			//spawn kit
			CreateConstructionKit();
		}

		super.OnPartDismantledServer(player, part_name, action_id);
	}

	override bool CanReceiveAttachment(EntityAI attachment, int slotId) { 
		return true;
	}

	override void SetActions() {
		super.SetActions();

		AddAction(ActionTogglePlaceObject);
		AddAction(ActionPlaceObject);
		AddAction(ActionFoldBaseBuildingObject);
	}
}