class ActionIncinerateBodyBag : ActionInteractBase
{
    BST_Incinerator incinerator;
	void ActionIncinerateBodyBag( )
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
		return "Incinerate Body Bag";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		array<Object> objects = new array<Object>;
		array<CargoBase> proxy_cargos = new array<CargoBase>;
		GetGame().GetObjectsAtPosition(player.GetPosition(), 3, objects, proxy_cargos);

        foreach (auto obj : objects)
        {
            Class.CastTo( incinerator, obj );
            if ( incinerator )
                return true;
        }
		return false;
	}

	override void OnStartServer( ActionData action_data )
	{
        BST_BodyBag_Base body = BST_BodyBag_Base.Cast(action_data.m_Target.GetObject());
        if (body) body.Delete();
        incinerator.StartFire( true );
        incinerator.SetIncinerationFire( FireplaceFireState.NORMAL_FIRE );
	}
}