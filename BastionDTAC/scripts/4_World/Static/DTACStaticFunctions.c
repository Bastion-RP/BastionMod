static void SendCURLRequest(string playerId) {
    RestApi curlCore = CreateRestApi();
    DTACCurl dtacCurl = new DTACCurl();
    RestContext ctx = curlCore.GetRestContext("https://bastionrp.com/api/");

    ctx.GET(dtacCurl, "characters.php?character_id=" + playerId);
}