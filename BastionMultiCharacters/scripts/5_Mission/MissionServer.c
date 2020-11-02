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
		map<EntityAI, int> mapSetQuickbar = new map<EntityAI, int>();
		newPlayer = BSTMCCreateNewCharacter(identity, playerData, apiData.GetCitizenClass().ToInt(), charType, mapSetQuickbar);

		newPlayer.BSTMCSetCharData(apiData.GetCharacterId().ToInt(), apiData.GetFirstName() + " " + apiData.GetLastName(), apiData.GetCitizenClass().ToInt());
		GetGame().SelectPlayer(identity, newPlayer);
		InvokeOnConnect(newPlayer, identity);
		FinishSpawningClient(identity, newPlayer);
		newPlayer.BSTMCSaveInventory();
		GetGame().RPCSingleParam(newPlayer, BST_MCRPC.CLIENT_RECEIVE_PLAYER_API_DATA, new Param3<int, string, int>(apiData.GetCharacterId().ToInt(), apiData.GetFirstName() + " " + apiData.GetLastName(), apiData.GetCitizenClass().ToInt()), true, newPlayer.GetIdentity());
		GetBSTMCServerManager().RemoveAPIDataById(pId);

		// Set player quickbar. Has to be done after player has been set to identity, so client player != null
		for (int i = 0; i < mapSetQuickbar.Count(); i++) {
			newPlayer.SetQuickBarEntityShortcut(mapSetQuickbar.GetKey(i), mapSetQuickbar.GetElement(i));
		}
	}

	void FinishSpawningClient(PlayerIdentity identity, PlayerBase player) {
		Print(_mcDebugPrefix + "Finishing spawning client! id=" + identity.GetPlainId());
		SyncEvents.SendPlayerList();
		ControlPersonalLight(player);
		SyncGlobalLighting(player);
		Print(_mcDebugPrefix + "Finished spawning id=" + identity.GetPlainId());
	}
	
	private PlayerBase BSTMCCreateNewCharacter(PlayerIdentity identity, BST_MCSavePlayer playerData, int charClass, string charType, out map<EntityAI, int> mapSetQuickbar) {
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
			// Build inventory
			foreach (BST_MCSaveObject objData : playerData.GetInventory()) {
				if (!objData) { continue; }
				BSTMCCreateItem(newPlayer, newPlayer, objData, mapSetQuickbar);
			}
		} else {
			Print(_mcDebugPrefix + "Player is dead or null");
			// Logic for grabbing a spawnpoint
			vector randomSpawn = GetBSTMCServerManager().GetRandomSpawnPointByClass(charClass);
			
			Print(_mcDebugPrefix + "Grabbed random spawn point=" + randomSpawn);
			
			newPlayer = PlayerBase.Cast(GetGame().CreatePlayer(identity, charType, randomSpawn, 0, "NONE"));

			BST_MCStartingSetup(newPlayer, charClass);
		}
		return newPlayer;
	}

	void BST_MCStartingSetup(PlayerBase player, int playerClass) { }

	private void BSTMCCreateItem(PlayerBase player, EntityAI parent, BST_MCSaveObject objData, out map<EntityAI, int> mapSetQuickbar) {
		array<ref BST_MCSaveObject> arrChildren;
		EntityAI newEnt;

		if (player == parent && objData.IsInHands()) {
			newEnt = player.GetHumanInventory().CreateInHands(objData.GetType());
		} else if (objData.GetSlot() != -1) {
			if (Weapon.Cast(parent)) {
				newEnt = EntityAI.Cast(GetGame().CreateObjectEx(objData.GetType(), parent.GetPosition(), ECE_PLACE_ON_SURFACE));
			} else {
				newEnt = parent.GetInventory().CreateAttachmentEx(objData.GetType(), objData.GetSlot());
			}
		} else {
			newEnt = parent.GetInventory().CreateEntityInCargoEx(objData.GetType(), objData.GetIndex(), objData.GetRow(), objData.GetCol(), objData.GetFlip());
		}
		if (!newEnt) { return; }
		arrChildren = objData.GetChildren();

		if (objData.GetQuickbarSlot() != -1) {
			mapSetQuickbar.Insert(newEnt, objData.GetQuickbarSlot());
		}
		newEnt.SetHealth("", "Health", objData.GetHealth());
		BSTMCSetItemQuant(newEnt, objData.GetQuantity());

		foreach (BST_MCSaveObject childData : arrChildren) {
			BSTMCCreateItem(player, newEnt, childData, mapSetQuickbar);
		}
	}

	private void BSTMCSetItemQuant(EntityAI ent, int quant) {
		ItemBase item = ItemBase.Cast(ent);
		Magazine ammo = Magazine.Cast(ent);

		if (ammo) {
			ammo.ServerSetAmmoCount(quant);
		} else if (item && item.GetCompEM()) {
			item.GetCompEM().SetEnergy(quant);
		} else {
			item.SetQuantity(quant);
		}
	}

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
				intStat.Set(arrStats[i]);
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