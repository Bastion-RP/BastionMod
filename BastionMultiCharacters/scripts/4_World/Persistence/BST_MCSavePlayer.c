/*
	Class written by RoomService
*/

class BST_MCSavePlayer : BST_MCSavePlayerBasic {
	private ref BST_MCLifespan _lifespan;
	private ref array<float> _arrStats;
    private ref array<ref BST_MCSaveModifier> _arrModifiers;
	private ref array<ref BST_MCSaveAgent> _arrAgents;
	private ref array<int> _arrSymptoms;
	private ref BST_MCSaveBleeding _bleeding;
	private float _health, _blood, _shock;
	private string _position, _direction, _orientation;

	void BST_MCSavePlayer() {
		_arrStats = new array<float>();
		_arrModifiers = new array<ref BST_MCSaveModifier>();
		_arrAgents = new array<ref BST_MCSaveAgent>();
		_arrSymptoms = new array<int>();
	}

	void WriteLife(float health, float blood, float shock) {
		_health = health;
		_blood = blood;
		_shock = shock;
	}

	void WriteLifespan(int state, int lastShaved, int bloodType, bool bloodyHandsVisible, bool bloodTypeVisible) {
		_lifespan = new BST_MCLifespan(state, lastShaved, bloodType, bloodyHandsVisible, bloodTypeVisible);
	}

	void WriteStats(array<ref PlayerStatBase> playerStats) {
		foreach (PlayerStatBase statBase : playerStats) {
			_arrStats.Insert(statBase.Get());
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

	void SetLocation(vector position, vector direction, vector orientation) {
		_position = "" + position[0] + " " + position[1] + " " + position[2];
		_direction = "" + direction[0] + " " + direction[1] + " " + direction[2];
		_orientation = "" + orientation[0] + " " + orientation[1] + " " + orientation[2];
	}

	BST_MCLifespan GetLifespan() { return _lifespan; }
	array<float> GetStats() { return _arrStats; }
	array<ref BST_MCSaveModifier> GetModifiers() { return _arrModifiers; }
	array<ref BST_MCSaveAgent> GetAgents() { return _arrAgents; }
	array<int> GetSymptoms() { return _arrSymptoms; }
	BST_MCSaveBleeding GetBleeding() { return _bleeding; }
	vector GetPos() { return _position.ToVector(); }
	vector GetDirection() { return _direction.ToVector(); }
	vector GetOrientation() { return _orientation.ToVector(); }
	float GetHealth() { return _health;	}
	float GetBlood() { return _blood; }
	float GetShock() { return _shock; }
}