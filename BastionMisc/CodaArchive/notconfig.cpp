class CfgPatches
{
	class BRP_gear
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Gear_Optics",
			"DZ_Weapons_Melee",
			"DZ_Gear_Tools",
			"DZ_Gear_Crafting"
		};
	};
};
class CfgMods
{
	class BRP_gear
	{
		dir="coda_gear";
		picture="";
		action="";
		hideName=1;
		hidePicture=1;
		name="coda_gear";
		credits="CodaRP";
		author="CodaRP";
		authorID="0";
		version="1.0";
		extra=0;
		type="mod";
		dependencies[]=
		{
			"World",
			"Game"
		};
		class defs
		{
			class gameScriptModule
			{
				value="";
				files[]=
				{
					"coda_gear/scripts/3_Game"
				};
			};
			class worldScriptModule
			{
				value="";
				files[]=
				{
					"coda_gear/scripts/4_World"
				};
			};
		};
	};
};
class CfgModels
{
	class ruble
	{
		sections[]=
		{
			"WholeObject"
		};
	};
};
class cfgVehicles
{
	class AnimalBase;
	class Man;
	class Clothing_Base;
	class Inventory_Base;
	class Switchable_Base;
	class Edible_Base;
	class Bottle_Base;
	class Clothing;
	class Container_Base;
	class HikingJacket_ColorBase;
	class Item_Base;
	class SurgicalGloves_ColorBase;
	class Box_Base;
	class DirtBikeHelmet_ColorBase;
	class DarkMotoHelmet_ColorBase: clothing//For no more helmet muffle
	{
		soundVoiceType="none";
		soundVoicePriority=5;
	};
	class BRP_uniquekey: Inventory_Base
	{
		scope=2;
		displayName="Unique Key";
		descriptionShort="A unique key that doesn't look like it would fit in a conventional lock. It's emblazoned with a pheonix emblem and the words 'DO NOT COPY' on it. ";
		model="\dz\gear\tools\Handcuff_Keys.p3d";
		animClass="Knife";
		rotationFlags=17;
		RestrainUnlockType=0;
		weight=4;
		itemSize[]={1,2};
		fragility=0.0099999998;
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
							1,
							
							{
								"DZ\gear\tools\data\Handcuff_Key.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\tools\data\Handcuff_Key.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\tools\data\Handcuff_Key_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\tools\data\Handcuff_Key_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\tools\data\Handcuff_Key_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class BRP_motohelmet_black: DarkMotoHelmet_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_motohelmet_black.paa",
			"DZ\characters\headgear\data\MotoHelmetVisor_dark_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"DZ\characters\headgear\data\MotoHelmet.rvmat",
			"DZ\characters\headgear\data\MotoHelmetVisor_nontrans.rvmat"
		};
	};
	class BRP_helmet_purple: DirtBikeHelmet_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_helmet_purple.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_helmet_purple.paa"
		};
	};
	class Fingerless_Gloves_Wool;
	class BRP_fingerlessgloves_armygreen: Fingerless_Gloves_Wool
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_fingerlessgloves_armygreen.paa"
		};
	};
	class BRP_fingerlessgloves_white: Fingerless_Gloves_Wool
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_fingerlessgloves_white.paa"
		};
	};
	class Bear_ColorBase;
	class BRP_teddybear_rooth: Bear_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_teddybear_rooth.paa"
		};
	};
	class BRP_surgicalgloves_black: SurgicalGloves_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_surgicalgloves_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_surgicalgloves_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_surgicalgloves_black.paa"
		};
	};
/*	class BRP_hikingjacket_test: HikingJacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_hikingjacket_testg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_hikingjacket_test.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_hikingjacket_test.paa"
		};
	};*/
/*	class Shirt_ColorBase: Clothing
	{
		itemSize[]={3,2};
		itemsCargoSize[]={5,4};
	};*/
	class BRP_shirt_floral: Shirt_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_shirt_floralg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_shirt_floral.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_shirt_floral.paa"
		};
	};
	class BRP_shirt_armygreen: Shirt_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_shirt_armygreeng.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_shirt_armygreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_shirt_armygreen.paa"
		};
	};
	class BRP_shirt_babyblue: Shirt_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_shirt_babyblueg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_shirt_babyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_shirt_babyblue.paa"
		};
	};
	class BRP_shirt_beige: Shirt_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_shirt_beigeg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_shirt_beige.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_shirt_beige.paa"
		};
	};
	class BRP_shirt_black: Shirt_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_shirt_blackg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_shirt_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_shirt_black.paa"
		};
	};
	class BRP_shirt_burgundy: Shirt_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_shirt_burgundyg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_shirt_burgundy.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_shirt_burgundy.paa"
		};
	};
	class BRP_shirt_cream: Shirt_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_shirt_creamg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_shirt_cream.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_shirt_cream.paa"
		};
	};
	class BRP_shirt_darkbrown: Shirt_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_shirt_darkbrowng.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_shirt_darkbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_shirt_darkbrown.paa"
		};
	};
	class BRP_shirt_darkgrey: Shirt_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_shirt_darkgreyg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_shirt_darkgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_shirt_darkgrey.paa"
		};
	};
	class BRP_shirt_lightbrown: Shirt_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_shirt_lightbrowng.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_shirt_lightbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_shirt_lightbrown.paa"
		};
	};
	class BRP_shirt_lightgrey: Shirt_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_shirt_lightgreyg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_shirt_lightgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_shirt_lightgrey.paa"
		};
	};
	class BRP_shirt_navyblue: Shirt_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_shirt_navyblueg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_shirt_navyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_shirt_navyblue.paa"
		};
	};
	class BRP_shirt_red: Shirt_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_shirt_redg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_shirt_red.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_shirt_red.paa"
		};
	};
	class BRP_shirt_royalblue: Shirt_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_shirt_royalblueg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_shirt_royalblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_shirt_royalblue.paa"
		};
	};
	class BRP_shirt_white: Shirt_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_shirt_whiteg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_shirt_white.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_shirt_white.paa"
		};
	};	

	class BalaclavaMask_ColorBase;
	class BRP_balaclava_edgy: BalaclavaMask_ColorBase
	{
		scope=2;
		color="edgy";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_balaclava_edgy.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_balaclava_edgy.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_balaclava_edgy.paa"
		};
	};
	class BRP_skullmask_blue: BalaclavaMask_ColorBase
	{
		scope=2;
		color="royalblue";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_skullmask_blue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_skullmask_blue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_skullmask_blue.paa"
		};
	};
	class BRP_skullmask_red: BalaclavaMask_ColorBase
	{
		scope=2;
		color="red";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_skullmask_red.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_skullmask_red.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_skullmask_red.paa"
		};
	};
	class BRP_skullmask_yellow: BalaclavaMask_ColorBase
	{
		scope=2;
		color="yellow";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_skullmask_yellow.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_skullmask_yellow.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_skullmask_yellow.paa"
		};
	};
	class BRP_skullmask_green: BalaclavaMask_ColorBase
	{
		scope=2;
		color="green";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_skullmask_green.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_skullmask_green.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_skullmask_green.paa"
		};
	};
	class MedicalScrubsShirt_ColorBase;
	class BRP_scrubs_black: MedicalScrubsShirt_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_scrubs_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_scrubs_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_scrubs_black.paa"
		};
	};
	class BRP_hikingjacket_lightgrey_aegis: HikingJacket_ColorBase
	{
		scope=2;
		descriptionShort="Property of AEGIS CORPORATION";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_hikingjacket_lightgrey_aegisg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_hikingjacket_lightgrey_aegis.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_hikingjacket_lightgrey_aegis.paa"
		};
	};
	class PlateCarrierVest;
	class PlateCarrierHolster;
	class PlateCarrierPouches;
