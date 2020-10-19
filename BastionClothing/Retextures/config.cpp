class CfgPatches
{
	class BastionRetextures
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
	};
};

class cfgVehicles
{
	class Shirt_ColorBase;
	class HuntingBag;
	class MiniDress_ColorBase;
	class BalaclavaMask_ColorBase;
	class Canvas_Backpack_Base;
	class AthleticShoes_ColorBase;
	class BandanaHead_ColorBase;
	class HunterPants_ColorBase;
	class BandanaMask_ColorBase;
	class TacticalShirt_ColorBase;
	class Shemagh_ColorBase;
	class TaloonBag_ColorBase;
	class Shemagh_Bandit_ColorBase;
	class GorkaEJacket_ColorBase;
	class GorkaPants_ColorBase;
	class Shemagh_Facemask_ColorBase;
	class Shemagh_Scarf_ColorBase;
	class BDUPants;
	class RidersJacket_ColorBase;
	class Mich2001Helmet;
	class MilitaryBeret_Red;
	class Sneakers_ColorBase;
	class MedicalScrubsShirt_ColorBase;
	class SurgicalMask;
	class Sweater_ColorBase;
	class ParamedicJacket_ColorBase;
	class TTsKOJacket_ColorBase;
	class TShirt_ColorBase;
	class HuntingJacket_ColorBase;
	class BeanieHat_ColorBase;
	class WindstridePoncho;
	class Ballerinas_ColorBase;
	class MilitaryBeret_ColorBase;
	class Blouse_ColorBase;
	class HikingJacket_ColorBase;
	class BaseballCap_ColorBase;
	class PoliceVest;
	class High_Knee_Sneakers;
	class SmershBag;
	class AssaultBag_ColorBase;
	class M65Jacket_ColorBase;
	class TortillaBag;
	class ParamedicPants_ColorBase;
	class PrisonUniformPants;
	class CargoPants_Colorbase;
	class Hoodie_ColorBase;
	class SmershVest;
	class TTSKOPants;
	class TacticalShirt_Grey;
	class Layered_Shirt_Base;
	class RadarCap_ColorBase;
	class LeatherSack_Natural;
	class LeatherHat_ColorBase;
	class Jeans_ColorBase;
	class WorkingBoots_ColorBase;
	class LeatherStorageVest_ColorBase;
	class LeatherJacket_ColorBase;
	class Military_Sweater;
	class LeatherGloves_ColorBase;
	class LeatherPants_ColorBase;
	class LeatherShoes_ColorBase;
//---Head
    class Inventory_base;
    class BRP_Head_admin: Inventory_Base
    {
        displayName="Head - Admin";
        scope=2;
        itemSize[]={2,2};
        descriptionShort="Admin Clothing; if you're not an admin be prepared to get whipped... HARD. | Model and config from Invisible Clothing Mod";
        model="BastionMod\BastionClothing\Retextures\data\invisible.p3d";
        inventorySlot="Head";
        simulation="head";
    };

//---NBC Hood
	class NBCHoodBase;

	class BRP_NBCHood: NBCHoodBase
	{
		displayName = "ISF NBC Hood";
		scope = 2;
		visibilityModifier = 0.7;
		hiddenSelectionsTextures[] = {"BastionMod\BastionClothing\Retextures\data\pathfinder_nbc_hood.paa","BastionMod\BastionClothing\Retextures\data\pathfinder_nbc_hood.paa","BastionMod\BastionClothing\Retextures\data\pathfinder_nbc_hood.paa"};
	};
//---Baseball Cap
	class BRP_ISF_BaseballCap: BaseballCap_ColorBase
	{
		scope=2;
		visibilityModifier=0.94999999;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\baseballcap_isf_co.paa",
			"BastionMod\BastionClothing\Retextures\data\baseballcap_isf_co.paa",
			"BastionMod\BastionClothing\Retextures\data\baseballcap_isf_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"BastionMod\BastionClothing\Retextures\data\baseballcap_isf.rvmat",
			"BastionMod\BastionClothing\Retextures\data\baseballcap_isf.rvmat",
			"BastionMod\BastionClothing\Retextures\data\baseballcap_isf.rvmat"
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
							1.01,

							{
								"DZ\characters\headgear\data\BaseballCapII.rvmat"
							}
						},

						{
							0.69999999,

							{
								"BastionMod\BastionClothing\Retextures\data\baseballcap_isf.rvmat"
							}
						},

						{
							0.5,

							{
								"BastionMod\BastionClothing\Retextures\data\baseballcap_isf_damage.rvmat"
							}
						},

						{
							0.30000001,

							{
								"BastionMod\BastionClothing\Retextures\data\baseballcap_isf_damage.rvmat"
							}
						},

						{
							0.0,

							{
								"BastionMod\BastionClothing\Retextures\data\baseballcap_isf_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};

//---Burlap Sack Cover
	class BRP_BurlapSackCoverMask: BalaclavaMask_ColorBase
	{
		scope = 2;
		displayName = "Burlap Mask";
		descriptionShort = "Improvised Mask made from cutting rough holes into an old burlap sack.";
		model = "\dz\characters\headgear\Head_sack_g.p3d";
		inventorySlot[] = { "Headgear" };
		simulation = "clothing";
		vehicleClass = "Clothing";
		itemInfo[] = {"Clothing","Headgear"};
		rotationFlags = 1;
		weight = 510;
		itemSize[] = {2,2};
		absorbency = 1;
		heatIsolation = 0.7;
		hiddenSelections[] = {"camoGround","camoMale","camoFemale"};
		hiddenSelectionsTextures[] = {"BastionMod\BastionClothing\Retextures\data\head_sack_co.paa","BastionMod\BastionClothing\Retextures\data\head_sack_co.paa","BastionMod\BastionClothing\Retextures\data\head_sack_co.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1,{"DZ\characters\headgear\data\Head_Sack.rvmat"}},{0.7,{"DZ\characters\headgear\data\Head_Sack.rvmat"}},{0.5,{"DZ\characters\headgear\data\Head_Sack_damage.rvmat"}},{0.3,{"DZ\characters\headgear\data\Head_Sack_damage.rvmat"}},{0,{"DZ\characters\headgear\data\Head_Sack_destruct.rvmat"}}};
				};
			};
		};
		class ClothingTypes
		{
			male = "\DZ\characters\headgear\Head_sack.p3d";
			female = "\DZ\characters\headgear\Head_sack.p3d";
		};
		class Protection
		{
			biological = 0.25;
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "Shirt_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "Shirt_drop_SoundSet";
					id = 898;
				};
			};
		};
		soundVoiceType = "none";
		soundVoicePriority = 10;
	};

