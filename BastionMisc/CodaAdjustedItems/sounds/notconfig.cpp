//Changed volumes of Fires, Fire barrels, vanilla vehicles, suppressors
//Suppressors are quieter to infected
//Also changed durability of suppressors
class CfgPatches
{
	class coda_gear
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Gear_Optics",
			"DZ_Weapons_Melee",
			"DZ_Gear_Tools",
			"DZ_Gear_Crafting"
		};
	};
};

class CfgDistanceFilters
{
    class softVehiclesDistanceFreqAttenuationFilter
    {
        type="lowPassFilter";
        minCutoffFrequency=150;
        qFactor=1;
        innerRange=10;
        range=800;
        powerFactor=32;
    };
};

class CfgSound3DProcessors
{
    class Vehicle_Ext_3DProcessingType
    {
        type="emitter";
        innerRange=8;
        range=20;
        radius=2;
        rangeCurve="Smooth1Curve";
    };
};

class CfgSoundShaders
{
    class LightFire_SoundShader
    {
        volume=0.3;
        range=20;
    };
    class HeavyFire_SoundShader
    {
        volume=0.3;
        range=10;
    };

    class baseCharacter_SoundShader;
    class powerGeneratorTurnOn_Soundshader: baseCharacter_SoundShader
    {
        range=20;
        volume=0.3;
    };
    class powerGeneratorTurnOff_Soundshader: baseCharacter_SoundShader
    {
        range=20;
        volume=0.3;
    };
    class powerGeneratorLoop_Soundshader: baseCharacter_SoundShader
    {
        range=20;
        volume=0.3;
    };
};

