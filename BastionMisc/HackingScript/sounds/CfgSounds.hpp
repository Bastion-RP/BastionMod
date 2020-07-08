class CfgSoundShaders
{
	class BRPHouseSiren_SoundShader
	{
		samples[]=
		{
			{
				"BastionMod\BastionMisc\HackingScript\sounds\Siren",
				1
			}
		};
		range=300;
		volume=50.1999998;
	};

};
class CfgSoundSets
{
	class BRPHouseSiren_SoundSet
	{
		soundShaders[]=
		{
			"BRPHouseSiren_SoundShader"
		};
	};
};