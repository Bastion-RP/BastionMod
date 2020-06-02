modded class MissionGameplay
{
	override void OnInit()
	{
		super.OnInit();

		g_HM		= HouseManager();
	}

	override void OnKeyPress(int key)
	{
		super.OnKeyPress(key);
		g_HM.OnKeyPress(key);
	}
}