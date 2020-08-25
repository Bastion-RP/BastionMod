class InsideDZ {

	string DZName;
	int DZType; //0:UNUSED - 1:UNUSED - 2: HIGH LEVEL RAD - 3: HAZARD ZONE
	bool DZStatut;

	void InsideDZ() {
		DZName = "";
		DZType = 0;
		DZStatut = false;
	}

}

modded class PlayerBase extends ManBase {
	private ref array<string> m_SLOTS = { "Headgear", "Body", "Gloves", "Legs", "Feet" };
	private ref array<string> m_Suits = { "NBCHoodBase", "NBCJacketBase", "NBCGloves_ColorBase", "NBCPantsBase", "NBCBootsBase" };
	ref array<string> m_SLOTS_ALL = { "Head", "Shoulder", "Melee", "Headgear", "Mask", "Eyewear", "Hands", "LeftHand", "Gloves", "Armband", "Vest", "Body", "Back", "Hips", "Legs", "Feet" };
	private ref array<int> m_Nbc_Health = { 100, 100, 100, 30, 100, 70 };
	private ref array<float> SuitsDamage;
	private ref array<float> SuitsDamageHazard;
	private int cpt = 0;
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
	float AmountGivenAfterCriticalProtection;
	int CriticalProtection;
	int NbSickGivenForRadiation;
	int NbSickGivenForHazard;
	float GasMask_Protection;
	float ClothesQuantityMultiplier;

	private int val = 0;

	override void Init() {
		super.Init();
		IsUnprotected = false;
		AntiRadPillsActivated = false;
		IsInside = new ref InsideDZ;
		SuitsDamage = new ref array<float>;
		SuitsDamageHazard = new ref array<float>;

		if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) {
			DayzPlayerItemBehaviorCfg toolsOneHanded = new DayzPlayerItemBehaviorCfg;
			toolsOneHanded.SetToolsOneHanded();

			DayzPlayerItemBehaviorCfg heavyItemBehaviour = new DayzPlayerItemBehaviorCfg;
			heavyItemBehaviour.SetHeavyItems();

			//Geiger Counter
			GetDayZPlayerType().AddItemInHandsProfileIK("BRP_Dosimeter", "dz/anims/workspaces/player/player_main/props/player_main_1h_torch.asi", toolsOneHanded, "dz/anims/anm/player/ik/gear/chemlight.anm");
			//Shower Kit
			GetDayZPlayerType().AddItemInHandsProfileIK("BRP_ShowerKit", "dz/anims/workspaces/player/player_main/player_main_heavy.asi", heavyItemBehaviour, "dz/anims/anm/player/ik/heavy/wooden_crate.anm");
		}
	}

	//not used since rework
	private void SendMessageClient(string message) {
		Param1<string> m_MesParam = new Param1<string>(message);
		GetGame().RPCSingleParam(this, ERPCs.RPC_USER_ACTION_MESSAGE, m_MesParam, true, this.GetIdentity());
	}

	void GiveRadSickness(int NbSickGiven) {
		if (AntiRadPillsActivated == false) {
			InsertAgent(DZAgents.RADSICK, NbSickGiven);
#ifdef DZDEBUG
			GetDZLogger().LogInfo(this.GetIdentity().GetName() + " no_pills " + "is taking radiation point" + GetSingleAgentCount(DZAgents.RADSICK).ToString());
#endif
		} else {
			m_AgentPool.SetAgentCount(DZAgents.RADSICK, 150);
#ifdef DZDEBUG
			GetDZLogger().LogInfo(this.GetIdentity().GetName() + " with_anti_rad_pills " + "is taking radiation point" + GetSingleAgentCount(DZAgents.RADSICK).ToString());
#endif
			return;
		}
	}

	void SetRadPoint(int value) {
		m_AgentPool.SetAgentCount(DZAgents.RADSICK, value);
#ifdef DZDEBUG
		GetDZLogger().LogInfo(this.GetIdentity().GetName() + "Rad Set value : " + value.ToString());
#endif
		return;
	}

	void GiveHazardSickness() {
#ifdef DZDEBUG
		GetDZLogger().LogInfo(this.GetIdentity().GetName() + "is taking hazard point" + GetSingleAgentCount(DZAgents.RADSICK).ToString());
#endif
		GetSymptomManager().QueueUpPrimarySymptom(SymptomIDs.SYMPTOM_COUGH);
		InsertAgent(DZAgents.HAZARDSICK, NbSickGivenForHazard);
	}

	override void EEHitBy(TotalDamageResult damageResult, int damageType, EntityAI source, int component, string dmgZone, string ammo, vector modelPos, float speedCoef) {
		super.EEHitBy(damageResult, damageType, source, component, dmgZone, ammo, modelPos, speedCoef);
		if (IsInside.DZStatut == true && IsInside.DZType != 0 && IsHazarded == false) {
			cpt += 1;
			if (cpt == 5) {
				cpt = 0;

				/* if (IsInside.DZType == 2) {
					HighLevelRadiationCheckLite();
					return;
				} */

				if (IsInside.DZType == 3) {
					GasMaskHazardCheck();
					return;
				}
#ifdef DZDEBUG
				GetDZLogger().LogInfo(this.GetIdentity().GetName() + "has been attacked 5 times in a zone so recheck is applied");
#endif
			}
		}
	}

	void SetSuitsDamageForRad(float damage) {
		for (int i = 0; i < m_Nbc_Health.Count(); i++) {
			SuitsDamage.Insert((m_Nbc_Health.Get(i) * damage) / 100);
		}
	}

	void SetSuitsDamageForHazard(float damage) {
		for (int i = 0; i < m_Nbc_Health.Count(); i++) {
			SuitsDamageHazard.Insert((m_Nbc_Health.Get(i) * damage) / 100);
		}
	}

	void RadCheck() {
		float maskProtection = HighLevelRadiationCheck();

		if (IsUnprotected) {
			GiveRadSickness(NbSickGivenForRadiation);
		} else {
			GiveRadSickness(NbSickGivenForRadiation * (1 - maskProtection));
		}
	}

	float HighLevelRadiationCheck() {
		if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) { return 0; }
		EntityAI wearingMask = FindAttachmentBySlotName("Mask");
		Print("[RAD ZONE DEBUG] Found gasmask=" + wearingMask.GetType());
		float maskProtection = 0;
		
		if (wearingMask && (wearingMask.IsKindOf("GP5GasMask") || wearingMask.IsKindOf("BRP_GasMask"))) {
			Print("[RAD ZONE DEBUG] Gasmask exists and is proper type");
			if (!wearingMask.GetCompEM().IsWorking()) {
				Print("[RAD ZONE DEBUG] No filter, unprotected");
				IsUnprotected = true;
			} else {
				maskProtection = GetProtectionLevel(wearingMask);
				Print("[RAD ZONE DEBUG] Filter found, protection level=" + maskProtection);
			}
		}
		return maskProtection;
	}

	void GiveRadQtyToPlayerClothes() {
		if (GetGame().IsServer()) {
			for (int i = 0; i < m_SLOTS_ALL.Count(); i++) {
				EntityAI Clothes;
				Clothes = FindAttachmentBySlotName(m_SLOTS.Get(i));

				if (Clothes != NULL && !Clothes.IsRuined()) {
					HandleRadAgentsOnClothesWhileInRadZone(ItemBase.Cast(Clothes));
					continue;
				}
			}
		}
	}

	float GetProtectionLevel(EntityAI attch) {
		GasMask_Protection = GetGame().ConfigGetFloat("CfgVehicles " + attch.GetType() + " Protection biological");
		Print("[RAD ZONE DEBUG] Grabbed protection level!!! " + GasMask_Protection);
		return GasMask_Protection;
	}

	void GasMaskHazardCheck() {
		if (GetGame().IsServer()) {
			if (IsHazarded == true) return;
			EntityAI SuitsPart;
			SuitsPart = this.FindAttachmentBySlotName(m_SLOTS.Get(0));

			if (SuitsPart == NULL || SuitsPart.IsRuined() || !SuitsPart.IsKindOf(m_Suits.Get(0))) {
				GiveHazardSickness();
#ifdef DZDEBUG
				GetDZLogger().LogInfo(this.GetIdentity().GetName() + "'s item on the mask slot doesn't protected for HazardZone");
#endif
				GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(this.GasMaskHazardCheck, 10000);
				return;
			} else {
				if (SuitsPart != NULL && !SuitsPart.IsRuined()) {
					if (!SuitsPart.GetCompEM().IsWorking()) {
						GiveHazardSickness();
#ifdef DZDEBUG
						GetDZLogger().LogInfo(this.GetIdentity().GetName() + "'s gasmask is not working (no filter?) for HazardZone");
#endif
						GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(this.GasMaskHazardCheck, 10000);
						return;
					}
					SuitsPart.AddHealth("", "", -SuitsDamageHazard.Get(0));
				}
			}
		}
	}

	void GasMaskHazardCheckLite() {
		if (GetGame().IsServer()) {
			if (IsHazarded == true) return;
			EntityAI SuitsPart;
			SuitsPart = this.FindAttachmentBySlotName(m_SLOTS.Get(0));

			if (SuitsPart == NULL || SuitsPart.IsRuined() || !SuitsPart.IsKindOf(m_Suits.Get(0))) {
				GiveHazardSickness();
#ifdef DZDEBUG
				GetDZLogger().LogInfo(this.GetIdentity().GetName() + "'s item on the mask slot doesn't protected for HazardZone");
#endif
				GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(this.GasMaskHazardCheck, 10000);
				return;
			}
		}
	}

	void IsHazardProtected() {
		if (!IsUnprotected) {
			return;
		} else {
#ifdef DZDEBUG
			GetDZLogger().LogInfo(this.GetIdentity().GetName() + "is checked again because he was not protected last check");
#endif
			GasMaskHazardCheckLite();
		}
	}

	override void EEItemAttached(EntityAI item, string slot_name) {
		super.EEItemAttached(item, slot_name);
		if (IsInside.DZStatut == true && IsInside.DZType == 2) {
			//HighLevelRadiationCheckLite();
			HandleRadAgentsOnClothesWhileInRadZone(item);
		} else HandleRadAgentsOnClothes(item);

		if (IsInside.DZStatut == true && IsHazarded == false && IsInside.DZType == 3) {
			GasMaskHazardCheckLite();
		}

#ifdef DZDEBUG
		GetDZLogger().LogInfo("item: " + item.GetType() + "slot_name: " + slot_name);
		GetDZLogger().LogInfo("player attached one parts of clothes from his body, need to check if the player is still protect");
#endif
	}

	void HandleRadAgentsOnClothesWhileInRadZone(EntityAI item) {
		ItemBase item_IB = ItemBase.Cast(item);
		if (NbSickGivenForRadiation * ClothesQuantityMultiplier > item_IB.GetRadAgentQuantity()) {
			item_IB.InjectRadAgent(NbSickGivenForRadiation * ClothesQuantityMultiplier);
		} else {
			GiveRadSickness(NbSickGivenForRadiation * ClothesQuantityMultiplier);
		}
	}

	void HandleRadAgentsOnClothes(EntityAI item) {
		ItemBase item_IB = ItemBase.Cast(item);
		if (item_IB.GetRadAgentQuantity() > 0) {
			GiveRadSickness(item_IB.GetRadAgentQuantity());
		}
	}

	override void EEItemDetached(EntityAI item, string slot_name) {
		super.EEItemDetached(item, slot_name);
		// no no no no no no no
		/* if (IsInside.DZStatut == true && IsInside.DZType == 2) {
			HighLevelRadiationCheckLite();
#ifdef DZDEBUG
			GetDZLogger().LogInfo("item: " + item.GetType() + "slot_name: " + slot_name);
			GetDZLogger().LogInfo("player removed one parts of clothes from his body, need to check if the player is still protect");
#endif
		} */

		if (IsInside.DZStatut == true && IsHazarded == false && IsInside.DZType == 3) {
			GasMaskHazardCheckLite();
#ifdef DZDEBUG
			GetDZLogger().LogInfo("item: " + item.GetType() + "slot_name: " + slot_name);
			GetDZLogger().LogInfo("player removed one parts of clothes from his body, need to check if the player is still protect");
#endif
		}

	}
}