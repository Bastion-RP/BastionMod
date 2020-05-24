modded class AnimalBase
{
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