modded class MissionServer {

    ref BRP_NameTagsSrv_NameTagsHandler BRP_NameTagsSrv_NameTagsHandler_m_Handler;

    void MissionServer () {
        BRP_NameTagsSrv_NameTagsHandler_m_Handler = new ref BRP_NameTagsSrv_NameTagsHandler;
        
    };
};