class ToxGeneralSetting
{
	private float PlayerDamageHealth;
	private float PlayerDamageBlood;
	private float MaskDamage;

	void ToxGeneralSetting(float pdh = 0, float pdb = 0, float md = 0)
	{
		PlayerDamageHealth = pdh;
		PlayerDamageBlood = pdb;
		MaskDamage = md;
	}

	float GetPHealthDmg() { return PlayerDamageHealth; }
	float GetPBloodDmg() { return PlayerDamageBlood; }
	float GetMaskDamage() { return MaskDamage; }
}