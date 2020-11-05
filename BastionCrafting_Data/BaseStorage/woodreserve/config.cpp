class CfgPatches
{
	class DZ_Base_WoodStorage
	{
		units[]=
		{
			"WoodStorage"
		};
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
	class Base_WoodStorage: Container_Base
	{
		scope=2;
		displayName="Wood Storage";
		descriptionShort="Wood, and misc storage.   Dismantle with pliers or a screwdriver  Created by Axobi";
		model="DZ\structures\residential\misc\misc_woodreserve.p3d";
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
			itemsCargoSize[]={10,6};
			openable=0;
			allowOwnedCargoManipulation=1;
		};
		attachments[]=
		{
			"Material_WoodenLogs",
			"Material_L1_WoodenLogs",
			"Material_L2_WoodenLogs",
			"Material_L3_WoodenLogs",
			"Material_WoodenPlanks",
			"Material_L1_WoodenPlanks",
			"Material_L1W1_WoodenPlanks",
			"Material_L1W2_WoodenPlanks",
			"Material_L1W3_WoodenPlanks",
			"Material_WoodenPlanks",
			"Material_L1_WoodenPlanks",
			"Material_L1W1_WoodenPlanks",
			"Material_L1W2_WoodenPlanks",
			"Material_L1W3_WoodenPlanks",
			"Material_L2_WoodenPlanks",
			"Material_L2W1_WoodenPlanks",
			"Material_L2W2_WoodenPlanks",
			"Firewood",
			"WoodenStick",
			"CookingTripod",
			"CookingEquipment",
			"Stones",
			"Rags",
			"MedicalBandage",
			"Paper",
			"Book",
			"OakBark",
			"BirchBark",
			"Melee",
			"Knife"
		};
		class GUIInventoryAttachmentsProps
		{
			class Log_Storage
			{
				name="Log Storage";
				description="";
				attachmentSlots[]=
				{
					"Material_WoodenLogs",
					"Material_L1_WoodenLogs",
					"Material_L2_WoodenLogs",
					"Material_L3_WoodenLogs",
				};
				icon="woodenlog";
			};
			class Plank_Storage
			{
				name="Plank Storage";
				description="";
				attachmentSlots[]=
				{
					"Material_WoodenPlanks",
					"Material_L1_WoodenPlanks",
					"Material_L1W1_WoodenPlanks",
					"Material_L1W2_WoodenPlanks",
					"Material_L1W3_WoodenPlanks",
					"Material_L2_WoodenPlanks",
					"Material_L2W1_WoodenPlanks",
					"Material_L2W2_WoodenPlanks"
				};
				icon="planks";
			};
			class Kindling_Storage
			{
				name="Fuel and Kindling";
				description="";
				attachmentSlots[]=
				{
					"Firewood",
					"WoodenStick",
					"Rags",
					"MedicalBandage",
					"Paper",
					"Book",
					"OakBark",
					"BirchBark"
				};
				icon="firewood";
			};
			class Misc_Storage
			{
				name="Misc Storage";
				description="";
				attachmentSlots[]=
				{
					"CookingTripod",
					"CookingEquipment",
					"Stones",
					"Melee",
					"Knife"
				};
				icon="missing";
			};
		};
	};
	class Base_WoodStorage_Kit_Holo: Container_Base
	{
		scope = 0;
		displayName = "WoodStorage HOLO";
		model="DZ\structures\residential\misc\misc_woodreserve.p3d";
	};
};
