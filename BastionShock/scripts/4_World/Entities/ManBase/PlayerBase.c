// Copyright 2020 GlutenFreeVapes All Rights Reserved.
//
// Author: GlutenFreeVapes
// Contact: GlutenFreeVapes@gmail.com
// Location: Estonia
// Estonian Copyright Act: https://www.riigiteataja.ee/en/eli/504042019001/consolide
// 
//
//
// Code provided to BastionRP https://bastionrp.com/ for use in the bastionRP servers, mods.
// BastionRP, BastionRP staff, BastionRP adminstration and BastionRP developers are allowed to (redistribrute, modify and build upon the code) for use on bastionRP mods and servers.
//
//
// Copyright 2020 GlutenFreeVapes All Rights Reserved.
modded class PlayerBase {
	const int SIMPLIFIED_SHOCK_CAP = 255; // more accurate shock effect

	int m_ShockSimplified = SIMPLIFIED_SHOCK_CAP;	// makes the shock effect turned OFF when spawning in


	
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