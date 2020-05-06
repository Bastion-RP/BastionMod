class CfgPatches
{
	class BRP_AIONBox
	{
		units[] = {"BRP_AIONBox"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
	};
};

class CfgVehicles
{
	class Inventory_Base;
	class HouseNoDestruct;
	class BRP_AIONBox: Inventory_Base
	{
		scope=2;
		displayName="AION Box";
		descriptionShort="Box full of Aion | All-In-One NutritionAion. Developed by the NATO-CSTO Coalition.  Is an affordable, sustainable, all-in-one solution to the food crisis that we face every day. In order to regrow a population in a world wracked with disaster, it is imperative that our citizens have access to nutrition that is easy to consume and easy to sustain, so no one in any Bastion goes hungry.Each serving contains 25% daily value of protein and fats, slow-burning carbohydrates, and 28 essential vitamins and minerals that are then mixed with purified water and bottled to ensure that every citizen remains happy and, most importantly, healthy.";
		model="BastionMod\BastionVendor_Data\AIONBox\box.p3d";
		weight=5000;
		itemSize[]={9,6};
		itemsCargoSize[]={9,6};
		itemBehaviour=0;
		hiddenSelections[] = 
		{
			"all"
		};
		hiddenSelectionsTextures[] = 
		{
			"BastionMod\BastionVendor_Data\AIONBox\data\aionbox_co.paa"
		};
		hiddenSelectionsMaterials[] = 
		{
			"BastionMod\BastionVendor_Data\AIONBox\data\aionbox.rvmat"
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
						{
							1.0,
							{"BastionMod\BastionVendor_Data\AIONBox\data\aionbox.rvmat"}
						},
						{
							0.7,
							{"BastionMod\BastionVendor_Data\AIONBox\data\aionbox.rvmat"}
						},
						{
							0.5,
							{"DZ\characters\data\generic_damage.rvmat"}
						},
						{
							0.3,
							{"DZ\characters\data\generic_damage.rvmat"}
						},
						{
							0.0,
							{"DZ\characters\data\generic_destruct.rvmat"}
						}
					};
				};
			};
		};
	};
	class BRP_AIONBoxes1: HouseNoDestruct
	{
		scope = 1;
		model = "\BastionMod\BastionVendor_Data\AIONBox\boxes_stack1.p3d";
	};
	class BRP_AIONBoxes2: HouseNoDestruct
	{
		scope = 1;
		model = "\BastionMod\BastionVendor_Data\AIONBox\boxes_stack2.p3d";
	};
	class BRP_AIONBoxes3: HouseNoDestruct
	{
		scope = 1;
		model = "\BastionMod\BastionVendor_Data\AIONBox\boxes_stack3.p3d";
	};
};
