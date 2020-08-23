class BST_MCSavePlayer : BST_MCSavePlayerBasic {
    private ref array<ref BST_MCSaveModifier> _arrModifiers;
	private ref array<ref BST_MCSaveAgent> _arrAgents;
	private string _position, _direction, _orientation;

	// For saving lifespan
	private int _lifespanState, _lifespanLastShaved, _lifespanBloodType;
	private bool _lifespanHasBloodyHandsVisible, _lifespanHasBloodTypeVisible;

	void BST_MCSavePlayer() {
		_arrModifiers = new array<ref BST_MCSaveModifier>();
		_arrAgents = new array<ref BST_MCSaveAgent>();
	}

    void WriteModifiers(map<int, ref ModifierBase> mapModifiers) {
        for (int i = 0; i < mapModifiers.Count(); i++) {
            ModifierBase mdfr = mapModifiers.GetElement(i);

            if (mdfr.IsActive() && mdfr.IsPersistent()) {
                BST_MCSaveModifier saveModifier;
                
                if (mdfr.IsTrackAttachedTime()) {
                    saveModifier = new BST_MCSaveModifier(mdfr.GetModifierID(), mdfr.GetAttachedTime());
                } else {
                    saveModifier = new BST_MCSaveModifier(mdfr.GetModifierID(), -1);
                }
                _arrModifiers.Insert(saveModifier);
            }
        }
    }

	void WriteAgents(map<int, float> mapAgents) {
		for (int i = 0; i < mapAgents.Count(); i++) {
			_arrAgents.Insert(new BST_MCSaveAgent(mapAgents.GetKey(i), mapAgents.GetElement(i)));
		}
	}

	void SetLifespan(int state, int lastShaved, int bloodType, bool bloodyHandsVisible, bool bloodTypeVisible) {
		_lifespanState = state;
		_lifespanLastShaved = lastShaved;
		_lifespanBloodType = bloodType;
		_lifespanHasBloodyHandsVisible = bloodyHandsVisible;
		_lifespanHasBloodTypeVisible = bloodTypeVisible;
	}

	void SetLocation(vector position, vector direction, vector orientation) {
		_position = "" + position[0] + " " + position[1] + " " + position[2];
		_direction = "" + direction[0] + " " + direction[1] + " " + direction[2];
		_orientation = "" + orientation[0] + " " + orientation[1] + " " + orientation[2];
	}

	array<ref BST_MCSaveModifier> GetModifiers() { return _arrModifiers; }
	array<ref BST_MCSaveAgent> GetAgents() { return _arrAgents; }
	vector GetPos() { return _position.ToVector(); }
	vector GetDirection() { return _direction.ToVector(); }
	vector GetOrientation() { return _orientation.ToVector(); }
	int GetLifespanState() { return _lifespanState; }
	int GetLifespanLastShaved() { return _lifespanLastShaved; }
	int GetLifespanBloodType() { return _lifespanBloodType; }
	bool GetLifespanBloodyHandsVisible() { return _lifespanHasBloodyHandsVisible; }
	bool GetLifespanBloodTypeVisible() { return _lifespanHasBloodTypeVisible; }
}