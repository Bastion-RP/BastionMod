class ActionBRPUpgradeFurnaceCB : ActionContinuousBaseCB
{
	PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime( UATimeSpent.DEFAULT_CONSTRUCT );
	}
};

class ActionBRPUpgradeFurnace: ActionContinuousBase
{
	protected Object								BRP_FurnaceFireplace_1;
	void ActionBRPUpgradeFurnace()
	{
		m_CallbackClass = ActionBRPUpgradeFurnaceCB;
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
			return "Build Furnace";
		}
		
		return "";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{	
		Object targetObject = target.GetObject();
		BRP_Furnace brpfurnace = BRP_Furnace.Cast( targetObject );
		if ( targetObject )
		{
			if ( brpfurnace && brpfurnace.CanUpgrade(player) && brpfurnace.HasBase() )
			{
				return true;
			}
			return false;
		}
		return false;
	}
		
	override void OnFinishProgressServer( ActionData action_data ) 
	{
		//target existing model
		BRP_Furnace brpfurnace = BRP_Furnace.Cast( action_data.m_Target.GetObject() );
		
		if ( brpfurnace ) 
		{
			//create new model
			vector position = brpfurnace.GetPosition();
			vector orientation = brpfurnace.GetOrientation();
			vector positionOffset = "0.08 0.86 0";
			//vector orientationOffset = "-90 0 0";
			BRP_FurnaceFireplace_1 = GetGame().CreateObject("BRP_FurnaceFireplace", brpfurnace.GetPosition(), false );
			BRP_FurnaceFireplace_1.SetPosition( position + positionOffset );
			BRP_FurnaceFireplace_1.SetOrientation( orientation );
			
			//delete existing model
			brpfurnace.Delete();
			
			//add damage to tool
			action_data.m_MainItem.DecreaseHealth( UADamageApplied.BUILD, false );
		}
		action_data.m_Player.MessageStatus((brpfurnace.GetPosition()-action_data.m_Player.GetPosition()).ToString());
		action_data.m_Player.GetSoftSkillsManager().AddSpecialty( m_SpecialtyWeight );
	}
}
