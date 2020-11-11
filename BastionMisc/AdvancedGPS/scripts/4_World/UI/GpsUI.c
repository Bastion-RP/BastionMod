class GpsUI
{
	private Widget root;
	private MapWidget gpsMap;
	private ImageWidget pDir;
	private ImageWidget bgdImg;
	private TextWidget azimutValue;
	private TextWidget coordsWrap;
	private TextWidget timeValue;
	private TextWidget idValue;

	private PlayerBase player;

	private const float maxScale = 0.5;
	private const float minScale = 0.1;

	private float scale, offsetx, offsety, posx, posy;
	private float defoffsetx = 642;
	private float defoffsety = -421;
	private int timePassed;
	private int updateChildrenInterval = 1000; //1 sec


	void GpsUI()
	{
		root = GetGame().GetWorkspace().CreateWidgets("BastionMod/BastionMisc/AdvancedGPS/assets/layouts/adv_gps.layout");
		gpsMap = MapWidget.Cast(root.FindAnyWidget("map"));
		pDir = ImageWidget.Cast(root.FindAnyWidget("pp"));
		bgdImg = ImageWidget.Cast(root.FindAnyWidget("ImgBgd"));
		azimutValue = TextWidget.Cast(root.FindAnyWidget("azimutValue"));
		coordsWrap = TextWidget.Cast(root.FindAnyWidget("coordsWrap"));
		timeValue = TextWidget.Cast(root.FindAnyWidget("timeValue"));
		idValue = TextWidget.Cast(root.FindAnyWidget("IDValue"));
		pDir.LoadImageFile(0, "BastionMod/BastionMisc/AdvancedGPS/assets/img/cursor_pl.edds");
		bgdImg.LoadImageFile(0, "BastionMod/BastionMisc/AdvancedGPS/assets/img/gps.edds");

		player = PlayerBase.Cast(GetGame().GetPlayer());
		InitMap();
		LoadSettings();
		UpdateGpsID();
	}

	void ~GpsUI()
	{
		Show(false);
		if (root)
			root.Unlink();
	}

	void Show(bool show)
	{
		root.Show(show);

		if (show)
			OnShow();
		else
			OnHide();
	}

	bool IsVisible()
	{
		return root.IsVisible();
	}

	void OnShow()
	{
		GetGame().GetCallQueue(CALL_CATEGORY_GUI).CallLater(Update, 10, true);
	}

	void OnHide()
	{
		GetGame().GetCallQueue(CALL_CATEGORY_GUI).Remove(Update);
	}

	void InitMap()
	{
		scale = 0.1;
		offsetx = GetADVCGps().GetConfig().GetOffsetX();
		offsety = GetADVCGps().GetConfig().GetOffsetY();
		if (offsetx == 0 || offsety == 0)
		{
			offsetx = defoffsetx;
			offsety = defoffsety;
		}
		gpsMap.SetScale(scale);
		SetMapPos();
	}

	void UpdateScale(float step)
	{
		scale = Math.Clamp(scale + step, minScale, maxScale);
		gpsMap.SetScale(scale);
	}

	void Update()
	{	
		UpdateMap();
		UpdateDisplay();
		UpdateOtherDevices();
	}

	void UpdateMap()
	{
		SetMapPos();
	}

	void UpdateDisplay()
	{
		float az = GetGame().GetCurrentCameraDirection().VectorToAngles().GetRelAngles()[0];
		int azimut = az;
		if (azimut < 0)
			azimut += 360;
		pDir.SetRotation(0, 0, azimut);
		azimutValue.SetText(azimut.ToString());
		coordsWrap.SetText(GetDisplayPos());
		timeValue.SetText(GetTime());
	}

	void SetMapPos()
	{
		if (player)
		{
			vector pos = player.GetPosition();
			gpsMap.SetMapPos(GetMapPos(pos));
		}
	}

	vector GetMapPos(vector pos)
	{
		vector result = pos;
		float x, y;
		x = result[0] + (10 * scale * offsetx);
		y = result[2] + (10 * scale * offsety);
		result = Vector(x, 0, y);
		return result; 
	}

	void Move(float x, float y)
	{
		int screenW, screenH;
		float width, height;
		GetScreenSize(screenW, screenH);
		root.GetSize(width, height);
		root.GetPos(posx, posy);
		posx = Math.Clamp(posx + x, 0, screenW - width);
		posy = Math.Clamp(posy + y, 0, screenH - height);
		root.SetPos(posx, posy);
	}

	array<float> GetSettings()
	{
		float x, y;
		root.GetPos(x, y);
		return {x, y, scale};
	}

	void SetSettings(float x1, float y1, float locscale)
	{
		posx = x1;
		posy = y1;
		scale = locscale;
		root.SetPos(posx, posy);
		gpsMap.SetScale(scale);
	}

	void LoadSettings()
	{
		GpsData data;
		JsonFileLoader<GpsData>.JsonLoadFile( GpsConsts.CONFIG_DIR, data );
		if (data)
			SetSettings(data.x, data.y, data.scale);
	}

	string GetDisplayPos()
	{
		string result;
		vector pos = player.GetPosition();
		float x,y,z;
		x = ((int)(pos[0] * 100)) / 100;
		y = ((int)(pos[1] * 100)) / 100;
		z = ((int)(pos[2] * 100)) / 100;
		result = x.ToString() + " : " + y.ToString() + " : " + z.ToString();
		return result;
	}

	string GetTime()
	{
		int hour, min;
		GetGame().GetWorld().GetDate( null, null, null, hour, min );
		string hours, minutes;
		if (hour < 10)
			hours = "0";
		hours += hour.ToString();
		if (min < 10)
			minutes = "0";
		minutes += min.ToString();

		return String(hours + ":" + minutes);
	}

	void ChangeScaleY(int val)
	{
		offsety += val;
		ADVCGps.Mess("offsety "+offsety.ToString());
	}

	void ChangeScaleX(int val)
	{
		offsetx += val;
		ADVCGps.Mess("offsetx "+offsetx.ToString());
	}

	void UpdateOtherDevices()
	{
		timePassed += 10;
		if (timePassed >= updateChildrenInterval)
		{
			timePassed = 0;
			DisplayChildrenOnMap();
		}
	}

	void UpdateGpsID()
	{
		if (player && player.GetMainGps())
			idValue.SetText(String("ID:"+ player.GetMainGps().GetLowBits().ToString()));
		else
			idValue.SetText(String("ID:Error"));
	}

	void DisplayChildrenOnMap()
	{
		if (!IsVisible() || !player || !player.IsAlive())
			return;
		
		gpsMap.ClearUserMarks();
		array<ref Param2<vector, int>> allChildren = player.GetMainGps().GetWorkingChildrenPositions();
		for (int i = 0; i < allChildren.Count(); i++)
		{
			gpsMap.AddUserMark(allChildren.Get(i).param1, allChildren.Get(i).param2.ToString() , ARGB(255,0,0,255), "\\dz\\gear\\navigation\\data\\map_tree_ca.paa");
		}
	}
}