class ToxGeneralSetting
{
	private float PlayerDamageHealth;
	private float PlayerDamageBlood;
	private float MaskDamage;
	private bool IsDebug; 

	void ToxGeneralSetting(float pdh = 0, float pdb = 0, float md = 0, bool dbg = false)
	{
		PlayerDamageHealth = pdh;
		PlayerDamageBlood = pdb;
		MaskDamage = md;
		IsDebug = dbg;
	}

	float GetPHealthDmg() { return PlayerDamageHealth; }
	float GetPBloodDmg() { return PlayerDamageBlood; }
	float GetMaskDamage() { return MaskDamage; }
	bool IsDebug() { return IsDebug; }
}