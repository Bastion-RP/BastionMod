modded class PlayerBase extends ManBase
{
	override void Init()
	{
		super.Init();
	}
	
	void CheckProtectionAgainstStun()
	{
		if (GetGame().IsServer())
		{
			EntityAI SuitsPart;
			SuitsPart = this.FindAttachmentBySlotName("Mask");
			if (SuitsPart == NULL || SuitsPart.IsRuined() || !(SuitsPart.IsKindOf("GP5GasMask")||SuitsPart.IsKindOf("GasMask")))
			{
				Print("GiveShock");
				GiveShock(-100);
				return;
			}
			/*else
			{
				if (SuitsPart != NULL && !SuitsPart.IsRuined())
				{
					SuitsPart.AddHealth( "", "", -GP5DamageGrenade);
				}
			}*/
		}
	}
}
