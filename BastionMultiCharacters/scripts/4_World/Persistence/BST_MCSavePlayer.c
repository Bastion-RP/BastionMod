class BST_MCSavePlayer : BST_MCSavePlayerBasic {
    private ref array<ref BST_MCSaveModifier> _arrModifiers;
	private ref array<ref BST_MCSaveAgent> _arrAgents;
	private ref array<int> _arrSymptoms;
	private ref BST_MCSaveBleeding _bleeding;
	private string _position, _direction, _orientation;

	// For saving lifespan
	private int _lifespanState, _lifespanLastShaved, _lifespanBloodType;
	private bool _lifespanHasBloodyHandsVisible, _lifespanHasBloodTypeVisible;

	void BST_MCSavePlayer() {
		_arrModifiers = new array<ref BST_MCSaveModifier>();
		_arrAgents = new array<ref BST_MCSaveAgent>();
		_arrSymptoms = new array<int>();
	}

	void WriteBleeding(BleedingSourcesManagerServer bleedingManager, int bits) {
		int bitOffset;

		_bleeding = new BST_MCSaveBleeding(bits);
		bitOffset = 0;

		for (int i = 0; i < BIT_INT_SIZE; i++) {
			int bit = 1 << bitOffset;

			if ((bit & bits) != 0) {
				_bleeding.Insert(bleedingManager.GetBleedingSourceActiveTime(bit));
			}
			bitOffset++;
		}
	}

	void WriteSymptoms(array<ref SymptomBase> arrSymptomQueuePrimary, array<ref SymptomBase> arrSymptomQueueSecondary) {
		_arrSymptoms = new array<int>();

		Print("[DEBUG] WriteSymptoms | arrSymptomQueuePrimary=" + arrSymptomQueuePrimary.Count() + " | arrSymptomQueueSecondary=" + arrSymptomQueueSecondary.Count());

		foreach (SymptomBase symptomPrimary : arrSymptomQueuePrimary) {
			if (!symptomPrimary) { continue; }
			if (symptomPrimary.IsPersistent()) {
				_arrSymptoms.Insert(symptomPrimary.GetType());
			}
		}
		foreach (SymptomBase symptomSecondary : arrSymptomQueueSecondary) {
			if (!symptomSecondary) { continue; }
			if (symptomSecondary.IsPersistent()) {
				_arrSymptoms.Insert(symptomSecondary.GetType());
			}
		}
	}

    void WriteModifiers(map<int, ref ModifierBase> mapModifiers) {
		Print("[DEBUG] WriteModifiers | mapModifiers=" + mapModifiers.Count());

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
		Print("[DEBUG] WriteModifiers | WriteAgents=" + mapAgents.Count());

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
	array<int> GetSymptoms() { return _arrSymptoms; }
	BST_MCSaveBleeding GetBleeding() { return _bleeding; }
	vector GetPos() { return _position.ToVector(); }
	vector GetDirection() { return _direction.ToVector(); }
	vector GetOrientation() { return _orientation.ToVector(); }
	int GetLifespanState() { return _lifespanState; }
	int GetLifespanLastShaved() { return _lifespanLastShaved; }
	int GetLifespanBloodType() { return _lifespanBloodType; }
	bool GetLifespanBloodyHandsVisible() { return _lifespanHasBloodyHandsVisible; }
	bool GetLifespanBloodTypeVisible() { return _lifespanHasBloodTypeVisible; }
}