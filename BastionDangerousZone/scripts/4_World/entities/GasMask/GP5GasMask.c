modded class BRP_Gasmask extends ClothingBase
{
	static float 			m_WorkingTimePerPills=60;
	protected bool 			m_CanStart;
	protected bool 			m_IsFilter;

	void BRP_Gasmask()
	{
		if ( m_WorkingTimePerPills == 0)
		{
			string cfg_path = "CfgVehicles " + GetType();
			m_WorkingTimePerPills = GetGame().ConfigGetFloat( cfg_path + "WorkingTimePerPills" );
		}
	}

	void ~BRP_Gasmask()
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
		Print(slot_name);
		CanStartGasMask(item,slot_name);
	}

	void CanStartGasMask(EntityAI item, string slot_name)
	{
		//Check if the server owner put the filter feature on, if not, the gasmask doesn't start

		ItemBase m_filter = ItemBase.Cast(item);
		if(m_filter.GetQuantity() >= 61 && m_CanStart)
		{
			m_filter.AddQuantity(-60);
			GetCompEM().AddEnergy(-1*GetCompEM().GetEnergy() + m_WorkingTimePerPills);
			GetCompEM().SwitchOn();
			//Print("CanStartGasMask: BRP_Gasmask :"+m_filter.GetQuantity().ToString());
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

			if(!m_CanStart)
			{
				//Print("OnWork : !m_CanStart");
				GetCompEM().SwitchOff();
			}
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
		if( player && player.IsInside.DZStatut && player.IsInside.DZType == 1)
		{
			player.LowLevelRadiationCheckLite();
		}

		if( player && player.IsInside.DZStatut && player.IsInside.DZType == 2)
		{
			player.HighLevelRadiationCheckLite();
		}

		if( player && player.IsInside.DZStatut && player.IsInside.DZType == 3)
		{
			player.GasMaskHazardCheck();
		}
	}

	void ConsumeFilter()
	{
		ItemBase m_gasmaskfilter = GetBRP_GasmaskFilter();

		if (m_gasmaskfilter)
		{
			//Print("ConsumeFilter : m_gasmaskfilter");
			m_gasmaskfilter.AddQuantity(-60);
			GetCompEM().AddEnergy(m_WorkingTimePerPills);
		}
	}

	BRP_Gasmask_Filter GetBRP_GasmaskFilter()
	{
		return BRP_Gasmask_Filter.Cast(GetAttachmentByType(BRP_Gasmask_Filter));
	}

}
