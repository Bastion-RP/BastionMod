class CfgPatches
{
	class BastionRadiation
	{
		requiredAddons[]=
		{
			"DZ_data"
		};
	};
};

class CfgMods
{
	class BastionRadiation
	{
		dir = "BastionRadiation";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "BastionRadiation";
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
				files[] = {"BastionMod/BastionRadiation/scripts/3_Game"};
			};
			class worldScriptModule
			{
				value="";
				files[]={"BastionMod/BastionRadiation/scripts/4_World"};
			};
			class missionScriptModule		
            {
                value = "";
                files[] = {"BastionMod/BastionRadiation/scripts/5_Mission"};
            };
        };
    };
};
