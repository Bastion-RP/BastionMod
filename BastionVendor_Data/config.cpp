class CfgPatches
{
	class BastionVendor
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1;
		requiredAddons[] = {"DZ_Data"};
	};
};
class CfgVehicles
{
	class HouseNoDestruct;
	class BRP_VendingMachine_Base: HouseNoDestruct
	{
		scope = 0;
		model = "\BastionMod\BastionVendor_Data\VendingMachine\vendingmachine.p3d";
		hiddenSelections[] = 
		{
			"vendor",
			"buttons"
		};
		hiddenSelectionsTextures[] = 
		{
			"\BastionMod\BastionVendor_Data\VendingMachine\data\vendor_medicalv1_co.paa",			
			"\BastionMod\BastionVendor_Data\VendingMachine\data\buttons_co.paa"
		};
		hiddenSelectionsMaterials[] = 
		{
			"BastionMod\BastionVendor_Data\VendingMachine\data\vendor_medical.rvmat",			
			""
		};
	};

	class BRP_AionVendor: BRP_VendingMachine_Base
	{
		scope = 1;
		hiddenSelectionsTextures[] = 
		{
			"\BastionMod\BastionVendor_Data\VendingMachine\data\vendor_aion_co.paa",			
			"\BastionMod\BastionVendor_Data\VendingMachine\data\buttons_aion_co.paa"
		};
		hiddenSelectionsMaterials[] = 
		{
			"BastionMod\BastionVendor_Data\VendingMachine\data\vendor_aion.rvmat",			
			""
		};
	};
	class BRP_MedicalVendor1: BRP_VendingMachine_Base
	{
		scope = 1;		
		hiddenSelectionsTextures[] = 
		{
			"\BastionMod\BastionVendor_Data\VendingMachine\data\vendor_medicalv1_co.paa",			
			"\BastionMod\BastionVendor_Data\VendingMachine\data\buttons_co.paa"
		};
	};
	class BRP_MedicalVendor1_Bloody: BRP_VendingMachine_Base
	{
		scope = 1;
		hiddenSelectionsTextures[] = 
		{
			"\BastionMod\BastionVendor_Data\VendingMachine\data\vendor_medicalv1_blood_co.paa",			
			"\BastionMod\BastionVendor_Data\VendingMachine\data\buttons_blood_co.paa"
		};
	};
	class BRP_MedicalVendor2: BRP_VendingMachine_Base
	{
		scope = 1;
		hiddenSelectionsTextures[] = 
		{
			"\BastionMod\BastionVendor_Data\VendingMachine\data\vendor_medicalv2_co.paa",			
			"\BastionMod\BastionVendor_Data\VendingMachine\data\buttons_co.paa"
		};
	};
	class BRP_MedicalVendor2_Bloody: BRP_VendingMachine_Base
	{
		scope = 1;
		hiddenSelectionsTextures[] = 
		{
			"\BastionMod\BastionVendor_Data\VendingMachine\data\vendor_medicalv2_blood_co.paa",			
			"\BastionMod\BastionVendor_Data\VendingMachine\data\buttons_blood_co.paa"
		};
	};
	class BRP_MedicalVendor3: BRP_VendingMachine_Base
	{
		scope = 1;
		hiddenSelectionsTextures[] = 
		{
			"\BastionMod\BastionVendor_Data\VendingMachine\data\vendor_medicalv3_co.paa",			
			"\BastionMod\BastionVendor_Data\VendingMachine\data\buttons_co.paa"
		};
		hiddenSelectionsMaterials[] = 
		{
			"BastionMod\BastionVendor_Data\VendingMachine\data\vendor_medicalv3.rvmat",			
			""
		};
	};
	class BRP_MedicalVendor4: BRP_VendingMachine_Base
	{
		scope = 1;
		hiddenSelectionsTextures[] = 
		{
			"\BastionMod\BastionVendor_Data\VendingMachine\data\vendor_medicalv4_co.paa",			
			"\BastionMod\BastionVendor_Data\VendingMachine\data\buttons_co.paa"
		};
		hiddenSelectionsMaterials[] = 
		{
			"BastionMod\BastionVendor_Data\VendingMachine\data\vendor_medicalv3.rvmat",			
			""
		};
	};
};
