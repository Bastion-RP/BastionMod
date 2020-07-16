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
class BRP_NameTagData {
    // the data object for the name tag handler


    // the tag script will be only present when using this
    // the tag script can be moved from one tag data to the other
    // the tag script will sometimes exist for longer and be edited and move between multiple datas (only available in the currently active one)
    
    ref BRP_NameTags_PlayerTag m_TagScript;     // the tag script 
    Widget m_Widget;                    // the widget
    bool m_IsActive = false;            // is the tag agtive
    bool m_IsDeletePlanned = false;     // is the tag set to deletetion

    float m_EnabledFor;                 // time how long the tag is enabled for
    float m_StartedAt;                  // time the tag was started on
    float m_EndingAt;                   // time the tag will end on
    int m_Status;                       // current status of the tag
    int m_Type;                         // type of tag
    int m_Tier;                         // tier, from 5 to 1 (1 being best)

    Man m_Man;                          // man associated with the tag
    vector m_Pos;                       // Position when recieved from the server
    string m_UID;                       // UID associated with the tag
    string m_Name;                      // Name of the man

};