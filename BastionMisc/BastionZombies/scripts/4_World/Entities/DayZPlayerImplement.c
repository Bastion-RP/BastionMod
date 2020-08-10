modded class DayZPlayerImplement {
	bool BRP_Misc_Zombies_OnEvalHit (TotalDamageResult pDamageResult, int pDamageType, EntityAI pSource, string pComponent, string pAmmoType, vector pModelPos, out int pAnimType, out float pAnimHitDir, out bool pAnimHitFullbody, bool f_IsHitAnim) {
		bool t_IsHitAnim = f_IsHitAnim; // get current hit state from super

        if (pDamageType != DT_CLOSE_COMBAT) {
            return t_IsHitAnim;
        };
		if (!IsAlive()) {
			return t_IsHitAnim;
		};
		
		if (!pSource) {
			return t_IsHitAnim;
		};
    
        ZombieBase t_ZB = ZombieBase.Cast(pSource);

        if (!t_ZB) {
            return t_IsHitAnim;
        };

        float t_DmgMod = t_ZB.BRP_Misc_Zombies_GetAtkMod();
        if (t_DmgMod != -1) {
			float t_HPBefore = GetHealth("","Health");
			
            // Increase HP by half the damage taken, this makes the total damage taken only half
            float dayxSrv_t_DmgHP = pDamageResult.GetDamage("","Health");
			dayxSrv_t_DmgHP = 0 - ((dayxSrv_t_DmgHP * t_DmgMod) - dayxSrv_t_DmgHP);
            AddHealth("","Health",dayxSrv_t_DmgHP);
        };


        
		// only ccontinue if a hit animation did not occur
		if (!t_IsHitAnim) {
			return t_IsHitAnim;
		};

        float t_KnockBackChance = 0;
        if (t_DmgMod >= 3) {
            t_KnockBackChance = 70;
        } else if (t_DmgMod >= 2) {
            t_KnockBackChance = 40;
        } else if (t_DmgMod >= 1) {
            t_KnockBackChance = 15;
        };
        
        if (t_KnockBackChance > 0 && Math.RandomInt(0,100) >= (100-t_KnockBackChance)) {
            
            // x2 smaller chance to get a knockback that's heavy
            if (t_DmgMod >= 3.0 && Math.RandomInt(-100,100) >= (100 - t_KnockBackChance)) {
                pAnimHitFullbody = true;
            };

            // cause player to knockback
            return true;

        };

        return t_IsHitAnim;
	};
	
	//! selects animation type and direction based on damage system data
	bool EvaluateDamageHitAnimation(TotalDamageResult pDamageResult, int pDamageType, EntityAI pSource, string pComponent, string pAmmoType, vector pModelPos, out int pAnimType, out float pAnimHitDir, out bool pAnimHitFullbody)	{
        bool t_IsHitAnim = super.EvaluateDamageHitAnimation(pDamageResult,pDamageType,pSource,pComponent,pAmmoType,pModelPos,pAnimType,pAnimHitDir,pAnimHitFullbody);
		
		return (BRP_Misc_Zombies_OnEvalHit(pDamageResult,pDamageType,pSource,pComponent,pAmmoType,pModelPos,pAnimType,pAnimHitDir,pAnimHitFullbody,t_IsHitAnim));
    };
};