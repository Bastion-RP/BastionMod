modded class ItemBase
{
	override bool CanRemoveFromCargo(EntityAI parent)
	{
		if (!super.CanRemoveFromCargo(parent))
			return false;

		PlayerBase currentParent;
		if (Class.CastTo(currentParent, GetHierarchyRootPlayer()))
		{
			if (currentParent.HasHandsUp() && currentParent.IsAlive())
				return false;
			else
				return true;
		}

		return true;
	}
}