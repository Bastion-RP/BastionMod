modded class MissionGameplay
{
    void MissionGameplay()
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