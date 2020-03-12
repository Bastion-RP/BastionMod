class StoredDataHook
{
	ref StoredData m_storedData;
	void StoredDataHook()
	{
		GetRPCManager().AddRPC( "BastionMenu", "ReceiveStoredData", this, SingeplayerExecutionType.Client );
	}

  void ReceiveStoredData( CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target )
	{
		Param3<int, string, string> data_param;
		if ( !ctx.Read( data_param ) ) return;

		int rations = data_param.param1;
		string steam = data_param.param2;
		vector position = PlayerBase.Cast(GetGame().GetPlayer()).GetPosition();
		string currentServer = data_param.param3;
		// TODO: If we want to specify areas based on position, we coul do that here
		// or do it in the mainmenu itself, or just load the boundaries from a file.
		// Most likely the best idea is to divide the map into grids or overlapping circles
		// Could also specify main city area as a circle and anything else is considered wilderness etc.

		Print(steam);
		Print(position);
		Print(rations);
		Print(currentServer);

		if (steam.Length() == 0) return;

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