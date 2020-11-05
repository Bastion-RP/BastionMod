class CfgPatches
{
	class BRP_fannypack
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Characters_Backpacks"
		};
	};	
};
class CfgVehicles
{
	class Clothing;
	class BRP_fannypack_ColorBase: Clothing
	{
		displayName="Fannypack";
		descriptionShort="A fannypack for that little extra space. Some items can be attached.";
		model="\BastionMod\BastionClothing\fannypack\fannypack_g.p3d";
		attachments[]=
		{
			"VestHolster",
			"Hatchet",
			"machete"
		};
		vehicleClass="Clothing";
		simulation="clothing";
		inventorySlot[]=
		{
			"Hips"
		};
		itemInfo[]=
		{
			"Clothing",
			"Hips"
		};
		itemSize[]={4,1};
		itemsCargoSize[]={4,2};
		weight=20;
		lootCategory="Crafted";
		lootTag[]=
		{
			"Civilian"
		};
		hiddenSelections[]=
		{
			"zbytek"
		};
		class ClothingTypes
		{
			male="\BastionMod\BastionClothing\fannypack\fannypack.p3d";
			female="\BastionMod\BastionClothing\fannypack\fannypack.p3d";
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
								"BastionMod\BastionClothing\fannypack\data\fannypack.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"BastionMod\BastionClothing\fannypack\data\fannypack.rvmat"
							}
						},
						
						{
							0.50000000,
							
							{
								"BastionMod\BastionClothing\fannypack\data\fannypack_damaged.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"BastionMod\BastionClothing\fannypack\data\fannypack_damaged.rvmat"
							}
						},
						
						{
							0.00000000,
							
							{
								"BastionMod\BastionClothing\fannypack\data\fannypack_destroyed.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class BRP_fannypack_pink :BRP_fannypack_ColorBase
	{
		scope=2;
		descriptionShort="Munghards pink fannypack";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\fannypack\data\fannypack_co.paa"
		};
	};
	class BRP_fannypack_black :BRP_fannypack_ColorBase
	{
		scope=2;
		descriptionShort="Munghards black fannypack";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\fannypack\data\fannypack_black_co.paa"
		};
	};
	class BRP_fannypack_multi :BRP_fannypack_ColorBase
	{
		scope=2;
		descriptionShort="Munghards multi fannypack";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\fannypack\data\fannypack_multi_co.paa"
		};
	};
	class BRP_fannypack_camo :BRP_fannypack_ColorBase
	{
		scope=2;
		descriptionShort="Munghards camo fannypack";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\fannypack\data\fannypack_camo_co.paa"
		};
	};
	class Inventory_Base;
	class Hatchet: Inventory_Base
	{
        inventorySlot[]=
        {
            "MassTool",
            "Hatchet",
            "Hatchet1",
            "Hatchet2",
            "Hatchet3",
            "Hatchet4"
        };
	};
	class Machete: Inventory_Base
	{
		inventorySlot[]=
		{
			"machete"
		};
	};
};
class CfgNonAIVehicles
{
	class ProxyAttachment;
	class Proxyhatchet: ProxyAttachment
	{
		scope=2;
		inventorySlot[]=
        {
            "MassTool",
            "Hatchet",
            "Hatchet1",
            "Hatchet2",
            "Hatchet3",
            "Hatchet4"
        };
		model="\dz\weapons\melee\blade\hatchet.p3d";
	};
	class Proxymachete: ProxyAttachment
	{
		scope=2;
		inventorySlot[]=
		{
			"machete"
		};
		model="\dz\weapons\melee\blade\machete.p3d";
	};
};
class CfgSlots
{
	class Slot_hatchet
	{
		name="hatchet";
		displayName="leftside";
		ghostIcon="default";
	};
	class Slot_machete
	{
		name="machete";
		displayName="rightside";
		ghostIcon="default";
	};
};