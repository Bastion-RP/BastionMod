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
			biological = 0;
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
	class BRP_ISF_Tacshirt: TacticalShirt_ColorBase
	{
		displayName = "ISF Tactical Shirt";
		descriptionShort = "";
		scope = 2;
		hiddenSelectionsTextures[] = {"BastionMod\BastionClothing\Retextures\data\ncc_tacshirt.paa","BastionMod\BastionClothing\Retextures\data\ncc_tacshirt.paa","BastionMod\BastionClothing\Retextures\data\ncc_tacshirt.paa"};
	};
	class BRP_ISF_DART_Tacshirt: TacticalShirt_ColorBase
	{
		displayName = "ISF Tactical Shirt";
		descriptionShort = "";
		scope = 2;
		hiddenSelectionsTextures[] = {"BastionMod\BastionClothing\Retextures\data\isff_tacshirt.paa","BastionMod\BastionClothing\Retextures\data\isff_tacshirt.paa","BastionMod\BastionClothing\Retextures\data\isff_tacshirt.paa"};
	};
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
	class BRP_ISF_DART_Helmet: Mich2001Helmet
	{
		scope = 2;
		displayName = "ISF Helmet";
		descriptionShort = "";
		hiddenSelectionsTextures[] = {"BastionMod\BastionClothing\Retextures\data\tacticalhelm_dart.paa","BastionMod\BastionClothing\Retextures\data\tacticalhelm_dart.paa","BastionMod\BastionClothing\Retextures\data\tacticalhelm_dart.paa"};
	};
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
	
	class BRP_ISF_OfficerBeret: MilitaryBeret_ColorBase
	{
		scope=2;
		displayName = "NCC Military Beret";
        descriptionShort = "Military beret for high-ranking NCC officials.";
		model="\DZ\characters\headgear\MilitaryBeret_g.p3d";
		class ClothingTypes
		{
			male="\DZ\characters\headgear\MilitaryBeret_m.p3d";
			female="\DZ\characters\headgear\MilitaryBeret_f.p3d";
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\militaryberet_isf_co.paa",
			"BastionMod\BastionClothing\Retextures\data\militaryberet_isf_co.paa",
			"BastionMod\BastionClothing\Retextures\data\militaryberet_isf_co.paa"
		};
	};
	class BRP_ISF_Blue_OfficerBeret: MilitaryBeret_ColorBase
	{
		scope=2;
		displayName = "NCC Military Beret";
        descriptionShort = "Military beret for high-ranking NCC officials.";
		model="\DZ\characters\headgear\MilitaryBeret_g.p3d";
		class ClothingTypes
		{
			male="\DZ\characters\headgear\MilitaryBeret_m.p3d";
			female="\DZ\characters\headgear\MilitaryBeret_f.p3d";
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionClothing\Retextures\data\militaryberet_isf_blue_co.paa",
			"BastionMod\BastionClothing\Retextures\data\militaryberet_isf_blue_co.paa",
			"BastionMod\BastionClothing\Retextures\data\militaryberet_isf_blue_co.paa"
		};
	};

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
};