//Note: All the plate carrier parts come from a single .paa file
	class BRP_platecarrier_aegis: PlateCarrierVest
	{
		scope=2;
		descriptionShort="Property of AEGIS CORPORATION";
		inventorySlot[]=
		{
			"Vest"
		};
		hiddenSelections[]=
		{
			"camoGround",
			"camoMale",
			"camoFemale"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_platecarrier_aegis.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_platecarrier_aegis.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_platecarrier_aegis.paa"
		};
	};
	class BRP_platecarrier_holster_aegis: PlateCarrierHolster
	{
		scope=2;
		descriptionShort="Property of AEGIS CORPORATION";
		hiddenSelections[]=
		{
			"camoGround",
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_platecarrier_aegis.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_platecarrier_aegis.paa"
		};
	};
	class BRP_platecarrier_pouches_aegis: PlateCarrierPouches
	{
		scope=2;
		descriptionShort="Property of AEGIS CORPORATION";
		hiddenSelections[]=
		{
			"camoGround",
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_platecarrier_aegis.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_platecarrier_aegis.paa"
		};
	};
	class BRP_platecarrier_white: PlateCarrierVest
	{
		scope=2;
		inventorySlot[]=
		{
			"Vest"
		};
		hiddenSelections[]=
		{
			"camoGround",
			"camoMale",
			"camoFemale"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_platecarrier_white.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_platecarrier_white.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_platecarrier_white.paa"
		};
	};
	class BRP_platecarrier_holster_white: PlateCarrierHolster
	{
		scope=2;
		hiddenSelections[]=
		{
			"camoGround",
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_platecarrier_white.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_platecarrier_white.paa"
		};
	};
	class BRP_platecarrier_pouches_white: PlateCarrierPouches
	{
		scope=2;
		hiddenSelections[]=
		{
			"camoGround",
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_platecarrier_white.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_platecarrier_white.paa"
		};
	};
	class Baseballcap_ColorBase: Clothing
	/*{
		itemSize[]={2,2};
	}*/;
	class BRP_baseballcap_crow: Baseballcap_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_baseballcap_crow.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_baseballcap_crow.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_baseballcap_crow.paa"
		};
	};
	class BRP_baseballcap_aegis: Baseballcap_ColorBase
	{
		scope=2;
		descriptionShort="Property of AEGIS CORPORATION";
		visibilityModifier=0.94999999;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_baseballcap_aegis.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_baseballcap_aegis.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_baseballcap_aegis.paa"
		};
	};
	class Armband_ColorBase: Clothing
	/*{
		itemSize[]={1,2};
	}*/;
	class BRP_armband_aegis: Armband_ColorBase
	{
		scope=2;
		descriptionShort="Property of AEGIS CORPORATION";
		color="aegis";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_armband_aegis.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_aegis.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_aegis.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_aegis.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_aegis.paa"
		};
	};
	class BRP_armband_armada: Armband_ColorBase
	{
		scope=2;
		color="armada";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_armband_armada.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_armada.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_armada.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_armada.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_armada.paa"
		};
	};
	class BRP_armband_enclave: Armband_ColorBase
	{
		scope=2;
		color="enclave";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_armband_enclave.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_enclave.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_enclave.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_enclave.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_enclave.paa"
		};
	};
	class MiniDress_ColorBase: Clothing
	/*{
		itemSize[]={2,2};
	}*/;
	class BRP_dress_weddingdress: MiniDress_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_dress_weddingdress.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_dress_weddingdress.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_dress_weddingdress.paa"
		};
	};
	class BRP_dress_pinklace: MiniDress_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_dress_pinklace.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_dress_pinklace.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_dress_pinklace.paa"
		};
	};
	class BRP_dress_camo: MiniDress_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_dress_camo.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_dress_camo.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_dress_camo.paa"
		};
	};
	class BRP_dress_galaxy: MiniDress_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_dress_galaxy.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_dress_galaxy.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_dress_galaxy.paa"
		};
	};
	class EvocatusBillboard1Base;//Requires Evocatus Signs and Billboards
	class BRP_billboard_1_map: EvocatusBillboard1Base
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\big_map_sign.paa"
		};
	};
	class BRP_billboard_vodkasign: EvocatusBillboard1Base
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\vodkasign.paa"
		};
	};
	class BRP_billboard_warningsign: EvocatusBillboard1Base
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_warningsign.paa"
		};
	};
	class BRP_billboard_1_map2: EvocatusBillboard1Base
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\big_map_sign2.paa"
		};
	};
	class BRP_billboard_1_test: EvocatusBillboard1Base
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\billboard_test.paa"
		};
	};
	class EvocatusFatBillboard1Base;
	class BRP_fatbillboard_1_test: EvocatusFatBillboard1Base
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\billboard_test2.paa"
		};
	};
	class BRP_fatbillboard_1_testmap: EvocatusBillboard1Base
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\billboard_test2.paa"
		};
	};
	class EvocatusWoodSign2Base;
	class BRP_floorsign_amelia: EvocatusWoodSign2Base
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\amelias_wardrobe.paa",
			"BastionMod\BastionClothing\Retextures\data\amelias_wardrobe.paa"
		};
	};
	class BRP_floorsign_berrymindful: EvocatusWoodSign2Base
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\berry_mindful.paa",
			"BastionMod\BastionClothing\Retextures\data\berry_mindful.paa"
		};
	};
	class EvocatusBillboard3Base;
	class BRP_billboard_aegis: EvocatusBillboard3Base
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\aegisbillboard.paa",
		};
	};
	class CargoPants_ColorBase: Clothing
	/*{
		itemSize[]={3,2};
	}*/;
	class BRP_cargopants_armygreen: CargoPants_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_cargopants_armygreeng.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_cargopants_armygreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_cargopants_armygreen.paa"
		};
	};
	class BRP_cargopants_lightgrey: CargoPants_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_cargopants_lightgreyg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_cargopants_lightgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_cargopants_lightgrey.paa"
		};
	};
	class BRP_cargopants_white: CargoPants_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_cargopants_whiteg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_cargopants_white.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_cargopants_white.paa"
		};
	};
	class PowderedMilk;
	class BRP_yeast: PowderedMilk
	{
		scope=2;
		displayName="Yeast";
		descriptionShort="A packet of plain ol' yeast";
		model="\dz\gear\cultivation\tomato_seeds_pack.p3d";
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_yeast.paa"
		};
	};
	class SmershVest: Clothing
	/*{
		itemsCargoSize[]={6,4};
	}*/;
	class SmershBag: Clothing
	/*{
		itemsCargoSize[]={5,4};
	}*/;
	class BRP_smershvest_armygreen: SmershVest
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_smersh_armygreeng.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_smersh_armygreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_smersh_armygreen.paa"
		};
	};
	class BRP_smershbag_armygreen: Smershbag
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_smersh_armygreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_smersh_armygreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_smersh_armygreen.paa"
		};
	};
	class BRP_smershvest_beige: SmershVest
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_smersh_beigeg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_smersh_beige.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_smersh_beige.paa"
		};
	};
	class BRP_smershbag_beige: Smershbag
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_smersh_beige.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_smersh_beige.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_smersh_beige.paa"
		};
	};
	class BRP_smershvest_black: SmershVest
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_smersh_blackg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_smersh_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_smersh_black.paa"
		};
	};
	class BRP_smershbag_black: Smershbag
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_smersh_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_smersh_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_smersh_black.paa"
		};
	};
	class BRP_smershvest_burgundy: SmershVest
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_smersh_burgundyg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_smersh_burgundy.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_smersh_burgundy.paa"
		};
	};
	class BRP_smershbag_burgundy: Smershbag
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_smersh_burgundy.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_smersh_burgundy.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_smersh_burgundy.paa"
		};
	};
	class BRP_smershvest_darkbrown: SmershVest
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_smersh_darkbrowng.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_smersh_darkbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_smersh_darkbrown.paa"
		};
	};
	class BRP_smershbag_darkbrown: Smershbag
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_smersh_darkbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_smersh_darkbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_smersh_darkbrown.paa"
		};
	};
	class BRP_smershvest_darkgrey: SmershVest
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_smersh_darkgreyg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_smersh_darkgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_smersh_darkgrey.paa"
		};
	};
	class BRP_smershbag_darkgrey: Smershbag
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_smersh_darkgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_smersh_darkgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_smersh_darkgrey.paa"
		};
	};
	class BRP_smershvest_lightbrown: SmershVest
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_smersh_lightbrowng.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_smersh_lightbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_smersh_lightbrown.paa"
		};
	};
	class BRP_smershbag_lightbrown: Smershbag
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_smersh_lightbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_smersh_lightbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_smersh_lightbrown.paa"
		};
	};
	class BRP_smershvest_lightgrey: SmershVest
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_smersh_lightgreyg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_smersh_lightgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_smersh_lightgrey.paa"
		};
	};
	class BRP_smershbag_lightgrey: Smershbag
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_smersh_lightgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_smersh_lightgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_smersh_lightgrey.paa"
		};
	};
	class BRP_smershvest_navyblue: SmershVest
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_smersh_navyblueg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_smersh_navyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_smersh_navyblue.paa"
		};
	};
	class BRP_smershbag_navyblue: Smershbag
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_smersh_navyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_smersh_navyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_smersh_navyblue.paa"
		};
	};
	class BRP_smershvest_olivegreen: SmershVest
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_smersh_olivegreeng.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_smersh_olivegreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_smersh_olivegreen.paa"
		};
	};
	class BRP_smershbag_olivegreen: Smershbag
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_smersh_olivegreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_smersh_olivegreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_smersh_olivegreen.paa"
		};
	};
	class BRP_smershvest_white: SmershVest
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_smersh_whiteg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_smersh_white.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_smersh_white.paa"
		};
	};
	class BRP_smershbag_white: Smershbag
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_smersh_white.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_smersh_white.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_smersh_white.paa"
		};
	};
	class WaterBottle: Bottle_Base
	{
		scope=2;
		hiddenSelections[]=
		{
			"zbytek",
			"zbytek",
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_waterbottle_empty.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_waterbottle_empty.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_waterbottle_empty.paa"
		};
	};
	class BRP_waterbottle_test: WaterBottle
	{
		scope=2;
		hiddenSelections[]=
		{
			"zbytek",
			"zbytek",
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_waterbottle_test.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_waterbottle_test.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_waterbottle_test.paa"
		};
	};
	class Rice;
	class BRP_sugar: Rice
	{
		scope=2;
		displayName="Sugar";
		descriptionShort="We're going down down";
		hiddenSelections[]=
		{
			"zbytek",
			"zbytek",
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_sugar.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sugar.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sugar.paa"
		};
	};
	class BRP_flour: Rice
	{
		scope=2;
		displayName="Flour";
		descriptionShort="White powdery substance...";
		hiddenSelections[]=
		{
			"zbytek",
			"zbytek",
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_flour.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_flour.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_flour.paa"
		};
	};
	class BRP_milk: PowderedMilk//Test item
	{
		scope=2;
		hiddenSelections[]=
		{
			"zbytek",
			"zbytek",
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_milk.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_milk.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_milk.paa"
		};
	};
	class BRP_clifbar: PowderedMilk
	{
		scope=2;
		displayName="Clif Bar";
		descriptionShort="Clif Bar";
		hiddenSelections[]=
		{
			"zbytek",
			"zbytek",
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_clifbar.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_clifbar.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_clifbar.paa"
		};
	};
	class BRP_cheetos: PowderedMilk
	{
		scope=2;
		displayName="Flamin' Hot Cheetos";
		descriptionShort="Flamin' Hot Cheetos";
		hiddenSelections[]=
		{
			"zbytek",
			"zbytek",
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_cheetos.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_cheetos.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_cheetos.paa"
		};
	};
	class Book_Base;
	class ItemBook: Book_Base
	{
		//itemsize[]={1,2};
		inventorySlot[]=
		{
			"codabook1",
			"codabook2",
			"codabook3",
			"codabook4",
			"codabook5",
			"codabook6",
			"codabook7",
			"codabook8",
			"codabook9",
			"codabook10",
			"codabook11",
			"codabook12",
			"codabook13",
			"codabook14",
			"codabook15",
			"codabook16",
			"codabook17",
			"codabook18",
			"codabook19",
			"codabook20",
			"codabook21",
			"codabook22",
			"codabook23",
			"codabook24",
			"codabook25",
			"codabook26",
			"codabook27",
			"codabook28",
			"codabook29",
			"codabook30",
			"codabook31",
			"codabook32"
		};
	};
	class BRP_bookbase: ItemBook//Baseclass for note compatible books
	{
		scope=0;
		//itemsize[]={1,2};
	};
	class BRP_journal: coda_bookbase
	{
		scope=2;
		title="Journal";
		author="PRIVATE";
		displayName="Journal";
		descriptionShort="A personal journal";
		rotationFlags=1;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_journal.paa"
		};
		attachments[]=
		{
			"coda_paper1",
			"coda_paper2",
			"coda_paper3",
			"coda_paper4",
			"coda_paper5",
			"coda_paper6",
			"coda_paper7",
			"coda_paper8",
			"coda_paper9",
			"coda_paper10",
			"coda_paper11",
			"coda_paper12",
			"coda_paper13",
			"coda_paper14",
			"coda_paper15",
			"coda_paper16"
		};
	};
	class BRP_journaltree: coda_bookbase
	{
		scope=2;
		title="Journal";
		author="PRIVATE";
		displayName="Journal";
		descriptionShort="A personal journal";
		rotationFlags=1;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_journaltree.paa"
		};
		attachments[]=
		{
			"coda_paper1",
			"coda_paper2",
			"coda_paper3",
			"coda_paper4",
			"coda_paper5",
			"coda_paper6",
			"coda_paper7",
			"coda_paper8",
			"coda_paper9",
			"coda_paper10",
			"coda_paper11",
			"coda_paper12",
			"coda_paper13",
			"coda_paper14",
			"coda_paper15",
			"coda_paper16"
		};
	};
	class BRP_journal_pheonix: coda_bookbase
	{
		scope=2;
		title="Journal";
		author="PRIVATE";
		displayName="Journal";
		descriptionShort="A personal journal emblazoned with an emblem of some sort";
		rotationFlags=1;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_journal_pheonix.paa"
		};
		attachments[]=
		{
			"coda_paper1",
			"coda_paper2",
			"coda_paper3",
			"coda_paper4",
			"coda_paper5",
			"coda_paper6",
			"coda_paper7",
			"coda_paper8",
			"coda_paper9",
			"coda_paper10",
			"coda_paper11",
			"coda_paper12",
			"coda_paper13",
			"coda_paper14",
			"coda_paper15",
			"coda_paper16"
		};
	};
	class BRP_dgr: coda_bookbase
	{
		scope=2;
		title="Deep Green Resistance";
		author="Derrick Jensen";
		displayName="Deep Green Resistance";
		descriptionShort="Deep Green Resistance";
		rotationFlags=1;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_dgr.paa"
		};
	};
	class BRP_blacknotebook: coda_bookbase
	{
		scope=2;
		title="Black Notebook";
		author="PRIVATE";
		displayName="Black Notebook";
		descriptionShort="A black notebook containing notes of some sort.";
		rotationFlags=1;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_blacknotebook.paa"
		};
		attachments[]=
		{
			"coda_paper1",
			"coda_paper2",
			"coda_paper3",
			"coda_paper4",
			"coda_paper5",
			"coda_paper6",
			"coda_paper7",
			"coda_paper8",
			"coda_paper9",
			"coda_paper10",
			"coda_paper11",
			"coda_paper12",
			"coda_paper13",
			"coda_paper14",
			"coda_paper15",
			"coda_paper16"
		};
	};
	class BRP_blankjournal_junehall: coda_bookbase
	{
		scope=2;
		title="Personalized Journal";
		author="PRIVATE";
		displayName="Black Notebook";
		descriptionShort="A notebook containing with the personalization of 'June Hall.'";
		rotationFlags=1;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_blankjournal_junehall.paa"
		};
		attachments[]=
		{
			"coda_paper1",
			"coda_paper2",
			"coda_paper3",
			"coda_paper4",
			"coda_paper5",
			"coda_paper6",
			"coda_paper7",
			"coda_paper8",
			"coda_paper9",
			"coda_paper10",
			"coda_paper11",
			"coda_paper12",
			"coda_paper13",
			"coda_paper14",
			"coda_paper15",
			"coda_paper16"
		};
	};
	class BRP_journal_armada: coda_bookbase
	{
		scope=2;
		title="Journal";
		author="PRIVATE";
		displayName="Journal";
		descriptionShort="This journal seems to have some kind of golden emblem on it.";
		rotationFlags=1;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_journal_armada.paa"
		};
		attachments[]=
		{
			"coda_paper1",
			"coda_paper2",
			"coda_paper3",
			"coda_paper4",
			"coda_paper5",
			"coda_paper6",
			"coda_paper7",
			"coda_paper8",
			"coda_paper9",
			"coda_paper10",
			"coda_paper11",
			"coda_paper12",
			"coda_paper13",
			"coda_paper14",
			"coda_paper15",
			"coda_paper16"
		};
	};
	class SodaCan_ColorBase;
	class BRP_beer: SodaCan_ColorBase//Baseclass for beers
	{
		class AnimEvents
		{
			class SoundWeapon
			{
				class SodaCan_in_B
				{
					soundSet="SodaCan_in_B_SoundSet";
					id=202;
				};
				class WellPond_loop
				{
					soundSet="WellPond_loop_SoundSet";
					id=209;
				};
				class WellBottle_loop
				{
					soundSet="WellBottle_loop_SoundSet";
					id=210;
				};
				class pickup
				{
					soundSet="SodaCan_pickup_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="SodaCan_drop_SoundSet";
					id=898;
				};
			};
		};
		class Nutrition
		{
			fullnessIndex=1;
			energy=43;
			water=100;
			nutritionalIndex=75;
			toxicity=0.0099999998;
			digestibility=2;
			agents=512;//value doesn't work for drunk mod
		};
	};
	class BRP_dudweiser: coda_beer
	{
		scope=2;
		displayName="Dudweiser";
		descriptionShort="Dude. It's a Dudweiser";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_dudweiser.paa"
		};
	};
	class BRP_pliny: coda_beer
	{
		scope=2;
		displayName="Pliny";
		descriptionShort="Blimey it's a Pliny";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_pliny.paa"
		};
	};
	class BRP_asahi: coda_beer
	{
		scope=2;
		displayName="Asahi";
		descriptionShort="Nani? Asahi? Hai.";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_asahi.paa"
		};
	};
	class BRP_londonpride: coda_beer
	{
		scope=2;
		displayName="London Pride";
		descriptionShort="Oye bruv! I'll 'av anuva init!";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_londonpride.paa"
		};
	};
	class BRP_sierranevada: coda_beer
	{
		scope=2;
		displayName="Sierra Nevada";
		descriptionShort="Have this beer with your friends. Not the other way around.";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_sierranevada.paa"
		};
	};
	class BRP_irnbru: coda_beer
	{
		scope=2;
		displayName="IRN BRU";
		descriptionShort="Who actually drinks this?";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_irnbru.paa"
		};
	};
	class BRP_behoppy: coda_beer
	{
		scope=2;
		displayName="Be Hoppy";
		descriptionShort="Or don't. Just drink the beer.";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_behoppy.paa"
		};
	};
	class HuntingKnife;
	class BRP_huntingknife_black: HuntingKnife
	{
		scope=2;
		hiddenSelections[]=
		{
			"zbytek",
			"zbytek",
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_huntingknife_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingknife_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingknife_black.paa"
		};
	};
	class DisinfectantAlcohol;
	class DisinfectantSpray: Edible_Base
	{
		scope=2;
		descriptionShort="WARNING. DANGEROUS WHEN INJECTED INTO ONESELF.";//Edited vanilla description
	};
	class BRP_soap: Box_Base
	{
		scope=2
		displayName="Bar of Soap";
		descriptionShort="It's a bar of homemade soap. It's just as you would expect.";
		model="\dz\weapons\ammunition\545x39_20RoundBox.p3d";
		itemsize[]={1,1};	
		rotationFlags=17;
		weight=85;
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_soap.paa"
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
							1,
							
							{
								"DZ\weapons\ammunition\data\545x39box.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\weapons\ammunition\data\545x39box.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\weapons\ammunition\data\545x39box_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\weapons\ammunition\data\545x39box_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\weapons\ammunition\data\545x39box_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class BRP_tarotcards: Box_Base
	{
		scope=2
		displayName="Tarot Cards";
		descriptionShort="A box of fortunetelling tarot cards.";
		itemsize[]={1,1};
		hiddenSelections[]=
		{
			"camoGround",
			"zbytek",
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_tarotcards.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_tarotcards.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_tarotcards.paa"
		};
		model="\dz\weapons\ammunition\545x39_20RoundBox.p3d";
		rotationFlags=17;
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
							1,
							
							{
								"DZ\weapons\ammunition\data\545x39box.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\weapons\ammunition\data\545x39box.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\weapons\ammunition\data\545x39box_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\weapons\ammunition\data\545x39box_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\weapons\ammunition\data\545x39box_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class BRP_alcohol_small: Bottle_Base//base class for alcohol tinctures
	{
		scope=0;
		model="\dz\gear\medical\alfa.p3d";
		varLiquidTypeInit=781;
		weight=25;
		itemSize[]={1,2};

		destroyOnEmpty=0;
		varQuantityDestroyOnMin=1;
		liquidContainerType="1 + 2 + 4 + 8 + 16 + 32 + 64 + 128 + 256 + 333 + 334 + 512 + 1024 + 2048 + 4096 + 8192 + 16384 + 32768 + 65536  - (1 + 2 + 4 + 8 + 16 + 32 + 64 + 128 + 256)";
		varQuantityInit=250;
		varQuantityMin=0;
		varQuantityMax=250;
		isMeleeWeapon=1;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=30;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\gear\medical\data\alfa.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\medical\data\alfa.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\medical\data\alfa_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\medical\data\alfa_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\medical\data\alfa_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class GlassBottle_in_B
				{
					soundSet="GlassBottle_in_B_SoundSet";
					id=202;
				};
				class GlassBottle_in_C
				{
					soundSet="GlassBottle_in_C_SoundSet";
					id=203;
				};
				class WaterBottle_in_C1
				{
					soundSet="WaterBottle_in_C1_SoundSet";
					id=204;
				};
				class GlassBottle_out_A
				{
					soundSet="GlassBottle_out_A_SoundSet";
					id=205;
				};
				class GlassBottle_out_B
				{
					soundSet="GlassBottle_out_B_SoundSet";
					id=206;
				};
				class WellPond_loop
				{
					soundSet="WellPond_loop_SoundSet";
					id=209;
				};
				class WellBottle_loop
				{
					soundSet="WellBottle_loop_SoundSet";
					id=210;
				};
			};
		};
	};
	class BRP_smirnorf: coda_alcohol_small
	{
		scope=2;
		displayName="Smirnorf";
		descriptionShort="Quite the kick for a knockoff";
		hiddenSelections[]=
		{
			"zbytek",
			"zbytek",
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_smirnorf.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_smirnorf.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_smirnorf.paa"
		};
	};
	class BRP_tequila: coda_alcohol_small
	{
		scope=2;
		displayName="Tequila";
		descriptionShort="It might kill you. It might not.";
		hiddenSelections[]=
		{
			"zbytek",
			"zbytek",
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_tequila.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_tequila.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_tequila.paa"
		};
	};
	class BRP_whiskey: coda_alcohol_small
	{
		scope=2;
		displayName="Whiskey";
		descriptionShort="Whiskey... I think.";
		hiddenSelections[]=
		{
			"zbytek",
			"zbytek",
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_whiskey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_whiskey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_whiskey.paa"
		};
	};
	class SewingKit;
	class BRP_suturekit: SewingKit
	{
		scope=2;
		displayName="Suture Kit";
		descriptionShort="It contains all the necessary equipment for suturing and stitching up wounds.";
		model="\dz\gear\medical\StartKit.p3d";
		hiddenSelections[]=
		{
			"zbytek",
			"zbytek",
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_suturekit.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_suturekit.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_suturekit.paa"
		};
	};
	class TetracyclineAntibiotics;
	class BRP_prozac: TetracyclineAntibiotics
	{
		scope=2;
		displayName="Prozac";
		descriptionShort="The pack reads 'Each capsule contains Fluoxetine Hydrochloride equivalent to Fluoxetine 20mg.' ";
		varQuantityInit=10;
		varQuantityMin=0;
		varQuantityMax=10;
		varQuantityDestroyOnMin=1;
		hiddenSelections[]=
		{
			"zbytek",
			"zbytek",
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_prozac.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_prozac.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_prozac.paa"
		};
		class Medicine
		{
			prevention=0.75;
			treatment=0.5;
			diseaseExit=0;
		};
	};
	class BRP_tramadol: TetracyclineAntibiotics
	{
		scope=2;
		displayName="Tramadol";
		descriptionShort="The pack reads 'Each capsule contains 50mg Tramadol Hydrochloride' ";
		varQuantityInit=10;
		varQuantityMin=0;
		varQuantityMax=10;
		varQuantityDestroyOnMin=1;
		hiddenSelections[]=
		{
			"zbytek",
			"zbytek",
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_tramadol.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_tramadol.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_tramadol.paa"
		};
	};
	class Injector_Base: Inventory_Base//Baseclass for shock injector mod plugin
	{
		model="\dz\gear\medical\Epinephrine.p3d";
		rotationFlags=17;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=1;
		itemSize[]={1,2};
		weight=60;
		lootCategory="Medical";
		lootTag[]=
		{
			"Medic"
		};
		hiddenSelections[]=
        {
            "zbytek"
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
							1,
							
							{
								"DZ\gear\medical\data\epipen.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\medical\data\epipen.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\medical\data\epipen_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\medical\data\epipen_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\medical\data\epipen_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		
		class AnimEvents
		{
			class SoundWeapon
			{
				class Morphine_spear
				{
					soundSet="Morphine_spear_SoundSet";
					id=201;
				};
				class Morphine_out
				{
					soundSet="Morphine_out_SoundSet";
					id=202;
				};
			};
		};
	};
	class ShockInjector: Injector_Base//Test object for diazepam syringe. Can be used in current state. Might want to use different epipen texture. Texture is currently yellow and unlabeled
	{
		scope=2;
		displayName="Shock Auto-Injector";
		descriptionShort="An experimental injection that will slowly lower the heartrate of the user until they collapsed unconscious.";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_epi.paa"
		};
	};
	class BRP_diazepam_syringe: ShockInjector//Recipe (Syringe + coda_diazepam = coda_diazepam_syringe)
	{
		scope=2;
		displayName="Filled Syringe";
		descriptionShort="A syringe filled with diazepam";
		model="\dz\gear\medical\syringe_Full.p3d";
		weight=110;
		//itemSize[]={1,2};
		hiddenSelections[]=
		{
			"camo"
		};
		hiddenSelectionsTextures[]=
		{
			"\dz\gear\medical\data\SyringeFluid_Grey_CA.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=20;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\gear\medical\data\Syringe.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\medical\data\Syringe.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\medical\data\Syringe_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\medical\data\Syringe_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\medical\data\Syringe_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class VitaminBottle;
	class BRP_codeine: VitaminBottle
	{
		scope=2;
		displayName="Codeine";
		descriptionShort="The bottle reads Codeine Phosphate/APAP 60/300mg.";
		model="\dz\gear\medical\dexamphetamine.p3d";
		varQuantityInit=40;
		varQuantityMin=0;
		varQuantityMax=40;
		varQuantityDestroyOnMin=1;
		hiddenSelections[]=
		{
			"zbytek",
			"zbytek",
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_codeine.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_codeine.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_codeine.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=50;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\gear\medical\data\dexamphetamine.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\medical\data\dexamphetamine.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\medical\data\dexamphetamine_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\medical\data\dexamphetamine_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\medical\data\dexamphetamine_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class BRP_risperidone: VitaminBottle
	{
		scope=2;
		displayName="Risperidone";
		descriptionShort="The bottle reads 'Each tablet contains Risperidone 1mg'.";
		model="\dz\gear\medical\dexamphetamine.p3d";
		varQuantityInit=20;
		varQuantityMin=0;
		varQuantityMax=20;
		varQuantityDestroyOnMin=1;
		hiddenSelections[]=
		{
			"zbytek",
			"zbytek",
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_risperidone.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_risperidone.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_risperidone.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=50;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\gear\medical\data\dexamphetamine.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\medical\data\dexamphetamine.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\medical\data\dexamphetamine_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\medical\data\dexamphetamine_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\medical\data\dexamphetamine_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class BRP_clozapine: VitaminBottle
	{
		scope=2;
		displayName="Clozapine";
		descriptionShort="The bottle reads 'Each tablet contains Clozapine 50mg'.";
		model="\dz\gear\medical\dexamphetamine.p3d";
		varQuantityInit=20;
		varQuantityMin=0;
		varQuantityMax=20;
		varQuantityDestroyOnMin=1;
		hiddenSelections[]=
		{
			"zbytek",
			"zbytek",
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_clozapine.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_clozapine.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_clozapine.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=50;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\gear\medical\data\dexamphetamine.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\medical\data\dexamphetamine.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\medical\data\dexamphetamine_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\medical\data\dexamphetamine_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\medical\data\dexamphetamine_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};
	/*class BRP_dexamphetaminetest: VitaminBottle//test
	{
		scope=2;
		displayName="dexamphetaminetest";
		descriptionShort="dexamphetaminetest";
		model="\dz\gear\medical\dexamphetamine.p3d";
		hiddenSelections[]=
		{
			"zbytek",
			"zbytek",
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"\dz\gear\medical\data\dexamphetamine_co.paa",
			"\dz\gear\medical\data\dexamphetamine_co.paa",
			"\dz\gear\medical\data\dexamphetamine_co.paa"
		};
		varQuantityInit=50;
		varQuantityMin=0;
		varQuantityMax=50;
		varQuantityDestroyOnMin=1;
		itemSize[]={1,2};
		weight=20;
		stackedUnit="pills";
		quantityBar=0;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=50;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\gear\medical\data\dexamphetamine.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\medical\data\dexamphetamine.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\medical\data\dexamphetamine_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\medical\data\dexamphetamine_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\medical\data\dexamphetamine_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class Medicine
		{
			prevention=0.75;
			treatment=0.5;
			diseaseExit=0;
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class VitaminBottle_open
				{
					soundSet="VitaminBottle_open_SoundSet";
					id=201;
				};
				class VitaminBottle_shake
				{
					soundSet="VitaminBottle_shake_SoundSet";
					id=202;
				};
				class VitaminBottle_close
				{
					soundSet="VitaminBottle_close_SoundSet";
					id=203;
				};
				class pickUpItem
				{
					soundSet="vitaminbottle_pickup_SoundSet";
					id=797;
				};
			};
		};
	};*/
	class JoggingShoes_ColorBase;
	class BRP_joggingshoes_black: JoggingShoes_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_joggingshoes_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_joggingshoes_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_joggingshoes_black.paa"
		};
	};
	class BRP_joggingshoes_burgundy: JoggingShoes_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_joggingshoes_burgundy.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_joggingshoes_burgundy.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_joggingshoes_burgundy.paa"
		};
	};
	class GasMask: clothing
	{
		soundVoiceType="none";
		soundVoicePriority=3;
	};
	class GP5GasMask: clothing
	{
		soundVoiceType="none";
		soundVoicePriority=5;
	};
	class BRP_gp5gasmask_black: GP5GasMask
	{
		scope=2;
		soundVoiceType="none";
		soundVoicePriority=5;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_gp5gasmask_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_gp5gasmask_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_gp5gasmask_black.paa"
		};
	};
	class MilitaryBeret_ColorBase;
	class BRP_beret_black: MilitaryBeret_ColorBase
	{
		scope=2;
		model="\DZ\characters\headgear\MilitaryBeret_NZ_g.p3d";
		lootTag[]=
		{
			"Military_west"
		};
		class ClothingTypes
		{
			male="\DZ\characters\headgear\MilitaryBeret_NZ_m.p3d";
			female="\DZ\characters\headgear\MilitaryBeret_NZ_f.p3d";
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_beret_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_beret_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_beret_black.paa"
		};
	};
	class BRP_beret_white: MilitaryBeret_ColorBase
	{
		scope=2;
		model="\DZ\characters\headgear\MilitaryBeret_NZ_g.p3d";
		class ClothingTypes
		{
			male="\DZ\characters\headgear\MilitaryBeret_NZ_m.p3d";
			female="\DZ\characters\headgear\MilitaryBeret_NZ_f.p3d";
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_beret_white.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_beret_white.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_beret_white.paa"
		};
	};
	class SmallProtectorCase: Container_Base
	/*{
		repairableWithKits[]={8};//epoxy
		repairCosts[]={25};
	}*/;
	class BRP_box: SmallProtectorCase//Small blue box
	{
		scope=2;
		displayName="A Box";
		descriptionShort="It looks like a container of some sort.";
		model="\dz\gear\tools\sewing_kit.p3d";
		itemSize[]={1,2};
		itemsCargoSize[]={2,2};
		hiddenSelections[]=
		{
			"zbytek",
			"zbytek",
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_box.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_box.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_box.paa"
		};
	};
	class BRP_protectorcase_black: SmallProtectorCase
	{
		scope=2;
		hiddenSelections[]=
		{
			"zbytek",
			"zbytek",
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_protectorcase_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_protectorcase_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_protectorcase_black.paa"
		};
	};
	class BRP_protectorcase_pheonix: SmallProtectorCase
	{
		scope=2;
		descriptionShort="There seems to be an emblem of some sort on the front of the case. Perhaps there's some meaning behind it.";
		hiddenSelections[]=
		{
			"zbytek",
			"zbytek",
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_protectorcase_pheonix.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_protectorcase_pheonix.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_protectorcase_pheonix.paa"
		};
	};
	class BRP_protectorcase_medical: SmallProtectorCase
	{
		scope=2;
		hiddenSelections[]=
		{
			"zbytek",
			"zbytek",
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_protectorcase_medical.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_protectorcase_medical.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_protectorcase_medical.paa"
		};
	};
	class InjectionVial;//All custom injectable meds will function as base game vials. Recipes will need to be adjusted to disable/enable them
	/*class BRP_injectionvial_test: InjectionVial//test
	{
		scope=2;
		model="\dz\gear\medical\InjectionVial.p3d";
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_injectionvial_test.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_injectionvial_test.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_injectionvial_test.paa"
		};
	};*/
	class BRP_injectionvial: Inventory_Base//custom class to only have one recipe fire when combining with syringe
	{
		scope=0;
		displayName="$STR_CfgVehicles_InjectionVial0";
		descriptionShort="$STR_CfgVehicles_InjectionVial1";
		model="\dz\gear\medical\InjectionVial.p3d";
		itemSize[]={1,1};
		weight=50;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=20;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\gear\medical\data\InjectionVial.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\medical\data\InjectionVial.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\medical\data\InjectionVial_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\medical\data\InjectionVial_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\medical\data\InjectionVial_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet="injectionvial_pickup_SoundSet";
					id=797;
				};
			};
		};
	};
	class BRP_diazepam: coda_injectionvial
	{
		scope=2;
		displayName="Diazepam Injection Vial";
		descriptionShort="An amber glass vial filled with diazepam medication";
		model="\dz\gear\medical\InjectionVial.p3d";
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_diazepam.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_diazepam.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_diazepam.paa"
		};
	};
	class BRP_lidocaine: InjectionVial
	{
		scope=2;
		displayName="Lidocaine Injection Vial";
		descriptionShort="An amber glass vial filled with lidocaine medication";
		//model="\dz\gear\medical\InjectionVial.p3d";
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_lidocaine.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_lidocaine.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_lidocaine.paa"
		};
	};
	class BRP_ketamine: InjectionVial
	{
		scope=2;
		displayName="Ketamine Injection Vial";
		descriptionShort="An amber glass vial filled with ketamine medication";
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_ketamine.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ketamine.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ketamine.paa"
		};
	};
	class BRP_insulin: InjectionVial
	{
		scope=2;
		displayName="Insulin Injection Vial";
		descriptionShort="An amber glass vial filled with insulin medication";
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_insulin.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_insulin.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_insulin.paa"
		};
	};
	class FirstAidKit;
	class BRP_pouch_black: FirstAidKit
	{
		scope=2;
		displayName="Belt Pouch";
		descriptionShort="A supply pouch designed to attach to a belt.";
		//canBeDigged=0;//Disallows item to be buried
		inventorySlot[]=
		{
			"Belt_Left"
		};
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_pouch_black.paa"
		};
	};
	class DesignerGlasses;
	class BRP_designersg_black: DesignerGlasses
	{
		scope=2;
		hiddenSelections[]=
		{
			"zbytek",
			"zbytek",
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_designersg_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_designersg_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_designersg_black.paa"
		};
	};
	class MountainBag_ColorBase;
	class BRP_mountainbag_black: MountainBag_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_mountainbag_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_mountainbag_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_mountainbag_black.paa"
		};
	};
	class BRP_mountainbag_brown: MountainBag_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_mountainbag_brown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_mountainbag_brown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_mountainbag_brown.paa"
		};
	};
	class CivilianBelt: Clothing
	/*{
		repairableWithKits[]={5,2};//Leather Sewing Kit
		repairCosts[]={30,25};
	}*/;
	class MilitaryBelt: Clothing
	/*{
		repairableWithKits[]={5,2};//Leather Sewing Kit
		repairCosts[]={30,25};
	}*/;
	class BRP_civbelt_black: CivilianBelt
	{
		scope=2;
		hiddenSelections[]=
        {
            "camoGround",
            "camoMale",
            "camoFemale",
            "zbytek"
        };
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_civbelt_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_civbelt_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_civbelt_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_civbelt_black.paa"
		};
	};
	class BRP_civbelt_brown: CivilianBelt
	{
		scope=2;
		hiddenSelections[]=
        {
            "camoGround",
            "camoMale",
            "camoFemale",
            "zbytek"
        };
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_civbelt_brown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_civbelt_brown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_civbelt_brown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_civbelt_brown.paa"
		};
	};
	class AssaultBag_ColorBase;
	class BRP_assaultbag_black: AssaultBag_ColorBase
	{
		scope=2;
		visibilityModifier=0.5;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_assaultbag_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_assaultbag_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_assaultbag_black.paa"
		};
	};
	class TortillaBag;
	class BRP_tortillabag_armygreen: TortillaBag
	{
		scope=2;
		hiddenSelections[]=
		{
			"zbytek",
			"zbytek",
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_tortillabag_armygreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_tortillabag_armygreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_tortillabag_armygreen.paa"
		};
	};
	class BRP_tortillabag_beige: TortillaBag
	{
		scope=2;
		hiddenSelections[]=
		{
			"zbytek",
			"zbytek",
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_tortillabag_beige.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_tortillabag_beige.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_tortillabag_beige.paa"
		};
	};
	class BRP_tortillabag_black: TortillaBag
	{
		scope=2;
		hiddenSelections[]=
		{
			"zbytek",
			"zbytek",
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_tortillabag_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_tortillabag_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_tortillabag_black.paa"
		};
	};
	class BRP_tortillabag_black2scarlet: TortillaBag
	{
		scope=2;
		hiddenSelections[]=
		{
			"zbytek",
			"zbytek",
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_tortillabag_black2.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_tortillabag_black2.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_tortillabag_black2.paa"
		};
	};
	class BRP_tortillabag_burgundy: TortillaBag
	{
		scope=2;
		hiddenSelections[]=
		{
			"zbytek",
			"zbytek",
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_tortillabag_burgundy.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_tortillabag_burgundy.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_tortillabag_burgundy.paa"
		};
	};
	class BRP_tortillabag_lightbrown: TortillaBag
	{
		scope=2;
		hiddenSelections[]=
		{
			"zbytek",
			"zbytek",
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_tortillabag_lightbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_tortillabag_lightbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_tortillabag_lightbrown.paa"
		};
	};
	class BRP_tortillabag_lightgrey: TortillaBag
	{
		scope=2;
		hiddenSelections[]=
		{
			"zbytek",
			"zbytek",
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_tortillabag_lightgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_tortillabag_lightgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_tortillabag_lightgrey.paa"
		};
	};
	class BRP_tortillabag_navyblue: TortillaBag
	{
		scope=2;
		hiddenSelections[]=
		{
			"zbytek",
			"zbytek",
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_tortillabag_navyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_tortillabag_navyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_tortillabag_navyblue.paa"
		};
	};
	/*class BRP_tortillabag_test: TortillaBag//test
	{
		scope=2;
		hiddenSelections[]=
		{
			"zbytek",
			"zbytek",
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_tortillabag_test.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_tortillabag_test.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_tortillabag_test.paa"
		};
	};*/
	class BomberJacket_ColorBase;
	class BRP_bomberjacket_armygreen: BomberJacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_bomberjacket_armygreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_bomberjacket_armygreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_bomberjacket_armygreen.paa"
		};
	};
	class BRP_bomberjacket_beige: BomberJacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_bomberjacket_beige.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_bomberjacket_beige.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_bomberjacket_beige.paa"
		};
	};
	class BRP_bomberjacket_black: BomberJacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_bomberjacket_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_bomberjacket_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_bomberjacket_black.paa"
		};
	};
	class BRP_bomberjacket_burgundy: BomberJacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_bomberjacket_burgundy.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_bomberjacket_burgundy.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_bomberjacket_burgundy.paa"
		};
	};
	class BRP_bomberjacket_lightbrown: BomberJacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_bomberjacket_lightbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_bomberjacket_lightbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_bomberjacket_lightbrown.paa"
		};
	};
	class BRP_bomberjacket_lightgrey: BomberJacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_bomberjacket_lightgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_bomberjacket_lightgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_bomberjacket_lightgrey.paa"
		};
	};
	class BRP_bomberjacket_navyblue: BomberJacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_bomberjacket_navyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_bomberjacket_navyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_bomberjacket_navyblue.paa"
		};
	};
	/*class BRP_bomberjacket_test2: BomberJacket_ColorBase//test
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_bomberjacket_test2.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_bomberjacket_test2.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_bomberjacket_test2.paa"
		};
	};*/
	class DryBag_ColorBase;
	class BRP_drybag_black: DryBag_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_drybag_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_drybag_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_drybag_black.paa"
		};
	};
	class Canteen: Bottle_Base {}
	class BRP_canteen_blackgreen: Canteen//black wrap with green canteen
	{
		scope=2;
		hiddenSelections[]=
		{
			"zbytek",
			"zbytek",
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_canteen_blackgreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_canteen_blackgreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_canteen_blackgreen.paa"
		};
	};
	class BRP_canteen_blackgrey: Canteen//black wrap with black canteen
	{
		scope=2;
		hiddenSelections[]=
		{
			"zbytek",
			"zbytek",
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_canteen_blackgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_canteen_blackgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_canteen_blackgrey.paa"
		};
	};
	class ChestHolster;
	class BRP_chestholster_black: ChestHolster
	{
		scope=2;
		hiddenSelections[]=
		{
			"zbytek",
			"zbytek",
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_chestholster_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_chestholster_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_chestholster_black.paa"
		};
	};
	class BRP_chestholster_brown: ChestHolster
	{
		scope=2; 
		hiddenSelections[]=
		{
			"zbytek",
			"zbytek",
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_chestholster_brown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_chestholster_brown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_chestholster_brown.paa"
		};
	};
	class DenimJacket;
	class BRP_denimjacket_black: DenimJacket
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_denimjacket_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_denimjacket_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_denimjacket_black.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_denimjacket_black.rvmat",
			"BastionMod\BastionClothing\Retextures\data\coda_denimjacket_black.rvmat",
			"BastionMod\BastionClothing\Retextures\data\coda_denimjacket_black.rvmat"
		};
	};
	class NioshFaceMask;
	class BRP_dustmask_black: NioshFaceMask
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_dustmask_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_dustmask_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_dustmask_black.paa"
		};
	};
	class JumpsuitJacket_ColorBase;
	class JumpsuitPants_ColorBase;
	class BRP_jumpsuitjacket_black: JumpsuitJacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_jumpsuitjacket_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_jumpsuitjacket_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_jumpsuitjacket_black.paa"
		};
	};
	class BRP_jumpsuitpants_black: JumpsuitPants_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_jumpsuitpants_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_jumpsuitpants_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_jumpsuitpants_black.paa"
		};
	};
	class BRP_jumpsuitjacket_darkgrey: JumpsuitJacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_jumpsuitjacket_darkgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_jumpsuitjacket_darkgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_jumpsuitjacket_darkgrey.paa"
		};
	};
	class BRP_jumpsuitjacket_lightgrey: JumpsuitJacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_jumpsuitjacket_lightgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_jumpsuitjacket_lightgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_jumpsuitjacket_lightgrey.paa"
		};
	};
	class LabCoat;
	class BRP_labcoat_black: LabCoat
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_labcoat_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_labcoat_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_labcoat_black.paa"
		};
	};
	class NBCGloves_ColorBase;
	class BRP_nbc_gloves_black: NBCGloves_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_nbc_gloves_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_nbc_gloves_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_nbc_gloves_black.paa"
		};
	};
	class BRP_nbc_gloves_white: NBCGloves_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_nbc_gloves_white.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_nbc_gloves_white.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_nbc_gloves_white.paa"
		};
	};
	class NBCBootsBase;
	class BRP_nbc_boots_black: NBCBootsBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_nbc_boots_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_nbc_boots_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_nbc_boots_black.paa"
		};
	};
	class BRP_nbc_boots_white: NBCBootsBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_nbc_boots_white.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_nbc_boots_white.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_nbc_boots_white.paa"
		};
	};
	class NBCHoodBase;
	class BRP_nbc_hood_black: NBCHoodBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_nbc_hood_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_nbc_hood_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_nbc_hood_black.paa"
		};
	};
	class BRP_nbc_hood_white: NBCHoodBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_nbc_hood_white.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_nbc_hood_white.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_nbc_hood_white.paa"
		};
	};
	class BRP_nbc_hood_BDU: NBCHoodBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_nbc_hood_BDU.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_nbc_hood_BDU.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_nbc_hood_BDU.paa"
		};
	};
	class NBCJacketBase;
	class BRP_nbc_jacket_white: NBCJacketBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_nbc_jacket_whiteg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_nbc_jacket_white.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_nbc_jacket_white.paa"
		};
	};
	class BRP_nbc_jacket_BDU: NBCJacketBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_nbc_jacket_BDUg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_nbc_jacket_BDU.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_nbc_jacket_BDU.paa"
		};
	};
	class NBCPantsBase;
	class BRP_nbc_pants_BDU: NBCPantsBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_nbc_pants_BDU.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_nbc_pants_BDU.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_nbc_pants_BDU.paa"
		};
	};
	class BRP_nbc_pants_white: NBCPantsBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_nbc_pants_white.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_nbc_pants_white.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_nbc_pants_white.paa"
		};
	};
	class PressVest_ColorBase;
	class BRP_pressvest_enclave: PressVest_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_pressvest_enclave.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_pressvest_enclave.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_pressvest_enclave.paa"
		};
	};
	class BRP_pressvest_armygreen: PressVest_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_pressvest_armygreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_pressvest_armygreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_pressvest_armygreen.paa"
		};
	};
	class BRP_pressvest_beige: PressVest_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_pressvest_beige.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_pressvest_beige.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_pressvest_beige.paa"
		};
	};
	class BRP_pressvest_black: PressVest_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_pressvest_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_pressvest_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_pressvest_black.paa"
		};
	};
	class BRP_pressvest_smiley: PressVest_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_pressvest_smiley.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_pressvest_smiley.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_pressvest_smiley.paa"
		};
	};
	class Raincoat_ColorBase;
	class BRP_raincoat_black: Raincoat_ColorBase
	{
		scope=2;
		color="Black";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_raincoat_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_raincoat_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_raincoat_black.paa"
		};
	};
	class BRP_raincoat_white: Raincoat_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_raincoat_white.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_raincoat_white.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_raincoat_white.paa"
		};
	};
	class Skirt_ColorBase;
	class BRP_skirt_black: Skirt_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_skirt_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_skirt_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_skirt_black.paa"
		};
	};
	class PoliceVest;
	class BRP_stabvest_black: PoliceVest
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_stabvest_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_stabvest_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_stabvest_black.paa"
		};
	};
	class SurgicalMask;
	class BRP_surgicalmask_smile: SurgicalMask
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_surgicalmask_smileg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_surgicalmask_smile.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_surgicalmask_smile.paa"
		};
	};
	class BRP_surgicalmask_black: SurgicalMask
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_surgicalmask_blackg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_surgicalmask_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_surgicalmask_black.paa"
		};
	};
	class BRP_surgicalmask_grey: SurgicalMask
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_surgicalmask_greyg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_surgicalmask_grey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_surgicalmask_grey.paa"
		};
	};
	class TacticalShirt_ColorBase: Clothing
	{
		//itemSize[]={3,2};
	};
	class BRP_tacticalshirt_grey: TacticalShirt_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_tacticalshirt_greyg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_tacticalshirt_grey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_tacticalshirt_grey.paa"
		};
	};
	class TacticalGloves_ColorBase;
	class BRP_tacticalgloves_black: TacticalGloves_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_tacticalgloves_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_tacticalgloves_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_tacticalgloves_black.paa"
		};
	};
	class Hoodie_ColorBase: Clothing
	{
		//itemSize[]={3,2};
	};
	class BRP_hoodie_armygreen: Hoodie_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_hoodie_armygreeng.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_hoodie_armygreenm.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_hoodie_armygreenf.paa"
		};
	};
	class BRP_hoodie_babyblue: Hoodie_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_hoodie_babyblueg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_hoodie_babybluem.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_hoodie_babybluef.paa"
		};
	};
	class BRP_hoodie_babypink: Hoodie_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_hoodie_babypinkg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_hoodie_babypinkm.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_hoodie_babypinkf.paa"
		};
	};
	class BRP_hoodie_beige: Hoodie_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_hoodie_beigeg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_hoodie_beigem.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_hoodie_beigef.paa"
		};
	};
	class BRP_hoodie_black: Hoodie_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_hoodie_blackg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_hoodie_blackm.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_hoodie_blackf.paa"
		};
	};
	class BRP_hoodie_burgundy: Hoodie_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_hoodie_burgundyg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_hoodie_burgundym.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_hoodie_burgundyf.paa"
		};
	};
	class BRP_hoodie_lightbrown: Hoodie_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_hoodie_lightbrowng.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_hoodie_lightbrownm.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_hoodie_lightbrownf.paa"
		};
	};
	class BRP_hoodie_lightgrey: Hoodie_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_hoodie_lightgreyg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_hoodie_lightgreym.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_hoodie_lightgreyf.paa"
		};
	};
	class BRP_hoodie_navyblue: Hoodie_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_hoodie_navyblueg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_hoodie_navybluem.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_hoodie_navybluef.paa"
		};
	};
	class BRP_hoodie_red: Hoodie_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_hoodie_redg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_hoodie_redm.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_hoodie_redf.paa"
		};
	};
	class BRP_hoodie_royalblue: Hoodie_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_hoodie_royalblueg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_hoodie_royalbluem.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_hoodie_royalbluef.paa"
		};
	};
	class BRP_hoodie_white: Hoodie_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_hoodie_whiteg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_hoodie_whitem.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_hoodie_whitef.paa"
		};
	};
	class WoolCoat_ColorBase;
	class BRP_woolcoat_armygreen: WoolCoat_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_woolcoat_armygreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_woolcoat_armygreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_woolcoat_armygreen.paa"
		};
	};
	class BRP_woolcoat_beige: WoolCoat_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_woolcoat_beige.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_woolcoat_beige.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_woolcoat_beige.paa"
		};
	};
	class BRP_woolcoat_black: WoolCoat_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_woolcoat_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_woolcoat_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_woolcoat_black.paa"
		};
	};
	class BRP_woolcoat_burgundy: WoolCoat_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_woolcoat_burgundy.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_woolcoat_burgundy.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_woolcoat_burgundy.paa"
		};
	};
	class BRP_woolcoat_lightbrown: WoolCoat_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_woolcoat_lightbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_woolcoat_lightbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_woolcoat_lightbrown.paa"
		};
	};
	class BRP_woolcoat_lightgrey: WoolCoat_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_woolcoat_lightgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_woolcoat_lightgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_woolcoat_lightgrey.paa"
		};
	};
	class BRP_woolcoat_navyblue: WoolCoat_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_woolcoat_navyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_woolcoat_navyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_woolcoat_navyblue.paa"
		};
	};
	class QuiltedJacket_ColorBase: Clothing
	{
		//itemSize[]={4,3};
	};
	class BRP_quiltedjacket_smiley: QuiltedJacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_quiltedjacket_smiley.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_quiltedjacket_smiley.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_quiltedjacket_smiley.paa"
		};
	};
	class BRP_quiltedjacket_armygreen: QuiltedJacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_quiltedjacket_armygreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_quiltedjacket_armygreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_quiltedjacket_armygreen.paa"
		};
	};
	class BRP_quiltedjacket_babypink: QuiltedJacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_quiltedjacket_babypink.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_quiltedjacket_babypink.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_quiltedjacket_babypink.paa"
		};
	};
	class BRP_quiltedjacket_beige: QuiltedJacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_quiltedjacket_beige.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_quiltedjacket_beige.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_quiltedjacket_beige.paa"
		};
	};
	class BRP_quiltedjacket_black: QuiltedJacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_quiltedjacket_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_quiltedjacket_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_quiltedjacket_black.paa"
		};
	};
	class BRP_quiltedjacket_burgundy: QuiltedJacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_quiltedjacket_burgundy.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_quiltedjacket_burgundy.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_quiltedjacket_burgundy.paa"
		};
	};
	class BRP_quiltedjacket_darkbrown: QuiltedJacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_quiltedjacket_darkbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_quiltedjacket_darkbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_quiltedjacket_darkbrown.paa"
		};
	};
	class BRP_quiltedjacket_darkgrey: QuiltedJacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_quiltedjacket_darkgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_quiltedjacket_darkgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_quiltedjacket_darkgrey.paa"
		};
	};
	class BRP_quiltedjacket_fuchsia: QuiltedJacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_quiltedjacket_fuchsia.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_quiltedjacket_fuchsia.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_quiltedjacket_fuchsia.paa"
		};
	};
	class BRP_quiltedjacket_lightbrown: QuiltedJacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_quiltedjacket_lightbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_quiltedjacket_lightbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_quiltedjacket_lightbrown.paa"
		};
	};
	class BRP_quiltedjacket_lightgrey: QuiltedJacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_quiltedjacket_lightgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_quiltedjacket_lightgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_quiltedjacket_lightgrey.paa"
		};
	};
	class BRP_quiltedjacket_navyblue: QuiltedJacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_quiltedjacket_navyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_quiltedjacket_navyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_quiltedjacket_navyblue.paa"
		};
	};
	class BRP_quiltedjacket_plum: QuiltedJacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_quiltedjacket_plum.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_quiltedjacket_plum.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_quiltedjacket_plum.paa"
		};
	};
	class BRP_quiltedjacket_purple: QuiltedJacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_quiltedjacket_purple.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_quiltedjacket_purple.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_quiltedjacket_purple.paa"
		};
	};
	class BRP_quiltedjacket_red: QuiltedJacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_quiltedjacket_red.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_quiltedjacket_red.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_quiltedjacket_red.paa"
		};
	};
	class BRP_quiltedjacket_royalblue: QuiltedJacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_quiltedjacket_royalblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_quiltedjacket_royalblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_quiltedjacket_royalblue.paa"
		};
	};
	class BRP_quiltedjacket_white: QuiltedJacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_quiltedjacket_white.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_quiltedjacket_white.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_quiltedjacket_white.paa"
		};
	};
	class WorkingGloves_ColorBase;
	class BRP_workinggloves_armygreen: WorkingGloves_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_workinggloves_armygreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_workinggloves_armygreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_workinggloves_armygreen.paa"
		};
	};
	class BRP_workinggloves_beige: WorkingGloves_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_workinggloves_beige.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_workinggloves_beige.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_workinggloves_beige.paa"
		};
	};
	class BRP_workinggloves_black: WorkingGloves_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_workinggloves_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_workinggloves_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_workinggloves_black.paa"
		};
	};
	class BRP_workinggloves_burgundy: WorkingGloves_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_workinggloves_burgundy.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_workinggloves_burgundy.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_workinggloves_burgundy.paa"
		};
	};
	class BRP_workinggloves_darkbrown: WorkingGloves_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_workinggloves_darkbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_workinggloves_darkbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_workinggloves_darkbrown.paa"
		};
	};
	class BRP_workinggloves_lightbrown: WorkingGloves_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_workinggloves_lightbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_workinggloves_lightbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_workinggloves_lightbrown.paa"
		};
	};
	class BRP_workinggloves_lightgrey: WorkingGloves_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_workinggloves_lightgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_workinggloves_lightgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_workinggloves_lightgrey.paa"
		};
	};
	class BRP_workinggloves_navyblue: WorkingGloves_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_workinggloves_navyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_workinggloves_navyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_workinggloves_navyblue.paa"
		};
	};
	class BDUJacket;
	class BRP_bdu_jacket: BDUJacket
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_bdujacket_beige.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_bdujacket_beige.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_bdujacket_beige.paa"
		};
	};
	class BDUPants;
	class BRP_bdu_pants: BDUPants
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_bdupants_beige.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_bdupants_beige.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_bdupants_beige.paa"
		};
	};
