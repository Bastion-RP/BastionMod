class GpsConfig
{
	private bool DebugEnable;
	private float offsetX;
	private float offsetY;

	void Default()
	{
		DebugEnable = false;
		offsetX = 642;
		offsetY = -421;
	}

	bool IsDebug() { return DebugEnable; }
	float GetOffsetX() { return offsetX; }
	float GetOffsetY() { return offsetY; }
}