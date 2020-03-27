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
								//auto spawnData = new Param3<PlayerIdentity, int, string>(identity, dataCharacterId.param1, dataCharacterType.param1);

								ThreadOnClientNewEvent(identity, dataCharacterId.param1, dataCharacterType.param1);

        						//GetGame().GameScript.Call(this, "ThreadOnClientNewEvent", spawnData);
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
	
	void ThreadOnClientNewEvent(/*Param3<PlayerIdentity, int, string> spawnData*/PlayerIdentity identity, int characterId, string characterType) {
		Print(MCConst.debugPrefix + "MissionServer | ThreadOnClientNewEvent | New thread created to spawn player");
		/* PlayerIdentity identity = spawnData.param1;
		int characterId = spawnData.param2;
		string characterType = spawnData.param3; */

		if (characterId != 0) {
			Print(MCConst.debugPrefix + "MissionServer | ThreadOnClientNewEvent | Loading client! id=" + identity.GetPlainId() + " | char id=" + characterId + " | char type=" + characterType);
			CURLCore curlCore;
			MultiCharactersCURL mcCurl;
			CURLContext curlCtx;
			MultiCharactersCharacterId webCharData;
			map<string, string> webSteamData;
			string error, data;

			curlCore = CreateCURLCore();
			mcCurl = new MultiCharactersCURL();
			curlCtx = curlCore.GetCURLContext("https://bastionrp.com/api/");
			jsSerializer.ReadFromString(webCharData, curlCtx.GET_now(MultiCharactersCURLEndpoints.ENDPOINT_BY_CHARACTER_ID + characterId), error);
			jsSerializer.ReadFromString(webSteamData, curlCtx.GET_now(MultiCharactersCURLEndpoints.ENDPOINT_BY_STEAM_ID + identity.GetPlainId()), error);

			if (webCharData && webSteamData && webSteamData.Contains(MCCurlConst.memberId) && webCharData.GetMemberId().ToInt() != 0 && webCharData.GetMemberId().ToInt() == webSteamData.Get(MCCurlConst.memberId).ToInt()) {
				Print(MCConst.debugPrefix + "MissionServer | ThreadOnClientNewEvent | Data received and validated!");
				PlayerBase newPlayer;
				SavePlayer savePlayer;
				string saveDir;

				saveDir = MCConst.loadoutDir + "\\" + identity.GetPlainId() + "\\" + characterId + MCConst.fileType;

				if (FileExist(saveDir)) {
					JsonFileLoader<SavePlayer>.JsonLoadFile(saveDir, savePlayer);

					if (savePlayer) {
						newPlayer = PlayerBase.Cast(GetGame().CreatePlayer(identity, savePlayer.GetType(), savePlayer.GetPos(), 0, "NONE"));

						LoadPlayer(newPlayer, savePlayer);
					}
				} else {
					vector spawnPos;

					if (webCharData.GetCitizenClass().ToInt() == BastionClasses.S) {
						spawnPos = GetMultiCharactersServerManager().GetRandomISFSpawnpoint();
					} else {
						spawnPos = GetMultiCharactersServerManager().GetRandomSpawnpoint();
					}
					
					newPlayer = PlayerBase.Cast(GetGame().CreatePlayer(identity, characterType, spawnPos, 0, "NONE"));

					newPlayer.GetInventory().CreateInInventory(topsArray.GetRandomElement());
					newPlayer.GetInventory().CreateInInventory(pantsArray.GetRandomElement());
					newPlayer.GetInventory().CreateInInventory(shoesArray.GetRandomElement());
					StartingEquipSetup(newPlayer, false);
				}
				newPlayer.SetMultiCharacterStats(characterId, webCharData.GetFirstName() + " " + webCharData.GetLastName(), webCharData.GetCitizenClass().ToInt());
				newPlayer.SaveInventory();
				GetGame().SelectPlayer(identity, newPlayer);
				FinishSpawningClient(identity, newPlayer);
			} else {
				Print(MCConst.debugPrefix + "MissionServer | OnClientNewEvent | Could not validate client! id=" + identity.GetPlainId());
				GetGame().DisconnectPlayer(identity);
				GetGame().RPCSingleParam(null, MultiCharRPC.CLIENT_DISCONNECT, null, true, identity);
			}
		}
		GetGame().GameScript.Release();
	}

	void InitializeClient(PlayerIdentity identity) {
		Print(MCConst.debugPrefix + "MissionServer | InitializeClient | Initializing client! id=" + identity.GetPlainId());
		PlayerBase player = PlayerBase.Cast(GetGame().CreatePlayer(identity, GetGame().CreateRandomPlayer(), "0 0 0", 0, "NONE"));

		GetGame().SelectPlayer(identity, player);
		FinishSpawningClient(identity, player);
		player.SetHealth("", "Health", 0);
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(GetGame().ObjectDelete, 5000, false, player);
	}

	void FinishSpawningClient(PlayerIdentity identity, PlayerBase player) {
		Print(MCConst.debugPrefix + "MissionServer | FinishSpawningClient | Finishing spawning client! id=" + identity.GetPlainId());
		InvokeOnConnect(player, identity);
		SyncEvents.SendPlayerList();
		ControlPersonalLight(player);
		SyncGlobalLighting(player);
	}

	void BuildInventory(PlayerBase newPlayer, SavePlayer savePlayer) {
		ref array<ref SaveObject> arrayInventory = savePlayer.GetInventory();

		foreach (SaveObject saveObject : arrayInventory) {
			if (saveObject) {
				array<ref SaveObject> arrayChildren = saveObject.GetChildren();
				EntityAI parent;

				if (saveObject.IsInHands()) {
					parent = newPlayer.GetHumanInventory().CreateInHands(saveObject.GetType());
				} else {
					parent = newPlayer.GetInventory().CreateInInventory(saveObject.GetType());
				}
				parent.SetHealth("", "Health", saveObject.GetHealth());
				SetItemQuantity(parent, saveObject.GetQuantity());

				foreach (SaveObject childObject : arrayChildren) {
					CreateObjectChildren(newPlayer, parent, childObject);
				}
			}
		}
		newPlayer.SpawnMissingMags();
	}

	void CreateObjectChildren(PlayerBase player, EntityAI parent, SaveObject objectToCreate) {
		array<ref SaveObject> children = objectToCreate.GetChildren();
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
		if (!localParent) {
			Print(MCConst.debugPrefix + "Could not spawn item type=" + type + " | playername=" + player.GetIdentity().GetName() + " | Exiting...");
			return;
		}
		localParent.SetHealth("", "Health", objectToCreate.GetHealth());

		if (slot != -1) {
			if (Class.CastTo(localAmmo, localParent)) {
				MagObject mag = new MagObject(localAmmo.GetType(), quant);
				player.InsertMag(mag);
				localParent.Delete();
				return;
			}
		} else {
			SetItemQuantity(localParent, quant, slot);
		}
		foreach (SaveObject saveObject : children) {
			CreateObjectChildren(player, localParent, saveObject);
		}
	}

	void SetItemQuantity(EntityAI item, int quant, int slot = -1) {
		ItemBase localItem = ItemBase.Cast(item);
		Magazine localAmmo = Magazine.Cast(item);

		if (localAmmo) {
			localAmmo.ServerSetAmmoCount(quant);
		} else if (localItem) {
			localItem.SetQuantity(quant);
		}
	}

	void LoadPlayer(PlayerBase player, SavePlayer savePlayer) {
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
		BuildInventory(player, savePlayer);
	}
}