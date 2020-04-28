class StoredData
{
    protected string steamId;
    protected string location;
    protected int rations;
    protected string lastServer;

    void StoredData( string _steamId = "", string _location = vector.Zero.ToString(), int _rations = 0, string _lastServer = "" )
    {
        steamId = _steamId;
        location = _location;
        rations = _rations;
        lastServer = _lastServer;
    }

    string GetSteamId()     { return steamId; }
    string GetLocation()    { return location; }
    int    GetRations()     { return rations; }
    string GetLastServer()  { return lastServer; }
}