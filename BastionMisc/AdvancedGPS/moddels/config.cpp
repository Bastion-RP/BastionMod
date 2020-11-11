class CfgPatches 
{
	class AdvancedGPS_Base 
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
	};
};


class CfgVehicles	
{
	class Inventory_Base;	// External class reference
	class GpsGarmin : Inventory_Base 
	{
		scope = 0;
		displayName = "GPS";
		descriptionShort = "GPS (Global Positioning System) глобальная позиционирующая система — спутниковая система навигации, обеспечивающая измерение расстояния, времени и определяющая местоположение во всемирной системе координат WGS 84. Позволяет почти при любой погоде определять местоположение в любом месте земли.";
		model = "BastionMod\BastionMisc\AdvancedGPS\moddels\gpsname_1\gps.p3d";
		weight = 260;
		//oldpower = 0;
		absorbency = 0.5;
		itemSize[] = {1, 3};
		rotationFlags = 16;
		attachments[] = {"BatteryD"};
		repairableWithKits[] = {7};
		repairCosts[] = {30.0, 25.0};
	
		class EnergyManager 
		{
			hasIcon = 1;
			energyUsagePerSecond = 0.01;
			plugType = 1;
			attachmentAction = 1;
		};
	
		class DamageSystem 
		{
			class GlobalHealth 
			{
				class Health 
				{
					hitpoints = 50;
					healthLevels[] = {{1.01, {"BastionMod\BastionMisc\AdvancedGPS\moddels\gpsname_1\gps.rvmat"}}, {0.7, {"BastionMod\BastionMisc\AdvancedGPS\moddels\gpsname_1\gps.rvmat"}}, {0.5, {"BastionMod\BastionMisc\AdvancedGPS\moddels\gpsname_1\gps_damage.rvmat"}}, {0.3, {"BastionMod\BastionMisc\AdvancedGPS\moddels\gpsname_1\gps_damage.rvmat"}}, {0.01, {"BastionMod\BastionMisc\AdvancedGPS\moddels\gpsname_1\gps_destruct.rvmat"}}};
				};
			};
		};
	};
		
	class GpsRC : Inventory_Base 
	{
		scope = 2;
		displayName = "GPS RC";
		descriptionShort = "GPS (Global Positioning System) глобальная позиционирующая система — спутниковая система навигации, обеспечивающая измерение расстояния, времени и определяющая местоположение во всемирной системе координат WGS 84. Позволяет почти при любой погоде определять местоположение в любом месте земли.";
		model = "BastionMod\BastionMisc\AdvancedGPS\moddels\gpsname_2\RC.p3d";
		weight = 260;
		forceFarBubble="true";
		//oldpower = 0;
		absorbency = 0.5;
		itemSize[] = {2, 2};
		attachments[] = {"BatteryD"};
		repairableWithKits[] = {7};
		repairCosts[] = {30.0, 25.0};
		class EnergyManager 
		{
			hasIcon = 1;
			energyUsagePerSecond = 0.01;
			plugType = 1;
			attachmentAction = 1;
		};
		
		class DamageSystem 
		{
			class GlobalHealth 
			{
				class Health 
				{
					hitpoints = 50;
					healthLevels[] = {{1.01, {"BastionMod\BastionMisc\AdvancedGPS\moddels\gpsname_2\rc.rvmat"}}, {0.7, {"BastionMod\BastionMisc\AdvancedGPS\moddels\gpsname_2\rc.rvmat"}}, {0.5, {"BastionMod\BastionMisc\AdvancedGPS\moddels\gpsname_2\rc_damage.rvmat"}}, {0.3, {"BastionMod\BastionMisc\AdvancedGPS\moddels\gpsname_2\rc_damage.rvmat"}}, {0.01, {"BastionMod\BastionMisc\AdvancedGPS\moddels\gpsname_2\rc_destruct.rvmat"}}};
				};
			};
		};
	};
};
