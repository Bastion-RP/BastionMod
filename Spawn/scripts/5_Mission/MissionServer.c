modded class MissionServer {
	ref SavePlayer m_SavePlayer;
	PlayerBase m_player;
	int m_PlayerIndex;

	override void OnClientReadyEvent(PlayerIdentity identity, PlayerBase player) {
		Print(" FUNCTION OnClientReadyEvent !! ");
		super.OnClientReadyEvent(identity, player);
	}

	override void OnClientPrepareEvent(PlayerIdentity identity, out bool useDB, out vector pos, out float yaw, out int preloadTimeout) {
		// Don't use the database for spawning players. This ensures that the game will spawn a new character every single time they spawn in.
		useDB = false;

		if (!GetHive()) {
			pos = "1189.3 0.0 5392.48";
			yaw = 0;
		}
	}

	void ProcessLoginData(ParamsReadContext ctx, out int playerIndex) {
		Print(" FUNCTION ProcessLoginData !! ");

		ref Param1<int> indexParam = new Param1<int>(-1);
		if (ctx.Read(indexParam)) {
			Print("PARAM READ | param=" + indexParam.param1);
			playerIndex = indexParam.param1;
		}
	}

	override PlayerBase CreateCharacter(PlayerIdentity identity, vector pos, ParamsReadContext ctx, string characterName) {
		Print(" FUNCTION CreateCharacter !! ");
		return super.CreateCharacter(identity, pos, ctx, characterName);
	}

	override void EquipCharacter() {
		Print(" FUNCTION EquipCharacter !! ");
		m_player.SetPlayerIndex(m_PlayerIndex);
		super.EquipCharacter();
	}

	void SetValues() {
		float health, blood, shock, water, energy, playerWater, playerEnergy, diffWater, diffEnergy;
		health = m_SavePlayer.GetHealth();
		blood = m_SavePlayer.GetBlood();
		shock = m_SavePlayer.GetShock();
		water = m_SavePlayer.GetWater();
		energy = m_SavePlayer.GetEnergy();
		playerWater = m_player.GetStatWater().Get();
		playerEnergy = m_player.GetStatEnergy().Get();

		Print("What's this | " + playerWater);
		Print("What's this | " + playerEnergy);

		diffWater = water - playerWater;
		diffEnergy = energy - playerEnergy;

		Print("VALUES | " + health + " | " + blood + " | " + shock + " | " + water + " | " + energy + " | " + playerWater + " | " + playerEnergy + " | " + diffWater + " | " + diffEnergy);

		m_player.SetHealth("", "Health", health);
		m_player.SetHealth("", "Blood", blood);
		m_player.SetHealth("GlobalHealth", "Shock", shock);
		m_player.GetStatWater().Add(diffWater);
		m_player.GetStatEnergy().Add(diffEnergy);
	}

	PlayerBase OnClientNewEvent(PlayerIdentity identity, vector pos, ParamsReadContext ctx) {
		Print(" FUNCTION OnClientNewEvent !! ");
		Print(" FUNCTION OnClientNewEvent | identity=" + identity + " | pos=" + pos + " | ctx=" + ctx);

		ProcessLoginData(ctx, m_PlayerIndex);

		string characterName;
		string dir = m_LoadoutDir + "\\" + identity.GetPlainId() + "\\" + m_PlayerIndex + m_FileType;
		JsonFileLoader<ref SavePlayer>.JsonLoadFile(dir, m_SavePlayer);

		if (m_SavePlayer) {
			Print("Player found");
			characterName = m_SavePlayer.GetType();
			pos = m_SavePlayer.GetPos();
		} else {
			Print("No player found");
			characterName = GetGame().CreateRandomPlayer();
			pos = "1189.3 0.0 5392.48";
		}

		if (CreateCharacter(identity, pos, ctx, characterName)) {
			EquipCharacter();
		}

		if (m_SavePlayer)
			SetValues();

		return m_player;
	}
}