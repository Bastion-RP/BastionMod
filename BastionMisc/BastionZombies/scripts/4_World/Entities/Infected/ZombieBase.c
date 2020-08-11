modded class ZombieBase {	

    void BRP_Misc_Zombies_DEBUG (string f_Msg) {
		//--- Message to all palyers
        return; // debug disabled
        
        string t_Newmsg = "BRP_Misc_Zombies:ZombieBase. " + f_Msg;
		ref array<Man> t_players = new array<Man>;
		GetGame().GetPlayers(t_players);
		foreach(auto t_player : t_players) {
			Param1<string> t_param_msg = new Param1<string>(t_Newmsg);
			GetGame().RPCSingleParam(t_player, ERPCs.RPC_USER_ACTION_MESSAGE, t_param_msg, true, t_player.GetIdentity());
		};
        
    };
	
	// remove stunning from melee when player has no stamina
	override void EEHitBy(TotalDamageResult damageResult, int damageType, EntityAI source, int component, string dmgZone, string ammo, vector modelPos, float speedCoef) {

		if (!this) {
			return;
		};
		
		// run the parent hitby
		super.EEHitBy(damageResult, damageType, source, component, dmgZone, ammo, modelPos, speedCoef);
		
		if (!damageResult) {
			return;
		};
        
        // zombie code
        BRP_Misc_Zombies_OnEEHitBy(damageResult, damageType, source, component, dmgZone, ammo, modelPos, speedCoef);
		

		// only ccontinue if a damage hit was set to be processed
		if (!m_DamageHitToProcess) {
			return;
		};
		
		// quit if not alive
		if (!IsAlive()) {
			return;
		};
		
		// make sure the source exists
		if (!source) {
			return;
		};

		
		// make sure hit was melee
		if (damageType != DT_CLOSE_COMBAT) {
			return;
		};
		PlayerBase t_PB;

		// test source	(it can also be a knife / weapon
		if (!Class.CastTo(t_PB,source) && !Class.CastTo(t_PB,source.GetHierarchyParent())) {
			return;
		};

		// check if the player has enough stamina for melee
		if (t_PB.GetStaminaHandler().GetStamina() <= GameConstants.STAMINA_DRAIN_MELEE_LIGHT) {
			m_DamageHitToProcess = false;

			// Increase HP by half the damage taken, this makes the total damage taken only half
			float BRP_Misc_Zombies_t_DmgHP = damageResult.GetDamage("","Health");
			AddHealth("","Health",BRP_Misc_Zombies_t_DmgHP * 0.75);


			BRP_Misc_Zombies_DEBUG("Dmg:" + BRP_Misc_Zombies_t_DmgHP + " type:" + damageType);

		};
	};



    
    override void Init() {
        super.Init();

        // time it later
		GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( BRP_Misc_Zombies_Init, 5000, false);
    };


    int BRP_Misc_Zombies_m_ForcedSpeed = -1;
    float BRP_Misc_Zombies_m_HpMod = -1;
    float BRP_Misc_Zombies_m_AtkMod = -1;

    float BRP_Misc_Zombies_GetAtkMod () {
        if (!IsAlive()) {
            return 0.0;
        };
        return BRP_Misc_Zombies_m_AtkMod;
    };

    void BRP_Misc_Zombies_Init() {

        // only run on the server
        if (!GetGame().IsServer()) {
            return;
        };
        

        // select zombie type:
        int t_ZombieType = Math.RandomIntInclusive(1,2);

		//t_ZombieType = 1;
        switch (t_ZombieType) {
            case 0: {
                // NOT ACTIVE
                // normal zombie, sprints like any other
                return;

                break;
            };
            case 1: {
                // walking zombie, increased HP/damage
                BRP_Misc_Zombies_m_ForcedSpeed = 1;
                BRP_Misc_Zombies_m_HpMod = 0.5;		// 50% damage taken
                BRP_Misc_Zombies_m_AtkMod = 4;		// 400& damage done

                break;
            };
            case 2: {
                // joggin zombie, increased HP/damage
                //BRP_Misc_Zombies_m_ForcedSpeed = 2;
                BRP_Misc_Zombies_m_HpMod = 3.0;      // 300% damage taken
                BRP_Misc_Zombies_m_AtkMod = 1.0;	 // 100% damage done

                break;
            };
            case 3: {
                // NOT ACTIVE
                // -- !!!BROKE!!!
                // -- causes zombies to run through walls
                // sprinting zombie, decreased HP/damage
                BRP_Misc_Zombies_m_ForcedSpeed = 3;
                BRP_Misc_Zombies_m_HpMod = 4.0;      // 300% damage taken
                BRP_Misc_Zombies_m_AtkMod = 0.5;		// 50% damage done

                break;
            };
        };

        if (BRP_Misc_Zombies_m_ForcedSpeed >= 3) {
            return;
        };
    };

    void OverrideMovementSpeed (float f_TargetSpeed) {
		DayZInfectedInputController BRP_Misc_Zombies_t_IC = GetInputController();
        if (!BRP_Misc_Zombies_t_IC) {
            return;
        };
        if (BRP_Misc_Zombies_t_IC.GetMovementSpeed() > f_TargetSpeed) {
            BRP_Misc_Zombies_m_IsOverride = true;
            BRP_Misc_Zombies_t_IC.OverrideMovementSpeed(true,f_TargetSpeed);
        };
    };

    bool BRP_Misc_Zombies_m_IsOverride = false;


    void BRP_Misc_Zombies_DisableSpeed () {
        if (!this) {
            return;
        };
        if (!IsAlive()) {
            return;
        };
        if (!BRP_Misc_Zombies_m_IsOverride) {
            return;
        };

		DayZInfectedInputController BRP_Misc_Zombies_t_IC = GetInputController();
        if (!BRP_Misc_Zombies_t_IC) {
            return;
        };
        BRP_Misc_Zombies_m_IsOverride = false;
        BRP_Misc_Zombies_t_IC.OverrideMovementSpeed(false,BRP_Misc_Zombies_m_ForcedSpeed);

        // re-check override in 300ms
		//BRP_Misc_Zombies_EnableSpeed();
        //GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( BRP_Misc_Zombies_EnableSpeed, 50, false, f_TargetSpeed);

    };

    void BRP_Misc_Zombies_EnableSpeed () {
        if (!this) {
            return;
        };
        if (!IsAlive()) {
            return;
        };
		
        float t_Speed = BRP_Misc_Zombies_m_ForcedSpeed;

        if (BRP_Misc_Zombies_m_ForcedSpeedTemp != -1) {
            t_Speed = BRP_Misc_Zombies_m_ForcedSpeedTemp;
        };
        
		DayZInfectedInputController BRP_Misc_Zombies_t_IC = GetInputController();
        if (!BRP_Misc_Zombies_t_IC) {
            return;
        };
        BRP_Misc_Zombies_m_IsOverride = true;
        BRP_Misc_Zombies_t_IC.OverrideMovementSpeed(true,t_Speed+0.01);
    };
	
	
	// OVERRIDE MINDSTATE CHANGE
	override bool HandleMindStateChange (int pCurrentCommandID, DayZInfectedInputController pInputController, float pDt) {
        BRP_Misc_Zombies_OnHandleMindStateChange(pInputController);
		return (super.HandleMindStateChange(pCurrentCommandID, pInputController, pDt));
	};

    float BRP_Misc_Zombies_m_TimeNextMindStateCheck = 0;

    void BRP_Misc_Zombies_OnHandleMindStateChange (DayZInfectedInputController f_IC) {
        if (BRP_Misc_Zombies_m_ForcedSpeed == -1) {
            return;
        };

		int t_MindState = f_IC.GetMindState();
        if (t_MindState == DayZInfectedConstants.MINDSTATE_CALM) {

            // - disable forced speed when in calm state
            //BRP_Misc_Zombies_DisableSpeed();
            return;
        };

        float t_Time = GetGame().GetTickTime();
        if (t_Time < BRP_Misc_Zombies_m_TimeNextMindStateCheck) {
            return;
        };
        BRP_Misc_Zombies_m_TimeNextMindStateCheck = t_Time + 1;

        if (t_MindState == DayZInfectedConstants.MINDSTATE_FIGHT) {
            if (BRP_Misc_Zombies_m_ForcedSpeedTemp != 1) {
                BRP_Misc_Zombies_m_ForcedSpeedTemp = 1;
            };
        } else {
            if (BRP_Misc_Zombies_m_ForcedSpeedTemp != -1) {
                BRP_Misc_Zombies_m_ForcedSpeedTemp = -1;
            };
        };
        BRP_Misc_Zombies_EnableSpeed();
        //GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( BRP_Misc_Zombies_EnableSpeed, 300, false);
    };
	
    float BRP_Misc_Zombies_m_ForcedSpeedTemp = -1;
	

    // override void HandleMove (int pCurrentCommandID) {
    //     super.HandleMove(pCurrentCommandID);
    //     BRP_Misc_Zombies_OnHandleMove();
    // };

    // void BRP_Misc_Zombies_OnHandleMove () {
    //     // no needed right now
    // };

    void BRP_Misc_Zombies_OnEEHitBy (TotalDamageResult damageResult, int damageType, EntityAI source, int component, string dmgZone, string ammo, vector modelPos, float speedCoef) {
		if (!this) {
			return;
		};

        if (BRP_Misc_Zombies_m_HpMod == -1) {
            return;
        };
		if (!damageResult) {
			return;
		};

        // reduce damage by 50%
        // - doing this by adding some health
        // -- save the total damage so it can also be affected by the no stamina thing below
		if (dmgZone == "Head") {
            return;
        };
		float t_HpPre = GetHealth();
        float t_Dmg = damageResult.GetDamage("","Health");
        float t_HpToAdd = 0 - ((t_Dmg * BRP_Misc_Zombies_m_HpMod) - t_Dmg);
		
		float t_DmgTotal = t_HpToAdd - t_Dmg;
		//Print(t_DmgTotal);
		
		//Print(GetHealth());
		
        // if the last health - the new damage plus the extra is less than 0, don't add more Hp
		// - hp to add has to also be bigger than 0
        if (t_HpToAdd > 0 && BRP_Misc_Zombies_m_LastHealth - (t_Dmg + t_HpToAdd) <= 0)  {
            return;
        };
        AddHealth("","Health",t_HpToAdd);
        BRP_Misc_Zombies_m_LastHealth = GetHealth();

        //Print("ZMBDMG:(" + t_Dmg + "-" + t_HpToAdd + "=" + (t_Dmg - t_HpToAdd) + ")  | mod " + BRP_Misc_Zombies_m_HpMod + " - " + t_Dmg * BRP_Misc_Zombies_m_HpMod + " Hp:" + t_HpPre + " -> " + GetHealth() );
		//Print(BRP_Misc_Zombies_m_LastHealth);
    };

    float BRP_Misc_Zombies_m_LastHealth = 100;
};		