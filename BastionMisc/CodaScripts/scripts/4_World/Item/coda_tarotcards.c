class coda_tarotcards : Box_Base
{

	override void SetActions()
	{
		super.SetActions();
		RemoveAction(ActionUnpackBox);
		
	}
	
}