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

	override void EEKilled( Object killer )	{
		super.EEKilled( killer );

		if (GetGame().IsServer()) {
			
			if (this) {
				//GetRPCManager().SendRPC("BRP_NameTags", "RemovePlayerRPC", new Param, true, NULL, this);
			};
		};

		// make sure player is selected and we are in a client
		if (! this.IsPlayerSelected() ||  ! GetGame().IsClient()) {
			return;
		};
		
		BRP_NameTags_GetNameTagHandler().RemoveAllPlayers();
	};

	override void OnDisconnect() {
		super.OnDisconnect();

		if (GetGame().IsServer()) {

			GetRPCManager().SendRPC("BRP_NameTags", "RemovePlayerRPC", new Param, true, NULL, this);
		};

		// make sure player is selected and we are in a client
		if (! this.IsPlayerSelected() ||  ! GetGame().IsClient()) {
			return;
		};
		
		// remove on disconnect
		//delete BRP_NameTags_GetNameTagHandler();
		BRP_NameTags_GetNameTagHandler().RemoveAllPlayers();
	};

	
}
