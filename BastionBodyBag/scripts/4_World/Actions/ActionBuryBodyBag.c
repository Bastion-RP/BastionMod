class ActionBuryBodyBag: ActionBuryBody
{		
	override string GetText()
	{
		return "#bury";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		BST_BodyBag_Base body_bag;
		Class.CastTo( body_bag, target.GetObject() );

		if ( body_bag )
		{
			string surface_type;
			vector position = body_bag.GetPosition();
			GetGame().SurfaceGetType ( position[0], position[2], surface_type );
			
			if ( GetGame().IsSurfaceDigable(surface_type) )
				return true;
		}

		return false;
	}
};
