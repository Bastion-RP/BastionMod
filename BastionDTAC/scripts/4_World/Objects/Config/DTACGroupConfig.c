class DTACGroupConfig {
    private static const float DEFAULT_UPDATE_SENS = 1.0;
    private static const int DEFAULT_UPDATE_INTERVAL = 1;
    private static const int DEFAULT_UPDATE_DIST_SENS = 25;

    private ref array<ref DTACGroupConfigObject> arrayConfigGroups;
    private float StatUpdateSensitivityPercentage;
    private int StatUpdateIntervalSeconds, DistanceUpdateSensitivityMeters;

    void DTACGroupConfig() {
        arrayConfigGroups = new array<ref DTACGroupConfigObject>();
        StatUpdateIntervalSeconds = DEFAULT_UPDATE_INTERVAL;
        StatUpdateSensitivityPercentage = DEFAULT_UPDATE_SENS;
        DistanceUpdateSensitivityMeters = DEFAULT_UPDATE_DIST_SENS;
    }

    void Validate() {
        if (arrayConfigGroups.Count() == 0) {
            for (int i = 0; i < 4; i++) {
                DTACGroupConfigObject newObject = new DTACGroupConfigObject();

                newObject.Validate();
                arrayConfigGroups.Insert(newObject);
            }
        } else {
            foreach (DTACGroupConfigObject configObject : arrayConfigGroups) {
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
        JsonFileLoader<DTACGroupConfig>.JsonSaveFile(DTACConst.configDir, this);
    }

    array<ref DTACGroupConfigObject> GetGroups() { return arrayConfigGroups; }
    float GetUpdateSensitivity() { return StatUpdateSensitivityPercentage; }
    int GetUpdateInterval() { return StatUpdateIntervalSeconds; }
    int GetDistanceSensitivity() { return DistanceUpdateSensitivityMeters; }
}