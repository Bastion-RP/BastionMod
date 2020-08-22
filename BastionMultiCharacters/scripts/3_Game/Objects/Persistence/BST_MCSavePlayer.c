class BST_MCSavePlayer {
	private ref array<ref BST_MCSaveObject> _arrInventory;
	private int _charId, _charClass, _deathTimestamp;
	private bool _isDead;
	private string _charName, _survivorType, _position, _direction, _orientation;
	private float _health, _blood, _shock, _water, _energy;

	void BST_MCSavePlayer() {
		_arrInventory = new array<ref BST_MCSaveObject>();
	}

	void SetDeathTimestamp (int deathTimestamp) {
		_deathTimestamp = deathTimestamp;
	}

	void SetCharacterName(string charName) {
		_charName = charName;
	}

	void SetCharacterId(int charId) {
		_charId = charId;
	}

	void SetCharacterClass(int charClass) {
		_charClass = charClass;
	}

	void SetDead(bool isDead) {
		_isDead = isDead;
	}

	void SetName(string charName) {
		_charName = charName;
	}

	void SetType(string survivorType) {
		_survivorType = survivorType;
	}

	void SetHealth(float health) {
		_health = health;
	}

	void SetBlood(float blood) {
		_blood = blood;
	}

	void SetShock(float shock) {
		_shock = shock;
	}

	void SetWater(float water) {
		_water = water;
	}

	void SetEnergy(float energy) {
		_energy = energy;
	}

	void SetPos(vector position) {
		_position = "" + position[0] + " " + position[1] + " " + position[2];
	}

	void SetDirection(vector direction) {
		_direction = "" + direction[0] + " " + direction[1] + " " + direction[2];
	}

	void SetOrientation(vector orientation) {
		_orientation = "" + orientation[0] + " " + orientation[1] + " " + orientation[2];
	}

	void SetInventory(ref array<ref BST_MCSaveObject> arrInventory) {
		_arrInventory = arrInventory;
	}

	void ClearInventory() {
		_arrInventory = new array<ref BST_MCSaveObject>();
	}

	ref array<ref BST_MCSaveObject> GetInventory() { return _arrInventory; }
	vector GetPos() { return _position.ToVector(); }
	vector GetDirection() { return _direction.ToVector(); }
	vector GetOrientation() { return _orientation.ToVector(); }
	bool IsDead() { return _isDead; }
	int GetCharacterId() { return _charId; }
	int GetCharacterClass() { return _charClass; }
	int GetDeathTimestamp() { return _deathTimestamp; }
	string GetName() { return _charName; }
	string GetType() { return _survivorType; }
	float GetHealth() { return _health; }
	float GetBlood() { return _blood; }
	float GetShock() { return _shock; }
	float GetWater() { return _water; }
	float GetEnergy() { return _energy; }
}