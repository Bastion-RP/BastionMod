class CfgPatches
{
	class BRP_Magazine
	{
		units[]=
		{
			"BRP_Magazine"
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Gear_Books"
		};
	};
};

class CfgVehicles
{		
	class ItemBook;
	class BRP_Magazine: ItemBook
	{
		scope=0; //should be 0 because it's a base class for inheriting from it
		model="\BastionMod\BastionCrafting_Data\BRP_Magazine\BRP_Magazine.p3d"; //path to the model
		displayName="Crafted Magazine"; //name, actually
		descriptionShort="A Crafted Magazine to read"; //description
		itemSize[]={2,2}; //item size
		weight = 500; //weight? 
		rotationFlags=17; //how this item will be rotated on respawn and when it was dropped
		absorbency=0.9; //water absorbency
		physLayer="item_small"; // small = no collision
		hiddenSelections[]= // selection for retexturing
		{
			"all"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionCrafting_Data\BRP_Magazine\textures\brp_magazine_co.paa" // path to the texture
		};
		class DamageSystem //damage states
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
					healthLevels[]=
					{
						{1.0,{"BastionMod\BastionCrafting_Data\BRP_Magazine\data\brp_magazine.rvmat"}},
						{0.7,{"BastionMod\BastionCrafting_Data\BRP_Magazine\data\brp_magazine.rvmat"}},
						{0.5,{"BastionMod\BastionCrafting_Data\BRP_Magazine\data\brp_magazine_damage.rvmat"}},
						{0.3,{"BastionMod\BastionCrafting_Data\BRP_Magazine\data\brp_magazine_damage.rvmat"}},
						{0.0,{"BastionMod\BastionCrafting_Data\BRP_Magazine\data\brp_magazine_destruct.rvmat"}}
					};
				};
			};
		};
	};
	class BRP_CraftingBook_ARBible: BRP_Magazine // we are inherit every parameter from our base class above, we don't need to fill every parameter now
	{
		scope=2; //2 because it's real item for gameplay
		displayName="The ArmaLite Bible"; //name, actually
		descriptionShort="Your one stop shop for all things ARs."; //description
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionCrafting_Data\BRP_Magazine\textures\brp_magazine_co.paa" // path to the NEW texture
		};
	};
	class BRP_CraftingBook_AKManual: BRP_Magazine // we are inherit every parameter from our base class above, we don't need to fill every parameter now
	{
		scope=2; //2 because it's real item for gameplay
		displayName="B33 Vol. IV - Kalashnikov"; //name, actually
		descriptionShort="Volume IV - ''Kalashnikov'' is a standalone handcrafting instruction manual detailing the full creation of three timeless weapons made by Kalashnikov Concern (previously Izhmash): the iconic AK-74 (5.45x39), the shortened AKS-74U variant (5.45x39), and the modernised AK-74M (7.62x39)."; //description
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionCrafting_Data\BRP_Magazine\textures\brp_magazine_co_kalashnikov.paa" // path to the NEW texture
		};
	};
	class BRP_CraftingBook_INTERPOLPistols: BRP_Magazine // we are inherit every parameter from our base class above, we don't need to fill every parameter now
	{
		scope=2; //2 because it's real item for gameplay
		displayName="INTERPOL Armorer's Guide - Vol. 1"; //name, actually
		descriptionShort="INTERPOL guide that provides schematics and instructions on the construction and maintenance of service pistols used by police and special forces across Europe and the United States."; //description
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionCrafting_Data\BRP_Magazine\textures\brp_magazine_co_kalashnikov.paa" // path to the NEW texture
		};
	};
};