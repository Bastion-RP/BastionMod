modded class PlayerBase
{
	bool Consume(ItemBase source, float amount, EConsumeType consume_type )
	{
		if( source )
		{
      string type = source.GetType();
      type.ToLower();
      if ( type == "bastionrp_aion" ) {
			  m_PlayerStomach.AddToStomach("BastionRP_AION", amount, 0 , Edible_Base.Cast(source).GetAgents() );
      }
			return true;
		}
		return super.Consume(source, amount, consume_type);
	}
}