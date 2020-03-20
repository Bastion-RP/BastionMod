class MultiCharactersCURL : CURLCallback {
    static ref ScriptInvoker multiCharactersData = new ScriptInvoker();

    override void OnError(int errorCode) {
        Print("Error Code:" + errorCode);
    }

    override void OnTimeout() {
        Print("Request Timeout");
    }

    override void OnSuccess(string data, int dataSize) {
        if (dataSize > 0) {
            Print(data);
            multiCharactersData.Invoke(data);
        }
    }
}

static void SendMultiCharactersCURLRequest(string endpoint) {
    CURLCore curlCore = CreateCURLCore();
    MultiCharactersCURL mcCurl = new MultiCharactersCURL();
    CURLContext ctx = curlCore.GetCURLContext("https://bastionrp.com/api/");

    ctx.GET(mcCurl, endpoint);
}

static void SendMultiCharactersCURLRequest(string endpoint, string id) {
    CURLCore curlCore = CreateCURLCore();
    MultiCharactersCURL mcCurl = new MultiCharactersCURL();
    CURLContext ctx = curlCore.GetCURLContext("https://bastionrp.com/api/");

    ctx.GET(mcCurl, endpoint + id);
}


class MultiCharactersCURLEndpoints {
    const static string ENDPOINT_BY_CHARACTER_ID = "characters.php?character_id=";
    const static string ENDPOINT_BY_STEAM_ID = "characters.php?steam_id=";
    const static string ENDPOINT_BY_MEMBER_ID = "characters.php?player_id=";
}