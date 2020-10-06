class CfgPatches
{
	class DZ_Base_Almara
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Scripts"
		};
	};
};
class CfgVehicles
{
	class Container_Base;
	class Base_Almara: Container_Base
	{
		scope=2;		
		displayName="Wardrobe Storage";
		descriptionShort="An Armoire, that can hold a loadout and also has some storage.   Dismantle with a pliers or screwdriver.  Created by Axobi";
		model="DZ\structures\furniture\cases\case_a\case_a.p3d";
		itemSize[]={10,8};		
		weight=50000;
		canBeDigged=0;
		bounding="BSphere";
		overrideDrawArea="3.0";
		placement="ForceSlopeOnTerrain";
		carveNavmesh=0;
		physLayer="item_large";
		class Cargo
		{
			itemsCargoSize[]={10,6};
			openable=0;
			allowOwnedCargoManipulation=1;
		};
		attachments[]=
		{
			"Shoulder1",
			"Shoulder2",
			"Melee",
			"Pistol",
			"Armband",
			"Hips",
			"Back",
			"Body",
			"Legs",
			"Feet",
			"Eyewear",
			"Mask",
			"Gloves",
			"Vest",
			"Headgear",
			"Knife"
		};
		class GUIInventoryAttachmentsProps
		{
			class Rifle_Storage
			{
				name="Weapons";
				description="";
				attachmentSlots[]=
				{
					"Shoulder1",
					"Shoulder2",
					"Pistol",
					"Knife",
					"Melee"
				};
			};
			class Loadout_Storage
			{
				name="Loadout";
				description="";
				attachmentSlots[]=
				{
					"Headgear",
					"Eyewear",
					"Mask",
					"Armband",
					"Gloves",
					"Body",
					"Vest",
					"Back",
					"Hips",
					"Legs",
					"Feet"
				};
			};
		};
	};
	class Base_Almara_Kit_Holo: Container_Base
	{
		scope = 0;
		displayName = "Wardrobe Storage HOLO";
		model="DZ\structures\furniture\cases\case_a\case_a.p3d";
	};
};