//---Military Berets
	class BRP_ISF_OfficerBeret: MilitaryBeret_ColorBase
	{
		scope=2;
		displayName = "NCC Military Beret";
        descriptionShort = "Military beret for high-ranking NCC officials.";
		model="\DZ\characters\headgear\MilitaryBeret_g.p3d";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\militaryberet_isf_co.paa",
			"BastionMod\BastionClothing\Retextures\data\militaryberet_isf_co.paa",
			"BastionMod\BastionClothing\Retextures\data\militaryberet_isf_co.paa"
		};
		class ClothingTypes
		{
			male="\DZ\characters\headgear\MilitaryBeret_m.p3d";
			female="\DZ\characters\headgear\MilitaryBeret_f.p3d";
		};
	};
	class BRP_ISF_Blue_OfficerBeret: MilitaryBeret_ColorBase
	{
		scope=2;
		displayName = "NCC Military Beret";
        descriptionShort = "Military beret for high-ranking NCC officials.";
		model="\DZ\characters\headgear\MilitaryBeret_g.p3d";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\militaryberet_isf_blue_co.paa",
			"BastionMod\BastionClothing\Retextures\data\militaryberet_isf_blue_co.paa",
			"BastionMod\BastionClothing\Retextures\data\militaryberet_isf_blue_co.paa"
		};
		class ClothingTypes
		{
			male="\DZ\characters\headgear\MilitaryBeret_m.p3d";
			female="\DZ\characters\headgear\MilitaryBeret_f.p3d";
		};
	};
	class BRP_ISF_Black_OfficerBeret: MilitaryBeret_ColorBase
	{
		scope=2;
		displayName = "NCC Military Beret";
        descriptionShort = "Military beret for high-ranking NCC officials.";
		model="\DZ\characters\headgear\MilitaryBeret_g.p3d";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\militaryberet_isf_black_co.paa",
			"BastionMod\BastionClothing\Retextures\data\militaryberet_isf_black_co.paa",
			"BastionMod\BastionClothing\Retextures\data\militaryberet_isf_black_co.paa"
		};
		class ClothingTypes
		{
			male="\DZ\characters\headgear\MilitaryBeret_m.p3d";
			female="\DZ\characters\headgear\MilitaryBeret_f.p3d";
		};
	};
	class BRP_ISF_Purple_OfficerBeret: MilitaryBeret_ColorBase
	{
		scope=2;
		displayName = "NCC Military Beret";
        descriptionShort = "Military beret for high-ranking NCC officials.";
		model="\DZ\characters\headgear\MilitaryBeret_g.p3d";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\militaryberet_isf_purple_co.paa",
			"BastionMod\BastionClothing\Retextures\data\militaryberet_isf_purple_co.paa",
			"BastionMod\BastionClothing\Retextures\data\militaryberet_isf_purple_co.paa"
		};
		class ClothingTypes
		{
			male="\DZ\characters\headgear\MilitaryBeret_m.p3d";
			female="\DZ\characters\headgear\MilitaryBeret_f.p3d";
		};
	};
	
//---Tactical Helmet
	class BRP_ISF_DART_Helmet: Mich2001Helmet
	{
		scope = 2;
		displayName = "ISF Helmet";
		descriptionShort = "";
		hiddenSelectionsTextures[] = 
		{
			"BastionMod\BastionClothing\Retextures\data\tacticalhelm_dart.paa",
			"BastionMod\BastionClothing\Retextures\data\tacticalhelm_dart.paa",
			"BastionMod\BastionClothing\Retextures\data\tacticalhelm_dart.paa"
		};
	};

//---Surgical Mask
	class BRP_SurgicalMask_Black: SurgicalMask
	{
		scope = 2;
		hiddenSelectionsTextures[] = 
		{
			"BastionMod\BastionClothing\Retextures\data\surgical_mask_blackground.paa",
			"BastionMod\BastionClothing\Retextures\data\surgical_maskblack_co.paa",
			"BastionMod\BastionClothing\Retextures\data\surgical_maskblack_co.paa"
		};
	};

//---Police Vest
	class BRP_ISF_PoliceVest: PoliceVest
	{
		scope=2;
		displayName = "ISF Light Vest";
		descriptionShort = "Standard issue ISF vest. Lightly armored.";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\policevest_isf_co.paa",
			"BastionMod\BastionClothing\Retextures\data\policevest_isf_co.paa",
			"BastionMod\BastionClothing\Retextures\data\policevest_isf_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"BastionMod\BastionClothing\Retextures\data\policevest_isf.rvmat",
			"BastionMod\BastionClothing\Retextures\data\policevest_isf.rvmat",
			"BastionMod\BastionClothing\Retextures\data\policevest_isf.rvmat"
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
							1.01,
							{
								"DZ\characters\vests\Data\PoliceVest.rvmat"
							}
						},
						{
							0.69999999,
							{
								"BastionMod\BastionClothing\Retextures\data\policevest_isf.rvmat"
							}
						},
						{
							0.5,
							{
								"BastionMod\BastionClothing\Retextures\data\policevest_isf_damage.rvmat"
							}
						},
						{
							0.30000001,
							{
								"BastionMod\BastionClothing\Retextures\data\policevest_isf_damage.rvmat"
							}
						},
						{
							0.0,
							{
								"BastionMod\BastionClothing\Retextures\data\policevest_isf_destruct.rvmat"
							}
						}
					};
				};
	            class GlobalArmor
                {
                    class Projectile
                    {
                        class Health
                        {
                            damage=0.5;
                        };
                        class Blood
                        {
                            damage=0;
                        };
                        class Shock
                        {
                            damage=0.4;
                        };
                    };
                    class Melee
                    {
                        class Health
                        {
                            damage=0.60;
                        };
                        class Blood
                        {
                            damage=0;
                        };
                        class Shock
                        {
                            damage=0.60;
                        };
                    };
                    class Infected
                    {
                        class Health
                        {
                            damage=0.60;
                        };
                        class Blood
                        {
                            damage=0;
                        };
                        class Shock
                        {
                            damage=0.60;
                        };
                    };
                    class FragGrenade
                    {
                        class Health
                        {
                            damage=0.5;
                        };
                        class Blood
                        {
                            damage=0;
                        };
                        class Shock
                        {
                            damage=0.4;
                        };
                    };
                };
			};
		};
	};

//---Smersh Rig
	class BRP_SmershRig_isf: SmershVest
	{
		displayName="Smersh Rig - ISF";
		descriptionShort="";
		model = "\DZ\characters\vests\smersh_g.p3d";
		inventorySlot = "Hips";
		scope=2;
		visibilityModifier = 0.6;
		hiddenSelections[] = 
		{
			"camoGround",
            "camoMale",
            "camoFemale"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\BRP_SmershRig_isf_co.paa",
			"BastionMod\BastionClothing\Retextures\data\BRP_SmershRig_isf_co.paa",
			"BastionMod\BastionClothing\Retextures\data\BRP_SmershRig_isf_co.paa"
		};
		class ClothingTypes
        {
            male="\DZ\characters\vests\smersh_m.p3d";
            female="\DZ\characters\vests\smersh_f.p3d";
        };
	};
	
	class BRP_SmershRig_isf_black: SmershVest
	{
		displayName="Smersh Rig - ISF";
		descriptionShort="";
		model = "\DZ\characters\vests\smersh_g.p3d";
		inventorySlot = "Hips";
		scope=2;
		visibilityModifier = 0.6;
		hiddenSelections[] = 
		{
			"camoGround",
            "camoMale",
            "camoFemale"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\BRP_SmershRig_isf_black_co.paa",
			"BastionMod\BastionClothing\Retextures\data\BRP_SmershRig_isf_black_co.paa",
			"BastionMod\BastionClothing\Retextures\data\BRP_SmershRig_isf_black_co.paa"
		};
		class ClothingTypes
        {
            male="\DZ\characters\vests\smersh_m.p3d";
            female="\DZ\characters\vests\smersh_f.p3d";
        };
	};
	
	
//---Smersh Bag
	class BRP_SmershBag_isf: SmershBag
	{
		displayName="Smersh Bag - ISF";
		descriptionShort="";
		scope=2;
		visibilityModifier = 0.6;
		hiddenSelections[] = 
		{
			"camoGround",
            "camoMale",
            "camoFemale"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\BRP_SmershRig_isf_co.paa",
			"BastionMod\BastionClothing\Retextures\data\BRP_SmershRig_isf_co.paa",
			"BastionMod\BastionClothing\Retextures\data\BRP_SmershRig_isf_co.paa"
        };
	};
	
	class BRP_SmershBag_isf_black: SmershBag
	{
		displayName="Smersh Bag - ISF";
		descriptionShort="";
		scope=2;
		visibilityModifier = 0.6;
		hiddenSelections[] = 
		{
			"camoGround",
            "camoMale",
            "camoFemale"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\BRP_SmershRig_isf_black_co.paa",
			"BastionMod\BastionClothing\Retextures\data\BRP_SmershRig_isf_black_co.paa",
			"BastionMod\BastionClothing\Retextures\data\BRP_SmershRig_isf_black_co.paa"
        };
	};

