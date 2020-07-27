modded class ModifiersManager
{
	override void Init()
	{
		super.Init();
		AddModifier(new RadSickMdfr);
		AddModifier(new HazardSickMdfr);
		AddModifier(new AntiRadPillsMdfr);
		AddModifier(new RadPillsTreatmentMdfr);
	}
}
