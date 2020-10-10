class CfgPatches
{
	class BastionToxic
	{
		requiredAddons[]=
		{
			"DZ_data"
		};
	};
};

class CfgMods
{
	class BastionToxic
	{
		dir = "BastionToxic";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "BastionToxic";
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
				files[] = {"BastionMod/BastionToxic/scripts/3_Game"};
			};
			class worldScriptModule
			{
				value="";
				files[]={"BastionMod/BastionToxic/scripts/4_World"};
			};
			class missionScriptModule		
            {
                value = "";
                files[] = {"BastionMod/BastionToxic/scripts/5_Mission"};
            };
        };
    };
};
