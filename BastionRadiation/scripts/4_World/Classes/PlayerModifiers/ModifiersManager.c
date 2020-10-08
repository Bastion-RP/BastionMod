enum Rad_eModifiers 
{
	MDF_RAD_SICKNESS = 75,
	MDF_RAD_BLOCK,
	MDF_RAD_BLOCK_COOLDOWN,
	MDF_RAD_SICKNESS_VOMIT,
}

modded class ModifiersManager
{
	override void Init()
	{
		super.Init();
		AddModifier(new RadiationSicknessMdfr);
		AddModifier(new RadiationBlockMdfr);
		AddModifier(new RadiationBlockCooldownMdfr);
		AddModifier(new RadiationSicknessVomitMdfr);
	}
}