class HouseStorageLoader
{
	const private static string m_ProfilePath		= "$profile:\\Bastion\\House_BD";
	const private static string m_FileName			= "AllHousesInfo";

	private ref FileSerializer 	file;
	private FileHandle          m_StartFile;

	ref GeneralHousesData	m_GenHosData;

	void HouseStorageLoader()
	{
		file = new FileSerializer();
		m_GenHosData = new GeneralHousesData();
		m_GenHosData.Admins.Insert("t6goVGbhstnvoqE9d_apyTpfMglcUNy099wKuvhVnmo=");
		m_GenHosData.Admins.Insert("OG-UnHi5ZORxnSaxd5ceczLK5yMTFp7ZC1fe6c8Ycu8=");
		Print(m_GenHosData);
		LoadData();
	}

	void LoadData()
    {   
        if (!FileExist(m_ProfilePath))
        {
			MakeDirectory(m_ProfilePath);
		}

		LoadHousesData();
        // if (FileExist(m_ProfilePath + "/" + m_FileName))
        // {
		// 	LoadDataFromFile();
		// 	Print("Load data");
		// 	m_GenHosData.Admins.Debug();
        // }
		// else
        // {
		// 	CreateNewData();
		// 	Print("Create new data");
        // }
    }
	
	// void LoadDataFromFile()
	// {
	// 	int elemCount = 0;
	// 	HouseData hd = new HouseData;
	// 	if (file.Open(m_ProfilePath + "/" + m_FileName, FileMode.READ))
	// 	{
	// 		file.Read(m_GenHosData);
	// 		file.Close();
	// 	}
	// }
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

	// void CreateNewData()
	// {
	// 	m_GenHosData.Admins.Insert("t6goVGbhstnvoqE9d_apyTpfMglcUNy099wKuvhVnmo=");
	// 	file.Open(m_ProfilePath + "/" + m_FileName, FileMode.WRITE);
	// 	file.Write(m_GenHosData);
	// 	file.Close();

	// 	SaveData();
	// }

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
		m_GenHosData.HousesData.Debug();
	}

	HouseData LoadHouseData(string filename)
	{
		ref HouseData data = new HouseData;
		JsonFileLoader<ref HouseData>.JsonLoadFile(m_ProfilePath + "\\" + filename, data);
		Print(data.Low);
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
		Print("Main house data sended");
	}

	void SendAllHouses(PlayerBase pl)
	{
		//pl.RPCSingleParam(HRPC.SEND_BRP_HOUSES, new Param1<ref array<ref HouseData>>(m_GenHosData.HousesData), true, pl.GetIdentity());
	}
}
ref HouseStorageLoader g_HSL;