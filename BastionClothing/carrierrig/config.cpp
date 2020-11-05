class CfgPatches
{
	class BRP_carrierrig
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Characters_Backpacks"
		};
	};	
};
class CfgVehicles
{
	class Clothing;
	class BRP_carrierrig: Clothing
	{
		scope=2;
		displayName="Backpack carrier-rig";
		descriptionShort="A rig for heavy carrying, takes many different attachments, effectively makes every backpack modular";
		model="\BastionMod\BastionClothing\carrierrig\carrierrig_g.p3d";
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
		rotationFlags=0;
		itemSize[]={9,10};
		itemsCargoSize[]={0,0};
		weight=3000;
		absorbency=0.2;
		heatIsolation=0.13;
		repairableWithKits[]={5,3};
		repairCosts[]={30,25};
		canBeDigged=1;
		soundAttType="Outdoor";
		attachments[]=
		{
			"Back",
			"protectorcase",
			"flashlight",
			"waterproofbag",
			"Chemlight",
			"CookingEquipment"
		};
		hiddenSelections[]=
		{
			"zbytek",
			"camoground"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\carrierrig\data\carrierrig_co.paa"
		};
		class ClothingTypes
		{
			male="\BastionMod\BastionClothing\carrierrig\carrierrig.p3d";
			female="\BastionMod\BastionClothing\carrierrig\carrierrig.p3d";
		};
	};
};
class CfgNonAIVehicles
{
	class ProxyAttachment;
	class Proxybackpack: ProxyAttachment
	{
		scope=2;
		inventorySlot[]=
		{
			"Back"
		};
		model="\BastionMod\BastionClothing\carrierrig\proxy\backpack.p3d";
	};
};