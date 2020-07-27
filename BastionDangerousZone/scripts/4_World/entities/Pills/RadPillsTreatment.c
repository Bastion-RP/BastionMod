class dz_RadPillsTreament : Edible_Base
{
	override void OnConsume(float amount, PlayerBase consumer)
	{
		if( consumer.GetModifiersManager().IsModifierActive(DZModifiers.MDF_DZRADPILLSTREATMENT ) )//effectively resets the timer
		{
			consumer.GetModifiersManager().DeactivateModifier(DZModifiers.MDF_DZRADPILLSTREATMENT );
		}
		consumer.GetModifiersManager().ActivateModifier(DZModifiers.MDF_DZRADPILLSTREATMENT );
	}

	override void SetActions()
	{
		super.SetActions();

		AddAction(ActionForceConsumeSingle);
		AddAction(ActionConsumeSingle);
	}
}
