modded class MissionGameplay
{
	override void OnUpdate(float timeslice)
	{
		super.OnUpdate(timeslice);
		if (GetADVCGps())
			GetADVCGps().OnUpdate();
	}

	override void DestroyAllMenus()
	{
		super.DestroyAllMenus();
		if (GetADVCGps())
			GetADVCGps().DestroyUI();
	}
}