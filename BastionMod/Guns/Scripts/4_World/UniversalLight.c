modded class UniversalLight extends Switchable_Base
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

		if ( parent.FindAttachmentBySlotName("weaponHandguardMP5") != NULL )
		{
			mp5_railhndgrd = parent.FindAttachmentBySlotName("weaponHandguardMP5").IsKindOf("MP5_RailHndgrd");
		}

		if ( m4_rishndgrd || ak_railhndgrd || mp5_railhndgrd || parent.IsKindOf("UMP45_Base") || parent.IsKindOf("AK12") )
		{
			return true;
		}
		
		return false;
	}
	
	//copied from Flashlight, TODO redo

}