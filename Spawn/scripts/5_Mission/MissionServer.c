modded class MissionServer {
	ref SavePlayer m_SavePlayer;
	ref array<vector> m_SpawnPoints;
	PlayerBase m_player;
	int m_PlayerIndex;

	override void OnClientPrepareEvent(PlayerIdentity identity, out bool useDB, out vector pos, out float yaw, out int preloadTimeout) {
		// Don't use the database for spawning players. This ensures that the game will spawn a new character every single time they spawn in.
		useDB = false;

		if (!GetHive()) {
			pos = "1189.3 0.0 5392.48";
			yaw = 0;
		}
	}

	void ProcessLoginData(ParamsReadContext ctx, out int playerIndex) {

		ref Param1<int> indexParam = new Param1<int>(-1);
		if (ctx.Read(indexParam)) {
			playerIndex = indexParam.param1;
		}
	}

	override PlayerBase CreateCharacter(PlayerIdentity identity, vector pos, ParamsReadContext ctx, string characterName) {
		return super.CreateCharacter(identity, pos, ctx, characterName);
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

		localParent.SetHealth("", "Health", objectToCreate.GetHealth());
		localItem = ItemBase.Cast(localParent);
		localAmmo = Magazine.Cast(localParent);

		if (localAmmo) {
			localAmmo.ServerSetAmmoCount(quant);
			if (slot != -1) {
				m_player.GetDayZPlayerInventory().PostWeaponEvent(new WeaponEventAttachMagazine(m_player, localAmmo));
			}
		} else if (localItem) {
			localItem.SetQuantity(quant);
		}

		for (int i = 0; i < children.Count(); i++) {
			CreateObjectChildren(localParent, children[i]);
		}
	}

	void SetValues() {
		float health, blood, shock, water, energy, playerWater, playerEnergy;
		health = m_SavePlayer.GetHealth();
		blood = m_SavePlayer.GetBlood();
		shock = m_SavePlayer.GetShock();
		water = m_SavePlayer.GetWater();
		energy = m_SavePlayer.GetEnergy();

		m_player.SetHealth("", "Health", health);
		m_player.SetHealth("", "Blood", blood);
		m_player.SetHealth("GlobalHealth", "Shock", shock);
		m_player.GetStatWater().Set(water);
		m_player.GetStatEnergy().Set(energy);
	}

	PlayerBase OnClientNewEvent(PlayerIdentity identity, vector pos, ParamsReadContext ctx) {
		ProcessLoginData(ctx, m_PlayerIndex);

		string dir = m_LoadoutDir + "\\" + identity.GetPlainId() + "\\" + m_PlayerIndex + m_FileType;
		ref array<ref SaveObject> inventory;
		string characterName;
		int inventorySize;
		int rndIndex;

		JsonFileLoader<ref SavePlayer>.JsonLoadFile(dir, m_SavePlayer);

		if (m_SavePlayer && !m_SavePlayer.IsDead()) {
			characterName = m_SavePlayer.GetType();
			pos = m_SavePlayer.GetPos();
		} else {
			characterName = GetGame().CreateRandomPlayer();
			JsonFileLoader<ref array<vector>>.JsonLoadFile(m_SpawnPointDir, m_SpawnPoints);

			rndIndex = Math.RandomInt(0, (m_SpawnPoints.Count() - 1));
			pos = m_SpawnPoints[rndIndex];
		}

		if (CreateCharacter(identity, pos, ctx, characterName)) {
			m_player.SetPlayerIndex(m_PlayerIndex);
			if (!m_SavePlayer || m_SavePlayer.IsDead())
				EquipCharacter();
		}

		if (m_SavePlayer) {
			inventory = m_SavePlayer.GetInventory();
			inventorySize = inventory.Count();

			SetValues();

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

				for (int j = 0; j < children.Count(); j++) {
					CreateObjectChildren(parent, children[j]);
				}
			}
		}

		m_player.SaveInventory();

		return m_player;
	}
}