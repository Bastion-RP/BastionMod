modded class DayZPlayerImplement
{
	
	override void OnItemInHandsChanged ()
	{
		
		StopWeaponEvent();
		GetItemAccessor().OnItemInHandsChanged();
		
		if (!IsAlive())
		{
			Print("inv: DayZPlayerImplement::OnItemInHandsChanged - human not alive! calling ResetWeaponInHands");
			GetItemAccessor().ResetWeaponInHands();
		}
		EntityAI backPack = FindAttachmentBySlotName("Back");
		if(backPack != null)
		{
			if(!GetGame().IsServer())
			{
				backPack.GetInventory().LockInventory(HIDE_INV_FROM_SCRIPT);
			}
		}
	}
}