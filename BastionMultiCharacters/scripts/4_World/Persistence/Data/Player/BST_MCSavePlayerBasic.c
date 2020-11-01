/*
	Class written by RoomService
*/

class BST_MCSavePlayerBasic {
	protected ref array<ref BST_MCSaveObject> _arrInventory;
	protected int _charId, _charClass, _deathTimestamp;
	protected bool _isDead;
    protected string _charName, _survivorType;

    void BST_MCSavePlayerBasic() {
		_arrInventory = new array<ref BST_MCSaveObject>();
    }

	void SetAPIData(string charName, int charId, int charClass) {
		_charName = charName;
		_charId = charId;
		_charClass = charClass;
	}

	void SetDeathTimestamp(int deathTimestamp) {
		_deathTimestamp = deathTimestamp;
	}

	void SetDead(bool isDead) {
		_isDead = isDead;
	}

	void SetType(string survivorType) {
		_survivorType = survivorType;
	}

	void SetInventory(array<ref BST_MCSaveObject> arrInventory) {
		_arrInventory = arrInventory;
	}
	
	/*
		Completely clears inventory.
		Only used for Death... NEVER call otherwise
	*/
	void ClearInventory() {
		_arrInventory = new array<ref BST_MCSaveObject>();
	}
	
	/*
		Purges all inventory items except for root attachments
		Be EXTREMELY careful when calling this. Should only be called
		on data being passed to client. NEVER call before saving data.
	*/
    void PurgeInventoryItems() {
        foreach (BST_MCSaveObject saveObject : _arrInventory) {
            if (!saveObject) { continue; }
            saveObject.ClearChildren();
        }
    }

	array<ref BST_MCSaveObject> GetInventory() { return _arrInventory; }
	bool IsDead() { return _isDead; }
	int GetDeathTimestamp() { return _deathTimestamp; }
	int GetCharacterId() { return _charId; }
	int GetCharacterClass() { return _charClass; }
	string GetName() { return _charName; }
	string GetType() { return _survivorType; }
}