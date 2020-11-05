class coda_soap : Box_Base
{

	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionDisinfectTarget);
		AddAction(ActionDisinfectSelf);
		RemoveAction(ActionUnpackBox);
		
	}
	
}