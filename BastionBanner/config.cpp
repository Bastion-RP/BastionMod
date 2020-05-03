class CfgPatches
{
	class BastionBanner
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Characters",
			"DZ_Characters_Backpacks",
			"DZ_Characters_Pants",
			"DZ_Characters_Tops",
			"DZ_Gear_Containers",
			"DZ_Characters_Headgear",
			"DZ_Data",
			"DZ_Scripts",
			"DZ_Gear_Medical",
			"DZ_Gear_consumables",
			"DZ_Weapons_Ammunition",
			"DZ_Weapons_Projectiles",
			"DZ_Weapons_Melee",
			"DZ_Gear_Camping",
			"DZ_Weapons_Firearms",
			"DZ_Pistols"
		};
		
	
	};
};
class CfgMods
{
    class banner
    {
        dir = "bastion";
        picture = "";
        action = "";
        hideName = 1;
        hidePicture = 1;
        name = "banner_custom";
        credits = "Creep";
        author = "Creep";
        authorID = "0"; 
        version = "1.0"; 
        extra = 0;
        type = "mod";
        
        
    };
};

class cfgVehicles
{
	class HouseNoDestruct;
	class banner: HouseNoDestruct
	{
		scope=1;
		model="BastionMod\BastionBanner\BastionBanner.p3d";
		
	};
	
};


