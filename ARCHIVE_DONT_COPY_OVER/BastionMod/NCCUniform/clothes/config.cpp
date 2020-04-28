////////////////////////////////////////////////////////////////////
//DeRap: P:\BastionMod\NCCUniform\clothes\config.bin
//Produced from mikero's Dos Tools Dll version 7.60
//https://mikero.bytex.digital/Downloads
//'now' is Thu Mar 26 20:46:12 2020 : 'file' last modified on Thu Mar 26 20:46:12 2020
////////////////////////////////////////////////////////////////////

#define _ARMA_

class CfgPatches
{
	class NCC_Clothes
	{
		units[] = {"Bastion_ISF_Tacshirt","Bastion_ISF_DART_Tacshirt","BastionRP_ISF_Pants","BastionRP_ISF_DART_Pants","BastionRP_ISF_OfficerBeret","BastionRP_ISF_DART_Helmet"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Characters","DZ_Characters_Vests","DZ_Characters_Pants","DZ_Characters_Tops","DZ_Characters_Shoes","DZ_Characters_Headgear","DZ_Data","DZ_Weapons_Optics","DZ_Weapons_Melee"};
	};
};
class cfgVehicles
{
	class BaseballCap_ColorBase;
	class BalaclavaMask_ColorBase;
	class Balaclava3Holes_ColorBase;
	class BandanaMask_ColorBase;
	class SurgicalMask;
	class GP5GasMask;
	class TacticalShirt_ColorBase;
	class Clothing_Base;
	class BDUPants;
	class Bastion_ISF_Tacshirt: TacticalShirt_ColorBase
	{
		displayName = "ISF Tactical Shirt";
		descriptionShort = "";
		scope = 2;
		hiddenSelectionsTextures[] = {"BastionMod\NCCUniform\clothes\data\ncc_tacshirt.paa","BastionMod\NCCUniform\clothes\data\ncc_tacshirt.paa","BastionMod\NCCUniform\clothes\data\ncc_tacshirt.paa"};
	};
	class Bastion_ISF_DART_Tacshirt: TacticalShirt_ColorBase
	{
		displayName = "ISF Tactical Shirt";
		descriptionShort = "";
		scope = 2;
		hiddenSelectionsTextures[] = {"BastionMod\NCCUniform\clothes\data\isff_tacshirt.paa","BastionMod\NCCUniform\clothes\data\isff_tacshirt.paa","BastionMod\NCCUniform\clothes\data\isff_tacshirt.paa"};
	};
	class BastionRP_ISF_Pants: BDUPants
	{
		scope = 2;
		displayName = "ISF Pants";
		descriptionShort = "";
		hiddenSelectionsTextures[] = {"BastionMod\NCCUniform\clothes\data\ncc_pants.paa","BastionMod\NCCUniform\clothes\data\ncc_pants.paa","BastionMod\NCCUniform\clothes\data\ncc_pants.paa"};
	};
	class BastionRP_ISF_DART_Pants: BDUPants
	{
		scope = 2;
		displayName = "ISF Pants";
		descriptionShort = "";
		hiddenSelectionsTextures[] = {"BastionMod\NCCUniform\clothes\data\isff_pants.paa","BastionMod\NCCUniform\clothes\data\isff_pants.paa","BastionMod\NCCUniform\clothes\data\isff_pants.paa"};
	};
	class MilitaryBeret_Red;
	class BastionRP_ISF_OfficerBeret: MilitaryBeret_Red
	{
		scope = 2;
		displayName = "ISF Officer Beret";
		descriptionShort = "";
		hiddenSelection[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"BastionMod\NCCUniform\clothes\data\ncc_officerberet.paa","BastionMod\NCCUniform\clothes\data\ncc_officerberet.paa","BastionMod\NCCUniform\clothes\data\ncc_officerberet.paa"};
	};
	class Mich2001Helmet;
	class BastionRP_ISF_DART_Helmet: Mich2001Helmet
	{
		displayName = "ISF Helmet";
		descriptionShort = "";
		scope = 2;
		hiddenSelectionsTextures[] = {"BastionMod\NCCUniform\clothes\data\tacticalhelm_dart.paa","BastionMod\NCCUniform\clothes\data\tacticalhelm_dart.paa","BastionMod\NCCUniform\clothes\data\tacticalhelm_dart.paa"};
	};
};
