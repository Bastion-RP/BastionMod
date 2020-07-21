class ActionBRPDismantleItemCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime( 60 );
	}
};

class ActionBRPDismantleItem: ActionContinuousBase
{
	void ActionBRPDismantleItem()
	{
		m_CallbackClass = ActionBRPDismantleItemCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_INTERACT;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH;
		
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_HIGH;
	}
	
	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTNonRuined( UAMaxDistances.BASEBUILDING );
	}

	override string GetText()
	{
		PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
		if ( player )
		{
			return "Dismantle";
		}
		
		return "";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{	
		Object targetObject = target.GetObject();
		if ( targetObject )
		{				
			ItemBase myItem = ItemBase.Cast( targetObject );
			if(myItem){
				if(!myItem.IsInvEmpty()) return false;				
				if (myItem.IsInherited(BRP_Item) || myItem.IsInherited(BRP_Openable_Base)  || myItem.IsInherited(BRP_Furnace_Fireplace))								
					return true;
			}

			BRP_BoxingRing ring = BRP_BoxingRing.Cast( targetObject );
			if(ring)
				return true;

		}
		return false;
	}
		
	override void OnFinishProgressServer( ActionData action_data ) 
	{
		vector pos = action_data.m_Player.GetPosition();
		string name = "";
		ItemBase myItem = ItemBase.Cast( action_data.m_Target.GetObject() );
		if(myItem)
		{
			name = myItem.Get_KitName();
			myItem.Delete();
		}

		BRP_BoxingRing ring = BRP_BoxingRing.Cast( action_data.m_Target.GetObject() );
		if(ring)
		{
			name = ring.Get_KitName();
			ring.Delete();
		}
		//add damage to tool
		action_data.m_MainItem.DecreaseHealth( 5, false );
		
		//return materials			
		ItemBase.Cast( GetGame().CreateObject(name, pos) );
		return;	
	}
	
}