modded class MissionServer {
	ref array<vector> m_SpawnPoints;
	ref array<vector> m_NCCSpawnPoints;
	PlayerBase m_player;
	ref SavePlayer m_SavePlayer;
	int m_PlayerIndex;
	string newSurvivorString;
	string dir;
	bool isWhitelisted;

	void MissionServer() {
		JsonFileLoader<ref array<vector>>.JsonLoadFile(m_NCCSpawnPointDir, m_NCCSpawnPoints);
		JsonFileLoader<ref array<vector>>.JsonLoadFile(m_SpawnPointDir, m_SpawnPoints);
	}

	override void OnClientPrepareEvent(PlayerIdentity identity, out bool useDB, out vector pos, out float yaw, out int preloadTimeout) {
		// Don't use the database for spawning players. This ensures that the game will spawn a new character every single time they spawn in.
		useDB = false;

		if (!GetHive()) {
			pos = "1189.3 0.0 5392.48";
			yaw = 0;
		}
	}

	void ProcessLoginData(ParamsReadContext ctx, out int playerIndex, out string survivorString) {
		ref Param1<int> indexParam = new Param1<int>(-1);
		if (ctx.Read(indexParam)) {
			playerIndex = indexParam.param1;
		}

		ref Param1<string> survivorStringParam = new Param1<string>("");
		if (ctx.Read(survivorStringParam)) {
			survivorString = survivorStringParam.param1;
		}
	}

	void BuildInventory() {
		ref array<ref SaveObject> inventory;
		int inventorySize;

		if (m_SavePlayer) {
			Print(m_DebugPrefix + "Spawning previous player loadout playername=" + m_player.GetIdentity().GetName() + " | playerIndex=" + m_PlayerIndex);

			inventory = m_SavePlayer.GetInventory();
			inventorySize = inventory.Count();

			SetValues(m_SavePlayer);

			for (int i = 0; i < inventorySize; i++) {
				ref SaveObject objectToCreate = inventory[i];
				ref array<ref SaveObject> children = objectToCreate.GetChildren();
				ref EntityAI parent;

				if (objectToCreate.IsInHands()) {
					parent = m_player.GetHumanInventory().CreateInHands(objectToCreate.GetType());
				} else {
					parent = m_player.GetInventory().CreateInInventory(objectToCreate.GetType());
				}

				parent.SetHealth("", "Health", objectToCreate.GetHealth());
				SetItemQuantity(parent, objectToCreate.GetQuantity());

				for (int j = 0; j < children.Count(); j++) {
					CreateObjectChildren(parent, children[j]);
				}
			}
			m_player.SpawnMissingMags();
		} else {
			EquipCharacter();
		}
		m_player.SaveInventory();
	}

	void CreateObjectChildren(ref EntityAI parent, ref SaveObject objectToCreate) {
		ref array<ref SaveObject> children = objectToCreate.GetChildren();
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
			Print(m_DebugPrefix + "Could not spawn item type=" + type + " | playername=" + m_player.GetIdentity().GetName() + " | Exiting...");
			return;
		}

		localParent.SetHealth("", "Health", objectToCreate.GetHealth());

		if (slot != -1) {
			if (Class.CastTo(localAmmo, localParent)) {
				MagObject mag = new MagObject(localAmmo.GetType(), quant);
				m_player.InsertMag(mag);
				localParent.Delete();
				return;
			}
		} else {
			SetItemQuantity(localParent, quant, slot);
		}

		for (int i = 0; i < children.Count(); i++) {
			CreateObjectChildren(localParent, children[i]);
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

	void SetValues(SavePlayer savePlayer) {
		Print(m_DebugPrefix + "Setting player values playername=" + m_player.GetIdentity().GetName() + " | playerIndex=" + m_PlayerIndex);

		float health, blood, shock, water, energy, playerWater, playerEnergy;
		health = savePlayer.GetHealth();
		blood = savePlayer.GetBlood();
		shock = savePlayer.GetShock();
		water = savePlayer.GetWater();
		energy = savePlayer.GetEnergy();

		m_player.SetHealth("", "Health", health);
		m_player.SetHealth("", "Blood", blood);
		m_player.SetHealth("GlobalHealth", "Shock", shock);
		m_player.GetStatWater().Set(water);
		m_player.GetStatEnergy().Set(energy);
	}

	PlayerBase CreateNewPlayer(PlayerIdentity identity, vector pos, ParamsReadContext ctx, string characterName) {
		Entity playerEnt;
		playerEnt = GetGame().CreatePlayer(identity, characterName, pos, 0, "NONE");//Creates random player
		Class.CastTo(m_player, playerEnt);

		if (m_PlayerIndex == 5 && !isWhitelisted) {
			Print(m_DebugPrefix + "Player not whitelisted yet chose whitelisted slot! playername=" + identity.GetName() + " | playerId=" + identity.GetPlainId());
			m_player.SetHealth("", "Health", 0);
			DeleteFile(dir);
		}
		if (m_SavePlayer) {
			Print(m_DebugPrefix + "Setting player position to previous position playername=" + identity.GetName() + " | playerId=" + identity.GetPlainId());
			m_player.SetPosition(pos);
		}

		GetGame().SelectPlayer(identity, m_player);
		m_player.SetPlayerIndex(m_PlayerIndex);
	
		return m_player;
	}

	PlayerBase OnClientNewEvent(PlayerIdentity identity, vector pos, ParamsReadContext ctx) {
		ProcessLoginData(ctx, m_PlayerIndex, newSurvivorString);

		string characterName;
		int rndIndex;
		m_SavePlayer = null;
		dir = m_LoadoutDir + "\\" + identity.GetPlainId() + "\\" + m_PlayerIndex + m_BSTFileType;
		isWhitelisted = g_Game.IsWhitelisted(identity.GetPlainId());

		JsonFileLoader<ref SavePlayer>.JsonLoadFile(dir, m_SavePlayer);

		if (m_SavePlayer) {
			characterName = m_SavePlayer.GetType();
			pos = m_SavePlayer.GetPos();
		} else {
			if (newSurvivorString != "") {
				characterName = newSurvivorString;
			} else {
				characterName = GetGame().CreateRandomPlayer();
			}

			if (m_PlayerIndex == 5 && isWhitelisted) {
				Print(m_DebugPrefix + "Spawning player as whitelisted NCC! playername=" + identity.GetName() + " | playerId=" + identity.GetPlainId());
				pos = m_NCCSpawnPoints.GetRandomElement();
			} else {
				pos = m_SpawnPoints.GetRandomElement();
			}
		}

		CreateNewPlayer(identity, pos, ctx, characterName);
		BuildInventory();
		
		return m_player;
	}
}