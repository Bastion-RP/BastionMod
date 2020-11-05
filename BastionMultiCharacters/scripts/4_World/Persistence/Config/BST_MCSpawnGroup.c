class BST_MCSpawnGroup {
    const static string CONST_DEFAULT_CLASS = "DEFAULT";

    private string SpawnClass;
    private ref array<string> SpawnPositions;

    void BST_MCSpawnGroup() {
        SpawnClass = CONST_DEFAULT_CLASS;
        SpawnPositions = BST_MCDefaultSpawns();
    }

    void Validate() {
        SpawnClass.ToUpper();

        for (int i = (SpawnPositions.Count() - 1); i >= 0; i--) {
            string str = SpawnPositions[i];

            if (str.Length() <= 0 || str.IndexOf(",") != -1) {
                SpawnPositions.Remove(i);

                if (str.IndexOf(",") != -1) {
                    str.Replace(",", " ");
                    SpawnPositions.Insert(str);
                }
            }
            if (SpawnPositions[i].ToVector() == "0 0 0") {
                SpawnPositions.Remove(i);
            }
        }
    }

    string GetClass() { return SpawnClass; }
    array<string> GetSpawnPoints() { return SpawnPositions; }
}