class BST_MCAPICallback : RestCallback {
    override void OnError(int errorCode) {
        Print("[API DEBUG] Error Code:" + errorCode);
    }

    override void OnTimeout() {
        Print("[API DEBUG] Request Timeout");
    }

    override void OnSuccess(string data, int dataSize) {
        if (dataSize > 0) {
        }
    }
}

class BST_MCAPIEndpoints {
    const static string CHARACTER_ID = "characters.php?character_id=";
    const static string STEAM_ID = "characters.php?steam_id=";
    const static string MEMBER_ID = "characters.php?player_id=";
}