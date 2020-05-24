class BRP_CartonBox_BodyBagKits: BuildingBase 
{
	override void SetActions()
	{
		super.SetActions();		
		AddAction(ActionTakeBodyBagKit);
	}
};