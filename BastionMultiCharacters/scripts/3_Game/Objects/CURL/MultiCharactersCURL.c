class MultiCharactersCURL : RestCallback {
    static ref ScriptInvoker multiCharactersData = new ScriptInvoker();

    override void OnError(int errorCode) {
        Print(MCConst.debugPrefix + "Error Code:" + errorCode);
    }

    override void OnTimeout() {
        Print(MCConst.debugPrefix + "Request Timeout");
    }

    override void OnSuccess(string data, int dataSize) {
        if (dataSize > 0) {
            Print(data);
            multiCharactersData.Invoke(data);
        }
    }
}

class MultiCharactersCURLEndpoints {
    const static string ENDPOINT_BY_CHARACTER_ID = "characters.php?character_id=";
    const static string ENDPOINT_BY_STEAM_ID = "characters.php?steam_id=";
    const static string ENDPOINT_BY_MEMBER_ID = "characters.php?player_id=";
}