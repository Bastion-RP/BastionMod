class DZManager
{
	ref RadiationAreaSettings m_ActiveRadiationAreaSettings;
	ref HazardAreaSettings m_ActiveHazardAreaSettings;
	ref InfectedAreaSettings m_ActiveInfectedAreaSettings;
	ref DZCrateSystemAreaSettings m_ActiveDZCrateSystemSettings;
	ref RadiationLocations m_RadZoneLocations;

	void DZManager()
  {
		if (GetGame().IsServer())	{
			//GetDZLogger().LogInfo("DZManager - Started !");
			m_ActiveRadiationAreaSettings = RadiationAreaSettings.Load();
			m_ActiveHazardAreaSettings = HazardAreaSettings.Load();
			m_ActiveInfectedAreaSettings = InfectedAreaSettings.Load();
			m_ActiveDZCrateSystemSettings = DZCrateSystemAreaSettings.Load();

			m_RadZoneLocations = new RadiationLocations(m_ActiveRadiationAreaSettings);

			#ifdef DZDEBUG
			GetDZLogger().LogInfo("DEBUG MODE ENABLED");
			#endif
		}
		else
		{
			GetRPCManager().SendRPC("DZConfig", "GetConfigRequest", NULL, true, NULL);
		}
		InitRPC();
  }

	void InitRPC()
		{
			if (GetGame().IsServer())	{
				//Server calls
				GetRPCManager().AddRPC("DZConfig", "GetConfigRequest", this, SingeplayerExecutionType.Server);
			}
			else	{
				//Client calls
				GetRPCManager().AddRPC("DZConfig", "GetConfigResponse", this, SingeplayerExecutionType.Server);
			}
		}

	void ~DZManager()
    {

    }

		//ONLY Called on server
 void GetConfigRequest(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)	{
	 if (!GetGame().IsServer())
		 return;
	 GetRPCManager().SendRPC("DZConfig", "GetConfigResponse", new Param1<ref RadiationLocations>(m_RadZoneLocations), true, sender);
 }

 //Only called on client
 void GetConfigResponse(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)	{
	 if (!GetGame().IsClient())
		 return;
	 Param1<ref RadiationLocations> data;
	 if (!ctx.Read(data))
		 return;
	 m_RadZoneLocations = data.param1;
 }

}
