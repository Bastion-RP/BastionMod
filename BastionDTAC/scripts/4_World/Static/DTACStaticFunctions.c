static void SendCURLRequest(string playerId) {
    CURLCore curlCore = CreateCURLCore();
    DTACCurl dtacCurl = new DTACCurl();
    CURLContext ctx = curlCore.GetCURLContext("https://bastionrp.com/api/");

    ctx.GET(dtacCurl, "characters.php?character_id=" + playerId);
}