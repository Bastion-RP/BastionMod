modded class PlayerBase {
	ref FileSerializer m_FileSerializer = new FileSerializer();
	ref array<ref MagObject> m_MagsToReload = new array<ref MagObject>();
	int m_PlayerIndex;

	override void OnStoreSave(ParamsWriteContext ctx) {
		if (!this) return;
		Print(m_DebugPrefix + "Saving player inventory | playerid=" + GetIdentity().GetPlainId());
		// Don't save the inventory since there's no use. Not using the DB for players anyways.
		SaveInventory();
	}

	void InsertMag(ref MagObject mag) {
		m_MagsToReload.Insert(mag);
	}

	void SpawnMissingMags() {
		Print(m_DebugPrefix + "Spawning mags in player inventory instead of weapon! playername=" + this.GetIdentity().GetName() + " | playerId=" + this.GetIdentity().GetPlainId());
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
				Print(m_DebugPrefix + "Found item, casting as mag!");
				localMag = Magazine.Cast(localItem);
				if (localMag) {
					Print(m_DebugPrefix + "Found mag, setting ammo count!");
					localMag.ServerSetAmmoCount(count);
				}
			}
		}
		if (magCount > 0) {
			Param1<int> param = new Param1<int>(magCount);
			g_Game.RPCSingleParam(this, MultiCharRPC.CLIENT_SPAWN_MAG, param, true, this.GetIdentity());
		}
	}

	void SaveInventory() {
		if (!GetGame().IsServer()) return;

		SavePlayer m_SavePlayer = new SavePlayer();
		array<EntityAI> m_EnumeratedInventory = new array<EntityAI>();
		array<EntityAI> m_InOrder = new array<EntityAI>();
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
		m_SavePlayer.SetIndex(m_PlayerIndex);
		m_SavePlayer.SetType(GetType());
		m_SavePlayer.SetPos(GetPosition());
		m_SavePlayer.SetInventory(m_SaveObjects);
		m_SavePlayer.SetHealth(GetHealth("", "Health"));
		m_SavePlayer.SetBlood(GetHealth("", "Blood"));
		m_SavePlayer.SetShock(GetHealth("GlobalHealth", "Shock"));
		m_SavePlayer.SetWater(GetStatWater().Get());
		m_SavePlayer.SetEnergy(GetStatEnergy().Get());

		string playerDir = m_LoadoutDir + "\\" + GetIdentity().GetPlainId();
		if (!FileExist(playerDir))
			MakeDirectory(playerDir);

		// Use this for viewing it in plain-text for debugging. This function fucking sucks for anything else. Use file serializer instead.
		JsonFileLoader<ref SavePlayer>.JsonSaveFile(playerDir + "\\" + m_PlayerIndex + m_BSTFileType, m_SavePlayer);
	}

	override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx) {
		super.OnRPC(sender, rpc_type, ctx);

		if (rpc_type == MultiCharRPC.CLIENT_SPAWN_MAG) {
			Param1<int> magCount;
			ctx.Read(magCount);

			int magsRemoved = magCount.param1;
			NotificationSystem.AddNotification(NotificationType.NOTIFICATIONS_END, 10, "" + magsRemoved + " mag(s) were removed from your weapon(s)\n and placed into your inventory!" );
		}
	}

	override void EEKilled(Object killer) { 
		super.EEKilled(killer);

		Print(m_DebugPrefix + this.GetIdentity().GetName() + " died, killing player at index=" + m_PlayerIndex);

		string playerDir = m_LoadoutDir + "\\" + GetIdentity().GetPlainId();
		SavePlayer tempPlayer;

		DeleteFile(playerDir + "\\" + m_PlayerIndex + m_BSTFileType);
	}

	void SetPlayerIndex(int playerIndex) {
		m_PlayerIndex = playerIndex;
	}
}