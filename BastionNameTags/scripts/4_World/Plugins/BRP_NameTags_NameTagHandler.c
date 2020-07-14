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
class BRP_NameTags_NameTagHandler extends PluginBase {
    
    //--- OPTIONS:
    // enable for 300 seconds
    static int o_EnabledFor = 30;
    int o_MaxDist = 800;   // TODO: read this from the server ServerConfigGetInt and RPC it over to all clients (server setting)



    //--- DEFINES:
    // map that will contain playerID: Widget
    
    // instead of a map, using an array of DATAs
    ref array<ref BRP_NameTagData> m_ArrayTags = new array<ref BRP_NameTagData>;

    // data's that are still being added to the main DATA
    ref array<ref BRP_NameTagData> m_ArrayTagsNew = new array<ref BRP_NameTagData>;
    
    ref array<ref BRP_NameTagData> m_ArrayTagsOld; // copy of the main array because some things get removed and not added back (timed out or fail conditions)

    // MAP containing the current active tag for every UID
    ref map<string, ref BRP_NameTagData> m_MapActiveTags = new map<string, ref BRP_NameTagData>();

    Widget t_Widget;
    BRP_NameTags_PlayerTag t_TagScript;

    bool m_IsPlayerFound;
    
    void BRP_NameTags_NameTagHandler_Say (string msg) {
        return; // return debug disabled

        msg = "nameTagHandler." + msg;
        GetGame().GetMission().OnEvent(ChatMessageEventTypeID, new ChatMessageEventParams(CCDirect, "", msg, ""));
        Print(msg);


    };


	override void OnDestroy() {
        RemoveAllPlayers();
	};


	void UpdatePositionsRPC(CallType f_Type, ref ParamsReadContext ctx, ref PlayerIdentity sender) {
        //return;

        Param1< map<string, vector> > data;
        if (!ctx.Read(data)) {
            return;
        };

        map<string, vector> t_MapPos = data.param1;

        
        BRP_NameTags_NameTagHandler_Say("UpdatePositionsRPC: " + data.param1);

        
		for ( int i = 0; i < m_ArrayTags.Count(); i++ ) {
            BRP_NameTagData t_Data = m_ArrayTags.Get(i);
            if (!t_Data || t_Data == NULL || t_Data.m_Tier != 3) {
                continue;
            };

			vector t_NewPos;
            if (t_MapPos.Find(t_Data.m_UID, t_NewPos)) {
                t_Data.m_Pos = t_NewPos;
            };
		};
	};



    override void OnInit() {


        // if handler has alaready been created and exists, delete this             
        if ((BRP_NameTags_g_nameTagHandler && BRP_NameTags_g_nameTagHandler != NULL) || (!GetGame().IsClient() && GetGame().IsMultiplayer())) {   // Not a client and in multiplayer
            delete this;
            return;
        };

        BRP_NameTags_g_nameTagHandler = this;

        
		GetRPCManager().AddRPC("BRP_NameTags", "UpdatePositionsRPC", this, SingleplayerExecutionType.Both);
		GetRPCManager().AddRPC("BRP_NameTags", "AddPlayerRPC", this, SingleplayerExecutionType.Both);
		GetRPCManager().AddRPC("BRP_NameTags", "RemovePlayerRPC", this, SingleplayerExecutionType.Both);
		//GetRPCManager().AddRPC("BRP_NameTags", "AddPlayerRPC", this, SingleplayerExecutionType.Server);

        // add the updater function to run 
        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(Update, 10000);
    };


    // update that will run all the time
    //
    // TASKS:
    //  - Time managment (delete the tags)
    //  - Conditions
    //  - Priority and options
    //
    void Update () {
        //BRP_NameTags_NameTagHandler_Say("Update!");




        // add the new tags to the tags
        // This is to keep any errors from tags being added between cycles.
        //m_ArrayTags.InsertAll(m_ArrayTagsNew);
        
		for ( int i = 0; i < m_ArrayTagsNew.Count(); i++ ) {
			m_ArrayTags.Insert( m_ArrayTagsNew.Get(i) );
		};

        m_ArrayTagsNew.Clear();

        // copy the old array 
        m_ArrayTagsOld = m_ArrayTags;
        m_ArrayTags = new array<ref BRP_NameTagData>;

        
        // process tags
        foreach (BRP_NameTagData t_Data: m_ArrayTagsOld) {
            ProcessUpdate(t_Data);
        };
        delete m_ArrayTagsOld;



        // next update
        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(Update, 50);

        // check if player is in the main mene
		if (GetGame().IsMissionMainMenu()) {
            RemoveAllPlayers();
			//return;
		};
    };

