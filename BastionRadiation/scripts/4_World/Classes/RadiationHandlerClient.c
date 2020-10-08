class RadiationHandlerClient
{
	private PlayerBase player;
	private ref RadiationClothingManager radiationClothingManager;

	private float externalRadiation;
	private float innerRadiation;

	void RadiationHandlerClient(PlayerBase player)
	{
		this.player = player;
		this.radiationClothingManager = new RadiationClothingManager(player);
	}

	void Init()
	{
		GetGame().GameScript.Call( this, "CheckPlayerAsync", null );
	}

	void CheckPlayerAsync()
	{
		bool playerAlive = true;
		vector playerPos;
		array<ref RadiationAreaData> zones;

		zones = GetRadiationManager().GetConfig().GetZones();

		while (player && playerAlive)
		{
			playerPos = player.GetPosition();
			playerPos[1] = 0;
			externalRadiation = 0;

			foreach (RadiationAreaData zone : zones)
			{
				if (inArea(playerPos, zone))
				{
					PlayerInRadiationZone(zone);
					break;
				}
			}

			playerAlive = player.IsAlive();
			Sleep(2000);
		}
	}

	bool inArea(vector playerPos, RadiationAreaData zone)
	{
		vector zonePos = zone.GetPos().ToVector();
		int radius = zone.GetRadius();
		return (vector.Distance(playerPos, zonePos) <= radius);
	}

	void PlayerInRadiationZone(RadiationAreaData zone)
	{
		externalRadiation = CalculateRadiationInPlayerPos(zone);
		innerRadiation = CalculateInnerRadiation(externalRadiation);//externalRadiation - ( externalRadiation * radiationClothingManager.GetPercentProtect(externalRadiation));
		QuestManager.SelfChatMessage("externalRadiation :"+externalRadiation);
		QuestManager.SelfChatMessage("innerRadiation :"+innerRadiation);
		SendRadiationDataOnServer();
	}

	float CalculateRadiationInPlayerPos(RadiationAreaData zone)
	{
		float percent = GetPercentPassedDistance(zone);
		float outer = zone.GetOuterRad();
		float diff = zone.GetInnerRad() - outer;
		float result = outer + diff * percent;
		return result;
	}

	float GetPercentPassedDistance(RadiationAreaData zone)
	{
		vector playerPos = player.GetPosition();
		vector zonePos = zone.GetPos().ToVector();
		zonePos[1] = 0;
		playerPos[1] = 0;
		float radius = zone.GetRadius();
		float passedDistance = radius - vector.Distance(zonePos, playerPos);
		float onePercent = radius / 100;
		float result = passedDistance / onePercent * 0.01;
		return result;
	}

	float CalculateInnerRadiation(float externalRadiation)
	{
		return radiationClothingManager.CalculateInnerRadiation(externalRadiation);
	}

	void SendRadiationDataOnServer()
	{
		GetGame().RPCSingleParam(player, RadRPCs.SEND_RADIATION_DATA, new Param2<TItemSlotDamageKoefMap, float>(radiationClothingManager.GetPlayerClothing(), GetInnerRadiation()), true, null);
	}

	float GetExternalRadiation()
	{
		return externalRadiation;
	}

	float GetInnerRadiation()
	{
		return innerRadiation;
	}
}