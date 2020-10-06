class BRP_bag_6B38_Colorbase extends Clothing
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