//Categorized
//	class Armband_ColorBase;
	class BRP_armband_armygreen: Armband_ColorBase
	{
		scope=2;
		color="armygreen";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_armband_armygreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_armygreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_armygreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_armygreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_armygreen.paa"
		};
	};
	class BRP_armband_babyblue: Armband_ColorBase
	{
		scope=2;
		color="babyblue";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_armband_babyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_babyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_babyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_babyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_babyblue.paa"
		};
	};
	class BRP_armband_babypink: Armband_ColorBase
	{
		scope=2;
		color="babypink";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_armband_babypink.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_babypink.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_babypink.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_babypink.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_babypink.paa"
		};
	};
	class BRP_armband_black: Armband_ColorBase
	{
		scope=2;
		color="black";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_armband_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_black.paa"
		};
	};
	class BRP_armband_beige: Armband_ColorBase
	{
		scope=2;
		color="beige";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_armband_beige.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_beige.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_beige.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_beige.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_beige.paa"
		};
	};
	class BRP_armband_burgundy: Armband_ColorBase
	{
		scope=2;
		color="burgundy";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_armband_burgundy.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_burgundy.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_burgundy.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_burgundy.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_burgundy.paa"
		};
	};
	class BRP_armband_candypink: Armband_ColorBase
	{
		scope=2;
		color="candypink";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_armband_candypink.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_candypink.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_candypink.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_candypink.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_candypink.paa"
		};
	};
	class BRP_armband_cream: Armband_ColorBase
	{
		scope=2;
		color="cream";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_armband_cream.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_cream.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_cream.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_cream.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_cream.paa"
		};
	};
	class BRP_armband_cyan: Armband_ColorBase
	{
		scope=2;
		color="cyan";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_armband_cyan.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_cyan.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_cyan.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_cyan.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_cyan.paa"
		};
	};
	class BRP_armband_darkbrown: Armband_ColorBase
	{
		scope=2;
		color="darkbrown";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_armband_darkbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_darkbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_darkbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_darkbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_darkbrown.paa"
		};
	};
	class BRP_armband_darkgrey: Armband_ColorBase
	{
		scope=2;
		color="darkgrey";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_armband_darkgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_darkgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_darkgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_darkgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_darkgrey.paa"
		};
	};
	class BRP_armband_fuchsia: Armband_ColorBase
	{
		scope=2;
		color="fuchsia";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_armband_fuchsia.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_fuchsia.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_fuchsia.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_fuchsia.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_fuchsia.paa"
		};
	};
	class BRP_armband_lavender: Armband_ColorBase
	{
		scope=2;
		color="lavender";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_armband_lavender.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_lavender.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_lavender.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_lavender.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_lavender.paa"
		};
	};
	class BRP_armband_lightbrown: Armband_ColorBase
	{
		scope=2;
		color="lightbrown";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_armband_lightbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_lightbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_lightbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_lightbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_lightbrown.paa"
		};
	};
	class BRP_armband_lightgrey: Armband_ColorBase
	{
		scope=2;
		color="lightgrey";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_armband_lightgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_lightgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_lightgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_lightgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_lightgrey.paa"
		};
	};
	class BRP_armband_navyblue: Armband_ColorBase
	{
		scope=2;
		color="navyblue";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_armband_navyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_navyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_navyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_navyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_navyblue.paa"
		};
	};
	class BRP_armband_olivegreen: Armband_ColorBase
	{
		scope=2;
		color="olivegreen";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_armband_olivegreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_olivegreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_olivegreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_olivegreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_olivegreen.paa"
		};
	};
	class BRP_armband_orange: Armband_ColorBase
	{
		scope=2;
		color="orange";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_armband_orange.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_orange.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_orange.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_orange.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_orange.paa"
		};
	};
	class BRP_armband_plum: Armband_ColorBase
	{
		scope=2;
		color="plum";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_armband_plum.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_plum.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_plum.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_plum.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_plum.paa"
		};
	};
	class BRP_armband_purple: Armband_ColorBase
	{
		scope=2;
		color="purple";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_armband_purple.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_purple.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_purple.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_purple.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_purple.paa"
		};
	};
	class BRP_armband_red: Armband_ColorBase
	{
		scope=2;
		color="red";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_armband_red.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_red.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_red.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_red.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_red.paa"
		};
	};
	class BRP_armband_royalblue: Armband_ColorBase
	{
		scope=2;
		color="royalblue";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_armband_royalblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_royalblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_royalblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_royalblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_royalblue.paa"
		};
	};
	class BRP_armband_white: Armband_ColorBase
	{
		scope=2;
		color="white";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_armband_white.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_white.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_white.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_white.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_white.paa"
		};
	};
	class BRP_armband_yellow: Armband_ColorBase
	{
		scope=2;
		color="yellow";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_armband_yellow.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_yellow.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_yellow.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_yellow.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_yellow.paa"
		};
	};
	/*class BRP_armband_test: Armband_ColorBase
	{
		scope=2;
		color="test";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_armband_test.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_test.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_test.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_test.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_armband_test.paa"
		};
	};*/
	class Ballerinas_ColorBase: Clothing
	{
		//itemSize[]={2,2};
	};
	class BRP_ballerinas_armygreen: Ballerinas_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_ballerinas_armygreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ballerinas_armygreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ballerinas_armygreen.paa"
		};
	};
	class BRP_ballerinas_babyblue: Ballerinas_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_ballerinas_babyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ballerinas_babyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ballerinas_babyblue.paa"
		};
	};
	class BRP_ballerinas_babypink: Ballerinas_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_ballerinas_babypink.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ballerinas_babypink.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ballerinas_babypink.paa"
		};
	};
	class BRP_ballerinas_black: Ballerinas_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_ballerinas_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ballerinas_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ballerinas_black.paa"
		};
	};
	class BRP_ballerinas_beige: Ballerinas_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_ballerinas_beige.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ballerinas_beige.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ballerinas_beige.paa"
		};
	};
	class BRP_ballerinas_burgundy: Ballerinas_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_ballerinas_burgundy.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ballerinas_burgundy.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ballerinas_burgundy.paa"
		};
	};
	class BRP_ballerinas_candypink: Ballerinas_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_ballerinas_candypink.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ballerinas_candypink.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ballerinas_candypink.paa"
		};
	};
	class BRP_ballerinas_cream: Ballerinas_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_ballerinas_cream.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ballerinas_cream.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ballerinas_cream.paa"
		};
	};
	class BRP_ballerinas_cyan: Ballerinas_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_ballerinas_cyan.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ballerinas_cyan.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ballerinas_cyan.paa"
		};
	};
	class BRP_ballerinas_darkbrown: Ballerinas_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_ballerinas_darkbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ballerinas_darkbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ballerinas_darkbrown.paa"
		};
	};
	class BRP_ballerinas_darkgrey: Ballerinas_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_ballerinas_darkgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ballerinas_darkgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ballerinas_darkgrey.paa"
		};
	};
	class BRP_ballerinas_fuchsia: Ballerinas_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_ballerinas_fuchsia.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ballerinas_fuchsia.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ballerinas_fuchsia.paa"
		};
	};
	class BRP_ballerinas_lavender: Ballerinas_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_ballerinas_lavender.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ballerinas_lavender.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ballerinas_lavender.paa"
		};
	};
	class BRP_ballerinas_lightbrown: Ballerinas_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_ballerinas_lightbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ballerinas_lightbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ballerinas_lightbrown.paa"
		};
	};
	class BRP_ballerinas_lightgrey: Ballerinas_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_ballerinas_lightgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ballerinas_lightgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ballerinas_lightgrey.paa"
		};
	};
	class BRP_ballerinas_navyblue: Ballerinas_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_ballerinas_navyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ballerinas_navyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ballerinas_navyblue.paa"
		};
	};
	class BRP_ballerinas_olivegreen: Ballerinas_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_ballerinas_olivegreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ballerinas_olivegreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ballerinas_olivegreen.paa"
		};
	};
	class BRP_ballerinas_orange: Ballerinas_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_ballerinas_orange.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ballerinas_orange.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ballerinas_orange.paa"
		};
	};
	class BRP_ballerinas_plum: Ballerinas_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_ballerinas_plum.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ballerinas_plum.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ballerinas_plum.paa"
		};
	};
	class BRP_ballerinas_purple: Ballerinas_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_ballerinas_purple.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ballerinas_purple.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ballerinas_purple.paa"
		};
	};
	class BRP_ballerinas_red: Ballerinas_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_ballerinas_red.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ballerinas_red.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ballerinas_red.paa"
		};
	};
	class BRP_ballerinas_royalblue: Ballerinas_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_ballerinas_royalblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ballerinas_royalblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ballerinas_royalblue.paa"
		};
	};
	class BRP_ballerinas_white: Ballerinas_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_ballerinas_white.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ballerinas_white.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ballerinas_white.paa"
		};
	};
	class BRP_ballerinas_yellow: Ballerinas_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_ballerinas_yellow.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ballerinas_yellow.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ballerinas_yellow.paa"
		};
	};
	/*class BRP_ballerinas_test: Ballerinas_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_ballerinas_test.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ballerinas_test.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ballerinas_test.paa"
		};
	};*/
	class BandanaHead_ColorBase;
	/*class BRP_dorag_armada: BandanaHead_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_dorag_armada.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_dorag_armada.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_dorag_armada.paa"
		};
	};*/
	class BRP_dorag_black: BandanaHead_ColorBase
	{
		scope=2;
		displayName="Do-Rag";
		descriptionShort="A type of scarf worn on the head to protect the hairdo.";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_bandanafacemask_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_bandanafacemask_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_bandanafacemask_black.paa"
		};
	};
	class BandanaMask_ColorBase;
	class BRP_bandana_armygreen: BandanaMask_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_bandanafacemask_armygreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_bandanafacemask_armygreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_bandanafacemask_armygreen.paa"
		};
	};
	class BRP_bandana_babyblue: BandanaMask_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_bandanafacemask_babyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_bandanafacemask_babyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_bandanafacemask_babyblue.paa"
		};
	};
	class BRP_bandana_babypink: BandanaMask_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_bandanafacemask_babypink.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_bandanafacemask_babypink.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_bandanafacemask_babypink.paa"
		};
	};
	class BRP_bandana_black: BandanaMask_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_bandanafacemask_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_bandanafacemask_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_bandanafacemask_black.paa"
		};
	};
	class BRP_bandana_beige: BandanaMask_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_bandanafacemask_beige.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_bandanafacemask_beige.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_bandanafacemask_beige.paa"
		};
	};
	class BRP_bandana_burgundy: BandanaMask_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_bandanafacemask_burgundy.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_bandanafacemask_burgundy.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_bandanafacemask_burgundy.paa"
		};
	};
	class BRP_bandana_candypink: BandanaMask_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_bandanafacemask_candypink.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_bandanafacemask_candypink.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_bandanafacemask_candypink.paa"
		};
	};
	class BRP_bandana_cream: BandanaMask_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_bandanafacemask_cream.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_bandanafacemask_cream.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_bandanafacemask_cream.paa"
		};
	};
	class BRP_bandana_cyan: BandanaMask_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_bandanafacemask_cyan.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_bandanafacemask_cyan.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_bandanafacemask_cyan.paa"
		};
	};
	class BRP_bandana_darkbrown: BandanaMask_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_bandanafacemask_darkbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_bandanafacemask_darkbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_bandanafacemask_darkbrown.paa"
		};
	};
	class BRP_bandana_darkgrey: BandanaMask_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_bandanafacemask_darkgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_bandanafacemask_darkgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_bandanafacemask_darkgrey.paa"
		};
	};
	class BRP_bandana_fuchsia: BandanaMask_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_bandanafacemask_fuchsia.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_bandanafacemask_fuchsia.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_bandanafacemask_fuchsia.paa"
		};
	};
	class BRP_bandana_lavender: BandanaMask_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_bandanafacemask_lavender.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_bandanafacemask_lavender.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_bandanafacemask_lavender.paa"
		};
	};
	class BRP_bandana_lightbrown: BandanaMask_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_bandanafacemask_lightbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_bandanafacemask_lightbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_bandanafacemask_lightbrown.paa"
		};
	};
	class BRP_bandana_lightgrey: BandanaMask_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_bandanafacemask_lightgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_bandanafacemask_lightgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_bandanafacemask_lightgrey.paa"
		};
	};
	class BRP_bandana_navyblue: BandanaMask_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_bandanafacemask_navyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_bandanafacemask_navyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_bandanafacemask_navyblue.paa"
		};
	};
	class BRP_bandana_olivegreen: BandanaMask_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_bandanafacemask_olivegreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_bandanafacemask_olivegreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_bandanafacemask_olivegreen.paa"
		};
	};
	class BRP_bandana_orange: BandanaMask_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_bandanafacemask_orange.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_bandanafacemask_orange.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_bandanafacemask_orange.paa"
		};
	};
	class BRP_bandana_plum: BandanaMask_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_bandanafacemask_plum.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_bandanafacemask_plum.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_bandanafacemask_plum.paa"
		};
	};
	class BRP_bandana_purple: BandanaMask_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_bandanafacemask_purple.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_bandanafacemask_purple.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_bandanafacemask_purple.paa"
		};
	};
	class BRP_bandana_red: BandanaMask_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_bandanafacemask_red.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_bandanafacemask_red.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_bandanafacemask_red.paa"
		};
	};
	class BRP_bandana_royalblue: BandanaMask_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_bandanafacemask_royalblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_bandanafacemask_royalblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_bandanafacemask_royalblue.paa"
		};
	};
	class BRP_bandana_white: BandanaMask_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_bandanafacemask_white.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_bandanafacemask_white.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_bandanafacemask_white.paa"
		};
	};
	class BRP_bandana_yellow: BandanaMask_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_bandanafacemask_yellow.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_bandanafacemask_yellow.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_bandanafacemask_yellow.paa"
		};
	};
	/*class BRP_bandana_test: BandanaMask_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_bandanafacemask_test.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_bandanafacemask_test.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_bandanafacemask_test.paa"
		};
	};*/
