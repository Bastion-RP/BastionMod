class BST_MCConfig {
    int RespawnTimerInMinutes, SpawnTimer;

    void BST_MCConfig() {
        RespawnTimerInMinutes = 30;
        SpawnTimer = 5;
    }
    
    int GetRespawnTimer() { return RespawnTimerInMinutes; }
    int GetSpawnTimer() { return SpawnTimer; }
}