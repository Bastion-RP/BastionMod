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
class BRP_NameTags_PlayerTag extends ScriptedWidgetEventHandler 
{
	//--- variables
	// o_* - Option, change these, maybe turn into settings in the future
	// m_* - Permanent variabeles which are used multiple times and where the value is important and doesn't reset
	// t_* - Temporary varibles which are overwritten often and reset whenever needed
	// f_* - Temporary varibles used in functions specific to the functions, used in the parameters

	// debug
	float m_Distance;


	//--- Basic
	// OPTIONS
	float o_DistanceMax = 800;		// max distance the tag is visible from
	float o_DistanceFaded = 30;		// distance the tag is faded
	float o_DistanceFade = 15;		// distance the tag starts fading
	int o_NameMaxLenght = 25;		// max name length
	bool o_IsVONShown = false;		// True to enable VON indicator (mic above name);


	//--- Widgets
	protected ref Widget m_LayoutRoot;				// the root layout, the base widget
	protected ref Widget m_WidgetTag;				// The Tag widget, this is the background
	protected ref TextWidget m_WidgetText;			// The text widget, contains text
	protected ref ImageWidget m_WidgetVON;			// The image widget containing VON icon
	protected ref RichTextWidget m_WidgetDot;		// First dot (star)
	protected ref RichTextWidget m_WidgetDot2;		// Second dot (star) background dot

	//--- Colors
	// exampples:
	// 0xFFd1ecff
	// 0xFF4b77be
	int m_ColorDot = 0xFF002080;	// not used
	int m_ColorText = 0xFFd1ecff;	// should be replaced

	int m_ColorTextDef = 0xFF969696;			// should be replaced
	int m_ColorTextFriend = 0xFF0c9f31;			//289f46;	// should be replaced
	int m_ColorTextKnown = 0xFF8195cf;			//8195cf;	// should be replaced


	//--- Object Variables
	// variables to keep track of the widget values etc.
	BRP_NameTagData m_Data;		// data checked to see if tag should stop existing
	Human m_Player;					// player object this tag is assigned to
	float m_VisibleUntil;			// tickTime this tag is visible until
	string m_PlayerName;			// player name
	string m_PlayerID;				// player id
	int m_BoneIndex;				// player bone index for position modifier
	vector m_Position;				// Last position of the player object (used in getposition)
	
	//--- temporary variables used in certain functions
	float t_Distance;				// temporary distance variable (used in update loop)
	float t_Alpha;					// temporary alpha variable (used in update loop)
	float t_AlphaBG;				// temporary alpha variable (used in setTextOpacity) for the background alpha


	//--- permanent variables
	int m_VONColor;					// von icon color to change it's opacity (used in SetDotOpacity)
	int m_DotColor;					// dot color to change it's opacity (used in SetDotOpacity)
	int m_DotColor2;				// 2nd dots color to change it's opacity (used in SetDotOpacity)

	float m_LayoutWidth;			// original width
	float m_LayoutHeight;			// original height

	float m_CurrentWidth;			// saved root layout width, unused
	float m_CurrentHeight;			// saved root layout height, unused
	float m_Size;					// calculated size for size, unused

	int m_alphaModifier = 0x10000000;	// modifier for alpha (not used)

	bool m_isDeleted = false;

	bool m_isInitialized = false;

	// text size
	string m_tempText;
	int m_tempLength; 
	int m_textLength = 16;


	float m_FadeEdgeMult;

	// variables for widgets
	bool m_ShowOnScreen;						// is the tag shown on screen?
	int m_ScreenWidth;							// screen width
	int m_ScreenHeight;							// screen height
	vector m_ScreenPos;							// the position on the screen that the nametag should appear on

	



	//-----------------------------------------------------------------------------------------
	//--- Raycasting variables
	// options:
	// how many times does the raycasting have to find collision before the tag is hidden
	int o_RayCastHitsRequired = 5;
	// hits required to fade half way
	int o_RayCastHitsFade = 1;
	// how much time has to pass for the raycasting hits to return to 0
	float o_RayCastHitsTimeout = 0.1;
	// how many times can the raycasting miss before the hits and misses reset
	int o_RayCastMissMax = 3;
	// Pause between every raycast attempt
	float o_RayCastPauseFor = 0.05;
	// option (speed)
	float o_RayCastModStep = 1;	// how fast raycasting affects alpha

	// Variables used in ray casting
	float m_RayCastNextAt = 0;
	int m_RayCastHitsCounter = 0;
	int m_RayCastMissCounter = 0;
	float m_RayCastHitsResetAt = 0;



