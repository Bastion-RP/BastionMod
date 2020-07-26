/*modded class GasMask extends ClothingBase
{
	static float 			m_WorkingTimePerPills=60;
	protected bool 			m_CanStart;

	void GasMask()
	{
		if ( m_WorkingTimePerPills == 0)
		{
			string cfg_path = "CfgVehicles " + GetType();
			m_WorkingTimePerPills = GetGame().ConfigGetFloat( cfg_path + "WorkingTimePerPills" );
		}
	}

	void ~GasMask()
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

			EntityAI m_item = this.FindAttachmentBySlotName("CharcoalTabTZ");
			if( m_item )
			{
				CanStartGasMask(m_item);
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

	//----------------CHARCOAL TABLETS PART--------------------//

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
		CanStartGasMask(item);
	}

	void CanStartGasMask(EntityAI item)
	{
		//Check if the server owner put the filter feature on, if not, the gasmask doesn't start

		ItemBase charcoaltab = ItemBase.Cast(item);

		//Print("CanStartGasMask: gasmask :"+charcoaltab.GetQuantity().ToString());
		//Print("m_WorkingTimePerPills"+m_WorkingTimePerPills.ToString());
		if(charcoaltab.GetQuantity() >= 1 && m_CanStart)
		{
			charcoaltab.AddQuantity(-1);
			GetCompEM().AddEnergy(-1*GetCompEM().GetEnergy() + m_WorkingTimePerPills);
			GetCompEM().SwitchOn();
		}
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
			//Print("OnWork GasMask: Energy :"+GetCompEM().GetEnergy().ToString());
			//Print("OnWork GasMask: EnergyUsage :"+GetCompEM().GetEnergyUsage().ToString());
			//Print("OnWork GasMask: UpdateInterval :"+GetCompEM().GetUpdateInterval().ToString());
			ConsumeCharcoal();

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
				//Print("OnWork GasMask: !m_CanStart");
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

	void ConsumeCharcoal()
	{
		ItemBase m_CharcoalTablets = GetCharcoalTablets();

		if (m_CharcoalTablets)
		{
			//Print("ConsumeCharcoal : m_CharcoalTablets");
			m_CharcoalTablets.AddQuantity(-1);
			GetCompEM().AddEnergy(m_WorkingTimePerPills);
		}
	}

	CharcoalTablets GetCharcoalTablets()
	{
		return CharcoalTablets.Cast( GetAttachmentByType(CharcoalTablets) );
	}
}
*/
