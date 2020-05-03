class CfgPatches
{
	class BastionBanner
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data"
		};
		
	
	};
};

class cfgVehicles
{
	class HouseNoDestruct;
	class BRP_Banner: HouseNoDestruct
	{
		scope=1;
		model="BastionMod\BastionBanner\banner.p3d";
		
	};
	
};