	int m_RayCastModActive = 2;
	float m_RayCastModApplied = 1;
	float m_RayCastModPauseUntil = 0;
	//-----------------------------------------------------------------------------------------

	void OnWidgetScriptInit(Widget w)
	{
		m_LayoutRoot = w;
		m_LayoutRoot.SetHandler(this);

		Init();
	}

	// script that runs when the object gets deleted
	void ~BRP_NameTags_PlayerTag()
	{
		Unlink();
	}

	void Init() 
	{
		m_WidgetTag = m_LayoutRoot.FindAnyWidget("PlayerTagName");
		m_WidgetDot = RichTextWidget.Cast(m_LayoutRoot.FindAnyWidget("TagDot"));
		m_WidgetDot2 = RichTextWidget.Cast(m_LayoutRoot.FindAnyWidget("TagDot2"));
		
		m_WidgetText = TextWidget.Cast(m_LayoutRoot.FindAnyWidget("text_name"));
		m_WidgetVON = ImageWidget.Cast(m_LayoutRoot.FindAnyWidget("mic"));
	}

	void Show()
	{
		m_LayoutRoot.Show(true);
		OnShow();
	}

	void Hide()
	{
		OnHide();
		m_LayoutRoot.Show(false);
	}

	// remove widget deletes it
	void RemoveWidget() {
		delete this;
	};


	// unlink deletes and removes the widget and all it's children
	void Unlink() {
		// make sure it's not deleted more than once
		if (m_isDeleted) {
			return;
		};
		m_isDeleted = true;

		GetGame().GetUpdateQueue(CALL_CATEGORY_GUI).Remove(this.Update);

		if (m_LayoutRoot) {
			m_LayoutRoot.Unlink();
		};

		delete m_WidgetText;
		delete m_WidgetVON;
		delete m_WidgetTag;
		delete m_WidgetDot;
		delete m_WidgetDot2;
		delete m_LayoutRoot;

	}

	void OnShow()
	{
	}

	void OnHide() 
	{
	}

	float ATan( float a )
	{
		return Math.Asin( a ) / Math.Acos( a );
	}


	float GetDirectionHead(Human f_Player) {
		
		if (f_Player == NULL) {
			return 0.0;
		};
		
		float t_Bone_rot[4];
		f_Player.GetBoneRotationWS(f_Player.GetBoneIndexByName("Head"), t_Bone_rot);
		vector new_orient = Math3D.QuatToAngles(t_Bone_rot);
		return new_orient[0];
	};


	// player direction
	float GetDirectionMod() {
		float t_PlayingPlayerDir = GetDirectionHead(Human.Cast(GetGame().GetPlayer()));
		//t_PlayingPlayerDir = 160;	// TODO: this is fake for testing

		float t_TagPlayerDir = GetDirectionHead(m_Player);
		float t_PlayerDirDiff = Math.AbsFloat(t_PlayingPlayerDir - t_TagPlayerDir);
		if (t_PlayerDirDiff >= 180) {
			t_PlayerDirDiff = 360 - t_PlayerDirDiff;
		};


		// -----
		// random for testing purposes
		//int t_TimeInt = GetGame().GetTickTime() / 2;
		//t_TimeInt = t_TimeInt % 10;	// split to 10 steps
		
		//float t_PlayerDirDiffFake = Math.Lerp(0, 200, (t_TimeInt/10));
		//t_PlayerDirDiff = t_PlayerDirDiffFake;
		// -----
		float t_PlayerDirDiff2 = t_PlayerDirDiff;


		t_PlayerDirDiff = Math.Clamp(Math.InverseLerp(0,180,t_PlayerDirDiff), 0, 1);
		return t_PlayerDirDiff;
	};


	vector GetPosition(bool isDefaultPos = false) {
		// if player has ceased to exist exit with the previous position
		if (m_Player == NULL) {
			return m_Position;
		};
		
		m_Position = m_Player.GetPosition();

		// add height if in vehicle
		if (m_Player.IsInTransport()) {
			return (m_Position + "0 1.1 0");
		};

		// if player head bone exists, use head height
		if ( m_BoneIndex != -1 ) {
			if (isDefaultPos) {
				return (m_Player.GetBonePositionWS(m_BoneIndex));
			} else {
				return (m_Player.GetBonePositionWS(m_BoneIndex) + "0 0.3 0");
			};
		};

		// default height
		return (m_Position + "0 1.85 0");

	}

