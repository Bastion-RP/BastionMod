class DayZIntroSceneNew
{
	protected PlayerBase			m_CharacterObj;
	private Camera 					m_Camera;
	private vector 					m_CharacterRot;
	private Weather					m_Weather;

	protected bool 					m_RotatingCharacter;
	protected int 					m_RotatingCharacterMouseX;
	protected int 					m_RotatingCharacterMouseY;
	protected float 				m_RotatingCharacterRot;
	protected float 				m_DiffX;
	EmoteCB							m_Callback;

	void DayZIntroSceneNew()
	{

		string root_path = "cfgLobbyScenes " + g_Game.GetWorldName();
		int count = g_Game.ConfigGetChildrenCount(root_path);

		string childName;
		g_Game.ConfigGetChildName(root_path, 0, childName);
	
		string scene_path 	   = root_path + " " + childName;
		vector playerPos  	   = g_Game.ConfigGetVector(scene_path + " playerPos");
		vector camPos          = g_Game.ConfigGetVector(scene_path + " camPos");
		vector camDir   	   = g_Game.ConfigGetVector(scene_path + " camDir");
		vector playerDir       = g_Game.ConfigGetVector(scene_path + " playerDir");
		float fov 		  	   = g_Game.ConfigGetFloat(scene_path + " fov");
		float rain 			   = g_Game.ConfigGetFloat(scene_path + " rain");
		float overcast 		   = g_Game.ConfigGetFloat(scene_path + " overcast");
		
		GetGame().ObjectDelete( m_Camera );
		Class.CastTo(m_Camera, g_Game.CreateObject("staticcamera", camPos, true));
		
		if (m_Camera)
		{
			m_Camera.SetPosition(Vector(m_Camera.GetPosition()[0] ,m_Camera.GetPosition()[1], m_Camera.GetPosition()[2]));
			m_Camera.SetOrientation(camDir);
			m_Camera.SetFOV(fov);
			m_Camera.SetFocus(1.0, 0.0);
			m_Camera.SetActive(true);
		}
		
		SetupCharacter(playerPos, playerDir);
		
		PPEffects.Init();
		PPEffects.DisableBurlapSackBlindness();
		PPEffects.SetVignette(0.6, 0,0,0);
	}

	void DestroyScene()
	{
		PPEffects.SetVignette(0.0, 0,0,0);
	}

	void CharacterRotationStart()
	{
		m_RotatingCharacter = true;
		g_Game.GetMousePos(m_RotatingCharacterMouseX, m_RotatingCharacterMouseY);
		
		if (m_CharacterObj) 
			m_RotatingCharacterRot = m_CharacterRot[0];
	}
	
	void CharacterRotationStop()
	{
		if (m_RotatingCharacter)
		{
			m_RotatingCharacter = false;
		}
	}
	
	bool IsRotatingCharacter()
	{
		return m_RotatingCharacter;
	}
	
	void CharacterRotate()
	{
		if (m_CharacterObj)
		{
			int actual_mouse_x;
			int actual_mouse_y;
			float coef;
			g_Game.GetMousePos(actual_mouse_x, actual_mouse_y);
		
			m_DiffX = m_RotatingCharacterMouseX - actual_mouse_x;
			
			coef = ( m_RotatingCharacterRot + (m_DiffX * 0.5) ) / 360;
			coef = coef - Math.Floor(coef);
			m_CharacterRot[0] = coef * 360;
			
			m_CharacterObj.SetOrientation(m_CharacterRot);
		}
	}
	
	void Update()
	{
		if (m_CharacterObj && m_RotatingCharacter)
			CharacterRotate();
	}

	void SetupCharacter(vector pos, vector orientation)
	{
		m_CharacterObj = PlayerBase.Cast(g_Game.CreateObject("SurvivorM_Boris", pos, true));
		
		m_CharacterObj.PlaceOnSurface();
		m_CharacterObj.SetPosition(pos);
		m_CharacterObj.SetOrientation(orientation);	

		m_CharacterObj.GetInventory().CreateInInventory("AliceBag_Green");
		m_CharacterObj.GetInventory().CreateInInventory("CargoPants_Green");
		m_CharacterObj.GetInventory().CreateInInventory("JungleBoots_Green");
		m_CharacterObj.GetInventory().CreateInInventory("TacticalShirt_Olive");
		m_CharacterObj.GetInventory().CreateInInventory("TacticalGloves_Green");
		m_CharacterObj.GetInventory().CreateInInventory("BoonieHat_Olive");

		m_CharacterObj.StartCommand_Action(DayZPlayerConstants.CMD_GESTUREFB_SOS,EmoteCB,DayZPlayerConstants.STANCEMASK_ERECT);
	}
}