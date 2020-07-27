class DZInfectedZone
{
	private ref array<Object> InfectedLists;

	private int m_CheckScheduler;

	private InfectedZoneLocation InfZone;

	private bool MustInfectedRespawn = 1;

	void DZInfectedZone(ref InfectedZoneLocation infzone)
	{
		GetDZLogger().LogInfo("[INFECTEDSYSTEM]:InfectedZone - Started !");

		InfZone = infzone;
		InfectedLists = new array<Object>;

		if ( GetGame().IsServer() ) {
			GetGame().GetMission().MissionScript.Call( this, "CheckScheduler", null );
		}
	}

	void CheckScheduler()
	{
		m_CheckScheduler = GetInfectedConfig().InfectedCheck;
		while(1)
		{
			CheckInfectedStatus();
			InfectedZoneHandler();
			Sleep(m_CheckScheduler);
		}
	}

	void InfectedZoneHandler()
	{
		if(MustInfectedRespawn == 1)
		{
			for(int j=0;j<InfZone.CreatureList.Count();j++)
			{
				int m_stop= -1 + InfZone.CreatureList.Get(j).Max;
				GetDZLogger().LogInfo("[INFECTEDSYSTEM] Spawned: " + InfZone.CreatureList.Get(j).CreatureName + "count: " + InfZone.CreatureList.Get(j).Max.ToString());
				for(int m_k=0;m_k<=m_stop;m_k++)
				{
					vector offset;
					offset[0] = InfZone.X + Math.RandomIntInclusive(-InfZone.Radius,InfZone.Radius);
					offset[2] = InfZone.Y + Math.RandomIntInclusive(--InfZone.Radius,InfZone.Radius);
					string creature = InfZone.CreatureList.Get(j).CreatureName;
					Object tempCreature=GetGame().CreateObject(creature, snapToGround(offset), false, true, true);
					InfectedLists.Insert(tempCreature);
				}
			}
		}
	}

	void CheckInfectedStatus()
	{
		GetDZLogger().LogInfo("[INFECTEDSYSTEM]: [InfectedCleaner] !");
		if(InfectedLists.Count() == 0){
			GetDZLogger().LogInfo("[INFECTEDSYSTEM]: Infected equal to 0!");
            return;
        }
		else
		{
			int infectedcount=0;
			for(int i = 0; i < InfectedLists.Count(); i++){
				if(InfectedLists.Get(i)!=NULL){
					infectedcount++;
				}
			}
			if(infectedcount < InfZone.MinCreature)
			{
				for(int j = 0; j < InfectedLists.Count(); j++){
					if(InfectedLists.Get(j)!=NULL){
						GetGame().ObjectDelete(InfectedLists.Get(j));
						GetDZLogger().LogInfo("[INFECTEDSYSTEM]: Infected has been deleted!");
					}
				}
				InfectedLists.Clear();
				MustInfectedRespawn = 1;
				return;
			}
			MustInfectedRespawn = 0;
			return;
		}
	}

	private vector snapToGround(vector pos)
    {
        float pos_x = pos[0];
        float pos_z = pos[2];
        float pos_y = GetGame().SurfaceY( pos_x, pos_z );
        vector tmp_pos = Vector( pos_x, pos_y, pos_z );
        tmp_pos[1] = tmp_pos[1] + pos[1];

        return tmp_pos;
    }
}
