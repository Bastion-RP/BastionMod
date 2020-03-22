modded class PlayerBase {
	private ref FileSerializer m_FileSerializer;
	private ref array<ref MagObject> m_MagsToReload;
	private int multicharactersPlayerId;
	private string multicharactersPlayerName;

	void PlayerBase() {
		m_MagsToReload = new array<ref MagObject>();
		m_FileSerializer = new FileSerializer();
		multicharactersPlayerId = -1;
	}

	override void OnStoreSave(ParamsWriteContext ctx) {
		if (multicharactersPlayerId == -1) { return; }
		SaveInventory();
	}

	void InsertMag(ref MagObject mag) {
		m_MagsToReload.Insert(mag);
	}

	void SpawnMissingMags() {
		Print(MCConst.debugPrefix + "Spawning mags in player inventory instead of weapon! playername=" + this.GetIdentity().GetName() + " | playerId=" + this.GetIdentity().GetPlainId());
		if (!m_MagsToReload) {
			m_MagsToReload = new array<ref MagObject>();
		}
		int magCount = m_MagsToReload.Count();
		for(int i = 0; i < magCount; i++) {
			InventoryLocation loc = new InventoryLocation();
			string type = m_MagsToReload[i].GetType();
			float count = m_MagsToReload[i].GetCount();
			EntityAI localItem;
			Magazine localMag;
			
			if (GetInventory().FindFirstFreeLocationForNewEntity(type, FindInventoryLocationType.CARGO, loc)) {
				localItem = loc.GetParent().GetInventory().CreateEntityInCargoEx(type, loc.GetIdx(), loc.GetRow(), loc.GetCol(), loc.GetFlip());
			}
			if (localItem) {
				Print(MCConst.debugPrefix + "Found item, casting as mag!");
				localMag = Magazine.Cast(localItem);
				if (localMag) {
					Print(MCConst.debugPrefix + "Found mag, setting ammo count!");
					localMag.ServerSetAmmoCount(count);
				}
			}
		}
		if (magCount > 0) {
			Param1<int> param = new Param1<int>(magCount);
			g_Game.RPCSingleParam(this, MultiCharRPC.CLIENT_SPAWN_MAG, param, true, this.GetIdentity());
		}
		delete m_MagsToReload;
	}

	void SaveInventory() {
		if (!GetGame().IsServer() || !GetGame().IsMultiplayer() || !GetIdentity() || !IsAlive()) { return; }
		Print(MCConst.debugPrefix + "Saving player inventory! playerId=" + this.GetIdentity().GetPlainId() + " | playerIndex=" + multicharactersPlayerId);

		SavePlayer m_SavePlayer = new SavePlayer();
		array<EntityAI> m_EnumeratedInventory = new array<EntityAI>();
		array<ref SaveObject> m_SaveObjects = new array<ref SaveObject>();
		array<ref SaveObject> m_RootChildren = new array<ref SaveObject>();
		array<ref SaveObject> m_ChildChildren = new array<ref SaveObject>();
		EntityAI m_Root;
		EntityAI m_ChildRoot;

		GetHumanInventory().EnumerateInventory(InventoryTraversalType.PREORDER, m_EnumeratedInventory);

		for (int i = (m_EnumeratedInventory.Count() - 1); i > -1; i--) {
			EntityAI localEntity = m_EnumeratedInventory[i];

			if (PlayerBase.Cast(localEntity))
				continue;

			ItemBase localItem = ItemBase.Cast(m_EnumeratedInventory[i]);
			EntityAI localParent = localItem.GetHierarchyParent();
			InventoryLocation il = new InventoryLocation();
			PlayerBase localPlayer;
			Magazine localAmmo;
			SaveObject tempObject;

			// Grab the InventoryLocation of the current object to grab the slot/index to spawn in the object later
			localEntity.GetInventory().GetCurrentInventoryLocation(il);
			tempObject = new SaveObject();

			// No root object, set one.
			if (!m_Root)
				m_Root = localParent;

			// Given the way preoder works, check to see if the parent isn't the root ( This means that it went to an object further out in the inventory ).
			// If the entity isn't the root and the parent isn't the root and the parent isn't the player, we went further into the inventory
			if (localParent != m_Root && localEntity != m_Root && !Class.CastTo(localPlayer, localParent)) {
				if (!m_ChildRoot)
					m_ChildRoot = localParent;

				// If this isn't the parent, it's a child
				if (m_ChildRoot != localEntity) {
					m_ChildChildren.Insert(tempObject);
				} else {
					// Set the children on the object. This object then becomes a child itself
					tempObject.SetChildren(m_ChildChildren);
					m_ChildChildren = new array<ref SaveObject>();
					m_ChildChildren.Insert(tempObject);
					m_ChildRoot = localParent;
				}
			} else {
				// If a child
				if (m_Root != localEntity && !Class.CastTo(localPlayer, localParent)) {
					// Insert it into the child array
					m_RootChildren.Insert(tempObject);

					// If more children were found, set them on this object
					if (m_ChildRoot && m_ChildChildren.Count() > 0) {
						tempObject.SetChildren(m_ChildChildren);
						m_ChildRoot = null;
						m_ChildChildren = new array<ref SaveObject>();
					}
				} else {
					// This is the root
					tempObject.SetChildren(m_RootChildren);
					m_RootChildren = new array<ref SaveObject>();

					// Parent is player, don't grab player as parent
					if (Class.CastTo(localPlayer, localParent)) {
						m_SaveObjects.Insert(tempObject);
						m_Root = null;
					} else {
						m_RootChildren.Insert(tempObject);
						m_Root = localParent;
					}
				}
			}

			tempObject.SetType(localEntity.GetType());
			tempObject.SetHealth(localItem.GetHealth("", ""));

			if (localItem == GetHumanInventory().GetEntityInHands()) {
				tempObject.SetHands();
			} else {
				tempObject.SetSlot(il.GetSlot());
				tempObject.SetIdx(il.GetIdx());
				tempObject.SetRow(il.GetRow());
				tempObject.SetCol(il.GetCol());
				tempObject.SetFlip(il.GetFlip());
			}

			if (Class.CastTo(localAmmo, localEntity)) {
				tempObject.SetQuantity(localAmmo.GetAmmoCount());
			} else
				tempObject.SetQuantity(localItem.GetQuantity());
		}

		// Set needed values for the player
		m_SavePlayer.SetCharacterName(multicharactersPlayerName);
		m_SavePlayer.SetCharacterId(multicharactersPlayerId);
		m_SavePlayer.SetType(GetType());
		m_SavePlayer.SetPos(GetPosition());
		m_SavePlayer.SetDirection(GetDirection());
		m_SavePlayer.SetOrientation(GetOrientation());
		m_SavePlayer.SetInventory(m_SaveObjects);
		m_SavePlayer.SetHealth(GetHealth("", "Health"));
		m_SavePlayer.SetBlood(GetHealth("", "Blood"));
		m_SavePlayer.SetShock(GetHealth("GlobalHealth", "Shock"));
		m_SavePlayer.SetWater(GetStatWater().Get());
		m_SavePlayer.SetEnergy(GetStatEnergy().Get());

		string playerDir = MCConst.loadoutDir + "\\" + GetIdentity().GetPlainId();
		if (!FileExist(playerDir))
			MakeDirectory(playerDir);

		// Use this for viewing it in plain-text for debugging. This function sucks for anything else. Use file serializer instead.
		JsonFileLoader<ref SavePlayer>.JsonSaveFile(playerDir + "\\" + multicharactersPlayerId + MCConst.fileType, m_SavePlayer);

		delete m_SavePlayer;
		delete m_EnumeratedInventory;
		delete m_SaveObjects;
		delete m_RootChildren;
		delete m_ChildChildren;
	}

	override void EEKilled(Object killer) { 
		super.EEKilled(killer);

		Print(MCConst.debugPrefix + this.GetIdentity().GetName() + " died, killing player at index=" + multicharactersPlayerId);

		string playerDir = MCConst.loadoutDir + "\\" + GetIdentity().GetPlainId();
		DeleteFile(playerDir + "\\" + multicharactersPlayerId + MCConst.fileType);
	}

	void SetCharacterId(int multicharactersPlayerId) {
		this.multicharactersPlayerId = multicharactersPlayerId;
	}

	void SetCharacterName(string multicharactersPlayerName) {
		this.multicharactersPlayerName = multicharactersPlayerName;
	}

	int GetCharacterId() {
		return multicharactersPlayerId;
	}
}