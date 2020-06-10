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
modded class DayZPlayerCameraBase {


	void 	StdFovUpdate(float pDt, out DayZPlayerCameraResult pOutResult)
	{



		PlayerBase BRP_GunPlay_t_PB = PlayerBase.Cast(GetGame().GetPlayer());
		float BRP_GunPlay_t_Zoom = GameConstants.DZPLAYER_CAMERA_FOV_EYEZOOM;
		float BRP_GunPlay_t_Normal = g_Game.GetUserFOV();
		float BRP_GunPlay_BRP_GunPlay_t_SpeedMod = 0.3;


		// check for movement speed 
		int BRP_GunPlay_t_Speed = DayZPlayerImplement.Cast(m_pPlayer).m_MovementState.m_iMovement;
		if (BRP_GunPlay_t_Speed == DayZPlayerConstants.MOVEMENTIDX_IDLE) {
			// standing still

			//BRP_GunPlay_t_Zoom = 0.44;
			BRP_GunPlay_t_Zoom = 0.3926;
		} else if (BRP_GunPlay_t_Speed == DayZPlayerConstants.MOVEMENTIDX_WALK) {
			// walking

			BRP_GunPlay_t_Zoom = 0.54;
			//BRP_GunPlay_t_Zoom = 0.44;
		} else if (BRP_GunPlay_t_PB.IsSprinting()) {
			// sprinting

			BRP_GunPlay_t_Zoom = 0.7;
			BRP_GunPlay_t_Normal = Math.Max(BRP_GunPlay_t_Zoom,BRP_GunPlay_t_Normal);
		} else {
			// jogging or default

			BRP_GunPlay_t_Zoom = 0.6;
			BRP_GunPlay_t_Normal = Math.Max(BRP_GunPlay_t_Zoom,BRP_GunPlay_t_Normal);
		};

		// Cases for jumping,fallling climbing
		if (BRP_GunPlay_t_PB.IsJumpInProgress() || BRP_GunPlay_t_PB.IsClimbingLadder() || BRP_GunPlay_t_PB.IsClimbing() || BRP_GunPlay_t_PB.IsFalling()) {

			BRP_GunPlay_t_Zoom = 0.7;
			BRP_GunPlay_t_Normal = Math.Max(BRP_GunPlay_t_Zoom,BRP_GunPlay_t_Normal);
		};


		//! change abs FOV for naked eye zoom
		if (m_pPlayer.IsEyeZoom()) {
			m_fFovAbsolute = Math.SmoothCD(m_fFovAbsolute, BRP_GunPlay_t_Zoom, m_fFovAbsVel, 0.1, 1000, pDt*0.3);
		} else {
			m_fFovAbsolute = Math.SmoothCD(m_fFovAbsolute, BRP_GunPlay_t_Normal, m_fFovAbsVel, 0.1, 1000, pDt*0.5);
		};

		pOutResult.m_fFovAbsolute = m_fFovAbsolute;

		//! switch shooting from camera to weapon (firearms)
		if (!m_pPlayer.IsShootingFromCamera())
		{
			pOutResult.m_fShootFromCamera = 0.0;
		}
	};
};