class CfgPatches
{
	class BRP_rifleholster
	{
		units[]=
		{
		
		};
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
	class BRP_rifleholster_colorbase: Clothing
	{
		displayName="rifleholster";
		descriptionShort="The scabbard is thickly padded for weapon protection.";
		model="\BastionMod\BastionClothing\rifleholster\rifleholster_g.p3d";
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
		itemSize[]={3,8};
		itemsCargoSize[]={4,2};
		weight=1000;
		absorbency=0.2;
		heatIsolation=0.13;
		repairableWithKits[]={5,3};
		repairCosts[]={30,25};
		canBeDigged=1;
		soundAttType="Outdoor";
		attachments[]=
		{
			"VestPouch",
			"shoulder",
			"Chemlight"
		};
		hiddenSelections[]=
		{
			"zbytek"
		};
		class ClothingTypes
		{
			male="\BastionMod\BastionClothing\rifleholster\rifleholster.p3d";
			female="\BastionMod\BastionClothing\rifleholster\rifleholster.p3d";
		};
	};
	class BRP_rifleholster_black : BRP_rifleholster_colorbase
	{
	scope = 2;
	displayName="Rifleholster black";
	hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\rifleholster\data\rifleholster_co.paa"
		};
	};
	class BRP_rifleholster_camo : BRP_rifleholster_colorbase
	{
	scope = 2;
	displayName="Rifleholster camo";
	hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\rifleholster\data\rifleholster_camo_co.paa"
		};
	};
	class BRP_rifleholster_camo_ucp : BRP_rifleholster_colorbase
	{
	scope = 2;
	displayName="Rifleholster camo ucp";
	hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\rifleholster\data\rifleholster_camo_v2_co.paa"
		};
	};
	class BRP_rifleholster_tan : BRP_rifleholster_colorbase
	{
	scope = 2;
	displayName="Rifleholster tan";
	hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\rifleholster\data\rifleholster_tan_co.paa"
		};
	};
	class BRP_rifleholster_snow : BRP_rifleholster_colorbase
	{
	scope = 2;
	displayName="Rifleholster snow";
	hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\rifleholster\data\rifleholster_snow_co.paa"
		};
	};
	class BRP_rifleholster_TTsKO : BRP_rifleholster_colorbase
	{
	scope = 2;
	displayName="Rifleholster TTsKO";
	hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\rifleholster\data\rifleholster_camo3_co.paa"
		};
	};
	class BRP_rifleholster_leatherengraved : BRP_rifleholster_colorbase
	{
	scope = 2;
	displayName="Rifleholster leather engraved";
	model="\BastionMod\BastionClothing\rifleholster\rifleholster_leather_g.p3d";
	hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\rifleholster\data\leather\rifleholster_leather_CO.paa"
		};
	class ClothingTypes
		{
			male="\BastionMod\BastionClothing\rifleholster\rifleholster_leather.p3d";
			female="\BastionMod\BastionClothing\rifleholster\rifleholster_leather.p3d";
		};
	};
};