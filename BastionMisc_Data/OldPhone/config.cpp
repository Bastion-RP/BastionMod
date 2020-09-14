class CfgPatches
{
	class BRP_OldPhone
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data"
		};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class BRP_OldPhone: Inventory_Base
	{
		scope=2;
		displayName="2001 BUDA Bokia";
		descriptionShort="In the year 2001 BUDA international (formaly known as CUDAInc) released its 'Bokia' model that surpassed any other modular cell device on the market with its 80mb of internal storage,1.3 megapixel camera,video recording and a variety of UI features such as Mobile Blog, Yoga Graphic book. It also came in colours such as Black,pink and lime these models mainly sought popularity throughout Korea and Kolograd";
		model="BastionMod\BastionMisc_Data\OldPhone\oldphone.p3d";
		weight=100;
		absorbency=0.0;
		itemSize[]={1,1};
		inventorySlot="WalkieTalkie";
		rotationFlags=1;
		isMeleeWeapon=1;
		class MeleeModes
		{
			class Default
			{
				ammo="MeleeLightBlunt";
				range=1;
			};
			class Heavy
			{
				ammo="MeleeLightBlunt_Heavy";
				range=1;
			};
			class Sprint
			{
				ammo="MeleeLightBlunt_Heavy";
				range=2.8;
			};
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = 
					{
						{1.0,{"BastionMod\BastionMisc_Data\OldPhone\data\phone.rvmat"}},
						{0.7,{"BastionMod\BastionMisc_Data\OldPhone\data\phone.rvmat"}},
						{0.5,{"BastionMod\BastionMisc_Data\OldPhone\data\phone_damage.rvmat"}},
						{0.3,{"BastionMod\BastionMisc_Data\OldPhone\data\phone_damage.rvmat"}},
						{0.0,{"BastionMod\BastionMisc_Data\OldPhone\data\phone_destruct.rvmat"}}
					};
				};
			};
		};
	};
};
