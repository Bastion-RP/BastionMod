class CfgPatches
{
	class RadiationCase
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
	};
};

class CfgMods
{
	class RadiationCase
	{
		dir="RadiationCase";
		picture="";
		action="";
		hideName=1;
		hidePicture=1;
		name="ToxicCase";
		credits="Captain_Bigzy & Dmitri";
		author="Dave";
		authorID="0";
		version="1.0";
		extra=0;
		type="mod";
	};
};

class CfgVehicles
{
	class Container_Base;
	class RadiationCase: Container_Base
	{
		scope = 2;
		displayName = "Radiation Case";
		descriptionShort = "A Case Found in the Radiation Zone";
		model = "BastionMod\BastionDangerousZone\data\RadiationCase\RadiationCase.p3d";
		weight=10000;
		heavyItem=2;
		itemSize[]={50,50};
		carveNavmesh=1;
		rotationFlags=2;
		class Cargo
		{
			itemsCargoSize[]={10,30};
			openable=0;
			allowOwnedCargoManipulation=1;
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "smallprotectorcase_pickup_SoundSet";
					id = 797;
				};
			class drop
				{
					soundset = "smallprotectorcase_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
};
