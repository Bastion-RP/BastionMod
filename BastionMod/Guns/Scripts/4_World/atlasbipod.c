modded class AtlasBipod extends Inventory_Base
{
	override bool CanPutAsAttachment( EntityAI parent )
	{
		bool m4_rishndgrd   = false;
		bool ak_railhndgrd  = false;
		bool mp5_railhndgrd = false;

		if ( parent.FindAttachmentBySlotName("weaponHandguardM4") != NULL )
		{
			m4_rishndgrd = parent.FindAttachmentBySlotName("weaponHandguardM4").IsKindOf("M4_RISHndgrd");
		}
		
		if ( parent.FindAttachmentBySlotName("weaponHandguardAK") != NULL )
		{
			ak_railhndgrd = parent.FindAttachmentBySlotName("weaponHandguardAK").IsKindOf("AK_RailHndgrd");
		}

		if ( m4_rishndgrd || ak_railhndgrd || parent.IsKindOf("AK12") )
		{
			return true;
		}
		
		return false;
	}

    override bool CanDetachAttachment( EntityAI attachment )
	{
		return false;
	}

}