    // Check if the tagdata should be deleted
    // called from ProcessUpdate()
    // returns: true if tagdata should be deleted
    bool CheckTagDeletion(BRP_NameTagData f_Data) {

        // check forced tag deletion
        if (f_Data.m_IsDeletePlanned) {
            return true;
        };

        // delete conditions based on tiers
        int t_Tier = f_Data.m_Tier;

        // tier 5 = normal tag
        // Deletion condition based on TIER
        // TIER CHECK
        if (t_Tier == 5) {

            // man not live
            if (f_Data.m_Man == NULL || !f_Data.m_Man.IsAlive()) {
                return true;
            };
        };
        if (t_Tier == 4) {

            // man not live
            if (f_Data.m_Man == NULL || !f_Data.m_Man.IsAlive()) {
                return true;
            };
        };
        if (t_Tier == 3) {

            // man not live
            if (f_Data.m_Man == NULL || !f_Data.m_Man.IsAlive()) {
                return true;
            };
        };
        if (t_Tier == 2) {

            // man not live
            if (f_Data.m_Man == NULL || !f_Data.m_Man.IsAlive()) {
                return true;
            };
        };

        return false;
    };

    // Check if the tagdata should be enabled
    // called from ProcessUpdate()
    // returns: true if tagdata should be enabled
    bool CheckTagEnabled(BRP_NameTagData f_Data) {

        // distance
        float t_Dist = vector.Distance(f_Data.m_Man.GetPosition(),GetGame().GetPlayer().GetPosition());
        float t_DistPos = vector.Distance(f_Data.m_Pos,GetGame().GetPlayer().GetPosition());

        // get distance from an active tag
        if (f_Data.m_IsActive && f_Data.m_TagScript) {
            t_Dist = f_Data.m_TagScript.m_Distance;
        };

        // get tier
        int t_Tier = f_Data.m_Tier;

        // Check conditions based on TIER
        // TIER CHECK

        // update color?   
        int t_UpdatedColor = 1;

        // tier 5 = normal tag
        if (t_Tier == 5) {

        };
        // tier 4 = handshaken normal tag
        if (t_Tier == 4) {
            // refresh timer to half if closer than 10 m
            if (t_Dist < 30) {
                UpdateTime(f_Data,f_Data.m_EnabledFor*0.5);
            };
            if (t_Dist < 2) {
                t_UpdatedColor = 3;
            };
        };

        // tier 3 = friend tag
        if (t_Tier == 3) {
            if (t_Dist < 2) {
                t_UpdatedColor = 2;
            };
            
        };

        // update the color
        f_Data.m_TagScript.SetTextColor(t_UpdatedColor);


		//float distance = vector.Distance(playerPosition, newPosition);

        // check man alive and distance from man to the player
        if (f_Data.m_Man == NULL || !f_Data.m_Man.IsAlive() || t_DistPos >= o_MaxDist) {

            // if tag 
            return false;
        };


        return true;
    };


    
    // Process a tag data in the update
    // called from Update()
    // returns: nothing
    void ProcessUpdate(BRP_NameTagData f_Data) {
        //BRP_NameTags_NameTagHandler_Say("ProcessUpdate: " + f_Data);

        float t_EndingAt = f_Data.m_EndingAt;
        bool t_IsDeletable = CheckTagDeletion(f_Data);


        // time has passed this tag is not needed any more
        if (GetGame().GetTickTime() >= t_EndingAt || t_IsDeletable) {

            //BRP_NameTags_NameTagHandler_Say("ProcessUpdate: DELETE");
            
            RemovePlayer(f_Data);
            delete f_Data;
            return;
        };

        // add the data to the new array
        m_ArrayTags.Insert(f_Data);


        bool t_IsEnabled = CheckTagEnabled(f_Data);


        // if this tag is currently disabled, exit here, so later a lower tier tag can still be displayed if it's conditions are met
        if (!t_IsEnabled) {
            //BRP_NameTags_NameTagHandler_Say("ProcessUpdate: DISABLED");
            DeActivateTag(f_Data,false);

            return;
        };


        //BRP_NameTags_NameTagHandler_Say("ProcessUpdate: ACTIVE");


        string t_UID = f_Data.m_UID;
        BRP_NameTagData t_FoundTagData;

        bool t_FoundActive = m_MapActiveTags.Find(t_UID,t_FoundTagData);

        // if the current data is already active, quit
        if (t_FoundTagData == f_Data) {
            return;
        };

        // found same UID tag
        if (t_FoundActive) {

            // compare TIERS
            if (f_Data.m_Tier > t_FoundTagData.m_Tier) {

                // the current data tier is worse(orsame) than the active tier
                return;
            };

            // this tier should be active, deactive the other tier
            DeActivateTag(t_FoundTagData,true);
            ActivateTag(f_Data,t_FoundTagData);
            
            // replace the old tag
            m_MapActiveTags.Set(t_UID, f_Data);
        } else {
            
            // same UID not found, add the tag to active map
            m_MapActiveTags.Insert(t_UID, f_Data);
            
            ActivateTag(f_Data);

        };
        


        // CHECK if the tag player is close enough to display and if the conditions for the tag are good.


    };

