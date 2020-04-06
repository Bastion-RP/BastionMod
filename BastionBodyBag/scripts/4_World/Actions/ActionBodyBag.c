class ActionBodyBagCB : ActionSkinningCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime( UATimeSpent.SKIN );
	}
};

class ActionBodyBag: ActionSkinning
{
	override string GetText()
	{
		return "Place in body bag";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{	
		Object targetObject = target.GetObject();
		if ( targetObject != NULL )
		{
			if ( targetObject.CanBeSkinned() && !targetObject.IsAlive() )
			{
				EntityAI target_EAI;
				Class.CastTo(target_EAI,  targetObject );
				
				if (!GetGame().IsServer()) // Temporal hackfix for skinning not working in multiplayer. Waiting for DAYZ-28269 to be resolved.
					return true;
				
                string type = item.GetType();
                type.ToLower();

                string bodybag = BastionBodyBagConst.bodyBagKitItem;
                bodybag.ToLower();

				if ( type == bodybag )
					return true;
			}
		}

		return false;
	}

	override void OnFinishProgressServer( ActionData action_data )
	{
		Object targetObject = action_data.m_Target.GetObject();
		
		// Mark the body as skinned to forbid another skinning action on it
		EntityAI body;
		Class.CastTo( body,  targetObject );
		vector body_pos = body.GetPosition();
		body.SetAsSkinned();
		
        GetGame().ObjectDelete(body);

		ItemBase added_item;
		Class.CastTo(added_item,  GetGame().CreateObject( BastionBodyBagConst.bodyBagItem, body_pos, false ) );
		added_item.PlaceOnSurface();
	}
};