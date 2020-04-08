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
		vector body_dir = body.GetDirection();
		body.SetAsSkinned();

        GetGame().ObjectDelete(body);
        action_data.m_MainItem.Delete();

        EntityAI entity = action_data.m_Player.SpawnEntityOnGroundPos ( BastionBodyBagConst.bodyBagItem, body_pos );
        entity.SetPosition(body_pos);
        entity.SetDirection(body_dir);
        body_dir = body.GetDirection();
        entity.SetDirection(body_dir);
	}
};