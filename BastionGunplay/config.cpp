class CfgPatches
{
	class BastionGunPlay
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
	class BastionGunPlay
	{
	    type = "mod";
	    dependencies[] = {"Game","World","Mission"};
	    class defs
	    {
			class gameScriptModule
            {
                value = "";
                files[] = {"BastionMod/BastionGunPlay/scripts/3_Game"};
            };
			class worldScriptModule
            {
                value = "";
                files[] = {"BastionMod/BastionGunPlay/scripts/4_World"};
            };
			class missionScriptModule
            {
                value = "";
                files[] = {"BastionMod/BastionGunPlay/scripts/5_Mission"};
            };
        };
    };
};