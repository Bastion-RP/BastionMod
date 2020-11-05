class DosimeterBase : ItemBase
{
	private int MaxDisplayRadiation;
	protected string activeScreenTexturePath;
	protected ref Timer animateLoop;
	protected ref map<string, int> selectionsMap;

	private ref array<string> hiddenSelections;
	private ref array<string> digitTexturePaths;
	private ref array<string> batteryTexturePaths;

	private const string DEFAULT_SCREEN_PATH = "BastionMod\\BastionDangerousZone_Data\\detectors\\data\\detectors_screen_co.paa";
	private const string BATTERY_SELECTION = "battery";

	private PlayerBase owner;
	private float animateTime;

	void DosimeterBase()
	{
		if ( !GetGame().IsServer()  ||  !GetGame().IsMultiplayer() )
		{
			SetMaxDisplayRadiation(999);
			InitializePaths();
			InitializeSelections();
		}
	}

	void InitializeSelections()
	{
		selectionsMap = new map<string, int>();
		foreach (string selectionName : hiddenSelections)
		{
			selectionsMap.Insert(selectionName, GetHiddenSelectionIndex(selectionName));
		}
	}

	void InitializePaths()
	{
		digitTexturePaths = new array<string>();
		hiddenSelections = new array<string>();
		batteryTexturePaths = new array<string>();

		ConfigGetTextArray ( "digitTexturePaths", digitTexturePaths );
		ConfigGetTextArray ( "hiddenSelections", hiddenSelections );
		ConfigGetTextArray ( "batteryTexturePaths", batteryTexturePaths);
		activeScreenTexturePath = ConfigGetString("workScreenPath");
	}

	void EnableScreen(bool val)
	{
		if (val)
			SetObjectTexture(1, activeScreenTexturePath);
		else
		{
			SetObjectTexture(1, 										DEFAULT_SCREEN_PATH);
			SetObjectTexture(selectionsMap.Get(BATTERY_SELECTION), 		string.Empty);
			OffAzimutDisplay();
			OffDisplayTime();
			ResetRadDisplay();
		}
	}

	void SetMaxDisplayRadiation(int radiation)
	{
		MaxDisplayRadiation = radiation;
	}

	int GetMaxDisplayRad()
	{
		return MaxDisplayRadiation;
	}

	void PlayGeigerTickSound()
	{
		SEffectManager.PlaySoundOnObject(String("GeiGer_Tick_"+Math.RandomInt(0,10)+"_SoundSet"), this);
	}

	void PlayOverloadSound()
	{
		SEffectManager.PlaySoundOnObject(String(string.Empty), this);
	}

	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionTurnOnWhileInHands);
		AddAction(ActionTurnOffWhileInHands);
	}

	void ShowRadiation(int radiation)
	{
		ResetRadDisplay();
		if (radiation == 0)
		{
			SetObjectTexture(selectionsMap.Get("dig0"), GetTexturePathByIndex(0));
			return;
		}
		string digits = radiation.ToString();
		int digit, idx;
		for (int i = 0; i < digits.Length(); i++)
		{
			idx = digits.Length() - i - 1;
			digit = digits.Get(idx).ToInt();

			if (i == 0)
				digit = Math.RandomInt(0,10);

			SetObjectTexture(selectionsMap.Get(String("dig"+i)),GetTexturePathByIndex(digit));
		}
	}

	void ResetRadDisplay()
	{
		SetObjectTexture(selectionsMap.Get("dig0"),string.Empty); 
		SetObjectTexture(selectionsMap.Get("dig1"),string.Empty); 
		SetObjectTexture(selectionsMap.Get("dig2"),string.Empty); 
	}

	string GetTexturePathByIndex(int idx)
	{
		return digitTexturePaths.Get(idx);
	}

	void AnimateLoop()
	{
		if (!owner)
			return;

		float externalRadiation = owner.GetRadiationHandler().GetExternalRadiation();

		if (externalRadiation >= GetMaxDisplayRad())
		{
			PlayOverloadSound();
			externalRadiation = GetMaxDisplayRad();
		}
		else
		{
			animateTime += (externalRadiation / 1000);

			if (externalRadiation > 0 && externalRadiation < 50)
				animateTime += 0.01;

			if (animateTime > 1.6)
			{
				if (Math.RandomInt(0, 11) < 3)
					return;
				PlayGeigerTickSound();
				ResetAnimTime();
			}	
		}
		ShowRadiation(externalRadiation);
		ShowAzimut();
		SetWorldTime();
	}

	void ShowAzimut()
	{
		vector ori = owner.GetDirection();
		float angle = ori.VectorToAngles().GetRelAngles()[0];
		if (angle < 0)
			angle += 360;

		int angleNrml = angle;

		if (angleNrml < 10)
			ChangeAzimutDisplay(angleNrml, 0, 0);
		else if (angleNrml < 100)
			ChangeAzimutDisplay((angleNrml % 10), (angleNrml / 10), 0);
		else
			ChangeAzimutDisplay((angleNrml % 10), (angleNrml % 100 / 10), (angleNrml / 100));
	}

	void ChangeAzimutDisplay(int units, int tens, int hundreds)
	{
		SetObjectTexture(selectionsMap.Get("cmpDig0"), GetTexturePathByIndex(units));
		SetObjectTexture(selectionsMap.Get("cmpDig1"), GetTexturePathByIndex(tens));
		SetObjectTexture(selectionsMap.Get("cmpDig2"), GetTexturePathByIndex(hundreds));
	}

	void OffAzimutDisplay()
	{
		SetObjectTexture(selectionsMap.Get("cmpDig0"), string.Empty);
		SetObjectTexture(selectionsMap.Get("cmpDig1"), string.Empty);
		SetObjectTexture(selectionsMap.Get("cmpDig2"), string.Empty);
	}

	void SetWorldTime()
	{
		int hour, minute;
		GetGame().GetWorld().GetDate(null, null, null, hour, minute);
		string time = ConvertTime(hour, minute);
		DisplayTime(time);
	}

	string ConvertTime(int hour, int min)
	{
		string result;
		if (hour < 10)
			result = "0";
		result += hour.ToString();
		if (min < 10)
			result += "0";
		result += min.ToString();

		return result;
	}

	void DisplayTime(string time)
	{
		int idx, digit;
		for (int i = 0; i < time.Length(); i++)
		{
			idx = time.Length() - i - 1;
			digit = time.Get(idx).ToInt();

			SetObjectTexture(selectionsMap.Get(String("time"+i)),GetTexturePathByIndex(digit));
		}
	}

	void OffDisplayTime()
	{
		for (int i = 0; i < 4; i++)
		{
			SetObjectTexture(selectionsMap.Get(String("time"+i)), string.Empty);
		}
	}

	void ResetAnimTime()
	{
		animateTime = 0;
	}

	string DebugGetRandTextPath()
	{
		return digitTexturePaths.GetRandomElement();
	}

	override void OnWorkStart()
	{
		if ( !GetGame().IsServer()  ||  !GetGame().IsMultiplayer() )
		{
			owner = PlayerBase.Cast(GetGame().GetPlayer());

			EnableScreen(true);

			if (!animateLoop)
				animateLoop = new Timer();

			if (!animateLoop.IsRunning())
				animateLoop.Run(0.005, this, "AnimateLoop", NULL, true);
		}
	}

	override void OnWork( float consumed_energy )
	{
		if ( !GetGame().IsServer()  ||  !GetGame().IsMultiplayer() )
		{
			Battery9V battery = Battery9V.Cast( GetCompEM().GetEnergySource() );
			
			if (battery)
			{
				float energy = battery.GetCompEM().GetEnergy0To1();
				ShowBatteryCharge(energy);
			}
		}
	}

	void ShowBatteryCharge(float energy)
	{
		int idx = selectionsMap.Get(BATTERY_SELECTION);
		if (energy < 0.25)
			SetObjectTexture(idx, batteryTexturePaths.Get(0));
		else if (energy < 0.5)
			SetObjectTexture(idx, batteryTexturePaths.Get(1));
		else if (energy < 0.75)
			SetObjectTexture(idx, batteryTexturePaths.Get(2));
		else
			SetObjectTexture(idx, batteryTexturePaths.Get(3));
	}

	override void OnWorkStop()
	{
		if ( !GetGame().IsServer()  ||  !GetGame().IsMultiplayer() )
		{
			animateLoop.Stop();
			ResetAnimTime();
			EnableScreen(false);
		}
		
	}
}