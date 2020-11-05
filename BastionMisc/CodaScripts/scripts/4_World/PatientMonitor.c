class brp_patientmonitor: ItemBase
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

class coda_medicaltable: ItemBase
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

class coda_microscope: ItemBase
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