class CfgPatches
{
	class ISFShield
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
	class BRP_ISFShield: HouseNoDestruct
	{
		scope=1;
		model="BastionMod\Shield\BRP_ISFShield.p3d";
		
	};
	
};


