class BRP_BenelliM2 : AutoShotgunScript
{
	void BRP_BenelliM2 ()
	{
	}
	
	override RecoilBase SpawnRecoilObject()
	{
		return new Mp133Recoil(this); //Probably should replace this
	}
	override float GetChanceToJam()
	{
		float chanceToJam = super.GetChanceToJam();
			chanceToJam = chanceToJam + ((0 - chanceToJam) * 0); // 0.1
		
		return chanceToJam;
	}
}