class CfgPatches
{
	class BRP_shikingbag
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Characters",
			"DZ_Characters_Backpacks",
			"DZ_Gear_Containers",
			"DZ_Gear_Consumables",
			"DZ_Gear_Tools",
			"DZ_Gear_Cooking",
			"DZ_Gear_Food",
			"DZ_Gear_Navigation",
			"DZ_Gear_Drinks",
			"DZ_Gear_Camping",
			"DZ_Gear_Optics",
			"DZ_Gear_Crafting",
			"DZ_Weapons_Firearms"
		};
	};	
};
class CfgVehicles
{
	class Clothing;
	class BRP_Hikingbag_ColorBase: Clothing
	{
		displayName="Munghards hiking backpack";
		descriptionShort="A hiking backpack designed for the people who take camping very seriously and likes to (have it all) when it comes to camping, takes many different attachments";
		model="\BastionMod\BastionClothing\hikingbag\Mung_backpack_g.p3d";
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
		weight=3000;
		absorbency=0.2;
		heatIsolation=0.13;
		repairableWithKits[]={5,3};
		repairCosts[]={30,25};
		canBeDigged=1;
		soundAttType="Outdoor";
		attachments[]=
		{
			"firstaidkit",
			"binocular",
			"GasCooker",
			"CookingEquipment",
			"Belt_Left",
			"compass",
			"tent",
			"WalkieTalkie",
			"flashlight",
			"waterproofbag",
			"cookingtripod",
			"Chemlight",
			"shoulder",
			"fishingpole"
		};
		hiddenSelections[]=
		{
			"zbytek",
			"camoground"
		};
		class ClothingTypes
		{
			male="\BastionMod\BastionClothing\hikingbag\Mung_backpack.p3d";
			female="\BastionMod\BastionClothing\hikingbag\Mung_backpack.p3d";
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
							1.000000000,
							
							{
								"BastionMod\BastionClothing\hikingbag\data\Backpack_mung.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"BastionMod\BastionClothing\hikingbag\data\Backpack_mung.rvmat"
							}
						},
						
						{
							0.50000000,
							
							{
								"BastionMod\BastionClothing\hikingbag\data\Backpack_mung_damaged.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"BastionMod\BastionClothing\hikingbag\data\Backpack_mung_damaged.rvmat"
							}
						},
						
