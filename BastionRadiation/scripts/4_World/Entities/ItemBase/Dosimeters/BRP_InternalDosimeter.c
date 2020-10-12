class BRP_InternalDosimeter : Morphine
{
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionMeasureRadiationLevel);
		RemoveAction(ActionInjectMorphineTarget);
		RemoveAction(ActionInjectMorphineSelf);
	}
}