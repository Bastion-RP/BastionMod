modded class SledgeHammer
{
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionBRPDismantleFurnace);
	}
}
modded class Hammer
{
	override void SetActions() 
	{
		super.SetActions();
		
		AddAction(BST_ActionUpgradeFurnace);
	}	
}
modded class Hatchet
{
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(BST_ActionUpgradeFurnace);
	}
};
