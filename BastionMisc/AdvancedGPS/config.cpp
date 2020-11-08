class CfgPatches
{
	class AdvancedGPS
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data"
		};
	};
};

class CfgMods
{
	class AdvancedGPS
	{
		dir = "AdvancedGPS";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "AdvancedGPS";
		credits = "Kactet";
		author = "Kactet";
		authorID = "Кастет#3542";
		version = "1.0";
		inputs="BastionMod/BastionMisc/AdvancedGPS/assets/inputs/modded_Inputs.xml";
		extra = 0;
		type = "mod";
		class defs
		{
			class gameScriptModule
			{
				value="";
				files[] = {"BastionMod/BastionMisc/AdvancedGPS/scripts/3_Game"};
			};
			class worldScriptModule
			{
				value="";
				files[]={"BastionMod/BastionMisc/AdvancedGPS/scripts/4_World"};
			};
			class missionScriptModule		
            {
                value = "";
                files[] = {"BastionMod/BastionMisc/AdvancedGPS/scripts/5_Mission"};
            };
		};
	};
};