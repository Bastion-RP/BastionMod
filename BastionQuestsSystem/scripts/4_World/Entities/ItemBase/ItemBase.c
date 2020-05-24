modded class ItemBase
{
	private int		UnicID;

	void ItemBase()
	{
		UnicID = -1;
		RegisterNetSyncVariableInt("UnicID");
	}

	void SetQuestNPC(int id)
	{
		SetAllowDamage(false);
		UnicID = id;
		SetSynchDirty();
	}

	int GetQuestID()
	{
		return UnicID;
	}

	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionInteractQuestItemNPC);
	}
}