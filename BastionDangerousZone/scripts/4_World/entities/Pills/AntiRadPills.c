class BRP_AntiRadPills : Edible_Base
{
	override void OnConsume(float amount, PlayerBase consumer)
	{
		if( consumer.GetModifiersManager().IsModifierActive(DZModifiers.MDF_DZANTIRADPILLS))//effectively resets the timer
		{
			consumer.GetModifiersManager().DeactivateModifier( DZModifiers.MDF_DZANTIRADPILLS );
		}
		consumer.GetModifiersManager().ActivateModifier( DZModifiers.MDF_DZANTIRADPILLS );
	}

	override void SetActions()
	{
		super.SetActions();

		AddAction(ActionForceConsumeSingle);
		AddAction(ActionConsumeSingle);
	}
}