    // DeActivateTag
    // deactivate the tag, removes the tag and widget and sets as not active
    // returns: nothing
    void DeActivateTag(BRP_NameTagData f_Data, bool f_IsTagKept = false) {


        f_Data.m_IsActive = false;
        if (!f_IsTagKept) {
            RemovePlayer(f_Data);
        };
        
        // add the data to the script
        f_Data.m_TagScript.SetData(NULL);

        f_Data.m_Widget = NULL;
        f_Data.m_TagScript = NULL;

    };
    
    // ActivateTag
    // activates the tag for the tagdata, can use another tagdata to steal a tag from
    // returns: nothing
    void ActivateTag(BRP_NameTagData f_Data, BRP_NameTagData f_DataOld = NULL) {

        //BRP_NameTags_NameTagHandler_Say("ActivateTag: " + f_Data.m_UID);

        f_Data.m_IsActive = true;

        // steal from old
        if (f_DataOld != NULL && f_DataOld.m_IsActive) {
            f_Data.m_TagScript = f_DataOld.m_TagScript;
            f_Data.m_Widget = f_DataOld.m_Widget;
        } else {
            CreateTag(f_Data);
        };

        //BRP_NameTags_NameTagHandler_Say("ActivateTag: We good");

        // set params for widget script
		f_Data.m_TagScript.SetPlayer(f_Data.m_Man);

        // add the data to the script
        f_Data.m_TagScript.SetData(f_Data);
        

        // set tag tier (updates the distance, fade and variables for the tag script)
        SetTagTier(f_Data);

    };

    // SetTagTier
    // Sets the data required for the tag tier
    // returns: nothing
    void SetTagTier(BRP_NameTagData f_Data) {

        //BRP_NameTags_NameTagHandler_Say("tier: " + f_Data.m_Tier);

        // defaults 
        f_Data.m_TagScript.o_IsVONShown = false;
        f_Data.m_TagScript.o_DistanceFade = 10;
        f_Data.m_TagScript.o_DistanceFaded = 30;
        f_Data.m_TagScript.SetTextColor(1);


        // TIER CHECK
        
        // tier 5 tag 
        if (f_Data.m_Tier == 5) {
            

            // enable von display
            f_Data.m_TagScript.o_IsVONShown = true;
        };
        if (f_Data.m_Tier == 4) {

            // smoother curve
            f_Data.m_TagScript.o_DistanceFade = 10;
            f_Data.m_TagScript.o_DistanceFaded = 50;
            f_Data.m_TagScript.SetTextColor(3);
            

            // enable von display
            f_Data.m_TagScript.o_IsVONShown = true;
        };
        if (f_Data.m_Tier == 3) {

            // smoother curve
            f_Data.m_TagScript.o_DistanceFade = 30;
            f_Data.m_TagScript.o_DistanceFaded = 75;
            f_Data.m_TagScript.SetTextColor(2);
            
            // enable von display
            f_Data.m_TagScript.o_IsVONShown = true;
        };
        if (f_Data.m_Tier == 2) {

            // smoother curve
            f_Data.m_TagScript.o_DistanceFade = 175;
            f_Data.m_TagScript.o_DistanceFaded = 900;
            
        };
    };

	void RemovePlayerRPC(CallType f_Type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object f_Target) {


        if (!f_Target || f_Target == NULL) {
            return;
        };
        
        //BRP_NameTags_NameTagHandler_Say("AddPlayerRPC: " + data);
        BRP_NameTags_NameTagHandler_Say("RemovePlayerRPC: " + f_Target);


		
		if (f_Type != CallType.Client) {
			return;
		};

		//Man t_Player = data.param1;
		Man t_Player = Man.Cast(f_Target);
        
		if (t_Player == NULL || t_Player.GetIdentity() == NULL) {
			return;
		};

        BRP_NameTags_GetNameTagHandler().RemovePlayerViaMan(t_Player);
        //BRP_NameTags_NameTagHandler_Say("player: " + t_Player);
	};

    
	
