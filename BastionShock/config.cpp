class CfgPatches
{
	class BastionShock
	{
		units[]={
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]={
			"DZ_Data",
			"DZ_Characters"
		};
	};
};
class CfgMods
{
	class BastionShock
	{
	    type = "mod";
	    dependencies[] = {"Game","World","Mission"};
	    class defs
	    {
			class gameScriptModule
            {
                value = "";
                files[] = {"BastionShock/scripts/3_Game"};
            };
			class worldScriptModule
            {
                value = "";
                files[] = {"BastionShock/scripts/4_World"};
            };
			class missionScriptModule
            {
                value = "";
                files[] = {"BastionShock/scripts/5_Mission"};
            };
        };
    };
};