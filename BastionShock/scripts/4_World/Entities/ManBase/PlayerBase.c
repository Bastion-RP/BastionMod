modded class PlayerBase {
	const int SIMPLIFIED_SHOCK_CAP = 255; // more accurate shock effect


	
	override void EEHitBy(TotalDamageResult damageResult, int damageType, EntityAI source, int component, string dmgZone, string ammo, vector modelPos, float speedCoef) {
		
		// run the parent hitby
		super.EEHitBy(damageResult, damageType, source, component, dmgZone, ammo, modelPos, speedCoef);


        //--- update shock if needed 
		int shock_simplified = SimplifyShock();
		
		// only update if needed
		if(m_ShockSimplified != shock_simplified) {
			m_ShockSimplified = shock_simplified;
			SetSynchDirty();
		};
    };
};