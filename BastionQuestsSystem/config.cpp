class CfgPatches
{
	class BastionQuestsSystem
	{
		requiredAddons[]=
		{
			// ""
		};
	};
};

class CfgMods
{
	class BastionQuestsSystem
	{
		dir = "BastionQuestsSystem";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "BastionQuestsSystem";
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
				files[] = {"BastionMod/BastionQuestsSystem/scripts/3_Game"};
			};
			class worldScriptModule
			{
				value="";
				files[]={"BastionMod/BastionQuestsSystem/scripts/4_World"};
			};
			class missionScriptModule		
            {
                value = "";
                files[] = {"BastionMod/BastionQuestsSystem/scripts/5_Mission"};
            };
        };
    };
};
