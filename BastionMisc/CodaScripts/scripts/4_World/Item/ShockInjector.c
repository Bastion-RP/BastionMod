class ShockInjector: Inventory_Base
{
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionInjectShockTarget);
		AddAction(ActionInjectShockSelf);
	}
};

class coda_diazepam_syringe: ShockInjector
{
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionInjectShockTarget);
		AddAction(ActionInjectShockSelf);
	}
};