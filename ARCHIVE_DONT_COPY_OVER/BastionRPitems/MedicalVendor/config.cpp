class CfgPatches
{
	class BastionRP_Items
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]={"DZ_Data"};
	};
};

class CfgVehicles
{
	class HouseNoDestruct;
	class Bastion_Medical_Vendor_Color: HouseNoDestruct
	{
		scope = 0;
		displayName = "Medical Supply Vendor";
		descriptionShort = "One stop source for all your medical needs.";
		itemSize[]={15,20};
	};

	class Bastion_Medical_Vendor1: Bastion_Medical_Vendor_Color
	{
		scope = 2;
		model = "\BastionRPitems\MedicalVendor\MedicalVendor_V1_noBlood.p3d";
	};
	
	class Bastion_Medical_Vendor1_Bloody: Bastion_Medical_Vendor_Color
	{
		scope = 2;
		model = "\BastionRPitems\MedicalVendor\MedicalVendor_V1.p3d";
	};
	
	class Bastion_Medical_Vendor2: Bastion_Medical_Vendor_Color
	{
		scope = 2;
		model = "\BastionRPitems\MedicalVendor\MedicalVendor_V2_noBlood.p3d";
	};
	
	class Bastion_Medical_Vendor2_Bloody: Bastion_Medical_Vendor_Color
	{
		scope = 2;
		model = "\BastionRPitems\MedicalVendor\MedicalVendor_V2.p3d";
	};
	
	class Bastion_Medical_Vendor3: Bastion_Medical_Vendor_Color
	{
		scope = 2;
		model = "\BastionRPitems\MedicalVendor\MedicalVendor_V3.p3d";
	};
	
	class Bastion_Medical_Vendor4: Bastion_Medical_Vendor_Color
	{
		scope = 2;
		model = "\BastionRPitems\MedicalVendor\MedicalVendor_V4.p3d";
	};
};