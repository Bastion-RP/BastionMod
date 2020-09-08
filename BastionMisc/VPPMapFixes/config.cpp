class CfgPatches
{
	class BastionVPPMapFixes
	{
		units[]=
		{
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Gear_Navigation",
			"VanillaPlusPlus",
			"RPC_Scripts",
			"BastionMultiCharacters"
		};
	};
};
class CfgMods
{
	class BastionVPPMapFixes
	{
	    type = "mod";
	    dependencies[] = {
			"Game",
			"World",
			"Mission",
			"gui",
			"VanillaPPMap",
			"BastionMultiCharacters"
		};
	    class defs
	    {
			class gameScriptModule
            {
                value = "";
                files[] = {"BastionMod/BastionMisc/VPPMapFixes/scripts/3_Game"};
            };
			class worldScriptModule
            {
                value = "";
                files[] = {"BastionMod/BastionMisc/VPPMapFixes/scripts/4_World"};
            };
			class missionScriptModule
            {
                value = "";
                files[] = {"BastionMod/BastionMisc/VPPMapFixes/scripts/5_Mission"};
            };
        };
    };
};