class CfgSoundSets
{
    class baseEngine_EXT_SoundSet
    {
        sound3DProcessingType="Vehicle_Ext_3DProcessingType";
        distanceFilter="softVehiclesDistanceFreqAttenuationFilter";
        volumeCurve="vehicleEngineAttenuationCurve";
        volumeFactor=1;
        occlusionFactor=0;
        obstructionFactor=0;
        spatial=1;
        loop=1;
        positionOffset[]={0,0,0.30000001};
    };
    class offroad_Engine_Ext_Rpm0_SoundSet: baseEngine_EXT_SoundSet
    {
        volumeFactor=0.3;
    };
    class offroad_Engine_Ext_Rpm1_SoundSet: baseEngine_EXT_SoundSet
    {
        volumeFactor=0.3;
    };
    class offroad_Engine_Offload_Ext_Rpm1_SoundSet: baseEngine_EXT_SoundSet
    {
        volumeFactor=0.3;
    };
    class offroad_Engine_Ext_Rpm2_SoundSet: baseEngine_EXT_SoundSet
    {
        volumeFactor=0.3;
    };
    class offroad_Engine_Offload_Ext_Rpm2_SoundSet: baseEngine_EXT_SoundSet
    {
        volumeFactor=0.3;
    };
    class offroad_Engine_Ext_Rpm3_SoundSet: baseEngine_EXT_SoundSet
    {
        volumeFactor=0.3;
    };
    class offroad_Engine_Offload_Ext_Rpm3_SoundSet: baseEngine_EXT_SoundSet
    {
        volumeFactor=0.3;
    };
    class offroad_Engine_Ext_Rpm4_SoundSet: baseEngine_EXT_SoundSet
    {
        volumeFactor=0.3;
    };
    class offroad_Engine_Offload_Ext_Rpm4_SoundSet: baseEngine_EXT_SoundSet
    {
        volumeFactor=0.3;
    };
    class offroad_Engine_Ext_Rpm5_SoundSet: baseEngine_EXT_SoundSet
    {
        volumeFactor=0.3;
    };
    class offroad_Engine_Offload_Ext_Rpm5_SoundSet: baseEngine_EXT_SoundSet
    {
        volumeFactor=0.3;
    };
    class offroad_Engine_Ext_Broken_SoundSet: baseEngine_EXT_SoundSet
    {
        volumeFactor=0.7;
    };
    class baseTires_Ext_SoundSet
    {
        sound3DProcessingType="Vehicle_Tires_Ext_3DProcessingType";
        distanceFilter="softVehiclesDistanceFreqAttenuationFilter";
        volumeCurve="vehicleAttenuationCurve";
        volumeFactor=1;
        occlusionFactor=0;
        obstructionFactor=0;
        spatial=1;
        loop=1;
    };
    class baseTires_Int_SoundSet;
    class offroad_Tires_rock_slow_EXT_SoundSet: baseTires_Ext_SoundSet
    {
        volumeFactor=0.3;
    };
    class offroad_Tires_rock_fast_EXT_SoundSet: baseTires_Ext_SoundSet
    {
        volumeFactor=0.3;
    };
    class offroad_Tires_grass_slow_EXT_SoundSet: baseTires_Ext_SoundSet
    {
        volumeFactor=0.3;
    };
    class offroad_Tires_grass_fast_EXT_SoundSet: baseTires_Ext_SoundSet
    {
        volumeFactor=0.3;
    };
    class offroad_Tires_gravel_slow_EXT_SoundSet: baseTires_Ext_SoundSet
    {
        volumeFactor=0.3;
    };
    class offroad_Tires_gravel_fast_EXT_SoundSet: baseTires_Ext_SoundSet
    {
        volumeFactor=0.3;
    };
    class offroad_Tires_asphalt_slow_EXT_SoundSet: baseTires_Ext_SoundSet
    {
        volumeFactor=0.3;
    };
    class offroad_Tires_asphalt_fast_EXT_SoundSet: baseTires_Ext_SoundSet
    {
        volumeFactor=0.3;
    };
    class offroad_Tires_asphalt_fast_general_INT_SoundSet: baseTires_Int_SoundSet
    {
        volumeFactor=0.1;
    };
    class offroad_Tires_water_slow_EXT_SoundSet: baseTires_Ext_SoundSet
    {
        volumeFactor=0.3;
    };
    class offroad_Tires_water_fast_EXT_SoundSet: baseTires_Ext_SoundSet
    {
        volumeFactor=0.3;
    };
    class offroad_Tires_gravel_dust_fast_EXT_SoundSet: baseTires_Ext_SoundSet
    {
        volumeFactor=0.3;
    };
    class baseVehicles_SoundSet;
    class offroad_engine_start_SoundSet: baseVehicles_SoundSet
    {
        volumeFactor=0.3;
    };
    class offroad_engine_stop_SoundSet: baseVehicles_SoundSet
    {
        volumeFactor=0.3;
    };
    class offroad_Gear_SoundSet
    {
        volumeFactor=0.3;
    };
    class Offroad_Engine_Thrust_Down_SoundSet: baseVehicles_SoundSet
    {
        volumeFactor=0.5;
    };

