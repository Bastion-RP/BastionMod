class BRP_AIONPowder_Crate: BuildingBase 
{
	override void SetActions()
	{
		super.SetActions();		
		AddAction(ActionTakeAIONPowderOrBottle);
	}
};

class BRP_AIONBottle_Crate: BuildingBase 
{
	override void SetActions()
	{
		super.SetActions();		
		AddAction(ActionTakeAIONPowderOrBottle);
	}
};