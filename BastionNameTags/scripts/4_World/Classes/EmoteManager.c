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
modded class EmoteManager {

    //
    // last active id to check what is active
    int BRP_NameTags_m_LastActiveID = 0;

	//Configure Emote parameters for callback here
	bool PlayEmote( int id ) {

        // leave if not server and the game is not multiplayer
        // 1 - 1 = 0 - 1 == 0
        // 0 - 0 = 1 - 0 == 0
        // 0 - 1 = 1 - 1 == 1   (client and multiplayer)
        if (!GetGame().IsServer() && GetGame().IsMultiplayer()) {
            return super.PlayEmote(id);
        };

        // run the main function
        bool BRP_NameTags_t_IsPlayingEmote = super.PlayEmote( id );

        // if emote is playing succesfully
        if (BRP_NameTags_t_IsPlayingEmote) {

            // update the last active (this one now)
            BRP_NameTags_m_LastActiveID = id;

            // remove the old re-call from the que, if it might exist
            GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Remove(BRP_NameTags_CheckEmote);


            // check the emote for nametag script compatability
            BRP_NameTags_CheckEmote(id);
        };

        return BRP_NameTags_t_IsPlayingEmote;
	}


    void BRP_NameTags_CheckEmote (int BRP_NameTags_f_ID  ) {

        
		//BRP_NameTags_NameTags_Say("BRP_NameTags_CheckEmote.BRP_NameTags_f_ID: " + BRP_NameTags_f_ID);
        
        // make sure an emote is playing and that the last active ID is the same as the current id
        if (!IsEmotePlaying() || BRP_NameTags_m_LastActiveID != BRP_NameTags_f_ID) {

            // remove the que
            GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Remove(BRP_NameTags_CheckEmote);
            return;
        };

        // Different delays for re-calling, based on the type of emote
        int BRP_NameTags_o_ReCheckDelay = 5000;
        bool BRP_NameTags_t_IsAGreeting = false;
        


        // hi wave short range greeting
        if(BRP_NameTags_f_ID ==  EmoteConstants.ID_EMOTE_GREETING) {
            BRP_NameTags_t_IsAGreeting = true;
            BRP_NameTags_o_ReCheckDelay = 1000;
        };

        // Hands far waving
        if(BRP_NameTags_f_ID == EmoteConstants.ID_EMOTE_SOS) {
            BRP_NameTags_t_IsAGreeting = true;
            BRP_NameTags_o_ReCheckDelay = 5000;
        };
        // Love sign (small one)
        if (BRP_NameTags_f_ID == EmoteConstants.ID_EMOTE_HEART) {
            BRP_NameTags_t_IsAGreeting = true;
            BRP_NameTags_o_ReCheckDelay = 500;
        };
        if (BRP_NameTags_f_ID == EmoteConstants.ID_EMOTE_TAUNT) {
            BRP_NameTags_t_IsAGreeting = true;
            BRP_NameTags_o_ReCheckDelay = 500;
        };
        if (BRP_NameTags_f_ID == EmoteConstants.ID_EMOTE_TAUNTELBOW) {
            BRP_NameTags_t_IsAGreeting = true;
            BRP_NameTags_o_ReCheckDelay = 1500;
        };
        
        
        if (!BRP_NameTags_t_IsAGreeting) {
            return;
        };

        // Run the greeting function
        BRP_NameTags_SendGreeting(m_Player,BRP_NameTags_f_ID);

        // re-run the function for as long as the emote is active
        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(BRP_NameTags_CheckEmote, BRP_NameTags_o_ReCheckDelay, false, BRP_NameTags_f_ID);
    };


    // debug enabled?
    bool BRP_NameTags_m_IsDebugActive = false;
    

    // send greeting to other players near this player
    void BRP_NameTags_SendGreeting (PlayerBase f_Player, int BRP_NameTags_f_ID) {
        // TODO
        // can check here if the other player is also doing the same emote
        // then applying a higher tier
        // - MAKE this function working with all options and other emotes
        int BRP_NameTags_t_ID = BRP_NameTags_f_ID;


        // settings and variables that change based on the tier
        //  BRP_NameTags_o_PlayersRange         - range that the players are affected by the greeting/nametag
        //  BRP_NameTags_o_Tier                 - Tier of the tag
        float BRP_NameTags_o_PlayersRange = 15;
        int BRP_NameTags_o_Tier = 5;

        if (BRP_NameTags_t_ID == EmoteConstants.ID_EMOTE_SOS) {
            BRP_NameTags_o_PlayersRange = 700;
            BRP_NameTags_o_Tier = 2;
        };
        if (BRP_NameTags_t_ID == EmoteConstants.ID_EMOTE_HEART) {
            BRP_NameTags_o_PlayersRange = 1.5;    // TODO back to 3
            BRP_NameTags_o_Tier = 3;
        };
        if (BRP_NameTags_t_ID == EmoteConstants.ID_EMOTE_TAUNT) {
            BRP_NameTags_o_PlayersRange = 70;   // from 55   // TODO back to 25
            BRP_NameTags_o_Tier = 7;
        };
        if (BRP_NameTags_t_ID == EmoteConstants.ID_EMOTE_TAUNTELBOW) {
            BRP_NameTags_o_PlayersRange = 50;   // TODO back to 9
            BRP_NameTags_o_Tier = 6;
        };
        if (BRP_NameTags_t_ID == EmoteConstants.ID_EMOTE_SURRENDER) {
            BRP_NameTags_o_PlayersRange = 25;
            BRP_NameTags_o_Tier = 5;
        };




        //PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
        
        // only run on server
        if (GetGame().IsClient()) {
            return;
        };

        // get all players in area        
        ref array<Object> players = new array<Object>;
        ref Man i_target;
        //GetGame().GetPlayers(players);
        GetGame().GetObjectsAtPosition(f_Player.GetPosition(), BRP_NameTags_o_PlayersRange, players, null);
        if (players == NULL || players.Count() == 0) {
            return;
        };
        
        // Loop through the players nearby
        foreach (Object obj: players) {
            i_target = Man.Cast(obj);

            // only run on different player
            if (Man.Cast(f_Player) == i_target) {
                if (!BRP_NameTags_m_IsDebugActive) {
                    continue;
                };
            };

            if (i_target && i_target != NULL) {

                
                // code to only run when doing normal hi greeting
                if (BRP_NameTags_t_ID == EmoteConstants.ID_EMOTE_GREETING) {

                    // reset the tier (might change per character)
                    BRP_NameTags_o_Tier = 5;
                    
                    // if the other player is playing the same emote, increase the tier to 4 (handshaken)
                    if (BRP_NameTags_NameTags_IsPlayingSameEmote(PlayerBase.Cast(i_target), BRP_NameTags_t_ID)) {
                        BRP_NameTags_o_Tier = 4;
                    };
                };

                // heart sign must be playing the same one, or it won't work
                if (BRP_NameTags_t_ID == EmoteConstants.ID_EMOTE_HEART) {
                    //BRP_NameTags_NameTags_Say("ID: " + BRP_NameTags_t_ID + " same: " + BRP_NameTags_NameTags_IsPlayingSameEmote(PlayerBase.Cast(i_target), BRP_NameTags_t_ID));

                    // if the other player is not doing the same emote, skip this loop
                    if (!BRP_NameTags_NameTags_IsPlayingSameEmote(PlayerBase.Cast(i_target), BRP_NameTags_t_ID)) {
                        continue;
                    };
                }; 

                // Elbow flip off is more personal, distance decreased behind the player
                if (BRP_NameTags_f_ID == EmoteConstants.ID_EMOTE_TAUNT) {

                    // the player will remove the other player from itself as well
                    GetRPCManager().SendRPC("BRP_NameTags", "AddPlayerRPC", new Param2<int,string>(BRP_NameTags_o_Tier,""), true, f_Player.GetIdentity(), i_target);
                }; 

                // Elbow flip off is more personal, distance decreased behind the player
                if (BRP_NameTags_f_ID == EmoteConstants.ID_EMOTE_TAUNTELBOW) {

                    // convert dir to target
                    vector BRP_NameTags_t_DirToTarget = vector.Direction(i_target.GetPosition(), f_Player.GetPosition());
                    BRP_NameTags_t_DirToTarget = BRP_NameTags_t_DirToTarget.VectorToAngles();
                    float BRP_NameTags_t_ManDir = (BRP_NameTags_t_DirToTarget[0] - 180);


                    float BRP_NameTags_t_Bone_rot[4];
                    f_Player.GetBoneRotationWS(f_Player.GetBoneIndexByName("Head"), BRP_NameTags_t_Bone_rot);

                    // convert head dir
                    vector BRP_NameTags_t_Orient = Math3D.QuatToAngles(BRP_NameTags_t_Bone_rot);
                    float BRP_NameTags_t_HeadDir = BRP_NameTags_t_Orient[0];


                    // calculate the difference in direction
                    float BRP_NameTags_t_DirDiff = Math.AbsFloat(BRP_NameTags_t_ManDir - BRP_NameTags_t_HeadDir);

                    // if the difference is larger than 180, use a different formula
                    if (BRP_NameTags_t_DirDiff >= 180) {
                        
                        // remove the difference from 360, so it comes down from 180
                        BRP_NameTags_t_DirDiff = 360 - BRP_NameTags_t_DirDiff;
                    };

                    //BRP_NameTags_t_DirDiff = Math.AbsFloat(BRP_NameTags_t_DirDiff - 90);
                    if (BRP_NameTags_t_DirDiff < 45 || BRP_NameTags_t_DirDiff > 135) {
                        // out of range (not in front)

                        continue;
                    };

                    
                    //BRP_NameTags_NameTags_Say("Taunt.Dir1: " + BRP_NameTags_t_ManDir + " Dir2: " + BRP_NameTags_t_HeadDir + " = " + BRP_NameTags_t_DirDiff);
                    //continue;

                    // the player will remove the other player from itself as well
                    GetRPCManager().SendRPC("BRP_NameTags", "AddPlayerRPC", new Param2<int,string>(BRP_NameTags_o_Tier,""), true, f_Player.GetIdentity(), i_target);
                }; 


                // if identity exists, send RPC
                if (i_target.GetIdentity()) {
                    GetRPCManager().SendRPC("BRP_NameTags", "AddPlayerRPC", new Param2<int,string>(BRP_NameTags_o_Tier,f_Player.GetMultiCharactersPlayerName()), true, i_target.GetIdentity(), f_Player);

                    BRP_NameTags_NameTags_Say("Sending from:" + f_Player.GetMultiCharactersPlayerName());
                    //GetRPCManager().SendRPC("BRP_NameTags", "AddPlayerRPC", new Param, true, i_target.GetIdentity(), player);
                };
            };
        };
        delete players;

        // send function to add player
        //GetRPCManager().SendRPC("BRP_NameTags", "AddPlayerRPC", new Param, true, null, player);
    
    };

    bool BRP_NameTags_NameTags_IsPlayingSameEmote (PlayerBase BRP_NameTags_f_Target, int BRP_NameTags_f_ID) {

        // check if the other player is also doing the same emote
        EmoteManager BRP_NameTags_t_TargetEmoteManager = BRP_NameTags_f_Target.GetEmoteManager();
        
        // check if the same emote is playing
        return (BRP_NameTags_t_TargetEmoteManager.IsEmotePlaying() && BRP_NameTags_t_TargetEmoteManager.BRP_NameTags_m_LastActiveID == BRP_NameTags_f_ID);

    };

    void BRP_NameTags_NameTags_Say (string msg) {
        return;

        msg = "BRP_NameTags - EmoteManager." + msg;
        GetGame().GetMission().OnEvent(ChatMessageEventTypeID, new ChatMessageEventParams(CCDirect, "", msg, ""));
        Print(msg);

		//--- Message to all palyers
		ref array<Man> t_players = new array<Man>;
		GetGame().GetPlayers(t_players);
		foreach(auto t_player : t_players) {
			Param1<string> t_param_msg = new Param1<string>(msg);
			GetGame().RPCSingleParam(t_player, ERPCs.RPC_USER_ACTION_MESSAGE, t_param_msg, true, t_player.GetIdentity());
		};


		//--- Message to the current player
		//Param1<string> t_MessageParam = new Param1<string>("");
		//t_MessageParam.param1 = msg;
		//GetGame().RPCSingleParam(this, ERPCs.RPC_USER_ACTION_MESSAGE, t_MessageParam, true, this.GetIdentity());

    };

}