class CfgPatches
{
	class BRP_BUIS
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
	};
};

class CfgMods
{
	class BRP_BUIS
	{
		dir="BRP_BUIS";
		picture="";
		action="";
		hideName=1;
		hidePicture=1;
		name="BRP_BUIS";
		credits="Inkota";
		author="Inkota";
		authorID="0";
		version="1.0";
		extra=0;
		type="mod";
		dependencies[] = {"Game","World","Mission"};	
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = {"BRP_BUIS/Scripts/3_Game"};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {"BRP_BUIS/Scripts/4_world"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"BRP_BUIS/Scripts/5_Mission"};
			};
		};		
	};
};

class cfgVehicles
{
	class ItemOptics;
	class BRP_BUIS: ItemOptics
	{
		scope = 2;
		displayName = "Bobro Lowrider BUIS";
		descriptionShort = "Designed from the start with the goal of creating the perfect back up iron sights for SBR owners, the Bobro Engineering LowRider sights are the lowest profile and lightest weight sights on the market today. Sitting at roughly 2/10ths of an inch thick, these sights will not interfere with optics, night-vision, lights, or lasers, allowing shooters to make the maximize their accessories while maintaining back up sights.";
		model = "BastionMod\BastionGuns\BUIS\buis.p3d";
		rotationFlags = 17;
		reversed = 0;
		weight = 200;
		itemSize[] = {2,1};
		inventorySlot[] = {"weaponOptics"};
		simulation = "itemoptics";
		memoryPointCamera = "eyeScope";
		cameraDir = "cameraDir";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = 
					{
						{1.0,{"BastionMod\BastionGuns\BUIS\data\frontsight.rvmat","BastionMod\BastionGuns\BUIS\data\rearsight.rvmat"}},
						{0.7,{"BastionMod\BastionGuns\BUIS\data\frontsight.rvmat","BastionMod\BastionGuns\BUIS\data\rearsight.rvmat"}},
						{0.5,{"BastionMod\BastionGuns\BUIS\data\frontsight_damage.rvmat","BastionMod\BastionGuns\BUIS\data\rearsight_damage.rvmat"}},
						{0.3,{"BastionMod\BastionGuns\BUIS\data\frontsight_damage.rvmat","BastionMod\BastionGuns\BUIS\data\rearsight_damage.rvmat"}},
						{0.0,{"BastionMod\BastionGuns\BUIS\data\frontsight_destruct.rvmat","BastionMod\BastionGuns\BUIS\data\rearsight_destruct.rvmat"}}
					};
				};
			};
		};
		class OpticsInfo
		{
			memoryPointCamera = "eyeScope";
			cameraDir = "cameraDir";
			modelOptics = "-";
			opticsZoomMin = 0.5236;
			opticsZoomMax = 0.5236;
			opticsZoomInit = 0.5236;
			distanceZoomMin = 100;
			distanceZoomMax = 600;
			discreteDistance[] = {100,200,300,400,500,600};
			discreteDistanceInitIndex = 0;
			PPMaskProperties[] = {0.0,0.0,0.0,0.00};
			PPLensProperties[] = {0,0.0,0,0};
			PPBlurProperties = 0.0;
		};
		class AnimationSources
		{
			class attached
			{
				source = "user";
				initPhase = 0;
				animPeriod = 0.01;
			};
			class detached
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.01;
			};
		};		
	};
};
class CfgNonAIVehicles
{
	class ProxyAttachment;
	class ProxyOptic_BRP_BUIS: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "weaponOptics";
		model = "BastionMod\BastionGuns\BUIS\buis.p3d";
	};
};
