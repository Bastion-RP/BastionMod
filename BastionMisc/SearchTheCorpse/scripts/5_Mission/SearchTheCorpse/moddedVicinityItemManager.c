modded class VicinityItemManager
{
	override bool ExcludeFromContainer_Phase1 (Object actor_in_radius)
	{
		bool ret = super.ExcludeFromContainer_Phase1(actor_in_radius);
		if(!ret)
		{
			EntityAI entity_ai;

			if ( !Class.CastTo( entity_ai, actor_in_radius) )
				return true;

			PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());

			if ( entity_ai != player )
			{
				if ( entity_ai.IsMan() )
				{
					PlayerBase analizePlayer = PlayerBase.Cast(entity_ai);
					if(!analizePlayer.IsAlive() || analizePlayer.IsUnconscious() )
					{
						if(analizePlayer.GetDeAIsSearching(PlayerBase.Cast(GetGame().GetPlayer()).GetID()) )
							ret = false;
						else
							ret = true;
					}
				}
				if( entity_ai.IsZombie() || entity_ai.IsZombieMilitary() )
				{
					ZombieBase analizeZombie = ZombieBase.Cast(entity_ai);
					if(!analizeZombie.IsAlive())
					{
						if(analizeZombie.GetDeAIsSearching(PlayerBase.Cast(GetGame().GetPlayer()).GetID()) )
							ret = false;
						else
							ret = true;
					}
				}
			}
		}

		return ret;
	}

	override bool ExcludeFromContainer_Phase2 (Object object_in_radius)
	{
		bool ret = super.ExcludeFromContainer_Phase2(object_in_radius);
		if(!ret)
		{
			EntityAI entity_ai;
			ItemBase item;

			if ( !Class.CastTo( entity_ai, object_in_radius) )
				return true;

			if(entity_ai != PlayerBase.Cast(GetGame().GetPlayer()) )
			{
				if ( entity_ai.IsMan() )
				{
					PlayerBase analizePlayer = PlayerBase.Cast(entity_ai);
					if(!analizePlayer.IsAlive() || analizePlayer.IsUnconscious())
					{
						if(analizePlayer.GetDeAIsSearching(PlayerBase.Cast(GetGame().GetPlayer()).GetID()) )
							ret = false;
						else
							ret = true;
					}
				}
			}
		}
		
		return ret;
	}

	override bool ExcludeFromContainer_Phase3 (Object object_in_cone)
	{
		bool ret = super.ExcludeFromContainer_Phase3(object_in_cone);
		if(!ret)
		{
			EntityAI entity_ai;
			
			if ( !Class.CastTo( entity_ai, object_in_cone) )
				return true;

			PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());

			if ( entity_ai != player )
			{
				if ( entity_ai.IsMan() )
				{
					PlayerBase analizePlayer = PlayerBase.Cast(entity_ai);
					if( !analizePlayer.IsAlive() || analizePlayer.IsUnconscious() )
					{
						if(analizePlayer.GetDeAIsSearching(PlayerBase.Cast(GetGame().GetPlayer()).GetID()) )
							ret = false;
						else
							ret = true;
					}
				}
			}
		}
		

		return ret;
	}
}

modded class ActionTargetsCursor extends ScriptedWidgetEventHandler
{
	protected void SetItemDesc(string descText, int cargoCount, string itemWidget, string descWidget)
	{
		Widget widget;
		widget = m_Root.FindAnyWidget(itemWidget);
		
		//! Last message from finished User Action on target (Thermometer, Blood Test Kit, etc. )
		PlayerBase playerT = PlayerBase.Cast(m_Target.GetObject());
		if (playerT)
			string msg = playerT.GetLastUAMessage();
				
		if(descText.Length() == 0 && msg.Length() == 0)
		{
			widget.Show(false);
			return;
		}
		
		descText.ToUpper();
		TextWidget itemName;
		Class.CastTo(itemName, widget.FindAnyWidget(descWidget));
	
		//! when cargo in container
		/*if (cargoCount > 0)
		{
			descText = string.Format("[+] %1  %2", descText, msg);
			itemName.SetText(descText);		
		}
		else*/
			descText = string.Format("%1  %2", descText, msg);
			itemName.SetText(descText);

		widget.Show(true);
	}
}