//---Hoodie
	class BRP_Hoodie_black: Hoodie_ColorBase
	{
		displayName="Hoodie - Black";
		descriptionShort="";
		scope=2;
		visibilityModifier = 0.6;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\BRP_Hoodie_black_m.paa",
			"BastionMod\BastionClothing\Retextures\data\BRP_Hoodie_black_m.paa",
			"BastionMod\BastionClothing\Retextures\data\BRP_Hoodie_black_f.paa",
			"BastionMod\BastionClothing\Retextures\data\BRP_Hoodie_black_f.paa"
		};
	};

//---NBC Jacket
    class NBCJacketBase;
    class BRP_Jacket_admin: NBCJacketBase
    {
        displayName="Jacket - Admin";
        descriptionShort="Admin Clothing; if you're not an admin be prepared to get whipped... HARD.";
        scope=2;
        itemSize[]={2,2};
        itemsCargoSize[] = {10,50};
        hiddenSelectionsTextures[]=
        {
//---There is nothing for a reason
        };
    };
	class BRP_NBCJacket: NBCJacketBase
	{
		displayName = "ISF NBC Jacket";
		scope = 2;
		visibilityModifier = 0.7;
		hiddenSelectionsTextures[] = {"BastionMod\BastionClothing\Retextures\data\pathfinder_nbc_jacket.paa","BastionMod\BastionClothing\Retextures\data\pathfinder_nbc_jacket.paa","BastionMod\BastionClothing\Retextures\data\pathfinder_nbc_jacket.paa"};
	};

//---Paramedic Jacket
	class BRP_ParamedicJacket_Light_Blue: ParamedicJacket_ColorBase
	{
		scope=2;
		visibilityModifier=0.5;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\paramedic_jacket_light-blue-ground.paa",
			"BastionMod\BastionClothing\Retextures\data\paramedic_jacket_lightblue.paa",
			"BastionMod\BastionClothing\Retextures\data\paramedic_jacket_lightblue.paa"
		};
	};
	class BRP_ParamedicJacket_Light_Green: ParamedicJacket_ColorBase
	{
		scope=2;
		visibilityModifier=0.5;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\paramedic_jacket_g_brightgreenground.paa",
			"BastionMod\BastionClothing\Retextures\data\paramedic_jacket_brightgreen.paa",
			"BastionMod\BastionClothing\Retextures\data\paramedic_jacket_brightgreen.paa"
		};
	};
	class BRP_ParamedicJacket_Light_Red: ParamedicJacket_ColorBase
	{
		scope=2;
		visibilityModifier=0.5;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\paramedic_jacket_g_red-ground.paa",
			"BastionMod\BastionClothing\Retextures\data\paramedic_jacket_red.paa",
			"BastionMod\BastionClothing\Retextures\data\paramedic_jacket_red.paa"
		};
	};

//---Tactical Shirt
	class BRP_ISF_Tacshirt: TacticalShirt_ColorBase
	{
		displayName = "ISF Tactical Shirt";
		descriptionShort = "";
		scope = 2;
		hiddenSelectionsTextures[] = 
		{
			"BastionMod\BastionClothing\Retextures\data\ncc_tacshirt.paa",
			"BastionMod\BastionClothing\Retextures\data\ncc_tacshirt.paa",
			"BastionMod\BastionClothing\Retextures\data\ncc_tacshirt.paa"
		};
	};
	class BRP_ISF_DART_Tacshirt: TacticalShirt_ColorBase
	{
		displayName = "ISF Tactical Shirt";
		descriptionShort = "";
		scope = 2;
		hiddenSelectionsTextures[] = 
		{
			"BastionMod\BastionClothing\Retextures\data\isff_tacshirt.paa",
			"BastionMod\BastionClothing\Retextures\data\isff_tacshirt.paa",
			"BastionMod\BastionClothing\Retextures\data\isff_tacshirt.paa"
		};
	};
	class BRP_TacticalShirt_DART: TacticalShirt_Grey
    {
        displayName = "DART Tactical Shirt";
        scope = 2;
        visibilityModifier = 0.7;
        hiddenSelectionsTextures[] = {"BastionMod\BastionClothing\Retextures\data\dart_tacshirt.paa","BastionMod\BastionClothing\Retextures\data\dart_tacshirt.paa","BastionMod\BastionClothing\Retextures\data\dart_tacshirt.paa"};
    };

//---TTSKO Jacket
	class BRP_TTsKOJacket_Civilian: TTsKOJacket_ColorBase
	{
		scope=2;
		displayName = "NCC Citizen's Jacket";
        descriptionShort = "Mass-produced, one size fits most, all-purpose clothing for citizens of the NCC. This version is colored in navy blue.";
		visibilityModifier=0.5;
		itemSize[]={3,3};
		itemsCargoSize[]={5,4};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\ttsko_jacket_brpcivilian_co.paa",
			"BastionMod\BastionClothing\Retextures\data\ttsko_jacket_brpcivilian_co.paa",
			"BastionMod\BastionClothing\Retextures\data\ttsko_jacket_brpcivilian_co.paa"
		};
	};
	class BRP_TTsKOJacket_Civilian_White: TTsKOJacket_ColorBase
	{
		scope=2;
		displayName = "NCC Citizen's Jacket";
        descriptionShort = "Mass-produced, one size fits most, all-purpose clothing for citizens of the NCC. This version is colored in white.";
		visibilityModifier=0.5;
		itemSize[]={3,3};
		itemsCargoSize[]={5,4};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\ttsko_jacket_brpcivilian_white_co.paa",
			"BastionMod\BastionClothing\Retextures\data\ttsko_jacket_brpcivilian_white_co.paa",
			"BastionMod\BastionClothing\Retextures\data\ttsko_jacket_brpcivilian_white_co.paa"
		};
	};
	class BRP_TTsKOJacket_Civilian_Brown: TTsKOJacket_ColorBase
	{
		scope=2;
		displayName = "NCC Citizen's Jacket";
        descriptionShort = "Mass-produced, one size fits most, all-purpose clothing for citizens of the NCC. This version is colored in brown.";
		visibilityModifier=0.5;
		itemSize[]={3,3};
		itemsCargoSize[]={5,4};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\ttsko_jacket_brpcivilian_brown_co.paa",
			"BastionMod\BastionClothing\Retextures\data\ttsko_jacket_brpcivilian_brown_co.paa",
			"BastionMod\BastionClothing\Retextures\data\ttsko_jacket_brpcivilian_brown_co.paa"
		};
	};
	class BRP_TTsKOJacket_Civilian_Olive: TTsKOJacket_ColorBase
	{
		scope=2;
		displayName = "NCC Citizen's Jacket";
        descriptionShort = "Mass-produced, one size fits most, all-purpose clothing for citizens of the NCC. This version is colored in olive.";
		visibilityModifier=0.5;
		itemSize[]={3,3};
		itemsCargoSize[]={5,4};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\ttsko_jacket_brpcivilian_olive_co.paa",
			"BastionMod\BastionClothing\Retextures\data\ttsko_jacket_brpcivilian_olive_co.paa",
			"BastionMod\BastionClothing\Retextures\data\ttsko_jacket_brpcivilian_olive_co.paa"
		};
	};
	class BRP_TTsKOJacket_Civilian_Red: TTsKOJacket_ColorBase
	{
		scope=2;
		displayName = "NCC Citizen's Jacket";
        descriptionShort = "Mass-produced, one size fits most, all-purpose clothing for citizens of the NCC. This version is colored in red.";
		visibilityModifier=0.5;
		itemSize[]={3,3};
		itemsCargoSize[]={5,4};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\ttsko_jacket_brpcivilian_red_co.paa",
			"BastionMod\BastionClothing\Retextures\data\ttsko_jacket_brpcivilian_red_co.paa",
			"BastionMod\BastionClothing\Retextures\data\ttsko_jacket_brpcivilian_red_co.paa"
		};
	};

