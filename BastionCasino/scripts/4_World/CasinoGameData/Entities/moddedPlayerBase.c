modded class PlayerBase extends ManBase
{
	CasinoConfig casinoConfig;
	bool actionOpenCasinoMenu;

	void SetActionOpenCasinoMenu(bool state)
	{
		actionOpenCasinoMenu = state;
	}

	bool GetActionOpenCasinoMenu()
	{
		return actionOpenCasinoMenu;
	}
}