class BRP_AIONBox_Base extends Inventory_Base{}
class BRP_AIONBox_Full extends BRP_AIONBox_Base
{
	void BRP_AIONBox_Full(){}

	void EEInit()
	{
		if (GetInventory()) FillBox();
	}

	void FillBox()
	{
		bool full = HasAnyCargo();
		while (!full)
		{
			EntityAI item;
			full = !(Class.CastTo(item, GetInventory().CreateEntityInCargo("BRP_AION")));
		}
	}
}

class BRP_AIONBoxes1 extends BuildingBase
{
	override void SetActions()
	{
		super.SetActions();

		AddAction(ActionTakeAIONPowderOrBottle);
	}
}
class BRP_AIONBoxes2 extends BuildingBase
{
	override void SetActions()
	{
		super.SetActions();

		AddAction(ActionTakeAIONPowderOrBottle);
	}
}
class BRP_AIONBoxes3 extends BuildingBase
{
	override void SetActions()
	{
		super.SetActions();

		AddAction(ActionTakeAIONPowderOrBottle);
	}
}