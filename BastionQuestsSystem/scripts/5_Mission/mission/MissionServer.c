modded class MissionServer
{
    override void OnInit()
    {
        super.OnInit();
        g_QD = new QuestsData();
        g_QD = QuestsData.LoadData();
        g_QD.LoadQuestData();
        g_QND = new QuestNPCData();
        g_QND.LoadAllNPCData();
		g_QND.SpawnAllNPCs();
    }
}