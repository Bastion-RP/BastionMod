class BST_MCSaveObject {
	private ref array<ref BST_MCSaveObject> _arrChildren;
	private string _type;
	private float _health = 100;
	private int _quant, _slot, _idx, _row, _col;
	private bool _flip, _inHands;

	void BST_MCSaveObject() {
		_arrChildren = new array<ref BST_MCSaveObject>();
	}
	void SetType(string type) {
		_type = type;
	}

	void SetHealth(float health) {
		_health = health;
	}

	void SetQuantity(int quant) {
		_quant = quant;
	}

	void SetSlot(int slot) {
		_slot = slot;
	}

	void SetIdx(int idx) {
		_idx = idx;
	}

	void SetRow(int row) {
		_row = row;
	}

	void SetCol(int col) {
		_col = col;
	}

	void SetFlip(bool flip) {
		_flip = flip;
	}

	void SetHands() {
		_inHands = true;
	}

	void SetChildren(ref array<ref BST_MCSaveObject> arrChildren) {
		_arrChildren = arrChildren;
	}

	void AddChild(ref BST_MCSaveObject child) {
		_arrChildren.Insert(child);
	}

	void ClearChildren() {
		delete _arrChildren;
		_arrChildren = new array<ref BST_MCSaveObject>();
	}

	ref array<ref BST_MCSaveObject> GetChildren() { return _arrChildren; }
	string GetType() { return _type; }
	float GetHealth() { return _health; }
	int GetQuantity() { return _quant; }
	int GetSlot() { return _slot; }
	int GetIndex() { return _idx; }
	int GetRow() { return _row; }
	int GetCol() { return _col; }
	bool GetFlip() { return _flip; }
	bool IsInHands() { return _inHands; }

}