modded class MissionGameplay {
    override void OnInit () {
        super.OnInit();
        if (BRP_Shock_ShockEffect.BRP_Shock_g_ShockMain) {
            return;
        };

        BRP_Shock_ShockEffect t_ShockEffect = new BRP_Shock_ShockEffect;
    }
};