						{
							0.00000000,
							
							{
								"BastionMod\BastionClothing\hikingbag\data\Backpack_mung_destroyed.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class BRP_Hikingbagmung_yellow :BRP_Hikingbag_ColorBase
	{
		scope=2;
		descriptionShort="Yellow hiking backpack";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\hikingbag\data\hikingbag_lp_yellow_co.paa",
			"BastionMod\BastionClothing\hikingbag\data\hikingbag_lp_yellow_co.paa"
		};
	};
	class BRP_Hikingbagmung_red :BRP_Hikingbag_ColorBase
	{
		scope=2;
		descriptionShort="Red hiking backpack";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\hikingbag\data\hikingbag_lp_red_co.paa",
			"BastionMod\BastionClothing\hikingbag\data\hikingbag_lp_red_co.paa"
		};
	};
	class BRP_Hikingbagmung_blue :BRP_Hikingbag_ColorBase
	{
		scope=2;
		descriptionShort="Blue hiking backpack";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\hikingbag\data\hikingbag_lp_blue_co.paa",
			"BastionMod\BastionClothing\hikingbag\data\hikingbag_lp_blue_co.paa"
		};
	};
	class BRP_Hikingbagmung_green :BRP_Hikingbag_ColorBase
	{
		scope=2;
		descriptionShort="Green hiking backpack";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\hikingbag\data\hikingbag_lp_green_co.paa",
			"BastionMod\BastionClothing\hikingbag\data\hikingbag_lp_green_co.paa"
		};
	};
	class BRP_Hikingbagmung_black :BRP_Hikingbag_ColorBase
	{
		scope=2;
		descriptionShort="Black hiking backpack";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\hikingbag\data\hikingbag_lp_black_co.paa",
			"BastionMod\BastionClothing\hikingbag\data\hikingbag_lp_black_co.paa"
		};
	};
	class BRP_Hikingbagmung_white :BRP_Hikingbag_ColorBase
	{
		scope=2;
		descriptionShort="white hiking backpack";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\hikingbag\data\hikingbag_lp_white_co.paa",
			"BastionMod\BastionClothing\hikingbag\data\hikingbag_lp_white_co.paa"
		};
	};
	class BRP_Hikingbagmung_camo :BRP_Hikingbag_ColorBase
	{
		scope=2;
		descriptionShort="Camo hiking backpack";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\hikingbag\data\hikingbag_lp_camo_co.paa",
			"BastionMod\BastionClothing\hikingbag\data\hikingbag_lp_camo_co.paa"
		};
	};
	class BRP_Hikingbagmung_pink :BRP_Hikingbag_ColorBase
	{
		scope=2;
		descriptionShort="Pink hiking backpack";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\hikingbag\data\hikingbag_lp_pink_co.paa",
			"BastionMod\BastionClothing\hikingbag\data\hikingbag_lp_pink_co.paa"
		};
	};
	class BRP_Hikingbagmung_meow :BRP_Hikingbag_ColorBase
	{
		scope=2;
		descriptionShort="Meow hiking backpack";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\hikingbag\data\hikingbag_lp_meow_co.paa",
			"BastionMod\BastionClothing\hikingbag\data\hikingbag_lp_meow_co.paa"
		};
	};
	class BRP_Hikingbagmung_snow :BRP_Hikingbag_ColorBase
	{
		scope=2;
		descriptionShort="Snow hiking backpack";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\hikingbag\data\hikingbag_lp_snow_co.paa",
			"BastionMod\BastionClothing\hikingbag\data\hikingbag_lp_snow_co.paa"
		};
	};
	class Container_Base;
	class Transmitter_Base;
	class Inventory_Base;
	class Bottle_Base;
	class FishingRod_Base_New;
	class ItemOptics;
	class Trap_Base;
	class BearTrap : Trap_Base
	{
		inventorySlot[]=
		{
			"tent"
		};
	};
	class WaterproofBag_ColorBase: Container_Base
	{
		inventorySlot[]=
		{
			"waterproofbag"
		};
	};
	class OrienteeringCompass: Inventory_Base
	{
		inventorySlot[]=
		{
			"compass",
			"MassCompass"
		};
	};
    class FishingRod: FishingRod_Base_New
    {
        inventorySlot[]=
        {
        	"Shoulder",
            "melee",
            "fishingpole",
            "fishingrod1",
            "fishingrod2",
            "fishingrod3",
            "fishingrod4",
            "fishingrod5",
            "fishingrod6",
            "fishingrod7",
            "fishingrod8",
            "fishingrod9",
            "fishingrod10"
        };
    };
	class Binoculars: ItemOptics
	{
		inventorySlot[]=
		{
			"binocular"
		};
	};
	class MediumTent: Container_Base
	{
		inventorySlot[]=
		{
			"tent"
		};
	};
	class PersonalRadio: Transmitter_Base
	{
		inventorySlot[]=
		{
			"walkietalkie",
			"MassRadio"
		};
	};
	class PortableGasStove: Inventory_Base
	{
		inventorySlot[]=
		{
			"GasCooker",
			"fishingpole"
		};
	};
	class FirstAidKit: Container_Base
	{
		inventorySlot[]=
		{
			"firstaidkit",
			"FirstAid"
		};
	};
	class Flashlight: Inventory_Base
	{
		inventorySlot[]=
		{
			"flashlight",
			"MassFlashlight"
		};
	};
	class CamoNet: Inventory_Base
	{
		inventorySlot[]=
		{
			"CamoNet",
			"Wall_Camonet",
			"Level_1_Wall_1_Camonet",
			"Level_1_Wall_2_Camonet",
			"Level_1_Wall_3_Camonet",
			"Level_2_Wall_1_Camonet",
			"Level_2_Wall_2_Camonet",
			"Level_2_Wall_3_Camonet",
			"Level_3_Wall_1_Camonet",
			"Level_3_Wall_2_Camonet",
			"Level_3_Wall_3_Camonet",
			"tent"
		};
	};
};
class CfgNonAIVehicles
{
	class ProxyAttachment;
	class Proxycompass_modern: ProxyAttachment
	{
		scope=2;
		inventorySlot[]=
		{
			"compass"
		};
		model="\DZ\gear\navigation\compass_modern.p3d";
	};
	class Proxybinoculars: ProxyAttachment
	{
		scope=2;
		inventorySlot[]=
		{
			"binocular"
		};
		model="\DZ\gear\optics\binoculars.p3d";
	};
	class ProxyGasCooker: ProxyAttachment
	{
		scope=2;
		inventorySlot[]=
		{
			"GasCooker"
		};
		model="\dz\gear\cooking\GasCooker.p3d";
	};
	class Proxyflashlight: ProxyAttachment
	{
		scope=2;
		inventorySlot[]=
		{
			"flashlight"
		};
		model="\DZ\gear\tools\flashlight.p3d";
	};
	class Proxytent_medium_packed: ProxyAttachment
	{
		scope=2;
		inventorySlot[]=
		{
			"tent"
		};
		model="\DZ\gear\camping\tent_medium_packed.p3d";
	};
	class Proxytripod_collapsed: ProxyAttachment
	{
		scope=2;
		inventorySlot[]=
		{
			"cookingtripod"
		};
		model="\DZ\gear\cooking\tripod_collapsed.p3d";
	};
	class Proxywalkietalkie: ProxyAttachment
	{
		scope=2;
		inventorySlot[]=
		{
			"walkietalkie"
		};
		model="\DZ\gear\radio\WalkieTalkie.p3d";
	};
	class Proxyfirstaidkit: ProxyAttachment
	{
		scope=2;
		inventorySlot[]=
		{
			"firstaidkit"
		};
		model="\DZ\gear\containers\FirstAidKit.p3d";
	};
	class ProxyWaterproofBag: ProxyAttachment
	{
		scope=2;
		inventorySlot[]=
		{
			"waterproofbag"
		};
		model="\dz\gear\containers\WaterproofBag.p3d";
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
	class Slot_GasCooker
	{
		name="GasCooker";
		displayName="GasCooker";
		ghostIcon="cookingequipment";
	};
	class Slot_compass
	{
		name="Compass";
		displayName="Compass";
		ghostIcon="default";
	};
	class Slot_tent
	{
		name="tent";
		displayName="tent";
		ghostIcon="back";
	};
	class Slot_FirstAid
	{
		name="firstaidkit";
		displayName="firstaidkit";
		ghostIcon="hips";
	};
	class Slot_waterproofbag
	{
		name="waterproofbag";
		displayName="waterproofbag";
		ghostIcon="pouches";
	};
};