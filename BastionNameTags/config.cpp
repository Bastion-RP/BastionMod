class CfgPatches
{
	class BastionNameTags
	{
		units[]={
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]={
			"DZ_Data",
			"DZ_Characters",
			"BastionDTAC"
		};
	};
};
class CfgMods
{
	class BastionNameTags
	{
	    type = "mod";
	    dependencies[] = {"Game","World","Mission","BastionDTAC"};	// dependency because using GetMultiCharactersPlayerName() in playerbase
	    class defs
	    {
			class gameScriptModule
            {
                value = "";
                files[] = {"BastionMod/BastionNameTags/scripts/3_Game"};
            };
			class worldScriptModule
            {
                value = "";
                files[] = {"BastionMod/BastionNameTags/scripts/4_World"};
            };
			class missionScriptModule
            {
                value = "";
                files[] = {"BastionMod/BastionNameTags/scripts/5_Mission"};
            };
        };
    };
};