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

	override void EEKilled( Object killer )
    {
        PlayerBase v_Killer;
        if (killer)
        {
            if (killer.IsInherited(SurvivorBase))
            {
                v_Killer = PlayerBase.Cast(killer);
                if (v_Killer && v_Killer.GetPersonalQuestManager())
				{
					v_Killer.GetPersonalQuestManager().KilledSomething(this);
				}
            }
            else
            {
                EntityAI wb = EntityAI.Cast(killer);
                if (wb)
                {
                    v_Killer = PlayerBase.Cast(wb.GetHierarchyRootPlayer());
                    if (v_Killer && v_Killer.GetPersonalQuestManager())
					{
						v_Killer.GetPersonalQuestManager().KilledSomething(this);
					}
                }
            }
        }
        super.EEKilled(killer);
    }
}