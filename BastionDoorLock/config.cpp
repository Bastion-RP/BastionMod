class CfgPatches
{
	class BastionDoorLock
	{
		requiredAddons[]=
		{
			"DZ_Data"
		};
	};
};

class CfgMods
{
	class BastionDoorLock
	{
		dir = "BastionDoorLock";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "BastionDoorLock";
		credits = "Kactet";
		author = "Kactet";
		authorID = "0";
		version = "1.0";
		extra = 0;
		type = "mod";
		dependencies[] = {"Game","World"};
		
	    class defs
	    {
			class gameScriptModule
			{
				value="";
				files[] = {"BastionMod/BastionDoorLock/scripts/3_Game"};
			};
			class worldScriptModule
			{
				value="";
				files[]={"BastionMod/BastionDoorLock/scripts/4_World"};
			};
        };
    };
};
