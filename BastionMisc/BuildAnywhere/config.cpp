class CfgPatches
{
	class BastionBuildAnywhere
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]={"DZ_Structures_Residential"};
	};
};

class CfgMods
{
	class BastionBuildAnywhere
	{
		dir="BastionBuildAnywhere";
		picture="";
		action="";
		hideName=1;
		hidePicture=1;
		name="BastionBuildAnywhere";
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
                files[] = {"BastionMod/BastionMisc/BuildAnywhere/scripts/4_World"};
			};

			class missionScriptModule
            {
                value = "";
                files[] = {"BastionMod/BastionMisc/BuildAnywhere/scripts/5_Mission"};
			};
		};
    };
};

class CfgVehicles
{
	class HouseNoDestruct;
	class GardenPlot: HouseNoDestruct
	{
		physLayer="item_small";
	};
};