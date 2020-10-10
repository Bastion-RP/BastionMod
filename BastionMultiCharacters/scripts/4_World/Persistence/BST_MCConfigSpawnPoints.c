class BST_MCConfigSpawnPoints {
    private ref array<ref BST_MCSpawnPoints> _arrSpawnPoints;

    void BST_MCConfigSpawnPoints() {
        BST_MCSpawnPoints exSpawnPoints = new BST_MCSpawnPoints();
        _arrSpawnPoints = new array<ref BST_MCSpawnPoints>();

        _arrSpawnPoints.Insert(exSpawnPoints);
    }

    vector GetRandomSpawnPointbyClass(int charClass) {
        string charString = typename.EnumToString(BastionClasses, charClass);

        if (charString.IndexOf("_") != -1) {
            charString.Replace("_", "-");
        }
        foreach (BST_MCSpawnPoints spawnPoint : _arrSpawnPoints) {
            if (!spawnPoint) { continue; }
            if (spawnPoint.HasClass(charString)) {
                return spawnPoint.GetRandomSpawnPoint();
            }
        }
        return vector.Zero;
    }
}