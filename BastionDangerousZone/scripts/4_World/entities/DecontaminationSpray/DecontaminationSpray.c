class DecontaminationSpray extends Inventory_Base
{
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionDecontaminationObject);
	}
}
