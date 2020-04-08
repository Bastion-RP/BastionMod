class ActionCompactBodyBag : ActionInteractBase
{
	BST_BodyBag_Base body_bag;
	void ActionCompactBodyBag( )
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_ATTACHITEM;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_HUDCursorIcon = CursorIcons.OpenDoors;
	}

	override void CreateConditionComponents( )  
	{	
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTObject(UAMaxDistances.BASEBUILDING);
	}

	override typename GetInputType( )
	{
		return InteractActionInput;
	}

	override string GetText()
	{
		return "Compact Body Bag";
	}

    protected bool FindBodyBag( PlayerBase player )
    {
        array<Object> objects = new array<Object>;
        array<CargoBase> proxy_cargos = new array<CargoBase>;
        GetGame().GetObjectsAtPosition(player.GetPosition(), 3, objects, proxy_cargos);

        foreach (auto obj : objects)
        {
            Class.CastTo( body_bag, obj );
            if ( body_bag )
                return true;
        }
        return false;
    }

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
        return FindBodyBag(player);
	}

	override void OnStartServer( ActionData action_data )
	{
        if ( body_bag || ( action_data.m_Player && FindBodyBag( action_data.m_Player ) ) )
        {
            body_bag.Delete();
        }
	}
}