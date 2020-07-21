// This is dumb. This needs to be expanded more or just changed completely.

static void SendCURLRequest(string playerId) {
    RestApi curlCore = CreateRestApi();
    BST_DTACRestCallback callback = new BST_DTACRestCallback();
    RestContext ctx = curlCore.GetRestContext("https://bastionrp.com/api/");

    ctx.GET(callback, "characters.php?character_id=" + playerId);
}