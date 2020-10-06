class BRP_carrierrig extends Clothing
{
	override bool CanPutAsAttachment( EntityAI parent )
	{
		if ( parent.IsKindOf("BRP_carrierrig"))
		{
			return false;
		}
		return true;
	}
};