class RadiationSetting
{
	private bool DebugEnable;

	void RadiationSetting(bool de = false)
	{
		DebugEnable = de;
	}

	bool IsDebugEnabled() { return DebugEnable; }
}