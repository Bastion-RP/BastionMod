/*
	Class modifications written by RoomService
*/

modded class PlayerBase {
	private ref FileSerializer m_FileSerializer;
	private ref array<ref BST_MCMagObject> m_MagsToReload;
	private int BST_APICharID, BST_APICharClass;
	private string BST_APICharName;

	void PlayerBase() {
		m_MagsToReload = new array<ref BST_MCMagObject>();
		m_FileSerializer = new FileSerializer();
		BST_APICharID = -1;
		BST_APICharClass = -1;
	}

	override void OnStoreSave(ParamsWriteContext ctx) {
		if (BST_APICharID == -1 || !GetGame().IsServer() || !GetGame().IsMultiplayer()) { return; }
		BSTMCSaveInventory();
	}

	void BSTMCSaveInventory() {
		if (GetIdentity()) {
			Print(BST_MCConst.debugPrefix + "Saving player inventory! playerId=" + GetIdentity().GetPlainId() + " | playerIndex=" + BST_APICharID);
		}

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

			if (PlayerBase.Cast(m_EnumeratedInventory[i])) { continue; }
			ItemBase localItem;
			EntityAI localParent;
			InventoryLocation il;
			PlayerBase localPlayer;
			Magazine localAmmo;
			BST_MCSaveObject tempObject;

			localItem = ItemBase.Cast(m_EnumeratedInventory[i]);
			localParent = localItem.GetHierarchyParent();
			il = new InventoryLocation();

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

			tempObject.SetType(localItem.GetType());
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

			if (Class.CastTo(localAmmo, localItem)) {
				tempObject.SetQuantity(localAmmo.GetAmmoCount());
			} else if (localItem.GetCompEM()) {
				tempObject.SetQuantity(localItem.GetCompEM().GetEnergy());
			} else {
				tempObject.SetQuantity(localItem.GetQuantity());
			}
		}
		// Set needed values for the player
		m_SavePlayer.SetAPIData(BST_APICharName, BST_APICharID, BST_APICharClass);
		// Save Location
		m_SavePlayer.SetLocation(GetPosition(), GetDirection(), GetOrientation());
		// Save Life
		m_SavePlayer.WriteLife(GetHealth("", "Health"), GetHealth("", "Blood"), GetHealth("GlobalHealth", "Shock"));
		// Save Stats
		m_SavePlayer.WriteStats(GetPlayerStats().GetPCO(GetGame().SaveVersion()).Get());
		// Save lifespan
		m_SavePlayer.WriteLifespan(m_LifeSpanState, m_LastShavedSeconds, m_HasBloodyHandsVisible, m_HasBloodTypeVisible, m_BloodType);
		// Save modifiers
		m_SavePlayer.WriteModifiers(m_ModifiersManager.m_ModifierList);
		// Save agents
		m_SavePlayer.WriteAgents(m_AgentPool.m_VirusPool);
		// Save symptoms
		m_SavePlayer.WriteSymptoms(m_SymptomManager.m_SymptomQueuePrimary, m_SymptomManager.m_SymptomQueueSecondary);
		// Save bleeding
		m_SavePlayer.WriteBleeding(GetBleedingManagerServer(), GetBleedingBits());

		m_SavePlayer.SetType(GetType());
		m_SavePlayer.SetInventory(m_SaveObjects);

		string playerDir = BST_MCConst.loadoutDir + "\\" + GetIdentity().GetPlainId();
		if (!FileExist(playerDir))
			MakeDirectory(playerDir);

		// Use this for viewing it in plain-text for debugging. This function sucks for anything else. Use file serializer instead.
		JsonFileLoader<BST_MCSavePlayer>.JsonSaveFile(playerDir + "\\" + BST_APICharID + ".json", m_SavePlayer);

		delete m_SavePlayer;
		delete m_EnumeratedInventory;
		delete m_SaveObjects;
		delete m_RootChildren;
		delete m_ChildChildren;
	}

	override void EEKilled(Object killer) {
		Print(BST_MCConst.debugPrefix + GetIdentity().GetName() + " died, killing player at index=" + BST_APICharID);

		if (GetIdentity() && BST_APICharID != -1) {
			BST_MCSavePlayer savePlayer;
			string playerDir;

			playerDir = BST_MCConst.loadoutDir + "\\" + GetIdentity().GetPlainId() + "\\" + BST_APICharID + ".json";

			if (FileExist(playerDir)) {
				JsonFileLoader<BST_MCSavePlayer>.JsonLoadFile(playerDir, savePlayer);
			}
			if (!savePlayer) {
				savePlayer = new BST_MCSavePlayer();

				savePlayer.SetAPIData(BST_APICharName, BST_APICharID, BST_APICharClass);
				savePlayer.SetType(GetType());
			}
			savePlayer.ClearInventory();
			savePlayer.SetDead(true);
			savePlayer.SetDeathTimestamp(GetBSTLibTimestamp().GetCurrentTimestamp());
			JsonFileLoader<BST_MCSavePlayer>.JsonSaveFile(playerDir, savePlayer);
		}
		super.EEKilled(killer);
	}
	
	void BSTMCSetLifespan(BST_MCLifespan lifespan) {
		m_LifeSpanState = lifespan.GetState();
		m_LastShavedSeconds = lifespan.GetLastShaved();
		m_BloodType = lifespan.GetBloodType();
		m_HasBloodyHandsVisible = lifespan.IsBloodyHandsVisible();
		m_HasBloodTypeVisible = lifespan.IsBloodTypeVisible();
	}

	// Function identical to OnConnect, just no other mod relies on it. So I can initialize a client without worrying about mods calling OnConnect to data that doesn't exist.
	void BSTMCOnConnect() {
		Print(BST_MCConst.debugPrefix + "PlayerBase | BSTMCOnConnect | Player connected:" + this.ToString());

		// analytics
		GetGame().GetAnalyticsServer().OnPlayerConnect( this );
		
		m_PlayerOldPos = GetPosition();
		if( m_AnalyticsTimer )
			m_AnalyticsTimer.Run( 60, this, "UpdatePlayerMeasures", null, true );
		
		//construction action data
		ResetConstructionActionData();
	}

	void BSTMCSetCharData(int CharID, string charName, int charClass) {
		BST_APICharID = CharID;
		BST_APICharClass = charClass;
		BST_APICharName = charName;
	}

	string GetMultiCharactersPlayerName() { return BST_APICharName; }
	int GetMultiCharactersPlayerId() { return BST_APICharID; }
	int GetMultiCharactersPlayerClass() { return BST_APICharClass; }
}