	void AddPlayerRPC(CallType f_Type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object f_Target) {

        Param1< int > data;
        if (!ctx.Read(data)) {
            return;
        };
        
        //BRP_NameTags_NameTagHandler_Say("AddPlayerRPC: " + data);
        BRP_NameTags_NameTagHandler_Say("AddPlayerRPC: " + data.param1);


		
		if (f_Type != CallType.Client) {
			return;
		};

		Man t_Player = Man.Cast(f_Target);
		if (t_Player == NULL || t_Player.GetIdentity() == NULL) {
			return;
		};

        BRP_NameTags_GetNameTagHandler().AddPlayer(t_Player,data.param1);
        //BRP_NameTags_NameTagHandler_Say("player: " + t_Player);
	};


    // Create tag (widget and tagScript)
    // called from ActivateTag()
    // returns: nothing
    void CreateTag(BRP_NameTagData f_Data) {

        Man t_player = f_Data.m_Man;
        

        // reset variable
		t_TagScript = null;
        t_Widget = null;

        // create widget
		t_Widget = GetGame().GetWorkspace().CreateWidgets("BastionMod/BastionNameTags/GUI/Layouts/NameTags/BRP_NameTags_PlayerTag.layout");

        

        // check if widget was created
		if (null == t_Widget) {
			return;
		};

        // get widget script
		t_Widget.GetScript(t_TagScript);

		if (t_TagScript == null) {
			return;
		};

        // set params for widget script
		t_TagScript.SetPlayer(t_player);
		//t_TagScript.SetVisibleUntil(o_EnabledFor);

        f_Data.m_Widget = t_Widget;
        f_Data.m_TagScript = t_TagScript;
        f_Data.m_IsActive = true;

    };


	// script that runs when the object gets deleted
	void ~BRP_NameTags_NameTagHandler() {
		RemoveAllPlayers();

        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Remove(Update);
	};

    // Create and add fresh tagData
    // BRP_NameTags_GetNameTagHandler().AddData(playerObject)
    // this data is later processed from the datas
    // returns: nothing
    //
    void AddData (Man f_Player, int f_Tier) {
        BRP_NameTagData t_Data = new BRP_NameTagData;

        m_ArrayTagsNew.Insert(t_Data);

        t_Data.m_Man = f_Player;
        t_Data.m_Pos = f_Player.GetPosition();
        t_Data.m_UID = f_Player.GetIdentity().GetId();
        //t_Data.m_Name = f_Player.GetIdentity().GetName();
        t_Data.m_Name = PlayerBase.Cast(f_Player).GetMultiCharactersPlayerName();

        t_Data.m_Tier = f_Tier;
        t_Data.m_Type = 0;
        t_Data.m_Status = 0;

        float t_EnabledFor = 15;

        // set the time based on tier
        // TIER CHECK
        if (f_Tier == 5) {
            t_EnabledFor = 3;
        };
        if (f_Tier == 4) {
            t_EnabledFor = 60;
        };
        if (f_Tier == 3) {
            t_EnabledFor = 60*60*24;
        };
        if (f_Tier == 2) {
            t_EnabledFor = 7;
        };

        
        UpdateTime(t_Data,t_EnabledFor);

        
        //BRP_NameTags_NameTagHandler_Say("AddData: " + f_Player);
    };

    // Update time
    // BRP_NameTags_GetNameTagHandler().UpdateTime(t_Data,o_EnabledFor);
    // returns: nothing
    //
    void UpdateTime (BRP_NameTagData f_Data, float f_Time) {

        // only define started at if it's undefined
        if (!f_Data.m_StartedAt) {
            f_Data.m_StartedAt = GetGame().GetTickTime();

            // also define the enabled for time to set the timer
            f_Data.m_EnabledFor = f_Time;
        };

        // calculaqte the ending time
        f_Data.m_EndingAt = GetGame().GetTickTime() + f_Time;
    };

