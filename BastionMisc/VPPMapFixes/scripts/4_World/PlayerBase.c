modded class PlayerBase {

    // run set can use map code after the multichar stats are enabled
	override void BSTMCSetCharData(int CharID, string charName, int charClass) {
        super.BSTMCSetCharData(CharID,charName,charClass);
        
        BRP_VPPMapFixes_SetCanUseMap();
	};

    // sets the 3d markers on or off based on player class
    void BRP_VPPMapFixes_SetCanUseMap () {
        
        // find player class
        int t_PlayerClass = GetMultiCharactersPlayerClass();

        // apply override
        GetDayZGame().BRP_VPPMapFixes_SetIs3dMarkerAllowed(!(t_PlayerClass < BastionClasses.ISF_F || t_PlayerClass > BastionClasses.ISF_E));
    };
};