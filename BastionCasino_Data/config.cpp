class CfgPatches
{
	class BastionCasino_Data
	{
		units[]={"BRP_CasinoChips"};
        weapons[]={};
        requiredVersion=1.0;
        requiredAddons[]={
            "DZ_Data"
        };
	};
};


class CfgMods
{
	class BastionCasino_Data
	{
		dir = "BastionCasino_Data";
		name = "BastionCasino_Data";
		credits = "TheBuster";
		author = "TheBuster";
		authorID = "0";
		version = "0.1";
		extra = 0;
		type = "mod";
		
		dependencies[] = {};

		class defs
		{
		};
	};
};

class cfgSoundSets
{
	class BastionCasino_FLIPCARD_SoundSet
	{
		soundShaders[]=
		{
			"BastionCasino_FLIPCARD_SoundShader"
		};
		sound3DProcessingType="character3DProcessingType";
		volumeCurve="characterAttenuationCurve";
		spatial=1;
		doppler=0;
		loop=0;
	};
	class BastionCasino_CLACK_SoundSet
	{
		soundShaders[]=
		{
			"BastionCasino_CLACK_SoundShader"
		};
		sound3DProcessingType="character3DProcessingType";
		volumeCurve="characterAttenuationCurve";
		spatial=1;
		doppler=0;
		loop=0;
	};
	class BastionCasino_WIN_SoundSet
	{
		soundShaders[]=
		{
			"BastionCasino_WIN_SoundShader"
		};
		sound3DProcessingType="character3DProcessingType";
		volumeCurve="characterAttenuationCurve";
		spatial=1;
		doppler=0;
		loop=0;
	};
	class BastionCasino_LOSE_SoundSet
	{
		soundShaders[]=
		{
			"BastionCasino_LOSE_SoundShader"
		};
		sound3DProcessingType="character3DProcessingType";
		volumeCurve="characterAttenuationCurve";
		spatial=1;
		doppler=0;
		loop=0;
	};
	class BastionCasino_JACKPOT_SoundSet
	{
		soundShaders[]=
		{
			"BastionCasino_JACKPOT_SoundShader"
		};
		sound3DProcessingType="character3DProcessingType";
		volumeCurve="characterAttenuationCurve";
		spatial=1;
		doppler=0;
		loop=0;
	};
	class BastionCasino_FLAP_SoundSet
	{
		soundShaders[]=
		{
			"BastionCasino_FLAP_SoundShader"
		};
		sound3DProcessingType="character3DProcessingType";
		volumeCurve="characterAttenuationCurve";
		spatial=1;
		doppler=0;
		loop=0;
	};
	class BastionCasino_RACE_BACKGROUND_SoundSet
	{
		soundShaders[]=
		{
			"BastionCasino_RACE_BACKGROUND_SoundShader"
		};
		sound3DProcessingType="character3DProcessingType";
		volumeCurve="characterAttenuationCurve";
		spatial=1;
		doppler=0;
		loop=0;
	};
	class BastionCasino_COUNTDOWN_1_SoundSet
	{
		soundShaders[]=
		{
			"BastionCasino_COUNTDOWN_1_SoundShader"
		};
		sound3DProcessingType="character3DProcessingType";
		volumeCurve="characterAttenuationCurve";
		spatial=1;
		doppler=0;
		loop=0;
	};
	class BastionCasino_COUNTDOWN_2_SoundSet
	{
		soundShaders[]=
		{
			"BastionCasino_COUNTDOWN_2_SoundShader"
		};
		sound3DProcessingType="character3DProcessingType";
		volumeCurve="characterAttenuationCurve";
		spatial=1;
		doppler=0;
		loop=0;
	};
	class BastionCasino_COUNTDOWN_3_SoundSet
	{
		soundShaders[]=
		{
			"BastionCasino_COUNTDOWN_3_SoundShader"
		};
		sound3DProcessingType="character3DProcessingType";
		volumeCurve="characterAttenuationCurve";
		spatial=1;
		doppler=0;
		loop=0;
	};
	class BastionCasino_SHOOT_SoundSet
	{
		soundShaders[]=
		{
			"BastionCasino_SHOOT_SoundShader"
		};
		sound3DProcessingType="character3DProcessingType";
		volumeCurve="characterAttenuationCurve";
		spatial=1;
		doppler=0;
		loop=0;
	};
};
class cfgSoundShaders
{
	class BastionCasino_CLACK_SoundShader
	{
		samples[]=
		{
			{
				"BastionMod\BastionCasino_Data\data\sounds\clack",
				1
			}
		};
		volume=1;
		range=10;
		limitation=0;
	};
	class BastionCasino_FLIPCARD_SoundShader
	{
		samples[]=
		{
			{
				"BastionMod\BastionCasino_Data\data\sounds\flipcard",
				1
			}
		};
		volume=1;
		range=10;
		limitation=0;
	};
	class BastionCasino_WIN_SoundShader
	{
		samples[]=
		{
			{
				"BastionMod\BastionCasino_Data\data\sounds\win",
				1
			}
		};
		volume=1;
		range=10;
		limitation=0;
	};
	class BastionCasino_LOSE_SoundShader
	{
		samples[]=
		{

			{
				"BastionMod\BastionCasino_Data\data\sounds\lose",
				1
			}
		};
		volume=1;
		range=10;
		limitation=0;
	};
	class BastionCasino_FLAP_SoundShader
	{
		samples[]=
		{

			{
				"BastionMod\BastionCasino_Data\data\sounds\flap",
				1
			}
		};
		volume=1;
		range=10;
		limitation=0;
	};
	class BastionCasino_JACKPOT_SoundShader
	{
		samples[]=
		{

			{
				"BastionMod\BastionCasino_Data\data\sounds\jackpot",
				1
			}
		};
		volume=1;
		range=10;
		limitation=0;
	};
	class BastionCasino_RACE_BACKGROUND_SoundShader
	{
		samples[]=
		{

			{
				"BastionMod\BastionCasino_Data\data\sounds\race_background",
				1
			}
		};
		volume=1;
		range=10;
		limitation=0;
	};
	class BastionCasino_COUNTDOWN_1_SoundShader
	{
		samples[]=
		{

			{
				"BastionMod\BastionCasino_Data\data\sounds\one",
				1
			}
		};
		volume=1;
		range=10;
		limitation=0;
	};
	class BastionCasino_COUNTDOWN_2_SoundShader
	{
		samples[]=
		{

			{
				"BastionMod\BastionCasino_Data\data\sounds\tow",
				1
			}
		};
		volume=1;
		range=10;
		limitation=0;
	};
	class BastionCasino_COUNTDOWN_3_SoundShader
	{
		samples[]=
		{

			{
				"BastionMod\BastionCasino_Data\data\sounds\three",
				1
			}
		};
		volume=1;
		range=10;
		limitation=0;
	};
	class BastionCasino_SHOOT_SoundShader
	{
		samples[]=
		{

			{
				"BastionMod\BastionCasino_Data\data\sounds\pistol-shot",
				1
			}
		};
		volume=1;
		range=10;
		limitation=0;
	};
};

class CfgVehicles
{
	class Inventory_Base;
	class BRP_CasinoChips: Inventory_Base
	{
		scope=2;
		displayName="Casino Chip";
		descriptionShort="With this chip you can play at casino games";
		model="BastionMod\BastionCasino_Data\data\CasinoChips.p3d";
		canBeSplit=1;
		rotationFlags=16;
		lootCategory="Materials";
		lootTag[]=
		{
			"Civilian",
			"Work"
		};
		itemSize[]={1};
		weight=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=10000;
		varQuantityDestroyOnMin=1;
		destroyOnEmpty=1;
		absorbency=1;
	};
};