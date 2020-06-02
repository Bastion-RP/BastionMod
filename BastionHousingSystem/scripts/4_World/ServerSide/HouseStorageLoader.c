class HouseStorageLoader
{
	const private static string m_ProfilePath		= "$profile:\\Bastion\\House_BD";
	const private static string m_FileName			= "AllHousesInfo";

	ref GeneralHousesData	m_GenHosData;

	void QuestManagerStg()
	{
		m_GenHosData = new GeneralHousesData();
	}

	static HouseStorageLoader LoadData()
    {   
        HouseStorageLoader data = new HouseStorageLoader();

        if (!FileExist(m_ProfilePath))
        {
			MakeDirectory(m_ProfilePath);
		}

        if (FileExist(m_ProfilePath + "/" + m_FileName + ".json"))
        {
            JsonFileLoader<HouseStorageLoader>.JsonLoadFile(m_ProfilePath + "\\" + m_FileName + ".json", data);
        }
		else
        {
			SaveData(data);
			JsonFileLoader<HouseStorageLoader>.JsonLoadFile(m_ProfilePath + "\\" + m_FileName + ".json", data);
        }
        return data;
    }
	
	static void SaveData(HouseStorageLoader data)
	{		
		JsonFileLoader<HouseStorageLoader>.JsonSaveFile(m_ProfilePath + "\\" + m_FileName + ".json", data);
	}

	void SendAdmins(PlayerBase pl)
	{
		pl.RPCSingleParam(HRPC.SEND_ADMINS_ID, new Param1<ref array<string>>(m_GenHosData.Admins), true, pl.GetIdentity());
	}
}
ref HouseStorageLoader g_HSL;