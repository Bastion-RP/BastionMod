modded class Hologram
{
	override void EvaluateCollision(ItemBase action_item = null)
    {
		ItemBase item_in_hands = ItemBase.Cast(m_Player.GetHumanInventory().GetEntityInHands());
		
		if (item_in_hands.IsInherited(BRP_BarrelTableCactus))
        {
            SetIsColliding(false);
            return;
        }
		
        super.EvaluateCollision();
    }
}
