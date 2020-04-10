class BST_Compactor : ItemBase {
    override void SetActions() {
        super.SetActions();
        AddAction(ActionCompactBodyBag);
    }

    override bool CanPutIntoHands(EntityAI parent)
	{
        return false;
    }

    override bool CanPutInCargo(EntityAI parent)
    {
		return false;
    }
};