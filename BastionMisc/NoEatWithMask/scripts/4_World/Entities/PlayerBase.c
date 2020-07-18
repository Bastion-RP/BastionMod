modded class PlayerBase
{
	bool MouthClosed()
	{
		array<string> AllowMasks = new array<string>();
		int slot_MASK = InventorySlots.MASK;
		ItemBase item_mask = ItemBase.Cast(this.GetInventory().FindAttachment( slot_MASK ));

		if (item_mask && !item_mask.GetType().Contains("3Hole") && (AllowMasks.Find(item_mask.GetType()) == -1))
		{
			return true;
		}

		return false;
	}
}