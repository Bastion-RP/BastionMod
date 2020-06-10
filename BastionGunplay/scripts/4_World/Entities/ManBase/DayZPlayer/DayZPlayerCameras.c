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
modded class DayZPlayerCameras {


	static float 	OnCameraChange(DayZPlayer pPlayer, int pFrom, int pTo)	{

		float BRP_GunPlay_t_TransTime = GetTransitionTime(pFrom, pTo);

			
		if (((pFrom <= DAYZCAMERA_3RD_PRO_RAISED) && (pTo == DAYZCAMERA_IRONSIGHTS || pTo == DAYZCAMERA_OPTICS)) ||	((pFrom == DAYZCAMERA_IRONSIGHTS || pFrom == DAYZCAMERA_OPTICS) && (pTo <= DAYZCAMERA_3RD_PRO_RAISED))) {
			BRP_GunPlay_t_TransTime = BRP_GunPlay_t_TransTime * 2;

			// modified based on weight
			Weapon_Base BRP_GunPlay_t_Weapon = Weapon_Base.Cast(pPlayer.GetHumanInventory().GetEntityInHands());
			float BRP_GunPlay_t_Weight = BRP_GunPlay_t_Weapon.GetWeight();                        // in grams


			// based on weight from 1250g to 7500 mult 1x to 3x
			float BRP_GunPlay_t_Mod = Math.Clamp(Math.Lerp(1,3,Math.InverseLerp(1250,7500,BRP_GunPlay_t_Weight)),1,3);
			BRP_GunPlay_t_TransTime = BRP_GunPlay_t_TransTime * BRP_GunPlay_t_Mod;
		};

		return BRP_GunPlay_t_TransTime;		
	};

};