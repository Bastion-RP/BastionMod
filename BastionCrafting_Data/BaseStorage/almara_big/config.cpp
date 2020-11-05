class CfgPatches
{
	class DZ_Base_Almara_Large
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
	class Base_Almara_Large: Container_Base
	{
		scope=2;
		displayName="Large Wardrobe Storage";
		descriptionShort="A Large Armoire, that can hold a loadout and also has some storage.   Dismantle with pliers or a screwdriver  Created by Axobi";
		model="DZ\structures\furniture\cases\almara\almara.p3d";
		itemSize[]={10,8};		
		weight=50000;
		canBeDigged=0;
		bounding="BSphere";
		overrideDrawArea="3.0";
		placement="ForceSlopeOnTerrain";
		carveNavmesh=1;
		physLayer="item_large";
		class Cargo
		{
			itemsCargoSize[]={10,8};
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
	class Base_Almara_Large_Kit_Holo: Container_Base
	{
		scope = 0;
		displayName = "Wardrobe Storage HOLO";
		model="DZ\structures\furniture\cases\almara\almara.p3d";
	};
};