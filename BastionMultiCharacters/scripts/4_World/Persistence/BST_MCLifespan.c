class BST_MCLifespan {
	private int _state, _lastShaved, _bloodType;
	private bool _bloodyHandsVisible, _bloodTypeVisible;

    void BST_MCLifespan(int state, int shaved, int bType, bool bHandsVisible, bool bTypeVisible) {
        _state = state;
        _lastShaved = shaved;
        _bloodType = bType;
        _bloodyHandsVisible = bHandsVisible;
        _bloodTypeVisible = bTypeVisible;
    }
    
    int GetState() { return _state; }
    int GetLastShaved() { return _lastShaved; }
    int GetBloodType() { return _bloodType; }
    bool IsBloodyHandsVisible() { return _bloodyHandsVisible; }
    bool IsBloodTypeVisible() { return _bloodTypeVisible; }
}