//	class Baseballcap_ColorBase;
	class BRP_bdu_cap: Baseballcap_ColorBase
	{
		scope=2;
		visibilityModifier=0.94999999;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_baseballcap_BDU.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_baseballcap_BDU.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_baseballcap_BDU.paa"
		};
	};
	class BRP_baseballcap_armygreen: Baseballcap_ColorBase
	{
		scope=2;
		visibilityModifier=0.94999999;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_baseballcap_armygreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_baseballcap_armygreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_baseballcap_armygreen.paa"
		};
	};
	class BRP_baseballcap_babyblue: Baseballcap_ColorBase
	{
		scope=2;
		visibilityModifier=0.94999999;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_baseballcap_babyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_baseballcap_babyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_baseballcap_babyblue.paa"
		};
	};
	class BRP_baseballcap_babypink: Baseballcap_ColorBase
	{
		scope=2;
		visibilityModifier=0.94999999;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_baseballcap_babypink.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_baseballcap_babypink.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_baseballcap_babypink.paa"
		};
	};
	class BRP_baseballcap_black: Baseballcap_ColorBase
	{
		scope=2;
		visibilityModifier=0.94999999;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_baseballcap_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_baseballcap_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_baseballcap_black.paa"
		};
	};
	class BRP_baseballcap_beige: Baseballcap_ColorBase
	{
		scope=2;
		visibilityModifier=0.94999999;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_baseballcap_beige.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_baseballcap_beige.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_baseballcap_beige.paa"
		};
	};
	class BRP_baseballcap_burgundy: Baseballcap_ColorBase
	{
		scope=2;
		visibilityModifier=0.94999999;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_baseballcap_burgundy.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_baseballcap_burgundy.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_baseballcap_burgundy.paa"
		};
	};
	class BRP_baseballcap_candypink: Baseballcap_ColorBase
	{
		scope=2;
		visibilityModifier=0.94999999;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_baseballcap_candypink.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_baseballcap_candypink.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_baseballcap_candypink.paa"
		};
	};
	class BRP_baseballcap_cream: Baseballcap_ColorBase
	{
		scope=2;
		visibilityModifier=0.94999999;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_baseballcap_cream.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_baseballcap_cream.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_baseballcap_cream.paa"
		};
	};
	class BRP_baseballcap_cyan: Baseballcap_ColorBase
	{
		scope=2;
		visibilityModifier=0.94999999;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_baseballcap_cyan.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_baseballcap_cyan.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_baseballcap_cyan.paa"
		};
	};
	class BRP_baseballcap_darkbrown: Baseballcap_ColorBase
	{
		scope=2;
		visibilityModifier=0.94999999;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_baseballcap_darkbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_baseballcap_darkbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_baseballcap_darkbrown.paa"
		};
	};
	class BRP_baseballcap_darkgrey: Baseballcap_ColorBase
	{
		scope=2;
		visibilityModifier=0.94999999;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_baseballcap_darkgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_baseballcap_darkgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_baseballcap_darkgrey.paa"
		};
	};
	class BRP_baseballcap_fuchsia: Baseballcap_ColorBase
	{
		scope=2;
		visibilityModifier=0.94999999;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_baseballcap_fuchsia.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_baseballcap_fuchsia.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_baseballcap_fuchsia.paa"
		};
	};
	class BRP_baseballcap_lavender: Baseballcap_ColorBase
	{
		scope=2;
		visibilityModifier=0.94999999;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_baseballcap_lavender.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_baseballcap_lavender.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_baseballcap_lavender.paa"
		};
	};
	class BRP_baseballcap_lightbrown: Baseballcap_ColorBase
	{
		scope=2;
		visibilityModifier=0.94999999;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_baseballcap_lightbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_baseballcap_lightbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_baseballcap_lightbrown.paa"
		};
	};
	class BRP_baseballcap_lightgrey: Baseballcap_ColorBase
	{
		scope=2;
		visibilityModifier=0.94999999;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_baseballcap_lightgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_baseballcap_lightgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_baseballcap_lightgrey.paa"
		};
	};
	class BRP_baseballcap_navyblue: Baseballcap_ColorBase
	{
		scope=2;
		visibilityModifier=0.94999999;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_baseballcap_navyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_baseballcap_navyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_baseballcap_navyblue.paa"
		};
	};
	class BRP_baseballcap_olivegreen: Baseballcap_ColorBase
	{
		scope=2;
		visibilityModifier=0.94999999;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_baseballcap_olivegreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_baseballcap_olivegreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_baseballcap_olivegreen.paa"
		};
	};
	class BRP_baseballcap_orange: Baseballcap_ColorBase
	{
		scope=2;
		visibilityModifier=0.94999999;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_baseballcap_orange.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_baseballcap_orange.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_baseballcap_orange.paa"
		};
	};
	class BRP_baseballcap_plum: Baseballcap_ColorBase
	{
		scope=2;
		visibilityModifier=0.94999999;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_baseballcap_plum.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_baseballcap_plum.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_baseballcap_plum.paa"
		};
	};
	class BRP_baseballcap_purple: Baseballcap_ColorBase
	{
		scope=2;
		visibilityModifier=0.94999999;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_baseballcap_purple.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_baseballcap_purple.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_baseballcap_purple.paa"
		};
	};
	class BRP_baseballcap_red: Baseballcap_ColorBase
	{
		scope=2;
		visibilityModifier=0.94999999;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_baseballcap_red.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_baseballcap_red.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_baseballcap_red.paa"
		};
	};
	class BRP_baseballcap_royalblue: Baseballcap_ColorBase
	{
		scope=2;
		visibilityModifier=0.94999999;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_baseballcap_royalblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_baseballcap_royalblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_baseballcap_royalblue.paa"
		};
	};
	class BRP_baseballcap_white: Baseballcap_ColorBase
	{
		scope=2;
		visibilityModifier=0.94999999;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_baseballcap_white.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_baseballcap_white.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_baseballcap_white.paa"
		};
	};
	class BRP_baseballcap_yellow: Baseballcap_ColorBase
	{
		scope=2;
		visibilityModifier=0.94999999;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_baseballcap_yellow.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_baseballcap_yellow.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_baseballcap_yellow.paa"
		};
	};
	/*class BRP_baseballcap_test: Baseballcap_ColorBase
	{
		scope=2;
		visibilityModifier=0.94999999;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_baseballcap_test.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_baseballcap_test.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_baseballcap_test.paa"
		};
	};*/
	class BeanieHat_ColorBase: Clothing
	{
		//itemSize[]={2,2};
	};
	class BRP_beanie_crow: BeanieHat_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_beanie_crow.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_beanie_crow.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_beanie_crow.paa"
		};
	};
	class BRP_beanie_aegis: BeanieHat_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_beanie_aegis.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_beanie_aegis.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_beanie_aegis.paa"
		};
	};
	class BRP_beanie_armygreen: BeanieHat_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_beanie_armygreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_beanie_armygreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_beanie_armygreen.paa"
		};
	};
	class BRP_beanie_babyblue: BeanieHat_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_beanie_babyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_beanie_babyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_beanie_babyblue.paa"
		};
	};
	class BRP_beanie_babypink: BeanieHat_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_beanie_babypink.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_beanie_babypink.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_beanie_babypink.paa"
		};
	};
	class BRP_beanie_black: BeanieHat_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_beanie_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_beanie_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_beanie_black.paa"
		};
	};
	class BRP_beanie_beige: BeanieHat_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_beanie_beige.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_beanie_beige.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_beanie_beige.paa"
		};
	};
	class BRP_beanie_burgundy: BeanieHat_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_beanie_burgundy.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_beanie_burgundy.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_beanie_burgundy.paa"
		};
	};
	class BRP_beanie_candypink: BeanieHat_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_beanie_candypink.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_beanie_candypink.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_beanie_candypink.paa"
		};
	};
	class BRP_beanie_cream: BeanieHat_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_beanie_cream.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_beanie_cream.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_beanie_cream.paa"
		};
	};
	class BRP_beanie_cyan: BeanieHat_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_beanie_cyan.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_beanie_cyan.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_beanie_cyan.paa"
		};
	};
	class BRP_beanie_darkbrown: BeanieHat_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_beanie_darkbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_beanie_darkbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_beanie_darkbrown.paa"
		};
	};
	class BRP_beanie_darkgrey: BeanieHat_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_beanie_darkgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_beanie_darkgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_beanie_darkgrey.paa"
		};
	};
	class BRP_beanie_fuchsia: BeanieHat_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_beanie_fuchsia.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_beanie_fuchsia.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_beanie_fuchsia.paa"
		};
	};
	class BRP_beanie_lavender: BeanieHat_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_beanie_lavender.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_beanie_lavender.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_beanie_lavender.paa"
		};
	};
	class BRP_beanie_lightbrown: BeanieHat_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_beanie_lightbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_beanie_lightbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_beanie_lightbrown.paa"
		};
	};
	class BRP_beanie_lightgrey: BeanieHat_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_beanie_lightgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_beanie_lightgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_beanie_lightgrey.paa"
		};
	};
	class BRP_beanie_navyblue: BeanieHat_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_beanie_navyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_beanie_navyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_beanie_navyblue.paa"
		};
	};
	class BRP_beanie_olivegreen: BeanieHat_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_beanie_olivegreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_beanie_olivegreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_beanie_olivegreen.paa"
		};
	};
	class BRP_beanie_orange: BeanieHat_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_beanie_orange.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_beanie_orange.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_beanie_orange.paa"
		};
	};
	class BRP_beanie_plum: BeanieHat_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_beanie_plum.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_beanie_plum.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_beanie_plum.paa"
		};
	};
	class BRP_beanie_purple: BeanieHat_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_beanie_purple.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_beanie_purple.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_beanie_purple.paa"
		};
	};
	class BRP_beanie_red: BeanieHat_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_beanie_red.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_beanie_red.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_beanie_red.paa"
		};
	};
	class BRP_beanie_royalblue: BeanieHat_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_beanie_royalblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_beanie_royalblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_beanie_royalblue.paa"
		};
	};
	class BRP_beanie_white: BeanieHat_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_beanie_white.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_beanie_white.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_beanie_white.paa"
		};
	};
	class BRP_beanie_yellow: BeanieHat_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_beanie_yellow.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_beanie_yellow.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_beanie_yellow.paa"
		};
	};
	/*class BRP_beanie_test: BeanieHat_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_beanie_test.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_beanie_test.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_beanie_test.paa"
		};
	};*/
	class HuntingBag;
	class BRP_huntingbag_armygreen: HuntingBag
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_huntingbag_armygreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingbag_armygreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingbag_armygreen.paa"
		};
	};
	class BRP_huntingbag_babyblue: HuntingBag
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_huntingbag_babyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingbag_babyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingbag_babyblue.paa"
		};
	};
	class BRP_huntingbag_babypink: HuntingBag
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_huntingbag_babypink.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingbag_babypink.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingbag_babypink.paa"
		};
	};
	class BRP_huntingbag_black: HuntingBag
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_huntingbag_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingbag_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingbag_black.paa"
		};
	};
	class BRP_huntingbag_beige: HuntingBag
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_huntingbag_beige.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingbag_beige.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingbag_beige.paa"
		};
	};
	class BRP_huntingbag_burgundy: HuntingBag
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_huntingbag_burgundy.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingbag_burgundy.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingbag_burgundy.paa"
		};
	};
	class BRP_huntingbag_candypink: HuntingBag
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_huntingbag_candypink.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingbag_candypink.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingbag_candypink.paa"
		};
	};
	class BRP_huntingbag_cream: HuntingBag
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_huntingbag_cream.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingbag_cream.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingbag_cream.paa"
		};
	};
	class BRP_huntingbag_cyan: HuntingBag
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_huntingbag_cyan.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingbag_cyan.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingbag_cyan.paa"
		};
	};
	class BRP_huntingbag_darkbrown: HuntingBag
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_huntingbag_darkbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingbag_darkbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingbag_darkbrown.paa"
		};
	};
	class BRP_huntingbag_darkgrey: HuntingBag
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_huntingbag_darkgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingbag_darkgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingbag_darkgrey.paa"
		};
	};
	class BRP_huntingbag_fuchsia: HuntingBag
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_huntingbag_fuchsia.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingbag_fuchsia.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingbag_fuchsia.paa"
		};
	};
	class BRP_huntingbag_lavender: HuntingBag
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_huntingbag_lavender.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingbag_lavender.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingbag_lavender.paa"
		};
	};
	class BRP_huntingbag_lightbrown: HuntingBag
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_huntingbag_lightbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingbag_lightbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingbag_lightbrown.paa"
		};
	};
	class BRP_huntingbag_lightgrey: HuntingBag
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_huntingbag_lightgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingbag_lightgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingbag_lightgrey.paa"
		};
	};
	class BRP_huntingbag_navyblue: HuntingBag
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_huntingbag_navyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingbag_navyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingbag_navyblue.paa"
		};
	};
	class BRP_huntingbag_olivegreen: HuntingBag
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_huntingbag_olivegreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingbag_olivegreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingbag_olivegreen.paa"
		};
	};
	class BRP_huntingbag_orange: HuntingBag
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_huntingbag_orange.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingbag_orange.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingbag_orange.paa"
		};
	};
	class BRP_huntingbag_plum: HuntingBag
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_huntingbag_plum.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingbag_plum.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingbag_plum.paa"
		};
	};
	class BRP_huntingbag_purple: HuntingBag
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_huntingbag_purple.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingbag_purple.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingbag_purple.paa"
		};
	};
	class BRP_huntingbag_red: HuntingBag
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_huntingbag_red.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingbag_red.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingbag_red.paa"
		};
	};
	class BRP_huntingbag_royalblue: HuntingBag
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_huntingbag_royalblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingbag_royalblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingbag_royalblue.paa"
		};
	};
	class BRP_huntingbag_white: HuntingBag
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_huntingbag_white.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingbag_white.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingbag_white.paa"
		};
	};
	class BRP_huntingbag_yellow: HuntingBag
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_huntingbag_yellow.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingbag_yellow.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingbag_yellow.paa"
		};
	};
	/*class BRP_huntingbag_test: HuntingBag
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_huntingbag_test.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingbag_test.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingbag_test.paa"
		};
	};*/
	class HuntingJacket_ColorBase;
	class BRP_huntingjacket_armygreen: HuntingJacket_ColorBase
	{
		scope=2;
		visibilityModifier=0.80000001;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_huntingjacket_armygreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingjacket_armygreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingjacket_armygreen.paa"
		};
	};
	class BRP_huntingjacket_babyblue: HuntingJacket_ColorBase
	{
		scope=2;
		visibilityModifier=0.80000001;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_huntingjacket_babyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingjacket_babyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingjacket_babyblue.paa"
		};
	};
	class BRP_huntingjacket_babypink: HuntingJacket_ColorBase
	{
		scope=2;
		visibilityModifier=0.80000001;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_huntingjacket_babypink.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingjacket_babypink.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingjacket_babypink.paa"
		};
	};
	class BRP_huntingjacket_black: HuntingJacket_ColorBase
	{
		scope=2;
		visibilityModifier=0.80000001;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_huntingjacket_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingjacket_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingjacket_black.paa"
		};
	};
	class BRP_huntingjacket_beige: HuntingJacket_ColorBase
	{
		scope=2;
		visibilityModifier=0.80000001;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_huntingjacket_beige.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingjacket_beige.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingjacket_beige.paa"
		};
	};
	class BRP_huntingjacket_burgundy: HuntingJacket_ColorBase
	{
		scope=2;
		visibilityModifier=0.80000001;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_huntingjacket_burgundy.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingjacket_burgundy.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingjacket_burgundy.paa"
		};
	};
	class BRP_huntingjacket_candypink: HuntingJacket_ColorBase
	{
		scope=2;
		visibilityModifier=0.80000001;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_huntingjacket_candypink.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingjacket_candypink.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingjacket_candypink.paa"
		};
	};
	class BRP_huntingjacket_cream: HuntingJacket_ColorBase
	{
		scope=2;
		visibilityModifier=0.80000001;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_huntingjacket_cream.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingjacket_cream.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingjacket_cream.paa"
		};
	};
	class BRP_huntingjacket_cyan: HuntingJacket_ColorBase
	{
		scope=2;
		visibilityModifier=0.80000001;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_huntingjacket_cyan.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingjacket_cyan.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingjacket_cyan.paa"
		};
	};
	class BRP_huntingjacket_darkbrown: HuntingJacket_ColorBase
	{
		scope=2;
		visibilityModifier=0.80000001;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_huntingjacket_darkbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingjacket_darkbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingjacket_darkbrown.paa"
		};
	};
	class BRP_huntingjacket_darkgrey: HuntingJacket_ColorBase
	{
		scope=2;
		visibilityModifier=0.80000001;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_huntingjacket_darkgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingjacket_darkgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingjacket_darkgrey.paa"
		};
	};
	class BRP_huntingjacket_fuchsia: HuntingJacket_ColorBase
	{
		scope=2;
		visibilityModifier=0.80000001;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_huntingjacket_fuchsia.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingjacket_fuchsia.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingjacket_fuchsia.paa"
		};
	};
	class BRP_huntingjacket_lavender: HuntingJacket_ColorBase
	{
		scope=2;
		visibilityModifier=0.80000001;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_huntingjacket_lavender.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingjacket_lavender.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingjacket_lavender.paa"
		};
	};
	class BRP_huntingjacket_lightbrown: HuntingJacket_ColorBase
	{
		scope=2;
		visibilityModifier=0.80000001;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_huntingjacket_lightbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingjacket_lightbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingjacket_lightbrown.paa"
		};
	};
	class BRP_huntingjacket_lightgrey: HuntingJacket_ColorBase
	{
		scope=2;
		visibilityModifier=0.80000001;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_huntingjacket_lightgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingjacket_lightgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingjacket_lightgrey.paa"
		};
	};
	class BRP_huntingjacket_navyblue: HuntingJacket_ColorBase
	{
		scope=2;
		visibilityModifier=0.80000001;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_huntingjacket_navyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingjacket_navyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingjacket_navyblue.paa"
		};
	};
	class BRP_huntingjacket_olivegreen: HuntingJacket_ColorBase
	{
		scope=2;
		visibilityModifier=0.80000001;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_huntingjacket_olivegreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingjacket_olivegreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingjacket_olivegreen.paa"
		};
	};
	class BRP_huntingjacket_orange: HuntingJacket_ColorBase
	{
		scope=2;
		visibilityModifier=0.80000001;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_huntingjacket_orange.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingjacket_orange.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingjacket_orange.paa"
		};
	};
	class BRP_huntingjacket_plum: HuntingJacket_ColorBase
	{
		scope=2;
		visibilityModifier=0.80000001;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_huntingjacket_plum.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingjacket_plum.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingjacket_plum.paa"
		};
	};
	class BRP_huntingjacket_purple: HuntingJacket_ColorBase
	{
		scope=2;
		visibilityModifier=0.80000001;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_huntingjacket_purple.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingjacket_purple.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingjacket_purple.paa"
		};
	};
	class BRP_huntingjacket_red: HuntingJacket_ColorBase
	{
		scope=2;
		visibilityModifier=0.80000001;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_huntingjacket_red.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingjacket_red.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingjacket_red.paa"
		};
	};
	class BRP_huntingjacket_royalblue: HuntingJacket_ColorBase
	{
		scope=2;
		visibilityModifier=0.80000001;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_huntingjacket_royalblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingjacket_royalblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingjacket_royalblue.paa"
		};
	};
	class BRP_huntingjacket_white: HuntingJacket_ColorBase
	{
		scope=2;
		visibilityModifier=0.80000001;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_huntingjacket_white.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingjacket_white.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingjacket_white.paa"
		};
	};
	class BRP_huntingjacket_yellow: HuntingJacket_ColorBase
	{
		scope=2;
		visibilityModifier=0.80000001;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_huntingjacket_yellow.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingjacket_yellow.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingjacket_yellow.paa"
		};
	};
	/*class BRP_huntingjacket_test: HuntingJacket_ColorBase
	{
		scope=2;
		visibilityModifier=0.80000001;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_huntingjacket_test.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingjacket_test.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_huntingjacket_test.paa"
		};
	};*/
	class M65Jacket_ColorBase;
	class BRP_m65jacket_vivian: M65Jacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_m65jacket_vivian.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_m65jacket_vivian.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_m65jacket_vivian.paa"
		};
	};
	class BRP_m65jacket_armygreen: M65Jacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_m65jacket_armygreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_m65jacket_armygreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_m65jacket_armygreen.paa"
		};
	};
	class BRP_m65jacket_babyblue: M65Jacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_m65jacket_babyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_m65jacket_babyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_m65jacket_babyblue.paa"
		};
	};
	class BRP_m65jacket_babypink: M65Jacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_m65jacket_babypink.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_m65jacket_babypink.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_m65jacket_babypink.paa"
		};
	};
	class BRP_m65jacket_black: M65Jacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_m65jacket_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_m65jacket_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_m65jacket_black.paa"
		};
	};
	class BRP_m65jacket_beige: M65Jacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_m65jacket_beige.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_m65jacket_beige.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_m65jacket_beige.paa"
		};
	};
	class BRP_m65jacket_burgundy: M65Jacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_m65jacket_burgundy.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_m65jacket_burgundy.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_m65jacket_burgundy.paa"
		};
	};
	class BRP_m65jacket_candypink: M65Jacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_m65jacket_candypink.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_m65jacket_candypink.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_m65jacket_candypink.paa"
		};
	};
	class BRP_m65jacket_cream: M65Jacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_m65jacket_cream.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_m65jacket_cream.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_m65jacket_cream.paa"
		};
	};
	class BRP_m65jacket_cyan: M65Jacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_m65jacket_cyan.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_m65jacket_cyan.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_m65jacket_cyan.paa"
		};
	};
	class BRP_m65jacket_darkbrown: M65Jacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_m65jacket_darkbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_m65jacket_darkbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_m65jacket_darkbrown.paa"
		};
	};
	class BRP_m65jacket_darkgrey: M65Jacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_m65jacket_darkgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_m65jacket_darkgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_m65jacket_darkgrey.paa"
		};
	};
	class BRP_m65jacket_fuchsia: M65Jacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_m65jacket_fuchsia.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_m65jacket_fuchsia.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_m65jacket_fuchsia.paa"
		};
	};
	class BRP_m65jacket_lavender: M65Jacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_m65jacket_lavender.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_m65jacket_lavender.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_m65jacket_lavender.paa"
		};
	};
	class BRP_m65jacket_lightbrown: M65Jacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_m65jacket_lightbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_m65jacket_lightbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_m65jacket_lightbrown.paa"
		};
	};
	class BRP_m65jacket_lightgrey: M65Jacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_m65jacket_lightgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_m65jacket_lightgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_m65jacket_lightgrey.paa"
		};
	};
	class BRP_m65jacket_navyblue: M65Jacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_m65jacket_navyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_m65jacket_navyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_m65jacket_navyblue.paa"
		};
	};
	class BRP_m65jacket_olivegreen: M65Jacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_m65jacket_olivegreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_m65jacket_olivegreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_m65jacket_olivegreen.paa"
		};
	};
	class BRP_m65jacket_orange: M65Jacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_m65jacket_orange.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_m65jacket_orange.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_m65jacket_orange.paa"
		};
	};
	class BRP_m65jacket_plum: M65Jacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_m65jacket_plum.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_m65jacket_plum.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_m65jacket_plum.paa"
		};
	};
	class BRP_m65jacket_purple: M65Jacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_m65jacket_purple.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_m65jacket_purple.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_m65jacket_purple.paa"
		};
	};
	class BRP_m65jacket_red: M65Jacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_m65jacket_red.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_m65jacket_red.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_m65jacket_red.paa"
		};
	};
	class BRP_m65jacket_royalblue: M65Jacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_m65jacket_royalblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_m65jacket_royalblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_m65jacket_royalblue.paa"
		};
	};
	class BRP_m65jacket_white: M65Jacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_m65jacket_white.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_m65jacket_white.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_m65jacket_white.paa"
		};
	};
	class BRP_m65jacket_yellow: M65Jacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_m65jacket_yellow.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_m65jacket_yellow.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_m65jacket_yellow.paa"
		};
	};
	/*class BRP_m65jacket_test: M65Jacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_m65jacket_test.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_m65jacket_test.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_m65jacket_test.paa"
		};
	};*/
	class WindstridePoncho: Clothing
	{
		//itemSize[]={2,2};
	};
	class BRP_poncho_test: WindstridePoncho
	{
		scope=0;//Will not show in menu unless scope=2
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_poncho_test.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_poncho_test.paa"
		};
	};
	class BRP_poncho_hellokitty: WindstridePoncho
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_poncho_hellokitty.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_poncho_hellokittyg.paa"
		};
	};
	class BRP_poncho_armygreen: WindstridePoncho
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_poncho_armygreen.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_poncho_armygreeng.paa"
		};
	};
	class BRP_poncho_babyblue: WindstridePoncho
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_poncho_babyblue.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_poncho_babyblueg.paa"
		};
	};
	class BRP_poncho_babypink: WindstridePoncho
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_poncho_babypink.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_poncho_babypinkg.paa"
		};
	};
	class BRP_poncho_black: WindstridePoncho
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_poncho_black.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_poncho_blackg.paa"
		};
	};
	class BRP_poncho_beige: WindstridePoncho
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_poncho_beige.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_poncho_beigeg.paa"
		};
	};
	class BRP_poncho_burgundy: WindstridePoncho
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_poncho_burgundy.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_poncho_burgundyg.paa"
		};
	};
	class BRP_poncho_candypink: WindstridePoncho
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_poncho_candypink.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_poncho_candypinkg.paa"
		};
	};
	class BRP_poncho_cream: WindstridePoncho
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_poncho_cream.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_poncho_creamg.paa"
		};
	};
	class BRP_poncho_cyan: WindstridePoncho
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_poncho_cyan.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_poncho_cyang.paa"
		};
	};
	class BRP_poncho_darkbrown: WindstridePoncho
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_poncho_darkbrown.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_poncho_darkbrowng.paa"
		};
	};
	class BRP_poncho_darkgrey: WindstridePoncho
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_poncho_darkgrey.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_poncho_darkgreyg.paa"
		};
	};
	class BRP_poncho_fuchsia: WindstridePoncho
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_poncho_fuchsia.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_poncho_fuchsiag.paa"
		};
	};
	class BRP_poncho_lavender: WindstridePoncho
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_poncho_lavender.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_poncho_lavenderg.paa"
		};
	};
	class BRP_poncho_lightbrown: WindstridePoncho
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_poncho_lightbrown.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_poncho_lightbrowng.paa"
		};
	};
	class BRP_poncho_lightgrey: WindstridePoncho
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_poncho_lightgrey.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_poncho_lightgreyg.paa"
		};
	};
	class BRP_poncho_navyblue: WindstridePoncho
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_poncho_navyblue.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_poncho_navyblueg.paa"
		};
	};
	class BRP_poncho_olivegreen: WindstridePoncho
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_poncho_olivegreen.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_poncho_olivegreeng.paa"
		};
	};
	class BRP_poncho_orange: WindstridePoncho
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_poncho_orange.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_poncho_orangeg.paa"
		};
	};
	class BRP_poncho_plum: WindstridePoncho
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_poncho_plum.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_poncho_plumg.paa"
		};
	};
	class BRP_poncho_purple: WindstridePoncho
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_poncho_purple.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_poncho_purpleg.paa"
		};
	};
	class BRP_poncho_red: WindstridePoncho
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_poncho_red.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_poncho_redg.paa"
		};
	};
	class BRP_poncho_royalblue: WindstridePoncho
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_poncho_royalblue.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_poncho_royalblueg.paa"
		};
	};
	class BRP_poncho_white: WindstridePoncho
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_poncho_white.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_poncho_whiteg.paa"
		};
	};
	class BRP_poncho_yellow: WindstridePoncho
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_poncho_yellow.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_poncho_yellowg.paa"
		};
	};
	/*class BRP_poncho_test: WindstridePoncho
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_poncho_test.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_poncho_test.paa"
		};
	};*/
	class RadarCap_ColorBase: Clothing
	{
		//itemSize[]={2,2};
	};
	class BRP_radarcap_aegis: RadarCap_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_radarcap_aegis.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_radarcap_aegis.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_radarcap_aegis.paa"
		};
	};
	class BRP_radarcap_armygreen: RadarCap_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_radarcap_armygreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_radarcap_armygreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_radarcap_armygreen.paa"
		};
	};
	class BRP_radarcap_babyblue: RadarCap_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_radarcap_babyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_radarcap_babyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_radarcap_babyblue.paa"
		};
	};
	class BRP_radarcap_babypink: RadarCap_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_radarcap_babypink.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_radarcap_babypink.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_radarcap_babypink.paa"
		};
	};
	class BRP_radarcap_black: RadarCap_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_radarcap_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_radarcap_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_radarcap_black.paa"
		};
	};
	class BRP_radarcap_beige: RadarCap_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_radarcap_beige.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_radarcap_beige.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_radarcap_beige.paa"
		};
	};
	class BRP_radarcap_burgundy: RadarCap_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_radarcap_burgundy.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_radarcap_burgundy.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_radarcap_burgundy.paa"
		};
	};
	class BRP_radarcap_candypink: RadarCap_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_radarcap_candypink.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_radarcap_candypink.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_radarcap_candypink.paa"
		};
	};
	class BRP_radarcap_cream: RadarCap_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_radarcap_cream.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_radarcap_cream.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_radarcap_cream.paa"
		};
	};
	class BRP_radarcap_cyan: RadarCap_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_radarcap_cyan.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_radarcap_cyan.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_radarcap_cyan.paa"
		};
	};
	class BRP_radarcap_darkbrown: RadarCap_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_radarcap_darkbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_radarcap_darkbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_radarcap_darkbrown.paa"
		};
	};
	class BRP_radarcap_darkgrey: RadarCap_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_radarcap_darkgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_radarcap_darkgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_radarcap_darkgrey.paa"
		};
	};
	class BRP_radarcap_fuchsia: RadarCap_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_radarcap_fuchsia.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_radarcap_fuchsia.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_radarcap_fuchsia.paa"
		};
	};
	class BRP_radarcap_lavender: RadarCap_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_radarcap_lavender.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_radarcap_lavender.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_radarcap_lavender.paa"
		};
	};
	class BRP_radarcap_lightbrown: RadarCap_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_radarcap_lightbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_radarcap_lightbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_radarcap_lightbrown.paa"
		};
	};
	class BRP_radarcap_lightgrey: RadarCap_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_radarcap_lightgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_radarcap_lightgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_radarcap_lightgrey.paa"
		};
	};
	class BRP_radarcap_navyblue: RadarCap_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_radarcap_navyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_radarcap_navyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_radarcap_navyblue.paa"
		};
	};
	class BRP_radarcap_olivegreen: RadarCap_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_radarcap_olivegreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_radarcap_olivegreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_radarcap_olivegreen.paa"
		};
	};
	class BRP_radarcap_orange: RadarCap_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_radarcap_orange.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_radarcap_orange.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_radarcap_orange.paa"
		};
	};
	class BRP_radarcap_plum: RadarCap_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_radarcap_plum.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_radarcap_plum.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_radarcap_plum.paa"
		};
	};
	class BRP_radarcap_purple: RadarCap_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_radarcap_purple.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_radarcap_purple.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_radarcap_purple.paa"
		};
	};
	class BRP_radarcap_red: RadarCap_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_radarcap_red.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_radarcap_red.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_radarcap_red.paa"
		};
	};
	class BRP_radarcap_royalblue: RadarCap_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_radarcap_royalblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_radarcap_royalblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_radarcap_royalblue.paa"
		};
	};
	class BRP_radarcap_white: RadarCap_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_radarcap_white.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_radarcap_white.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_radarcap_white.paa"
		};
	};
	class BRP_radarcap_yellow: RadarCap_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_radarcap_yellow.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_radarcap_yellow.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_radarcap_yellow.paa"
		};
	};
	/*class BRP_radarcap_test: RadarCap_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_radarcap_test.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_radarcap_test.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_radarcap_test.paa"
		};
	};*/
	class RidersJacket_ColorBase: Clothing
	{
		//itemSize[]={4,3};
	};
	class BRP_ridersjacket_king: RidersJacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_king.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_king.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_king.paa"
		};
	};
	class BRP_ridersjacket_brain: RidersJacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_brain.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_brain.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_brain.paa"
		};
	};
	class BRP_ridersjacket_armada: RidersJacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_armada.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_armada.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_armada.paa"
		};
	};
	class BRP_ridersjacket_mud: RidersJacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_mud.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_mud.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_mud.paa"
		};
	};
	class BRP_ridersjacket_armygreen: RidersJacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_armygreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_armygreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_armygreen.paa"
		};
	};
	class BRP_ridersjacket_babyblue: RidersJacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_babyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_babyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_babyblue.paa"
		};
	};
	class BRP_ridersjacket_babypink: RidersJacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_babypink.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_babypink.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_babypink.paa"
		};
	};
	class BRP_ridersjacket_black: RidersJacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_black.paa"
		};
	};
	class BRP_ridersjacket_beige: RidersJacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_beige.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_beige.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_beige.paa"
		};
	};
	class BRP_ridersjacket_burgundy: RidersJacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_burgundy.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_burgundy.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_burgundy.paa"
		};
	};
	class BRP_ridersjacket_candypink: RidersJacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_candypink.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_candypink.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_candypink.paa"
		};
	};
	class BRP_ridersjacket_cream: RidersJacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_cream.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_cream.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_cream.paa"
		};
	};
	class BRP_ridersjacket_cyan: RidersJacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_cyan.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_cyan.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_cyan.paa"
		};
	};
	class BRP_ridersjacket_darkbrown: RidersJacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_darkbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_darkbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_darkbrown.paa"
		};
	};
	class BRP_ridersjacket_darkgrey: RidersJacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_darkgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_darkgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_darkgrey.paa"
		};
	};
	class BRP_ridersjacket_fuchsia: RidersJacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_fuchsia.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_fuchsia.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_fuchsia.paa"
		};
	};
	class BRP_ridersjacket_lavender: RidersJacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_lavender.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_lavender.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_lavender.paa"
		};
	};
	class BRP_ridersjacket_lightbrown: RidersJacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_lightbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_lightbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_lightbrown.paa"
		};
	};
	class BRP_ridersjacket_lightgrey: RidersJacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_lightgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_lightgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_lightgrey.paa"
		};
	};
	class BRP_ridersjacket_navyblue: RidersJacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_navyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_navyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_navyblue.paa"
		};
	};
	class BRP_ridersjacket_olivegreen: RidersJacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_olivegreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_olivegreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_olivegreen.paa"
		};
	};
	class BRP_ridersjacket_orange: RidersJacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_orange.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_orange.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_orange.paa"
		};
	};
	class BRP_ridersjacket_plum: RidersJacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_plum.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_plum.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_plum.paa"
		};
	};
	class BRP_ridersjacket_purple: RidersJacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_purple.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_purple.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_purple.paa"
		};
	};
	class BRP_ridersjacket_red: RidersJacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_red.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_red.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_red.paa"
		};
	};
	class BRP_ridersjacket_royalblue: RidersJacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_royalblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_royalblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_royalblue.paa"
		};
	};
	class BRP_ridersjacket_white: RidersJacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_white.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_white.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_white.paa"
		};
	};
	class BRP_ridersjacket_yellow: RidersJacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_yellow.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_yellow.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_yellow.paa"
		};
	};
	/*class BRP_ridersjacket_test: RidersJacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_test.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_test.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_ridersjacket_test.paa"
		};
	};*/
