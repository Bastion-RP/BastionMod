class QuestsData
{
    const private static string m_ProfilePath		= "$profile:\\Bastion\\";
	const private static string m_FolderName		= "Quests";
	const private static string m_FileName			= "GeneralSettings";
  
    ref GeneralSettings m_GeneralSettings;
	ref QuestsLoader	m_QuestsLoader;

    void QuestsData()
    {
        m_GeneralSettings 	= new GeneralSettings();
    }


    static QuestsData LoadData()
    {   
        QuestsData data = new QuestsData();

        if (!FileExist(m_ProfilePath + m_FolderName + "\\"))
        {
			MakeDirectory(m_ProfilePath + m_FolderName + "\\");
		}

        if (FileExist(m_ProfilePath + m_FolderName + "\\" + m_FileName + ".json"))
        {
            JsonFileLoader<QuestsData>.JsonLoadFile(m_ProfilePath + m_FolderName + "\\" + m_FileName + ".json", data);
        }
        else
        {
            Print("[QUESTS] File GeneralSettings not found!");
        }

        return data;
    }

	void LoadQuestData()
	{
		m_QuestsLoader = new QuestsLoader();
		m_QuestsLoader = QuestsLoader.LoadData();
	}

	void SendQuestsData(PlayerBase player)
	{
		player.RPCSingleParam(QRPC.SEND_QUESTS_DATA, new Param1<ref array<ref Quest>>(m_QuestsLoader.AllQuests), true, player.GetIdentity());
	}
}
ref QuestsData g_QD;

class QuestsLoader
{
	const private static string m_ProfilePath		= "$profile:\\Bastion\\Quests";
	const private static string m_FileName			= "Quests";

	ref array<ref Quest> AllQuests;

	void QuestsLoader()
	{
		AllQuests = new array<ref Quest>();
	}

	static QuestsLoader LoadData()
    {   
        QuestsLoader data = new QuestsLoader();

        if (!FileExist(m_ProfilePath + "\\"))
        {
			MakeDirectory(m_ProfilePath + "\\");
		}

        if (FileExist(m_ProfilePath + "\\" + m_FileName + ".json"))
        {
            JsonFileLoader<QuestsLoader>.JsonLoadFile(m_ProfilePath + "\\" + m_FileName + ".json", data);
        }
        else
        {
            Print("[QUESTS] File Quests not found!");
        }
        return data;
    }
}