modded class MissionServer
{
    void MissionServer()
    {
        g_Announcements = null;
        GetAnnouncements();
    }

    override void OnInit()
	{
		super.OnInit();

        if ( GetGame().IsServer() )
            GetAnnouncements().OnInit();
    }
}