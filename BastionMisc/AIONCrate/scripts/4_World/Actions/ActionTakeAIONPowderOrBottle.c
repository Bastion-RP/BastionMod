class ActionTakeAIONPowderOrBottle: ActionInteractBase
{
	string m_ToolTipText;
	void ActionTakeAIONPowderOrBottle()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_OPENDOORFW;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_HUDCursorIcon = CursorIcons.CloseDoors;
	}

	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTNone;
	}

	override string GetText()
	{
		return m_ToolTipText;
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if( !target ) return false;

		if(!IsInReach(player, target, UAMaxDistances.DEFAULT)) return false;
		
		BRP_AIONPowder_Crate powdercrate = BRP_AIONPowder_Crate.Cast(target.GetObject());		
		if(powdercrate)
		{
			m_ToolTipText = "Take AION Powder";
			return true;
		}
		
		BRP_AIONBottle_Crate bottlecrate = BRP_AIONBottle_Crate.Cast(target.GetObject());		
		if(bottlecrate)
		{
			m_ToolTipText = "Take AION Bottle";
			return true;
		}
		
		BRP_OIMHat_Crate oimhat = BRP_OIMHat_Crate.Cast(target.GetObject());		
		if(oimhat)
		{
			m_ToolTipText = "Take White Hardhat";
			return true;
		}
		
		BRP_OIMVest_Crate oimvest = BRP_OIMVest_Crate.Cast(target.GetObject());		
		if(oimvest)
		{
			m_ToolTipText = "Take Reflective Vest";
			return true;
		}

		BRP_OIMNCCShirt_Crate nccshirt = BRP_OIMNCCShirt_Crate.Cast(target.GetObject());		
		if(nccshirt)
		{
			m_ToolTipText = "Take Damaged Shirt";
			return true;
		}

		BRP_OIMNCCPants_Crate nccpants = BRP_OIMNCCPants_Crate.Cast(target.GetObject());		
		if(nccpants)
		{
			m_ToolTipText = "Take Damaged Pants";
			return true;
		}

		BRP_AIONBoxes2 boxes = BRP_AIONBoxes2.Cast(target.GetObject());	
		if (boxes)
		{
			m_ToolTipText = "Take AION box";
			return true;
		}
		return false;
	}

	override void OnStartServer( ActionData action_data )
	{		
		vector pos = action_data.m_Player.GetPosition();
		EntityAI item;
		BRP_AIONPowder_Crate powdercrate = BRP_AIONPowder_Crate.Cast(action_data.m_Target.GetObject());
		BRP_AIONBottle_Crate bottlecrate = BRP_AIONBottle_Crate.Cast(action_data.m_Target.GetObject());
		BRP_AIONBoxes2 boxes = BRP_AIONBoxes2.Cast(action_data.m_Target.GetObject());
		BRP_OIMHat_Crate oimhat = BRP_OIMHat_Crate.Cast(action_data.m_Target.GetObject());
		BRP_OIMVest_Crate oimvest = BRP_OIMVest_Crate.Cast(action_data.m_Target.GetObject());
		BRP_OIMNCCShirt_Crate nccshirt = BRP_OIMNCCShirt_Crate.Cast(action_data.m_Target.GetObject());
		BRP_OIMNCCPants_Crate nccpants = BRP_OIMNCCPants_Crate.Cast(action_data.m_Target.GetObject());
		if (powdercrate)
        {
		    item = EntityAI.Cast(GetGame().CreateObject("BRP_AIONPowder", pos));
        }
		else if (bottlecrate)
        {
		    item = EntityAI.Cast(GetGame().CreateObject("BRP_AION_Empty", pos));
        }
		else if (boxes)
		{
			item = EntityAI.Cast(GetGame().CreateObject("BRP_AIONBox_Empty", pos));
		}
		else if (oimhat)
        {
		    item = EntityAI.Cast(GetGame().CreateObject("ConstructionHelmet_White", pos));
        }
		else if (oimvest)
        {
		    item = EntityAI.Cast(GetGame().CreateObject("ReflexVest", pos));
        }
		else if (nccshirt)
        {
		    item = EntityAI.Cast(GetGame().CreateObject("BRP_TTsKOJacket_Civilian", pos));
			item.DecreaseHealthCoef(0.7);
        }
		else if (nccpants)
        {
		    item = EntityAI.Cast(GetGame().CreateObject("BRP_PrisonPants_NCC", pos));
			item.DecreaseHealthCoef(0.7);
        }
		
		if (item)
		{
            if ( !GetGame().IsMultiplayer() )
            {
                action_data.m_Player.PredictiveTakeEntityToHands(item);
            }
            else
            {
                action_data.m_Player.ServerTakeEntityToHands(item);
            }
		}
	}
};