	void SetTextOpacity (float alpha) {
		t_AlphaBG = Math.Clamp(Math.Lerp(0.1,0,alpha),0,0.1);
		t_AlphaBG = Math.Lerp(0,t_AlphaBG,m_FadeEdgeMult);
		t_AlphaBG = Math.Lerp(t_AlphaBG,0,m_RayCastModApplied);
		m_WidgetTag.SetAlpha(0);
		alpha = Math.Lerp(0,15,alpha);
		m_WidgetText.SetColor(GetColorAlpha(alpha,m_ColorText));
	};

	// get color alpha
	int GetColorAlpha(float alpha, int color) {
		alpha = Math.Lerp(15,alpha,m_FadeEdgeMult);
		alpha = Math.Lerp(alpha,15,m_RayCastModApplied);
		alpha = Math.Clamp(alpha,0,15);

		for (int i = 0; i < alpha; i++) {
			color = color - 0x11000000;
		};
		return color;
	}

	void SetVONOpacity (float alpha) {
		if (alpha >= 0.95) {
			m_WidgetVON.Show(false);
		} else {
			m_WidgetVON.Show(true);
		};

		alpha = Math.Lerp(0,15,alpha);
		m_WidgetVON.SetColor(GetColorAlpha(alpha+1, m_VONColor));

	};

	void SetDotOpacity (float alpha) {
		alpha = Math.Lerp(0,15,alpha);
		m_WidgetDot.SetColor(GetColorAlpha((alpha+5), m_DotColor));
		m_WidgetDot2.SetColor(GetColorAlpha(alpha, m_DotColor2));

	};

	void RayCastHandler(float tDelta) {

		if (m_FadeEdgeMult < 1) {};	// disabled
		if (m_RayCastModPauseUntil > GetGame().GetTickTime()) {
			return;
		};
		if (m_RayCastModActive >= 1) {


			// do raycast check
			vector contact_point;
			vector contact_dir;
			int contact_component;
			
			if (GetGame().GetTickTime() > m_RayCastNextAt) {
				m_RayCastNextAt = (GetGame().GetTickTime() + o_RayCastPauseFor);
				if( DayZPhysics.RaycastRV(GetGame().GetCurrentCameraPosition(), (GetPosition(true)), contact_point, contact_dir, contact_component, null, m_Player, GetGame().GetPlayer(), false, false, ObjIntersectFire) ) {
					m_RayCastHitsCounter ++;

					if (m_RayCastHitsCounter >= o_RayCastHitsRequired) {
						m_RayCastModActive = 0;
						m_RayCastHitsCounter = 1;
						m_RayCastMissCounter = 0;
					} else if (m_RayCastHitsCounter == o_RayCastHitsFade) {
						if (m_RayCastModActive == 1) {
							m_RayCastModActive = 3;
						};
					};
				} else {
					if (m_RayCastHitsCounter > 0) {
						m_RayCastMissCounter ++;
						if (m_RayCastMissCounter >= o_RayCastMissMax) {
							m_RayCastMissCounter = 0;
							m_RayCastHitsCounter = 0;
							m_RayCastModActive = 2;

						};
					};

				};
			} else {
			};
		};

		if (m_RayCastModActive == 0) {
			if (m_RayCastModApplied < 1) {
				m_RayCastModApplied = m_RayCastModApplied + (o_RayCastModStep * 3) * tDelta;
			} else {
				m_RayCastModPauseUntil = GetGame().GetTickTime() + 0.5;
				m_RayCastModActive = 2;
			};
		};
		
		if (m_RayCastModActive == 2 && m_RayCastHitsCounter == 0) {
			if (m_RayCastModApplied > 0) {
				m_RayCastModApplied = m_RayCastModApplied - o_RayCastModStep * tDelta;
			} else {
				m_RayCastModActive = 1;
			};
		};
		
		
		if (m_RayCastModActive == 3) {
			float o_RayCastFadeMax = 0.75;
			if (m_RayCastModApplied < o_RayCastFadeMax) {
				m_RayCastModApplied = m_RayCastModApplied + (o_RayCastModStep * 2) * tDelta;
			} else {

				if (m_RayCastHitsCounter == 0) {

				};
			};
		};

		m_RayCastModApplied = Math.Clamp(m_RayCastModApplied,0,1);
	};


    void BRP_NameTags_NameTag_Say (string msg) {
        //return; // return debug disabled

        msg = "nameTag." + msg;
        GetGame().GetMission().OnEvent(ChatMessageEventTypeID, new ChatMessageEventParams(CCDirect, "", msg, ""));
        Print(msg);


    };



