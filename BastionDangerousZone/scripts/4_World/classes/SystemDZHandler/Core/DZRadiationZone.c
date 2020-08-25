class DZRadiationZone extends DZManager {
	private int m_CheckScheduler;

	void DZRadiationZone() {
		if (GetGame().IsServer()) {
			GetDZLogger().LogInfo("DZRadiationZone - Started !");
			GetGame().GetMission().MissionScript.Call(this, "CheckScheduler", null);
		}
	}

	void CheckScheduler() {
		m_CheckScheduler = GetRadConfig().RadCheck;
		while (1) {
			array<Man> m_Players = new array<Man>;
			GetGame().GetPlayers(m_Players);

			// This is a nested continuous loop. This is awful for performance.
			for (int i = 0; i < m_Players.Count(); i++) {
				PlayerBase player;
				Class.CastTo(player, m_Players.Get(i));
				for (int k = 0; k < GetRadConfig().RadiationAreaLocation.Count(); k++) {
					private RadiationZoneLocation m_ActiveRadiationAreaLocation = GetRadConfig().RadiationAreaLocation.Get(k);
					if (m_ActiveRadiationAreaLocation.IsSquareZone == 0) {
						HighLevelRadiationZoneRound(m_ActiveRadiationAreaLocation.NbSickGivenForRadiation, m_ActiveRadiationAreaLocation.X, m_ActiveRadiationAreaLocation.Y, m_ActiveRadiationAreaLocation.Radius, m_ActiveRadiationAreaLocation.RadiationZoneStatut, player);
					} else {
						HighLevelRadiationZoneSquare(m_ActiveRadiationAreaLocation.NbSickGivenForRadiation, m_ActiveRadiationAreaLocation.X1, m_ActiveRadiationAreaLocation.Y1, m_ActiveRadiationAreaLocation.X2, m_ActiveRadiationAreaLocation.Y2, m_ActiveRadiationAreaLocation.RadiationZoneStatut, player);
					}
				}
			}
			Sleep(m_CheckScheduler);
		}
	}

	void HighLevelRadiationZoneRound(int m_NbSickGivenForRadiation, float m_X, float m_Y, float Zone_Radius, string Status, PlayerBase player) {
		string ZoneCheck;
		vector pos = player.GetPosition();
		float distance_squared = Math.Pow(m_X - pos[0], 2) + Math.Pow(m_Y - pos[2], 2);
		if (distance_squared <= Math.Pow(0.33 * Zone_Radius, 2)) {
			if (player.IsInside.DZName == Status && player.IsInside.DZStatut && player.NbSickGivenForRadiation == m_NbSickGivenForRadiation * 3) //Already in zone
			{
				// I'm not reworking the logic on this.
			} else {
				player.IsInside.DZName = Status;
				player.IsInside.DZStatut = true;
				player.IsInside.DZType = 2;
				player.NbSickGivenForRadiation = m_NbSickGivenForRadiation * 3;
				player.GiveRadQtyToPlayerClothes();
			}
			player.RadCheck();
		} else if (distance_squared <= Math.Pow(0.66 * Zone_Radius, 2)) {
			if (player.IsInside.DZName == Status && player.IsInside.DZStatut && player.NbSickGivenForRadiation == m_NbSickGivenForRadiation * 2) //Already in zone
			{
				// I'm not reworking the logic on this.
			} else {
				player.IsInside.DZName = Status;
				player.IsInside.DZStatut = true;
				player.IsInside.DZType = 2;
				player.NbSickGivenForRadiation = m_NbSickGivenForRadiation * 2;
				player.GiveRadQtyToPlayerClothes();
			}
			player.RadCheck();
		} else if (distance_squared <= Math.Pow(Zone_Radius, 2)) {
			if (player.IsInside.DZName == Status && player.IsInside.DZStatut && player.NbSickGivenForRadiation == m_NbSickGivenForRadiation) //Already in zone
			{
				// I'm not reworking the logic on this.
			} else {
				player.IsInside.DZName = Status;
				player.IsInside.DZStatut = true;
				player.IsInside.DZType = 2;
				player.NbSickGivenForRadiation = m_NbSickGivenForRadiation;
				player.GiveRadQtyToPlayerClothes();
				if (GetRadConfig().IsMsgActive == 1) {
					NotificationSystem.SendNotificationToPlayerIdentityExtended(player.GetIdentity(), 5, "Radiation Zone", GetRadConfig().MsgEnterZone, "BastionMod/BastionDangerousZone/images/radiation.paa");
				}
			}
			player.RadCheck();
		} else if (distance_squared > Math.Pow(Zone_Radius, 2)) {
			if (player.IsInside.DZName == Status && player.IsInside.DZStatut) {
				player.IsInside.DZStatut = false;
				player.IsInside.DZName = "";
				player.IsInside.DZType = 0;
				if (GetRadConfig().IsMsgActive == 1) {
					NotificationSystem.SendNotificationToPlayerIdentityExtended(player.GetIdentity(), 5, "Radiation Zone", GetRadConfig().MsgExitZone, "BastionMod/BastionDangerousZone/images/radiation.paa");
				}
			} else {
				return;
			}
		}
	}

	private void SendMessageClient(PlayerBase player, string message) {
		Param1<string> m_MesParam = new Param1<string>(message);
		GetGame().RPCSingleParam(player, ERPCs.RPC_USER_ACTION_MESSAGE, m_MesParam, true, player.GetIdentity());
	}

	float GetSquarePercentageCoordonate(float percentage, float Coo1, float Coo2) {
		int temp = Coo1;
		temp = temp + percentage * (Coo2 - Coo1);
		return temp;
	}

	void HighLevelRadiationZoneSquare(int m_NbSickGivenForRadiation, float m_X1, float m_Y1, float m_X2, float m_Y2, string Status, PlayerBase player) {
		string ZoneCheck;
		vector pos = player.GetPosition();
		if ((pos[0] > GetSquarePercentageCoordonate(0.167, m_X1, m_X2) && pos[0] < GetSquarePercentageCoordonate(0.167, m_X2, m_X1)) && (pos[2] > GetSquarePercentageCoordonate(0.167, m_Y1, m_Y2) && pos[2] < GetSquarePercentageCoordonate(0.167, m_Y2, m_Y1))) {
			if (player.IsInside.DZName == Status && player.IsInside.DZStatut && player.NbSickGivenForRadiation == m_NbSickGivenForRadiation * 3) //Already in zone
			{
				// I'm not reworking the logic on this.
			} else {
				player.IsInside.DZName = Status;
				player.IsInside.DZStatut = true;
				player.IsInside.DZType = 2;
				player.NbSickGivenForRadiation = m_NbSickGivenForRadiation * 3;
				player.GiveRadQtyToPlayerClothes();
				if (GetRadConfig().IsMsgActive == 1) {
					NotificationSystem.SendNotificationToPlayerIdentityExtended(player.GetIdentity(), 5, "Radiation Zone", GetRadConfig().MsgEnterZone, "BastionMod/BastionDangerousZone/images/radiation.paa");
				}
			}
			player.RadCheck();
		} else if ((pos[0] > GetSquarePercentageCoordonate(0.33, m_X1, m_X2) && pos[0] < GetSquarePercentageCoordonate(0.33, m_X2, m_X1)) && (pos[2] > GetSquarePercentageCoordonate(0.33, m_Y1, m_Y2) && pos[2] < GetSquarePercentageCoordonate(0.33, m_Y2, m_Y1))) {
			if (player.IsInside.DZName == Status && player.IsInside.DZStatut && player.NbSickGivenForRadiation == m_NbSickGivenForRadiation * 2) //Already in zone
			{
				// I'm not reworking the logic on this.
			} else {
				player.IsInside.DZName = Status;
				player.IsInside.DZStatut = true;
				player.IsInside.DZType = 2;
				player.NbSickGivenForRadiation = m_NbSickGivenForRadiation * 2;
				player.GiveRadQtyToPlayerClothes();
				if (GetRadConfig().IsMsgActive == 1) {
					NotificationSystem.SendNotificationToPlayerIdentityExtended(player.GetIdentity(), 5, "Radiation Zone", GetRadConfig().MsgEnterZone, "BastionMod/BastionDangerousZone/images/radiation.paa");
				}
			}
			player.RadCheck();
		} else if ((pos[0] > m_X1 && pos[0] < m_X2) && (pos[2] > m_Y1 && pos[2] < m_Y2)) {
			if (player.IsInside.DZName == Status && player.IsInside.DZStatut && player.NbSickGivenForRadiation == m_NbSickGivenForRadiation) //Already in zone
			{
			} else {
				player.IsInside.DZName = Status;
				player.IsInside.DZStatut = true;
				player.IsInside.DZType = 2;
				player.NbSickGivenForRadiation = m_NbSickGivenForRadiation;
				player.GiveRadQtyToPlayerClothes();
				if (GetRadConfig().IsMsgActive == 1) {
					NotificationSystem.SendNotificationToPlayerIdentityExtended(player.GetIdentity(), 5, "Radiation Zone", GetRadConfig().MsgEnterZone, "BastionMod/BastionDangerousZone/images/radiation.paa");
				}
			}
			player.RadCheck();
		} else {
			if (player.IsInside.DZName == Status && player.IsInside.DZStatut) {
				player.IsInside.DZStatut = false;
				player.IsInside.DZName = "";
				player.IsInside.DZType = 0;
				if (GetRadConfig().IsMsgActive == 0) return;
				NotificationSystem.SendNotificationToPlayerIdentityExtended(player.GetIdentity(), 5, "Radiation Zone", GetRadConfig().MsgExitZone, "BastionMod/BastionDangerousZone/images/radiation.paa");
			} else {
				return;
			}
		}
	}
}