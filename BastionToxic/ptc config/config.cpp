class CfgPatches
{
	class BastionToxicParticles
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
		};
	};
};

class CfgVehicles
{
	class HouseNoDestruct;
	class SporeBase : HouseNoDestruct
	{
		scope=2;
		displayName="Spore";
		forceFarBubble="true";
		carveNavmesh=1;
		rotationFlags=2;
		itemSize[]={1,1};
		weight=1000000;
	};
	class GreenSpore: SporeBase
	{

	};
	class WeirdGreenSpore: SporeBase
	{

	};
	class WeirdGreenSpore2: SporeBase
	{
		
	};
	class BlueSpore: SporeBase
	{
		
	};
	class RedSpore: SporeBase
	{
		
	};
	class PurpleSpore: SporeBase
	{
		
	};
	class WhiteSpore: SporeBase
	{

	};
	class WeirdGreenSporeSmall: SporeBase
	{

	};
	class WeirdGreenSporeExtraSmall: SporeBase
	{

	};
};