modded class MissionServer {
	private ref array<vector> multiCharactersSpawnPoints;

	void MissionServer() {
		//JsonFileLoader<ref array<vector>>.JsonLoadFile(m_NCCSpawnPointDir, m_NCCSpawnPoints);
		JsonFileLoader<ref array<vector>>.JsonLoadFile(MCConst.spawnPointDir, multiCharactersSpawnPoints);
	}

	override void OnClientPrepareEvent(PlayerIdentity identity, out bool useDB, out vector pos, out float yaw, out int preloadTimeout) {
		// Don't use the database for spawning players. This ensures that the game will spawn a new character every single time they spawn in.
		useDB = false;

		if (!GetHive()) {
			pos = "1189.3 0.0 5392.48";
			yaw = 0;
		}
	}

	void ProcessLoginData(ParamsReadContext ctx, PlayerIdentity sender, out int characterId, out string characterType, out string characterName) {
		Print(MCConst.debugPrefix + "Reading login data");
		ref Param1<int> dataCharacterId = new Param1<int>(-1);
		ref Param1<string> dataCharacterType = new Param1<string>("");
		ref Param1<string> dataCharacterName = new Param1<string>("");

		if (ctx.Read(dataCharacterId)) {
			characterId = dataCharacterId.param1;
		}
		if (ctx.Read(dataCharacterType)) {
			characterType = dataCharacterType.param1;
		}
		if (ctx.Read(dataCharacterName)) {
			characterName = dataCharacterName.param1;
		}
		if (characterName == string.Empty) {
			GetGame().RPCSingleParam(null, MultiCharRPC.CLIENT_DISCONNECT, null, true, sender);
		}
		Print(MCConst.debugPrefix + "Read");
	}
	
	void EquipCharacter(PlayerBase player)
	{
		EntityAI item = player.GetInventory().CreateInInventory(topsArray.GetRandomElement());
		EntityAI item2 = player.GetInventory().CreateInInventory(pantsArray.GetRandomElement());
		EntityAI item3 = player.GetInventory().CreateInInventory(shoesArray.GetRandomElement());
		
		StartingEquipSetup(player, false);
	}

	void BuildInventory(PlayerBase newPlayer, SavePlayer savePlayer) {
		if (savePlayer) {
			ref array<ref SaveObject> arrayInventory = savePlayer.GetInventory()
			Print(MCConst.debugPrefix + "Spawning previous player loadout playername=" + newPlayer.GetIdentity().GetName() + " | playerIndex=" + newPlayer.GetCharacterId());

			foreach (SaveObject saveObject : arrayInventory) {
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
			newPlayer.SpawnMissingMags();
		} else {
			EquipCharacter(newPlayer);
		}
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

	void SetPlayerStats(PlayerBase player, SavePlayer savePlayer) {
		Print(MCConst.debugPrefix + "Setting player values playername=" + player.GetIdentity().GetName() + " | playerIndex=" + player.GetCharacterId());

		float health, blood, shock, water, energy, playerWater, playerEnergy;
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
	}

	PlayerBase CreateNewPlayer(PlayerIdentity identity, vector pos, ParamsReadContext ctx, string characterType) {
		PlayerBase newPlayer = PlayerBase.Cast(GetGame().CreatePlayer(identity, characterType, pos, 0, "NONE"));

		GetGame().SelectPlayer(identity, newPlayer);
	
		return newPlayer;
	}

	PlayerBase OnClientNewEvent(PlayerIdentity identity, vector pos, ParamsReadContext ctx) {
		PlayerBase newPlayer;
		SavePlayer savePlayer;
		vector playerPos;
		int characterId;
		string characterType, characterName, saveDir;

		ProcessLoginData(ctx, identity, characterId, characterType, characterName);
		saveDir = MCConst.loadoutDir + "\\" + identity.GetPlainId() + "\\" + characterId + MCConst.fileType;

		if (FileExist(saveDir)) {
			JsonFileLoader<SavePlayer>.JsonLoadFile(saveDir, savePlayer);

			if (savePlayer) {
				characterType = savePlayer.GetType();
				playerPos = savePlayer.GetPos();
			}
		} else {
			if (characterType == string.Empty) {
				characterType = GetGame().CreateRandomPlayer();
			}
			playerPos = multiCharactersSpawnPoints.GetRandomElement();
		}
		newPlayer = CreateNewPlayer(identity, playerPos, ctx, characterType);

		if (savePlayer) {
			SetPlayerStats(newPlayer, savePlayer);
			newPlayer.SetPosition(playerPos);
		}
		newPlayer.SetCharacterName(characterName);
		newPlayer.SetCharacterId(characterId);
		BuildInventory(newPlayer, savePlayer);
		newPlayer.SaveInventory();
		
		return newPlayer;
	}
}