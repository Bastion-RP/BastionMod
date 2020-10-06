class CfgPatches
{
	class BRP_simplebackpack
	{
		units[]=
		{
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Characters_Backpacks",
			"DZ_Gear_Containers"
		};
	};	
};
class CfgVehicles
{
	class Clothing;
	class BRP_simplebackpack_ColorBase: Clothing
	{
		displayName="Simple backpack";
		descriptionShort="A Simple backpack with the possibility to attach some items.";
		model="\BastionMod\BastionClothing\simplebackpack\simplebackpack_g.p3d";
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
		itemSize[]={4,6};
		itemsCargoSize[]={6,5};
		weight=2300;
		absorbency=0.2;
		heatIsolation=0.13;
		repairableWithKits[]={5,3};
		repairCosts[]={30,25};
		soundAttType="Outdoor";
		attachments[]=
		{
			"teddy",
			"protectorcase",
			"flashlight",
			"Belt_Left",
			"waterproofbag"
		};
		hiddenSelections[]=
		{
			"zbytek",
			"groundmodel"
		};
		class ClothingTypes
		{
			male="\BastionMod\BastionClothing\simplebackpack\simplebackpack.p3d";
			female="\BastionMod\BastionClothing\simplebackpack\simplebackpack.p3d";
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
							1.00000000,
							
							{
								"BastionMod\BastionClothing\simplebackpack\data\simplebackpack.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"BastionMod\BastionClothing\simplebackpack\data\simplebackpack.rvmat"
							}
						},
						
						{
							0.50000000,
							
							{
								"BastionMod\BastionClothing\simplebackpack\data\simplebackpack_damaged.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"BastionMod\BastionClothing\simplebackpack\data\simplebackpack_damaged.rvmat"
							}
						},
						
						{
							0.00000000,
							
							{
								"BastionMod\BastionClothing\simplebackpack\data\simplebackpack_destroyed.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class BRP_simplebackpack_blue :BRP_simplebackpack_ColorBase
	{
		scope=2;
		descriptionShort="Munghards simple blue backpack";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\simplebackpack\data\simplebackpack_co.paa",
			"BastionMod\BastionClothing\simplebackpack\data\simplebackpack_co.paa"
		};
	};
	class BRP_simplebackpack_camoblack :BRP_simplebackpack_ColorBase
	{
		scope=2;
		descriptionShort="Munghards simple camo/black backpack";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\simplebackpack\data\simplebackpack_camoblack_co.paa",
			"BastionMod\BastionClothing\simplebackpack\data\simplebackpack_camoblack_co.paa"
		};
	};
	class BRP_simplebackpack_green :BRP_simplebackpack_ColorBase
	{
		scope=2;
		descriptionShort="Munghards simple green backpack";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\simplebackpack\data\simplebackpack_green_co.paa",
			"BastionMod\BastionClothing\simplebackpack\data\simplebackpack_green_co.paa"
		};
	};
	class BRP_simplebackpack_redpink :BRP_simplebackpack_ColorBase
	{
		scope=2;
		descriptionShort="Munghards simple red/pink backpack";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\simplebackpack\data\simplebackpack_redpink_co.paa",
			"BastionMod\BastionClothing\simplebackpack\data\simplebackpack_redpink_co.paa"

		};
	};
	class BRP_simplebackpack_redyellow :BRP_simplebackpack_ColorBase
	{
		scope=2;
		descriptionShort="Munghards simple red/yellow backpack";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\simplebackpack\data\simplebackpack_redyellow_co.paa",
			"BastionMod\BastionClothing\simplebackpack\data\simplebackpack_redyellow_co.paa"
		};
	};
	class Container_Base;
	class Bear_ColorBase: Container_Base
	{
		inventorySlot[]=
		{
			"teddy"
		};
	};
	class SmallProtectorCase: Container_Base
	{
		inventorySlot[]=
		{
			"protectorcase"
		};
	};
};
class CfgNonAIVehicles
{
	class ProxyAttachment;
	class Proxyteddybear: ProxyAttachment
	{
		scope=2;
		inventorySlot[]=
		{
			"teddy"
		};
		model="\dz\gear\containers\teddybear.p3d";
	};
	class Proxyprotector_case: ProxyAttachment
	{
		scope=2;
		inventorySlot[]=
		{
			"protectorcase"
		};
		model="\dz\gear\containers\protector_case.p3d";
	};
};
class CfgSlots
{
	class Slot_teddy
	{
		name="teddy";
		displayName="teddy";
		ghostIcon="pouches";
	};
	class Slot_protectorcase
	{
		name="protectorcase";
		displayName="protectorcase";
		ghostIcon="pouches";
	};
};