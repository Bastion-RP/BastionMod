class BRP_Shock_SuppRPC {

    // the RPC manager for Suppression systems
    void BRP_Shock_SuppRPC () {
        GetRPCManager().AddRPC( "RPC_BRP_Shock_Supp", "SuppressRPC", this, SingeplayerExecutionType.Client );
    };

    void SuppressRPC ( CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target ) {

        // only continue with server
        if (!GetGame().IsServer()) {
            return;
        };

        Param2< int, Man > data;
        if ( !ctx.Read( data ) ) return;
        

        SuppressPlayer(data.param1, data.param2);
    };

    void SuppressPlayer ( int BRP_f_SuppCount, Man BRP_f_SuppMan ) {

        // 
        PlayerBase BRP_t_Player = PlayerBase.Cast(BRP_f_SuppMan);


        // update the delay to shock regen
        float BRP_t_LastTime = BRP_t_Player.m_LastShockHitTime;

        // calc the delay (if it exists)
        // 130 - 120 = 10;
        // 130 - 135 = -5;
        // 
        float BRP_t_lastTimeDelay = Math.Clamp(BRP_t_LastTime/1000 - GetGame().GetTime()/1000,-PlayerConstants.SHOCK_REFILL_COOLDOWN_AFTER_HIT,25);
        float BRP_t_AddedTime = BRP_f_SuppCount * 0.35;

        // Only add delay if the current delay is < 20 seconds
        if (BRP_t_lastTimeDelay < 20) {
            
            if (BRP_t_lastTimeDelay < 0) {
                BRP_t_AddedTime = BRP_t_AddedTime * 2;
            };

            float BRP_t_NewTimeDelay = Math.Clamp(BRP_t_lastTimeDelay + BRP_t_AddedTime,-PlayerConstants.SHOCK_REFILL_COOLDOWN_AFTER_HIT,25);

            BRP_t_Player.m_LastShockHitTime = GetGame().GetTime() + BRP_t_NewTimeDelay * 1000;
        };

        // do stamina damage
        BRP_t_Player.GetStaminaHandler().DepleteStamina(BRP_f_SuppCount * 0.50);


        // check curretn shock
        float BRP_t_CurrentShock =  BRP_t_Player.GetHealth("GlobalHealth", "Shock");

        float BRP_t_ShockLimit = BRP_t_Player.GetMaxHealth("","Shock") * 0.65;

        // only run if the current shock is higher than conscious threshold
        if (BRP_t_CurrentShock > BRP_t_ShockLimit) {

            // determine current shock %
            float BRP_t_ShockHealthLeft = BRP_t_CurrentShock / BRP_t_Player.GetMaxHealth("","Shock");
            float BRP_t_ShockDmgPerBullet = 0.75;
            float BRP_t_ShockDmg = 0;
            
            // the dmg per bullet increases if the hp left is bigger (big hit at start)
            if (BRP_t_ShockHealthLeft >= 0.85) {
                BRP_t_ShockHealthLeft = Math.InverseLerp(0.85, 1, BRP_t_ShockHealthLeft);
                BRP_t_ShockDmg = BRP_t_ShockDmg + Math.Lerp(0, 4, BRP_t_ShockHealthLeft);

                // remove 1 supp count
                BRP_f_SuppCount = BRP_f_SuppCount - 1;

            };


            BRP_t_ShockDmg = BRP_t_ShockDmg + BRP_f_SuppCount * BRP_t_ShockDmgPerBullet;

            float newShock = BRP_t_CurrentShock - BRP_t_ShockDmg;

            // Calc extra shock which will be clipped
            float extraShock = BRP_t_ShockLimit - newShock;
            if (extraShock > 0) {

                // reduce shock damage
                BRP_t_ShockDmg = Math.Clamp(BRP_t_ShockDmg - extraShock,0,PlayerConstants.CONSCIOUS_THRESHOLD);
            };
            
            BRP_t_Player.AddHealth("GlobalHealth", "Shock", -BRP_t_ShockDmg);
        };

    };

};