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
modded class Weapon_Base extends Weapon {
    
    // DEBUG
    bool BRP_Shock_m_IsDebug = false;

    float BRP_Shock_GetGunDir() {
		vector BRP_Shock_t_MuzzlePos = this.GetSelectionPositionLS( "Usti hlavne" ); 
        vector BRP_Shock_t_BarrelPos = this.GetSelectionPositionLS( "konec hlavne" );//konec hlavne
        vector BRP_Shock_t_MuzzlePosW = this.ModelToWorld(BRP_Shock_t_MuzzlePos);
        vector BRP_Shock_t_BarrelPosW = this.ModelToWorld(BRP_Shock_t_BarrelPos);

        float BRP_Shock_t_GunDir = BRP_Shock_GetDirTo(BRP_Shock_t_BarrelPosW, BRP_Shock_t_MuzzlePosW);

        return BRP_Shock_t_GunDir;
    };

    float BRP_Shock_GetDirTo(vector BRP_Shock_f_Pos1, vector BRP_Shock_f_Pos2) {

        vector BRP_Shock_t_VectorDir = vector.Direction(BRP_Shock_f_Pos1, BRP_Shock_f_Pos2);
        BRP_Shock_t_VectorDir = BRP_Shock_t_VectorDir.VectorToAngles();
        return BRP_Shock_t_VectorDir[0];

    };

	void EEFired (int muzzleType, int mode, string ammoType) {
        super.EEFired(muzzleType,mode,ammoType);

        // prelimineary checks
        // - IsNotPlayer        - can't my bullets NOTE:Done by distance check (<5 not allowed)
        // - DistanceFromPlayer - Only suppressed by shots which are < 1000m
        // - Direction          - Maybe don't suppress when a player close shoots away from the player
        //                      - Direction must be from the start, if the bullet is aimed away from the player, don't suppress

        // make sure the gun and the player exist
        if (this == NULL || GetGame().GetPlayer() == NULL) {
            return;
        };

        // distance check
        float BRP_Shock_t_Dist = vector.Distance(GetGame().GetPlayer().GetPosition(), this.GetPosition());
        
        // quit if distance is less than 1 or bigger than 1000
        if (BRP_Shock_t_Dist < 1 || BRP_Shock_t_Dist > 1500) {
            if (!BRP_Shock_m_IsDebug) {
                return;
            };
        };

        float BRP_Shock_t_GunDir = BRP_Shock_GetGunDir();

        // need direction from gun to player
        float BRP_Shock_t_GunToPlayerDir = BRP_Shock_GetDirTo(this.GetPosition(), GetGame().GetPlayer().GetPosition());

        // calculate difference in direction
        float BRP_Shock_t_DirDiff = Math.AbsFloat(BRP_Shock_t_GunDir - BRP_Shock_t_GunToPlayerDir);

        // If the differnece in angles (360 max) is bigger than 180, remove the result from 360
        //  350 - 150 =     200:     360 - 200   = 160
        //  330 - 5 =       325:     360 - 325   = 35
        if (BRP_Shock_t_DirDiff > 180) {
            BRP_Shock_t_DirDiff = 360 - BRP_Shock_t_DirDiff;
        };

        // if the difference of direction is big (> 45 degrees, it's not gonna suppress player)
        // TODO: Could have a linear converstion here based on the distance
        //      - This would mean the angle is bigger if the gun is closer to the player and smaller when the gun is further
        if (BRP_Shock_t_DirDiff > 45) {
            if (!BRP_Shock_m_IsDebug) {
                return;
            };
        };



		vector BRP_Shock_t_MuzzlePos = this.GetSelectionPositionLS( "Usti hlavne" ); 
        vector start = this.ModelToWorld(BRP_Shock_t_MuzzlePos);
        
        ref array<Object> arr_objects = new array<Object>;
        GetGame().GetObjectsAtPosition(start, 1.0, arr_objects, null);

        string t_Types = "";




        

        foreach(Object t_Obj: arr_objects) {
            string t_ObjStr = t_Obj.GetType();
            t_ObjStr.ToLower();
            if (t_ObjStr.Contains("bullet")) {
                vector t_Vel = t_Obj.GetPosition();
                float BRP_Shock_t_Speed = Math.AbsFloat(t_Vel[0]) + Math.AbsFloat(t_Vel[2]);            

                t_Types = t_Types + t_Obj.GetType() + "->" + t_Obj.Type() + "|" + t_Obj.GetDirection();
                if (t_Obj && t_Obj != NULL) {
                    BRP_Shock_AddSupp(t_Obj,BRP_Shock_t_Dist);
                };
            };
        };
    };

    void BRP_Shock_AddSupp (Object f_Obj, float f_Dist) {

        // check for null
        if (!f_Obj || f_Obj == NULL) {
            return;
        };

        string t_ObjType = f_Obj.GetType(); 
        string t_Path;
        float t_Speed;
        float t_Damage;

        t_Path = "CfgAmmo " + t_ObjType;
        t_Speed = GetGame().ConfigGetFloat(t_Path + " initSpeed");
        t_Damage = GetGame().ConfigGetFloat(t_Path + " DamageApplied Health damage");

        // calculate the strength of the bullet
        int t_Pwr = 0;
        t_Pwr = t_Pwr + Math.Floor(t_Speed/200);
        t_Pwr = t_Pwr + Math.Floor(t_Damage/30);

        // testing only
        if (BRP_Shock_m_IsDebug) {
            f_Dist = 55;
        };

        // limit the distance
        // limited from 5 to 35m
        // at 35m the effect will be 1 (full)
        f_Dist = Math.Clamp(f_Dist,5,35);
        f_Dist = f_Dist/35;

        t_Pwr = Math.Round(t_Pwr * f_Dist);

        if (t_Pwr < 1) {
            return;
        };

        // add the bullet to an array, constantly check the array
        BRP_Shock_m_ArrBulletsToAdd.Insert(new Param3<ref Object,int,bool>(f_Obj,t_Pwr,false));

        if (!BRP_Shock_m_IsCheckRunning) {
            BRP_Shock_CheckSupp();
        };
    };

    // Param3:
    //  Object          - The bullet
    //  int             - Strenght 1 - 10
    //  bool            - IsDoneSupp (has the bullet already done a little bit of suppression)

    ref array<ref Param3<ref Object,int,bool>> BRP_Shock_m_ArrBullets = new array<ref Param3<ref Object,int,bool>>;

    ref array<ref Param3<ref Object,int,bool>> BRP_Shock_m_ArrBulletsOld = new array<ref Param3<ref Object,int,bool>>;
    ref array<ref Param3<ref Object,int,bool>> BRP_Shock_m_ArrBulletsToAdd = new array<ref Param3<ref Object,int,bool>>;
    bool BRP_Shock_m_IsCheckRunning = false;


    // check the array of bullets that can cause suppression
    void BRP_Shock_CheckSupp () {

        BRP_Shock_m_IsCheckRunning = true;

        // add the new bullets to the check array
		for ( int i = 0; i < BRP_Shock_m_ArrBulletsToAdd.Count(); i++ ) {
			BRP_Shock_m_ArrBullets.Insert( BRP_Shock_m_ArrBulletsToAdd.Get(i) );
		};

        BRP_Shock_m_ArrBulletsToAdd.Clear();

        // copy the old array 
        BRP_Shock_m_ArrBulletsOld = BRP_Shock_m_ArrBullets;
        BRP_Shock_m_ArrBullets = new array<ref Param3<ref Object,int,bool>>;

        int BRP_Shock_t_SuppCount = 0;

        for (int t_i=0; t_i < BRP_Shock_m_ArrBulletsOld.Count(); t_i++) {
            ref Param3<ref Object,int,bool> t_Param3 = BRP_Shock_m_ArrBulletsOld.Get(t_i);

            ref Object t_Obj = t_Param3.param1;
            if (!t_Obj || t_Obj == NULL) {
                continue;
            };

            int t_Pwr = t_Param3.param2;

            // check distance from player
            // distance check
            float BRP_Shock_t_Dist = vector.Distance(GetGame().GetPlayer().GetPosition(), t_Obj.GetPosition());

            // initial suppression, with small effect, only done once
            if (BRP_Shock_t_Dist >= 5 && BRP_Shock_t_Dist < 30 && !t_Param3.param3) {
                
                t_Param3.param3 = true;

                float t_Mod = Math.InverseLerp(30,5,BRP_Shock_t_Dist);
                t_Mod = Math.Lerp(0.1,0.4,t_Mod);

                // add half effect at 20m
                BRP_Shock_t_SuppCount += Math.Round(t_Pwr * t_Mod);
            };

            // do close suppression (extra supp for < 5m), full effect
            if (t_Param3.param3) {
                
                if (BRP_Shock_t_Dist < 5) {

                    // add full effect at 5m
                    BRP_Shock_t_SuppCount += t_Pwr;
                    continue;
                };

                // skip if the distacen is bigger than 35
                if (BRP_Shock_t_Dist > 35) {
                    continue;
                };
            };
            
            // add the bullet back if the distance is < 1500 still
            if (BRP_Shock_t_Dist < 1500) {

                // re-add for checking next time
                BRP_Shock_m_ArrBullets.Insert(t_Param3);
            };
        };

        if (BRP_Shock_t_SuppCount > 0) {

            // instant effect for client
            if (BRP_Shock_ShockEffect.BRP_Shock_g_ShockMain == NULL) {
                return;
            };

            BRP_Shock_ShockEffect.BRP_Shock_g_ShockMain.ShockEffectSetForceExtra(BRP_Shock_t_SuppCount);

            // bullet close, suppression call
            GetRPCManager().SendRPC( "RPC_BRP_Shock_Supp", "SuppressRPC", new Param2<int, Man>(BRP_Shock_t_SuppCount, GetGame().GetPlayer()) );
        };

        delete BRP_Shock_m_ArrBulletsOld;

        if (BRP_Shock_m_ArrBullets.Count() == 0) {
            BRP_Shock_m_IsCheckRunning = false;
            return;
            
        };

        // run the same function again
        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(BRP_Shock_CheckSupp, 1, false, t_Obj);
    };

};