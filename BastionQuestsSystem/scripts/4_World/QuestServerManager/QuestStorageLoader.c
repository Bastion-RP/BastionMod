class QuestStorageLoader
{
	const private static string m_ProfilePath		= "$profile:\\Bastion\\Quests_BD";

	ref QuestManagerStg	m_QuestManagerStg;

	void QuestManagerStg()
	{
		m_QuestManagerStg = new QuestManagerStg();
	}

	static QuestStorageLoader LoadData(string ID)
    {   
        QuestStorageLoader data = new QuestStorageLoader();

        if (!FileExist(m_ProfilePath))
        {
			MakeDirectory(m_ProfilePath);
		}

        if (FileExist(m_ProfilePath + "/" + ID + ".json"))
        {
            JsonFileLoader<QuestStorageLoader>.JsonLoadFile(m_ProfilePath + "\\" + ID + ".json", data);
        }
		else
        {
			SaveData(data, ID);
			JsonFileLoader<QuestStorageLoader>.JsonLoadFile(m_ProfilePath + "\\" + ID + ".json", data);
        }

        return data;
    }
	
	static void SaveData(QuestStorageLoader data, string ID)
	{		
		JsonFileLoader<QuestStorageLoader>.JsonSaveFile(m_ProfilePath + "\\" + ID + ".json", data);
	}
}