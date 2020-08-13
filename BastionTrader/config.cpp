class CfgPatches
{
	class BastionTrader
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
	class BastionTrader
	{
		dir = "BastionTrader";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "BastionTrader";
		credits = "Kactet";
		author = "Kactet";
		authorID = "0";
		version = "1.0";
		extra = 0;
		type = "mod";
		class defs
		{
			class gameScriptModule
			{
				value="";
				files[] = {"BastionMod/BastionTrader/scripts/3_Game"};
			};
			class worldScriptModule
			{
				value="";
				files[]={"BastionMod/BastionTrader/scripts/4_World"};
			};
			class missionScriptModule		
            {
                value = "";
                files[] = {"BastionMod/BastionTrader/scripts/5_Mission"};
            };
		};
	};
};
