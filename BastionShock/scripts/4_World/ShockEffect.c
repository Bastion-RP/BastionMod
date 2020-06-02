class BRP_Shock_ShockEffect {
	
	// creator function
	void BRP_Shock_ShockEffect () {

		// if we are not a client and we are in multiplayer, leave now
		if (!GetGame().IsClient() && GetGame().IsMultiplayer()) {
			return;
		};

		// client init code
		ClientInit();

		// reset on start
		ShockEffectReset ();

	}

	ref static BRP_Shock_ShockEffect BRP_Shock_g_ShockMain;

	// initialize variables and stuff 
	void ClientInit () {


		if (BRP_Shock_g_ShockMain != NULL) {
			delete BRP_Shock_g_ShockMain;
		};

		BRP_Shock_g_ShockMain = this;
		
		
		m_MatRotBlur = GetGame().GetWorld().GetMaterial("graphics/materials/postprocess/rotblur");
		m_MatRadBlur = GetGame().GetWorld().GetMaterial("graphics/materials/postprocess/radialblur");
		m_MatGlow = GetGame().GetWorld().GetMaterial("graphics/materials/postprocess/glow");
		m_MatChrom = GetGame().GetWorld().GetMaterial("graphics/materials/postprocess/chromaber");

		// Add the shock effect updater
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(Update, 0, true);

	};


	Material m_MatRotBlur;
	Material m_MatRadBlur;
	Material m_MatGlow;
	Material m_MatChrom;
	

    void BRP_Shock_Debug (string msg) {
        return; // return debug disabled

        msg = "BRP_Shock." + msg;
        GetGame().GetMission().OnEvent(ChatMessageEventTypeID, new ChatMessageEventParams(CCDirect, "", msg, ""));
        Print(msg);


    };

	float m_TickTimeLast = 0;

	void Update () {
		float deltatime = GetGame().GetTickTime() - m_TickTimeLast;
		m_TickTimeLast = GetGame().GetTickTime();
		
		BRP_Shock_Debug("+++++++++++Run+++++++++++");
		BRP_Shock_Debug("deltaTime:" + deltatime);

		// if the evaluation returns false, reset :O
		if (!EvaluateShock(deltatime)) {
			ShockEffectReset();
		};
		
		// save old shock
		m_HPOld = GetShockHealth();

		
	};
	


	void Delete() {
		ShockEffectReset();
		GetGame().GetCallQueue(CALL_CATEGORY_GUI).Remove(Update);
	}

	void ~BRP_Shock_ShockEffect() {
		

		// if we are not a client and we are in multiplayer, leave now
		if (!GetGame().IsClient() && GetGame().IsMultiplayer()) {
			return;
		};
		
		Delete();
	}


	float m_HPOld = 1.0;

	// Evaluate the shock ( main function )
	bool EvaluateShock (float deltatime) {
		
		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());

		// player exists
		if (!player || player == NULL) {
			return false;
		};

		// player is dead
		if (!player.IsAlive()) {
			return false;
		};


		//--- Disable these sainty checks because unconsciousness is not applied instantly (dayzbug)
		// Make sure player is not unconscious
		if (GetShockHealth() <= (PlayerConstants.UNCONSCIOUS_THRESHOLD / player.GetMaxHealth("","Shock")) || player.IsUnconscious()) {
		 	//return false;
		};
		
		// if shock is really low and player is not unconscious, return false?
		if (GetShockHealth() <= (PlayerConstants.UNCONSCIOUS_THRESHOLD / player.GetMaxHealth("","Shock")) && player.IsUnconscious()) {
		 	//return false;
		};
		//---




		// special time check
		if (GetShockHealth() == 1.0 && GetGame().GetTickTime() > (m_ShockEffectForceExtraNext + 1)) {	// check if shock is already full
			return false;
			//TODO test;
		};
		//--- Sanity Checks Done
		
		ShockEffect(deltatime);

		return true;
	}


	// reset function to disable the effects
	void ShockEffectReset () {
		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());

		if (player) {
			// reset hpold (just in case bro)
			m_HPOld = GetShockHealth();
		} else {
			m_HPOld = 0.0;
		};
		
		m_ShockEffectExtra = 0;
		m_ShockEffectToAdd = 0;
		m_ShockEffectToAddMax = 0;
		m_ShockEffectToAddMaxBackup = 0;
		ShockEffectApply(0.0, true);
	};

	// returns shock health:
	// Gets the shock percentage (as float 0.0  == 0 | 1.0 = 100)
	// lerp from unconscious threshold to max shock (0 == uncon threshold)
	float GetShockHealth () {
		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
		
		if (player) {
			float t_ShockNormalized = player.GetSimplifiedShockNormalized();
			BRP_Shock_Debug("shocknormalized:" + t_ShockNormalized);

			// min and max for re-normalization
			float t_Min = PlayerConstants.UNCONSCIOUS_THRESHOLD;
			float t_Max = player.GetMaxHealth("","Shock");

			// ShockHP when 0 is the uncsoncious threshold
			// denormalized into hp == 1.0 -> 100 | 0.25 -> 0
			float t_ShockHP = Math.Lerp(t_Min, t_Max, t_ShockNormalized);

			// clamp it
			t_ShockHP = Math.Clamp(t_ShockHP, t_Min, t_Max);


			// normalize it again
			t_ShockHP = Math.InverseLerp(t_Min, t_Max, t_ShockHP);

			// fake shock
			//if (m_ShockEffectForceExtra3) {
			//	t_ShockHP = t_ShockHP + m_ShockEffectForceExtra3FakeShock;
			//};

			return t_ShockHP;




			//return Math.InverseLerp(PlayerConstants.UNCONSCIOUS_THRESHOLD, player.GetMaxHealth("","Shock"), player.GetHealth("","Shock"));
		};
		return 0.0;
	};



	bool m_ShockEffectForceExtra = false;
	float m_ShockEffectForceExtraSize = 0.05;
	float m_ShockEffectForceExtraMax = 0.05;
	float m_ShockEffectForceExtraNext = 0;

	void ShockEffectSetForceExtra (int f_size) {

		float t_time = GetGame().GetTickTime();

		// Only allow to add by limit
		if (t_time < m_ShockEffectForceExtraNext && m_ShockEffectForceExtra) {
			return;
		};
		m_ShockEffectForceExtraNext = t_time + (f_size * 0.25);

		f_size = Math.Clamp(f_size,1,8);


		// arbitary shock size
		float t_ForceExtraSize = 0.005;
		//t_ForceExtraSize = t_ForceExtraSize + Math.Lerp(0.0,0.03,Math.Clamp(Math.InverseLerp(0.9,1.0,GetShockHealth()),0,1));
		

		// choose the size:
		m_ShockEffectForceExtraMax = 0.08 + t_ForceExtraSize * f_size;
		m_ShockEffectForceExtraSize = 0 - m_ShockEffectForceExtraMax*0.5;

		m_ShockEffectForceExtra = true;
		//m_HPOld = m_HPOld + 0.25;
            
	};



	void ShockEffect (float deltatime) {
		
		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
		
		// get shock hp
		float t_ShockHP = GetShockHealth();

		if (m_ShockEffectForceExtraNext >= 0) {
			t_ShockHP = t_ShockHP - (m_ShockEffectForceExtraMax/2 - Math.AbsFloat(m_ShockEffectForceExtraSize));	// size will be /2 and - (0.5 = 0.25 = -0.25) until size = /2
			// 0.5/2 = 0.25			- (0.25)

		};


		// get last shockhp and save the current one
		float t_ShockHPOld = m_HPOld;

		// check for big drop in shock
		float t_ShockLost = t_ShockHPOld - t_ShockHP;

		if (t_ShockLost >= 0.05) {
			// Big change
			// temporary effect

			float t_ShockLostMod = t_ShockLost * 4;	// 0.25 turns into 1

			// update toadds
			m_ShockEffectToAdd = t_ShockLostMod;
			m_ShockEffectToAddMax = t_ShockLostMod;
			m_ShockEffectToAddMaxBackup = t_ShockLostMod;

		};
		if (m_ShockEffectForceExtraSize < (m_ShockEffectForceExtraMax/2)) {

			float t_ChangeSize = 0.35 * deltatime;
			
			// keep the extra eneabled until the limit has been cleared
			if (m_ShockEffectForceExtraSize > 0) {
				t_ChangeSize = 0.25 * deltatime;
				if (m_ShockEffectForceExtra) {
					m_ShockEffectForceExtra = false;
				};
			} else {
			};
			// reduce extra size instead
			m_ShockEffectForceExtraSize = Math.Clamp(m_ShockEffectForceExtraSize + t_ChangeSize,-m_ShockEffectForceExtraMax/2,m_ShockEffectForceExtraMax/2);
		};

		BRP_Shock_Debug("HP:" + t_ShockHP);

		//--- shock effect
		// calculate the shockeffect for this frame
		// it's shock damage (aka reversed shock health)
		float t_ShockEffect = 1-t_ShockHP;
		float t_ShockEffectExtra = 0;



		//--- calc modifier
		float t_ModifierExtra = 0.01;


		// only calculate when needed
		if (m_ShockEffectToAdd > 0 || m_ShockEffectExtra > 0) {

			float t_ModifierRemaining;
			if (m_ShockEffectToAdd > 0) {
				t_ModifierRemaining = m_ShockEffectToAdd;
			} else {
				t_ModifierRemaining = m_ShockEffectExtra;
			};

			// modifier size has to be dependant on toAdd remaining
			t_ModifierExtra = Math.InverseLerp(0, m_ShockEffectToAddMaxBackup, t_ModifierRemaining);
			t_ModifierExtra = Math.Clamp(t_ModifierExtra, 0, 3);

			float t_SizeMod = Math.InverseLerp(0.0, 3.0, m_ShockEffectToAddMaxBackup);
			t_SizeMod = Math.Lerp(5, 40, t_SizeMod);
			t_SizeMod = Math.Clamp(t_SizeMod, 5, 60);

			// ease it in/out
			t_ModifierExtra = Easing.EaseInOutBounce(t_ModifierExtra);
			t_ModifierExtra += (0.1 * deltatime);	// slower because now that fps is faster it has to be something 

			// times 10, means that when the toAdd is maxed above^^^, it will be 1, which would mean 1 per second thanks to deltatime. So we multiply by 10
			t_ModifierExtra *= t_SizeMod;
			BRP_Shock_Debug("sizeMod:" + t_SizeMod);

			// based on time
			t_ModifierExtra *= deltatime;
		};

		// when the toadd is depleted, reset the max
		if (m_ShockEffectToAdd <= 0) {
			m_ShockEffectToAddMax = 0;
		};

		BRP_Shock_Debug("mod:" + t_ModifierExtra);

		// add temporary effect
		if (m_ShockEffectToAdd > 0) {
			BRP_Shock_Debug("adding");
			// add extra shock from sudden change

			// the modifier is how much is added until the required effect has been reached.
			// the add will mean that the max should be reached in 0.1 seconds every time.

			// faster effect when adding
			t_ModifierExtra *= 2;
			m_ShockEffectExtra += t_ModifierExtra;

			// remove from the toadd
			m_ShockEffectToAdd -= t_ModifierExtra;
		

		} else {
			// no extra needed to add

			// if the current extra exists, bleed it
			if (m_ShockEffectExtra > 0) {

				// removing is a bit slower (x2)
				t_ModifierExtra *= 0.5;
				m_ShockEffectExtra -= t_ModifierExtra;
				

				// make sure 0 is not breached
				if (m_ShockEffectExtra < 0) {
					m_ShockEffectExtra = 0;
				};
				
			};
		};

		// real shock effect with the extra added on top
		t_ShockEffect += m_ShockEffectExtra;
		BRP_Shock_Debug("extra:" + m_ShockEffectExtra);
		BRP_Shock_Debug("toAdd:" + m_ShockEffectToAdd);

		ShockEffectApply(t_ShockEffect);
	};

	// sets the post process effects based on shock effect
	void ShockEffectApply (float shockEffect, bool shockEffectReset = false) {
		
		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());

		float t_ShockEffectOriginal = shockEffect;

		// if there is no need for change, then bye bye
		if (shockEffect == m_ShockEffectCurrent) {
			if (shockEffect >= 1.0 || shockEffect <= 0.0) {
				return;
			};
		};
		m_ShockEffectCurrent = shockEffect;
		
		BRP_Shock_Debug("shockEffect:" + shockEffect);

		// half shock effect, this way the amount of extra has a better and more noticable effect and does not max the effects
		shockEffect *= 0.5;

		

		// TODO osciallating extra
		// - I can just use the ToAdd and play off of that.
		//		- that one might be too fast
		// - I can just use custom code
		//		- better adjustment
		//		- add a custom extra so I can remove separately
		//		- or use the current extra so it auto-removes *this is also bad
		//
		float t_ShockOsc = 0;
		if (shockEffect > 0) {


			// smooth the oscillation rate based on the shock damage, the higher the damage, the faster the osciallation
			// The higher the oscrate is the faster the oscillation, 1k = 1x per second?, 500 = 0.5x per second?
			// oscrate is how many refreshes in a second, 1000 = 1 refresh | 500 = 0.5 refresh | 2000 = 2 refresh
			float t_ShockOscRate = 1000;
			float t_ShockOscExtra = 1;
			BRP_Shock_Debug("oscRate:" + t_ShockOscRate);


			if (t_ShockEffectOriginal > 0.75) {

				t_ShockOscRate = 2300;
				t_ShockOscExtra = 2;
			} else if (t_ShockEffectOriginal > 0.5) {
				t_ShockOscRate = 1500;
				t_ShockOscExtra = 1.5;
			};


			// Multiplying by 100, this way the result is more accurate (0.155 instead of 0.1)
			// current time multiplied by the Oscillation rate (which is over 1k to allow 3 decimals to be included for accuracy)
			int t_TimeInt = GetGame().GetTickTime() * t_ShockOscRate;// putting 30 here instead of 10 makes it reset every 0.3 seconmds

			// use modulo to make it reset every 1000 units
			t_TimeInt = t_TimeInt % 1000;
			float t_TimeFloat = t_TimeInt * 0.001;
			
			// make timefloat smalller so effect is smaller
			t_TimeFloat *= 0.1;

			// oscillation is -0.025 + timefloat ( meaning it goes from -0.025 to 0.025)
			t_ShockOsc = 0.0 + t_TimeFloat;

			// if timefloat is bigger than half (oscillation would be 0)
			if (t_TimeFloat > 0.05) {

				// oscillation is 0.025 - timefloat, this starts at 0.025 so this would mean from 0 to -0.025
				t_ShockOsc = 0.1 - t_TimeFloat;
				
				//BRP_Shock_Debug("timefloat flip");
			};
			t_ShockOsc *= t_ShockOscExtra;
			BRP_Shock_Debug("timefloat:" + t_TimeFloat);
			BRP_Shock_Debug("osc:" + t_ShockOsc);

			// custom code to make it so that near the end (close to full hp) the effect doesn't suddenly cut off
			if (t_ShockEffectOriginal < 0.1) {

				// this will make it so that at 90% hp, the effect is 1x, but then linearly the effectiveness decreases
				t_ShockOsc *= Math.InverseLerp(0.0, 0.1, t_ShockEffectOriginal);
			};
			shockEffect += t_ShockOsc;
		};

		
		// rotational blur
		// Clamped
		float t_EffectRotBlur = Math.Lerp(0.01, 0.25, shockEffect);
		t_EffectRotBlur = Math.Clamp(t_EffectRotBlur, 0.01, 0.5);
		
		// radial blur
		float t_EffectRadBlurX = Math.Lerp(-0.001, 0.04, shockEffect);
		t_EffectRadBlurX = Math.Clamp(t_EffectRadBlurX, 0.0, 0.08);

		float t_EffectRadBlurY = Math.Lerp(-0.001, 0.03, shockEffect);
		t_EffectRadBlurY = Math.Clamp(t_EffectRadBlurY, 0.0, 0.08);

		float t_EffectVignetteBurner = 0;

		// burner for vignette if the effect is really low
		if (shockEffect <= 0.1) {
			t_EffectVignetteBurner = Math.InverseLerp(0.0, 0.1, shockEffect);
			t_EffectVignetteBurner = Math.Lerp(0.35, 0, t_EffectVignetteBurner);
		};

		// vignette
		float t_EffectVignette = Math.Lerp(0.3, 1.0, (Easing.EaseOutCirc(shockEffect) + t_ShockOsc));

		// if shock effect is over 1.0, then do the function without easoutCirc
		if (shockEffect >= 1) {
			t_EffectVignette = Math.Lerp(0.3, 1.0, ((shockEffect) + t_ShockOsc));
		};
		if (m_ShockEffectToAddMax > 0 || m_ShockEffectExtra > 0) {
		};
		t_EffectVignette -= t_EffectVignetteBurner;
		t_EffectVignette = Math.Clamp(t_EffectVignette, 0.0, 2.0);

		// chromatic aberration
		float t_ChromX = Math.Lerp(-0.001, 0.05, shockEffect);
		t_ChromX = Math.Clamp(t_ChromX, 0.0, 0.1);

		float t_ChromY = Math.Lerp(-0.001, 0.025, shockEffect);
		t_ChromY = Math.Clamp(t_ChromY, 0.0, 0.075);

		if (shockEffectReset) {
			t_EffectRotBlur = 0;
			t_EffectRadBlurX = 0;
			t_EffectRadBlurY = 0;
			t_EffectVignette = 0;
			t_ChromX = 0;
			t_ChromY = 0;
		};

		// skip the params, fps test

		// apply the effect
        m_MatRotBlur.SetParam("Power", t_EffectRotBlur);
        m_MatRadBlur.SetParam("PowerX", t_EffectRadBlurX);
        m_MatRadBlur.SetParam("PowerY", t_EffectRadBlurY);
		if (player && !player.IsUnconscious()) {

			// check for blindness protection
			if (t_EffectVignette > 0.9) {
				if (GetGame().GetTickTime() > m_BlindProtectNext) {
					m_BlindProtectNext = GetGame().GetTickTime() + 1;
        			m_MatGlow.SetParam("Vignette", t_EffectVignette * 0.5);
				};
			};
			
        	m_MatGlow.SetParam("Vignette", t_EffectVignette);
		};
		if (player && (player.IsUnconscious() || !player.IsAlive())) {
        	m_MatGlow.SetParam("Vignette", 0);
		};
        m_MatChrom.SetParam("PowerX", t_ChromX);
        m_MatChrom.SetParam("PowerY", t_ChromY);
	};

	float m_ShockEffectCurrent = 0;		// current shock effect
	float m_ShockEffectExtra = 0;		// extra shock effect added on the current
	float m_ShockEffectToAdd = 0;		// extra shock effect that still needs to be added
	float m_ShockEffectToAddMax = 0;	// max of the current to extra (used for easing)
	float m_ShockEffectToAddMaxBackup = 0;	// used as a backup max for the modifier of the temporary effect (sudden shock)
	float m_BlindProtectNext = 0;

}