    class baseEngineCivilianSedan_EXT_SoundSet
    {
        sound3DProcessingType="Vehicle_Ext_3DProcessingType";
        distanceFilter="softVehiclesDistanceFreqAttenuationFilter";
        volumeCurve="vehicleEngineAttenuationCurve";
        volumeFactor=1;
        occlusionFactor=0;
        obstructionFactor=0;
        spatial=1;
        loop=1;
        positionOffset[]={0,0,0.30000001};
    };
    class CivilianSedan_Engine_Ext_Rpm0_SoundSet: baseEngineCivilianSedan_EXT_SoundSet
    {
        volumeFactor=0.3;
    };
    class CivilianSedan_Engine_Ext_Rpm1_SoundSet: baseEngineCivilianSedan_EXT_SoundSet
    {
        volumeFactor=0.3;
    };
    class CivilianSedan_Engine_Offload_Ext_Rpm1_SoundSet: baseEngineCivilianSedan_EXT_SoundSet
    {
        volumeFactor=0.3;
    };
    class CivilianSedan_Engine_Ext_Rpm2_SoundSet: baseEngineCivilianSedan_EXT_SoundSet
    {
        volumeFactor=0.3;
    };
    class CivilianSedan_Engine_Offload_Ext_Rpm2_SoundSet: baseEngineCivilianSedan_EXT_SoundSet
    {
        volumeFactor=0.3;
    };
    class CivilianSedan_Engine_Ext_Rpm3_SoundSet: baseEngineCivilianSedan_EXT_SoundSet
    {
        volumeFactor=0.3;
    };
    class CivilianSedan_Engine_Offload_Ext_Rpm3_SoundSet: baseEngineCivilianSedan_EXT_SoundSet
    {
        volumeFactor=0.3;
    };
    class CivilianSedan_Engine_Ext_Rpm4_SoundSet: baseEngineCivilianSedan_EXT_SoundSet
    {
        volumeFactor=0.3;
    };
    class CivilianSedan_Engine_Offload_Ext_Rpm4_SoundSet: baseEngineCivilianSedan_EXT_SoundSet
    {
        volumeFactor=0.3;
    };
    class CivilianSedan_Engine_Ext_Rpm5_SoundSet: baseEngineCivilianSedan_EXT_SoundSet
    {
        volumeFactor=0.3;
    };
    class CivilianSedan_Engine_Offload_Ext_Rpm5_SoundSet: baseEngineCivilianSedan_EXT_SoundSet
    {
        volumeFactor=0.3;
    };
    class CivilianSedan_Engine_Ext_Broken_SoundSet: baseEngineCivilianSedan_EXT_SoundSet
    {
        volumeFactor=0.7;
    };
    class baseTiresCivilianSedan_Ext_SoundSet
    {
        sound3DProcessingType="Vehicle_Tires_Ext_3DProcessingType";
        distanceFilter="softVehiclesDistanceFreqAttenuationFilter";
        volumeCurve="vehicleAttenuationCurve";
        volumeFactor=1;
        occlusionFactor=0;
        obstructionFactor=0;
        spatial=1;
        loop=1;
    };
    class baseTiresCivilianSedan_Int_SoundSet;
    class CivilianSedan_Tires_rock_slow_EXT_SoundSet: baseTiresCivilianSedan_Ext_SoundSet
    {
        volumeFactor=0.3;
    };
    class CivilianSedan_Tires_rock_fast_EXT_SoundSet: baseTiresCivilianSedan_Ext_SoundSet
    {
        volumeFactor=0.3;
    };
    class CivilianSedan_Tires_grass_slow_EXT_SoundSet: baseTiresCivilianSedan_Ext_SoundSet
    {
        volumeFactor=0.3;
    };
    class CivilianSedan_Tires_grass_fast_EXT_SoundSet: baseTiresCivilianSedan_Ext_SoundSet
    {
        volumeFactor=0.3;
    };
    class CivilianSedan_Tires_gravel_slow_EXT_SoundSet: baseTiresCivilianSedan_Ext_SoundSet
    {
        volumeFactor=0.3;
    };
    class CivilianSedan_Tires_gravel_fast_EXT_SoundSet: baseTiresCivilianSedan_Ext_SoundSet
    {
        volumeFactor=0.3;
    };
    class CivilianSedan_Tires_asphalt_slow_EXT_SoundSet: baseTiresCivilianSedan_Ext_SoundSet
    {
        volumeFactor=0.3;
    };
    class CivilianSedan_Tires_asphalt_fast_EXT_SoundSet: baseTiresCivilianSedan_Ext_SoundSet
    {
        volumeFactor=0.3;
    };
    class CivilianSedan_Tires_asphalt_fast_general_INT_SoundSet: baseTiresCivilianSedan_Int_SoundSet
    {
        volumeFactor=0.1;
    };
    class CivilianSedan_Tires_water_slow_EXT_SoundSet: baseTiresCivilianSedan_Ext_SoundSet
    {
        volumeFactor=0.3;
    };
    class CivilianSedan_Tires_water_fast_EXT_SoundSet: baseTiresCivilianSedan_Ext_SoundSet
    {
        volumeFactor=0.3;
    };
    class CivilianSedan_Tires_gravel_dust_fast_EXT_SoundSet: baseTires_Ext_SoundSet
    {
        volumeFactor=0.3;
    };
    class baseVehiclesCivilianSedan_SoundSet;
    class CivilianSedan_engine_start_SoundSet: baseVehiclesCivilianSedan_SoundSet
    {
        volumeFactor=0.3;
    };
    class CivilianSedan_engine_stop_SoundSet: baseVehiclesCivilianSedan_SoundSet
    {
        volumeFactor=0.3;
    };
    class CivilianSedan_Gear_SoundSet
    {
        volumeFactor=0.3;
    };
    class CivilianSedan_Engine_Thrust_Down_SoundSet: baseVehicles_SoundSet
    {
        volumeFactor=0.5;
    };

