class BRP_CasinoBaseConfig
{
    protected void Load(string filename)
    {
        if (IsServerAndMultiplayerCasino() && FileExist(CASINO_CONFIGSFOLDER + filename)) {
			DebugMessageCasino("load file");
			DoLoad();
        }
    }

    protected void Save(string filename)
    {
        if (IsServerAndMultiplayerCasino()) {
			if (!FileExist(CASINO_CONFIGSFOLDER)) {
                MakeDirectory(CASINO_CONFIGSFOLDER);
                DebugMessageCasino("create folder");
            }
			DebugMessageCasino("save file");
			DoSave();
		}
    }

	
	protected void DoLoad() {}
	protected void DoSave() {}
};