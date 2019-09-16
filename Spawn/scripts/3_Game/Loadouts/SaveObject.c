class SaveObject {
	string m_Type;
	float m_Health;
	int m_Quantity;
	int m_Slot;
	int m_Idx;
	int m_Row;
	int m_Col;
	bool m_Flip;
	bool m_InHands;
	bool m_IsAttachment;
	ref array<ref SaveObject> m_Children;

	void SaveObject() {
		m_Children = new array<ref SaveObject>();
	}

	string GetType() {
		return m_Type;
	}

	float GetHealth() {
		return m_Health;
	}

	int GetQuantity() {
		return m_Quantity;
	}

	bool IsAttachment() {
		return m_IsAttachment;
	}

	void SetType(string type) {
		m_Type = type;
	}

	void SetHealth(float health) {
		m_Health = health;
	}

	void SetQuantity(int quantity) {
		m_Quantity = quantity;
	}

	void SetSlot(int slot) {
		m_Slot = slot;
	}

	void SetIdx(int idx) {
		m_Idx = idx;
	}

	void SetRow(int row) {
		m_Row = row;
	}

	void SetCol(int col) {
		m_Col = col;
	}

	void SetFlip(bool flip) {
		m_Flip = flip;
	}

	void IsInHands() {
		m_InHands = true;
	}

	void SetAttachment(bool isAttachment) {
		m_IsAttachment = isAttachment;
	}

	void SetChildren(ref array<ref SaveObject> children) {
		m_Children = children;
	}
}