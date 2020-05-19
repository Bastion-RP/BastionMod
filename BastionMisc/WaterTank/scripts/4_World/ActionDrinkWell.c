modded class ActionDrinkWellContinuous: ActionContinuousBase
{	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{	
		if( target.GetObject() && target.GetObject().IsWell() )
		{            
            if(target.GetObject().IsKindOf("BRP_WaterTank2"))
            {
                string selection = target.GetObject().GetActionComponentName(target.GetComponentIndex());
                return selection.Contains("valve");            
            }
        
			return true;
		}	
			
		return super.ActionCondition(player,target,item);
	}
};