    class baseEngineHatchback_02_EXT_SoundSet
    {
        sound3DProcessingType="Vehicle_Ext_3DProcessingType";
        distanceFilter="softVehiclesDistanceFreqAttenuationFilter";
        volumeCurve="vehicleEngineAttenuationCurve";
        volumeFactor=1;
        occlusionFactor=0;
        obstructionFactor=0;
        spatial=1;
        loop=1;
        positionOffset[]={0,0,0.30000001};
    };
    class Hatchback_02_Engine_Ext_Rpm0_SoundSet: baseEngineHatchback_02_EXT_SoundSet
    {
        volumeFactor=0.3;
    };
    class Hatchback_02_Engine_Ext_Rpm1_SoundSet: baseEngineHatchback_02_EXT_SoundSet
    {
        volumeFactor=0.3;
    };
    class Hatchback_02_Engine_Offload_Ext_Rpm1_SoundSet: baseEngineHatchback_02_EXT_SoundSet
    {
        volumeFactor=0.3;
    };
    class Hatchback_02_Engine_Ext_Rpm2_SoundSet: baseEngineHatchback_02_EXT_SoundSet
    {
        volumeFactor=0.3;
    };
    class Hatchback_02_Engine_Offload_Ext_Rpm2_SoundSet: baseEngineHatchback_02_EXT_SoundSet
    {
        volumeFactor=0.3;
    };
    class Hatchback_02_Engine_Ext_Rpm3_SoundSet: baseEngineHatchback_02_EXT_SoundSet
    {
        volumeFactor=0.3;
    };
    class Hatchback_02_Engine_Offload_Ext_Rpm3_SoundSet: baseEngineHatchback_02_EXT_SoundSet
    {
        volumeFactor=0.3;
    };
    class Hatchback_02_Engine_Ext_Rpm4_SoundSet: baseEngineHatchback_02_EXT_SoundSet
    {
        volumeFactor=0.3;
    };
    class Hatchback_02_Engine_Offload_Ext_Rpm4_SoundSet: baseEngineHatchback_02_EXT_SoundSet
    {
        volumeFactor=0.3;
    };
    class Hatchback_02_Engine_Ext_Rpm5_SoundSet: baseEngineHatchback_02_EXT_SoundSet
    {
        volumeFactor=0.3;
    };
    class Hatchback_02_Engine_Offload_Ext_Rpm5_SoundSet: baseEngineHatchback_02_EXT_SoundSet
    {
        volumeFactor=0.3;
    };
    class Hatchback_02_Engine_Ext_Broken_SoundSet: baseEngineHatchback_02_EXT_SoundSet
    {
        volumeFactor=0.7;
    };
    class baseTiresHatchback_02_Ext_SoundSet
    {
        sound3DProcessingType="Vehicle_Tires_Ext_3DProcessingType";
        distanceFilter="softVehiclesDistanceFreqAttenuationFilter";
        volumeCurve="vehicleAttenuationCurve";
        volumeFactor=1;
        occlusionFactor=0;
        obstructionFactor=0;
        spatial=1;
        loop=1;
    };
    class baseTiresHatchback_02_Int_SoundSet;
    class Hatchback_02_Tires_rock_slow_EXT_SoundSet: baseTiresHatchback_02_Ext_SoundSet
    {
        volumeFactor=0.3;
    };
    class Hatchback_02_Tires_rock_fast_EXT_SoundSet: baseTiresHatchback_02_Ext_SoundSet
    {
        volumeFactor=0.3;
    };
    class Hatchback_02_Tires_grass_slow_EXT_SoundSet: baseTiresHatchback_02_Ext_SoundSet
    {
        volumeFactor=0.3;
    };
    class Hatchback_02_Tires_grass_fast_EXT_SoundSet: baseTiresHatchback_02_Ext_SoundSet
    {
        volumeFactor=0.3;
    };
    class Hatchback_02_Tires_gravel_slow_EXT_SoundSet: baseTiresHatchback_02_Ext_SoundSet
    {
        volumeFactor=0.3;
    };
    class Hatchback_02_Tires_gravel_fast_EXT_SoundSet: baseTiresHatchback_02_Ext_SoundSet
    {
        volumeFactor=0.3;
    };
    class Hatchback_02_Tires_asphalt_slow_EXT_SoundSet: baseTiresHatchback_02_Ext_SoundSet
    {
        volumeFactor=0.3;
    };
    class Hatchback_02_Tires_asphalt_fast_EXT_SoundSet: baseTiresHatchback_02_Ext_SoundSet
    {
        volumeFactor=0.3;
    };
    class Hatchback_02_Tires_asphalt_fast_general_INT_SoundSet: baseTiresHatchback_02_Int_SoundSet
    {
        volumeFactor=0.3;
    };
    class Hatchback_02_Tires_water_slow_EXT_SoundSet: baseTiresHatchback_02_Ext_SoundSet
    {
        volumeFactor=0.3;
    };
    class Hatchback_02_Tires_water_fast_EXT_SoundSet: baseTiresHatchback_02_Ext_SoundSet
    {
        volumeFactor=0.3;
    };
    class Hatchback_02_Tires_gravel_dust_fast_EXT_SoundSet: baseTires_Ext_SoundSet
    {
        volumeFactor=0.3;
    };
    class baseVehiclesHatchback_02_SoundSet;
    class Hatchback_02_engine_start_SoundSet: baseVehiclesHatchback_02_SoundSet
    {
        volumeFactor=0.3;
    };
    class Hatchback_02_engine_stop_SoundSet: baseVehiclesHatchback_02_SoundSet
    {
        volumeFactor=0.3;
    };
    class Hatchback_02_Gear_SoundSet
    {
        volumeFactor=0.3;
    };
    class Hatchback_02_Engine_Thrust_Down_SoundSet: baseVehicles_SoundSet
    {
        volumeFactor=0.5;
    };

