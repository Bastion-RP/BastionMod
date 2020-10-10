class BST_MCSpawnPoints {
    private ref array<string> ClassesForSpawnPoints;
    private ref array<string> SpawnPoints;

    void BST_MCSpawnPoints() {
        ClassesForSpawnPoints = new array<string>();
        SpawnPoints = new array<string>();

        ClassesForSpawnPoints.Insert("F");
        SpawnPoints = MultiCharactersDefaultSpawns();
    }

    bool HasClass(string charClass) {
        charClass.ToLower();

        foreach (string str : ClassesForSpawnPoints) {
            str.ToLower();

            if (str == charClass) {
                return true;
            }
        }
        return false;
    }

    vector GetRandomSpawnPoint() {
        return SpawnPoints.GetRandomElement().ToVector();
    }
}