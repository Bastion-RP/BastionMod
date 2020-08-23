modded class BUISOptic extends ItemOptics
{
	override bool CanPutAsAttachment( EntityAI parent )
	{
		if ( parent.IsKindOf("BRP_AR15Hunting_Base") )
		{
			return true;
		}

		return false;
        return super.CanPutAsAttachment(parent);		
	}
};