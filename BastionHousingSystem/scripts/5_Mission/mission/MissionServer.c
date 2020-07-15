modded class MissionServer
{
	private int			saveDelay;
	private int			maxHoursNonPayment;

	override void OnInit()
	{
		super.OnInit();
		if ( GetGame().IsServer() )
		{
			saveDelay = 2; // minutes
			maxHoursNonPayment = g_HSL.m_GenHosData.MaxHoursNonPayment * -60;
			GetGame().GameScript.Call( this, "UpdateRentalTime", NULL );
		}
	}

	void UpdateRentalTime()
	{
		Sleep((saveDelay * 60000));
		while ( true )
		{
			for (int i = 0; i < g_HSL.m_GenHosData.HousesData.Count(); i++)
			{
				HouseData hd = g_HSL.m_GenHosData.HousesData.Get(i);
				if (!hd.MainOwner.Name) continue;
				hd.MainOwner.RentTimeLeft -= saveDelay;
				if (hd.MainOwner.RentTimeLeft < maxHoursNonPayment)
				{
					BuildingBase.DeleteOwnerHouse(hd);
				}
				g_HSL.SaveData(hd);
			}
			Sleep((saveDelay * 60000)); //save each saveDelay minutes
		}
	}
}