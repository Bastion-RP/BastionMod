class Wetsuit_Base: Clothing
{
	PlayerBase m_Player;
	Invisible_Pants m_InvisPants;

	override bool CanPutAsAttachment(EntityAI parent)
	{
		return super.CanPutAsAttachment(parent) && !parent.FindAttachmentBySlotName("Legs");
	}

	override void OnWasAttached(EntityAI parent, int slot_id)
	{
		super.OnWasAttached(parent, slot_id);

		Class.CastTo(m_Player, parent.GetHierarchyRootPlayer());
		if (m_Player.GetInventory()) Class.CastTo(m_InvisPants, m_Player.GetInventory().CreateInInventory("Invisible_Pants"));
	}
	
	override void OnWasDetached(EntityAI parent, int slot_id)
	{
		super.OnWasDetached(parent, slot_id);

		if (m_InvisPants)
		{
			m_InvisPants.Delete();
			m_InvisPants = null;
		}
	}
};

class Invisible_Pants: Clothing
{
	bool IsWetsuitOn(EntityAI parent)
	{
		Wetsuit_Base wetsuit;
		Class.CastTo(wetsuit, parent.FindAttachmentBySlotName("Body"));
		if (wetsuit) return true;
		return false;
	}

	override bool CanPutAsAttachment(EntityAI parent)
	{
		return super.CanPutAsAttachment(parent) && IsWetsuitOn(parent);
	}

	override bool CanDetachAttachment(EntityAI parent)
	{
		return false;
	}

	override void OnWasAttached(EntityAI parent, int slot_id)
	{
		super.OnWasAttached(parent, slot_id);

		if (!IsWetsuitOn(parent)) Delete();
	}

	override void OnWasDetached(EntityAI parent, int slot_id)
	{
		super.OnWasDetached(parent, slot_id);

		Delete();
	}
};

class BRP_Tactical_Jacket_Base: Clothing {};
class BRP_Tactical_Jacket_Tan: BRP_Tactical_Jacket_Base {};
class BRP_Tactical_Jacket_Black: BRP_Tactical_Jacket_Base {};
class BRP_Tactical_Jacket_Woodland_Camo: BRP_Tactical_Jacket_Base {};
class BRP_Tactical_Jacket_Urban_Camo: BRP_Tactical_Jacket_Base {};
class BRP_Tactical_Jacket_DarkGrey_Camo: BRP_Tactical_Jacket_Base {};
class BRP_Tactical_Jacket_Arctic_Camo: BRP_Tactical_Jacket_Base {};