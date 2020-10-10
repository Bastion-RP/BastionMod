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
	class TacticalShirt_ColorBase;
	class BDUPants;	
	class Mich2001Helmet;
	class MilitaryBeret_Red;
	class TTsKOJacket_ColorBase;
	class MilitaryBeret_ColorBase;
	class BaseballCap_ColorBase;
	class PoliceVest;
	class SmershBag;
	class AssaultBag_ColorBase;
	class TortillaBag;
	class PrisonUniformPants;
	class Hoodie_ColorBase;
	class SmershVest;
	class TTSKOPants;
	class TacticalShirt_Grey;
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
// TTSKO Pants	
    class BRP_TTSKOPants_DART: TTSKOPants
    {    
        displayName = "DART Tactical Pants";
        scope = 2;
        visibilityModifier = 0.7;
        hiddenSelectionsTextures[] = {"BastionMod\BastionClothing\Retextures\data\dart_ttsko.paa","BastionMod\BastionClothing\Retextures\data\dart_ttsko.paa","BastionMod\BastionClothing\Retextures\data\dart_ttsko.paa"};
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
};
