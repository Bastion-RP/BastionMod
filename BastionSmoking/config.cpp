class CfgPatches
{
	class BastionSmoking
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
	class BastionSmoking
	{
		dir = "BastionSmoking";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "BastionSmoking";
		credits = "Jad, Windstride";
		author = "Jad";
		version = "1.0";
		extra = 0;
		type = "mod";
		dependencies[] = {"Game", "World", "Mission"};
		class defs
		{
			class gameScriptModule
			{
				value="";
				files[] = {"BastionMod/BastionSmoking/scripts/3_Game"};
			};
			class worldScriptModule
			{
				value="";
				files[]={"BastionMod/BastionSmoking/scripts/4_World"};
			};
			class missionScriptModule		
            {
                value = "";
                files[] = {"BastionMod/BastionSmoking/scripts/5_Mission"};
            };
		};
	};
};
