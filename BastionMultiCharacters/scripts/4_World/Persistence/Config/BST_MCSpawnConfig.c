class BST_MCSpawnConfig {
    private ref array<ref BST_MCSpawnGroup> _arrSpawnGroups;

    void BST_MCSpawnConfig() {
        BST_MCSpawnGroup newGroup = new BST_MCSpawnGroup();
        _arrSpawnGroups = new array<ref BST_MCSpawnGroup>();

        _arrSpawnGroups.Insert(newGroup);
    }

    void Validate() {
        bool hasDefault = false;

        foreach (BST_MCSpawnGroup spawnGroup : _arrSpawnGroups) {
            if (!spawnGroup) { continue; }
            string groupName = spawnGroup.GetClass();

            groupName.ToUpper();

            if (groupName == BST_MCSpawnGroup.CONST_DEFAULT_CLASS) {
                hasDefault = true;
            }
            spawnGroup.Validate();
        }
        if (!hasDefault) {
            _arrSpawnGroups.Insert(new BST_MCSpawnGroup());
        }
    }

    map<string, ref array<string>> GetSpawnGroupMap() {
        map<string, ref array<string>> mapSpawnGroups = new map<string, ref array<string>>();

        foreach (BST_MCSpawnGroup spawnGroup : _arrSpawnGroups) {
            if (!BST_MCSpawnGroup) { continue; }
            mapSpawnGroups.Insert(spawnGroup.GetClass(), spawnGroup.GetSpawnPoints());
        }
        return mapSpawnGroups;
    }

    array<ref BST_MCSpawnGroup> GetSpawnGroups() { return _arrSpawnGroups; }
}