class BRP_RadPillsTreament : Edible_Base
{
	override void OnConsume(float amount, PlayerBase consumer)
	{
		consumer.DecreaseAgent(BST_Agents.RADIATION, RadConst.RAD_PILLS_POWER);
	}

	override void SetActions()
	{
		super.SetActions();

		AddAction(ActionForceConsumeSingle);
		AddAction(ActionConsumeSingle);
	}
}
