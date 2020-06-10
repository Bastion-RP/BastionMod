class CfgPatches
{
	class BastionGunplay
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
	class BastionGunplay
	{
	    type = "mod";
	    dependencies[] = {"Game","World","Mission"};
	    class defs
	    {
			class gameScriptModule
            {
                value = "";
                files[] = {"BastionMod/BastionGunplay/scripts/3_Game"};
            };
			class worldScriptModule
            {
                value = "";
                files[] = {"BastionMod/BastionGunplay/scripts/4_World"};
            };
			class missionScriptModule
            {
                value = "";
                files[] = {"BastionMod/BastionGunplay/scripts/5_Mission"};
            };
        };
    };
};