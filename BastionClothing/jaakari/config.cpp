	class CfgPatches
{
	class BRP_jaakari
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Characters_Backpacks"
		};
	};	
};
class CfgVehicles
{
	class Clothing;
	class BRP_jaakari_Colorbase: Clothing
	{
		scope=0;
		displayName="jaakari with pouches";
		model="\BastionMod\BastionClothing\jaakari\jaakari_g.p3d";
		inventorySlot[]=
		{
			"Back"
		};
		simulation="clothing";
		vehicleClass="Clothing";
		itemInfo[]=
		{
			"Clothing",
			"Back"
		};
		rotationFlags=16;
		itemSize[]={7,8};
		itemsCargoSize[]={8,8};
		weight=1600;
		absorbency=0.2;
		heatIsolation=0.13;
		repairableWithKits[]={5,3};
		repairCosts[]={30,25};
		canBeDigged=1;
		soundAttType="Outdoor";
		attachments[]=
		{
			"Belt_Left",
			"WalkieTalkie",
			"flashlight",
			"Chemlight",
			"CookingEquipment"
		};
		hiddenSelections[]=
		{
			"zbytek"
		};
		class ClothingTypes
		{
			male="\BastionMod\BastionClothing\jaakari\jaakari.p3d";
			female="\BastionMod\BastionClothing\jaakari\jaakari.p3d";
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
					healthLevels[]=
					{
						
						{
							1.000000000,
							
							{
								"BastionMod\BastionClothing\jaakari\data\jaakari.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"BastionMod\BastionClothing\jaakari\data\jaakari.rvmat"
							}
						},
						
						{
							0.50000000,
							
							{
								"BastionMod\BastionClothing\jaakari\data\jaakari_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"BastionMod\BastionClothing\jaakari\data\jaakari_damage.rvmat"
							}
						},
						
						{
							0.00000000,
							
							{
								"BastionMod\BastionClothing\jaakari\data\jaakari_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class BRP_jaakari_simple_Colorbase: BRP_jaakari_Colorbase
	{
		displayName="jaakari";
		model="\BastionMod\BastionClothing\jaakari\jaakari_simple_g.p3d";
		itemSize[]={5,8};
		itemsCargoSize[]={5,8};
		class ClothingTypes
		{
			male="\BastionMod\BastionClothing\jaakari\jaakari_simple.p3d";
			female="\BastionMod\BastionClothing\jaakari\jaakari_simple.p3d";
		};
	};
	class BRP_jaakari_brown: BRP_jaakari_Colorbase
	{
	scope = 2;
	displayName="Jaakari brown";
	hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\jaakari\data\Jaakari_backpack_lp_brown_CO.paa"
		};
	};
	class BRP_jaakari_camo: BRP_jaakari_Colorbase
	{
	scope = 2;
	displayName="Jaakari camo";
	hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\jaakari\data\Jaakari_backpack_lp_camo_CO.paa"
		};
	};
	class BRP_jaakari_black: BRP_jaakari_Colorbase
	{
	scope = 2;
	displayName="Jaakari black";
	hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\jaakari\data\Jaakari_backpack_lp_black_CO.paa"
		};
	};
	class BRP_jaakari_tan: BRP_jaakari_Colorbase
	{
	scope = 2;
	displayName="Jaakari tan";
	hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\jaakari\data\Jaakari_backpack_lp_tan_CO.paa"
		};
	};
	class BRP_jaakari_simple_brown: BRP_jaakari_simple_Colorbase
	{
	scope = 2;
	displayName="Jaakari brown";
	hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\jaakari\data\Jaakari_backpack_lp_brown_CO.paa"
		};
	};
	class BRP_jaakari_simple_camo: BRP_jaakari_simple_Colorbase
	{
	scope = 2;
	displayName="Jaakari camo";
	hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\jaakari\data\Jaakari_backpack_lp_camo_CO.paa"
		};
	};
	class BRP_jaakari_simple_black: BRP_jaakari_simple_Colorbase
	{
	scope = 2;
	displayName="Jaakari black";
	hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\jaakari\data\Jaakari_backpack_lp_black_CO.paa"
		};
	};
	class BRP_jaakari_simple_tan: BRP_jaakari_simple_Colorbase
	{
	scope = 2;
	displayName="Jaakari tan";
	hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\jaakari\data\Jaakari_backpack_lp_tan_CO.paa"
		};
	};
};
