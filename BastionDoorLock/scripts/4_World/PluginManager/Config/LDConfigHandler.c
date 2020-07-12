class LockedDoorsConfigHandler : PluginBase
{
	ref LockDoorConfig ldConfig;

	void LockedDoorsConfigHandler() 
	{
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) 
		{ return; }

		CheckDirectories();

		if (FileExist(LockDoorConst.settingModDir))
		{
			JsonFileLoader<LockDoorConfig>.JsonLoadFile(LockDoorConst.settingModDir, ldConfig);
            ldConfig.Validate();
            JsonFileLoader<LockDoorConfig>.JsonSaveFile(LockDoorConst.settingModDir, ldConfig);
		}
		else
		{
			ldConfig = new LockDoorConfig();
			ldConfig.Validate();
			JsonFileLoader<LockDoorConfig>.JsonSaveFile(LockDoorConst.settingModDir, ldConfig);
		}
	}

	void CheckDirectories()
	{
		if (!FileExist(LockDoorConst.profileModDir))
		{
            MakeDirectory(LockDoorConst.profileModDir);
        }
	}

	ref LockDoorConfig GetConfig()
	{
		return ldConfig;
	}

	void SetConfig(LockDoorConfig config)
	{
		ldConfig = config;
	}
}

LockedDoorsConfigHandler GetLockedDoorsConfigHandler()
{
	return LockedDoorsConfigHandler.Cast(GetPlugin(LockedDoorsConfigHandler));
}