class CfgPatches
{
	class BastionPA
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1;
		requiredAddons[] = {"DZ_Data"};
	};
};

class CfgSoundShaders
{
	class Bastion_basePAPole_SoundShader
	{
		range=300;
	};

	class Bastion_PA1_SoundShader: Bastion_basePAPole_SoundShader
	{
		samples[] = {{"\BastionMod\BastionPA_Data\PA\PA1",1}};
		volume = 1;
	};

	class Bastion_PA2_SoundShader: Bastion_basePAPole_SoundShader
	{
		samples[] = {{"\BastionMod\BastionPA_Data\PA\PA2",1}};
		volume = 1;
	};
};

class CfgSoundSets
{
	class Bastion_basePA_SoundSet
	{
		sound3DProcessingType="Vehicle_Ext_3DProcessingType";
		distanceFilter="softVehiclesDistanceFreqAttenuationFilter";
		volumeCurve="vehicleEngineAttenuationCurve";
		volumeFactor=1;
		spatial=1;
		loop=0;
	};

	class BastionPA1: Bastion_basePA_SoundSet
	{
		soundShaders[]=
		{
			"Bastion_PA1_SoundShader"
		};
		volumeFactor=1;
	};

	class BastionPA2: Bastion_basePA_SoundSet
	{
		soundShaders[]=
		{
			"Bastion_PA2_SoundShader"
		};
		volumeFactor=1;
	};	
};