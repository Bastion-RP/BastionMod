class CfgPatches
{
	class BastionQuestsSystemServer
	{
		requiredAddons[]=
		{
			// ""
		};
	};
};

class CfgMods
{
	class BastionQuestsSystemServer
	{
	    type = "mod";
		
	    class defs
	    {
			class gameScriptModule
			{
				value="";
				files[] = {"BastionQuestsSystemServer/scripts/3_Game"};
			};
			class worldScriptModule
			{
				value="";
				files[]={"BastionQuestsSystemServer/scripts/4_World"};
			};
			class missionScriptModule		
            {
                value = "";
                files[] = {"BastionQuestsSystemServer/scripts/5_Mission"};
            };
        };
    };
};