    // Add player and create a widget for him
    // BRP_NameTags_GetNameTagHandler().AddPlayer(playerObject)
    // the original add function is based on the player object, but after this we will use the UID
    // returns: nothing
    //
    void AddPlayer (Man f_Player, int f_Tier) {
        
        //BRP_NameTags_NameTagHandler_Say("AddPlayer: " + f_Player);

        bool t_IsDataFound = false;

        // check if the current tier / type already exists
        BRP_NameTagData t_Data;
        int t_DataIndex;
        
        for (t_DataIndex = 0; t_DataIndex < m_ArrayTags.Count(); t_DataIndex++) {
            t_Data = m_ArrayTags.Get(t_DataIndex);

            // same player found
            if (t_Data.m_Man == f_Player) {

                // check tier 6 for removal of tier 3 tag
                if (f_Tier == 6 && t_Data.m_Tier == 3) {
                    RemoveData(t_Data);
                    return;
                };

                // check tier 6 for removal of tier 3 tag
                if (f_Tier == 7 && t_Data.m_Tier == 4) {
                    RemoveData(t_Data);
                    return;
                };

                // remove same tier 
                if (t_Data.m_Tier == f_Tier) {
                    t_IsDataFound = true;
                    break;
                };
            };
        };

        // tier 6 = delete player
        if (f_Tier == 6) {
            return;
        };

        // tier 7 = delete player
        if (f_Tier == 7) {
            return;
        };



        // player was not in the list, add him
        if (!t_IsDataFound) {
            //CreateTag(f_Player);
            AddData(f_Player,f_Tier);

            return;
        };
        

        //BRP_NameTags_NameTagHandler_Say("AddPlayer data found, updating time");

        // player found, run timer edit function
        UpdateTime(t_Data,t_Data.m_EnabledFor);
        //t_TagScript.SetVisibleUntil(o_EnabledFor);

        // also update the player (in case he was dead before)
        //t_Data.m_TagScript.SetPlayer(f_Player);
    };

    // Remove player via man
    // BRP_NameTags_GetNameTagHandler().RemovePlayer(t_Data)
    // returns: nothing
    void RemovePlayerViaMan (Man f_Player) {
        BRP_NameTagData t_Data;
        int t_DataIndex;

        for (t_DataIndex = 0; t_DataIndex < m_ArrayTags.Count(); t_DataIndex++) {
            t_Data = m_ArrayTags.Get(t_DataIndex);

            // same player found
            if (t_Data.m_Man == f_Player) {

                // remove the data
                RemoveData(t_Data);
            };
        };
    };

    // Remove player, deletes the tag
    // BRP_NameTags_GetNameTagHandler().RemovePlayer(t_Data)
    // returns: nothing
    void RemovePlayer (BRP_NameTagData f_Data) {

        m_MapActiveTags.Remove(f_Data.m_UID);

        t_TagScript = f_Data.m_TagScript;

        // Run remove widget script if the widget exists
        if (t_TagScript != NULL) {
            DeleteTag(t_TagScript);
        };

        //delete f_Data;
    };

    // Sets the data enabled for deletion
    // BRP_NameTags_GetNameTagHandler().RemoveData(t_Data)
    // returns: nothing
    void RemoveData (BRP_NameTagData f_Data) {

        //m_MapActiveTags.Remove(f_Data.m_UID);
        f_Data.m_IsDeletePlanned = true;
    };




    // Delete Widget
    // DeleteTag(script)
    // returns: nothing
    void DeleteTag (BRP_NameTags_PlayerTag tagScript) {
        if (tagScript != NULL) {
            tagScript.Unlink();
            delete tagScript;
        };
    };

    // Remove all players
    // BRP_NameTags_GetNameTagHandler().RemoveAllPlayers();
    // returns: nothing
    void RemoveAllPlayers () {
        
        //m_ArrayTags.InsertAll(m_ArrayTagsNew);

        // iterate over all players and delete their widgets
        foreach(BRP_NameTagData t_Data: m_ArrayTags) {
            RemovePlayer(t_Data);
            DeleteTag(t_Data.m_TagScript);
            delete t_Data;
        };
        
        
        if (m_ArrayTags && m_ArrayTags != NULL) {
            m_ArrayTags.Clear();
        };
        if (m_ArrayTagsNew && m_ArrayTagsNew != NULL) {
            m_ArrayTagsNew.Clear(); 
        };
        if (m_ArrayTagsOld && m_ArrayTagsOld != NULL) {
            m_ArrayTagsOld.Clear();
        };
        

        // clear players array
        m_MapActiveTags.Clear();
    };
     
};


// return the handler
// BRP_NameTags_GetNameTagHandler()
// static function to get the nametaghandler
static ref BRP_NameTags_NameTagHandler BRP_NameTags_g_nameTagHandler;
static ref BRP_NameTags_NameTagHandler BRP_NameTags_GetNameTagHandler() {
    // Not a client and in multiplayer
    // client and multiplayer = True True / False True
    // server and multiplayer = False True / True True
    // client and sinleplayer = True False / False False
    // server and singleplayer = False False / True False
    if (!GetGame().IsClient() && GetGame().IsMultiplayer()) { 
        return NULL;
    };

    if (!BRP_NameTags_g_nameTagHandler) {
        BRP_NameTags_g_nameTagHandler = new ref BRP_NameTags_NameTagHandler;
    };
    return BRP_NameTags_g_nameTagHandler;
};