//Shemaghs have a very weird classname naming scheme to allow Windstrides base recipe to accomodate the clothing type switch
	class Shemagh_ColorBase;
	class Shemagh_Bandit_ColorBase;
	class Shemagh_Facemask_ColorBase;
	class Shemagh_Scarf_ColorBase;
	class BRP_shemagh_fangs_color: Shemagh_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_black.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_black.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_black.paa"
		};
	};
	class BRP_shemagh_bandit_fangs_color: Shemagh_Bandit_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_black.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_black.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_black.paa"
		};
	};
	class BRP_shemagh_facemask_fangs_color: Shemagh_Facemask_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_fangs.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_fangs.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_fangs.paa"
		};
	};
	class BRP_shemagh_scarf_fangs_color: Shemagh_Scarf_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_black.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_black.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_black.paa"
		};
	};
	class Shemagh_coda_fangs: BRP_shemagh_fangs_color
	{
		scope=2;
		color="coda_fangs";
	};
	class Shemagh_Bandit_coda_fangs: BRP_shemagh_bandit_fangs_color
	{
		scope=2;
		color="coda_fangs";
	};
	class Shemagh_Facemask_coda_fangs: BRP_shemagh_facemask_fangs_color
	{
		scope=2;
		color="coda_fangs";
	};
	class Shemagh_Scarf_coda_fangs: BRP_shemagh_scarf_fangs_color 
	{
		scope=2;
		color="coda_fangs";
	};
	class BRP_shemagh_armygreen_color: Shemagh_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_armygreen.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_armygreen.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_armygreen.paa"
		};
	};
	class BRP_shemagh_bandit_armygreen_color: Shemagh_Bandit_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_armygreen.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_armygreen.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_armygreen.paa"
		};
	};
	class BRP_shemagh_facemask_armygreen_color: Shemagh_Facemask_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_armygreen.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_armygreen.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_armygreen.paa"
		};
	};
	class BRP_shemagh_scarf_armygreen_color: Shemagh_Scarf_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_armygreen.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_armygreen.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_armygreen.paa"
		};
	};
	class Shemagh_coda_armygreen: BRP_shemagh_armygreen_color
	{
		scope=2;
		color="coda_armygreen";
	};
	class Shemagh_Bandit_coda_armygreen: BRP_shemagh_bandit_armygreen_color
	{
		scope=2;
		color="coda_armygreen";
	};
	class Shemagh_Facemask_coda_armygreen: BRP_shemagh_facemask_armygreen_color
	{
		scope=2;
		color="coda_armygreen";
	};
	class Shemagh_Scarf_coda_armygreen: BRP_shemagh_scarf_armygreen_color 
	{
		scope=2;
		color="coda_armygreen";
	};
	class BRP_shemagh_babyblue_color: Shemagh_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_babyblue.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_babyblue.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_babyblue.paa"
		};
	};
	class BRP_shemagh_bandit_babyblue_color: Shemagh_Bandit_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_babyblue.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_babyblue.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_babyblue.paa"
		};
	};
	class BRP_shemagh_facemask_babyblue_color: Shemagh_Facemask_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_babyblue.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_babyblue.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_babyblue.paa"
		};
	};
	class BRP_shemagh_scarf_babyblue_color: Shemagh_Scarf_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_babyblue.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_babyblue.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_babyblue.paa"
		};
	};
	class Shemagh_coda_babyblue: BRP_shemagh_babyblue_color
	{
		scope=2;
		color="coda_babyblue";
	};
	class Shemagh_Bandit_coda_babyblue: BRP_shemagh_bandit_babyblue_color
	{
		scope=2;
		color="coda_babyblue";
	};
	class Shemagh_Facemask_coda_babyblue: BRP_shemagh_facemask_babyblue_color
	{
		scope=2;
		color="coda_babyblue";
	};
	class Shemagh_Scarf_coda_babyblue: BRP_shemagh_scarf_babyblue_color 
	{
		scope=2;
		color="coda_babyblue";
	};
	class BRP_shemagh_babypink_color: Shemagh_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_babypink.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_babypink.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_babypink.paa"
		};
	};
	class BRP_shemagh_bandit_babypink_color: Shemagh_Bandit_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_babypink.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_babypink.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_babypink.paa"
		};
	};
	class BRP_shemagh_facemask_babypink_color: Shemagh_Facemask_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_babypink.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_babypink.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_babypink.paa"
		};
	};
	class BRP_shemagh_scarf_babypink_color: Shemagh_Scarf_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_babypink.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_babypink.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_babypink.paa"
		};
	};
	class Shemagh_coda_babypink: BRP_shemagh_babypink_color
	{
		scope=2;
		color="coda_babypink";
	};
	class Shemagh_Bandit_coda_babypink: BRP_shemagh_bandit_babypink_color
	{
		scope=2;
		color="coda_babypink";
	};
	class Shemagh_Facemask_coda_babypink: BRP_shemagh_facemask_babypink_color
	{
		scope=2;
		color="coda_babypink";
	};
	class Shemagh_Scarf_coda_babypink: BRP_shemagh_scarf_babypink_color 
	{
		scope=2;
		color="coda_babypink";
	};
	class BRP_shemagh_black_color: Shemagh_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_black.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_black.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_black.paa"
		};
	};
	class BRP_shemagh_bandit_black_color: Shemagh_Bandit_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_black.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_black.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_black.paa"
		};
	};
	class BRP_shemagh_facemask_black_color: Shemagh_Facemask_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_black.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_black.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_black.paa"
		};
	};
	class BRP_shemagh_scarf_black_color: Shemagh_Scarf_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_black.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_black.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_black.paa"
		};
	};
	class Shemagh_coda_black: BRP_shemagh_black_color
	{
		scope=2;
		color="coda_black";
	};
	class Shemagh_Bandit_coda_black: BRP_shemagh_bandit_black_color
	{
		scope=2;
		color="coda_black";
	};
	class Shemagh_Facemask_coda_black: BRP_shemagh_facemask_black_color
	{
		scope=2;
		color="coda_black";
	};
	class Shemagh_Scarf_coda_black: BRP_shemagh_scarf_black_color 
	{
		scope=2;
		color="coda_black";
	};
	class BRP_shemagh_beige_color: Shemagh_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_beige.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_beige.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_beige.paa"
		};
	};
	class BRP_shemagh_bandit_beige_color: Shemagh_Bandit_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_beige.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_beige.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_beige.paa"
		};
	};
	class BRP_shemagh_facemask_beige_color: Shemagh_Facemask_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_beige.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_beige.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_beige.paa"
		};
	};
	class BRP_shemagh_scarf_beige_color: Shemagh_Scarf_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_beige.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_beige.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_beige.paa"
		};
	};
	class Shemagh_coda_beige: BRP_shemagh_beige_color
	{
		scope=2;
		color="coda_beige";
	};
	class Shemagh_Bandit_coda_beige: BRP_shemagh_bandit_beige_color
	{
		scope=2;
		color="coda_beige";
	};
	class Shemagh_Facemask_coda_beige: BRP_shemagh_facemask_beige_color
	{
		scope=2;
		color="coda_beige";
	};
	class Shemagh_Scarf_coda_beige: BRP_shemagh_scarf_beige_color 
	{
		scope=2;
		color="coda_beige";
	};
	class BRP_shemagh_burgundy_color: Shemagh_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_burgundy.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_burgundy.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_burgundy.paa"
		};
	};
	class BRP_shemagh_bandit_burgundy_color: Shemagh_Bandit_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_burgundy.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_burgundy.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_burgundy.paa"
		};
	};
	class BRP_shemagh_facemask_burgundy_color: Shemagh_Facemask_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_burgundy.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_burgundy.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_burgundy.paa"
		};
	};
	class BRP_shemagh_scarf_burgundy_color: Shemagh_Scarf_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_burgundy.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_burgundy.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_burgundy.paa"
		};
	};
	class Shemagh_coda_burgundy: BRP_shemagh_burgundy_color
	{
		scope=2;
		color="coda_burgundy";
	};
	class Shemagh_Bandit_coda_burgundy: BRP_shemagh_bandit_burgundy_color
	{
		scope=2;
		color="coda_burgundy";
	};
	class Shemagh_Facemask_coda_burgundy: BRP_shemagh_facemask_burgundy_color
	{
		scope=2;
		color="coda_burgundy";
	};
	class Shemagh_Scarf_coda_burgundy: BRP_shemagh_scarf_burgundy_color 
	{
		scope=2;
		color="coda_burgundy";
	};
	class BRP_shemagh_candypink_color: Shemagh_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_candypink.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_candypink.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_candypink.paa"
		};
	};
	class BRP_shemagh_bandit_candypink_color: Shemagh_Bandit_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_candypink.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_candypink.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_candypink.paa"
		};
	};
	class BRP_shemagh_facemask_candypink_color: Shemagh_Facemask_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_candypink.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_candypink.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_candypink.paa"
		};
	};
	class BRP_shemagh_scarf_candypink_color: Shemagh_Scarf_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_candypink.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_candypink.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_candypink.paa"
		};
	};
	class Shemagh_coda_candypink: BRP_shemagh_candypink_color
	{
		scope=2;
		color="coda_candypink";
	};
	class Shemagh_Bandit_coda_candypink: BRP_shemagh_bandit_candypink_color
	{
		scope=2;
		color="coda_candypink";
	};
	class Shemagh_Facemask_coda_candypink: BRP_shemagh_facemask_candypink_color
	{
		scope=2;
		color="coda_candypink";
	};
	class Shemagh_Scarf_coda_candypink: BRP_shemagh_scarf_candypink_color 
	{
		scope=2;
		color="coda_candypink";
	};
	class BRP_shemagh_cream_color: Shemagh_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_cream.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_cream.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_cream.paa"
		};
	};
	class BRP_shemagh_bandit_cream_color: Shemagh_Bandit_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_cream.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_cream.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_cream.paa"
		};
	};
	class BRP_shemagh_facemask_cream_color: Shemagh_Facemask_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_cream.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_cream.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_cream.paa"
		};
	};
	class BRP_shemagh_scarf_cream_color: Shemagh_Scarf_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_cream.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_cream.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_cream.paa"
		};
	};
	class Shemagh_coda_cream: BRP_shemagh_cream_color
	{
		scope=2;
		color="coda_cream";
	};
	class Shemagh_Bandit_coda_cream: BRP_shemagh_bandit_cream_color
	{
		scope=2;
		color="coda_cream";
	};
	class Shemagh_Facemask_coda_cream: BRP_shemagh_facemask_cream_color
	{
		scope=2;
		color="coda_cream";
	};
	class Shemagh_Scarf_coda_cream: BRP_shemagh_scarf_cream_color 
	{
		scope=2;
		color="coda_cream";
	};
	class BRP_shemagh_cyan_color: Shemagh_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_cyan.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_cyan.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_cyan.paa"
		};
	};
	class BRP_shemagh_bandit_cyan_color: Shemagh_Bandit_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_cyan.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_cyan.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_cyan.paa"
		};
	};
	class BRP_shemagh_facemask_cyan_color: Shemagh_Facemask_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_cyan.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_cyan.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_cyan.paa"
		};
	};
	class BRP_shemagh_scarf_cyan_color: Shemagh_Scarf_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_cyan.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_cyan.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_cyan.paa"
		};
	};
	class Shemagh_coda_cyan: BRP_shemagh_cyan_color
	{
		scope=2;
		color="coda_cyan";
	};
	class Shemagh_Bandit_coda_cyan: BRP_shemagh_bandit_cyan_color
	{
		scope=2;
		color="coda_cyan";
	};
	class Shemagh_Facemask_coda_cyan: BRP_shemagh_facemask_cyan_color
	{
		scope=2;
		color="coda_cyan";
	};
	class Shemagh_Scarf_coda_cyan: BRP_shemagh_scarf_cyan_color 
	{
		scope=2;
		color="coda_cyan";
	};
	class BRP_shemagh_darkbrown_color: Shemagh_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_darkbrown.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_darkbrown.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_darkbrown.paa"
		};
	};
	class BRP_shemagh_bandit_darkbrown_color: Shemagh_Bandit_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_darkbrown.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_darkbrown.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_darkbrown.paa"
		};
	};
	class BRP_shemagh_facemask_darkbrown_color: Shemagh_Facemask_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_darkbrown.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_darkbrown.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_darkbrown.paa"
		};
	};
	class BRP_shemagh_scarf_darkbrown_color: Shemagh_Scarf_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_darkbrown.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_darkbrown.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_darkbrown.paa"
		};
	};
	class Shemagh_coda_darkbrown: BRP_shemagh_darkbrown_color
	{
		scope=2;
		color="coda_darkbrown";
	};
	class Shemagh_Bandit_coda_darkbrown: BRP_shemagh_bandit_darkbrown_color
	{
		scope=2;
		color="coda_darkbrown";
	};
	class Shemagh_Facemask_coda_darkbrown: BRP_shemagh_facemask_darkbrown_color
	{
		scope=2;
		color="coda_darkbrown";
	};
	class Shemagh_Scarf_coda_darkbrown: BRP_shemagh_scarf_darkbrown_color 
	{
		scope=2;
		color="coda_darkbrown";
	};
	class BRP_shemagh_darkgrey_color: Shemagh_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_darkgrey.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_darkgrey.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_darkgrey.paa"
		};
	};
	class BRP_shemagh_bandit_darkgrey_color: Shemagh_Bandit_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_darkgrey.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_darkgrey.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_darkgrey.paa"
		};
	};
	class BRP_shemagh_facemask_darkgrey_color: Shemagh_Facemask_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_darkgrey.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_darkgrey.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_darkgrey.paa"
		};
	};
	class BRP_shemagh_scarf_darkgrey_color: Shemagh_Scarf_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_darkgrey.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_darkgrey.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_darkgrey.paa"
		};
	};
	class Shemagh_coda_darkgrey: BRP_shemagh_darkgrey_color
	{
		scope=2;
		color="coda_darkgrey";
	};
	class Shemagh_Bandit_coda_darkgrey: BRP_shemagh_bandit_darkgrey_color
	{
		scope=2;
		color="coda_darkgrey";
	};
	class Shemagh_Facemask_coda_darkgrey: BRP_shemagh_facemask_darkgrey_color
	{
		scope=2;
		color="coda_darkgrey";
	};
	class Shemagh_Scarf_coda_darkgrey: BRP_shemagh_scarf_darkgrey_color 
	{
		scope=2;
		color="coda_darkgrey";
	};
	class BRP_shemagh_fuchsia_color: Shemagh_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_fuchsia.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_fuchsia.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_fuchsia.paa"
		};
	};
	class BRP_shemagh_bandit_fuchsia_color: Shemagh_Bandit_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_fuchsia.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_fuchsia.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_fuchsia.paa"
		};
	};
	class BRP_shemagh_facemask_fuchsia_color: Shemagh_Facemask_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_fuchsia.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_fuchsia.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_fuchsia.paa"
		};
	};
	class BRP_shemagh_scarf_fuchsia_color: Shemagh_Scarf_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_fuchsia.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_fuchsia.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_fuchsia.paa"
		};
	};
	class Shemagh_coda_fuchsia: BRP_shemagh_fuchsia_color
	{
		scope=2;
		color="coda_fuchsia";
	};
	class Shemagh_Bandit_coda_fuchsia: BRP_shemagh_bandit_fuchsia_color
	{
		scope=2;
		color="coda_fuchsia";
	};
	class Shemagh_Facemask_coda_fuchsia: BRP_shemagh_facemask_fuchsia_color
	{
		scope=2;
		color="coda_fuchsia";
	};
	class Shemagh_Scarf_coda_fuchsia: BRP_shemagh_scarf_fuchsia_color 
	{
		scope=2;
		color="coda_fuchsia";
	};
	class BRP_shemagh_lavender_color: Shemagh_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_lavender.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_lavender.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_lavender.paa"
		};
	};
	class BRP_shemagh_bandit_lavender_color: Shemagh_Bandit_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_lavender.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_lavender.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_lavender.paa"
		};
	};
	class BRP_shemagh_facemask_lavender_color: Shemagh_Facemask_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_lavender.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_lavender.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_lavender.paa"
		};
	};
	class BRP_shemagh_scarf_lavender_color: Shemagh_Scarf_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_lavender.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_lavender.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_lavender.paa"
		};
	};
	class Shemagh_coda_lavender: BRP_shemagh_lavender_color
	{
		scope=2;
		color="coda_lavender";
	};
	class Shemagh_Bandit_coda_lavender: BRP_shemagh_bandit_lavender_color
	{
		scope=2;
		color="coda_lavender";
	};
	class Shemagh_Facemask_coda_lavender: BRP_shemagh_facemask_lavender_color
	{
		scope=2;
		color="coda_lavender";
	};
	class Shemagh_Scarf_coda_lavender: BRP_shemagh_scarf_lavender_color 
	{
		scope=2;
		color="coda_lavender";
	};
	class BRP_shemagh_lightbrown_color: Shemagh_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_lightbrown.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_lightbrown.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_lightbrown.paa"
		};
	};
	class BRP_shemagh_bandit_lightbrown_color: Shemagh_Bandit_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_lightbrown.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_lightbrown.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_lightbrown.paa"
		};
	};
	class BRP_shemagh_facemask_lightbrown_color: Shemagh_Facemask_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_lightbrown.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_lightbrown.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_lightbrown.paa"
		};
	};
	class BRP_shemagh_scarf_lightbrown_color: Shemagh_Scarf_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_lightbrown.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_lightbrown.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_lightbrown.paa"
		};
	};
	class Shemagh_coda_lightbrown: BRP_shemagh_lightbrown_color
	{
		scope=2;
		color="coda_lightbrown";
	};
	class Shemagh_Bandit_coda_lightbrown: BRP_shemagh_bandit_lightbrown_color
	{
		scope=2;
		color="coda_lightbrown";
	};
	class Shemagh_Facemask_coda_lightbrown: BRP_shemagh_facemask_lightbrown_color
	{
		scope=2;
		color="coda_lightbrown";
	};
	class Shemagh_Scarf_coda_lightbrown: BRP_shemagh_scarf_lightbrown_color 
	{
		scope=2;
		color="coda_lightbrown";
	};
	class BRP_shemagh_lightgrey_color: Shemagh_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_lightgrey.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_lightgrey.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_lightgrey.paa"
		};
	};
	class BRP_shemagh_bandit_lightgrey_color: Shemagh_Bandit_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_lightgrey.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_lightgrey.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_lightgrey.paa"
		};
	};
	class BRP_shemagh_facemask_lightgrey_color: Shemagh_Facemask_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_lightgrey.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_lightgrey.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_lightgrey.paa"
		};
	};
	class BRP_shemagh_scarf_lightgrey_color: Shemagh_Scarf_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_lightgrey.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_lightgrey.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_lightgrey.paa"
		};
	};
	class Shemagh_coda_lightgrey: BRP_shemagh_lightgrey_color
	{
		scope=2;
		color="coda_lightgrey";
	};
	class Shemagh_Bandit_coda_lightgrey: BRP_shemagh_bandit_lightgrey_color
	{
		scope=2;
		color="coda_lightgrey";
	};
	class Shemagh_Facemask_coda_lightgrey: BRP_shemagh_facemask_lightgrey_color
	{
		scope=2;
		color="coda_lightgrey";
	};
	class Shemagh_Scarf_coda_lightgrey: BRP_shemagh_scarf_lightgrey_color 
	{
		scope=2;
		color="coda_lightgrey";
	};
	class BRP_shemagh_navyblue_color: Shemagh_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_navyblue.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_navyblue.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_navyblue.paa"
		};
	};
	class BRP_shemagh_bandit_navyblue_color: Shemagh_Bandit_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_navyblue.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_navyblue.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_navyblue.paa"
		};
	};
	class BRP_shemagh_facemask_navyblue_color: Shemagh_Facemask_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_navyblue.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_navyblue.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_navyblue.paa"
		};
	};
	class BRP_shemagh_scarf_navyblue_color: Shemagh_Scarf_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_navyblue.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_navyblue.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_navyblue.paa"
		};
	};
	class Shemagh_coda_navyblue: BRP_shemagh_navyblue_color
	{
		scope=2;
		color="coda_navyblue";
	};
	class Shemagh_Bandit_coda_navyblue: BRP_shemagh_bandit_navyblue_color
	{
		scope=2;
		color="coda_navyblue";
	};
	class Shemagh_Facemask_coda_navyblue: BRP_shemagh_facemask_navyblue_color
	{
		scope=2;
		color="coda_navyblue";
	};
	class Shemagh_Scarf_coda_navyblue: BRP_shemagh_scarf_navyblue_color 
	{
		scope=2;
		color="coda_navyblue";
	};
	class BRP_shemagh_olivegreen_color: Shemagh_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_olivegreen.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_olivegreen.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_olivegreen.paa"
		};
	};
	class BRP_shemagh_bandit_olivegreen_color: Shemagh_Bandit_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_olivegreen.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_olivegreen.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_olivegreen.paa"
		};
	};
	class BRP_shemagh_facemask_olivegreen_color: Shemagh_Facemask_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_olivegreen.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_olivegreen.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_olivegreen.paa"
		};
	};
	class BRP_shemagh_scarf_olivegreen_color: Shemagh_Scarf_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_olivegreen.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_olivegreen.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_olivegreen.paa"
		};
	};
	class Shemagh_coda_olivegreen: BRP_shemagh_olivegreen_color
	{
		scope=2;
		color="coda_olivegreen";
	};
	class Shemagh_Bandit_coda_olivegreen: BRP_shemagh_bandit_olivegreen_color
	{
		scope=2;
		color="coda_olivegreen";
	};
	class Shemagh_Facemask_coda_olivegreen: BRP_shemagh_facemask_olivegreen_color
	{
		scope=2;
		color="coda_olivegreen";
	};
	class Shemagh_Scarf_coda_olivegreen: BRP_shemagh_scarf_olivegreen_color 
	{
		scope=2;
		color="coda_olivegreen";
	};
	class BRP_shemagh_orange_color: Shemagh_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_orange.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_orange.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_orange.paa"
		};
	};
	class BRP_shemagh_bandit_orange_color: Shemagh_Bandit_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_orange.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_orange.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_orange.paa"
		};
	};
	class BRP_shemagh_facemask_orange_color: Shemagh_Facemask_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_orange.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_orange.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_orange.paa"
		};
	};
	class BRP_shemagh_scarf_orange_color: Shemagh_Scarf_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_orange.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_orange.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_orange.paa"
		};
	};
	class Shemagh_coda_orange: BRP_shemagh_orange_color
	{
		scope=2;
		color="coda_orange";
	};
	class Shemagh_Bandit_coda_orange: BRP_shemagh_bandit_orange_color
	{
		scope=2;
		color="coda_orange";
	};
	class Shemagh_Facemask_coda_orange: BRP_shemagh_facemask_orange_color
	{
		scope=2;
		color="coda_orange";
	};
	class Shemagh_Scarf_coda_orange: BRP_shemagh_scarf_orange_color 
	{
		scope=2;
		color="coda_orange";
	};
	class BRP_shemagh_plum_color: Shemagh_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_plum.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_plum.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_plum.paa"
		};
	};
	class BRP_shemagh_bandit_plum_color: Shemagh_Bandit_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_plum.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_plum.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_plum.paa"
		};
	};
	class BRP_shemagh_facemask_plum_color: Shemagh_Facemask_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_plum.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_plum.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_plum.paa"
		};
	};
	class BRP_shemagh_scarf_plum_color: Shemagh_Scarf_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_plum.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_plum.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_plum.paa"
		};
	};
	class Shemagh_coda_plum: BRP_shemagh_plum_color
	{
		scope=2;
		color="coda_plum";
	};
	class Shemagh_Bandit_coda_plum: BRP_shemagh_bandit_plum_color
	{
		scope=2;
		color="coda_plum";
	};
	class Shemagh_Facemask_coda_plum: BRP_shemagh_facemask_plum_color
	{
		scope=2;
		color="coda_plum";
	};
	class Shemagh_Scarf_coda_plum: BRP_shemagh_scarf_plum_color 
	{
		scope=2;
		color="coda_plum";
	};
	class BRP_shemagh_purple_color: Shemagh_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_purple.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_purple.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_purple.paa"
		};
	};
	class BRP_shemagh_bandit_purple_color: Shemagh_Bandit_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_purple.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_purple.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_purple.paa"
		};
	};
	class BRP_shemagh_facemask_purple_color: Shemagh_Facemask_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_purple.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_purple.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_purple.paa"
		};
	};
	class BRP_shemagh_scarf_purple_color: Shemagh_Scarf_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_purple.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_purple.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_purple.paa"
		};
	};
	class Shemagh_coda_purple: BRP_shemagh_purple_color
	{
		scope=2;
		color="coda_purple";
	};
	class Shemagh_Bandit_coda_purple: BRP_shemagh_bandit_purple_color
	{
		scope=2;
		color="coda_purple";
	};
	class Shemagh_Facemask_coda_purple: BRP_shemagh_facemask_purple_color
	{
		scope=2;
		color="coda_purple";
	};
	class Shemagh_Scarf_coda_purple: BRP_shemagh_scarf_purple_color 
	{
		scope=2;
		color="coda_purple";
	};
	class BRP_shemagh_red_color: Shemagh_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_red.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_red.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_red.paa"
		};
	};
	class BRP_shemagh_bandit_red_color: Shemagh_Bandit_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_red.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_red.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_red.paa"
		};
	};
	class BRP_shemagh_facemask_red_color: Shemagh_Facemask_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_red.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_red.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_red.paa"
		};
	};
	class BRP_shemagh_scarf_red_color: Shemagh_Scarf_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_red.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_red.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_red.paa"
		};
	};
	class Shemagh_coda_red: BRP_shemagh_red_color
	{
		scope=2;
		color="coda_red";
	};
	class Shemagh_Bandit_coda_red: BRP_shemagh_bandit_red_color
	{
		scope=2;
		color="coda_red";
	};
	class Shemagh_Facemask_coda_red: BRP_shemagh_facemask_red_color
	{
		scope=2;
		color="coda_red";
	};
	class Shemagh_Scarf_coda_red: BRP_shemagh_scarf_red_color 
	{
		scope=2;
		color="coda_red";
	};
	class BRP_shemagh_royalblue_color: Shemagh_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_royalblue.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_royalblue.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_royalblue.paa"
		};
	};
	class BRP_shemagh_bandit_royalblue_color: Shemagh_Bandit_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_royalblue.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_royalblue.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_royalblue.paa"
		};
	};
	class BRP_shemagh_facemask_royalblue_color: Shemagh_Facemask_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_royalblue.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_royalblue.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_royalblue.paa"
		};
	};
	class BRP_shemagh_scarf_royalblue_color: Shemagh_Scarf_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_royalblue.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_royalblue.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_royalblue.paa"
		};
	};
	class Shemagh_coda_royalblue: BRP_shemagh_royalblue_color
	{
		scope=2;
		color="coda_royalblue";
	};
	class Shemagh_Bandit_coda_royalblue: BRP_shemagh_bandit_royalblue_color
	{
		scope=2;
		color="coda_royalblue";
	};
	class Shemagh_Facemask_coda_royalblue: BRP_shemagh_facemask_royalblue_color
	{
		scope=2;
		color="coda_royalblue";
	};
	class Shemagh_Scarf_coda_royalblue: BRP_shemagh_scarf_royalblue_color 
	{
		scope=2;
		color="coda_royalblue";
	};
	class BRP_shemagh_white_color: Shemagh_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_white.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_white.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_white.paa"
		};
	};
	class BRP_shemagh_bandit_white_color: Shemagh_Bandit_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_white.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_white.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_white.paa"
		};
	};
	class BRP_shemagh_facemask_white_color: Shemagh_Facemask_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_white.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_white.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_white.paa"
		};
	};
	class BRP_shemagh_scarf_white_color: Shemagh_Scarf_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_white.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_white.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_white.paa"
		};
	};
	class Shemagh_coda_white: BRP_shemagh_white_color
	{
		scope=2;
		color="coda_white";
	};
	class Shemagh_Bandit_coda_white: BRP_shemagh_bandit_white_color
	{
		scope=2;
		color="coda_white";
	};
	class Shemagh_Facemask_coda_white: BRP_shemagh_facemask_white_color
	{
		scope=2;
		color="coda_white";
	};
	class Shemagh_Scarf_coda_white: BRP_shemagh_scarf_white_color 
	{
		scope=2;
		color="coda_white";
	};
	class BRP_shemagh_yellow_color: Shemagh_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_yellow.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_yellow.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_yellow.paa"
		};
	};
	class BRP_shemagh_bandit_yellow_color: Shemagh_Bandit_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_yellow.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_yellow.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_yellow.paa"
		};
	};
	class BRP_shemagh_facemask_yellow_color: Shemagh_Facemask_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_yellow.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_yellow.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_yellow.paa"
		};
	};
	class BRP_shemagh_scarf_yellow_color: Shemagh_Scarf_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_yellow.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_yellow.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_yellow.paa"
		};
	};
	class Shemagh_coda_yellow: BRP_shemagh_yellow_color
	{
		scope=2;
		color="coda_yellow";
	};
	class Shemagh_Bandit_coda_yellow: BRP_shemagh_bandit_yellow_color
	{
		scope=2;
		color="coda_yellow";
	};
	class Shemagh_Facemask_coda_yellow: BRP_shemagh_facemask_yellow_color
	{
		scope=2;
		color="coda_yellow";
	};
	class Shemagh_Scarf_coda_yellow: BRP_shemagh_scarf_yellow_color 
	{
		scope=2;
		color="coda_yellow";
	};
	class BRP_shemagh_babypinkcheck_color: Shemagh_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_full_babypinkcheck.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_full_babypinkcheck.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_full_babypinkcheck.paa"
		};
	};
	class BRP_shemagh_bandit_babypinkcheck_color: Shemagh_Bandit_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_bandit_babypinkcheck.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_bandit_babypinkcheck.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_bandit_babypinkcheck.paa"
		};
	};
	class BRP_shemagh_facemask_babypinkcheck_color: Shemagh_Facemask_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_facemask_babypinkcheck.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_facemask_babypinkcheck.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_facemask_babypinkcheck.paa"
		};
	};
	class BRP_shemagh_scarf_babypinkcheck_color: Shemagh_Scarf_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_scarf_babypinkcheck.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_scarf_babypinkcheck.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_scarf_babypinkcheck.paa"
		};
	};
	class Shemagh_coda_babypinkcheck: BRP_shemagh_babypinkcheck_color
	{
		scope=2;
		color="coda_babypinkcheck";
	};
	class Shemagh_Bandit_coda_babypinkcheck: BRP_shemagh_bandit_babypinkcheck_color
	{
		scope=2;
		color="coda_babypinkcheck";
	};
	class Shemagh_Facemask_coda_babypinkcheck: BRP_shemagh_facemask_babypinkcheck_color
	{
		scope=2;
		color="coda_babypinkcheck";
	};
	class Shemagh_Scarf_coda_babypinkcheck: BRP_shemagh_scarf_babypinkcheck_color 
	{
		scope=2;
		color="coda_babypinkcheck";
	};
	class BRP_shemagh_navybluecheck_color: Shemagh_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_full_navybluecheck.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_full_navybluecheck.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_full_navybluecheck.paa"
		};
	};
	class BRP_shemagh_bandit_navybluecheck_color: Shemagh_Bandit_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_bandit_navybluecheck.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_bandit_navybluecheck.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_bandit_navybluecheck.paa"
		};
	};
	class BRP_shemagh_facemask_navybluecheck_color: Shemagh_Facemask_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_facemask_navybluecheck.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_facemask_navybluecheck.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_facemask_navybluecheck.paa"
		};
	};
	class BRP_shemagh_scarf_navybluecheck_color: Shemagh_Scarf_ColorBase
	{
		visibilityModifier=0.85000002;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_scarf_navybluecheck.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_scarf_navybluecheck.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_shemagh_scarf_navybluecheck.paa"
		};
	};
	class Shemagh_coda_navybluecheck: BRP_shemagh_navybluecheck_color
	{
		scope=2;
		color="coda_navybluecheck";
	};
	class Shemagh_Bandit_coda_navybluecheck: BRP_shemagh_bandit_navybluecheck_color
	{
		scope=2;
		color="coda_navybluecheck";
	};
	class Shemagh_Facemask_coda_navybluecheck: BRP_shemagh_facemask_navybluecheck_color
	{
		scope=2;
		color="coda_navybluecheck";
	};
	class Shemagh_Scarf_coda_navybluecheck: BRP_shemagh_scarf_navybluecheck_color 
	{
		scope=2;
		color="coda_navybluecheck";
	};
	class Sneakers_ColorBase: Clothing
	{
		//itemSize[]={3,2};
	};
	class BRP_sneakers_galaxy: Sneakers_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_sneakers_galaxy.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sneakers_galaxy.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sneakers_galaxy.paa"
		};
	};
	class BRP_sneakers_hellokitty: Sneakers_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_sneakers_hellokitty.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sneakers_hellokitty.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sneakers_hellokitty.paa"
		};
	};
	class BRP_sneakers_armygreen: Sneakers_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_sneakers_armygreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sneakers_armygreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sneakers_armygreen.paa"
		};
	};
	class BRP_sneakers_babyblue: Sneakers_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_sneakers_babyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sneakers_babyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sneakers_babyblue.paa"
		};
	};
	class BRP_sneakers_babypink: Sneakers_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_sneakers_babypink.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sneakers_babypink.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sneakers_babypink.paa"
		};
	};
	class BRP_sneakers_black: Sneakers_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_sneakers_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sneakers_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sneakers_black.paa"
		};
	};
	class BRP_sneakers_beige: Sneakers_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_sneakers_beige.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sneakers_beige.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sneakers_beige.paa"
		};
	};
	class BRP_sneakers_burgundy: Sneakers_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_sneakers_burgundy.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sneakers_burgundy.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sneakers_burgundy.paa"
		};
	};
	class BRP_sneakers_candypink: Sneakers_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_sneakers_candypink.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sneakers_candypink.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sneakers_candypink.paa"
		};
	};
	class BRP_sneakers_cream: Sneakers_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_sneakers_cream.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sneakers_cream.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sneakers_cream.paa"
		};
	};
	class BRP_sneakers_cyan: Sneakers_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_sneakers_cyan.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sneakers_cyan.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sneakers_cyan.paa"
		};
	};
	class BRP_sneakers_darkbrown: Sneakers_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_sneakers_darkbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sneakers_darkbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sneakers_darkbrown.paa"
		};
	};
	class BRP_sneakers_darkgrey: Sneakers_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_sneakers_darkgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sneakers_darkgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sneakers_darkgrey.paa"
		};
	};
	class BRP_sneakers_fuchsia: Sneakers_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_sneakers_fuchsia.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sneakers_fuchsia.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sneakers_fuchsia.paa"
		};
	};
	class BRP_sneakers_lavender: Sneakers_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_sneakers_lavender.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sneakers_lavender.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sneakers_lavender.paa"
		};
	};
	class BRP_sneakers_lightbrown: Sneakers_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_sneakers_lightbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sneakers_lightbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sneakers_lightbrown.paa"
		};
	};
	class BRP_sneakers_lightgrey: Sneakers_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_sneakers_lightgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sneakers_lightgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sneakers_lightgrey.paa"
		};
	};
	class BRP_sneakers_navyblue: Sneakers_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_sneakers_navyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sneakers_navyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sneakers_navyblue.paa"
		};
	};
	class BRP_sneakers_olivegreen: Sneakers_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_sneakers_olivegreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sneakers_olivegreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sneakers_olivegreen.paa"
		};
	};
	class BRP_sneakers_orange: Sneakers_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_sneakers_orange.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sneakers_orange.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sneakers_orange.paa"
		};
	};
	class BRP_sneakers_plum: Sneakers_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_sneakers_plum.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sneakers_plum.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sneakers_plum.paa"
		};
	};
	class BRP_sneakers_purple: Sneakers_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_sneakers_purple.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sneakers_purple.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sneakers_purple.paa"
		};
	};
	class BRP_sneakers_red: Sneakers_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_sneakers_red.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sneakers_red.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sneakers_red.paa"
		};
	};
	class BRP_sneakers_royalblue: Sneakers_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_sneakers_royalblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sneakers_royalblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sneakers_royalblue.paa"
		};
	};
	class BRP_sneakers_white: Sneakers_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_sneakers_white.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sneakers_white.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sneakers_white.paa"
		};
	};
	class BRP_sneakers_yellow: Sneakers_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_sneakers_yellow.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sneakers_yellow.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sneakers_yellow.paa"
		};
	};
	/*class BRP_sneakers_test: Sneakers_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_sneakers_test.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sneakers_test.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sneakers_test.paa"
		};
	};*/
	class Sweater_ColorBase: Clothing
	{
		//itemsCargoSize[]={5,4};
	};
	class BRP_sweater_armygreen: Sweater_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_sweater_armygreeng.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sweater_armygreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sweater_armygreen.paa"
		};
	};
	class BRP_sweater_babyblue: Sweater_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_sweater_babyblueg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sweater_babyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sweater_babyblue.paa"
		};
	};
	class BRP_sweater_babypink: Sweater_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_sweater_babypinkg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sweater_babypink.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sweater_babypink.paa"
		};
	};
	class BRP_sweater_black: Sweater_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_sweater_blackg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sweater_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sweater_black.paa"
		};
	};
	class BRP_sweater_beige: Sweater_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_sweater_beigeg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sweater_beige.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sweater_beige.paa"
		};
	};
	class BRP_sweater_burgundy: Sweater_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_sweater_burgundyg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sweater_burgundy.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sweater_burgundy.paa"
		};
	};
	class BRP_sweater_candypink: Sweater_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_sweater_candypinkg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sweater_candypink.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sweater_candypink.paa"
		};
	};
	class BRP_sweater_cream: Sweater_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_sweater_creamg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sweater_cream.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sweater_cream.paa"
		};
	};
	class BRP_sweater_cyan: Sweater_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_sweater_cyang.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sweater_cyan.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sweater_cyan.paa"
		};
	};
	class BRP_sweater_darkbrown: Sweater_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_sweater_darkbrowng.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sweater_darkbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sweater_darkbrown.paa"
		};
	};
	class BRP_sweater_darkgrey: Sweater_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_sweater_darkgreyg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sweater_darkgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sweater_darkgrey.paa"
		};
	};
	class BRP_sweater_fuchsia: Sweater_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_sweater_fuchsiag.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sweater_fuchsia.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sweater_fuchsia.paa"
		};
	};
	class BRP_sweater_lavender: Sweater_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_sweater_lavenderg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sweater_lavender.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sweater_lavender.paa"
		};
	};
	class BRP_sweater_lightbrown: Sweater_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_sweater_lightbrowng.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sweater_lightbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sweater_lightbrown.paa"
		};
	};
	class BRP_sweater_lightgrey: Sweater_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_sweater_lightgreyg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sweater_lightgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sweater_lightgrey.paa"
		};
	};
	class BRP_sweater_navyblue: Sweater_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_sweater_navyblueg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sweater_navyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sweater_navyblue.paa"
		};
	};
	class BRP_sweater_olivegreen: Sweater_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_sweater_olivegreeng.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sweater_olivegreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sweater_olivegreen.paa"
		};
	};
	class BRP_sweater_orange: Sweater_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_sweater_orangeg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sweater_orange.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sweater_orange.paa"
		};
	};
	class BRP_sweater_plum: Sweater_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_sweater_plumg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sweater_plum.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sweater_plum.paa"
		};
	};
	class BRP_sweater_purple: Sweater_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_sweater_purpleg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sweater_purple.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sweater_purple.paa"
		};
	};
	class BRP_sweater_red: Sweater_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_sweater_redg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sweater_red.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sweater_red.paa"
		};
	};
	class BRP_sweater_royalblue: Sweater_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_sweater_royalblueg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sweater_royalblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sweater_royalblue.paa"
		};
	};
	class BRP_sweater_white: Sweater_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_sweater_whiteg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sweater_white.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sweater_white.paa"
		};
	};
	class BRP_sweater_yellow: Sweater_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_sweater_yellowg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sweater_yellow.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sweater_yellow.paa"
		};
	};
	/*class BRP_sweater_test: Sweater_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_sweater_testg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sweater_test.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_sweater_test.paa"
		};
	};*/
	class TaloonBag_ColorBase;
	class BRP_taloon_armygreen: TaloonBag_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_taloon_armygreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_taloon_armygreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_taloon_armygreen.paa"
		};
	};
	class BRP_taloon_babyblue: TaloonBag_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_taloon_babyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_taloon_babyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_taloon_babyblue.paa"
		};
	};
	class BRP_taloon_babypink: TaloonBag_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_taloon_babypink.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_taloon_babypink.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_taloon_babypink.paa"
		};
	};
	class BRP_taloon_black: TaloonBag_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_taloon_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_taloon_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_taloon_black.paa"
		};
	};
	class BRP_taloon_beige: TaloonBag_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_taloon_beige.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_taloon_beige.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_taloon_beige.paa"
		};
	};
	class BRP_taloon_burgundy: TaloonBag_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_taloon_burgundy.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_taloon_burgundy.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_taloon_burgundy.paa"
		};
	};
	class BRP_taloon_candypink: TaloonBag_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_taloon_candypink.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_taloon_candypink.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_taloon_candypink.paa"
		};
	};
	class BRP_taloon_cream: TaloonBag_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_taloon_cream.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_taloon_cream.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_taloon_cream.paa"
		};
	};
	class BRP_taloon_cyan: TaloonBag_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_taloon_cyan.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_taloon_cyan.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_taloon_cyan.paa"
		};
	};
	class BRP_taloon_darkbrown: TaloonBag_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_taloon_darkbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_taloon_darkbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_taloon_darkbrown.paa"
		};
	};
	class BRP_taloon_darkgrey: TaloonBag_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_taloon_darkgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_taloon_darkgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_taloon_darkgrey.paa"
		};
	};
	class BRP_taloon_fuchsia: TaloonBag_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_taloon_fuchsia.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_taloon_fuchsia.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_taloon_fuchsia.paa"
		};
	};
	class BRP_taloon_lavender: TaloonBag_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_taloon_lavender.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_taloon_lavender.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_taloon_lavender.paa"
		};
	};
	class BRP_taloon_lightbrown: TaloonBag_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_taloon_lightbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_taloon_lightbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_taloon_lightbrown.paa"
		};
	};
	class BRP_taloon_lightgrey: TaloonBag_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_taloon_lightgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_taloon_lightgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_taloon_lightgrey.paa"
		};
	};
	class BRP_taloon_navyblue: TaloonBag_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_taloon_navyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_taloon_navyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_taloon_navyblue.paa"
		};
	};
	class BRP_taloon_olivegreen: TaloonBag_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_taloon_olivegreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_taloon_olivegreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_taloon_olivegreen.paa"
		};
	};
	class BRP_taloon_orange: TaloonBag_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_taloon_orange.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_taloon_orange.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_taloon_orange.paa"
		};
	};
	class BRP_taloon_plum: TaloonBag_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_taloon_plum.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_taloon_plum.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_taloon_plum.paa"
		};
	};
	class BRP_taloon_purple: TaloonBag_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_taloon_purple.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_taloon_purple.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_taloon_purple.paa"
		};
	};
	class BRP_taloon_red: TaloonBag_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_taloon_red.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_taloon_red.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_taloon_red.paa"
		};
	};
	class BRP_taloon_royalblue: TaloonBag_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_taloon_royalblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_taloon_royalblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_taloon_royalblue.paa"
		};
	};
	class BRP_taloon_white: TaloonBag_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_taloon_white.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_taloon_white.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_taloon_white.paa"
		};
	};
	class BRP_taloon_yellow: TaloonBag_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_taloon_yellow.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_taloon_yellow.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_taloon_yellow.paa"
		};
	};
	/*class BRP_taloon_test: TaloonBag_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_taloon_test.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_taloon_test.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_taloon_test.paa"
		};
	};*/
	class TShirt_ColorBase: Clothing
	{
		//itemsCargoSize[]={5,4};
	};
	class BRP_tshirt_cross: TShirt_ColorBase
	{
		scope=2;
		displayName="Cross T-Shirt";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_tshirt_blackg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_tshirt_cross.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_tshirt_cross.paa"
		};
	};
	class BRP_tshirt_armygreen: TShirt_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_tshirt_armygreeng.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_tshirt_armygreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_tshirt_armygreen.paa"
		};
	};
	class BRP_tshirt_babyblue: TShirt_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_tshirt_babyblueg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_tshirt_babyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_tshirt_babyblue.paa"
		};
	};
	class BRP_tshirt_babypink: TShirt_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_tshirt_babypinkg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_tshirt_babypink.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_tshirt_babypink.paa"
		};
	};
	class BRP_tshirt_black: TShirt_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_tshirt_blackg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_tshirt_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_tshirt_black.paa"
		};
	};
	class BRP_tshirt_beige: TShirt_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_tshirt_beigeg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_tshirt_beige.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_tshirt_beige.paa"
		};
	};
	class BRP_tshirt_burgundy: TShirt_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_tshirt_burgundyg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_tshirt_burgundy.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_tshirt_burgundy.paa"
		};
	};
	class BRP_tshirt_candypink: TShirt_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_tshirt_candypinkg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_tshirt_candypink.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_tshirt_candypink.paa"
		};
	};
	class BRP_tshirt_cream: TShirt_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_tshirt_creamg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_tshirt_cream.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_tshirt_cream.paa"
		};
	};
	class BRP_tshirt_cyan: TShirt_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_tshirt_cyang.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_tshirt_cyan.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_tshirt_cyan.paa"
		};
	};
	class BRP_tshirt_darkbrown: TShirt_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_tshirt_darkbrowng.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_tshirt_darkbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_tshirt_darkbrown.paa"
		};
	};
	class BRP_tshirt_darkgrey: TShirt_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_tshirt_darkgreyg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_tshirt_darkgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_tshirt_darkgrey.paa"
		};
	};
	class BRP_tshirt_fuchsia: TShirt_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_tshirt_fuchsiag.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_tshirt_fuchsia.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_tshirt_fuchsia.paa"
		};
	};
	class BRP_tshirt_lavender: TShirt_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_tshirt_lavenderg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_tshirt_lavender.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_tshirt_lavender.paa"
		};
	};
	class BRP_tshirt_lightbrown: TShirt_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_tshirt_lightbrowng.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_tshirt_lightbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_tshirt_lightbrown.paa"
		};
	};
	class BRP_tshirt_lightgrey: TShirt_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_tshirt_lightgreyg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_tshirt_lightgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_tshirt_lightgrey.paa"
		};
	};
	class BRP_tshirt_navyblue: TShirt_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_tshirt_navyblueg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_tshirt_navyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_tshirt_navyblue.paa"
		};
	};
	class BRP_tshirt_olivegreen: TShirt_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_tshirt_olivegreeng.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_tshirt_olivegreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_tshirt_olivegreen.paa"
		};
	};
	class BRP_tshirt_orange: TShirt_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_tshirt_orangeg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_tshirt_orange.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_tshirt_orange.paa"
		};
	};
	class BRP_tshirt_plum: TShirt_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_tshirt_plumg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_tshirt_plum.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_tshirt_plum.paa"
		};
	};
	class BRP_tshirt_purple: TShirt_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_tshirt_purpleg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_tshirt_purple.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_tshirt_purple.paa"
		};
	};
	class BRP_tshirt_red: TShirt_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_tshirt_redg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_tshirt_red.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_tshirt_red.paa"
		};
	};
	class BRP_tshirt_royalblue: TShirt_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_tshirt_royalblueg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_tshirt_royalblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_tshirt_royalblue.paa"
		};
	};
	class BRP_tshirt_white: TShirt_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_tshirt_whiteg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_tshirt_white.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_tshirt_white.paa"
		};
	};
	class BRP_tshirt_yellow: TShirt_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_tshirt_yellowg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_tshirt_yellow.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_tshirt_yellow.paa"
		};
	};
	/*class BRP_tshirt_test: TShirt_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_tshirt_testg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_tshirt_test.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_tshirt_test.paa"
		};
	};*/
	class WorkingBoots_ColorBase;
	class BRP_workingboots_armygreen: WorkingBoots_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_workingboots_armygreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_workingboots_armygreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_workingboots_armygreen.paa"
		};
	};
	class BRP_workingboots_babyblue: WorkingBoots_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_workingboots_babyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_workingboots_babyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_workingboots_babyblue.paa"
		};
	};
	class BRP_workingboots_babypink: WorkingBoots_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_workingboots_babypink.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_workingboots_babypink.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_workingboots_babypink.paa"
		};
	};
	class BRP_workingboots_black: WorkingBoots_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_workingboots_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_workingboots_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_workingboots_black.paa"
		};
	};
	class BRP_workingboots_beige: WorkingBoots_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_workingboots_beige.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_workingboots_beige.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_workingboots_beige.paa"
		};
	};
	class BRP_workingboots_burgundy: WorkingBoots_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_workingboots_burgundy.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_workingboots_burgundy.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_workingboots_burgundy.paa"
		};
	};
	class BRP_workingboots_candypink: WorkingBoots_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_workingboots_candypink.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_workingboots_candypink.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_workingboots_candypink.paa"
		};
	};
	class BRP_workingboots_cream: WorkingBoots_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_workingboots_cream.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_workingboots_cream.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_workingboots_cream.paa"
		};
	};
	class BRP_workingboots_cyan: WorkingBoots_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_workingboots_cyan.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_workingboots_cyan.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_workingboots_cyan.paa"
		};
	};
	class BRP_workingboots_darkbrown: WorkingBoots_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_workingboots_darkbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_workingboots_darkbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_workingboots_darkbrown.paa"
		};
	};
	class BRP_workingboots_darkgrey: WorkingBoots_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_workingboots_darkgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_workingboots_darkgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_workingboots_darkgrey.paa"
		};
	};
	class BRP_workingboots_fuchsia: WorkingBoots_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_workingboots_fuchsia.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_workingboots_fuchsia.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_workingboots_fuchsia.paa"
		};
	};
	class BRP_workingboots_lavender: WorkingBoots_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_workingboots_lavender.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_workingboots_lavender.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_workingboots_lavender.paa"
		};
	};
	class BRP_workingboots_lightbrown: WorkingBoots_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_workingboots_lightbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_workingboots_lightbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_workingboots_lightbrown.paa"
		};
	};
	class BRP_workingboots_lightgrey: WorkingBoots_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_workingboots_lightgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_workingboots_lightgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_workingboots_lightgrey.paa"
		};
	};
	class BRP_workingboots_navyblue: WorkingBoots_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_workingboots_navyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_workingboots_navyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_workingboots_navyblue.paa"
		};
	};
	class BRP_workingboots_olivegreen: WorkingBoots_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_workingboots_olivegreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_workingboots_olivegreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_workingboots_olivegreen.paa"
		};
	};
	class BRP_workingboots_orange: WorkingBoots_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_workingboots_orange.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_workingboots_orange.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_workingboots_orange.paa"
		};
	};
	class BRP_workingboots_plum: WorkingBoots_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_workingboots_plum.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_workingboots_plum.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_workingboots_plum.paa"
		};
	};
	class BRP_workingboots_purple: WorkingBoots_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_workingboots_purple.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_workingboots_purple.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_workingboots_purple.paa"
		};
	};
	class BRP_workingboots_red: WorkingBoots_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_workingboots_red.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_workingboots_red.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_workingboots_red.paa"
		};
	};
	class BRP_workingboots_royalblue: WorkingBoots_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_workingboots_royalblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_workingboots_royalblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_workingboots_royalblue.paa"
		};
	};
	class BRP_workingboots_white: WorkingBoots_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_workingboots_white.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_workingboots_white.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_workingboots_white.paa"
		};
	};
	class BRP_workingboots_yellow: WorkingBoots_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_workingboots_yellow.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_workingboots_yellow.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_workingboots_yellow.paa"
		};
	};
	/*class BRP_workingboots_test: WorkingBoots_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_workingboots_test.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_workingboots_test.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_workingboots_test.paa"
		};
	};*/
	class Jeans_ColorBase;
	class BRP_jeans_jetblack: Jeans_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_jeans_jetblackg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_jeans_jetblackm.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_jeans_jetblackf.paa"
		};
	};
	class BRP_jeans_beige: Jeans_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_jeans_beigeg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_jeans_beigem.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_jeans_beigef.paa"
		};
	};
	class BRP_jeans_black: Jeans_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_jeans_blackg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_jeans_blackm.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_jeans_blackf.paa"
		};
	};
	class BRP_jeans_burgundy: Jeans_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_jeans_burgundyg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_jeans_burgundym.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_jeans_burgundyf.paa"
		};
	};
	class BRP_jeans_cream: Jeans_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_jeans_creamg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_jeans_creamm.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_jeans_creamf.paa"
		};
	};
	class BRP_jeans_darkbeige: Jeans_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_jeans_darkbeigeg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_jeans_darkbeigem.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_jeans_darkbeigef.paa"
		};
	};
	class BRP_jeans_darkblue: Jeans_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_jeans_darkblueg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_jeans_darkbluem.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_jeans_darkbluef.paa"
		};
	};
	class BRP_jeans_darkbrown: Jeans_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_jeans_darkbrowng.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_jeans_darkbrownm.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_jeans_darkbrownf.paa"
		};
	};
	class BRP_jeans_darkdarkblue: Jeans_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_jeans_darkdarkblueg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_jeans_darkdarkbluem.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_jeans_darkdarkbluef.paa"
		};
	};
	class BRP_jeans_darkgrey: Jeans_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_jeans_darkgreyg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_jeans_darkgreym.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_jeans_darkgreyf.paa"
		};
	};
	class BRP_jeans_lightblue: Jeans_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_jeans_lightblueg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_jeans_lightbluem.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_jeans_lightbluef.paa"
		};
	};
	class BRP_jeans_lightbrown: Jeans_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_jeans_lightbrowng.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_jeans_lightbrownm.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_jeans_lightbrownf.paa"
		};
	};
	class BRP_jeans_lightgrey: Jeans_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_jeans_lightgreyg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_jeans_lightgreym.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_jeans_lightgreyf.paa"
		};
	};
	class BRP_jeans_mediumblue: Jeans_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_jeans_mediumblueg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_jeans_mediumbluem.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_jeans_mediumbluef.paa"
		};
	};
	class BRP_jeans_armygreen: Jeans_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_jeans_armygreeng.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_jeans_armygreenm.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_jeans_armygreenf.paa"
		};
	};
	class BRP_jeans_white: Jeans_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_jeans_whiteg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_jeans_whitem.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_jeans_whitef.paa"
		};
	};
	/*class BRP_jeans_test: Jeans_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_jeans_testg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_jeans_testm.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_jeans_testf.paa"
		};
	};*/
	class HunterPants_ColorBase;
	class BRP_hunterpants_armygreen: HunterPants_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_hunterpants_armygreen.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_hunterpants_armygreen.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_hunterpants_armygreen.paa"
		};
	};
	class BRP_hunterpants_beige: HunterPants_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_hunterpants_beige.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_hunterpants_beige.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_hunterpants_beige.paa"
		};
	};
	class BRP_hunterpants_black: HunterPants_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_hunterpants_black.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_hunterpants_black.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_hunterpants_black.paa"
		};
	};
	class BRP_hunterpants_burgundy: HunterPants_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_hunterpants_burgundy.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_hunterpants_burgundy.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_hunterpants_burgundy.paa"
		};
	};
	class BRP_hunterpants_darkbrown: HunterPants_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_hunterpants_darkbrown.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_hunterpants_darkbrown.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_hunterpants_darkbrown.paa"
		};
	};
	class BRP_hunterpants_darkgrey: HunterPants_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_hunterpants_darkgrey.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_hunterpants_darkgrey.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_hunterpants_darkgrey.paa"
		};
	};
	class BRP_hunterpants_lightbrown: HunterPants_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_hunterpants_lightbrown.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_hunterpants_lightbrown.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_hunterpants_lightbrown.paa"
		};
	};
	class BRP_hunterpants_lightgrey: HunterPants_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_hunterpants_lightgrey.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_hunterpants_lightgrey.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_hunterpants_lightgrey.paa"
		};
	};
	class BRP_hunterpants_navyblue: HunterPants_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_hunterpants_navyblue.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_hunterpants_navyblue.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_hunterpants_navyblue.paa"
		};
	};
	/*class BRP_hunterpants_test: HunterPants_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\BastionMod\BastionClothing\Retextures\data\coda_hunterpants_test.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_hunterpants_test.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_hunterpants_test.paa"
		};
	};*/
	class BRP_admin_boots: Inventory_Base//Admin clothing for invisibility. Has weird one way texture that cannot be removed.
	{
		scope=2;
		displayName="CodaRP Admin Boots";
		itemSize[]={2,2};
		descriptionShort="For CodaRP Admin Use";
		model="\BastionMod\BastionClothing\Retextures\data\coda_admin.p3d";
		inventorySlot="Feet";
		itemInfo[]=
		{
			"Clothing",
			"Feet"
		};
		visibilityModifier=0.80000001;
		weight=1230;
		durability=0.5;
		repairableWithKits[]={5,3};
		repairCosts[]={30,25};
		absorbency=0.1;
		heatIsolation=0.5;
	};
	class BRP_admin_pants: HunterPants_ColorBase
	{
		scope=2;
		displayName="CodaRP Admin Pants";
		descriptionShort="For CodaRP Admin Use";
		visibilityModifier=0;
		hiddenSelectionsTextures[]=
		{
			"#(argb,8,8,3)color(1,1,1,0.3,ca)",
			"\BastionMod\BastionClothing\Retextures\data\coda_admin.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_admin.paa"
		};
	};
	class GorkaEJacket_ColorBase;
	class BRP_admin_top: GorkaEJacket_ColorBase
	{
		displayName="CodaRP Admin Top";
		descriptionShort="For CodaRP Admin Use";
		scope=2;
		visibilityModifier=0;
		hiddenSelectionsTextures[]=
		{
			"#(argb,8,8,3)color(1,1,1,0.3,ca)",
			"\BastionMod\BastionClothing\Retextures\data\coda_admin.paa",
			"\BastionMod\BastionClothing\Retextures\data\coda_admin.paa"
		};
	};
	class BRP_admin_gloves: Inventory_Base
	{
		scope=2;
		displayName="CodaRP Admin Gloves";
		itemSize[]={2,2};
		descriptionShort="For CodaRP Admin Use";
		model="\BastionMod\BastionClothing\Retextures\data\coda_admin.p3d";
		inventorySlot="Gloves";
		visibilityModifier=0;
	};
	class BRP_admin_head: Inventory_Base
	{
		scope=2;
		displayName="CodaRP Admin head";
		itemSize[]={2,2};
		descriptionShort="For CodaRP Admin Use";
		model="\BastionMod\BastionClothing\Retextures\data\coda_admin.p3d";
		inventorySlot="Head";
		simulation="head";
	};
