modded class GP5GasMask extends ClothingBase
{
	static float 			  m_WorkingTimePerPills=60;
	protected bool 			m_CanStart;
	protected bool 			m_IsFilter;

	void GP5GasMask()
	{
		if ( m_WorkingTimePerPills == 0)
		{
			string cfg_path = "CfgVehicles " + GetType();
			m_WorkingTimePerPills = GetGame().ConfigGetFloat( cfg_path + "WorkingTimePerPills" );
		}
	}

	void ~GP5GasMask()
	{
		PlayerBase player;
		Class.CastTo(player, GetHierarchyRootPlayer());
		if( player )
		{
			MutePlayer(player,false);
		}
	}

	override bool CanPutAsAttachment( EntityAI parent )
	{
		if(!super.CanPutAsAttachment(parent)) {return false;}
		bool headgear_present = false;

		if ( parent.FindAttachmentBySlotName( "Headgear" ) )
		{
			headgear_present = parent.FindAttachmentBySlotName( "Headgear" ).ConfigGetBool( "noMask" );
		}

		if ( ( GetNumberOfItems() == 0 || !parent || parent.IsMan() ) && !headgear_present )
		{
			return true;
		}
		return false;
	}

	override void OnWasAttached(EntityAI parent, int slot_id)
	{
		super.OnWasAttached(parent,slot_id);

		PlayerBase player;
		Class.CastTo(player, parent.GetHierarchyRootPlayer());

		if ( player && slot_id == InventorySlots.MASK )
		{
			MutePlayer(player,true);
			m_CanStart=true;

			EntityAI m_item = this.FindAttachmentBySlotName("GasMaskFilter");
			if( m_item )
			{
				CanStartGasMask(m_item, "GasMaskFilter");
			}
		}
	}

	override void OnWasDetached(EntityAI parent, int slot_id)
	{
		super.OnWasDetached(parent,slot_id);

		PlayerBase player = PlayerBase.Cast(parent);

		if ( player )
		{
			MutePlayer(player,false);
			m_CanStart=false;
			GetCompEM().SwitchOff();
		}
	}

	override void MutePlayer(PlayerBase player, bool state)
	{
		if( GetGame() )
		{
			if (( GetGame().IsServer() && GetGame().IsMultiplayer() ) || ( GetGame().GetPlayer() == player ))
			{
				GetGame().SetVoiceEffect(player, VoiceEffectObstruction, state);
			}
		}
	}

	override bool IsObstructingVoice()
	{
		return true;
	}

	//----------------Filter PART--------------------//

	override bool CanReceiveAttachment(EntityAI attachment, int slotId)
	{
		ItemBase att = ItemBase.Cast(GetInventory().FindAttachment(slotId));
		if (att && att.IsFullQuantity())
			return false;

		return true;
	}

	override bool CanReleaseAttachment (EntityAI attachment)
	{
		if( !super.CanReleaseAttachment( attachment ) )
			return false;
		return !GetCompEM().IsWorking();
	}

	override void EEItemAttached ( EntityAI item, string slot_name )
	{
		super.EEItemAttached( item, slot_name );
		//Print(slot_name);
		CanStartGasMask(item,slot_name);
	}

	void CanStartGasMask(EntityAI item, string slot_name)
	{
		//Check if the server owner put the filter feature on, if not, the gasmask doesn't start

		ItemBase m_filter = ItemBase.Cast(item);
		if(m_filter.GetQuantity() >= 1 && m_CanStart)
		{
			m_filter.AddQuantity(-1);
			GetCompEM().AddEnergy(-1*GetCompEM().GetEnergy() + m_WorkingTimePerPills);
			GetCompEM().SwitchOn();
			//Print("CanStartGasMask: GP5GasMask :"+m_filter.GetQuantity().ToString());
		}

		//Print("m_WorkingTimePerPills"+m_WorkingTimePerPills.ToString());
	}

	override void OnSwitchOn()
	{
		if ( !GetCompEM().HasEnoughStoredEnergy() )
			GetCompEM().SwitchOff();
	}

	override void OnWork ( float consumed_energy )
	{
		if ( GetGame().IsServer() )
		{
			//Print("OnWork GP5: Energy :"+GetCompEM().GetEnergy().ToString());

			//Print("OnWork GP5: Energy :"+GetCompEM().GetEnergy().ToString());
			//Print("OnWork GP5: EnergyUsage :"+GetCompEM().GetEnergyUsage().ToString());
			//Print("OnWork GP5: UpdateInterval :"+GetCompEM().GetUpdateInterval().ToString());

			ConsumeFilter();

			PlayerBase player;
			Class.CastTo(player, GetHierarchyRootPlayer());

			if(player && !player.IsAlive())
			{
				//Print("OnWork : player is dead");
				GetCompEM().SwitchOff();
				return;
			}

			#ifdef DZDEBUG
			if(!player)return;
			GetDZLogger().LogInfo("GasMask_OnWork on"+"player:"+player.GetIdentity().GetName()+"current energy: "+GetCompEM().GetEnergy().ToString());
			#endif
		}
	}

	override void OnWorkStart()
	{
		//Print("OnWorkStart");
	}

	override void OnWorkStop()
	{
		//Print("OnWorkStop");
		PlayerBase player;
		Class.CastTo(player, GetHierarchyRootPlayer());

		if( player && player.IsInside.DZStatut && player.IsInside.DZType == 2)
		{
			player.HighLevelRadiationCheck();
		}

		if( player && player.IsInside.DZStatut && player.IsInside.DZType == 3)
		{
			player.GasMaskHazardCheck();
		}
	}

	void ConsumeFilter()
	{
		ItemBase m_gasmaskfilter = GetGP5GasMaskFilter();

		if (m_gasmaskfilter)
		{
			//Print("ConsumeFilter : m_gasmaskfilter");
			m_gasmaskfilter.AddQuantity(-1);
			GetCompEM().AddEnergy(m_WorkingTimePerPills);
		}
	}

	GP5GasMask_Filter GetGP5GasMaskFilter()
	{
		return GP5GasMask_Filter.Cast(GetAttachmentByType(GP5GasMask_Filter));
	}

}
