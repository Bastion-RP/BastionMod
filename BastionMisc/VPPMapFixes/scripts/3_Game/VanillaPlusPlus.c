modded class DayZGame {
    
    bool BRP_VPPMapFixes_Is3dMarkerAllowed = false;
    void BRP_VPPMapFixes_SetIs3dMarkerAllowed (bool BRP_VPPMapFixes_f_Is3dMarkerAllowed) {
        BRP_VPPMapFixes_Is3dMarkerAllowed = BRP_VPPMapFixes_f_Is3dMarkerAllowed;
        if (BRP_VPPMapFixes_f_Is3dMarkerAllowed) {
            return;
        };
        SetUse3DMarkers(false);
        
        // hide existing markers
        if (!m_TempHidden3dMarkers) {
            HideAll3dMarkers();
        };
    };

    void TempToggleAll3dMarkers() {
        if (!BRP_VPPMapFixes_Is3dMarkerAllowed) {
            return;
        };

        super.TempToggleAll3dMarkers();
    };
};