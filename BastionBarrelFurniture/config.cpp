class CfgMods
{
    class BastionBarrelFurniture
    {
		type = "mod";
		author = "Chopper";
		name = "BastionBarrelFurniture";
        dir = "BastionBarrelFurniture";
        dependencies[] = {"World"};

        class defs
        {
            class worldScriptModule
            {
                files[] = {"BastionMod\BastionBarrelFurniture\scripts\4_World"};
			};
		};
    };
};

class CfgPatches
{
	class BastionBarrelFurniture
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Gear_Containers",
			"DZ_Gear_Crafting",
			"DZ_Data"
		};
	};
};
