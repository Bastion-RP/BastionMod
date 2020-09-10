class CfgPatches
{
	class BRP_6B38
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Characters",
			"DZ_Characters_Backpacks",
			"DZ_Gear_Containers"
		};
	};	
};
class CfgVehicles
{
	class Container_Base;
	class AmmoBox: Container_Base
	{
		inventorySlot[]=
		{
			"300RoundBox"
		};
	};
	class Clothing;
	class BRP_bag_6B38_Colorbase: Clothing
	{

		displayName="6B38";
		model="\BastionMod\BastionClothing\6B38\6B38_g.p3d";
		inventorySlot[]=
		{
			"Back"
		};
		simulation="clothing";
		vehicleClass="Clothing";
		itemInfo[]=
		{
			"Clothing",
			"Back"
		};
		rotationFlags=0;
		itemSize[]={5,7};
		itemsCargoSize[]={10,8};
		weight=2600;
		absorbency=0.2;
		heatIsolation=0.13;
		repairableWithKits[]={5,3};
		repairCosts[]={30,25};
		canBeDigged=1;
		soundAttType="Outdoor";
		attachments[]=
		{
			"binocular",
			"VestPouch",
			"Belt_Left",
			"WalkieTalkie",
			"flashlight",
			"300roundbox",
			"Chemlight",
			"shoulder"
		};
		hiddenSelections[]=
		{
			"zbytek"
		};
		class ClothingTypes
		{
			male="\BastionMod\BastionClothing\6B38\6B38.p3d";
			female="\BastionMod\BastionClothing\6B38\6B38.p3d";
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
					healthLevels[]=
					{
						
						{
							1.0,
							
							{
								"BastionMod\BastionClothing\6B38\data\raidbackpack_6B38.rvmat"
							}
						},
						
						{
							0.7,
							
							{
								"BastionMod\BastionClothing\6B38\data\raidbackpack_6B38.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"BastionMod\BastionClothing\6B38\data\raidbackpack_6B38.rvmat"
							}
						},
						
						{
							0.3,
							
							{
								"BastionMod\BastionClothing\6B38\data\raidbackpack_6B38.rvmat"
							}
						},
						
						{
							0.0,
							
							{
								"BastionMod\BastionClothing\6B38\data\raidbackpack_6B38.rvmat"
							}
						}
					};
				};
			};
		};
	};
		class BRP_bag_6B38_camo: BRP_bag_6B38_Colorbase
	{
	scope = 2;
	displayName="6B38";
	descriptionShort="Original Russian Army raid  BACKPACK EMR Camo. Produced by Zaratkul. Supplied military equipment number is 6B38.";
	hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\6B38\data\raidbackpack_6B38_co.paa"
		};
	};
		class bag_6B38_LETO_mung: BRP_bag_6B38_Colorbase
	{
	scope = 2;
	displayName="6B38 LETO";
	descriptionShort="Original Russian Army raid  BACKPACK EMR Leto Camo. Produced by Zaratkul. Supplied military equipment number is 6B38.";
	hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\6B38\data\raidbackpack_6B38_LETO_co.paa"
		};
	};
		class bag_6B38_Black_mung: BRP_bag_6B38_Colorbase
	{
	scope = 2;
	displayName="6B38 BLACK";
	descriptionShort="Original Russian Army raid  BACKPACK EMR Black. Produced by Zaratkul. Supplied military equipment number is 6B38.";
	hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\6B38\data\raidbackpack_6B38_black_co.paa"
		};
	};
		class bag_6B38_Snow_mung: BRP_bag_6B38_Colorbase
	{
	scope = 2;
	displayName="6B38 SNOW";
	descriptionShort="Original Russian Army raid  BACKPACK EMR Snow. Produced by Zaratkul. Supplied military equipment number is 6B38.";
	hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\6B38\data\raidbackpack_6B38_snow_co.paa"
		};
	};
};
class CfgSlots
{
	class Slot_flashlight
	{
		name="flashlight";
		displayName="flashlight";
		ghostIcon="flashlight";
	};
	class Slot_binocular
	{
		name="binocular";
		displayName="binocular";
		ghostIcon="opticacog";
	};
	class Slot_ammobox
	{
		name="300roundbox";
		displayName="300roundbox";
		ghostIcon="hips";
	};
};
class CfgNonAIVehicles
{
	class ProxyAttachment;
	class Proxy300RoundBox: ProxyAttachment
	{
		scope=2;
		inventorySlot[]=
		{
			"300RoundBox"
		};
		model="\dz\gear\containers\300RoundBox.p3d";
	};
	class Proxyweaponproxy: ProxyAttachment
	{
		scope=2;
		inventorySlot[]=
		{
			"Shoulder"
		};
		model="BastionMod\BastionClothing\6B38\weaponproxy.p3d";
	};
};