/*modded class Hologram
{
	override string ProjectionBasedOnParent()
	{
		ItemBase item_in_hands = ItemBase.Cast( m_Player.GetHumanInventory().GetEntityInHands() );

		if ( item_in_hands.IsInherited( coda_sleepingbagpacked_black ))
		{
			return "coda_sleepingbag_black";
		}

		return super.ProjectionBasedOnParent();

	}

	override void EvaluateCollision(ItemBase action_item = null)
	{	
		ItemBase item_in_hands = ItemBase.Cast( m_Player.GetHumanInventory().GetEntityInHands() );
		
		if(item_in_hands)
		{
			 if ( item_in_hands.IsInherited( coda_sleepingbagpacked_black ))
			{
				SetIsColliding(false);
				return;
			}
		}
		super.EvaluateCollision();
	}
};*/