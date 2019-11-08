class CfgPatches
{
	class Menu
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
	class Menu
	{
		dir = "BastionMenu";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "BastionRP Menu";
		credits = "0";
		author = "Buckeyes";
		authorID = "0"; 
		version = "1.0"; 
		extra = 0;
		type = "mod";
		dependencies[] = {"Game", "Mission"};
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = {"Menu/scripts/3_Game"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"Menu/scripts/5_Mission"};
			};
		};
	};
};