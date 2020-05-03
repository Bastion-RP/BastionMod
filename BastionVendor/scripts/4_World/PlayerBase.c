modded class PlayerBase
{
	bool Consume(ItemBase source, float amount, EConsumeType consume_type )
	{
		if ( source )
		{
      		string type = source.GetType();
      		type.ToLower();

      		if ( type == "BRP_AION" ) 
			{
				m_PlayerStomach.AddToStomach("BRP_AION", amount, 0 , Edible_Base.Cast(source).GetAgents() );
      		}
		}

		return super.Consume(source, amount, consume_type);
	}
}