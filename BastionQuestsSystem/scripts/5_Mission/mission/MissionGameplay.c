modded class MissionGameplay
{
    override void OnInit()
	{
		super.OnInit();
        g_QM = new QuestManager();
    }

	override void OnKeyPress(int key)
	{
		super.OnKeyPress(key);
		g_QM.OnKeyPress(key);
	}
}