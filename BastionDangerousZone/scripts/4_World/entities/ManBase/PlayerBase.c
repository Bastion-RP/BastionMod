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
	private ref array<string>m_Suits = {"BRP_Gasmask","NBCHoodBase","NBCJacketBase","NBCGloves_ColorBase","NBCPantsBase","NBCBootsBase"};
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
			//GetDZLogger().LogInfo("RadPills" + GetSingleAgentCount(DZAgents.RADSICK).ToString());
			return;
		}
		else
		{
			//GetDZLogger().LogInfo("NO RadPills" + GetSingleAgentCount(DZAgents.RADSICK).ToString());
			GetSymptomManager().QueueUpPrimarySymptom(SymptomIDs.SYMPTOM_COUGH);
			InsertAgent(DZAgents.RADSICK,NbSickGivenForRadiation);
		}
	}

	void GiveHazardSickness()
	{
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
			}
		}
	}

	void SetSuitsDamageForRad(float damage)
	{
		for(int i=0;i<m_Nbc_Health.Count();i++)
		{
			SuitsDamage.Insert((m_Nbc_Health.Get(i)*damage)/100);
			//Print("NBC: "+ m_Nbc_Health.Get(i).ToString());
			//Print("damage: "+ damage.ToString());
			//Print("DamageFinal: "+ SuitsDamage.Get(i).ToString());
		}
	}

	void SetSuitsDamageForHazard(float damage)
	{
		for(int i=0;i<m_Nbc_Health.Count();i++)
		{
			SuitsDamageHazard.Insert((m_Nbc_Health.Get(i)*damage)/100);
			//Print("NBC: "+ m_Nbc_Health.Get(i).ToString());
			//Print("damage: "+ damage.ToString());
			//Print("DamageFinal: "+ SuitsDamage.Get(i).ToString());
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
					return;
				}
				else
				{
					if (SuitsPart != NULL && !SuitsPart.IsRuined())
					{
						if(i!=0)
						{
							SuitsPart.AddHealth( "", "", -SuitsDamage.Get(i));
							continue;
						}

						if(i == 0 && !SuitsPart.GetCompEM().IsWorking())
						{
							IsUnprotected=true;
							GiveRadSickness();
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
					return;
				}
				else
				{
					if (SuitsPart != NULL && !SuitsPart.IsRuined())
					{
						if(i!=0)
						{
							SuitsPart.AddHealth( "", "", -SuitsDamage.Get(i));
							continue;
						}

						if(i == 0 && !SuitsPart.GetCompEM().IsWorking())
						{
							IsUnprotected=true;
							SetLowLevelEffetOnPlayer();
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
	}
}
