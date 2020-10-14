class CfgPatches
{
	class BastionMisc_Other
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] =
		{
			"DZ_Data"
		};
	};
};
class CfgVehicles
{
	class Edible_Base;
	class BRP_PainMedicalBottle: Edible_Base
	{
		scope=2;
		displayName="Pain Medical Pills";
		descriptionShort="When you can't handle the pain more, these pills will combat the pain.";
		model="\dz\gear\medical\VitaminBottle.p3d";
		varQuantityInit=10;
		varQuantityMin=0;
		varQuantityMax=10;
		varQuantityDestroyOnMin=1;
		itemSize[]={1,2};
		weight=20;
		stackedUnit="pills";
		quantityBar=0;
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionMisc\Retextures\data\painmeds_bottle_co.paa",
			"BastionMod\BastionMisc\Retextures\data\painmeds_bottle_co.paa",
			"BastionMod\BastionMisc\Retextures\data\painmeds_bottle_co.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
					healthLevels[] = {{1.0,{"DZ\gear\medical\data\vitamin_bottle.rvmat"}},{0.7,{"DZ\gear\medical\data\vitamin_bottle.rvmat"}},{0.5,{"DZ\gear\medical\data\vitamin_bottle_damage.rvmat"}},{0.3,{"DZ\gear\medical\data\vitamin_bottle_damage.rvmat"}},{0.0,{"DZ\gear\medical\data\vitamin_bottle_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class VitaminBottle_open
				{
					soundSet="VitaminBottle_open_SoundSet";
					id=201;
				};
				class VitaminBottle_shake
				{
					soundSet="VitaminBottle_shake_SoundSet";
					id=202;
				};
				class VitaminBottle_close
				{
					soundSet="VitaminBottle_close_SoundSet";
					id=203;
				};
				class pickUpItem
				{
					soundSet="vitaminbottle_pickup_SoundSet";
					id=797;
				};
			};
		};
	};
	class BRP_AllergyBottle: Edible_Base
	{
		scope=2;
		displayName="Allergy Pills";
		descriptionShort="These pills will help fight against those horrible allergies.";
		model="\dz\gear\medical\VitaminBottle.p3d";
		varQuantityInit=10;
		varQuantityMin=0;
		varQuantityMax=10;
		varQuantityDestroyOnMin=1;
		itemSize[]={1,2};
		weight=20;
		stackedUnit="pills";
		quantityBar=0;
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionMisc\Retextures\data\alergy_bottle_co.paa",
			"BastionMod\BastionMisc\Retextures\data\alergy_bottle_co.paa",
			"BastionMod\BastionMisc\Retextures\data\alergy_bottle_co.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
					healthLevels[] = {{1.0,{"DZ\gear\medical\data\vitamin_bottle.rvmat"}},{0.7,{"DZ\gear\medical\data\vitamin_bottle.rvmat"}},{0.5,{"DZ\gear\medical\data\vitamin_bottle_damage.rvmat"}},{0.3,{"DZ\gear\medical\data\vitamin_bottle_damage.rvmat"}},{0.0,{"DZ\gear\medical\data\vitamin_bottle_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class VitaminBottle_open
				{
					soundSet="VitaminBottle_open_SoundSet";
					id=201;
				};
				class VitaminBottle_shake
				{
					soundSet="VitaminBottle_shake_SoundSet";
					id=202;
				};
				class VitaminBottle_close
				{
					soundSet="VitaminBottle_close_SoundSet";
					id=203;
				};
				class pickUpItem
				{
					soundSet="vitaminbottle_pickup_SoundSet";
					id=797;
				};
			};
		};
	};
};