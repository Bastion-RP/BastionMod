class Bastion_Medical_Vendor_Color extends Inventory_Base
{
	override void InitItemVariables()
	{
		m_IsTakeable = false;
	}
	
	override bool IsContainer()
	{
		return false;		
	}
	
	override bool CanPutInCargo( EntityAI parent )
	{
		return false;
	}
	
	override bool CanPutAsAttachment( EntityAI parent )
	{		
		return false;
	}
}