	void Update(float tDelta) {	
		// make sure layout exists
		if (!m_LayoutRoot) {
			return;
		};

		// make sure a data is connected to this tag
		if (!m_Data || m_Data == NULL) {
			Unlink();
			return;
		};

		m_ScreenPos = GetGame().GetScreenPos(GetPosition());
		GetScreenSize(m_ScreenWidth, m_ScreenHeight);

		// try to center nametag		
		float temp_width;
		float temp_height;
		m_LayoutRoot.GetSize(temp_width,temp_height);
		

		if ( m_ScreenPos[0] <= 0 || m_ScreenPos[1] <= 0 )
		{
			m_ShowOnScreen = false;
		} else {
			m_ShowOnScreen = true;
		}

		if ( m_ShowOnScreen && ( m_ScreenPos[0] >= m_ScreenWidth || m_ScreenPos[1] >= m_ScreenHeight ) )
		{
			m_ShowOnScreen = false;
		}

		if (m_ShowOnScreen && m_ScreenPos[2] > 0) {
			
			//m_LayoutRoot.SetPos( m_ScreenPos[0], m_ScreenPos[1] - ( m_ScreenHeight / 2 ), true );
			m_LayoutRoot.SetPos( m_ScreenPos[0] - (temp_width / 2), m_ScreenPos[1] - ( m_ScreenHeight / 2 ), true );
			
			float distFromEdgeW;
			if (m_ScreenPos[0] > m_ScreenWidth/2) {
				distFromEdgeW = m_ScreenWidth - m_ScreenPos[0];
			} else {
				distFromEdgeW = m_ScreenPos[0];
			};
			m_FadeEdgeMult = 1;


			if (distFromEdgeW < m_ScreenWidth / 3) {
				m_FadeEdgeMult = Math.InverseLerp(m_ScreenWidth/20, m_ScreenWidth /4, distFromEdgeW);
			};


			float distFromEdgeH;
			if (m_ScreenPos[1] > m_ScreenHeight/2) {
				distFromEdgeH = m_ScreenHeight - m_ScreenPos[1];
			} else {
				distFromEdgeH = m_ScreenPos[1];
			};
			float distFromEdgeModifierH = 1;

			if (distFromEdgeH < m_ScreenHeight / 3) {
				distFromEdgeModifierH = Math.InverseLerp(m_ScreenHeight/10, m_ScreenHeight / 3, distFromEdgeH);
				if (distFromEdgeModifierH < m_FadeEdgeMult) {
					m_FadeEdgeMult = distFromEdgeModifierH;
				};
			};

			float m_ADSMod = 0.0;
			DayZPlayerImplement m_PlayerDpi = DayZPlayerImplement.Cast(GetGame().GetPlayer());
			
			if (m_PlayerDpi.IsInOptics()) {
				m_ADSMod = 0.7;
			} else if (m_PlayerDpi.IsInIronsights()) {
				m_ADSMod = 0.55;
			} else if (GetGame().GetPlayer().GetInputController().IsWeaponRaised()) {
				m_ADSMod = 0.45;
			};

			if (m_ADSMod > 0) {

				float m_ADSModW = Math.InverseLerp(m_ScreenWidth*0.25, m_ScreenWidth*0.45, distFromEdgeW);
				float m_ADSModH = Math.InverseLerp(m_ScreenHeight*0.35, m_ScreenHeight*0.45, distFromEdgeH);

				m_ADSMod = Math.InverseLerp(0,2,(m_ADSModW + m_ADSModH) * m_ADSMod);
			};
			m_FadeEdgeMult -= m_ADSMod;
			m_FadeEdgeMult = Math.Clamp(m_FadeEdgeMult,0,1);
			RayCastHandler(tDelta);
			t_Distance = m_ScreenPos[2];
			m_Distance = t_Distance;
			float t_DirectionMod = GetDirectionMod();						
			t_Distance = t_Distance + t_Distance * (1 - t_DirectionMod);
			
			t_Alpha = Math.Clamp (Math.InverseLerp(o_DistanceFade,o_DistanceFaded,t_Distance),0,1);
			SetTextOpacity(t_Alpha);
			SetDotOpacity(1);

			// Doesnt work, needs RPC from clientside? or a different function from isplayerspeaking
			float t_IsPlayerSpeaking = DayZPlayer.Cast(m_Player).IsPlayerSpeaking();
			float m_VONMod = Math.Lerp(1,0,t_IsPlayerSpeaking * 2);	// screaming returns 0
			m_VONMod = Math.Clamp(m_VONMod,0,1);

			if (o_IsVONShown && t_Distance < 35) {
				
				//BRP_NameTags_NameTag_Say("speaking: " + t_IsPlayerSpeaking + " / " + m_VONMod);
				//Math.Clamp(1-(t_IsPlayerSpeaking*2),0,1)
				//SetVONOpacity(m_VONMod);
			};
			//Math.Clamp(1-(t_IsPlayerSpeaking*3),0,1)
			// 0.7
			// 1 - ( 0.7 * 3 )
			// 1 - 2.1 = -1.1
			// -1.1 , 0 , 1 = 0





			m_WidgetText.SetText(m_PlayerName);
			t_Distance = m_ScreenPos[2];
			m_Size = Math.InverseLerp(150,45,t_Distance);
			m_Size = Math.Clamp(m_Size,0.3,0.8);
			m_CurrentWidth = Math.Lerp(0,m_LayoutWidth,m_Size);
			m_CurrentHeight = Math.Lerp(0,m_LayoutHeight,m_Size);

			// -----
			// update size
			m_LayoutRoot.SetSize(m_CurrentWidth, m_CurrentHeight, true);
			
			Show();
		} else {
			Hide();
		}
	}