//---Assault Backpack
	class BRP_AssaultBackpack_isf: AssaultBag_ColorBase
	{
		displayName="Assault Backpack - ISF";
		descriptionShort="";
		scope=2;
		visibilityModifier = 0.6;
		hiddenSelectionsTextures[] = 
		{
			"BastionMod\BastionClothing\Retextures\data\BRP_AssaultBackpack_isf_co.paa",
			"BastionMod\BastionClothing\Retextures\data\BRP_AssaultBackpack_isf_co.paa",
			"BastionMod\BastionClothing\Retextures\data\BRP_AssaultBackpack_isf_co.paa"
		};
	};

//---Combat Backpack
	class BRP_CombatBackpack_isf: TortillaBag
	{
		displayName="Combat Backpack - ISF";
		descriptionShort="";
		scope=2;
		visibilityModifier = 0.6;
		hiddenSelections[] = 
		{
			"camoGround",
			"camoMale",
			"camoFemale"
		};
		hiddenSelectionsTextures[] = 
		{
			"BastionMod\BastionClothing\Retextures\data\BRP_CombatBackpack_isf_co.paa",
			"BastionMod\BastionClothing\Retextures\data\BRP_CombatBackpack_isf_co.paa",
			"BastionMod\BastionClothing\Retextures\data\BRP_CombatBackpack_isf_co.paa"
		};
	};

//---NBC Gloves
    class NBCGloves_ColorBase;
    class BRP_Gloves_admin: NBCGloves_ColorBase
    {
        displayName="Gloves - Admin";
        descriptionShort="Admin Clothing; if you're not an admin be prepared to get whipped... HARD.";
        scope=2;
        itemSize[]={2,2};
        hiddenSelectionsTextures[]=
        {
//---There is nothing here for a reason
        };
    };
	class BRP_NBCGloves: NBCGloves_Colorbase
	{
		displayName = "ISF NBC Gloves";
		scope = 2;
		visibilityModifier = 0.7;
		hiddenSelectionsTextures[] = {"BastionMod\BastionClothing\Retextures\data\pathfinder_nbc_gloves.paa","BastionMod\BastionClothing\Retextures\data\pathfinder_nbc_gloves.paa","BastionMod\BastionClothing\Retextures\data\pathfinder_nbc_gloves.paa"};
	};

//---BDU Pants
	class BRP_ISF_Pants: BDUPants
	{
		scope = 2;
		displayName = "ISF Pants";
		descriptionShort = "";
		hiddenSelectionsTextures[] = {"BastionMod\BastionClothing\Retextures\data\ncc_pants.paa","BastionMod\BastionClothing\Retextures\data\ncc_pants.paa","BastionMod\BastionClothing\Retextures\data\ncc_pants.paa"};
	};
	class BRP_ISF_DART_Pants: BDUPants
	{
		scope = 2;
		displayName = "ISF Pants";
		descriptionShort = "";
		hiddenSelectionsTextures[] = {"BastionMod\BastionClothing\Retextures\data\isff_pants.paa","BastionMod\BastionClothing\Retextures\data\isff_pants.paa","BastionMod\BastionClothing\Retextures\data\isff_pants.paa"};
	};

//---NBC Pants
    class NBCPantsBase;
    class BRP_Pants_admin: NBCPantsBase
    {
        displayName="Pants - Admin";
        descriptionShort="Admin Clothing; if you're not an admin be prepared to get whipped... HARD.";
        scope=2;
        itemSize[]={2,2};
        itemsCargoSize[] = {0,0};
        hiddenSelectionsTextures[] = 
        {
//---There is nothing here for a reason
        };
    };
	class BRP_NBCPants: NBCPantsBase
	{
		displayName = "ISF NBC Pants";
		scope = 2;
		visibilityModifier = 0.7;
		hiddenSelectionsTextures[] = {"BastionMod\BastionClothing\Retextures\data\pathfinder_nbc_pants.paa","BastionMod\BastionClothing\Retextures\data\pathfinder_nbc_pants.paa","BastionMod\BastionClothing\Retextures\data\pathfinder_nbc_pants.paa"};
	};

//---TTSKO Pants	
    class BRP_TTSKOPants_DART: TTSKOPants
    {    
        displayName = "DART Tactical Pants";
        scope = 2;
        visibilityModifier = 0.7;
        hiddenSelectionsTextures[] = {"BastionMod\BastionClothing\Retextures\data\dart_ttsko.paa","BastionMod\BastionClothing\Retextures\data\dart_ttsko.paa","BastionMod\BastionClothing\Retextures\data\dart_ttsko.paa"};
    };

//---Paramedic Pants
	class BRP_ParamedicPants_Light_Blue: ParamedicPants_ColorBase
	{
		scope=2;
		visibilityModifier=0.5;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\paramedic_pants_lightblue.paa",
			"BastionMod\BastionClothing\Retextures\data\paramedic_pants_lightblue.paa",
			"BastionMod\BastionClothing\Retextures\data\paramedic_pants_lightblue.paa"
		};
	};
	class BRP_ParamedicPants_Light_Green: ParamedicPants_ColorBase
	{
		scope=2;
		visibilityModifier=0.5;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\paramedic_pants_lightgreen.paa",
			"BastionMod\BastionClothing\Retextures\data\paramedic_pants_lightgreen.paa",
			"BastionMod\BastionClothing\Retextures\data\paramedic_pants_lightgreen.paa"
		};
	};
	class BRP_ParamedicPants_Light_Red: ParamedicPants_ColorBase
	{
		scope=2;
		visibilityModifier=0.5;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\paramedic_pants_red.paa",
			"BastionMod\BastionClothing\Retextures\data\paramedic_pants_red.paa",
			"BastionMod\BastionClothing\Retextures\data\paramedic_pants_red.paa"
		};
	};

//---Prison Pants
	class BRP_PrisonPants_NCC: PrisonUniformPants
	{
		scope=2;
		displayName = "NCC Prison Pants";
        descriptionShort = "Factory produced clothing for prisoners being held by NCC. This version is colored in navy blue.";
		visibilityModifier=0.5;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\BRP_PrisonPants_ncc.paa",
			"BastionMod\BastionClothing\Retextures\data\BRP_PrisonPants_ncc.paa",
			"BastionMod\BastionClothing\Retextures\data\BRP_PrisonPants_ncc.paa"
		};
	};

//---NBC Boots
	class NBCBootsBase;
    class BRP_Boots_admin: NBCBootsBase
    {
        displayName="Boots - Admin";
        descriptionShort="Admin Clothing; if you're not an admin be prepared to get whipped... HARD.";
        scope=2;
        itemSize[]={2,2};
        hiddenSelectionsTextures[]=
        {
//---There is nothing for a reason
        };
    };
	class BRP_NBCBoots: NBCBootsBase
	{
		displayName = "ISF NBC Boots";
		scope = 2;
		visibilityModifier = 0.7;
		hiddenSelectionsTextures[] = {"BastionMod\BastionClothing\Retextures\data\pathfinder_nbc_boots.paa","BastionMod\BastionClothing\Retextures\data\pathfinder_nbc_boots.paa","BastionMod\BastionClothing\Retextures\data\pathfinder_nbc_boots.paa"};
	};
	
	
	
