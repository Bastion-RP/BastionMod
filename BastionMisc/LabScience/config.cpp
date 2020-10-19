//DayZ assets that were coded to allow for better functionality as roleplay items
class CfgPatches
{
	class BRP_LabScience
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Gear_Optics",
			"DZ_Weapons_Melee",
			"DZ_Gear_Tools",
			"DZ_Gear_Crafting"
		};
	};
};
class CfgSlots
{
	class Slot_Material_BloodBagFull
	{
		name="Material_BloodBagFull";
		displayName="Full BloodBag";
		selection="Material_BloodBagFull";
		ghostIcon="missing";
		show="false";
		stackMax=2;
	};
	class Slot_Material_Petridish
	{
		name="Material_Petridish";
		displayName="Petridish";
		selection="Material_Petridish";
		ghostIcon="missing";
		show="false";
		stackMax=2;
	};
};
class cfgVehicles
{
	class Inventory_Base;
	class BRP_petridish: Inventory_Base
	{
		scope=2;
		displayName="Petridish";
		descriptionShort="A little glass dish for holding that really small something.";
		model="\dz\structures\furniture\school_equipment\lab_petri_dish.p3d";
		weight=0;
		interactionWeight=1;
		itemSize[]={2,1};
		inventorySlot="Material_Petridish";
		hiddenSelections[]=
		{
			"component1"
		};
		hiddenSelectionsTextures[]=
		{
			"\DZ\structures\furniture\school_equipment\data\lab_set_ca.paa",
			"\DZ\structures\furniture\school_equipment\data\lab_set_ca.paa",
			"\DZ\structures\furniture\school_equipment\data\lab_set_ca.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"\DZ\data\data\penetration\glass.rvmat",
			"\DZ\data\data\penetration\glass.rvmat",
			"\DZ\data\data\penetration\glass.rvmat"
		};
	};
	class BloodBagFull: Inventory_Base
	{
		inventorySlot="Material_BloodBagFull";
	};
	class BRP_microscope: Inventory_Base
	{
		scope=2;
		displayName="Microscope";
		descriptionShort="It makes really small things not so small to the naked eye... No, it won't help with that.";
		model="\dz\structures\furniture\school_equipment\lab_microscope.p3d";
		itemSize[]={3,3};
		weight=100;
		attachments[]=
		{
			"Material_Petridish",
			"Material_BloodBagFull"
		};
		hiddenSelections[]=
		{
			"component1"
		};
		hiddenSelectionsTextures[]=
		{
			"\DZ\structures\furniture\school_equipment\data\lab_set_ca.paa",
			"\DZ\structures\furniture\school_equipment\data\lab_set_ca.paa",
			"\DZ\structures\furniture\school_equipment\data\lab_set_ca.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"\DZ\structures\furniture\school_equipment\data\lab_set.rvmat"
		};
		class GUIInventoryAttachmentsProps
		{
			class Materials
			{
				name="Research Items";
				description="";
				attachmentSlots[]=
				{
					"Material_Petridish",
					"Material_BloodBagFull"
				};
				icon="missing";
			};
		};
	};
	class BRP_patientmonitor: Inventory_Base
	{
		scope=2;
		displayName="Patient Monitor";
		descriptionShort="Patient Monitor";
		model="\DZ\structures\furniture\medical\patient_monitor\patient_monitor.p3d";
		itemSize[]={3,10};
		itemsCargoSize[]={2,2};
		weight=100;
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"\DZ\structures\furniture\medical\patient_monitor\data\patient_monitor.paa",
			"\DZ\structures\furniture\medical\patient_monitor\data\patient_monitor.paa",
			"\DZ\structures\furniture\medical\patient_monitor\data\patient_monitor.paa"
		};
		itemBehaviour=2;
	};
	class BRP_medicaltable: Inventory_Base
	{
		scope=2;
		model="\DZ\structures\furniture\medical\medical_table\medical_table.p3d";
		itemSize[]={6,6};
		weight=100;
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"\DZ\structures\furniture\medical\medical_table\medical_table.paa",
			"\DZ\structures\furniture\medical\medical_table\medical_table.paa",
			"\DZ\structures\furniture\medical\medical_table\medical_table.paa"
		};
		itemBehaviour=2;
	};
	class BRP_lab_triplebeam: Inventory_Base
	{
		scope=2;
		model="\DZ\structures\furniture\school_equipment\lab_triplebeam.p3d";
		itemSize[]={3,3};
		weight=100;
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"\DZ\structures\furniture\school_equipment\lab_triplebeam.paa",
			"\DZ\structures\furniture\school_equipment\lab_triplebeam.paa",
			"\DZ\structures\furniture\school_equipment\lab_triplebeam.paa"
		};
		itemBehaviour=2;
	};
	class BRP_lab_vial: Inventory_Base
	{
		scope=2;
		model="\DZ\structures\furniture\school_equipment\lab_vial.p3d";
		itemSize[]={1,2};
		weight=100;
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"\DZ\structures\furniture\school_equipment\lab_vial.paa",
			"\DZ\structures\furniture\school_equipment\lab_vial.paa",
			"\DZ\structures\furniture\school_equipment\lab_vial.paa"
		};
		itemBehaviour=2;
	};
	class BRP_lab_beaker: Inventory_Base
	{
		scope=2;
		model="\DZ\structures\furniture\school_equipment\lab_volume_beaker.p3d";
		itemSize[]={1,2};
		weight=100;
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"\DZ\structures\furniture\school_equipment\lab_volume_beaker.paa",
			"\DZ\structures\furniture\school_equipment\lab_volume_beaker.paa",
			"\DZ\structures\furniture\school_equipment\lab_volume_beaker.paa"
		};
		itemBehaviour=2;
	};
	class BRP_lab_bunsen: Inventory_Base
	{
		scope=2;
		model="\DZ\structures\furniture\school_equipment\lab_bunsen.p3d";
		itemSize[]={2,2};
		weight=100;
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"\DZ\structures\furniture\school_equipment\lab_bunsen.paa",
			"\DZ\structures\furniture\school_equipment\lab_bunsen.paa",
			"\DZ\structures\furniture\school_equipment\lab_bunsen.paa"
		};
		itemBehaviour=2;
	};
	class BRP_lab_cylinderbeaker: Inventory_Base
	{
		scope=2;
		model="\DZ\structures\furniture\school_equipment\lab_cylinder_beaker.p3d";
		itemSize[]={2,2};
		weight=100;
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"\DZ\structures\furniture\school_equipment\lab_cylinder_beaker.paa",
			"\DZ\structures\furniture\school_equipment\lab_cylinder_beaker.paa",
			"\DZ\structures\furniture\school_equipment\lab_cylinder_beaker.paa"
		};
		itemBehaviour=2;
	};
	class BRP_lab_dropper: Inventory_Base
	{
		scope=2;
		model="\DZ\structures\furniture\school_equipment\lab_dropper.p3d";
		itemSize[]={2,2};
		weight=100;
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"\DZ\structures\furniture\school_equipment\lab_dropper.paa",
			"\DZ\structures\furniture\school_equipment\lab_dropper.paa",
			"\DZ\structures\furniture\school_equipment\lab_dropper.paa"
		};
		itemBehaviour=2;
	};
	class BRP_lab_erlenmeyerflask: Inventory_Base
	{
		scope=2;
		model="\DZ\structures\furniture\school_equipment\lab_erlenmeyer_flask.p3d";
		itemSize[]={2,2};
		weight=100;
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"\DZ\structures\furniture\school_equipment\lab_erlenmeyer_flask.paa",
			"\DZ\structures\furniture\school_equipment\lab_erlenmeyer_flask.paa",
			"\DZ\structures\furniture\school_equipment\lab_erlenmeyer_flask.paa"
		};
		itemBehaviour=2;
	};
};