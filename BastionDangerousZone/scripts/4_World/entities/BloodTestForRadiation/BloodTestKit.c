class BloodTestForRadiationKit: Inventory_Base
{
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionTestForRadiationSelf);
		AddAction(ActionTestForRadiationTarget);
	}
};
