class BST_DTACGroupConfig {
    private static const float DEFAULT_UPDATE_SENS = 1.0;
    private static const int DEFAULT_UPDATE_INTERVAL = 1;
    private static const int DEFAULT_UPDATE_DIST_SENS = 25;

    private ref array<ref BST_DTACGroupConfigObject> arrayConfigGroups;
    private float StatUpdateSensitivityPercentage;
    private int StatUpdateIntervalSeconds, DistanceUpdateSensitivityMeters;

    void BST_DTACGroupConfig() {
        arrayConfigGroups = new array<ref BST_DTACGroupConfigObject>();
        StatUpdateIntervalSeconds = DEFAULT_UPDATE_INTERVAL;
        StatUpdateSensitivityPercentage = DEFAULT_UPDATE_SENS;
        DistanceUpdateSensitivityMeters = DEFAULT_UPDATE_DIST_SENS;
    }

    void Validate() {
        if (arrayConfigGroups.Count() == 0) {
            for (int i = 0; i < 4; i++) {
                BST_DTACGroupConfigObject newObject = new BST_DTACGroupConfigObject();

                newObject.Validate();
                arrayConfigGroups.Insert(newObject);
            }
        } else {
            foreach (BST_DTACGroupConfigObject configObject : arrayConfigGroups) {
                if (configObject) {
                    configObject.Validate();
                }
            }
        }
        if (StatUpdateIntervalSeconds <= 0) {
            StatUpdateIntervalSeconds = DEFAULT_UPDATE_SENS;
        }
        if (StatUpdateSensitivityPercentage <= 0.0) {
            StatUpdateSensitivityPercentage = DEFAULT_UPDATE_SENS;
        }
        if (DistanceUpdateSensitivityMeters <= 0) {
            DistanceUpdateSensitivityMeters = DEFAULT_UPDATE_DIST_SENS;
        }
        Save();
    }

    void Save() {
        JsonFileLoader<BST_DTACGroupConfig>.JsonSaveFile(BST_DTACConst.configDir, this);
    }

    array<ref BST_DTACGroupConfigObject> GetGroups() { return arrayConfigGroups; }
    float GetUpdateSensitivity() { return StatUpdateSensitivityPercentage; }
    int GetUpdateInterval() { return StatUpdateIntervalSeconds; }
    int GetDistanceSensitivity() { return DistanceUpdateSensitivityMeters; }
}