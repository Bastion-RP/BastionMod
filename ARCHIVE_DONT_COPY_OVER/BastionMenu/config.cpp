class CfgPatches
{
	class BastionMenu
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
	class BastionMenu
	{
		dir = "BastionMenu";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "BastionRP Menu";
		credits = "0";
		author = "Buckeyes & Kerkkoh";
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
				files[] = {"BastionMenu/scripts/3_Game"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"BastionMenu/scripts/5_Mission"};
			};
		};
	};
};