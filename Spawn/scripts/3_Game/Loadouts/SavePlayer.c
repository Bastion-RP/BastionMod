class SavePlayer {
	int m_Index;
	bool m_Dead;
	string m_Type;
	float m_Health;
	float m_Blood;
	float m_Shock;
	float m_Water;
	float m_Energy;
	vector m_Pos;
	ref array<ref SaveObject> m_Inventory;

	ref array<ref SaveObject> GetInventory() {
		return m_Inventory;
	}

	vector GetPos() {
		return m_Pos;
	}

	int GetIndex() {
		return m_Index;
	}
	
	bool IsDead() {
		return m_Dead;
	}

	string GetType() {
		return m_Type;
	}

	float GetHealth() {
		return m_Health;
	}

	float GetBlood() {
		return m_Blood;
	}

	float GetShock() {
		return m_Shock;
	}

	float GetWater() {
		return m_Water;
	}

	float GetEnergy() {
		return m_Energy;
	}

	void SetIndex(int index) {
		m_Index = index;
	}

	void SetDead(bool dead) {
		m_Dead = dead;
	}

	void SetType(string type) {
		m_Type = type;
	}

	void SetHealth(float health) {
		m_Health = health;
	}

	void SetBlood(float blood) {
		m_Blood = blood;
	}

	void SetShock(float shock) {
		m_Shock = shock;
	}

	void SetWater(float water) {
		m_Water = water;
	}

	void SetEnergy(float energy) {
		m_Energy = energy;
	}

	void SetPos(vector pos) {
		m_Pos = pos;
	}

	void SetInventory(ref array<ref SaveObject> inventory) {
		m_Inventory = inventory;
	}

	void ClearInventory() {
		m_Inventory = new array<ref SaveObject>();
	}
}