	// return the root layout
	ref Widget GetLayoutRoot() 
	{
		return m_LayoutRoot;
	}


	// Set the visible until time
	//
	// returns: nothing
	void SetVisibleUntil(float enabledFor) {
		m_VisibleUntil = (GetGame().GetTickTime() + enabledFor);
	};

	
	// Set the text color
	//	1 - Normal color
	//	2 - Green color
	//	3 - Blue color
	//
	// returns: nothing
	void SetTextColor(int f_Color) {

		if (f_Color == 1) {
			m_ColorText = m_ColorTextDef;
		};
		if (f_Color == 2) {
			m_ColorText = m_ColorTextFriend;
		};
		if (f_Color == 3) {
			m_ColorText = m_ColorTextKnown;
		};
		//BRP_NameTags_NameTag_Say("set: " + f_Color + " text: " + m_ColorText);

	};


	void SetName(string f_Name = "") {

		//m_PlayerName = m_Player.GetIdentity().GetName();
		if (f_Name == "") {
			m_PlayerName = m_Data.m_Name;
		};
		
		//BRP_NameTags_NameTag_Say("name: "+ m_PlayerName);
		if (m_PlayerName == "") {
			// cannot use this because only works on servers
			//m_PlayerName = PlayerBase.Cast(m_Player).GetMultiCharactersPlayerName();
			
			//BRP_NameTags_NameTag_Say("name2: " + PlayerBase.Cast(m_Player).GetMultiCharactersPlayerName());
			if (m_PlayerName == "") {
				m_PlayerName = "Unknown";
			};
		};

		// remove whitespaces ( can't because bastion names are supposed to have whitespaces )
		//m_PlayerName = m_PlayerName.Trim();


		// save the name state before trimming (is long?)
		bool t_IsLongName = (m_PlayerName.LengthUtf8() >= o_NameMaxLenght);

		// limit player name to a certain size
		m_PlayerName = m_PlayerName.SubstringUtf8(0, o_NameMaxLenght - 3);

		// if the name was long, add 3 dots
		if (t_IsLongName) {
			m_PlayerName += "...";
		};

	};


	// initalizers the inital player (when added for the first time)
	// adds the script to update queue
	void InitPlayer() {

		m_isInitialized = true;

		SetName();



		m_PlayerID = m_Player.GetIdentity().GetId();

		// check player head bone existance
		m_BoneIndex = m_Player.GetBoneIndexByName("Head");
		
		// default to 10 seconds visbility time
		m_VisibleUntil = (GetGame().GetTickTime() + 10);

		// set color
		m_WidgetText.SetColor(m_ColorText);

		// save layout color (alpha)
		//m_layoutColor = m_LayoutRoot.GetColor();

		m_VONColor = m_WidgetVON.GetColor();
		m_DotColor = m_WidgetDot.GetColor();
		m_DotColor2 = m_WidgetDot2.GetColor();



		// save the original size of the tag
		m_LayoutRoot.GetSize(m_LayoutWidth, m_LayoutHeight);

		// enable widget tag
		m_WidgetTag.Show(true);
		m_ShowOnScreen = true;
		
		// add update to update queue
		GetGame().GetUpdateQueue(CALL_CATEGORY_GUI).Insert(this.Update);

	};

	void SetData (BRP_NameTagData f_Data) {

		m_Data = f_Data;

		// also update the player name based on the new data
		SetName();
	};

	void SetPlayer(Man player) {	
		//BRP_NameTags_NameTag_Say("SetPlayer: "+ player);
		// cast the player
		m_Player = Human.Cast(player);


		// make sure player being set exists and is alive
		if (m_Player == NULL || !m_Player.IsAlive()) 
		{
			// delete this
			Unlink();
		};

		// if already intialized, exit
		if (m_isInitialized) {
			return;
		};

		// first time initalization
		InitPlayer();
	}
}
