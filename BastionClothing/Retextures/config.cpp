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
	class BalaclavaMask_ColorBase;
	class Canvas_Backpack_Base;
	class AthleticShoes_ColorBase;
	class TacticalShirt_ColorBase;
	class BDUPants;	
	class Mich2001Helmet;
	class MilitaryBeret_Red;
	class SurgicalMask;
	class ParamedicJacket_ColorBase;
	class TTsKOJacket_ColorBase;
	class MilitaryBeret_ColorBase;
	class HikingJacket_ColorBase;
	class BaseballCap_ColorBase;
	class PoliceVest;
	class High_Knee_Sneakers;
	class SmershBag;
	class AssaultBag_ColorBase;
	class TortillaBag;
	class ParamedicPants_ColorBase;
	class PrisonUniformPants;
	class CargoPants_Colorbase;
	class Hoodie_ColorBase;
	class SmershVest;
	class TTSKOPants;
	class TacticalShirt_Grey;
	class Layered_Shirt_Base;
	class LeatherSack_Natural;
	class LeatherHat_ColorBase;
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
};
