static void DebugMessageCasino(string message) {
    if (DAYZ_CASINO_DEBUG) {
        Print("[BastionCasino] " + message);
        GetGame().AdminLog("[BastionCasino] " + message);
    }
}

static bool IsServerCasino()
{
    return GetGame().IsServer();
}
static bool IsMultiplayerCasino()
{
    return GetGame().IsMultiplayer();
}

static bool IsServerAndMultiplayerCasino()
{
    return IsMultiplayerCasino() && IsServerCasino();
}
static bool IsClientOrNotMultiplayerCasino()
{
    return !IsMultiplayerCasino() || GetGame().IsClient();
}

