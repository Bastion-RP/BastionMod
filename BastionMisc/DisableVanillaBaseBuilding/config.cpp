class CfgPatches
{
	class DisableVanillaBaseBuilding
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]={"DZ_Data"};
	};
};

class CfgMods
{
	class DisableVanillaBaseBuilding
	{
		dir="DisableVanillaBaseBuilding";
		picture="";
		action="";
		hideName=1;
		hidePicture=1;
		name="DisableVanillaBaseBuilding";
		credits="";
		author="Helkhiana";
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
                files[] = {"BastionMod/BastionMisc/DisableVanillaBaseBuilding/scripts/4_World"};
			};
		};
    };
};