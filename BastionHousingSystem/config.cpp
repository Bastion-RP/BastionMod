class CfgPatches
{
	class BastionHousingSystem
	{
		requiredAddons[]=
		{
			"DZ_Data"
		};
	};
};

class CfgMods
{
	class BastionHousingSystem
	{
		dir = "BastionHousingSystem";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "BastionHousingSystem";
		credits = "Kactet";
		author = "Kactet";
		authorID = "0";
		version = "1.0";
		extra = 0;
		type = "mod";
		dependencies[] = {"Game","World","Mission"};
		
	    class defs
	    {
			class gameScriptModule
			{
				value="";
				files[] = {"BastionMod/BastionHousingSystem/scripts/3_Game"};
			};
			class worldScriptModule
			{
				value="";
				files[]={"BastionMod/BastionHousingSystem/scripts/4_World"};
			};
			class missionScriptModule		
            {
                value = "";
                files[] = {"BastionMod/BastionHousingSystem/scripts/5_Mission"};
            };
        };
    };
};
