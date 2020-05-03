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
	class BRP_ISF_OfficerBeret: MilitaryBeret_Red
	{
		scope = 2;
		displayName = "ISF Officer Beret";
		descriptionShort = "";
		hiddenSelection[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"BastionMod\BastionClothing\Retextures\data\ncc_officerberet.paa","BastionMod\BastionClothing\Retextures\data\ncc_officerberet.paa","BastionMod\BastionClothing\Retextures\data\ncc_officerberet.paa"};
	};
	class BRP_ISF_DART_Helmet: Mich2001Helmet
	{
		displayName = "ISF Helmet";
		descriptionShort = "";
		scope = 2;
		hiddenSelectionsTextures[] = {"BastionMod\BastionClothing\Retextures\data\tacticalhelm_dart.paa","BastionMod\BastionClothing\Retextures\data\tacticalhelm_dart.paa","BastionMod\BastionClothing\Retextures\data\tacticalhelm_dart.paa"};
	};
};
