modded class Grenade_Base extends InventoryItemSuper
{
	PlayerBase m_Player;

	override void Unpin()
	{
		super.Unpin();
		Class.CastTo(m_Player, GetHierarchyRootPlayer());
	}	
}

modded class BRP_RemoteDetonator extends ItemBase
{
	override void AddBomb(BRP_RemoteIED IED)
	{
		super.AddBomb(IED);
		Class.CastTo(IED.m_Player, GetHierarchyRootPlayer());
	}
}

modded class BRP_RemoteIED extends TrapBase
{
	PlayerBase m_Player;
}