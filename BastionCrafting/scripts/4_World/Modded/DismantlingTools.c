modded class Screwdriver
{
    override void SetActions()
    {
        super.SetActions();
        AddAction(ActionBRPDismantleItem);
    }
};

modded class Pliers
{
    override void SetActions()
    {
        super.SetActions();
        AddAction(ActionBRPDismantleItem);
    }
};

modded class Wrench extends ItemBase
{
  override void SetActions()
	{
		super.SetActions();
		AddAction(ActionBRPDismantleItem);
	}
}

