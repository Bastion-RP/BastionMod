modded class MissionServer {
    protected ref JsonSerializer jsSerializer;
	string _mcDebugPrefix;

	void MissionServer() {
		jsSerializer = new JsonSerializer();
	}

	override void OnClientPrepareEvent(PlayerIdentity identity, out bool useDB, out vector pos, out float yaw, out int preloadTimeout) {
		// Don't use the database for spawning players. This ensures that the game will spawn a new character every single time they spawn in.
		useDB = false;
	}

	override void OnEvent(EventType eventTypeId, Param params) {
		if (eventTypeId == ClientNewEventTypeID) {
			// Params < PlayerIdentity, vector, ParamsReadContext
			ClientNewEventParams newParams = ClientNewEventParams.Cast(params);

			BSTMCProcessLogin(newParams.param1, newParams.param3);
		} else {
			super.OnEvent(eventTypeId, params);
		}
	}

	private void BSTMCProcessLogin(PlayerIdentity identity, ParamsReadContext ctx) {
		Param1<int> paramCharId;
		Param1<string> paramCharType;
		string pId, charType;

		pId = identity.GetPlainId();
		_mcDebugPrefix = GetBSTLibTimestamp().GetHourTimestampFormatted() + BST_MCConst.debugPrefix;

		ctx.Read(paramCharId);
		ctx.Read(paramCharType);

		charType = paramCharType.param1;

		Print(_mcDebugPrefix + "Processing new login, id=" + pId);

		if (!GetBSTMCServerManager().HasAPIData(pId)) { return; }
		BST_APICharacterId apiData = GetBSTMCServerManager().GetAPIDataById(pId, paramCharId.param1.ToString());

		if (!apiData) { return; }
		Print(_mcDebugPrefix + "Grabbed spawn data! id=" + apiData.GetCharacterId() + " | fname=" + apiData.GetFirstName() + " | lname=" + apiData.GetLastName());
		Print(_mcDebugPrefix + "Creating new character!");

		string dataDir;
		BST_MCSavePlayer playerData;
		PlayerBase newPlayer;

		dataDir = BST_MCConst.loadoutDir + "/" + pId + "/" + apiData.GetCharacterId() + ".json";

		Print(_mcDebugPrefix + "Checking if char file exists");

		if (FileExist(dataDir)) {
			JsonFileLoader<BST_MCSavePlayer>.JsonLoadFile(dataDir, playerData);

			Print(_mcDebugPrefix + "File exists, loading data");

			if (playerData) {
				Print(_mcDebugPrefix + "Data exists");

				charType = playerData.GetType();

				if (playerData.IsDead()) {
					Print(_mcDebugPrefix + "Character is dead, checking timestamp");

					int timestamp = GetBSTLibTimestamp().GetCurrentTimestamp();

					if (timestamp - playerData.GetDeathTimestamp() <= GetBSTMCManager().GetConfig().GetRespawnTimer()) {
						return;
					}
					playerData = null;
				}
			}
		}
		newPlayer = BSTMCCreateNewCharacter(identity, playerData, apiData.GetCitizenClass().ToInt(), charType);

		newPlayer.BSTMCSetCharData(apiData.GetCharacterId().ToInt(), apiData.GetFirstName() + " " + apiData.GetLastName(), apiData.GetCitizenClass().ToInt());
		GetGame().SelectPlayer(identity, newPlayer);
		InvokeOnConnect(newPlayer, identity);
		FinishSpawningClient(identity, newPlayer);
		newPlayer.BSTMCSaveInventory();
		GetGame().RPCSingleParam(newPlayer, BST_MCRPC.CLIENT_RECEIVE_PLAYER_API_DATA, new Param3<int, string, int>(apiData.GetCharacterId().ToInt(), apiData.GetFirstName() + " " + apiData.GetLastName(), apiData.GetCitizenClass().ToInt()), true, newPlayer.GetIdentity());
	}

	void FinishSpawningClient(PlayerIdentity identity, PlayerBase player) {
		Print(_mcDebugPrefix + "Finishing spawning client! id=" + identity.GetPlainId());
		SyncEvents.SendPlayerList();
		ControlPersonalLight(player);
		SyncGlobalLighting(player);
		Print(_mcDebugPrefix + "Finished spawning id=" + identity.GetPlainId());
	}
	
	private PlayerBase BSTMCCreateNewCharacter(PlayerIdentity identity, BST_MCSavePlayer playerData, int charClass, string charType) {
		Print(_mcDebugPrefix + "data=" + playerData + " | class=" + charClass + " | type=" + charType);

		PlayerBase newPlayer;

		if (playerData) {
			Print(_mcDebugPrefix + "Player is alive!");

			newPlayer = PlayerBase.Cast(GetGame().CreatePlayer(identity, charType, playerData.GetPos(), 0, "NONE"));

			// Set Position
			newPlayer.SetPosition(playerData.GetPos());
			newPlayer.SetDirection(playerData.GetDirection());
			newPlayer.SetOrientation(playerData.GetOrientation());
			// Set Life, Blood, Shock
			newPlayer.SetHealth("", "Health", playerData.GetHealth());
			newPlayer.SetHealth("", "Blood", playerData.GetBlood());
			newPlayer.SetHealth("GlobalHealth", "Shock", playerData.GetShock());
			// Load lifespan
			newPlayer.BSTMCSetLifespan(playerData.GetLifespan());
			// Load stats
			BSTMCLoadStats(newPlayer, playerData.GetStats());
			// Load modifiers
			BSTMCLoadModifiers(newPlayer, playerData.GetModifiers());
			// Loag agents
			BSTMCLoadAgents(newPlayer, playerData.GetAgents());
			// Load Symptoms
			BSTMCLoadSymptoms(newPlayer, playerData.GetSymptoms());
			// Load Bleeding
			newPlayer.GetBleedingManagerServer().BSTMCLoadBleedingSource(playerData.GetBleeding());
			// Load Stomach
				// Not implemented yet
			// Load broken legs state
				// This is for when EXP releases
		} else {
			Print(_mcDebugPrefix + "Player is dead or null");
			newPlayer = PlayerBase.Cast(GetGame().CreatePlayer(identity, charType, GetBSTMCServerManager().GetRandomSpawnpoint(), 0, "NONE"));
		}
		return newPlayer;
	}

	void BST_MCStartingSetup(PlayerBase player, int playerClass) { }

	private void BSTMCLoadStats(PlayerBase player, array<float> arrStats) {
		if (arrStats.Count() <= 0) {
			Print(_mcDebugPrefix + "Loading stats! Bailing! stats size = 0!");
			return;
		}
		array<ref PlayerStatBase> arrPlayerStats = player.GetPlayerStats().GetPCO(GetGame().SaveVersion()).Get();
		
		Print(_mcDebugPrefix + "Loading stats! stats size=" + arrStats.Count() + " | p pstats size=" + arrPlayerStats.Count());

		for (int i = 0; i < arrPlayerStats.Count(); i++) {
			PlayerStatBase playerStat = arrPlayerStats[i];
			PlayerStat<float> castStat = PlayerStat<float>.Cast(playerStat);
			PlayerStat<int> intStat = PlayerStat<int>.Cast(playerStat);

			if (castStat) {
				castStat.Set(arrStats[i]);
			} else {
				intStat.Set(arrStats[i])
			}
		}
	}

	private void BSTMCLoadModifiers(PlayerBase player, array<ref BST_MCSaveModifier> arrModifiers) {
		ref ModifiersManager manager = player.m_ModifiersManager;

		foreach (BST_MCSaveModifier saveModifier : arrModifiers) {
			if (!saveModifier) { continue; }
			ModifierBase modifier = manager.GetModifier(saveModifier.GetId());

			if (modifier) {
				if (modifier.IsTrackAttachedTime()) {
					modifier.SetAttachedTime(saveModifier.GetTime());
				}
				manager.ActivateModifier(saveModifier.GetId(), EActivationType.TRIGGER_EVENT_ON_CONNECT);
			}
		}
	}

	private void BSTMCLoadAgents(PlayerBase player, array<ref BST_MCSaveAgent> arrAgents) {
		foreach (BST_MCSaveAgent saveAgent : arrAgents) {
			if (!saveAgent) { return; }
			player.m_AgentPool.SetAgentCount(saveAgent.GetKey(), saveAgent.GetValue());
		}
	}

	private void BSTMCLoadSymptoms(PlayerBase player, array<int> arrSymptoms) {
		if (!player.GetSymptomManager()) { return; }
		foreach (int id : arrSymptoms) {
			if (player.GetSymptomManager().IsSymptomPrimary(id)) {
				player.GetSymptomManager().QueueUpPrimarySymptom(id);
			} else {
				player.GetSymptomManager().QueueUpSecondarySymptom(id);
			}
		}
	}
}