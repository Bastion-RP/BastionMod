
enum BRP_Shock_SymptomIDs : SymptomIDs {
    BRP_SYMPTOM_SHOCKLOSS,
};



modded class SymptomManager {

	override void Init() {
        super.Init();
		RegisterSymptom(new ShockLoss);
    };


        
	override void AutoactivateSymptoms() {
        super.AutoactivateSymptoms();

		if( GetGame().IsClient()) {
			return;
		};
		
		QueueUpSecondarySymptom(BRP_Shock_SymptomIDs.BRP_SYMPTOM_SHOCKLOSS);
	};
};
