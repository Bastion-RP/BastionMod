class DZCrateSystem
{
	private EntityAI m_Loot=NULL;
	private ref array<EntityAI> m_LootList;
	private ref array<Object> DeadWolfObjs;

    void DZCrateSystem()
    {
		GetDZLogger().LogInfo("CrateSystem - Started !");

		DeadWolfObjs = new array<Object>;
		m_LootList = new array<EntityAI>;

		if ( GetGame().IsServer() ) {
			GetGame().GetMission().MissionScript.Call( this, "LootSpawner", null );
		}
    }

	void ~DZCrateSystem()
    {

    }

	void LootSpawner()
	{
		while(1)
		{
			GetDZLogger().LogInfo("LootSpawner - Started !");
			CheckDeadWolfStatus();
			CheckCrateListStatus();
			for( int i=0;i<GetCrateSystemConfig().AreaLocation.Count();i++)
			{
				GetDZLogger().LogInfo("NumberOfCratePerTime: " + GetCrateSystemConfig().AreaLocation.Get(i).DZNbCrate.ToString());
				for(int j=0; j< GetCrateSystemConfig().AreaLocation.Get(i).DZNbCrate; j++)
				{
					int fin=-1+GetCrateSystemConfig().AreaLocation.Get(i).CrateLocation.Count();
					int WhichZone=Math.RandomIntInclusive(0,fin);
					ref DZ_CSArea DZAr = GetCrateSystemConfig().AreaLocation.Get(i);
					CreateEzDrop(DZAr.CrateLocation.Get(WhichZone).DZMaxLoot,DZAr.CrateLocation.Get(WhichZone).DZContainer,DZAr.CrateLocation.Get(WhichZone).POS, DZAr.CrateLocation.Get(WhichZone).ORI,DZAr.DZNbCreature,DZAr.CrateLocation.Get(WhichZone).Name,DZAr.DZCreature);
				}
			}
			Sleep(GetCrateSystemConfig().TimerLoot);
		}
	}

	void CreateEzDrop(int maxloot, string container_name,vector v, vector o,int nbwolf, string name, string creature)
	{
		int k,temp;
		if(v[1]==0)v[1]=GetGame().SurfaceY(v[0], v[2]);
		m_Loot = EntityAI.Cast(GetGame().CreateObject( container_name, v, false, true, true));
		m_Loot.SetOrientation(o);
		m_LootList.Insert(m_Loot);
		GetDZLogger().LogInfo("[LOOTSYSTEM]: CrateSystem2Spawned:"+" CrateName: "+ name + "- Position: X:"+v[0].ToString()+" Y:"+v[1].ToString()+" Z:"+v[2].ToString());
		int count=-1+GetCrateSystemConfig().ListLoots.Count();
		for(int i=0; i<=count;i++)
		{
			if(GetCrateSystemConfig().ListLoots.Get(i).Name==name){
				k=i;
			}
		}
		for(int l=0;l<GetCrateSystemConfig().ListLoots.Get(k).Loots.Count();l++)
		{
			if(temp>=maxloot && maxloot!=-1)continue;
			if ( GetCrateSystemConfig().ListLoots.Get(k).Loots.Get(l).ProbToSpawn > Math.RandomFloatInclusive(0,1) )
			{
				if (GetCrateSystemConfig().ListLoots.Get(k).Loots.Get(l).AttachmentsToLoot.Count() == 0)
				{
					m_Loot.GetInventory().CreateInInventory(GetCrateSystemConfig().ListLoots.Get(k).Loots.Get(l).LootName);
					temp+=1;
					GetDZLogger().LogInfo(GetCrateSystemConfig().ListLoots.Get(k).Loots.Get(l).LootName);
					continue;
				}
				else
				{
					m_Loot.GetInventory().CreateInInventory(GetCrateSystemConfig().ListLoots.Get(k).Loots.Get(l).LootName);
					temp+=1;
					GetDZLogger().LogInfo(GetCrateSystemConfig().ListLoots.Get(k).Loots.Get(l).LootName);
					for( int parc=0; parc < GetCrateSystemConfig().ListLoots.Get(k).Loots.Get(l).AttachmentsToLoot.Count() ; parc++)
					{
						if ( GetCrateSystemConfig().ListLoots.Get(k).Loots.Get(l).AttachmentsToLoot.Get(parc).ProbAttachToSpawn > Math.RandomFloatInclusive(0,1) )
						{
							m_Loot.GetInventory().CreateInInventory(GetCrateSystemConfig().ListLoots.Get(k).Loots.Get(l).AttachmentsToLoot.Get(parc).AttachName);
							temp+=1;
							GetDZLogger().LogInfo(GetCrateSystemConfig().ListLoots.Get(k).Loots.Get(l).AttachmentsToLoot.Get(parc).AttachName);
						}
					}
				}
			}
		}
		if(nbwolf!=0)
		{
			GetDZLogger().LogInfo(nbwolf.ToString() + " " + creature + " spawned around the crate");
		}
		for(int j=0;j<nbwolf;j++)
		{
			vector offset = v;
			offset[0] = offset[0] + Math.RandomIntInclusive(-20,20);
			offset[2] = offset[2] + Math.RandomIntInclusive(-20,20);
			Object Wolf=GetGame().CreateObject(creature, snapToGround(offset), false, true);
			DeadWolfObjs.Insert(Wolf);
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

	void CheckDeadWolfStatus()
	{
		GetDZLogger().LogInfo("CheckCreatureStatus Started !");
		if(DeadWolfObjs.Count() == 0){
			GetDZLogger().LogInfo("Object:Creature equal to 0!");
            return;
        }
		else
		{
			for(int i = 0; i < DeadWolfObjs.Count(); i++){
				if(DeadWolfObjs.Get(i)!=NULL){
					GetGame().ObjectDelete(DeadWolfObjs.Get(i));
					GetDZLogger().LogInfo("Object:Creature deleted!");
				}
			}
			DeadWolfObjs.Clear();
			return;
		}

	}

	void CheckCrateListStatus()
	{
		GetDZLogger().LogInfo("[LOOTSYSTEM]: [CrateCleaner] !");
		if(m_LootList.Count() == 0){
			GetDZLogger().LogInfo("[LOOTSYSTEM]: CrateList equal to 0!");
            return;
        }
		else
		{
			for(int i = 0; i < m_LootList.Count(); i++){
				if(m_LootList.Get(i)!=NULL){
					GetGame().ObjectDelete(m_LootList.Get(i));
					GetDZLogger().LogInfo("[LOOTSYSTEM]: CrateList has been deleted!");
				}
			}
			m_LootList.Clear();
			return;
		}

	}
}
