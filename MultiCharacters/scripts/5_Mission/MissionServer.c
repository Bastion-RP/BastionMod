modded class MissionServer {
	override void OnClientPrepareEvent(PlayerIdentity identity, out bool useDB, out vector pos, out float yaw, out int preloadTimeout) {
		// Don't use the database for spawning players. This ensures that the game will spawn a new character every single time they spawn in.
		useDB = false;

		if (!GetHive()) {
			pos = "1189.3 0.0 5392.48";
			yaw = 0;
		}
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

	PlayerBase OnClientNewEvent(PlayerIdentity identity, vector pos, ParamsReadContext ctx) {
		// Read data from client
		Param1<int> dataCharacterId;
		Param1<bool> dataIsInitializing;
		Param1<string> dataCharacterType, dataCharacterName;

		if (!ctx.Read(dataCharacterId) || !ctx.Read(dataCharacterType) || !ctx.Read(dataCharacterName) || !ctx.Read(dataIsInitializing)) {
        	Print(MCConst.debugPrefix + "MissionServer | OnClientNewEvent | Data not found! Disconnecting client! id=" + identity.GetPlainId());
			GetGame().DisconnectPlayer(identity);
			GetGame().RPCSingleParam(null, MultiCharRPC.CLIENT_DISCONNECT, null, true, identity);
		}
		if (dataIsInitializing.param1) {
        	Print(MCConst.debugPrefix + "MissionServer | OnClientNewEvent | Initializing client! id=" + identity.GetPlainId())
			PlayerBase initPlayer = PlayerBase.Cast(GetGame().CreatePlayer(identity, GetGame().CreateRandomPlayer(), "0 0 0", 0, "NONE"));

			GetGame().SelectPlayer(identity, initPlayer);
			initPlayer.SetHealth("", "Health", 0);
			GetGame().RPCSingleParam(null, MultiCharRPC.CLIENT_FINISH_INITIALIZATION, null, true, identity);
			GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(GetGame().ObjectDelete, 5000, false, initPlayer);
			return initPlayer;
		}
		Print(MCConst.debugPrefix + "MissionServer | OnClientNewEvent | Loading client! id=" + identity.GetPlainId())
		PlayerBase newPlayer;
		SavePlayer savePlayer;
		string saveDir = MCConst.loadoutDir + "\\" + identity.GetPlainId() + "\\" + dataCharacterId.param1 + MCConst.fileType;

		if (FileExist(saveDir)) {
			JsonFileLoader<SavePlayer>.JsonLoadFile(saveDir, savePlayer);

			if (savePlayer) {
				newPlayer = PlayerBase.Cast(GetGame().CreatePlayer(identity, savePlayer.GetType(), savePlayer.GetPos(), 0, "NONE"));

				LoadPlayer(newPlayer, savePlayer);
			}
		} else {
			vector spawnPos = GetMultiCharactersServerManager().GetRandomSpawnpoint();

			if (spawnPos == vector.Zero) {
				spawnPos = GetMultiCharactersServerManager().GetRandomSpawnpoint();
			}
			newPlayer = PlayerBase.Cast(GetGame().CreatePlayer(identity, dataCharacterType.param1, spawnPos, 0, "NONE"));

			newPlayer.GetInventory().CreateInInventory(topsArray.GetRandomElement());
			newPlayer.GetInventory().CreateInInventory(pantsArray.GetRandomElement());
			newPlayer.GetInventory().CreateInInventory(shoesArray.GetRandomElement());
			StartingEquipSetup(newPlayer, false);
		}
		newPlayer.SetCharacterName(dataCharacterName.param1);
		newPlayer.SetCharacterId(dataCharacterId.param1);
		newPlayer.SaveInventory();
		GetGame().SelectPlayer(identity, newPlayer);
		
		return newPlayer;
	}
}