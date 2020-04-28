class ActionCompactBodyBag : ActionInteractBase
{
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

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
        if(!target) 
			return false;
		if (!target.GetObject() || !target.GetObject().IsInherited(BST_Compactor))
			return false;

		BST_Compactor compactor = BST_Compactor.Cast(target.GetObject());
		//getting HumanInventory entity in hands because on server item variable seems to be null
		BST_BodyBag_Base bodybag = BST_BodyBag_Base.Cast(player.GetHumanInventory().GetEntityInHands());		
		if (compactor && bodybag)
		{
			string selection = compactor.GetActionComponentName(target.GetComponentIndex());
			if(selection.Contains("compactoraction"))
				return true;
		}
        return false;
	}

	override void OnStartServer( ActionData action_data )
	{
		PlayerBase player = PlayerBase.Cast(action_data.m_Player);
		BST_BodyBag_Base bodybag = BST_BodyBag_Base.Cast(player.GetHumanInventory().GetEntityInHands());
		if(bodybag)
			bodybag.Delete();
	}
};