modded class MissionServer {
    // Do I want to store the key on the server? It's probably fine?
    // Can a mod override missionserver and call to bstAPIKey? probably....
    // Ez fix, make this shit server-side only and don't publish it to the workshop.
    // Set inside of DayZGame() instead of mission...
    private const string bstAPIDir = "$profile:\\Bastion\\curlKey.bastion";
    private string bstAPISrc;
    private string bstAPIKey;

    void MissionServer() {
        if (!FileExist(bstAPIDir)) {
            Print(BSTWConst.debugPrefix + "File containing API information not found! Whitelist will not work properly!!");
            Print(BSTWConst.debugPrefix + "File containing API information not found! Whitelist will not work properly!!");
            Print(BSTWConst.debugPrefix + "File containing API information not found! Whitelist will not work properly!!");
            Print(BSTWConst.debugPrefix + "File containing API information not found! Whitelist will not work properly!!");
            Print(BSTWConst.debugPrefix + "File containing API information not found! Whitelist will not work properly!!");
            Print(BSTWConst.debugPrefix + "File containing API information not found! Whitelist will not work properly!!");
            Print(BSTWConst.debugPrefix + "File containing API information not found! Whitelist will not work properly!!");
            Print(BSTWConst.debugPrefix + "File containing API information not found! Whitelist will not work properly!!");
        } else {
            LoadKey();
            GetDayZGame().InitializeCURL();
        }
    }

    private void LoadKey() {
		FileHandle file_handle = OpenFile(bstAPIDir, FileMode.READ);
		string line_content;

		FGets(file_handle, line_content);
        bstAPISrc = line_content;
        GetDayZGame().SetAPISrc(line_content);

		FGets(file_handle, line_content);
        GetDayZGame().SetAPIKey(line_content);

        CloseFile(file_handle);
    }
}