modded class MissionServer {
    /* void MissionServer() {
        BST_DTACGeneralRecordCallback._dtacGeneralRecordInvoker.Insert(TestAPI);
        Print("[DEBUG] Testing Rest API callback!");
        RestApi apiCore = GetRestApi();

        if (!apiCore) {
            apiCore = CreateRestApi();
        }
        BST_DTACGeneralRecordCallback fileCallback = new BST_DTACGeneralRecordCallback();
        RestContext ctx = apiCore.GetRestContext("https://bastionrp.com/api/");
        
        //ctx.FILE(fileCallback, "criminalrecords.php?criminalCharacterId=" + "50153", "test.json");
        ctx.FILE(fileCallback, "generalrecords.php?generalReportCharacterId=" + "50153", "test.json");
    }

    void TestAPI(string fileName) {
        if (fileName.Length() > 0) {
            Print("[DEBUG] Succeeded");
        } else {
            Print("[DEBUG] Failed");
        }
        Print("[DEBUG] Testing how this shit works file=" + fileName);
        array<ref BST_DTAC_CURL_GeneralRecord> arrCriminalRecords;
        string fileDir = "$profile:\\Users\\Survivor\\" + fileName;

        if (FileExist(fileDir)) {
            Print("[DEBUG] Found file!!!");
            JsonFileLoader<array<ref BST_DTAC_CURL_GeneralRecord>>.JsonLoadFile(fileDir, arrCriminalRecords);
            Print(arrCriminalRecords[0].NewToString());
            arrCriminalRecords.Debug();
            DeleteFile(fileDir);
        } else {
            Print("[DEBUG] Something fucked up");
        }
    } */

    /* void TestAPI(string fileName) {
        Print("[DEBUG] Testing how this shit works file=" + fileName);
        array<ref BST_DTACCriminalRecord> arrCriminalRecords;
        string fileDir = "$profile:\\Users\\Survivor\\" + fileName;

        if (FileExist(fileDir)) {
            Print("[DEBUG] Found file!!!");
            JsonFileLoader<array<ref BST_DTACCriminalRecord>>.JsonLoadFile(fileDir, arrCriminalRecords);
            Print(arrCriminalRecords[0].NewToString());
            arrCriminalRecords.Debug();
        } else {
            Print("[DEBUG] Something fucked up");
        }
    } */
    
    override void InvokeOnDisconnect(PlayerBase player) {
        if (player && player.GetIdentity()) {
            GetDTACServerGroupManager().RemoveUserFromGroup(player);
        }
        super.InvokeOnDisconnect(player);
    }
}