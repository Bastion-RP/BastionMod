modded class WoodenCrate: Container_Base
{
	override bool IsDeployable()
	{
		return true;
	}

	override void SetActions()
    {
        super.SetActions();
        AddAction(ActionTogglePlaceObject);
		AddAction(ActionPlaceObject);
    }
};