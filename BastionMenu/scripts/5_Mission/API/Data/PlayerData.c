class MenuPlayerData
{
    protected string member_id;
    protected string name;
    protected string ip;
    protected string steam;

    void MenuPlayerData( string _member_id = "", string _name = "", string _ip = "", string _steam = "" )
    {
        member_id = _member_id;
        name = _name;
        ip = _ip;
        steam = _steam;
    }

    string GetId() { return member_id; }
    string GetName() { return name; }
    string GetIP() { return ip; }
    string GetSteamId() { return steam; }
}