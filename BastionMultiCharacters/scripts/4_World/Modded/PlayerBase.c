modded class PlayerBase {
	private ref FileSerializer m_FileSerializer;
	private ref array<ref BST_MCMagObject> m_MagsToReload;
	private int multicharactersPlayerId, multicharactersPlayerClass;
	private string multicharactersPlayerName;
	private bool bstMCCanSavePlayer;

	void PlayerBase() {
		m_MagsToReload = new array<ref BST_MCMagObject>();
		m_FileSerializer = new FileSerializer();
		bstMCCanSavePlayer = true;
		multicharactersPlayerId = -1;
		multicharactersPlayerClass = -1;
	}

	override void OnStoreSave(ParamsWriteContext ctx) {
		if (multicharactersPlayerId == -1) { return; }
		SaveInventory();
	}

	void InsertMag(ref BST_MCMagObject mag) {
		m_MagsToReload.Insert(mag);
	}

	void SpawnMissingMags() {
		if (!m_MagsToReload) {
			m_MagsToReload = new array<ref BST_MCMagObject>();
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
			} else {
				localItem = GetGame().CreateObjectEx(type, GetPosition(), ECE_PLACE_ON_SURFACE);
			}
			
			if (localItem) {
				localMag = Magazine.Cast(localItem);
				if (localMag) {
					localMag.ServerSetAmmoCount(count);
				}
			}
		}
		/* if (magCount > 0) {
			Param1<int> param = new Param1<int>(magCount);
			g_Game.RPCSingleParam(this, MultiCharRPC.CLIENT_SPAWN_MAG, param, true, GetIdentity());
		} */
		delete m_MagsToReload;
	}

	void SaveInventory() {
		if (!GetGame().IsServer() || !GetGame().IsMultiplayer() || !GetIdentity() || !IsAlive() || !bstMCCanSavePlayer) { return; }
		Print(MCConst.debugPrefix + "Saving player inventory! playerId=" + this.GetIdentity().GetPlainId() + " | playerIndex=" + multicharactersPlayerId);

		BST_MCSavePlayer m_SavePlayer = new BST_MCSavePlayer();
		array<EntityAI> m_EnumeratedInventory = new array<EntityAI>();
		array<ref BST_MCSaveObject> m_SaveObjects = new array<ref BST_MCSaveObject>();
		array<ref BST_MCSaveObject> m_RootChildren = new array<ref BST_MCSaveObject>();
		array<ref BST_MCSaveObject> m_ChildChildren = new array<ref BST_MCSaveObject>();
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
			Weapon_Base localWeapon;
			BST_MCSaveObject tempObject;

			// Grab the InventoryLocation of the current object to grab the slot/index to spawn in the object later
			localEntity.GetInventory().GetCurrentInventoryLocation(il);
			tempObject = new BST_MCSaveObject();

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
					m_ChildChildren = new array<ref BST_MCSaveObject>();
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
						m_ChildChildren = new array<ref BST_MCSaveObject>();
					}
				} else {
					// This is the root
					tempObject.SetChildren(m_RootChildren);
					m_RootChildren = new array<ref BST_MCSaveObject>();

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
			} else if (Class.CastTo(localWeapon, localEntity)) {
				ref BST_MCSaveObject pile = new BST_MCSaveObject();
				int muzzle = localWeapon.GetCurrentMuzzle();
				pile.SetType(localWeapon.GetChamberAmmoTypeName(muzzle));
				pile.SetQuantity(localWeapon.GetTotalCartridgeCount(muzzle));
				if (pile.GetQuantity() > 0) tempObject.AddChild(pile);
			} else if (localItem && localItem.GetCompEM()) {
				tempObject.SetQuantity(localItem.GetCompEM().GetEnergy());
			} else {
				tempObject.SetQuantity(localItem.GetQuantity());
			}
		}

		// Set needed values for the player
		m_SavePlayer.SetAPIData(multicharactersPlayerName, multicharactersPlayerId, multicharactersPlayerClass);
		m_SavePlayer.SetLocation(GetPosition(), GetDirection(), GetOrientation());
		m_SavePlayer.SetLifeStats(GetHealth("", "Health"), GetHealth("", "Blood"), GetHealth("GlobalHealth", "Shock"), GetStatWater().Get(), GetStatEnergy().Get());

		// Save lifespan
		m_SavePlayer.SetLifespan(m_LifeSpanState, m_LastShavedSeconds, m_HasBloodyHandsVisible, m_HasBloodTypeVisible, m_BloodType);
		// Save modifiers
		m_SavePlayer.WriteModifiers(m_ModifiersManager.m_ModifierList);
		// Save agents
		m_SavePlayer.WriteAgents(m_AgentPool.m_VirusPool);
		// Save symptoms
		m_SavePlayer.WriteSymptoms(m_SymptomManager.m_SymptomQueuePrimary, m_SymptomManager.m_SymptomQueueSecondary);
		// Save bleeding
		Print("[DEBUG] GetBleedingBits=" + GetBleedingBits());
		m_SavePlayer.WriteBleeding(GetBleedingManagerServer(), GetBleedingBits());

		m_SavePlayer.SetType(GetType());
		m_SavePlayer.SetInventory(m_SaveObjects);

		string playerDir = MCConst.loadoutDir + "\\" + GetIdentity().GetPlainId();
		if (!FileExist(playerDir))
			MakeDirectory(playerDir);

		// Use this for viewing it in plain-text for debugging. This function sucks for anything else. Use file serializer instead.
		JsonFileLoader<BST_MCSavePlayer>.JsonSaveFile(playerDir + "\\" + multicharactersPlayerId + MCConst.fileType, m_SavePlayer);

		delete m_SavePlayer;
		delete m_EnumeratedInventory;
		delete m_SaveObjects;
		delete m_RootChildren;
		delete m_ChildChildren;
	}
	
	override void OnDisconnect() {
		if (IsRestrained() || IsUnconscious()) {
			if (GetIdentity()) {
				Print(MCConst.debugPrefix + "OnDisconnect | Player logged out while restrained or unconcious!!! " + GetIdentity().GetName() + " | playerIndex=" + multicharactersPlayerId);
			} else {
				Print(MCConst.debugPrefix + "OnDisconnect | Player logged out while restrained or unconcious!!! | playerIndex=" + multicharactersPlayerId);
			}
			BSTMCKillPlayer();

			bstMCCanSavePlayer = false;
		}
		super.OnDisconnect();
	}

	override void EEKilled(Object killer) {
		if (GetIdentity()) {
			Print(MCConst.debugPrefix + GetIdentity().GetName() + " died, killing player at index=" + multicharactersPlayerId);
		} else {
			Print(MCConst.debugPrefix + "Player died, killing player at index=" + multicharactersPlayerId);
		}
		BSTMCKillPlayer();
		super.EEKilled(killer);
	}

	void BSTMCKillPlayer() {
		Print(MCConst.debugPrefix + "BSTMCKillPlayer | kill function called");
		if (GetIdentity() && multicharactersPlayerId != -1 && bstMCCanSavePlayer) {
			BST_MCSavePlayer savePlayer;
			string playerDir;


			playerDir = MCConst.loadoutDir + "\\" + GetIdentity().GetPlainId() + "\\" + multicharactersPlayerId + MCConst.fileType;
			Print(MCConst.debugPrefix + "BSTMCKillPlayer | playerDir = " + playerDir);

			if (FileExist(playerDir)) {
				Print(MCConst.debugPrefix + "BSTMCKillPlayer | File exists, loading");
				JsonFileLoader<BST_MCSavePlayer>.JsonLoadFile(playerDir, savePlayer);
			}
			if (!savePlayer) {
				Print(MCConst.debugPrefix + "BSTMCKillPlayer | Save player doesn't exist, creating new one!!!");
				savePlayer = new BST_MCSavePlayer();

				savePlayer.SetAPIData(multicharactersPlayerName, multicharactersPlayerId, multicharactersPlayerClass);
				savePlayer.SetType(GetType());
			}
			Print(MCConst.debugPrefix + "BSTMCKillPlayer | Clearing character inventory and setting death timestamp!!!");
			savePlayer.ClearInventory();
			savePlayer.SetDead(true);
			savePlayer.SetDeathTimestamp(GetBSTLibTimestamp().GetCurrentTimestamp());
			JsonFileLoader<BST_MCSavePlayer>.JsonSaveFile(playerDir, savePlayer);
		}
	}
	
	void BSTMCSetLifespan(int state, int lastShaved, bool bloodHands, bool bloodVisible, int bloodType) {
		m_LifeSpanState = state;
		m_LastShavedSeconds = lastShaved;
		m_HasBloodyHandsVisible = bloodHands;
		m_HasBloodTypeVisible = bloodVisible;
		m_BloodType = bloodType;
	}

	// Function identical to OnConnect, just no other mod relies on it. So I can initialize a client without worrying about mods calling OnConnect to data that doesn't exist.
	void MultiCharInit() {
		Print(MCConst.debugPrefix + "PlayerBase | MultiCharInit | Player connected:" + this.ToString());

		// analytics
		GetGame().GetAnalyticsServer().OnPlayerConnect( this );
		
		m_PlayerOldPos = GetPosition();
		if( m_AnalyticsTimer )
			m_AnalyticsTimer.Run( 60, this, "UpdatePlayerMeasures", null, true );
		
		//construction action data
		ResetConstructionActionData();
	}

	void SetMultiCharacterStats(int multicharactersPlayerId, string multicharactersPlayerName, int multicharactersPlayerClass) {
		this.multicharactersPlayerId = multicharactersPlayerId;
		this.multicharactersPlayerClass = multicharactersPlayerClass;
		this.multicharactersPlayerName = multicharactersPlayerName;
	}

	string GetMultiCharactersPlayerName() { return multicharactersPlayerName; }
	int GetMultiCharactersPlayerId() { return multicharactersPlayerId; }
	int GetMultiCharactersPlayerClass() { return multicharactersPlayerClass; }
}