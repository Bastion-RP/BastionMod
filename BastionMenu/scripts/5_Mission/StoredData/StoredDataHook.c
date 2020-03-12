class StoredDataHook
{
	ref StoredData m_storedData;
	void StoredDataHook()
	{
		GetRPCManager().AddRPC( "BastionMenu", "ReceiveStoredData", this, SingeplayerExecutionType.Client );
	}

  void ReceiveStoredData( ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target )
	{
		Param2<string, int> data_param;
		if ( !ctx.Read( data_param ) ) return;

		string steam = data_param.param1;
		vector position = PlayerBase.Cast(GetGame().GetPlayer()).GetPosition();
		int rations = data_param.param2;
		string currentServer = GetCurrentServerInfo().m_Name;

		// TODO: If we want to specify areas based on position, we coul do that here
		// or do it in the mainmenu itself, or just load the boundaries from a file.
		// Most likely the best idea is to divide the map into grids or overlapping circles
		// Could also specify main city area as a circle and anything else is considered wilderness etc.

		autoptr StoredData data = new StoredData( steam, "BKG-023 Korolgrad", rations, currentServer );

		FileSerializer file = new FileSerializer();
		
		if (file.Open("$profile:BastionMenuCache.bin", FileMode.WRITE))
			file.Write(data);

		file.Close();
  }

	bool LoadData()
	{
		FileSerializer file = new FileSerializer();
		
		if (file.Open("$profile:BastionMenuCache.bin", FileMode.READ))
		{
			file.Read(m_storedData);
			file.Close();
			return true;
		}
		return false;
	}
}