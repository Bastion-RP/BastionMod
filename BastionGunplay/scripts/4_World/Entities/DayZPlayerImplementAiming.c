// Copyright 2020 GlutenFreeVapes All Rights Reserved.
//
// Author: GlutenFreeVapes
// Contact: GlutenFreeVapes@gmail.com
// Location: Estonia
// Estonian Copyright Act: https://www.riigiteataja.ee/en/eli/504042019001/consolide
// 
//
//
// Code provided to BastionRP https://bastionrp.com/ for use in the bastionRP servers, mods.
// BastionRP, BastionRP staff, BastionRP adminstration and BastionRP developers are allowed to (redistribrute, modify and build upon the code) for use on bastionRP mods and servers.
//
//
// Copyright 2020 GlutenFreeVapes All Rights Reserved.
modded class DayZPlayerImplementAiming {

    void BRP_GunPlay_Say (string msg) {
        return; // return debug disabled

        msg = "BRPGunPlay." + msg;
        GetGame().GetMission().OnEvent(ChatMessageEventTypeID, new ChatMessageEventParams(CCDirect, "", msg, ""));
        Print(msg);


    };

    float BRP_GunPlay_m_TimeLastAim = 0;
    float BRP_GunPlay_m_TimeLastModMove = 0;
    float BRP_GunPlay_m_TimeLastModAim = 0;

    vector BRP_GunPlay_m_PosLast = "0 0 0";
    
    float BRP_GunPlay_m_Mod = 0;              // The current processed modifier to use
    float BRP_GunPlay_m_ModToAdd = 0;         // The modifier to add over time
    float BRP_GunPlay_m_ModMoveToAdd = 0;     // moving modifier to add over time
    float BRP_GunPlay_m_ModMove = 0;          // moving modifier
    float BRP_GunPlay_m_ModAim = 0;           // aiming modifier

    // add the code needed to run every frame in the constructor
    void DayZPlayerImplementAiming (DayZPlayerImplement player) {
        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(BRP_GunPlay_update, 1000);
    };

    // update code which runs on the call queue
    // handles the modmove
    void BRP_GunPlay_update () {
        if (!m_PlayerPb) {
            return;
        };

        // only run if player is alive
        if (!m_PlayerPb || !m_PlayerPb.IsAlive()) {
            return;
        };
        BRP_GunPlay_ModMove();

        // add the next update
        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(BRP_GunPlay_update, 100);
        
    };


    // movement modifier calculation
    void BRP_GunPlay_ModMove () {

        // movement evaluation every 0.1 seconds:
        // time since last move check
        float t_TimePassedMove = GetGame().GetTickTime() - BRP_GunPlay_m_TimeLastModMove;

        if (t_TimePassedMove < 0.1) {
            return;
        };

        // it's been 0.1 since last movement check
        BRP_GunPlay_m_TimeLastModMove = GetGame().GetTickTime();

        // pos
        vector t_PosOld = BRP_GunPlay_m_PosLast;
        vector t_Pos = m_PlayerPb.GetPosition();
        BRP_GunPlay_m_PosLast = t_Pos;

        // calculate distance from last postion
        float t_Dist = vector.Distance(t_Pos,t_PosOld);
        t_Dist *= 2;



        // save the current pos as last pos
        BRP_GunPlay_m_PosLast = t_Pos;

        // 0.01m = 0 | 0.2m = 2
        //float t_ModMove = Math.InverseLerp(0.005, 0.1, t_Dist);
        //t_ModMove = t_ModMove * 2;
        //t_ModMove = -0.5 + t_ModMove;
        

        // adjust mod move more over distance, making the effect smaller over small distance, but bigger over the bigger distance
        float t_ModMove = Math.InverseLerp(0.015, 0.65, t_Dist);
        t_ModMove = t_ModMove * 2;
        t_ModMove = -0.15 + t_ModMove;


        t_ModMove *= t_TimePassedMove;

        // multiply the distance based on time passed
        // 0.1 seconds passed means the distance multiplier is 1
        // at 0.5m the mod is 1, if it's been 0.1 seconds then the result here is also 1
        //t_ModMove = t_ModMove * (t_TimePassedMove * 10);  // CANNOT BASE ON TIME, based on movement instead
        t_ModMove = Math.Clamp(t_ModMove,-0.1,3);



        // add it to the toAdd which will be added over time
        BRP_GunPlay_m_ModMoveToAdd += t_ModMove;
        BRP_GunPlay_m_ModMoveToAdd = Math.Clamp(BRP_GunPlay_m_ModMoveToAdd,-1,3);

    };

    float BRP_GunPlay_m_AimingLastX = 990;
    float BRP_GunPlay_m_AimingLastY = 990;

    // the custom aimn code
    void BRP_GunPlay_CustomAim (SDayZPlayerAimingModel pModel) {

        // time
        float t_TimePassed = GetGame().GetTickTime() - BRP_GunPlay_m_TimeLastAim;
        BRP_GunPlay_m_TimeLastAim = GetGame().GetTickTime();



        //--- check for change in aiming MOUSE
        // after a pause, reset the last aim
        if (t_TimePassed > 0.5) {
            // this might be needed to increase this value when there is a break in aiming
        };

        float t_TimePassedAim = GetGame().GetTickTime() - BRP_GunPlay_m_TimeLastModAim;

        // stance needed for bleed mod and aim change
        int stance = m_PlayerDpi.m_MovementState.m_iStanceIdx; 

        if (t_TimePassedAim > 0.1) {
            BRP_GunPlay_m_TimeLastModAim = GetGame().GetTickTime();


            // check mouse movement and add it based on the time passed
            float t_AimChangeX = Math.AbsFloat(pModel.m_fCurrentAimX - BRP_GunPlay_m_AimingLastX);
            float t_AimChangeY = Math.AbsFloat(pModel.m_fCurrentAimY - BRP_GunPlay_m_AimingLastY);



            if (t_AimChangeX > 5) {
                // moved at least 5


                if (pModel.m_fCurrentAimX > BRP_GunPlay_m_AimingLastX) {
                    // moved to the right


                    BRP_GunPlay_m_ModCamXIncrease = true;
                } else {
                    // moved to the left


                    BRP_GunPlay_m_ModCamXIncrease = false;
                };
            };
            if (t_AimChangeY > 5) {
                // moved at least 5


                if (pModel.m_fCurrentAimY > BRP_GunPlay_m_AimingLastY) {
                    // moved to the right


                    BRP_GunPlay_m_ModCamYIncrease = true;
                } else {
                    // moved to the left


                    BRP_GunPlay_m_ModCamYIncrease = false;
                };
            };



            BRP_GunPlay_m_AimingLastX = pModel.m_fCurrentAimX;
            BRP_GunPlay_m_AimingLastY = pModel.m_fCurrentAimY;

            float t_AimChange = Math.Sqrt((t_AimChangeX * t_AimChangeX) + (t_AimChangeY * t_AimChangeY));

            

            // HIGHER AIM CHANGE mod when in prone
            if (stance == DayZPlayerConstants.STANCEIDX_PRONE || stance == DayZPlayerConstants.STANCEIDX_RAISEDPRONE) {
                if (t_AimChange < 10 && (BRP_GunPlay_m_Mod + BRP_GunPlay_m_ModToAdd < 0.5)) {
                    t_AimChange *= 15;
                } else {
                    t_AimChange *= 7.5;
                }
            };
            
            

            // only the one that changed the most will be done. (meaning going diagonally accross will only add whichever one was the biggest)
            if (t_AimChange > 5) {
                t_AimChange = Math.InverseLerp(5, 40, t_AimChange);
                t_AimChange = Math.Clamp(t_AimChange, 0, 1);
                t_AimChange = t_AimChange * 0.5;    // half the effect
                if (BRP_GunPlay_m_Mod + BRP_GunPlay_m_ModToAdd + t_AimChange < 1.5) {
                    BRP_GunPlay_m_ModToAdd += t_AimChange;
                };
            };
        };


        // get the time based modifier
        // if it's been 2.5 seconds, the 
        // - this has to be based on time since aiming began, not last time
        // - DETECT when aiming stops
        float t_ModTime = Math.InverseLerp(0.5, 2, t_TimePassed);
        t_ModTime = Math.Clamp(t_ModTime, 0, 3);

        if (t_ModTime > 0) {
            BRP_GunPlay_m_ModToAdd += t_ModTime;
        };

        


        //--- STAMINA CHECK
        // if player can't hold breath, cause destab
        if (!m_PlayerPb.CanConsumeStamina(EStaminaConsumers.HOLD_BREATH)) {
            if (BRP_GunPlay_m_Mod < 1) {
                BRP_GunPlay_m_ModToAdd += 0.01 * t_TimePassed;
            };
        };
   

        // If it's been more than 0.3 seconds, deplete the toAdd
        if (t_TimePassed > 0.3) {

            // update mod by adding all toAdd
            BRP_GunPlay_m_Mod += BRP_GunPlay_m_ModMoveToAdd;
            BRP_GunPlay_m_Mod = Math.Clamp(BRP_GunPlay_m_Mod,0.0,3);    // clamp here because moveAdd can be negative

            BRP_GunPlay_m_Mod += BRP_GunPlay_m_ModToAdd;
            BRP_GunPlay_m_Mod = Math.Clamp(BRP_GunPlay_m_Mod,0.0,3);

            // reset toAdd
            BRP_GunPlay_m_ModMoveToAdd = 0;
            BRP_GunPlay_m_ModToAdd = 0;


            return; // return here because the change must be instant and no more is needed
        };


        float t_WeaponModRaw = BRP_GunPlay_WeaponMod(true);

        // limit move to add + current mod based on the gun size (and player weight)
        float t_ModWeaponMax = 3 - t_WeaponModRaw;


        // calc to add based on time passed (1 second = 10 for mod)
        // to add CANNOT be based on toadd mod, but a constant instead
        float t_ToAdd = 0;
        float t_SizeSmoother = 1;

        // only apply smoother if it's close to 10% off min or max
        //if (BRP_GunPlay_m_Mod > t_ModWeaponMax*0.7 || BRP_GunPlay_m_Mod < t_ModWeaponMax*0.3) {   // not neede, using Easing
        if (true) {
                
            float t_ToAddSizeMod = Math.InverseLerp(0, t_ModWeaponMax, BRP_GunPlay_m_Mod);
            t_SizeSmoother = Easing.EaseInOutSine(t_ToAddSizeMod);
            

            // if the mod is higher than half, reverse the smoother
            if (BRP_GunPlay_m_Mod > t_ModWeaponMax*0.5) {
                t_SizeSmoother = 1 - t_SizeSmoother;    // 0.8 turns into 0.2
            };
        };


        float t_ToAddSize = 1.5;
        float t_ToAddSizeMove = 10;
        
        // apply smoother
        t_ToAddSize = t_ToAddSize * t_SizeSmoother;
        t_ToAddSizeMove = t_ToAddSizeMove * t_SizeSmoother;
        
        t_ToAddSize = 0.01 + t_ToAddSize * t_TimePassed;    // from 1.5
        t_ToAddSizeMove = 0.01 + t_ToAddSizeMove * t_TimePassed;    // from 1.5

        // TimeToAdd
        if (BRP_GunPlay_m_ModToAdd > 0) {
            // toadd bigger than 0, add some extra

            // calculate new toadd
            t_ToAdd += t_ToAddSize;

            // bleed the toadd
            BRP_GunPlay_m_ModToAdd -= t_ToAddSize;
            BRP_GunPlay_m_ModToAdd = Math.Clamp(BRP_GunPlay_m_ModToAdd,0,3);
        };

        // MoveToAdd 
        if (BRP_GunPlay_m_ModMoveToAdd > 0) {

            // calculate new toadd
            t_ToAdd += t_ToAddSizeMove;
            
            // remove more if the mod is 90%
            if (BRP_GunPlay_m_Mod > t_ModWeaponMax * 0.9) {

                // remove more if we have more than 0.3 (so it drops off faster if already full)
                if (BRP_GunPlay_m_ModMoveToAdd > t_ModWeaponMax * 0.3) {
                    t_ToAddSizeMove *= 10;
                };
            };


            BRP_GunPlay_m_ModMoveToAdd -= t_ToAddSizeMove;

            BRP_GunPlay_m_ModMoveToAdd = Math.Clamp(BRP_GunPlay_m_ModMoveToAdd,0,t_ModWeaponMax);
        };


        // determine if maxed before MoveToAdd
        // if it is maxed, don't remove from movement toadd


        // if there is something to add, add it, otherwise bleed the mod
        if (t_ToAdd > 0) {
            // apply the toadd            

            // if the sum of current mod and tobe added mod is smaller than the max of this gun
            if ((BRP_GunPlay_m_Mod + t_ToAdd) < t_ModWeaponMax) {
                
                // Add the toadd
                BRP_GunPlay_m_Mod += t_ToAdd;
            } else {
                // current sum is equal or higher than this gun max

                // add 20%
                BRP_GunPlay_m_Mod += (t_ToAdd * 0.20);

            };

        } else {
            // bleed the main modifier (RESTABLIZIE AIM)

            float t_StanceMod = 0;
            
            if (stance == DayZPlayerConstants.STANCEIDX_CROUCH || stance == DayZPlayerConstants.STANCEIDX_RAISEDCROUCH) {
                t_StanceMod = 0.25;
            };
            if (stance == DayZPlayerConstants.STANCEIDX_PRONE || stance == DayZPlayerConstants.STANCEIDX_RAISEDPRONE) {
                t_StanceMod = 0.5;
            };

            float t_BleedPerSec = 0.5;
            float t_BleedPerSecDef = t_BleedPerSec;

            float t_WeaponMod = t_WeaponModRaw;
            t_BleedPerSec += t_StanceMod;
            t_BleedPerSec += t_WeaponMod * 0.25;

            // size mod so it smoothly reduces the restabilazation as the gun gets more and more stable
            float t_BleedSlow = Math.InverseLerp(0, 0.5, BRP_GunPlay_m_Mod);
            t_BleedSlow = Math.Clamp(t_BleedSlow, 0, 1);
            t_BleedSlow = Math.Lerp((t_BleedPerSec - 0.1),0.01,t_BleedSlow);  // 1 == mod at 0.01 | 0 == mod at 0.5
            t_BleedSlow = Easing.EaseInOutSine(t_BleedSlow);

            t_BleedPerSec -= t_BleedSlow;

            // faster bleed when holding breath
		    if(m_PlayerPb.IsHoldingBreath()) {
                t_BleedPerSec += 0.75;
            } else {
                // not holding breath
            };

            BRP_GunPlay_m_Mod -= (t_BleedPerSec) * t_TimePassed;
        };
        
        // clamp the mod
        BRP_GunPlay_m_Mod = Math.Clamp(BRP_GunPlay_m_Mod,0.0,t_ModWeaponMax);
        
        BRP_GunPlay_Say("mod: " + BRP_GunPlay_m_Mod);
        //BRP_GunPlay_Say("toadd: " + t_ToAdd);
        //BRP_GunPlay_Say("toadd perm: " + BRP_GunPlay_m_ModMoveToAdd);
        //BRP_GunPlay_Say("ToAdd: " + t_ToAdd);

    }


    // calculate the player modifier, based on the weight of the player
    // from 0 to 1
    // 0 = unloaded player
    // 1 = max loaded player
    float BRP_GunPlay_PlayerMod () {
        //

        if (!m_PlayerPb) {
            return 0;
        };

        //! gets the actual players load
        float BRP_GunPlay_t_PlayerLoad = m_PlayerPb.GetPlayerLoad();  // in grams, player weight

		EntityAI BRP_GunPlay_t_PlayerBag = m_PlayerPb.GetInventory().FindAttachment(InventorySlots.BACK);

        // get bag weight
        float BRP_GunPlay_t_BagLoad = BRP_GunPlay_t_PlayerBag.GetWeight();
		
        // increase the weight by bag amount
        BRP_GunPlay_t_PlayerLoad += BRP_GunPlay_t_BagLoad;      // could mult x2 here to icnrease the bag size effect


        // min weigt
        // 3000 g
        // max weight
        // 60000 g

        return Math.Clamp(Math.InverseLerp(6000,60000,BRP_GunPlay_t_PlayerLoad),0,1);
    };


    // universal weapon modifier check
    // returns the weapon modifier from 0 to 2  (can even go higher) || perhaps it is better to just go from 0 to 1 and then evaluate later
    // 0 mod is very light and short
    // 1 is medium / normal
    // 2 is very long and heavy
    // || should never be 0, this is a modifier and having it 0 would mean no effect or no X || this could be done specific where it is used
    // I can use the 1 as default, this way there is a default to fallback on ( but shouldn't even need it  )
    float BRP_GunPlay_WeaponMod (bool isReversed = false) {
        
		Weapon_Base weapon = Weapon_Base.Cast(m_PlayerDpi.GetHumanInventory().GetEntityInHands());
		if (!weapon) {
            return 1;
        };
        float t_Length = weapon.BRP_GunPlay_GetLength();      // suppressor has no effect
        float t_Weight = weapon.GetWeight();                        // in grams

        // add suppressor length
		ItemBase t_Attach;
		if (ItemBase.CastTo(t_Attach,weapon.FindAttachmentBySlotName("weaponBayonet")) || ItemBase.CastTo(t_Attach,weapon.FindAttachmentBySlotName("weaponBayonetAK")) || ItemBase.CastTo(t_Attach,weapon.FindAttachmentBySlotName("weaponBayonetMosin")) || ItemBase.CastTo(t_Attach,weapon.FindAttachmentBySlotName("weaponBayonetSKS")) || ItemBase.CastTo(t_Attach,weapon.GetAttachedSuppressor())) {
			t_Length += t_Attach.m_ItemModelLength;
		};

        // add buttstock length
        if (weapon.HasButtstockAttached()) {
            
            int t_AttachCount = weapon.GetInventory().AttachmentCount();
            
            //attachments?
            if (t_AttachCount > 0) {
                for (int t_Attach_i = 0; t_Attach_i < t_AttachCount; t_Attach_i++) {
                    t_Attach = ItemBase.Cast(weapon.GetInventory().GetAttachmentFromIndex(t_Attach_i));
		            string t_ClassName = t_Attach.GetType();
                    string t_SlotName;
                    string t_Path = "cfgVehicles " + t_ClassName + " inventorySlot";
                    GetGame().ConfigGetText(t_Path,t_SlotName);

                    t_SlotName.ToLower();	// thanks bohemia

                    // if it's not a stock, skip the rest
				    if (t_SlotName.IndexOf("stock") == -1 && t_SlotName.IndexOf("btt") == -1 && t_SlotName.IndexOf("butt") == -1) {
                        continue;
                    };

                    int item_size_x = 1;
                    int item_size_y = 1;
                    
                    GetGame().GetInventoryItemSize(t_Attach, item_size_x, item_size_y);

                    float t_StockSize = item_size_x + item_size_y;

                    // half the size
                    t_StockSize *= 0.5;

                    // use the weight as an extra modifier
                    t_StockSize = (-t_StockSize * 0.5) + (t_StockSize * (t_Attach.GetWeight() * 0.001));    //(-1 * t_StockSize) + 
                    BRP_GunPlay_Say("stock size: " + t_StockSize);
                    BRP_GunPlay_Say("pre stock length: " + t_Length);

                    t_Length += t_StockSize;
                }
            }
        };
        //BRP_GunPlay_Say("legnthPost: " + t_Length);

        // max: 1 (svd ~1.1)
        // min: 0.5 (pmm ~0.5)
        float t_Mod = Math.InverseLerp(0.5, 1, t_Length);


        // max: 5000 (fal ~3700)
        // min: 750 (pmm ~ 760)
        t_Mod += Math.InverseLerp(750,5000,t_Weight);

        // recoil modifier from the gun
        vector t_RecoilMods = weapon.GetPropertyModifierObject().m_RecoilModifiers;

        // 1- mod, so that when the mod is 0.7 it will be 0.3. If it's 0.9 it will be 0.1
        float t_RecoilMod = 1 - t_RecoilMods[0];
        t_RecoilMod *= 0.5;

        //BRP_GunPlay_Say("recoilMod: " + t_RecoilMod);
        //BRP_GunPlay_Say("weaponMod: " + t_Mod);

        t_Mod -= t_RecoilMod;
        //BRP_GunPlay_Say("weaponMod: " + t_Mod);


        // a short and a light gun will return      ~ 0.1 + 0.1     = 0.2
        // a long and heavy gun will return         ~ 1 + 1.2       = 2.2

        // clamp it
        if (isReversed) {
            
            return (Math.Clamp((2-t_Mod), 0.1, 1.9));
        }
        return (Math.Clamp(t_Mod, 0.1, 1.9));
    };


    // stamina depleting function
    void BRP_GunPlay_Stamina() {

        BRP_GunPlay_Say("stamina.GunSupport: " + BRP_GunPlay_m_GunSupportStrength);

        // if gun is supported, lose no stamina !!!! this doesn't work because the server never finds the gun like that 
        if (BRP_GunPlay_m_GunSupportStrength != 0) {
            //return;
        };

        if (!m_PlayerPb) {
            return;
        };
		int stance = m_PlayerDpi.m_MovementState.m_iStanceIdx;

        

        // if player is prone, quit
        if (stance == DayZPlayerConstants.STANCEIDX_PRONE || stance == DayZPlayerConstants.STANCEIDX_RAISEDPRONE) {
            return;
        };
        
        float t_Mod = 0;
        if (stance == DayZPlayerConstants.STANCEIDX_CROUCH || stance == DayZPlayerConstants.STANCEIDX_RAISEDCROUCH) {
            //t_Mod += 1;
        };
        if (stance == DayZPlayerConstants.STANCEIDX_RAISEDERECT || stance == DayZPlayerConstants.STANCEIDX_ERECT) {
            t_Mod += 1;
        };
        
        float t_WeaponMod = BRP_GunPlay_WeaponMod();
        t_WeaponMod = t_WeaponMod * 0.8;

        t_Mod += t_WeaponMod;
        //BRP_GunPlay_Say("stanceMod: " + t_Mod);
        //BRP_GunPlay_Say("weaponMod: " + t_WeaponMod);
        if (t_Mod >= 3) {
            m_PlayerPb.DepleteStamina(BRP_GunPlay_EStaminaModifiers.BRP_GunPlay_AIM_ULTRA);
            return;
        };

        if (t_Mod >= 2) {
            m_PlayerPb.DepleteStamina(BRP_GunPlay_EStaminaModifiers.BRP_GunPlay_AIM_HIGH);
            return;
        };
        

        if (t_Mod > 1) {
            m_PlayerPb.DepleteStamina(BRP_GunPlay_EStaminaModifiers.BRP_GunPlay_AIM_MED);
            return;
        };
        

        m_PlayerPb.DepleteStamina(BRP_GunPlay_EStaminaModifiers.BRP_GunPlay_AIM_LOW);
        // 
        
    };
    
    // The fire function called from weapon manager
    // Will calculate and add extra aim
    void BRP_GunPlay_Fire(Weapon_Base wpn) {
        // extra penalty when fired
        // - Based on weapon weight and weapon length | light/short weapons have a smaller effect
        // - stance | aim destabilizes more when standing up or crouching, barely at all when proning
		int mi = wpn.GetCurrentMuzzle();
        if( wpn.IsChamberFiredOut(mi) || wpn.IsJammed() || wpn.IsChamberEmpty(mi) ) {
            //BRP_GunPlay_Say("empty: " + wpn);
            return;
        };
        
		TStringArray t_Arr = new TStringArray;
		wpn.ConfigGetTextArray("chamberableFrom", t_Arr);
        float t_Weight = 0;

        for (int t_i = 0; t_i < t_Arr.Count(); t_i++) {
            string t_Ammo = t_Arr.Get(t_i);
            //BRP_GunPlay_Say("fire ammo: " + t_Ammo);

            string t_AmmoName;
            string t_Path = "CfgMagazines " + t_Ammo + " displayName";
            GetGame().ConfigGetText(t_Path,t_AmmoName);
            //BRP_GunPlay_Say("fire name: " + t_AmmoName);
            
            // check if the mag name contains $ (means the mag is bugged or unfinished)
            // also check if the mag contains TEST
            t_AmmoName.ToLower();	// thanks bohemia
            if (t_AmmoName.IndexOf("$") != -1 || t_AmmoName.IndexOf("test") != -1) {
                // $ exists
                //BRP_GunPlay_Say("fire fail: " + t_AmmoName);
                
                // skip
                continue;
            };

            // ammo
		    t_Path = "CfgMagazines " + t_Ammo + " weight";
			t_Weight = GetGame().ConfigGetFloat(t_Path);
            //BRP_GunPlay_Say("fire cweight: " + t_Weight);
            break;
        };
        //BRP_GunPlay_Say("fire weight: " + t_Weight);
        
        float t_ToAdd = Math.InverseLerp(2,10,t_Weight);
        t_ToAdd = Math.Clamp(t_ToAdd,0,1);
        t_ToAdd = Math.Lerp(0, 0.25, t_ToAdd);
        //BRP_GunPlay_Say("fire ToAdd: " + t_ToAdd);
        
        BRP_GunPlay_m_Mod += t_ToAdd;
    };

    // the biggest function with the most amount of calculations and it calls the other functions
	bool ProcessAimFilters(float pDt, SDayZPlayerAimingModel pModel, int stance_index) {

        // calculate the main multiplier over here... This will run before all the code in the aiming logic
            // - check every 0.1 seconds (could extend this to use the time since last as a modifier (to mitigate lag effects))
            // - check for character movement (WASD) [BIG EFFECT]
            // - check for aim movement (currentAim) [small effect]
            // - based on the changes in the last 0.1 seconds, add custom modifier
            //
            // - Save the last time the calculation ran
            // - Use the last time ran to reset aim to WORST
            // - lerp the aim based on time spent aiming
            //      - 2.5 seconds BEST (better than vanilla)
            //      - 0.5 seconds WORST
            //
            // - consider only doing a separate modifier for horizontal noise
            //      - horizontal noise is more chaotic and has a odd effect
            //      - different lerp/mod for this
            //
            //
            // - holding breath slows the speed down by 10X (IsHoldingBreath)
            //      - Change the speed change (ApplyBreathingPattern)
            //
            //
            // - not aiming down sights should have a smaller modifier (IsInOptics)
            //      - not ADS mode already has a lot of dispersion, so whatever
            //
            //
            // - FIRE modifier
            //      - last time the gun was shot will also apply a modifier
            //
            //
            // - STAMINA modifier
            //      - if stamina drained, there should be an extra effect

        
        // check for gun support
        BRP_GunPlay_GunSupportCheck();

        // run stamina depletion code
        BRP_GunPlay_Stamina();

        // run the custom aim code
        BRP_GunPlay_CustomAim(pModel);
        bool BRP_GunPlay_t_result = super.ProcessAimFilters(pDt, pModel, stance_index);


        
        // if gun is supported, reset mod
        if (BRP_GunPlay_m_GunSupportStrength != 0) {
            BRP_GunPlay_m_Mod = 0;
        };


        
        BRP_GunPlay_m_TimeNextCamOffset = GetGame().GetTickTime() + BRP_GunPlay_m_Mod;
        int t_TimeInt = GetGame().GetTickTime() * 10;
        t_TimeInt = t_TimeInt % 30;
        float t_TimeFloat = t_TimeInt * 0.1;
        t_TimeFloat = Math.InverseLerp(0, 3, t_TimeFloat);

        float t_Target = 1;
        float t_VelocityAdd = -2;
        if (BRP_GunPlay_m_ModCamXApplied >= 1) {
            BRP_GunPlay_m_ModCamXTarget = -1;
        };
        if (BRP_GunPlay_m_ModCamXApplied <= -1) {
            BRP_GunPlay_m_ModCamXTarget = 1;
        };

        float t_Velocity[1];
        if (BRP_GunPlay_m_ModCamXTarget > 0) {
            t_VelocityAdd = 2;
        } else {

        };
        t_Velocity[0] = t_VelocityAdd;
        
        BRP_GunPlay_m_ModCamXApplied = Math.SmoothCD(BRP_GunPlay_m_ModCamXApplied, BRP_GunPlay_m_ModCamXTarget, t_Velocity, 0.3, t_VelocityAdd, pDt);
        
        if (t_TimeFloat == 0) {
            if (BRP_GunPlay_m_ModCamYTarget > 0) {
                BRP_GunPlay_m_ModCamYTarget = -1;
            } else {
                BRP_GunPlay_m_ModCamYTarget = 1;
            };
        };


        //BRP_GunPlay_Say("t_TimeFloat: " + t_TimeFloat);
        //BRP_GunPlay_Say("yApplied: " + BRP_GunPlay_m_ModCamYApplied);
        
        // 
        if (BRP_GunPlay_m_ModCamYTarget > 0) {
            BRP_GunPlay_m_ModCamYApplied = -1 + (Easing.EaseInOutSine(t_TimeFloat) * 2);  // -1 to 1
        } else {
            BRP_GunPlay_m_ModCamYApplied = 1 - (Easing.EaseInOutSine(t_TimeFloat) * 2);   // 1 to -1
        };

        if (BRP_GunPlay_m_ModCamYIncrease) {
            // INCREASE

            if (BRP_GunPlay_m_ModCamYTimed > 1) {
                BRP_GunPlay_m_ModCamYIncrease = false;
            };

            // add new timed y mod based on time passed
            BRP_GunPlay_m_ModCamYTimed += 1 * pDt;
        } else {
            // DECREASE

            if (BRP_GunPlay_m_ModCamYTimed < 0) {
                BRP_GunPlay_m_ModCamYIncrease = true;
            };

            // add new timed y mod based on time passed
            BRP_GunPlay_m_ModCamYTimed -= 1 * pDt;
        };
        BRP_GunPlay_m_ModCamYApplied = -0.5 + (Easing.EaseInOutSine(BRP_GunPlay_m_ModCamYTimed) * 2);   // from -1 | from 2

        if (BRP_GunPlay_m_ModCamXIncrease) {
            // INCREASE

            if (BRP_GunPlay_m_ModCamXTimed > 1) {
                BRP_GunPlay_m_ModCamXIncrease = false;
            };

            // add new timed y mod based on time passed
            BRP_GunPlay_m_ModCamXTimed += 1.5 * pDt;
        } else {
            // DECREASE

            if (BRP_GunPlay_m_ModCamXTimed < 0) {
                BRP_GunPlay_m_ModCamXIncrease = true;
            };

            // add new timed y mod based on time passed
            BRP_GunPlay_m_ModCamXTimed -= 1.5 * pDt;
        };
        BRP_GunPlay_m_ModCamXApplied = -1 + (Easing.EaseInOutSine(BRP_GunPlay_m_ModCamXTimed) * 2);

        // add custom cam offset
        //! cam offset
        // the applied offset has to normalize over time, then the modded one is applied to it over time        
        pModel.m_fAimXCamOffset += Math.Lerp(0, BRP_GunPlay_m_ModCamXApplied, (BRP_GunPlay_m_Mod * 0.25));  // from 0.5
        pModel.m_fAimYCamOffset += Math.Lerp(0, BRP_GunPlay_m_ModCamYApplied, (BRP_GunPlay_m_Mod * 0.25));
            
            
                   
        //BRP_GunPlay_Say("aimX: ProcessDone");
        //BRP_GunPlay_Say("Optics: " + m_PlayerDpi.IsInOptics());
        //BRP_GunPlay_Say("aimX: " + pModel.m_fCurrentAimX);
        //BRP_GunPlay_Say("aimY: " + pModel.m_fCurrentAimY);
        //BRP_GunPlay_Say("filter mod: " + BRP_GunPlay_m_Mod);
        //BRP_GunPlay_Say("aimXHandsOff: " + pModel.m_fAimXHandsOffset);
        //BRP_GunPlay_Say("aimYHandsOff: " + pModel.m_fAimYHandsOffset);
        //BRP_GunPlay_Say("aimXCamOff: " + pModel.m_fAimXCamOffset);
        //BRP_GunPlay_Say("aimYCamOff: " + pModel.m_fAimYCamOffset);

        return BRP_GunPlay_t_result;
    }

    float BRP_GunPlay_m_ModCamYTimed = 0;
    bool BRP_GunPlay_m_ModCamYIncrease = true;
    float BRP_GunPlay_m_ModCamXTimed = 0;
    bool BRP_GunPlay_m_ModCamXIncrease = true;

    float BRP_GunPlay_m_ModCamXTarget = 1;
    float BRP_GunPlay_m_ModCamYTarget = 1;
    float BRP_GunPlay_m_ModCamXApplied = 0;
    float BRP_GunPlay_m_ModCamYApplied = 0;
    
    float BRP_GunPlay_m_ModCamX = 0;
    float BRP_GunPlay_m_ModCamY = 0;
    float BRP_GunPlay_m_TimeNextCamOffset = 0;



    // just here in case the modifier needed
    override void ApplyBreathingPattern(out float x_axis, out float y_axis, float pAmplitude, out float pTotalTime, float weight) {
        super.ApplyBreathingPattern(x_axis,y_axis,pAmplitude,pTotalTime,weight);
    };

    
    float BRP_GunPlay_m_TimeNextGunSupportCheck = 0;
    int BRP_GunPlay_m_GunSupportStrength = 0;

    // checks and caches gun support checks. Delayed release of gun supporting
    void BRP_GunPlay_GunSupportCheck () {
		if (GetGame().IsServer() || !GetGame().IsMultiplayer()) {
            return;
        };
        
        // disabled for now
        return;

        // time check
        if (GetGame().GetTickTime() < BRP_GunPlay_m_TimeNextGunSupportCheck) {
            return;
        };

        // reset the support strength if the pause was longer than 0.5 seconds
        if (GetGame().GetTickTime() - BRP_GunPlay_m_TimeNextGunSupportCheck >= 0.5) {
            BRP_GunPlay_m_GunSupportStrength = 0;

            //since it's been more than 0.1, pause a little and then start (so that long guns won't activate the support too fast)
            BRP_GunPlay_m_TimeNextGunSupportCheck = GetGame().GetTickTime() + 0.3;   
            return;
        };

        // only check every 0.1 seconds
        BRP_GunPlay_m_TimeNextGunSupportCheck = GetGame().GetTickTime() + 0.1;

        // run the gun support check
        bool t_IsGunSupported = BRP_GunPlay_IsGunSupported(BRP_GunPlay_m_GunSupportStrength);

        // increment support strength if check success and strength is okay
        if (t_IsGunSupported && BRP_GunPlay_m_GunSupportStrength < 2) {
            BRP_GunPlay_m_GunSupportStrength ++;
        } else if (!t_IsGunSupported) {
            // Check failed

            // reset strength
            BRP_GunPlay_m_GunSupportStrength = 0;
        };
    };


    // The gun support check/logic with raycasting
    // option to increase the distance (once mounted, stays mounted easier)
    bool BRP_GunPlay_IsGunSupported (int p_SupportLevel = 0) {
        float t_Dist1 = 0.2;
        float t_Dist2 = 0.5;
        if (p_SupportLevel == 1) {
            t_Dist1 = 0.3;
            t_Dist2 = 0.6;
        };
        if (p_SupportLevel == 2) {
            t_Dist1 = 0.4;
            t_Dist2 = 0.8;
        };
        
        //--- Add checks for gun supports        
        // add suppressor length
		Weapon_Base t_Weapon = Weapon_Base.Cast(m_PlayerDpi.GetHumanInventory().GetEntityInHands());
		vector usti_hlavne_position = t_Weapon.GetSelectionPositionLS( "Usti hlavne" ); 	// Usti hlavne
        //BRP_GunPlay_Say("usti: " + usti_hlavne_position);
        //vector usti_hlavne_world_position = t_Weapon.ModelToWorld(usti_hlavne_position);

        vector start = t_Weapon.ModelToWorld(usti_hlavne_position);
        
        usti_hlavne_position[1] = usti_hlavne_position[1] - t_Dist1;
        //vector usti_hlavne_world_position = t_Weapon.ModelToWorld(usti_hlavne_position);
        vector end = t_Weapon.ModelToWorld(usti_hlavne_position);

        //vector start = usti_hlavne_world_position;
        //vector end = usti_hlavne_world_position;
        //end[1] = end[1] - t_Dist1;
	    PhxInteractionLayers hit_mask = PhxInteractionLayers.CHARACTER | PhxInteractionLayers.BUILDING | PhxInteractionLayers.DOOR | PhxInteractionLayers.VEHICLE | PhxInteractionLayers.ROADWAY | PhxInteractionLayers.TERRAIN | PhxInteractionLayers.ITEM_SMALL | PhxInteractionLayers.ITEM_LARGE | PhxInteractionLayers.FENCE | PhxInteractionLayers.AI;
		Object hit_obj;
		vector hit_pos, hit_normal; //junk
		float hit_fraction; //junk
        //BRP_GunPlay_Say("start: " + start);
        //BRP_GunPlay_Say("end: " + end);

		DayZPhysics.RayCastBullet(start, end, hit_mask, m_PlayerPb, hit_obj, hit_pos, hit_normal, hit_fraction);
        BRP_GunPlay_Say("hit_pos: " + hit_pos);
        //BRP_GunPlay_Say("hit_obj: " + hit_obj);
        //Shape t_LineTest = Debug.DrawLine(start, end, Colors.RED, ShapeFlags.NOZBUFFER );
        
        // check for hit 
		if (hit_pos != vector.Zero) {
            return true;
        };

        // 2nd check ( towards player)
        start = end;
        usti_hlavne_position[0] = 0;
        end = t_Weapon.ModelToWorld(usti_hlavne_position);
        end[1] = end[1] - t_Dist2;
        

		DayZPhysics.RayCastBullet(start, end, hit_mask, m_PlayerPb, hit_obj, hit_pos, hit_normal, hit_fraction);
        BRP_GunPlay_Say("hit_pos2: " + hit_pos);
        //BRP_GunPlay_Say("hit_obj2: " + hit_obj);

        // check for hit 
		if (hit_pos != vector.Zero) {
            return true;
        };

        return false;
    };

    // Calculates the weight that is used inside the processaimfilters
	override float CalculateWeight(int stance_index, float current_stamina, float camera_sway_modifier) {

        // if gun is supported, replace the stamina
        if (BRP_GunPlay_m_GunSupportStrength != 0) {
            current_stamina = 1;
            stance_index = DayZPlayerConstants.STANCEIDX_RAISEDPRONE;
        };


        float BRP_GunPlay_t_AimWeight = super.CalculateWeight(stance_index, current_stamina, camera_sway_modifier);
        BRP_GunPlay_t_AimWeight *= 0.5;
      

        // weapon mod
        float t_WeaponMod = (BRP_GunPlay_WeaponMod() * 0.5);  // only half effect
    
        // different mod when in optis or ironsights (aiming from the hip)
        if (m_PlayerDpi.IsInOptics() || m_PlayerDpi.IsInIronsights()) {
            // in optics / ironsights

            // clamp the weapon mod
            t_WeaponMod = Math.Clamp(t_WeaponMod,0,1.25);

            // always 0.3 (up to 1.25) | multiply by 2 (0.6 -> 2.5)
            t_WeaponMod = (0.3 + t_WeaponMod) * 2;  // double the effect (after clamp and 0.3)


            BRP_GunPlay_t_AimWeight *= (2.5 * BRP_GunPlay_m_Mod + 1);
            BRP_GunPlay_t_AimWeight *= t_WeaponMod;
        } else {
            // Not in optics / ironsights

            // check for movement speed 
		    int t_Speed = m_PlayerDpi.m_MovementState.m_iMovement;

            //BRP_GunPlay_Say("speed: " + t_Speed);

            // uniform hipfire sway
            //BRP_GunPlay_t_AimWeight *= (10 * BRP_GunPlay_m_Mod + 1);
            BRP_GunPlay_t_AimWeight += Math.Lerp(0.2,2,Math.InverseLerp(0,3,BRP_GunPlay_m_Mod));  // hipfire aim penalty from aiming mod (how stable the aim currently)

            if (t_Speed == DayZPlayerConstants.MOVEMENTIDX_IDLE) {
                // standing still

                //BRP_GunPlay_t_AimWeight *= (5.5 * BRP_GunPlay_m_Mod + 1);
            } else if (t_Speed == DayZPlayerConstants.MOVEMENTIDX_WALK) {
                // walking

                //BRP_GunPlay_t_AimWeight *= (10 * BRP_GunPlay_m_Mod + 1);
            } else {
                // jogging or default

                //BRP_GunPlay_t_AimWeight *= (15 * BRP_GunPlay_m_Mod + 1);
            };

            //BRP_GunPlay_t_AimWeight *= t_WeaponMod;
            BRP_GunPlay_t_AimWeight += (t_WeaponMod * 0.25);    // perma effect for hipfire aim based on weapon size
        };
        BRP_GunPlay_Say("weight: " + BRP_GunPlay_t_AimWeight);

        return BRP_GunPlay_t_AimWeight;
    
	};

	override void ApplyHorizontalNoise(out float x_axis, out float y_axis, float smooth_time,float max_velocity_low, float max_velocity_high, float velocity_modifier,  float max_distance, float weight, float pDt)
	{

        // run the supper with the modified values
        super.ApplyHorizontalNoise(x_axis, y_axis, smooth_time, max_velocity_low, max_velocity_high, velocity_modifier, max_distance, weight, pDt*0.5);

	}
}