//--- CODA IMPORT
	class BRP_cargopants_armygreen: CargoPants_Colorbase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_cargopants_armygreeng.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_cargopants_armygreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_cargopants_armygreen.paa"
		};
	};
	class BRP_cargopants_beige: CargoPants_Colorbase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_cargopants_beigeg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_cargopants_beige.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_cargopants_beige.paa"
		};
	};
	class BRP_cargopants_black: CargoPants_Colorbase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_cargopants_blackg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_cargopants_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_cargopants_black.paa"
		};
	};
	class BRP_cargopants_burgundy: CargoPants_Colorbase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_cargopants_burgundyg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_cargopants_burgundy.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_cargopants_burgundy.paa"
		};
	};
	class BRP_cargopants_darkbrown: CargoPants_Colorbase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_cargopants_darkbrowng.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_cargopants_darkbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_cargopants_darkbrown.paa"
		};
	};
	class BRP_cargopants_lightbrown: CargoPants_Colorbase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_cargopants_lightbrowng.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_cargopants_lightbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_cargopants_lightbrown.paa"
		};
	};
	class BRP_cargopants_lightgrey: CargoPants_Colorbase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_cargopants_lightgreyg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_cargopants_lightgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_cargopants_lightgrey.paa"
		};
	};
	class BRP_cargopants_navyblue: CargoPants_Colorbase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_cargopants_navyblueg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_cargopants_navyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_cargopants_navyblue.paa"
		};
	};
	class BRP_cargopants_olivegreen: CargoPants_Colorbase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_cargopants_olivegreeng.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_cargopants_olivegreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_cargopants_olivegreen.paa"
		};
	};
	class BRP_cargopants_white: CargoPants_Colorbase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_cargopants_whiteg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_cargopants_white.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_cargopants_white.paa"
		};
	};
	class BRP_athleticshoes_armygreen: AthleticShoes_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_athleticshoes_armygreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_athleticshoes_armygreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_athleticshoes_armygreen.paa"
		};
	};
	class BRP_athleticshoes_babyblue: AthleticShoes_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_athleticshoes_babyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_athleticshoes_babyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_athleticshoes_babyblue.paa"
		};
	};
	class BRP_athleticshoes_babypink: AthleticShoes_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_athleticshoes_babypink.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_athleticshoes_babypink.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_athleticshoes_babypink.paa"
		};
	};
	class BRP_athleticshoes_beige: AthleticShoes_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_athleticshoes_beige.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_athleticshoes_beige.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_athleticshoes_beige.paa"
		};
	};
	class BRP_athleticshoes_black: AthleticShoes_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_athleticshoes_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_athleticshoes_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_athleticshoes_black.paa"
		};
	};
	class BRP_athleticshoes_black2: AthleticShoes_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_athleticshoes_black2.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_athleticshoes_black2.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_athleticshoes_black2.paa"
		};
	};
	class BRP_athleticshoes_burgundy: AthleticShoes_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_athleticshoes_burgundy.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_athleticshoes_burgundy.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_athleticshoes_burgundy.paa"
		};
	};
	class BRP_athleticshoes_candypink: AthleticShoes_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_athleticshoes_candypink.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_athleticshoes_candypink.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_athleticshoes_candypink.paa"
		};
	};
	class BRP_athleticshoes_cream: AthleticShoes_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_athleticshoes_cream.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_athleticshoes_cream.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_athleticshoes_cream.paa"
		};
	};
	class BRP_athleticshoes_cyan: AthleticShoes_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_athleticshoes_cyan.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_athleticshoes_cyan.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_athleticshoes_cyan.paa"
		};
	};
	class BRP_athleticshoes_darkbrown: AthleticShoes_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_athleticshoes_darkbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_athleticshoes_darkbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_athleticshoes_darkbrown.paa"
		};
	};
	class BRP_athleticshoes_darkgrey: AthleticShoes_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_athleticshoes_darkgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_athleticshoes_darkgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_athleticshoes_darkgrey.paa"
		};
	};
	class BRP_athleticshoes_fuchsia: AthleticShoes_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_athleticshoes_fuchsia.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_athleticshoes_fuchsia.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_athleticshoes_fuchsia.paa"
		};
	};
	class BRP_athleticshoes_lightbrown: AthleticShoes_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_athleticshoes_lightbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_athleticshoes_lightbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_athleticshoes_lightbrown.paa"
		};
	};
	class BRP_athleticshoes_lightgrey: AthleticShoes_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_athleticshoes_lightgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_athleticshoes_lightgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_athleticshoes_lightgrey.paa"
		};
	};
	class BRP_athleticshoes_navyblue: AthleticShoes_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_athleticshoes_navyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_athleticshoes_navyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_athleticshoes_navyblue.paa"
		};
	};
	class BRP_athleticshoes_olivegreen: AthleticShoes_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_athleticshoes_olivegreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_athleticshoes_olivegreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_athleticshoes_olivegreen.paa"
		};
	};
	class BRP_athleticshoes_orange: AthleticShoes_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_athleticshoes_orange.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_athleticshoes_orange.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_athleticshoes_orange.paa"
		};
	};
	class BRP_athleticshoes_plum: AthleticShoes_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_athleticshoes_plum.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_athleticshoes_plum.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_athleticshoes_plum.paa"
		};
	};
	class BRP_athleticshoes_purple: AthleticShoes_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_athleticshoes_purple.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_athleticshoes_purple.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_athleticshoes_purple.paa"
		};
	};
	class BRP_athleticshoes_red: AthleticShoes_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_athleticshoes_red.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_athleticshoes_red.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_athleticshoes_red.paa"
		};
	};
	class BRP_athleticshoes_royalblue: AthleticShoes_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_athleticshoes_royalblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_athleticshoes_royalblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_athleticshoes_royalblue.paa"
		};
	};
	class BRP_athleticshoes_white: AthleticShoes_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_athleticshoes_white.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_athleticshoes_white.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_athleticshoes_white.paa"
		};
	};
	class BRP_athleticshoes_yellow: AthleticShoes_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_athleticshoes_yellow.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_athleticshoes_yellow.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_athleticshoes_yellow.paa"
		};
	};
