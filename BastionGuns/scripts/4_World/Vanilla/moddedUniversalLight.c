modded class UniversalLight
{
	override bool CanPutAsAttachment( EntityAI parent )
	{
		if( parent.IsKindOf("BRP_SCARH_Black") || parent.IsKindOf("BRP_AR15Hunting")) 	
		{
			return true;
		}		
		return super.CanPutAsAttachment(parent);
	}
};