class BST_DTACConfigServer : BST_DTACConfig {
    // Keep this shit server-side only. The base config will be passed to the client.
    private string APIPOSTGeneralPassword;
    private string APIPOSTCriminalPassword;

    void BST_DTACConfigServer() {
        APIPOSTGeneralPassword = "";
        APIPOSTCriminalPassword = "";
        
        Print("[DTAC][WARNING] Config was just generated!!! API Passwords are left blank!!! Endpoints requiring a password WILL NOT work!!! [WARNING]");
    }

    override void Validate() {
        if (APIPOSTGeneralPassword == "") {
            Print("[DTAC][WARNING] API Password for POST General Records was left blank!!! This endpoint will not work! [WARNING]");
        }
        if (APIPOSTCriminalPassword == "") {
            Print("[DTAC][WARNING] API Password for POST Criminal Records was left blank!!! This endpoint will not work! [WARNING]");
        }
    }

    string GetGeneralPassword() { return APIPOSTGeneralPassword; }
    string GetCriminalPassword() { return APIPOSTCriminalPassword; }
}