//Item Size/Stack Changes
	class Blouse_ColorBase: Clothing
	{
		//itemSize[]={3,2};
		//itemsCargoSize[]={5,4};
	};
	class BRP_blouse_tropical: Blouse_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_blouse_tropical.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_blouse_tropical.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_blouse_tropical.paa"
		};
	};
	/*class Apple;
	class Pineapple: Apple//ExtraFarmingItems
	{
		itemSize[]={1,2};
	};
	class RedMango: Apple//ExtraFarmingItems
	{
		itemSize[]={1,1};
	};*/
	class ZmijovkaCap_ColorBase: Clothing
	{
		//itemSize[]={2,2};
	};
	class FlatCap_ColorBase: Clothing
	{
		//itemSize[]={2,2};
	};
	class Paper: Inventory_Base//Paper stack change to 10. Requires paper to be split to not consume whole stack when using in tandem with Notes mod
	{
		/*canBeSplit = 1;
		varQuantityInit = 1;
		varQuantityMin = 0;
		varQuantityMax = 10;
		varQuantityDestroyOnMin = 1;*/
	};
	class ItemCompass;
	class Compass: ItemCompass
	{
		//itemSize[]={1,1};
	};
	class ItemOptics;
	class Binoculars: ItemOptics
	{
		//itemSize[]={2,2};
	};
	class Rope: Inventory_Base
	{
		//itemSize[]={1,2};
	};
	class Headtorch_ColorBase: Switchable_Base
	{
		//itemSize[]={1,2};
	};
	class Rag: Inventory_Base
	{
		//itemSize[]={1,2};
	};
	class Roadflare: Inventory_Base
	{
		//itemSize[]={1,2};
	};
	class Chemlight_ColorBase: Inventory_Base
	{
		//itemSize[]={1,1};
	};
	class LargeGasCanister: Inventory_Base
	{
		//itemSize[]={2,3};
	};
	class MediumGasCanister: Inventory_Base
	{
		//itemSize[]={2,2};
	};
	class SmallGasCanister: Inventory_Base
	{
		//itemSize[]={2,1};
	};
	class Hook: Inventory_Base
	{
		//itemSize[]={1,1};
	};
	class BoneHook: Inventory_Base
	{
		//itemSize[]={1,1};
	};
	class Bait: Inventory_Base
	{
		//itemSize[]={1,1};
	};
	class BoneBait: Inventory_Base
	{
		//itemSize[]={1,1};
	};
	class Netting: Inventory_Base
	{
		//itemSize[]={1,2};
	};
	class PortableGasLamp: Inventory_Base
	{
		//itemSize[]={2,3};
	};
	class Tripod: Inventory_Base
	{
		//itemSize[]={1,5};
	};
	class BurlapSack: Inventory_Base
	{
		//itemSize[]={2,2};
	};
	class MetalWire: Inventory_Base
	{
		//itemSize[]={2,2};
	};
	class HandDrillKit: Inventory_Base
	{
		//itemSize[]={1,2};
	};
	class Defibrillator: Inventory_Base
	{
		//itemSize[]={2,2};
	};
	class OrienteeringCompass: Inventory_Base
	{
		//itemSize[]={1,1};
	};
	class Flashlight: Inventory_Base
	{
		//itemSize[]={2,1};
	};
	class Heatpack: Inventory_Base
	{
		//itemSize[]={1,2};
	};
	class Lockpick: Inventory_Base
	{
		//itemSize[]={1,1};
	};
	class Whetstone: Inventory_Base
	{
		//itemSize[]={1,1};
	};
	class LeatherSewingKit: Inventory_Base
	{
		//itemSize[]={2,2};
		//varQuantityDestroyOnMin=1;
	};
	class WeaponCleaningKit: Inventory_Base
	{
		//itemSize[]={2,2};
	};
	class Transmitter_Base;
	class PersonalRadio: Transmitter_Base
	{
		//itemSize[]={1,2};
		//weight=1200;
	};
	class BaseRadio: Transmitter_Base{};
	class Megaphone: Inventory_Base
	{
		//itemSize[]={3,4};
	};
	/*class MassTacticalBag: FirstAidKit//Requires MassMIO
	{
		//itemsize[]={5,3};
	};*/
	/*class BRP_handheldradio: PersonalRadio//Custom class for broken radio
	{
		scope=2;
		displayName="Handheld Radio";
	};
	class BRP_baseradio: BaseRadio//Custom class for broken radio
	{
		scope=2;
		displayName="Field Radio";
	};*/
	/*class MD_Item: Inventory_Base//Requires MD Items
	{
		//descriptionShort="Someone trained might be able to move this.";
	};
	class MD_WhiteFridge: MD_Item//Requires MD Items
	{
		scope=2;
		class Cargo
		{
			itemsCargoSize[]={5,5};
			openable=0;
			allowOwnedCargoManipulation=1;
		};
	};*/
	class BRP_gorka_top_black: GorkaEJacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_gorka_top_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_gorka_top_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_gorka_top_black.paa"
		};
	};
	class GorkaPants_ColorBase;
	class BRP_gorka_pants_black: GorkaPants_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_gorka_pants_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_gorka_pants_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_gorka_pants_black.paa"
		};
	};
	/*class MD_DoubleFridge: MD_Item
	{
		scope=2;
		class Cargo
		{
			itemsCargoSize[]={5,5};
			openable=0;
			allowOwnedCargoManipulation=1;
		};
	};
	class MD_TrashCan: MD_Item
	{
		scope=2;
		class Cargo
		{
			itemsCargoSize[]={10,5};
			openable=0;
			allowOwnedCargoManipulation=1;
		};
	};
	class FP4_HuntingTOP_Bag: TortillaBag
	{
		itemSize[]={5,7};
		itemsCargoSize[]={10,9};
	};
	class FP4_HuntingTOP_Bag_BLACK: FP4_HuntingTOP_Bag
	{
		itemSize[]={5,7};
		itemsCargoSize[]={10,9};
	};*/
	class Shovel: Inventory_Base 
	{
		//repairableWithKits[]={5};
	};
	class Wellies_ColorBase: Clothing
	{
		//repairableWithKits[]={3,5};
	};
	/*class CowSteakMeat: Edible_Base//Changes Cow Steaks to match other red meats
	{
		varQuantityInit=150;
		varQuantityMax=150;
		itemsize[]={1,2};
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[]={0,0,0};
					nutrition_properties[]={2.5,160,70,1,0,4};
					cooking_properties[]={0,0};
				};
				class Rotten
				{
					visual_properties[]={-1,-1,5};
					nutrition_properties[]=
					{
						2,
						120,
						35,
						1,
						0,
						"4 + 		  16"
					};
					cooking_properties[]={0,0};
				};
				class Baked
				{
					visual_properties[]={0,1,1};
					nutrition_properties[]={1.75,280,52.5,1,0};
					cooking_properties[]={70,45};
				};
				class Boiled
				{
					visual_properties[]={0,2,2};
					nutrition_properties[]={1.5,200,70,1,0};
					cooking_properties[]={70,55};
				};
				class Dried
				{
					visual_properties[]={0,3,3};
					nutrition_properties[]={0.75,160,7,1,0};
					cooking_properties[]={70,45,80};
				};
				class Burned
				{
					visual_properties[]={0,4,4};
					nutrition_properties[]={2,120,17.5,1,0,16};
					cooking_properties[]={100,30};
				};
			};
		};
	};*/
