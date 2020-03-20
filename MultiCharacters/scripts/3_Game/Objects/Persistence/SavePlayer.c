class SavePlayer {
	private int characterId;
	private bool isDead;
	private string survivorName;
	private string survivorType;
	private float healthLevel;
	private float bloodLevel;
	private float shockLevel;
	private float waterLevel;
	private float energyLevel;
	private vector position;
	private ref array<ref SaveObject> arrayInventory;

	void SavePlayer() {
		arrayInventory = new array<ref SaveObject>();
	}

	ref array<ref SaveObject> GetInventory() {
		return arrayInventory;
	}

	vector GetPos() {
		return position;
	}

	bool IsDead() {
		return isDead;
	}

	int GetCharacterId() {
		return characterId;
	}

	string GetName() {
		return survivorName;
	}

	string GetType() {
		return survivorType;
	}

	float GetHealth() {
		return healthLevel;
	}

	float GetBlood() {
		return bloodLevel;
	}

	float GetShock() {
		return shockLevel;
	}

	float GetWater() {
		return waterLevel;
	}

	float GetEnergy() {
		return energyLevel;
	}

	void SetCharacterName(string survivorName) {
		this.survivorName = survivorName;
	}

	void SetCharacterId(int characterId) {
		this.characterId = characterId;
	}

	void SetDead(bool isDead) {
		this.isDead = isDead;
	}

	void SetName(string survivorName) {
		this.survivorName = survivorName;
	}

	void SetType(string survivorType) {
		this.survivorType = survivorType;
	}

	void SetHealth(float healthLevel) {
		this.healthLevel = healthLevel;
	}

	void SetBlood(float bloodLevel) {
		this.bloodLevel = bloodLevel;
	}

	void SetShock(float shockLevel) {
		this.shockLevel = shockLevel;
	}

	void SetWater(float waterLevel) {
		this.waterLevel = waterLevel;
	}

	void SetEnergy(float energyLevel) {
		this.energyLevel = energyLevel;
	}

	void SetPos(vector position) {
		this.position = position;
	}

	void SetInventory(ref array<ref SaveObject> arrayInventory) {
		this.arrayInventory = arrayInventory;
	}

	void ClearInventory() {
		this.arrayInventory = new array<ref SaveObject>();
	}
}