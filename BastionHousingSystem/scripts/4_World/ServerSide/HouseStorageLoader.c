class HouseStorageLoader
{
	const private static string m_ProfilePath		= "$profile:\\Bastion\\House_BD";
	const private static string m_FileName			= "GeneralHouseData";

	private ref FileSerializer 	file;
	private FileHandle          m_StartFile;

	ref GeneralHousesData	m_GenHosData;

	void HouseStorageLoader()
	{
		file = new FileSerializer();
		m_GenHosData = new GeneralHousesData();
		m_GenHosData.Admins.Insert("50278"); // default
		m_GenHosData.Admins.Insert("50013"); // default
		m_GenHosData.MaxHoursNonPayment = 10; // default
		LoadData();
	}

	void LoadData()
    {   
        if (!FileExist(m_ProfilePath))
        {
			MakeDirectory(m_ProfilePath);
		}

		LoadGeneralData();
		LoadHousesData();
    }
	
	void SaveData(HouseData hd)
	{
		string name = hd.BuildingPos;
		name.Replace("<","");
		name.Replace(">","");
		JsonFileLoader<HouseData>.JsonSaveFile(m_ProfilePath + "\\" + name + ".json", hd);
	}

	void SaveAllData()
	{
		for (int i = 0; i < m_GenHosData.HousesData.Count(); i++)
		{
			HouseData hd = m_GenHosData.HousesData.Get(i);
			string name = hd.BuildingPos;
			name.Replace("<","");
			name.Replace(">","");
			JsonFileLoader<HouseData>.JsonSaveFile(m_ProfilePath + "\\" + name + ".json", hd);
		}
	}

	void LoadGeneralData()
	{
		if (FileExist(m_ProfilePath + "\\" + m_FileName + ".json"))
		{
			JsonFileLoader<GeneralHousesData>.JsonLoadFile(m_ProfilePath + "\\" + m_FileName + ".json", m_GenHosData);
		}
		else
		{
			JsonFileLoader<GeneralHousesData>.JsonSaveFile(m_ProfilePath + "\\" + m_FileName + ".json", m_GenHosData);
		}
	}

	void LoadHousesData()
	{
		string fileName;
		FileAttr fileAttr;
		HouseData hd;
		FindFileHandle houseFile = FindFile(m_ProfilePath +"/*.json", fileName, fileAttr, 0);
		
		if (!houseFile)
			return;

		hd = LoadHouseData(fileName);
		if (hd)
		{
			m_GenHosData.HousesData.Insert(hd);

			while(FindNextFile(houseFile, fileName, fileAttr))
			{
				hd = LoadHouseData(fileName);
				if (!hd) continue;
				m_GenHosData.HousesData.Insert(hd);
			}
		}
		CloseFindFile(houseFile);
	}

	HouseData LoadHouseData(string filename)
	{
		ref HouseData data = new HouseData;
		JsonFileLoader<ref HouseData>.JsonLoadFile(m_ProfilePath + "\\" + filename, data);
		if (!data.Low) return NULL;
		return data;
	}
	

	void SendAdmins(PlayerBase pl)
	{
		pl.RPCSingleParam(HRPC.SEND_ADMINS_ID, new Param1<ref array<string>>(m_GenHosData.Admins), true, pl.GetIdentity());
	}

	void SendMainHouseData(PlayerBase pl)
	{
		pl.RPCSingleParam(HRPC.SEND_HOUSES_DATA, new Param1<ref array<ref HouseData>>(m_GenHosData.HousesData), true, pl.GetIdentity());
	}
}
ref HouseStorageLoader g_HSL;