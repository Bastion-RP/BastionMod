modded class PlayerBase {

    // run set can use map code after the multichar stats are enabled
	override void SetMultiCharacterStats(int multicharactersPlayerId, string multicharactersPlayerName, int multicharactersPlayerClass) {
        super.SetMultiCharacterStats(multicharactersPlayerId,multicharactersPlayerName,multicharactersPlayerClass);
        
        BRP_VPPMapFixes_SetCanUseMap();
	};

    // sets the 3d markers on or off based on player class
    void BRP_VPPMapFixes_SetCanUseMap () {
        
        // find player class
        int t_PlayerClass = GetMultiCharactersPlayerClass();

        // apply override
        GetDayZGame().BRP_VPPMapFixes_SetIs3dMarkerAllowed(!(t_PlayerClass < BastionClasses.ISF_F || t_PlayerClass > BastionClasses.ISF_E));
        BRP_VPPMapFixes_Say("done");
        BRP_VPPMapFixes_Say("status: " + GetDayZGame().CanUse3DMarkers());
    };
};