//Skinning Changes
// change count=# to desired variable to change steak output
	/*class Animal_BosTaurus: AnimalBase
	{
		class Skinning
		{
			class ObtainedSteaks
			{
				count=10;
			};
		};
	};
	class Animal_BosTaurusF: AnimalBase
	{
		class Skinning
		{
			class ObtainedSteaks
			{
				count=10;
			};
		};
	};
	class Animal_CervusElaphus: AnimalBase
	{
		class Skinning
		{
			class ObtainedSteaks
			{
				count=8;
			};
		};
	};
	class Animal_CervusElaphusF: AnimalBase
	{
		class Skinning
		{
			class ObtainedSteaks
			{
				count=8;
			};
		};
	};
	class Animal_CapraHircus: AnimalBase
	{
		class Skinning
		{
			class ObtainedSteaks
			{
				count=6;
			};
		};
	};
	class Animal_CapraHircusF: AnimalBase
	{
		class Skinning
		{
			class ObtainedSteaks
			{
				count=6;
			};
		};
	};
	class Animal_SusDomesticus: AnimalBase
	{
		class Skinning
		{
			class ObtainedSteaks
			{
				count=8;
			};
		};
	};
	class Animal_SusScrofa: AnimalBase
	{
		class Skinning
		{
			class ObtainedSteaks
			{
				count=8;
			};
		};
	};
	class Animal_CapreolusCapreolus: AnimalBase
	{
		class Skinning
		{
			class ObtainedSteaks
			{
				count=6;
			};
		};
	};
	class Animal_CapreolusCapreolusF: AnimalBase
	{
		class Skinning
		{
			class ObtainedSteaks
			{
				count=6;
			};
		};
	};
	class Animal_OvisAries: AnimalBase
	{
		class Skinning
		{
			class ObtainedSteaks
			{
				count=6;
			};
		};
	};
	class Animal_OvisAriesF: AnimalBase
	{
		class Skinning
		{
			class ObtainedSteaks
			{
				count=6;
			};
		};
	};
	class Animal_OvisOrientalis: AnimalBase
	{
		class Skinning
		{
			class ObtainedSteaks
			{
				count=6;
			};
		};
	};
	class Animal_CanisLupus: AnimalBase
	{
		class Skinning
		{
			class ObtainedSteaks
			{
				count=6;
			};
		};
	};
	class Animal_UrsusArctos: AnimalBase
	{
		class Skinning
		{
			class ObtainedPelt
			{
				count=1;//Reduced bear pelt #
			};
			class ObtainedSteaks
			{
				count=10;
			};
			class ObtainedHead
			{
				item="bearhead_mung";
				count=0;
				transferToolDamageCoef=1;
			};
		};
	};
	class SurvivorBase: Man//Reduced human steaks and eliminated fat drops from dead survivors
	{
		class Skinning
		{
			class Steaks
			{
				count=4;
			};
			class Lard
			{
				count=0;
			};
		};
	};
*/
	/*class MassSmershvestcomplete: SmershVest//Requires MassMIO
	{
		scope=2;
		descriptionShort="Mass's Smersh vest.";
		inventorySlot[]=
		{
			"Vest"
		};
		itemInfo[]=
		{
			"Clothing",
		};
	};
	class MassSmershvestWintercomplete: MassSmershvestcomplete
	{
		descriptionShort="Mass's winter smersh vest.";
	};
	class MassSmershvestWW2complete: MassSmershvestcomplete
	{
		descriptionShort="Mass's WW2 smersh vest.";
	};
	class MassSmershvestblackcomplete: MassSmershvestcomplete
	{
		descriptionShort="Mass's black smersh vest.";
	};*/
	class WoodenCrate: Container_Base
	{
		itemBehaviour=2;//Allows Crate to be 'placed'
	};
	class SeaChest: Container_Base//Allows SeaChest to be 'placed'
	{
		itemBehaviour=2;
	};

	class MotoHelmet_ColorBase: clothing
	{
		soundVoiceType="none";
		soundVoicePriority=5;
	};
};
class CfgNonAIVehicles
{
	class StaticObject;
};
