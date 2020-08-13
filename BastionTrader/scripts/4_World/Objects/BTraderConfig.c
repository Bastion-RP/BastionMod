class BTraderConfig
{
	private int 		TradeCooldown;
	private int			MinHealthLevel;

	int GetCD() { return TradeCooldown; }
	int GetMH() { return MinHealthLevel; }

	void Validate()
	{
		if (!TradeCooldown)
		{
			TradeCooldown = 2;
		}
		if (!MinHealthLevel)
		{
			MinHealthLevel = 1;
		}
	}
}