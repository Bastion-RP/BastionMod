enum ScarlettModifiers
{
	SCARLETT_DRUNK
};

modded class ModifiersManager
{
	override void Init()
	{
		super.Init();

		AddModifier(new DrunkModifier);
	}
};