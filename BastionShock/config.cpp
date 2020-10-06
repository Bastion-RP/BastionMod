class CfgPatches
{
	class BastionShock
	{
		units[]={
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]={
			"DZ_Data",
			"DZ_Characters"
		};
	};
};
class CfgMods
{
	class BastionShock
	{
	    type = "mod";
	    dependencies[] = {"Game","World","Mission"};
	    class defs
	    {
			class gameScriptModule
            {
                value = "";
                files[] = {"BastionMod/BastionShock/scripts/3_Game"};
            };
			class worldScriptModule
            {
                value = "";
                files[] = {"BastionMod/BastionShock/scripts/4_World"};
            };
			class missionScriptModule
            {
                value = "";
                files[] = {"BastionMod/BastionShock/scripts/5_Mission"};
            };
        };
    };
};

// - Increased HP
// - Increased blood
// - Increased headshot damage base multiplier
// - Removed instakill chance from headshots
// - Reduce arm multiplier by 10%
// - Updated to 1.08
class CfgVehicles
{
	class AllVehicles;
	class Man: AllVehicles
	{
	};
	class SurvivorBase: Man
	{
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=150;
					healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}}};
				};
				class Blood
				{
					hitpoints=6000;
				};
				class Shock
				{
					hitpoints=100;
				};
			};
			class DamageZones
			{
				class Head
				{
					class Health
					{
						hitpoints=33;
						transferToGlobalCoef=3;
					};
					class Blood
					{
						hitpoints=100;
						transferToGlobalCoef=0;
					};
					class Shock
					{
						hitpoints=0;
						transferToGlobalCoef=1.5;	// increased from van
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage=1;
							};
							class Blood
							{
								damage=1;
							};
							class Shock
							{
								damage=3;
							};
						};
						class Melee
						{
							class Health
							{
								damage=0.5;
							};
							class Blood
							{
								damage=1;
							};
							class Shock
							{
								damage=1;
							};
						};
						class Infected
						{
							class Health
							{
								damage=0.5;
							};
							class Blood
							{
								damage=1;
							};
							class Shock
							{
								damage=1;
							};
						};
					};
					componentNames[] = {"dmgZone_head"};
					fatalInjuryCoef = -1;
					inventorySlots[] = {"Headgear","Mask","Eyewear"};
				};
				class Brain
				{
					class Health
					{
						hitpoints=100;
						transferToGlobalCoef=0;
					};
					class Blood
					{
						hitpoints=100;
						transferToGlobalCoef=0;
					};
					class Shock
					{
						hitpoints=0;
						transferToGlobalCoef=1;
					};
					class ArmorType
					{
						class Melee
						{
							class Health
							{
								damage=0;
							};
							class Blood
							{
								damage=1;
							};
							class Shock
							{
								damage=1;
							};
						};
						class Projectile
						{
							class Health
							{
								damage=1;
							};
							class Blood
							{
								damage=0;
							};
							class Shock
							{
								damage=0;
							};
						};
						class FragGrenade
						{
							class Health
							{
								damage=0;
							};
							class Blood
							{
								damage=1;
							};
							class Shock
							{
								damage=1;
							};
						};
					};
					componentNames[] = {"dmgZone_brain"};
					fatalInjuryCoef=-1;
				};
				class Lungs
				{
					class Health
					{
						hitpoints=100;
						transferToGlobalCoef=0;
					};
					class Blood
					{
						hitpoints=100;
						transferToGlobalCoef=0;
					};
					class Shock
					{
						hitpoints=0;
						transferToGlobalCoef=1;
					};
					class ArmorType
					{
						class Melee
						{
							class Health
							{
								damage=0;
							};
							class Blood
							{
								damage=1;
							};
							class Shock
							{
								damage=1;
							};
						};
						class Projectile
						{
							class Health
							{
								damage=1;
							};
							class Blood
							{
								damage=0;
							};
							class Shock
							{
								damage=0;
							};
						};
						class FragGrenade
						{
							class Health
							{
								damage=0;
							};
							class Blood
							{
								damage=1;
							};
							class Shock
							{
								damage=1;
							};
						};
					};
					componentNames[] = {""};
					fatalInjuryCoef=-1;
				};
				class Spine
				{
					class Health
					{
						hitpoints=100;
						transferToGlobalCoef=0;
					};
					class Blood
					{
						hitpoints=100;
						transferToGlobalCoef=0;
					};
					class Shock
					{
						hitpoints=0;
						transferToGlobalCoef=1;
					};
					class ArmorType
					{
						class Melee
						{
							class Health
							{
								damage=0;
							};
							class Blood
							{
								damage=1;
							};
							class Shock
							{
								damage=1;
							};
						};
						class Projectile
						{
							class Health
							{
								damage=1;
							};
							class Blood
							{
								damage=0;
							};
							class Shock
							{
								damage=0;
							};
						};
					};
					componentNames[] = {""};
					fatalInjuryCoef=-1;
				};
				class Liver
				{
					class Health
					{
						hitpoints=100;
						transferToGlobalCoef=0;
					};
					class Blood
					{
						hitpoints=100;
						transferToGlobalCoef=0;
					};
					class Shock
					{
						hitpoints=0;
						transferToGlobalCoef=1;
					};
					class ArmorType
					{
						class Melee
						{
							class Health
							{
								damage=0;
							};
							class Blood
							{
								damage=1;
							};
							class Shock
							{
								damage=1;
							};
						};
						class Projectile
						{
							class Health
							{
								damage=1;
							};
							class Blood
							{
								damage=0;
							};
							class Shock
							{
								damage=0;
							};
						};
					};
					componentNames[] = {""};
					fatalInjuryCoef=-1;
				};
				class Heart
				{
					class Health
					{
						hitpoints=100;
						transferToGlobalCoef=0;
					};
					class Blood
					{
						hitpoints=100;
						transferToGlobalCoef=0;
					};
					class Shock
					{
						hitpoints=0;
						transferToGlobalCoef=1;
					};
					class ArmorType
					{
						class Melee
						{
							class Health
							{
								damage=0;
							};
							class Blood
							{
								damage=1;
							};
							class Shock
							{
								damage=1;
							};
						};
						class Projectile
						{
							class Health
							{
								damage=1;
							};
							class Blood
							{
								damage=0;
							};
							class Shock
							{
								damage=0;
							};
						};
						class FragGrenade
						{
							class Health
							{
								damage=0;
							};
							class Blood
							{
								damage=1;
							};
							class Shock
							{
								damage=1;
							};
						};
					};
					componentNames[] = {""};
					fatalInjuryCoef=-1;
				};
				class Torso
				{
					class Health
					{
						hitpoints=100;
						transferToGlobalCoef=1;
					};
					class Blood
					{
						hitpoints=100;
						transferToGlobalCoef=0;
					};
					class Shock
					{
						hitpoints=0;
						transferToGlobalCoef=1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage=1;
							};
							class Blood
							{
								damage=1;
							};
							class Shock
							{
								damage=1;
							};
						};
					};
					componentNames[] = {"dmgZone_torso","dmgZone_lungs","dmgZone_spine","dmgZone_liver","dmgZone_heart"};
					fatalInjuryCoef=-1;
					inventorySlots[] = {"Vest","Body","Back","Hips"};
					inventorySlotsCoefs[] = {1.0,1.0,0.5,0.35};
				};
				class LeftArm
				{
					class Health
					{
						hitpoints=100;
						transferToGlobalCoef=0.23000001;
					};
					class Blood
					{
						hitpoints=100;
						transferToGlobalCoef=0;
					};
					class Shock
					{
						hitpoints=0;
						transferToGlobalCoef=1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage=1;
							};
							class Blood
							{
								damage=1;
							};
							class Shock
							{
								damage=0.33000001;
							};
						};
					};
					componentNames[] = {"dmgZone_leftArm"};
					fatalInjuryCoef=-1;
				};
				class RightArm
				{
					class Health
					{
						hitpoints=100;
						transferToGlobalCoef=0.23000001;
					};
					class Blood
					{
						hitpoints=100;
						transferToGlobalCoef=0;
					};
					class Shock
					{
						hitpoints=0;
						transferToGlobalCoef=1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage=1;
							};
							class Blood
							{
								damage=1;
							};
							class Shock
							{
								damage=0.33000001;
							};
						};
					};
					componentNames[] = {"dmgZone_rightArm"};
					fatalInjuryCoef=-1;
				};
				class LeftHand
				{
					class Health
					{
						hitpoints=100;
						transferToGlobalCoef=0.1;
					};
					class Blood
					{
						hitpoints=100;
						transferToGlobalCoef=0;
					};
					class Shock
					{
						hitpoints=0;
						transferToGlobalCoef=1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage=1;
							};
							class Blood
							{
								damage=1;
							};
							class Shock
							{
								damage=0.1;
							};
						};
					};
					transferToZonesNames[] = {"LeftArm"};
					transferToZonesCoefs[] = {0.1};
					componentNames[] = {"dmgZone_leftHand"};
					fatalInjuryCoef = -1;
					inventorySlots[] = {"Gloves"};
				};
				class RightHand
				{
					class Health
					{
						hitpoints=100;
						transferToGlobalCoef=0.1;
					};
					class Blood
					{
						hitpoints=100;
						transferToGlobalCoef=0;
					};
					class Shock
					{
						hitpoints=0;
						transferToGlobalCoef=1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage=1;
							};
							class Blood
							{
								damage=1;
							};
							class Shock
							{
								damage=0.1;
							};
						};
					};
					transferToZonesNames[] = {"RightArm"};
					transferToZonesCoefs[] = {0.1};
					componentNames[] = {"dmgZone_rightHand"};
					fatalInjuryCoef = -1;
					inventorySlots[] = {"Gloves"};
				};
				class LeftLeg
				{
					class Health
					{
						hitpoints=100;
						transferToGlobalCoef=0.33000001;
					};
					class Blood
					{
						hitpoints=100;
						transferToGlobalCoef=0;
					};
					class Shock
					{
						hitpoints=0;
						transferToGlobalCoef=1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage=1;
							};
							class Blood
							{
								damage=1;
							};
							class Shock
							{
								damage=0.33000001;
							};
						};
					};
					fatalInjuryCoef = -1;
					componentNames[] = {"dmgZone_leftLeg"};
					inventorySlots[] = {"Legs"};
				};
				class RightLeg
				{
					class Health
					{
						hitpoints=100;
						transferToGlobalCoef=0.33000001;
					};
					class Blood
					{
						hitpoints=100;
						transferToGlobalCoef=0;
					};
					class Shock
					{
						hitpoints=0;
						transferToGlobalCoef=1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage=1;
							};
							class Blood
							{
								damage=1;
							};
							class Shock
							{
								damage=0.33000001;
							};
						};
					};
					componentNames[] = {"dmgZone_rightLeg"};
					inventorySlots[] = {"Legs"};
				};
				class LeftFoot
				{
					class Health
					{
						hitpoints=100;
						transferToGlobalCoef=0.1;
					};
					class Blood
					{
						hitpoints=100;
						transferToGlobalCoef=0;
					};
					class Shock
					{
						hitpoints=0;
						transferToGlobalCoef=1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage=1;
							};
							class Blood
							{
								damage=1;
							};
							class Shock
							{
								damage=0.1;
							};
						};
					};
					fatalInjuryCoef = -1;
					componentNames[] = {"dmgZone_leftFoot"};
					inventorySlots[] = {"Feet"};
					transferToZonesNames[] = {"LeftLeg"};
					transferToZonesCoefs[] = {0.2};
				};
				class RightFoot
				{
					class Health
					{
						hitpoints=100;
						transferToGlobalCoef=0.1;
					};
					class Blood
					{
						hitpoints=100;
						transferToGlobalCoef=0;
					};
					class Shock
					{
						hitpoints=0;
						transferToGlobalCoef=1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage=1;
							};
							class Blood
							{
								damage=1;
							};
							class Shock
							{
								damage=0.1;
							};
						};
					};
					componentNames[] = {"dmgZone_rightFoot"};
					transferToZonesNames[] = {"RightLeg"};
					transferToZonesCoefs[] = {0.2};
				};
			};
		};
		class NoiseStepStand
		{
			strength=16;
			type="sound";
		};
		class NoiseStepCrouch
		{
			strength=6;
			type="sound";
		};
		class NoiseStepProne
		{
			strength=3;
			type="sound";
		};
		class NoiseLandLight
		{
			strength=8;
			type="sound";
		};
		class NoiseLandHeavy
		{
			strength=16;
			type="sound";
		};
	};
};