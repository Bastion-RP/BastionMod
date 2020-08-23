class BST_MCSavePlayerBasic {
	protected ref array<ref BST_MCSaveObject> _arrInventory;
	protected int _charId, _charClass, _deathTimestamp;
	protected bool _isDead;
    protected string _charName, _survivorType;
	protected float _health, _blood, _shock, _water, _energy;

    void BST_MCSavePlayerBasic() {
		_arrInventory = new array<ref BST_MCSaveObject>();
    }

	void SetAPIData(string charName, int charId, int charClass) {
		_charName = charName;
		_charId = charId;
		_charClass = charClass;
	}

	void SetLifeStats(float health, float blood, float shock, float water, float energy) {
		_health = health;
		_blood = blood;
		_shock = shock;
		_water = water;
		_energy = energy;
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

	void ClearInventory() {
		_arrInventory = new array<ref BST_MCSaveObject>();
	}

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
	float GetHealth() { return _health; }
	float GetBlood() { return _blood; }
	float GetShock() { return _shock; }
	float GetWater() { return _water; }
	float GetEnergy() { return _energy; }
}