class BRP_canvasbackpack_babypink: Canvas_Backpack_Base
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_canvasbackpack_babypink.paa"
		};
	};
	class BRP_canvasbackpack_black: Canvas_Backpack_Base
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_canvasbackpack_black.paa"
		};
	};
	class BRP_canvasbackpack_darkgrey: Canvas_Backpack_Base
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_canvasbackpack_darkgrey.paa"
		};
	};
	class BRP_canvasbackpack_fuchsia: Canvas_Backpack_Base
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_canvasbackpack_fuchsia.paa"
		};
	};
	class BRP_canvasbackpack_white: Canvas_Backpack_Base
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_canvasbackpack_white.paa"
		};
	};
	class BRP_hikingjacket_armygreen: HikingJacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_hikingjacket_armygreeng.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_hikingjacket_armygreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_hikingjacket_armygreen.paa"
		};
	};
	class BRP_hikingjacket_babyblue: HikingJacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_hikingjacket_babyblueg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_hikingjacket_babyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_hikingjacket_babyblue.paa"
		};
	};
	class BRP_hikingjacket_babypink: HikingJacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_hikingjacket_babypinkg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_hikingjacket_babypink.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_hikingjacket_babypink.paa"
		};
	};
	class BRP_hikingjacket_beige: HikingJacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_hikingjacket_beigeg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_hikingjacket_beige.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_hikingjacket_beige.paa"
		};
	};
	class BRP_hikingjacket_black: HikingJacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_hikingjacket_blackg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_hikingjacket_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_hikingjacket_black.paa"
		};
	};
	class BRP_hikingjacket_burgundy: HikingJacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_hikingjacket_burgundyg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_hikingjacket_burgundy.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_hikingjacket_burgundy.paa"
		};
	};
	class BRP_hikingjacket_candypink: HikingJacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_hikingjacket_candypinkg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_hikingjacket_candypink.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_hikingjacket_candypink.paa"
		};
	};
	class BRP_hikingjacket_cream: HikingJacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_hikingjacket_creamg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_hikingjacket_cream.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_hikingjacket_cream.paa"
		};
	};
	class BRP_hikingjacket_cyan: HikingJacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_hikingjacket_cyang.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_hikingjacket_cyan.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_hikingjacket_cyan.paa"
		};
	};
	class BRP_hikingjacket_darkbrown: HikingJacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_hikingjacket_darkbrowng.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_hikingjacket_darkbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_hikingjacket_darkbrown.paa"
		};
	};
	class BRP_hikingjacket_darkgrey: HikingJacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_hikingjacket_darkgreyg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_hikingjacket_darkgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_hikingjacket_darkgrey.paa"
		};
	};
	class BRP_hikingjacket_fuchsia: HikingJacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_hikingjacket_fuchsiag.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_hikingjacket_fuchsia.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_hikingjacket_fuchsia.paa"
		};
	};
	class BRP_hikingjacket_lavender: HikingJacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_hikingjacket_lavenderg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_hikingjacket_lavender.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_hikingjacket_lavender.paa"
		};
	};
	class BRP_hikingjacket_lightbrown: HikingJacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_hikingjacket_lightbrowng.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_hikingjacket_lightbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_hikingjacket_lightbrown.paa"
		};
	};
	class BRP_hikingjacket_lightgrey: HikingJacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_hikingjacket_lightgreyg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_hikingjacket_lightgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_hikingjacket_lightgrey.paa"
		};
	};
	class BRP_hikingjacket_navyblue: HikingJacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_hikingjacket_navyblueg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_hikingjacket_navyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_hikingjacket_navyblue.paa"
		};
	};
	class BRP_hikingjacket_olivegreen: HikingJacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_hikingjacket_olivegreeng.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_hikingjacket_olivegreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_hikingjacket_olivegreen.paa"
		};
	};
	class BRP_hikingjacket_orange: HikingJacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_hikingjacket_orangeg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_hikingjacket_orange.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_hikingjacket_orange.paa"
		};
	};
	class BRP_hikingjacket_plum: HikingJacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_hikingjacket_plumg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_hikingjacket_plum.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_hikingjacket_plum.paa"
		};
	};
	class BRP_hikingjacket_purple: HikingJacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_hikingjacket_purpleg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_hikingjacket_purple.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_hikingjacket_purple.paa"
		};
	};
	class BRP_hikingjacket_red: HikingJacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_hikingjacket_redg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_hikingjacket_red.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_hikingjacket_red.paa"
		};
	};
	class BRP_hikingjacket_royalblue: HikingJacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_hikingjacket_royalblueg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_hikingjacket_royalblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_hikingjacket_royalblue.paa"
		};
	};
	class BRP_hikingjacket_white: HikingJacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_hikingjacket_whiteg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_hikingjacket_white.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_hikingjacket_white.paa"
		};
	};
	class BRP_hikingjacket_yellow: HikingJacket_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_hikingjacket_yellowg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_hikingjacket_yellow.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_hikingjacket_yellow.paa"
		};
	};
	class BRP_kneehighsneakers_armygreen: High_Knee_Sneakers
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_kneehighsneakers_armygreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_kneehighsneakers_armygreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_kneehighsneakers_armygreen.paa"
		};
	};
	class BRP_kneehighsneakers_babyblue: High_Knee_Sneakers
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_kneehighsneakers_babyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_kneehighsneakers_babyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_kneehighsneakers_babyblue.paa"
		};
	};
	class BRP_kneehighsneakers_babypink: High_Knee_Sneakers
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_kneehighsneakers_babypink.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_kneehighsneakers_babypink.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_kneehighsneakers_babypink.paa"
		};
	};
	class BRP_kneehighsneakers_beige: High_Knee_Sneakers
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_kneehighsneakers_beige.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_kneehighsneakers_beige.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_kneehighsneakers_beige.paa"
		};
	};
	class BRP_kneehighsneakers_black: High_Knee_Sneakers
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_kneehighsneakers_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_kneehighsneakers_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_kneehighsneakers_black.paa"
		};
	};
	class BRP_kneehighsneakers_burgundy: High_Knee_Sneakers
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_kneehighsneakers_burgundy.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_kneehighsneakers_burgundy.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_kneehighsneakers_burgundy.paa"
		};
	};
	class BRP_kneehighsneakers_candypink: High_Knee_Sneakers
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_kneehighsneakers_candypink.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_kneehighsneakers_candypink.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_kneehighsneakers_candypink.paa"
		};
	};
	class BRP_kneehighsneakers_cream: High_Knee_Sneakers
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_kneehighsneakers_cream.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_kneehighsneakers_cream.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_kneehighsneakers_cream.paa"
		};
	};
	class BRP_kneehighsneakers_cyan: High_Knee_Sneakers
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_kneehighsneakers_cyan.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_kneehighsneakers_cyan.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_kneehighsneakers_cyan.paa"
		};
	};
	class BRP_kneehighsneakers_darkbrown: High_Knee_Sneakers
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_kneehighsneakers_darkbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_kneehighsneakers_darkbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_kneehighsneakers_darkbrown.paa"
		};
	};
	class BRP_kneehighsneakers_darkgrey: High_Knee_Sneakers
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_kneehighsneakers_darkgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_kneehighsneakers_darkgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_kneehighsneakers_darkgrey.paa"
		};
	};
	class BRP_kneehighsneakers_fuchsia: High_Knee_Sneakers
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_kneehighsneakers_fuchsia.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_kneehighsneakers_fuchsia.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_kneehighsneakers_fuchsia.paa"
		};
	};
	class BRP_kneehighsneakers_lavender: High_Knee_Sneakers
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_kneehighsneakers_lavender.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_kneehighsneakers_lavender.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_kneehighsneakers_lavender.paa"
		};
	};
	class BRP_kneehighsneakers_lightbrown: High_Knee_Sneakers
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_kneehighsneakers_lightbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_kneehighsneakers_lightbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_kneehighsneakers_lightbrown.paa"
		};
	};
	class BRP_kneehighsneakers_lightgrey: High_Knee_Sneakers
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_kneehighsneakers_lightgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_kneehighsneakers_lightgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_kneehighsneakers_lightgrey.paa"
		};
	};
	class BRP_kneehighsneakers_navyblue: High_Knee_Sneakers
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_kneehighsneakers_navyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_kneehighsneakers_navyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_kneehighsneakers_navyblue.paa"
		};
	};
	class BRP_kneehighsneakers_olivegreen: High_Knee_Sneakers
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_kneehighsneakers_olivegreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_kneehighsneakers_olivegreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_kneehighsneakers_olivegreen.paa"
		};
	};
	class BRP_kneehighsneakers_orange: High_Knee_Sneakers
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_kneehighsneakers_orange.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_kneehighsneakers_orange.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_kneehighsneakers_orange.paa"
		};
	};
	class BRP_kneehighsneakers_plum: High_Knee_Sneakers
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_kneehighsneakers_plum.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_kneehighsneakers_plum.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_kneehighsneakers_plum.paa"
		};
	};
	class BRP_kneehighsneakers_purple: High_Knee_Sneakers
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_kneehighsneakers_purple.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_kneehighsneakers_purple.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_kneehighsneakers_purple.paa"
		};
	};
	class BRP_kneehighsneakers_red: High_Knee_Sneakers
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_kneehighsneakers_red.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_kneehighsneakers_red.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_kneehighsneakers_red.paa"
		};
	};
	class BRP_kneehighsneakers_royalblue: High_Knee_Sneakers
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_kneehighsneakers_royalblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_kneehighsneakers_royalblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_kneehighsneakers_royalblue.paa"
		};
	};
	class BRP_kneehighsneakers_white: High_Knee_Sneakers
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_kneehighsneakers_white.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_kneehighsneakers_white.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_kneehighsneakers_white.paa"
		};
	};
	class BRP_kneehighsneakers_yellow: High_Knee_Sneakers
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_kneehighsneakers_yellow.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_kneehighsneakers_yellow.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_kneehighsneakers_yellow.paa"
		};
	};
	class BRP_layeredshirt_armygreen: Layered_Shirt_Base
	{
		scope=2;
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_layeredshirt_armygreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_layeredshirt_armygreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_layeredshirt_armygreen.paa"
		};
	};
	class BRP_layeredshirt_babyblue: Layered_Shirt_Base
	{
		scope=2;
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_layeredshirt_babyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_layeredshirt_babyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_layeredshirt_babyblue.paa"
		};
	};
	class BRP_layeredshirt_babypink: Layered_Shirt_Base
	{
		scope=2;
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_layeredshirt_babypink.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_layeredshirt_babypink.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_layeredshirt_babypink.paa"
		};
	};
	class BRP_layeredshirt_beige: Layered_Shirt_Base
	{
		scope=2;
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_layeredshirt_beige.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_layeredshirt_beige.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_layeredshirt_beige.paa"
		};
	};
	class BRP_layeredshirt_black: Layered_Shirt_Base
	{
		scope=2;
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_layeredshirt_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_layeredshirt_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_layeredshirt_black.paa"
		};
	};
	class BRP_layeredshirt_burgundy: Layered_Shirt_Base
	{
		scope=2;
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_layeredshirt_burgundy.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_layeredshirt_burgundy.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_layeredshirt_burgundy.paa"
		};
	};
	class BRP_layeredshirt_candypink: Layered_Shirt_Base
	{
		scope=2;
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_layeredshirt_candypink.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_layeredshirt_candypink.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_layeredshirt_candypink.paa"
		};
	};
	class BRP_layeredshirt_cream: Layered_Shirt_Base
	{
		scope=2;
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_layeredshirt_cream.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_layeredshirt_cream.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_layeredshirt_cream.paa"
		};
	};
	class BRP_layeredshirt_cyan: Layered_Shirt_Base
	{
		scope=2;
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_layeredshirt_cyan.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_layeredshirt_cyan.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_layeredshirt_cyan.paa"
		};
	};
	class BRP_layeredshirt_darkbrown: Layered_Shirt_Base
	{
		scope=2;
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_layeredshirt_darkbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_layeredshirt_darkbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_layeredshirt_darkbrown.paa"
		};
	};
	class BRP_layeredshirt_darkgrey: Layered_Shirt_Base
	{
		scope=2;
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_layeredshirt_darkgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_layeredshirt_darkgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_layeredshirt_darkgrey.paa"
		};
	};
	class BRP_layeredshirt_fuchsia: Layered_Shirt_Base
	{
		scope=2;
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_layeredshirt_fuchsia.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_layeredshirt_fuchsia.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_layeredshirt_fuchsia.paa"
		};
	};
	class BRP_layeredshirt_lavender: Layered_Shirt_Base
	{
		scope=2;
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_layeredshirt_lavender.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_layeredshirt_lavender.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_layeredshirt_lavender.paa"
		};
	};
	class BRP_layeredshirt_lightbrown: Layered_Shirt_Base
	{
		scope=2;
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_layeredshirt_lightbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_layeredshirt_lightbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_layeredshirt_lightbrown.paa"
		};
	};
	class BRP_layeredshirt_lightgrey: Layered_Shirt_Base
	{
		scope=2;
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_layeredshirt_lightgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_layeredshirt_lightgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_layeredshirt_lightgrey.paa"
		};
	};
	class BRP_layeredshirt_navyblue: Layered_Shirt_Base
	{
		scope=2;
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_layeredshirt_navyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_layeredshirt_navyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_layeredshirt_navyblue.paa"
		};
	};
	class BRP_layeredshirt_olivegreen: Layered_Shirt_Base
	{
		scope=2;
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_layeredshirt_olivegreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_layeredshirt_olivegreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_layeredshirt_olivegreen.paa"
		};
	};
	class BRP_layeredshirt_orange: Layered_Shirt_Base
	{
		scope=2;
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_layeredshirt_orange.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_layeredshirt_orange.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_layeredshirt_orange.paa"
		};
	};
	class BRP_layeredshirt_plum: Layered_Shirt_Base
	{
		scope=2;
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_layeredshirt_plum.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_layeredshirt_plum.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_layeredshirt_plum.paa"
		};
	};
	class BRP_layeredshirt_purple: Layered_Shirt_Base
	{
		scope=2;
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_layeredshirt_purple.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_layeredshirt_purple.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_layeredshirt_purple.paa"
		};
	};
	class BRP_layeredshirt_red: Layered_Shirt_Base
	{
		scope=2;
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_layeredshirt_red.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_layeredshirt_red.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_layeredshirt_red.paa"
		};
	};
	class BRP_layeredshirt_royalblue: Layered_Shirt_Base
	{
		scope=2;
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_layeredshirt_royalblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_layeredshirt_royalblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_layeredshirt_royalblue.paa"
		};
	};
	class BRP_layeredshirt_white: Layered_Shirt_Base
	{
		scope=2;
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_layeredshirt_white.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_layeredshirt_white.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_layeredshirt_white.paa"
		};
	};
	class BRP_layeredshirt_yellow: Layered_Shirt_Base
	{
		scope=2;
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_layeredshirt_yellow.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_layeredshirt_yellow.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_layeredshirt_yellow.paa"
		};
	};
	class BRP_leathersack_armygreen: LeatherSack_Natural
	{
		scope=2;
		color="coda_armygreen";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_leathersack_armygreeng.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_leathersack_armygreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_leathersack_armygreen.paa"
		};
	};
	class BRP_leatherhat_armygreen: LeatherHat_ColorBase
	{
		scope=2;
		color="coda_armygreen";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_leatherhat_armygreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_leatherhat_armygreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_leatherhat_armygreen.paa"
		};
	};
	class BRP_leathervest_armygreen: LeatherStorageVest_ColorBase
	{
		scope=2;
		color="coda_armygreen";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_leathervest_armygreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_leathervest_armygreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_leathervest_armygreen.paa"
		};
	};
	class BRP_leatherjacket_armygreen: LeatherJacket_ColorBase
	{
		scope=2;
		color="coda_armygreen";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_leatherjacket_armygreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_leatherjacket_armygreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_leatherjacket_armygreen.paa"
		};
	};
	class BRP_leathergloves_armygreen: LeatherGloves_ColorBase
	{
		scope=2;
		color="coda_armygreen";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_leathergloves_armygreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_leathergloves_armygreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_leathergloves_armygreen.paa"
		};
	};
	class BRP_leatherpants_armygreen: LeatherPants_ColorBase
	{
		scope=2;
		color="coda_armygreen";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_leatherpants_armygreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_leatherpants_armygreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_leatherpants_armygreen.paa"
		};
	};
	class BRP_leathershoes_armygreen: LeatherShoes_ColorBase
	{
		scope=2;
		color="coda_armygreen";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_leathershoes_armygreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_leathershoes_armygreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_leathershoes_armygreen.paa"
		};
	};
	class BRP_leathersack_beige: LeatherSack_Natural
	{
		scope=2;
		color="coda_beige";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_leathersack_beigeg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_leathersack_beige.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_leathersack_beige.paa"
		};
	};
	class BRP_leatherhat_beige: LeatherHat_ColorBase
	{
		scope=2;
		color="coda_beige";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_leatherhat_beige.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_leatherhat_beige.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_leatherhat_beige.paa"
		};
	};
	class BRP_leathervest_beige: LeatherStorageVest_ColorBase
	{
		scope=2;
		color="coda_beige";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_leathervest_beige.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_leathervest_beige.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_leathervest_beige.paa"
		};
	};
	class BRP_leatherjacket_beige: LeatherJacket_ColorBase
	{
		scope=2;
		color="coda_beige";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_leatherjacket_beige.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_leatherjacket_beige.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_leatherjacket_beige.paa"
		};
	};
	class BRP_leathergloves_beige: LeatherGloves_ColorBase
	{
		scope=2;
		color="coda_beige";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_leathergloves_beige.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_leathergloves_beige.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_leathergloves_beige.paa"
		};
	};
	class BRP_leatherpants_beige: LeatherPants_ColorBase
	{
		scope=2;
		color="coda_beige";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_leatherpants_beige.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_leatherpants_beige.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_leatherpants_beige.paa"
		};
	};
	class BRP_leathershoes_beige: LeatherShoes_ColorBase
	{
		scope=2;
		color="coda_beige";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_leathershoes_beige.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_leathershoes_beige.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_leathershoes_beige.paa"
		};
	};
	class BRP_leathersack_black: LeatherSack_Natural
	{
		scope=2;
		color="coda_black";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_leathersack_blackg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_leathersack_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_leathersack_black.paa"
		};
	};
	class BRP_leatherhat_black: LeatherHat_ColorBase
	{
		scope=2;
		color="coda_black";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_leatherhat_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_leatherhat_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_leatherhat_black.paa"
		};
	};
	class BRP_leathervest_black: LeatherStorageVest_ColorBase
	{
		scope=2;
		color="coda_black";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_leathervest_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_leathervest_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_leathervest_black.paa"
		};
	};
	class BRP_leatherjacket_black: LeatherJacket_ColorBase
	{
		scope=2;
		color="coda_black";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_leatherjacket_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_leatherjacket_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_leatherjacket_black.paa"
		};
	};
	class BRP_leathergloves_black: LeatherGloves_ColorBase
	{
		scope=2;
		color="coda_black";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_leathergloves_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_leathergloves_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_leathergloves_black.paa"
		};
	};
	class BRP_leatherpants_black: LeatherPants_ColorBase
	{
		scope=2;
		color="coda_black";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_leatherpants_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_leatherpants_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_leatherpants_black.paa"
		};
	};
	class BRP_leathershoes_black: LeatherShoes_ColorBase
	{
		scope=2;
		color="coda_black";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_leathershoes_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_leathershoes_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_leathershoes_black.paa"
		};
	};
	class BRP_leathersack_cream: LeatherSack_Natural
	{
		scope=2;
		color="coda_cream";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_leathersack_creamg.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_leathersack_cream.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_leathersack_cream.paa"
		};
	};
	class BRP_leatherhat_cream: LeatherHat_ColorBase
	{
		scope=2;
		color="coda_cream";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_leatherhat_cream.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_leatherhat_cream.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_leatherhat_cream.paa"
		};
	};
	class BRP_leathervest_cream: LeatherStorageVest_ColorBase
	{
		scope=2;
		color="coda_cream";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_leathervest_cream.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_leathervest_cream.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_leathervest_cream.paa"
		};
	};
	class BRP_leatherjacket_cream: LeatherJacket_ColorBase
	{
		scope=2;
		color="coda_cream";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_leatherjacket_cream.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_leatherjacket_cream.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_leatherjacket_cream.paa"
		};
	};
	class BRP_leathergloves_cream: LeatherGloves_ColorBase
	{
		scope=2;
		color="coda_cream";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_leathergloves_cream.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_leathergloves_cream.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_leathergloves_cream.paa"
		};
	};
	class BRP_leatherpants_cream: LeatherPants_ColorBase
	{
		scope=2;
		color="coda_cream";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_leatherpants_cream.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_leatherpants_cream.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_leatherpants_cream.paa"
		};
	};
	class BRP_leathershoes_cream: LeatherShoes_ColorBase
	{
		scope=2;
		color="coda_cream";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_leathershoes_cream.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_leathershoes_cream.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_leathershoes_cream.paa"
		};
	};
	class BRP_leathersack_darkbrown: LeatherSack_Natural
	{
		scope=2;
		color="coda_darkbrown";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_leathersack_darkbrowng.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_leathersack_darkbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_leathersack_darkbrown.paa"
		};
	};
	class BRP_leatherhat_darkbrown: LeatherHat_ColorBase
	{
		scope=2;
		color="coda_darkbrown";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_leatherhat_darkbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_leatherhat_darkbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_leatherhat_darkbrown.paa"
		};
	};
	class BRP_leathervest_darkbrown: LeatherStorageVest_ColorBase
	{
		scope=2;
		color="coda_darkbrown";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_leathervest_darkbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_leathervest_darkbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_leathervest_darkbrown.paa"
		};
	};
	class BRP_leatherjacket_darkbrown: LeatherJacket_ColorBase
	{
		scope=2;
		color="coda_darkbrown";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_leatherjacket_darkbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_leatherjacket_darkbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_leatherjacket_darkbrown.paa"
		};
	};
	class BRP_leathergloves_darkbrown: LeatherGloves_ColorBase
	{
		scope=2;
		color="coda_darkbrown";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_leathergloves_darkbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_leathergloves_darkbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_leathergloves_darkbrown.paa"
		};
	};
	class BRP_leatherpants_darkbrown: LeatherPants_ColorBase
	{
		scope=2;
		color="coda_darkbrown";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_leatherpants_darkbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_leatherpants_darkbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_leatherpants_darkbrown.paa"
		};
	};
	class BRP_leathershoes_darkbrown: LeatherShoes_ColorBase
	{
		scope=2;
		color="coda_darkbrown";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_leathershoes_darkbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_leathershoes_darkbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_leathershoes_darkbrown.paa"
		};
	};
	class BRP_militarysweater_armygreen: Military_Sweater
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_militarysweater_armygreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_militarysweater_armygreen.paa",
		};
	};
	class BRP_militarysweater_babyblue: Military_Sweater
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_militarysweater_babyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_militarysweater_babyblue.paa",
		};
	};
	class BRP_militarysweater_babypink: Military_Sweater
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_militarysweater_babypink.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_militarysweater_babypink.paa",
		};
	};
	class BRP_militarysweater_beige: Military_Sweater
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_militarysweater_beige.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_militarysweater_beige.paa",
		};
	};
	class BRP_militarysweater_black: Military_Sweater
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_militarysweater_black.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_militarysweater_black.paa",
		};
	};
	class BRP_militarysweater_burgundy: Military_Sweater
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_militarysweater_burgundy.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_militarysweater_burgundy.paa",
		};
	};
	class BRP_militarysweater_candypink: Military_Sweater
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_militarysweater_candypink.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_militarysweater_candypink.paa",
		};
	};
	class BRP_militarysweater_cream: Military_Sweater
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_militarysweater_cream.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_militarysweater_cream.paa",
		};
	};
	class BRP_militarysweater_cyan: Military_Sweater
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_militarysweater_cyan.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_militarysweater_cyan.paa",
		};
	};
	class BRP_militarysweater_darkbrown: Military_Sweater
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_militarysweater_darkbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_militarysweater_darkbrown.paa",
		};
	};
	class BRP_militarysweater_darkgrey: Military_Sweater
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_militarysweater_darkgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_militarysweater_darkgrey.paa",
		};
	};
	class BRP_militarysweater_fuchsia: Military_Sweater
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_militarysweater_fuchsia.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_militarysweater_fuchsia.paa",
		};
	};
	class BRP_militarysweater_lavender: Military_Sweater
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_militarysweater_lavender.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_militarysweater_lavender.paa",
		};
	};
	class BRP_militarysweater_lightbrown: Military_Sweater
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_militarysweater_lightbrown.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_militarysweater_lightbrown.paa",
		};
	};
	class BRP_militarysweater_lightgrey: Military_Sweater
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_militarysweater_lightgrey.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_militarysweater_lightgrey.paa",
		};
	};
	class BRP_militarysweater_navyblue: Military_Sweater
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_militarysweater_navyblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_militarysweater_navyblue.paa",
		};
	};
	class BRP_militarysweater_olivegreen: Military_Sweater
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_militarysweater_olivegreen.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_militarysweater_olivegreen.paa",
		};
	};
	class BRP_militarysweater_orange: Military_Sweater
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_militarysweater_orange.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_militarysweater_orange.paa",
		};
	};
	class BRP_militarysweater_plum: Military_Sweater
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_militarysweater_plum.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_militarysweater_plum.paa",
		};
	};
	class BRP_militarysweater_purple: Military_Sweater
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_militarysweater_purple.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_militarysweater_purple.paa",
		};
	};
	class BRP_militarysweater_red: Military_Sweater
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_militarysweater_red.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_militarysweater_red.paa",
		};
	};
	class BRP_militarysweater_royalblue: Military_Sweater
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_militarysweater_royalblue.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_militarysweater_royalblue.paa",
		};
	};
	class BRP_militarysweater_white: Military_Sweater
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_militarysweater_white.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_militarysweater_white.paa",
		};
	};
	class BRP_militarysweater_yellow: Military_Sweater
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_militarysweater_yellow.paa",
			"BastionMod\BastionClothing\Retextures\data\coda_militarysweater_yellow.paa",
		};
	};
	class BRP_shirt_floral: Shirt_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\coda_shirt_floral.paa",
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
};
