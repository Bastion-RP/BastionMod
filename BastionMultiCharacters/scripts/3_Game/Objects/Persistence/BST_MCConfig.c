class BST_MCConfig {
    int RespawnTimerInMinutes;

    void BST_MCConfig() {
        RespawnTimerInMinutes = 30;
    }
    
    int GetRespawnTimer() { return RespawnTimerInMinutes; }
}