    class baseEngineSedan_02_EXT_SoundSet
    {
        sound3DProcessingType="Vehicle_Ext_3DProcessingType";
        distanceFilter="softVehiclesDistanceFreqAttenuationFilter";
        volumeCurve="vehicleEngineAttenuationCurve";
        volumeFactor=1;
        occlusionFactor=0;
        obstructionFactor=0;
        spatial=1;
        loop=1;
    };
    class Sedan_02_Engine_Ext_Rpm0_SoundSet: baseEngineSedan_02_EXT_SoundSet
    {
        volumeFactor=0.3;
    };
    class Sedan_02_Engine_Ext_Rpm1_SoundSet: baseEngineSedan_02_EXT_SoundSet
    {
        volumeFactor=0.3;
    };
    class Sedan_02_Engine_Offload_Ext_Rpm1_SoundSet: baseEngineSedan_02_EXT_SoundSet
    {
        volumeFactor=0.3;
    };
    class Sedan_02_Engine_Ext_Rpm2_SoundSet: baseEngineSedan_02_EXT_SoundSet
    {
        volumeFactor=0.3;
    };
    class Sedan_02_Engine_Offload_Ext_Rpm2_SoundSet: baseEngineSedan_02_EXT_SoundSet
    {
        volumeFactor=0.3;
    };
    class Sedan_02_Engine_Ext_Rpm3_SoundSet: baseEngineSedan_02_EXT_SoundSet
    {
        volumeFactor=0.3;
    };
    class Sedan_02_Engine_Offload_Ext_Rpm3_SoundSet: baseEngineSedan_02_EXT_SoundSet
    {
        volumeFactor=0.3;
    };
    class Sedan_02_Engine_Ext_Rpm4_SoundSet: baseEngineSedan_02_EXT_SoundSet
    {
        volumeFactor=0.3;
    };
    class Sedan_02_Engine_Offload_Ext_Rpm4_SoundSet: baseEngineSedan_02_EXT_SoundSet
    {
        volumeFactor=0.3;
    };
    class Sedan_02_Engine_Ext_Rpm5_SoundSet: baseEngineSedan_02_EXT_SoundSet
    {
        volumeFactor=0.3;
    };
    class Sedan_02_Engine_Offload_Ext_Rpm5_SoundSet: baseEngineSedan_02_EXT_SoundSet
    {
        volumeFactor=0.3;
    };
    class Sedan_02_Engine_Ext_Broken_SoundSet: baseEngineSedan_02_EXT_SoundSet
    {
        volumeFactor=0.5;
    };
    class baseTiresSedan_02_Ext_SoundSet
    {
        sound3DProcessingType="Vehicle_Tires_Ext_3DProcessingType";
        distanceFilter="softVehiclesDistanceFreqAttenuationFilter";
        volumeCurve="vehicleAttenuationCurve";
        volumeFactor=1;
        occlusionFactor=0;
        obstructionFactor=0;
        spatial=1;
        loop=1;
    };
    class baseTiresSedan_02_Int_SoundSet;
    class Sedan_02_Tires_rock_slow_EXT_SoundSet: baseTiresSedan_02_Ext_SoundSet
    {
        volumeFactor=0.3;
    };
    class Sedan_02_Tires_rock_fast_EXT_SoundSet: baseTiresSedan_02_Ext_SoundSet
    {
        volumeFactor=0.3;
    };
    class Sedan_02_Tires_grass_slow_EXT_SoundSet: baseTiresSedan_02_Ext_SoundSet
    {
        volumeFactor=0.3;
    };
    class Sedan_02_Tires_grass_fast_EXT_SoundSet: baseTiresSedan_02_Ext_SoundSet
    {
        volumeFactor=0.3;
    };
    class Sedan_02_Tires_gravel_slow_EXT_SoundSet: baseTiresSedan_02_Ext_SoundSet
    {
        volumeFactor=0.3;
    };
    class Sedan_02_Tires_gravel_fast_EXT_SoundSet: baseTiresSedan_02_Ext_SoundSet
    {
        volumeFactor=0.3;
    };
    class Sedan_02_Tires_asphalt_slow_EXT_SoundSet: baseTiresSedan_02_Ext_SoundSet
    {
        volumeFactor=0.3;
    };
    class Sedan_02_Tires_asphalt_fast_EXT_SoundSet: baseTiresSedan_02_Ext_SoundSet
    {
        volumeFactor=0.3;
    };
    class Sedan_02_Tires_asphalt_fast_general_INT_SoundSet: baseTiresSedan_02_Int_SoundSet
    {
        volumeFactor=0.3;
    };
    class Sedan_02_Tires_water_slow_EXT_SoundSet: baseTiresSedan_02_Ext_SoundSet
    {
        volumeFactor=0.3;
    };
    class Sedan_02_Tires_water_fast_EXT_SoundSet: baseTiresSedan_02_Ext_SoundSet
    {
        volumeFactor=0.3;
    };
    class Sedan_02_Tires_gravel_dust_fast_EXT_SoundSet: baseTires_Ext_SoundSet
    {
        volumeFactor=0.3;
    };
    class baseVehiclesSedan_02_SoundSet;
    class Sedan_02_engine_start_SoundSet: baseVehiclesSedan_02_SoundSet
    {
        volumeFactor=0.3;
    };
    class Sedan_02_engine_stop_SoundSet: baseVehiclesSedan_02_SoundSet
    {
        volumeFactor=0.3;
    };
    class Sedan_02_Engine_Thrust_Down_SoundSet: baseVehicles_SoundSet
    {
        volumeFactor=0.3;
    };
    class Sedan_02_Gear_SoundSet
    {
        volumeFactor=0.3;
    };
};
class cfgVehicles
{
	class ItemSuppressor;
	class M4_Suppressor: ItemSuppressor
	{
		noiseShootModifier=-3;//Quieter to infected
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;//More durable suppressors
				};
			};
		};
	};
	class AK_Suppressor: ItemSuppressor
	{
		noiseShootModifier=-3;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
				};
			};
		};
	};
	class PistolSuppressor: ItemSuppressor
	{
		noiseShootModifier=-3;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
				};
			};
		};
	};
	class ImprovisedSuppressor: ItemSuppressor
	{
		noiseShootModifier=-2;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=2;//Will become ruined very quickly
				};
			};
		};
	};
	class Suppressor_556: ItemSuppressor
	{
		noiseShootModifier=-3;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
				};
			};
		};
	};
};