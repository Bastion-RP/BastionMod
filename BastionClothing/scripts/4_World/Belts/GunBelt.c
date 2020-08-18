class BRP_LeatherWeaponBelt_ColorBase extends Clothing 
{
	override bool CanPutInCargo( EntityAI parent )
    {
		if ( IsEmpty() )
		{
			return true;
		}
		return false;
    }	
	
	override bool CanReceiveAttachment (EntityAI attachment, int slotId)
	{
		if ( attachment.!IsWeapon())
		{
			return false;
		}	
		return true;		
        return super.CanReceiveAttachment(attachment, slotId);			
	}		
};

class BRP_LeatherWeaponBelt_Brown extends BRP_LeatherWeaponBelt_ColorBase {};
class BRP_LeatherWeaponBelt_Black extends BRP_LeatherWeaponBelt_ColorBase {};