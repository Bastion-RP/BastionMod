modded class MissionServer {
    protected ref JsonSerializer jsSerializer;

	void MissionServer() {
		jsSerializer = new JsonSerializer();
	}

	override void OnClientPrepareEvent(PlayerIdentity identity, out bool useDB, out vector pos, out float yaw, out int preloadTimeout) {
		// Don't use the database for spawning players. This ensures that the game will spawn a new character every single time they spawn in.
		useDB = false;

		if (!GetHive()) {
			pos = "1189.3 0.0 5392.48";
			yaw = 0;
		}
	}

	override void OnEvent(EventType eventTypeId, Param params) {
		switch (eventTypeId) {
			case ClientNewEventTypeID:
				{
					ClientNewEventParams clientSpawnParams = ClientNewEventParams.Cast(params);

					if (clientSpawnParams) {
						PlayerIdentity identity = clientSpawnParams.param1;
						ParamsReadContext ctx = clientSpawnParams.param3;

						if (identity && ctx) {
							Param1<int> dataCharacterId;
							Param1<string> dataCharacterType;
							Param1<bool> dataIsInitializing;

							ctx.Read(dataCharacterId);
							ctx.Read(dataCharacterType);
							ctx.Read(dataIsInitializing);

							if (dataIsInitializing.param1) {
								InitializeClient(identity);
							} else {
								Print(MCConst.debugPrefix + "MissionServer | OnEvent | ClientNewEventTypeID | Creating new thread to spawn player!");
								ThreadOnClientNewEvent(identity, dataCharacterId.param1, dataCharacterType.param1);
							}
						}
					}
					break;
				}
			default:
				{
					super.OnEvent(eventTypeId, params);
					break;
				}
		}
	}
	
	void ThreadOnClientNewEvent(PlayerIdentity identity, int characterId, string characterType) {
		Print(MCConst.debugPrefix + "MissionServer | ThreadOnClientNewEvent | New thread created to spawn player");

		if (characterId != 0) {
			Print(MCConst.debugPrefix + "MissionServer | ThreadOnClientNewEvent | Loading client! id=" + identity.GetPlainId() + " | char id=" + characterId + " | char type=" + characterType);
			RestApi curlCore;
			MultiCharactersCURL mcCurl;
			RestContext curlCtx;
			MultiCharactersCharacterId webCharData;
			map<string, string> webSteamData;
			string error, data;

			curlCore = CreateRestApi();
			mcCurl = new MultiCharactersCURL();
			curlCtx = curlCore.GetRestContext("https://bastionrp.com/api/");
			jsSerializer.ReadFromString(webCharData, curlCtx.GET_now(MultiCharactersCURLEndpoints.ENDPOINT_BY_CHARACTER_ID + characterId), error);
			jsSerializer.ReadFromString(webSteamData, curlCtx.GET_now(MultiCharactersCURLEndpoints.ENDPOINT_BY_STEAM_ID + identity.GetPlainId()), error);

			if (webCharData && webSteamData && webSteamData.Contains(MCCurlConst.memberId) && webCharData.GetMemberId().ToInt() != 0 && webCharData.GetMemberId().ToInt() == webSteamData.Get(MCCurlConst.memberId).ToInt()) {
				Print(MCConst.debugPrefix + "MissionServer | ThreadOnClientNewEvent | Data received and validated!");
				PlayerBase newPlayer;
				BST_MCSavePlayer savePlayer;
				Param params;
				string saveDir;
				bool validPlayer;

				validPlayer = false;
				params = new Param3<int, string, int>(characterId, webCharData.GetFirstName() + " " + webCharData.GetLastName(), webCharData.GetCitizenClass().ToInt());
				saveDir = MCConst.loadoutDir + "\\" + identity.GetPlainId() + "\\" + characterId + MCConst.fileType;

				if (FileExist(saveDir)) {
					JsonFileLoader<BST_MCSavePlayer>.JsonLoadFile(saveDir, savePlayer);

					if (savePlayer) {
						int currentTimestamp = GetBSTLibTimestamp().GetCurrentTimestamp();

						if (currentTimestamp - savePlayer.GetDeathTimestamp() <= GetBSTMCManager().GetConfig().GetRespawnTimer()) {
							// Kick player. Somehow they chose a character they shouldn't have.
            				GetGame().RPCSingleParam(null, MultiCharRPC.CLIENT_DISCONNECT, null, true, identity);
							return;
						}
						if (!savePlayer.IsDead()) {
							newPlayer = PlayerBase.Cast(GetGame().CreatePlayer(identity, savePlayer.GetType(), savePlayer.GetPos(), 0, "NONE"));
							validPlayer = true;

							LoadPlayer(newPlayer, savePlayer);
						}
					}
				}
				if (!validPlayer) {
					vector spawnPos;

					if (webCharData.GetCitizenClass().ToInt() >= BastionClasses.ISF_F && webCharData.GetCitizenClass().ToInt() <= BastionClasses.ISF_E) {
						spawnPos = GetMultiCharactersServerManager().GetRandomISFSpawnpoint();
					} else {
						spawnPos = GetMultiCharactersServerManager().GetRandomSpawnpoint();
					}
					
					newPlayer = PlayerBase.Cast(GetGame().CreatePlayer(identity, characterType, spawnPos, 0, "NONE"));
					
					if (webCharData.GetCitizenClass().ToInt() >= BastionClasses.ISF_F && webCharData.GetCitizenClass().ToInt() <= BastionClasses.ISF_E) {
						StartingISFSetup(newPlayer);
					} else {
						newPlayer.GetInventory().CreateInInventory(topsArray.GetRandomElement());
						newPlayer.GetInventory().CreateInInventory(pantsArray.GetRandomElement());
						newPlayer.GetInventory().CreateInInventory(shoesArray.GetRandomElement());
						StartingEquipSetup(newPlayer, false);
					}
				}
				newPlayer.SetMultiCharacterStats(characterId, webCharData.GetFirstName() + " " + webCharData.GetLastName(), webCharData.GetCitizenClass().ToInt());
				newPlayer.SaveInventory();
				GetGame().SelectPlayer(identity, newPlayer);
				InvokeOnConnect(newPlayer, identity);
				FinishSpawningClient(identity, newPlayer);

				Print(MCConst.debugPrefix + "MissionServer | ThreadOnClientNewEvent | Sending API data to client");
        		GetGame().RPCSingleParam(newPlayer, MultiCharRPC.CLIENT_RECEIVE_PLAYER_API_DATA, params, true, newPlayer.GetIdentity());
				Print(MCConst.debugPrefix + "MissionServer | ThreadOnClientNewEvent | API Data Sent");
			} else {
				Print(MCConst.debugPrefix + "MissionServer | ThreadOnClientNewEvent | Could not validate client! id=" + identity.GetPlainId());
				GetGame().DisconnectPlayer(identity);
				GetGame().RPCSingleParam(null, MultiCharRPC.CLIENT_DISCONNECT, null, true, identity);
			}
		}
	}

	void StartingISFSetup(PlayerBase player) {}

	void InitializeClient(PlayerIdentity identity) {
		Print(MCConst.debugPrefix + "MissionServer | InitializeClient | Initializing client! id=" + identity.GetPlainId());
		PlayerBase player = PlayerBase.Cast(GetGame().CreatePlayer(identity, GetGame().CreateRandomPlayer(), "0 0 0", 0, "NONE"));

		GetGame().SelectPlayer(identity, player);
		if (player) {
			player.MultiCharInit();
		}
		FinishSpawningClient(identity, player);
		player.SetHealth("", "Health", 0);
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(GetGame().ObjectDelete, 5000, false, player);
		Print(MCConst.debugPrefix + "MissionServer | InitializeClient | Client Initialized! id=" + identity.GetPlainId());
	}

	void FinishSpawningClient(PlayerIdentity identity, PlayerBase player) {
		Print(MCConst.debugPrefix + "MissionServer | FinishSpawningClient | Finishing spawning client! id=" + identity.GetPlainId());
		SyncEvents.SendPlayerList();
		ControlPersonalLight(player);
		SyncGlobalLighting(player);
		Print(MCConst.debugPrefix + "MissionServer | FinishSpawningClient | Finished spawning id=" + identity.GetPlainId());
	}

	void BuildInventory(PlayerBase newPlayer, BST_MCSavePlayer savePlayer) {
		ref array<ref BST_MCSaveObject> arrayInventory = savePlayer.GetInventory();

		foreach (BST_MCSaveObject saveObject : arrayInventory) {
			if (saveObject) {
				array<ref BST_MCSaveObject> arrayChildren = saveObject.GetChildren();
				EntityAI parent;

				if (saveObject.IsInHands()) {
					parent = newPlayer.GetHumanInventory().CreateInHands(saveObject.GetType());
				} else {
					parent = newPlayer.GetInventory().CreateInInventory(saveObject.GetType());
				}
				if (!parent) { continue; }
				parent.SetHealth("", "Health", saveObject.GetHealth());
				SetItemQuantity(parent, saveObject.GetQuantity());

				foreach (BST_MCSaveObject childObject : arrayChildren) {
					CreateObjectChildren(newPlayer, parent, childObject);
				}
			}
		}
		newPlayer.SpawnMissingMags();
	}

	void CreateObjectChildren(PlayerBase player, EntityAI parent, BST_MCSaveObject objectToCreate) {
		array<ref BST_MCSaveObject> children = objectToCreate.GetChildren();
		Weapon_Base localWeapon;
		Magazine localAmmo;
		ItemBase localItem;
		EntityAI localParent;
		string type;
		int quant, slot, index, row, col, flip;

		type = objectToCreate.GetType();
		quant = objectToCreate.GetQuantity();
		slot = objectToCreate.GetSlot();
		index = objectToCreate.GetIndex();
		row = objectToCreate.GetRow();
		col = objectToCreate.GetCol();
		flip = objectToCreate.GetFlip();

		if (slot == -1) {
			localParent = parent.GetInventory().CreateEntityInCargoEx(type, index, row, col, flip);
		} else {
			localParent = parent.GetInventory().CreateAttachmentEx(type, slot);
		}

		// this is awful
		if (!localParent && parent.IsWeapon()) {
			localParent = GetGame().CreateObjectEx(type, parent.GetPosition(), ECE_PLACE_ON_SURFACE);
		}
		if (!localParent) return;
		localParent.SetHealth("", "Health", objectToCreate.GetHealth());

		if ((slot != -1 || parent.IsWeapon()) && Class.CastTo(localAmmo, localParent)) {
			player.InsertMag(new BST_MCMagObject(localAmmo.GetType(), quant));
			localParent.Delete();
			return;
		}
		SetItemQuantity(localParent, quant, slot);
		
		foreach (BST_MCSaveObject saveObject : children) {
			CreateObjectChildren(player, localParent, saveObject);
		}
	}

	void SetItemQuantity(EntityAI item, int quant, int slot = -1) {
		ItemBase localItem = ItemBase.Cast(item);
		Magazine localAmmo = Magazine.Cast(item);

		if (localAmmo) {
			localAmmo.ServerSetAmmoCount(quant);
		} else if (localItem && localItem.GetCompEM()) {
			localItem.GetCompEM().SetEnergy(quant);
		} else {
			localItem.SetQuantity(quant);
		}
	}

	void LoadPlayer(PlayerBase player, BST_MCSavePlayer savePlayer) {
		vector position, direction, orientation;
		float health, blood, shock, water, energy, playerWater, playerEnergy;
		position = savePlayer.GetPos();
		direction = savePlayer.GetDirection();
		orientation = savePlayer.GetOrientation();
		health = savePlayer.GetHealth();
		blood = savePlayer.GetBlood();
		shock = savePlayer.GetShock();
		water = savePlayer.GetWater();
		energy = savePlayer.GetEnergy();

		player.SetHealth("", "Health", health);
		player.SetHealth("", "Blood", blood);
		player.SetHealth("GlobalHealth", "Shock", shock);
		player.GetStatWater().Set(water);
		player.GetStatEnergy().Set(energy);
		player.SetPosition(savePlayer.GetPos());
		player.SetDirection(savePlayer.GetDirection());
		player.SetOrientation(savePlayer.GetOrientation());
		player.BSTMCSetLifespan(savePlayer.GetLifespanState(), savePlayer.GetLifespanLastShaved(), savePlayer.GetLifespanBloodyHandsVisible(), savePlayer.GetLifespanBloodTypeVisible(), savePlayer.GetLifespanBloodType());
		player.GetBleedingManagerServer().BSTMCLoadBleedingSource(savePlayer.GetBleeding());
		BSTMCLoadModifiers(player, savePlayer.GetModifiers());
		BSTMCLoadAgents(player, savePlayer.GetAgents());
		BSTMCLoadSymptoms(player, savePlayer.GetSymptoms());
		BuildInventory(player, savePlayer);
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