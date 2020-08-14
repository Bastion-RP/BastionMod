class DecontaminationSpray extends ItemBase
{
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionDecontaminationObject);
	}
}
