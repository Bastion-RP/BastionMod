class ActionSellItem : ActionInteractBase
{
	private string currencyType;
	private string sum = "Sale for ";

	void ActionSellItem()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_ATTACHITEM;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_HUDCursorIcon = CursorIcons.OpenDoors;
	}

	override void CreateConditionComponents()  
	{	
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTObject(UAMaxDistances.BASEBUILDING);
	}

	override typename GetInputType()
	{
		return InteractActionInput;
	}

	override string GetText()
	{
		return sum;
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		ItemBase sellerObj = ItemBase.Cast( target.GetObject() );
		InventoryLocation loc;
		if (!player.GetHumanInventory().GetEntityInHands()) 
			return false;
		if (!sellerObj.IsSeller())
			return false;
		ItemBase plItem = ItemBase.Cast(player.GetHumanInventory().GetEntityInHands());

		string itemType = plItem.GetType();
		currencyType = GetBSTBankingConfigHandler().GetConfig().GetCurrencyClassName();
		sum = "Sale for ";
		int placeholder;
		int price;
		if ( sellerObj && GetGame().IsClient())
		{
			if (GetSellerManager().CanSellItem(itemType, sellerObj.GetType()))
			{
				price = GetSellerManager().GetTotalSum(plItem, placeholder, sellerObj.GetType());
				if (price == 0) return false;
				sum = sum + price;
				return true;
			}
			else
			{
				return false;
			}
		}
		
		return true;
	}

	override void OnStartServer( ActionData action_data )
	{
		ItemBase sellerObj = ItemBase.Cast( action_data.m_Target.GetObject() );
		PlayerBase player = PlayerBase.Cast(action_data.m_Player);
		ItemBase item = ItemBase.Cast(player.GetHumanInventory().GetEntityInHands());

		if (!item) return;

		GetSellerManager().SellItem(item, sellerObj);
	}

	override void OnEndServer( ActionData action_data )
	{
		ItemBase sellerObj = ItemBase.Cast( action_data.m_Target.GetObject() );
		if( sellerObj )
		{
			sellerObj.SoundSynchRemoteReset();
		}
	}
}