class BRP_AntiRadPills : Edible_Base
{
	override void OnConsume(float amount, PlayerBase consumer)
	{
		if( consumer.GetModifiersManager().IsModifierActive(Rad_eModifiers.MDF_RAD_BLOCK_COOLDOWN))
		{
			consumer.GetModifiersManager().DeactivateModifier( Rad_eModifiers.MDF_RAD_BLOCK_COOLDOWN );
			ActivatePenalty(consumer);
		}
		else
		{
			consumer.GetModifiersManager().ActivateModifier( Rad_eModifiers.MDF_RAD_BLOCK );
		}
		consumer.GetModifiersManager().ActivateModifier( Rad_eModifiers.MDF_RAD_BLOCK_COOLDOWN );
	}

	void ActivatePenalty(PlayerBase player)
	{
		if( player.GetModifiersManager().IsModifierActive(Rad_eModifiers.MDF_RAD_SICKNESS_VOMIT))
			player.GetModifiersManager().DeactivateModifier( Rad_eModifiers.MDF_RAD_SICKNESS_VOMIT );
		player.GetModifiersManager().ActivateModifier( Rad_eModifiers.MDF_RAD_SICKNESS_VOMIT );
	}

	override void SetActions()
	{
		super.SetActions();

		AddAction(ActionForceConsumeSingle);
		AddAction(ActionConsumeSingle);
	}
}