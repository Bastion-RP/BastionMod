modded class ItemBase
{
	bool IsSeller()
	{
		return false;
	}

	override void SetActions() 
    {
        super.SetActions();
        AddAction(ActionSellItem);
    }

	override bool CanPutInCargo (EntityAI parent)
	{
		if (IsSeller())
			return false;
		return super.CanPutInCargo(parent);
	}

    override bool CanPutIntoHands (EntityAI parent)
	{
		if (IsSeller())
			return false;
		return super.CanPutIntoHands(parent);
	}
}