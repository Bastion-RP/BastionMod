class SaveObject {
	private string objectType;
	private float healthLevel;
	private int quantity;
	private int invSlot;
	private int invIdx;
	private int invRow;
	private int invCol;
	private bool invFlip;
	private bool isInHands;
	private ref array<ref SaveObject> arrayChildren;

	void SaveObject() {
		arrayChildren = new array<ref SaveObject>();
	}

	ref array<ref SaveObject> GetChildren() {
		return arrayChildren;
	}

	string GetType() {
		return objectType;
	}

	float GetHealth() {
		return healthLevel;
	}

	int GetQuantity() {
		return quantity;
	}

	int GetSlot() {
		return invSlot;
	}

	int GetIndex() {
		return invIdx;
	}

	int GetRow() {
		return invRow;
	}

	int GetCol() {
		return invCol;
	}

	int GetFlip() {
		return invFlip;
	}

	bool IsInHands() {
		return isInHands;
	}

	void SetType(string objectType) {
		this.objectType = objectType;
	}

	void SetHealth(float healthLevel) {
		this.healthLevel = healthLevel;
	}

	void SetQuantity(int quantity) {
		this.quantity = quantity;
	}

	void SetSlot(int invSlot) {
		this.invSlot = invSlot;
	}

	void SetIdx(int invIdx) {
		this.invIdx = invIdx;
	}

	void SetRow(int invRow) {
		this.invRow = invRow;
	}

	void SetCol(int invCol) {
		this.invCol = invCol;
	}

	void SetFlip(bool invFlip) {
		this.invFlip = invFlip;
	}

	void SetHands() {
		this.isInHands = true;
	}

	void SetChildren(ref array<ref SaveObject> arrayChildren) {
		this.arrayChildren = arrayChildren;
	}
}