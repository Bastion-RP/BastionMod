modded class MissionServer {

    ref BRP_Shock_SuppRPC BRP_Shock_m_SuppRPCSrv;

    void MissionServer () {
        BRP_Shock_m_SuppRPCSrv = new ref BRP_Shock_SuppRPC;
    };
};