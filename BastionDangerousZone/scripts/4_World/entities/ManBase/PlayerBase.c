class InsideDZ{

	string DZName;
	int 	 DZType; //0:INFECTEDZONE - 1:LOW LEVEL RAD - 2: HIGH LEVEL RAD - 3: HAZARD ZONE
	bool   DZStatut;


	void InsideDZ(){
		DZName="";
		DZType=0;
		DZStatut=false;
	}

}

modded class PlayerBase extends ManBase
{
	private ref array<string>m_SLOTS = {"Mask","Headgear","Body","Gloves","Legs","Feet"};
	private ref array<string>m_Suits = {"GP5GasMask","NBCHoodBase","NBCJacketBase","NBCGloves_ColorBase","NBCPantsBase","NBCBootsBase"};
	private ref array<int>m_Nbc_Health = {100,100,100,30,100,70};
	private ref array<float>SuitsDamage;
	private ref array<float>SuitsDamageHazard;
	private int cpt=0;
	bool IsIrradied;
	bool IsHazarded;
	bool AntiRadPillsActivated;
	bool IsGasMaskWorking;
	ref InsideDZ IsInside;
	bool IsUnprotected;
	float HazardShockValue;
	float HazardChanceCough;
	float HazardChanceShock;
	float RadChanceVomit;
	float RadChanceBleeding;
	float RadBloodLossDamage;
	float RadHealthDamage;
	float RadHighMultiplier;
	int NbSickGivenForRadiation;
	int NbSickGivenForHazard;


	private int val = 0;

	override void Init()
	{
		super.Init();
		IsUnprotected=false;
		IsIrradied=false;
		AntiRadPillsActivated=false;
		IsInside=new ref InsideDZ;
		SuitsDamage = new ref array<float>;
		SuitsDamageHazard = new ref array<float>;
	}

	private void SendMessageClient(string message)
	{
		Param1<string> m_MesParam = new Param1<string>(message);
		GetGame().RPCSingleParam(this, ERPCs.RPC_USER_ACTION_MESSAGE, m_MesParam, true, this.GetIdentity());
	}

	void GiveRadSickness()
	{
		if(AntiRadPillsActivated == true)
		{
			m_AgentPool.SetAgentCount(DZAgents.RADSICK,150);
			#ifdef DZDEBUG
			GetDZLogger().LogInfo(this.GetIdentity().GetName() + " with_anti_rad_pills "+"is taking radiation point" + GetSingleAgentCount(DZAgents.RADSICK).ToString());
			#endif
			return;
		}
		else
		{
			InsertAgent(DZAgents.RADSICK,NbSickGivenForRadiation);
			#ifdef DZDEBUG
			GetDZLogger().LogInfo(this.GetIdentity().GetName()+" no_pills "+"is taking radiation point" + GetSingleAgentCount(DZAgents.RADSICK).ToString());
			#endif
		}
	}

	void GiveHazardSickness()
	{
		#ifdef DZDEBUG
		GetDZLogger().LogInfo(this.GetIdentity().GetName()+"is taking hazard point" + GetSingleAgentCount(DZAgents.RADSICK).ToString());
		#endif
		GetSymptomManager().QueueUpPrimarySymptom(SymptomIDs.SYMPTOM_COUGH);
		InsertAgent(DZAgents.HAZARDSICK,NbSickGivenForHazard);
	}

	override void EEHitBy(TotalDamageResult damageResult, int damageType, EntityAI source, int component, string dmgZone, string ammo, vector modelPos, float speedCoef)
	{
		super.EEHitBy(damageResult,damageType,source,component,dmgZone,ammo,modelPos,speedCoef);
		if(IsInside.DZStatut==true && IsInside.DZType!=0 && IsIrradied==false && IsHazarded == false )
		{
			cpt+=1;
			if(cpt==5)
			{
				cpt=0;
				if(IsInside.DZType==1)
				{
					LowLevelRadiationCheckLite();
					return;
				}

				if(IsInside.DZType==2)
				{
					HighLevelRadiationCheckLite();
					return;
				}

				if(IsInside.DZType==3)
				{
					GasMaskHazardCheck();
					return;
				}
				#ifdef DZDEBUG
				GetDZLogger().LogInfo(this.GetIdentity().GetName()+"has been attacked 5 times in a zone so recheck is applied");
				#endif
			}
		}
	}

	void SetSuitsDamageForRad(float damage)
	{
		for(int i=0;i<m_Nbc_Health.Count();i++)
		{
			SuitsDamage.Insert((m_Nbc_Health.Get(i)*damage)/100);
		}
	}

	void SetSuitsDamageForHazard(float damage)
	{
		for(int i=0;i<m_Nbc_Health.Count();i++)
		{
			SuitsDamageHazard.Insert((m_Nbc_Health.Get(i)*damage)/100);
		}
	}

	void HighLevelRadiationCheck()
	{
		if (GetGame().IsServer())
		{
			for (int i = 0; i < m_SLOTS.Count();i++)
			{
				EntityAI SuitsPart;
				SuitsPart = this.FindAttachmentBySlotName(m_SLOTS.Get(i));

				if (SuitsPart == NULL || SuitsPart.IsRuined() || !SuitsPart.IsKindOf(m_Suits.Get(i)))
				{
					IsUnprotected=true;
					GiveRadSickness();
					#ifdef DZDEBUG
					GetDZLogger().LogInfo(this.GetIdentity().GetName()+"is not fully protected for High level RadZone");
					#endif
					return;
				}
				else
				{
					if (SuitsPart != NULL && !SuitsPart.IsRuined())
					{
						if(i!=0)
						{
							SuitsPart.AddHealth( "", "", -SuitsDamage.Get(i));
							#ifdef DZDEBUG
							GetDZLogger().LogInfo(this.GetIdentity().GetName()+"is fully protected for High level RadZone, only damage applied on suits");
							#endif
							continue;
						}

						if(i == 0 && !SuitsPart.GetCompEM().IsWorking())
						{
							IsUnprotected=true;
							GiveRadSickness();
							#ifdef DZDEBUG
							GetDZLogger().LogInfo(this.GetIdentity().GetName()+"'s GasMask doesn't have a filter for High level RadZone, only damage applied on suits");
							#endif
							return;
						}
					}
				}
			}
		}
	}

	void HighLevelRadiationCheckLite()
	{
		if (GetGame().IsServer())
		{
			for (int i = 0; i < m_SLOTS.Count();i++)
			{
				EntityAI SuitsPart;
				SuitsPart = this.FindAttachmentBySlotName(m_SLOTS.Get(i));

				if (SuitsPart == NULL || SuitsPart.IsRuined() || !SuitsPart.IsKindOf(m_Suits.Get(i)))
				{
					IsUnprotected=true;
					GiveRadSickness();
					#ifdef DZDEBUG
					GetDZLogger().LogInfo(this.GetIdentity().GetName()+"is not fully protected for High level RadZone");
					#endif
					return;
				}
				else
				{
					if (SuitsPart != NULL && !SuitsPart.IsRuined())
					{
						if(i == 0 && !SuitsPart.GetCompEM().IsWorking())
						{
							IsUnprotected=true;
							GiveRadSickness();
							#ifdef DZDEBUG
							GetDZLogger().LogInfo(this.GetIdentity().GetName()+"'s GasMask doesn't have a filter for High level RadZone, only damage applied on suits");
							#endif
							return;
						}
					}
				}
			}
		}
	}

	void SetLowLevelEffetOnPlayer()
	{
		//SendMessageClient("SetLowLevelEffetOnPlayer");
		float currenthealth = GetHealth("GlobalHealth", "Blood");
		SetHealth("GlobalHealth", "Blood" ,  currenthealth - RadBloodLossDamage );
		currenthealth = GetHealth();
		SetHealth(currenthealth - RadHealthDamage);
	}

	void LowLevelRadiationCheck()
	{
		if (GetGame().IsServer())
		{
			for (int i = 0; i < m_SLOTS.Count();i++)
			{
				EntityAI SuitsPart;
				SuitsPart = this.FindAttachmentBySlotName(m_SLOTS.Get(i));

				if (SuitsPart == NULL || SuitsPart.IsRuined() || !SuitsPart.IsKindOf(m_Suits.Get(i)))
				{
					IsUnprotected=true;
					SetLowLevelEffetOnPlayer();
					#ifdef DZDEBUG
					GetDZLogger().LogInfo(this.GetIdentity().GetName()+"is not fully protected for Low level RadZone");
					#endif
					return;
				}
				else
				{
					if (SuitsPart != NULL && !SuitsPart.IsRuined())
					{
						if(i!=0)
						{
							SuitsPart.AddHealth( "", "", -SuitsDamage.Get(i));
							#ifdef DZDEBUG
							GetDZLogger().LogInfo(this.GetIdentity().GetName()+" is fully protected for Low level RadZone, only damage applied on suits");
							#endif
							continue;
						}

						if(i == 0 && !SuitsPart.GetCompEM().IsWorking())
						{
							IsUnprotected=true;
							SetLowLevelEffetOnPlayer();
							#ifdef DZDEBUG
							GetDZLogger().LogInfo(this.GetIdentity().GetName()+" 's GasMask doesn't have a filter for Low level RadZone, only damage applied on suits");
							#endif
							return;
						}
					}
				}
			}
		}
	}

	void LowLevelRadiationCheckLite()
	{
		if (GetGame().IsServer())
		{
			for (int i = 0; i < m_SLOTS.Count();i++)
			{
				EntityAI SuitsPart;
				SuitsPart = this.FindAttachmentBySlotName(m_SLOTS.Get(i));
				if (SuitsPart == NULL || SuitsPart.IsRuined() || !SuitsPart.IsKindOf(m_Suits.Get(i)))
				{
					IsUnprotected=true;
					SetLowLevelEffetOnPlayer();
					#ifdef DZDEBUG
					GetDZLogger().LogInfo(this.GetIdentity().GetName()+" is not fully protected for Low level RadZone");
					#endif
					return;
				}
				else
				{
					if (SuitsPart != NULL && !SuitsPart.IsRuined())
					{
						if(i == 0 && !SuitsPart.GetCompEM().IsWorking())
						{
							IsUnprotected=true;
							SetLowLevelEffetOnPlayer();
							#ifdef DZDEBUG
							GetDZLogger().LogInfo(this.GetIdentity().GetName()+"'s GasMask doesn't have a filter for High level RadZone, only damage applied on suits");
							#endif
							return;
						}
					}
				}
			}
			IsUnprotected=false;
		}
	}

	void GasMaskHazardCheck()
	{
		if (GetGame().IsServer())
		{
			if(IsHazarded == true)return;
			EntityAI SuitsPart;
			SuitsPart = this.FindAttachmentBySlotName(m_SLOTS.Get(0));

			if (SuitsPart == NULL || SuitsPart.IsRuined() || !SuitsPart.IsKindOf(m_Suits.Get(0)))
			{
				GiveHazardSickness();
				#ifdef DZDEBUG
				GetDZLogger().LogInfo(this.GetIdentity().GetName()+"'s item on the mask slot doesn't protected for HazardZone");
				#endif
				GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater(this.GasMaskHazardCheck, 10000 );
				return;
			}
				else
				{
					if (SuitsPart != NULL && !SuitsPart.IsRuined())
					{
						if(!SuitsPart.GetCompEM().IsWorking())
						{
							GiveHazardSickness();
							#ifdef DZDEBUG
							GetDZLogger().LogInfo(this.GetIdentity().GetName()+"'s gasmask is not working (no filter?) for HazardZone");
							#endif
							GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater(this.GasMaskHazardCheck, 10000 );
							return;
						}
						SuitsPart.AddHealth( "", "", -SuitsDamageHazard.Get(0));
					}
				}
			}
		}

	void IsRadProtected(int x)
	{
		if (!IsUnprotected){
			return;
		}
		else{
			#ifdef DZDEBUG
			GetDZLogger().LogInfo(this.GetIdentity().GetName()+"is checked again because he was not protected last check");
			#endif
			if(x == 1)
			{
				LowLevelRadiationCheckLite();
			}
			else
			{
				HighLevelRadiationCheckLite();
			}
		}
	}

	void IsHazardProtected()
	{
		if (!IsUnprotected){
			return;
		}
		else{
			#ifdef DZDEBUG
			GetDZLogger().LogInfo(this.GetIdentity().GetName()+"is checked again because he was not protected last check");
			#endif
				GasMaskHazardCheck();
		}
	}

	override void EEItemAttached(EntityAI item, string slot_name)
	{
		super.EEItemAttached(item, slot_name);
		//Print("item:"+item.ToString()+"slot:"+slot_name);
		if(IsInside.DZStatut==true && IsInside.DZType==1)
		{
			LowLevelRadiationCheckLite();
		}

		if(IsInside.DZStatut==true && IsInside.DZType==2)
		{
			HighLevelRadiationCheckLite();
		}

		if(IsInside.DZStatut==true && IsHazarded==false && IsInside.DZType==3)
		{
			GasMaskHazardCheck();
		}
		#ifdef DZDEBUG
		GetDZLogger().LogInfo(this.GetIdentity().GetName()+" attached one parts of clothes from his body, need to check if the player is still protect");
		#endif
	}

	override void EEItemDetached(EntityAI item, string slot_name)
	{
		super.EEItemDetached(item, slot_name);
		//Print("item:"+item.ToString()+"slot:"+slot_name);
		if(IsInside.DZStatut==true && IsInside.DZType==1)
		{
			LowLevelRadiationCheckLite();
		}

		if(IsInside.DZStatut==true && IsInside.DZType==2)
		{
			HighLevelRadiationCheckLite();
		}

		if(IsInside.DZStatut==true && IsHazarded==false && IsInside.DZType==3)
		{
			GasMaskHazardCheck();
		}

		#ifdef DZDEBUG
		GetDZLogger().LogInfo(this.GetIdentity().GetName()+" removed one parts of clothes from his body, need to check if the player is still protect");
		#endif
	}
}
