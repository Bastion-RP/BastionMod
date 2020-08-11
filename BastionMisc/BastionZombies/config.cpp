class CfgPatches
{
	class BastionZombies
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
	class BastionZombies
	{
	    type = "mod";
	    dependencies[] = {"Game","World","Mission"};
	    class defs
	    {
			class gameScriptModule
            {
                value = "";
                files[] = {"BastionMod/BastionMisc/BastionZombies/scripts/3_Game"};
            };
			class worldScriptModule
            {
                value = "";
                files[] = {"BastionMod/BastionMisc/BastionZombies/scripts/4_World"};
            };
			class missionScriptModule
            {
                value = "";
                files[] = {"BastionMod/BastionMisc/BastionZombies/scripts/5_Mission"};
            };
        };
    };
};

class CfgVehicles
{
	class DayZInfected;
	class ZombieBase: DayZInfected
	{		
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=150;
				};
			};
			class DamageZones
			{
				class Head
				{
					class Health
					{
						hitpoints=100;
						transferToGlobalCoef=0.4;	// from 0.3
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage=5;
							};
						};
						class FragGrenade
						{
							class Health
							{
								damage=3;
							};
						};
					};
					componentNames[]=
					{
						"Head"
					};
					fatalInjuryCoef=0.05;	// 5 % chance to instakill
					inventorySlots[]=
					{
						"Headgear",
						"Mask"
					};
				};
				class Torso
				{
					class Health
					{
						hitpoints=500;
						transferToGlobalCoef=0.10;	// from 0.05
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage=4;	// from 8
							};
						};
						class FragGrenade
						{
							class Health
							{
								damage=2;
							};
						};
					};
					componentNames[]=
					{
						"Spine1",
						"Spine3"
					};
					fatalInjuryCoef=-1;
					inventorySlots[]=
					{
						"Vest",
						"Body",
						"Back"
					};
				};
				class LeftArm
				{
					class Health
					{
						hitpoints=100;
						transferToGlobalCoef=0.033000001;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage=2;
							};
						};
						class FragGrenade
						{
							class Health
							{
								damage=2;
							};
						};
					};
					componentNames[]=
					{
						"LeftArm",
						"LeftForeArm"
					};
					fatalInjuryCoef=-1;
				};
				class RightArm
				{
					class Health
					{
						hitpoints=100;
						transferToGlobalCoef=0.033000001;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage=2;
							};
						};
						class FragGrenade
						{
							class Health
							{
								damage=2;
							};
						};
					};
					componentNames[]=
					{
						"RightArm",
						"RightForeArm"
					};
					fatalInjuryCoef=-1;
				};
				class LeftLeg
				{
					class Health
					{
						hitpoints=300;
						transferToGlobalCoef=0.033000001;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage=4;
							};
						};
						class FragGrenade
						{
							class Health
							{
								damage=2;
							};
						};
					};
					componentNames[]=
					{
						"LeftLeg",
						"LeftUpLeg"
					};
					fatalInjuryCoef=-1;
					inventorySlots[]=
					{
						"Legs"
					};
				};
				class RightLeg
				{
					class Health
					{
						hitpoints=300;
						transferToGlobalCoef=0.033000001;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage=4;
							};
						};
						class FragGrenade
						{
							class Health
							{
								damage=2;
							};
						};
					};
					componentNames[]=
					{
						"RightLeg",
						"RightUpLeg"
					};
					fatalInjuryCoef=-1;
					inventorySlots[]=
					{
						"Legs"
					};
				};
				class LeftFoot
				{
					class Health
					{
						hitpoints=100;
						transferToGlobalCoef=0.01;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage=2;
							};
						};
						class FragGrenade
						{
							class Health
							{
								damage=2;
							};
						};
					};
					transferToZonesNames[]=
					{
						"LeftLeg"
					};
					transferToZonesCoefs[]={0.1};
					componentNames[]=
					{
						"LeftFoot"
					};
					fatalInjuryCoef=-1;
					inventorySlots[]=
					{
						"Feet"
					};
				};
				class RightFoot
				{
					class Health
					{
						hitpoints=100;
						transferToGlobalCoef=0.01;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage=2;
							};
						};
						class FragGrenade
						{
							class Health
							{
								damage=2;
							};
						};
					};
					transferToZonesNames[]=
					{
						"RightLeg"
					};
					transferToZonesCoefs[]={0.1};
					componentNames[]=
					{
						"RightFoot"
					};
					fatalInjuryCoef=-1;
					inventorySlots[]=
					{
						"Feet"
					};
				};
			};
		};
	};
};