class CfgPatches
{
	class SearchableItems
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
	class SearchableItems
	{
		dir = "SearchableItems";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "SearchableItems";
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
				files[] = {"BastionMod/BastionMisc/SearchableItems/scripts/3_Game"};
			};
			class worldScriptModule
			{
				value="";
				files[]={"BastionMod/BastionMisc/SearchableItems/scripts/4_World"};
			};
			class missionScriptModule		
            {
                value = "";
                files[] = {"BastionMod/BastionMisc/SearchableItems/scripts/5_Mission"};
            };
		};
	};
};
