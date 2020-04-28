////////////////////////////////////////////////////////////////////
//DeRap: P:\BastionMod\BastionVendor_Data\AIONVendor\config.bin
//Produced from mikero's Dos Tools Dll version 7.60
//https://mikero.bytex.digital/Downloads
//'now' is Tue Apr 28 21:02:08 2020 : 'file' last modified on Tue Apr 28 21:02:08 2020
////////////////////////////////////////////////////////////////////

#define _ARMA_

class CfgPatches
{
	class BastionVendor
	{
		units[] = {"NCC_AionVendor","Bastion_Medical_Vendor1","Bastion_Medical_Vendor1_Bloody","Bastion_Medical_Vendor2","Bastion_Medical_Vendor2_Bloody","Bastion_Medical_Vendor3","Bastion_Medical_Vendor4"};
		weapons[] = {};
		requiredVersion = 1;
		requiredAddons[] = {"DZ_Data"};
		author = "Swade_93";
		name = "BastionVendor";
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class NCC_AionVendor: Inventory_Base
	{
		scope = 2;
		displayName = "Vending Machine";
		descriptionShort = "Vending Machine";
		model = "\BastionMod\BastionVendor_Data\AIONVendor\Aion_Vendor.p3d";
		weight = 5000;
		itemBehaviour = 0;
		itemSize[] = { 5, 5 };
		carveNavmesh = 1;
		bounding="BSphere";
		physLayer="item_large";
	};
	class Bastion_Medical_Vendor_Color: Inventory_Base
	{
		scope = 0;
		displayName = "Medical Supply Vendor";
		descriptionShort = "One stop source for all your medical needs.";
		itemSize[] = {15,20};
	};
	class Bastion_Medical_Vendor1: Bastion_Medical_Vendor_Color
	{
		scope = 2;
		model = "\BastionMod\BastionVendor_Data\MedicalVendor\MedicalVendor_V1_noBlood.p3d";
	};
	class Bastion_Medical_Vendor1_Bloody: Bastion_Medical_Vendor_Color
	{
		scope = 2;
		model = "\BastionMod\BastionVendor_Data\MedicalVendor\MedicalVendor_V1.p3d";
	};
	class Bastion_Medical_Vendor2: Bastion_Medical_Vendor_Color
	{
		scope = 2;
		model = "\BastionMod\BastionVendor_Data\MedicalVendor\MedicalVendor_V2_noBlood.p3d";
	};
	class Bastion_Medical_Vendor2_Bloody: Bastion_Medical_Vendor_Color
	{
		scope = 2;
		model = "\BastionMod\BastionVendor_Data\MedicalVendor\MedicalVendor_V2.p3d";
	};
	class Bastion_Medical_Vendor3: Bastion_Medical_Vendor_Color
	{
		scope = 2;
		model = "\BastionMod\BastionVendor_Data\MedicalVendor\MedicalVendor_V3.p3d";
	};
	class Bastion_Medical_Vendor4: Bastion_Medical_Vendor_Color
	{
		scope = 2;
		model = "\BastionMod\BastionVendor_Data\MedicalVendor\MedicalVendor_V4.p3d";
	};
};
