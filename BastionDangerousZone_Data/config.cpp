class CfgPatches
{
	class BastionDangerousZone_Data
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] =
		{
			"DZ_Data"
		};
	};
};

class CfgMods
{
	class BastionDangerousZone_Data
	{
		dir = "BastionDangerousZone_Data";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "BastionDangerousZone_Data";
		credits = "";
		author = "";
		authorID = "0";
		version = "1.0";
		extra = 0;
		type = "mod";
		dependencies[] = {"World"};
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = {"BastionMod/BastionDangerousZone_Data/scripts/4_World"};
			};
		};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class BRP_Dosimeter: Inventory_Base
	{
		scope = 2;
		displayName = "Dosimeter";
		descriptionShort = "A radiation dosimeter is a device that measures dose uptake of external ionizing radiation. It is worn by the person being monitored when used as a personal dosimeter, and is a record of the radiation dose received.";
		model = "BastionMod\BastionDangerousZone_Data\dosimeter\geiger.p3d";
		rotationFlags = 2;
		weight = 500;
		absorbency = 0.0;
		itemSize[] = {3,2};
		attachments[]=
		{
			"BatteryD"
		};
		hiddenSelections[]=
		{
			"all"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionDangerousZone_Data\dosimeter\data\geiger_ca.paa"
		};
		class EnergyManager
		{
			hasIcon=1;
			autoSwitchOff=1;
			energyUsagePerSecond=0.0049999999;
			plugType=1;
			attachmentAction=1;
			updateInterval=30;
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 60;
					healthLevels[] =
					{
						{1.0,{"BastionMod\BastionDangerousZone_Data\dosimeter\data\geiger.rvmat"}},
						{0.7,{"BastionMod\BastionDangerousZone_Data\dosimeter\data\geiger.rvmat"}},
						{0.5,{"BastionMod\BastionDangerousZone_Data\dosimeter\data\geiger_damage.rvmat"}},
						{0.3,{"BastionMod\BastionDangerousZone_Data\dosimeter\data\geiger_damage.rvmat"}},
						{0.0,{"BastionMod\BastionDangerousZone_Data\dosimeter\data\geiger_destruct.rvmat"}}
					};
				};
			};
		};
		class MeleeModes
		{
			class Default
			{
				ammo = "MeleeLightBlunt";
				range = 1.0;
			};
			class Heavy
			{
				ammo = "MeleeLightBlunt_Heavy";
				range = 1.0;
			};
			class Sprint
			{
				ammo = "MeleeLightBlunt_Heavy";
				range = 2.8;
			};
		};
	};

	class BRP_Dosimeter_Opal : BRP_Dosimeter
	{
		scope = 2;
		displayName = "Dosimeter Opal";		
		itemSize[] = {2,3};
		model = "BastionMod\BastionDangerousZone_Data\detectors\detector_opal.p3d";		
		hiddenSelections[]=
		{
			"base",
			"screen"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionDangerousZone_Data\detectors\data\detectors_co.paa",
			"BastionMod\BastionDangerousZone_Data\detectors\data\detectors_screen_co.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 60;
					healthLevels[] =
					{
						{1.0,{"BastionMod\BastionDangerousZone_Data\detectors\data\detectors.rvmat"}},
						{0.7,{"BastionMod\BastionDangerousZone_Data\detectors\data\detectors.rvmat"}},
						{0.5,{"BastionMod\BastionDangerousZone_Data\detectors\data\detectors_damage.rvmat"}},
						{0.3,{"BastionMod\BastionDangerousZone_Data\detectors\data\detectors_damage.rvmat"}},
						{0.0,{"BastionMod\BastionDangerousZone_Data\detectors\data\detectors_destruct.rvmat"}}
					};
				};
			};
		};
	};
	class BRP_Dosimeter_Osa : BRP_Dosimeter_Opal
	{
		scope = 2;
		displayName = "Dosimeter Osa";
		model = "BastionMod\BastionDangerousZone_Data\detectors\detector_osa.p3d";
	};
	class BRP_Dosimeter_Sova : BRP_Dosimeter_Opal
	{
		scope = 2;
		displayName = "Dosimeter Sova";
		model = "BastionMod\BastionDangerousZone_Data\detectors\detector_sova.p3d";
	};
	class BRP_Dosimeter_Zov : BRP_Dosimeter_Opal
	{
		scope = 2;
		displayName = "Dosimeter Zov";
		model = "BastionMod\BastionDangerousZone_Data\detectors\detector_zov.p3d";
	};
};