modded class ActionUnrestrainTarget: ActionContinuousBase
{
	override void OnFinishProgressServer( ActionData action_data )
	{	
		PlayerBase player_target = PlayerBase.Cast(action_data.m_Target.GetObject());
		PlayerBase player_source = PlayerBase.Cast(action_data.m_Player);
		
		EntityAI unrestraining_tool = action_data.m_MainItem;
		EntityAI restraining_item = player_target.GetItemInHands();

		player_target.SetRestrained(false);
		MiscGameplayFunctions.TransformRestrainItem(restraining_item, unrestraining_tool, player_source, player_target);

		RestrainingToolLocked m_item = RestrainingToolLocked.Cast(restraining_item)
		string NewItem = m_item.NonLockedItem();
		
		restraining_item.Delete();
		player_source.GetInventory().CreateInInventory( NewItem );

		action_data.m_Player.GetSoftSkillsManager().AddSpecialty( m_SpecialtyWeight );
	}
};

modded class RestrainingToolLocked extends ItemBase
{
	string NonLockedItem()
	{
		return "WoodenPlank";
	}
};

modded class HandcuffsLocked extends RestrainingToolLocked
{
	override string NonLockedItem()
	{
		return "Handcuffs";
	}
};

modded class RopeLocked extends RestrainingToolLocked
{
	override string NonLockedItem()
	{
		return "Rope";
	}
};

modded class DuctTapeLocked extends RestrainingToolLocked
{
	override string NonLockedItem()
	{
		return "";
	}
};

modded class MetalWireLocked extends RestrainingToolLocked
{
	override string NonLockedItem()
	{
		return "MetalWire";
	}
};

modded class BarbedWireLocked extends RestrainingToolLocked
{
	override string NonLockedItem()
	{
		return "BarbedWire";
	}
};
