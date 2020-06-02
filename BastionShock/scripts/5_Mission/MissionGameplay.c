modded class MissionGameplay {

    ref BRP_Shock_SuppRPC BRP_Shock_m_SuppRPC;

    void MissionGameplay () {
        BRP_Shock_m_SuppRPC = new ref BRP_Shock_SuppRPC;
    };


    override void OnInit () {
        super.OnInit();
        if (BRP_Shock_ShockEffect.BRP_Shock_g_ShockMain) {
            return;
        };

        BRP_Shock_ShockEffect t_ShockEffect = new BRP_Shock_ShockEffect;
    }
};