class ActionBRPDismantleFurnaceCB : ActionContinuousBaseCB
{
	PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime( 300 );
	}
};

class ActionBRPDismantleFurnace: ActionContinuousBase
{
	void ActionBRPDismantleFurnace()
	{
		m_CallbackClass = ActionBRPDismantleFurnaceCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_ASSEMBLE;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT;
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
			return "Dismantle Furnace";
		}
		
		return "";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{	
		Object targetObject = target.GetObject();
		BRP_FurnaceFireplace brpfurnacefireplace = BRP_FurnaceFireplace.Cast( targetObject );
		if ( targetObject ) 
		{				
			if ( brpfurnacefireplace )
			{	
                return true;
			}
		}
		return false;
	}
		
	override void OnFinishProgressServer( ActionData action_data ) 
	{
		//target existing model
		BRP_FurnaceFireplace brpfurnacefireplace = BRP_FurnaceFireplace.Cast( action_data.m_Target.GetObject() );
		
		if ( brpfurnacefireplace) 
		{	
			//logging
			PlayerIdentity myIdentity = PlayerIdentity.Cast(action_data.m_Player.GetIdentity());
			Print(myIdentity.GetName()+" dismantled BRP_FurnaceFireplace");
			
			//delete existing model
			brpfurnacefireplace.Delete();
			
			//add damage to tool
			action_data.m_MainItem.DecreaseHealth( UADamageApplied.DESTROY, false );
			
			//return materials
			vector pos = action_data.m_Player.GetPosition();
			ItemBase Re_Kit = ItemBase.Cast( GetGame().CreateObject("BRP_FurnaceKit", pos) );	// Result Class
		}
		action_data.m_Player.MessageStatus((brpfurnacefireplace.GetPosition()-action_data.m_Player.GetPosition()).ToString());
		action_data.m_Player.GetSoftSkillsManager().AddSpecialty( m_SpecialtyWeight );
	}
	
	//setup
	override bool SetupAction( PlayerBase player, ActionTarget target, ItemBase item, out ActionData action_data, Param extra_data = NULL )
	{	
		if( super.SetupAction( player, target, item, action_data, extra_data ) )
		{
			SetBuildingAnimation( item );
			
			return true;
		}
		return false;
	}
	
	void SetBuildingAnimation( ItemBase item )
	{
		switch( item.Type() )
		{
			case Shovel:
			case FieldShovel:
				m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_DIGMANIPULATE;
				break;
			case Pliers:
				m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_INTERACT;
				break;				
			default:
				m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_DISASSEMBLE;
				break;
		}
	}
}
