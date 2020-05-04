class CfgPatches
{
	class BastionSearchPlayer
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]={};
	};
};

class CfgMods
{
	class BastionSearchPlayer
	{
		dir="BastionSearchPlayer";
		picture="";
		action="";
		hideName=1;
		hidePicture=1;
		name="BastionSearchPlayer";
		credits="";
		author="Jest";
		authorID="0";
		version="1.0";
		extra=0;
		type="mod";
        dependencies[] = {"World", "Mission"};
        
        class defs
        {
			class worldScriptModule
            {
                value = "";
                files[] = {"BastionMod/BastionMisc/SearchPlayer/scripts/4_World"};
			};

			class missionScriptModule
            {
                value = "";
                files[] = {"BastionMod/BastionMisc/SearchPlayer/scripts/5_Mission"};
			};
		};
    };
};

