class CfgPatches
{
	class BastionAIONCrate
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
    class AIONCrate
    {
        dir = "AIONCrate";
        picture = "";
        action = "";
        hideName = 1;
        hidePicture = 1;
        name = "AIONCrate";
        credits = "";
        author = "Helkhiana";
        authorID = "0"; 
        version = "1.0"; 
        extra = 0;
        type = "mod";
        
        dependencies[] = {"World"};
        
        class defs
        {
            class worldScriptModule
            {
                value = "";
                files[] = {"BastionMod/BastionMisc/AIONCrate/scripts/4_World"};
			};
		};
    };
};