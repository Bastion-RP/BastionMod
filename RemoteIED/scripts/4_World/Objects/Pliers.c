modded class Pliers extends ItemBase
{
	override void SetActions()
	{
		super.SetActions();

		AddAction( ActionDisarmIED );
		AddAction( ActionArmIED );
	}
}