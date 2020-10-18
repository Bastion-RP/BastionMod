class CfgPatches
{
	class BRP_RankInsignia
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Characters_Tops"};
	};
};
class cfgVehicles
{
	class Armband_ColorBase;
	class BRP_RankInsignia_base: Armband_ColorBase
	{
		displayName = "Rank Insignia";
		model = "\BastionMod\BastionClothing\RankInsignia\BRP_RankInsignia_g.p3d";
		selection = "leftarm";
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\BastionMod\BastionClothing\RankInsignia\data\rankinsignia_rct_ca.paa"};
		
		class ClothingTypes
		{
			male = "\BastionMod\BastionClothing\RankInsignia\BRP_RankInsignia_m.p3d";
			female = "\BastionMod\BastionClothing\RankInsignia\BRP_RankInsignia_f.p3d";
		};
	};
	
	class BRP_RankInsignia_RCT: BRP_RankInsignia_base
	{
		scope = 2;
		displayName = "Recruit Rank Insignia";
		hiddenSelectionsTextures[] = {"\BastionMod\BastionClothing\RankInsignia\data\rankinsignia_rct_ca.paa"};
	};
/*
	class BRP_RankInsignia_TR: BRP_RankInsignia_base
	{
		scope = 2;
		displayName = "Trooper Rank Insignia";
		hiddenSelectionsTextures[] = {"\BastionMod\BastionClothing\RankInsignia\data\rankinsignia_tr_ca.paa"};
	};
	class BRP_RankInsignia_STR: BRP_RankInsignia_base
	{
		scope = 2;
		displayName = "Senior Trooper Rank Insignia";
		hiddenSelectionsTextures[] = {"\BastionMod\BastionClothing\RankInsignia\data\rankinsignia_str_ca.paa"};
	};
	class BRP_RankInsignia_CPL: BRP_RankInsignia_base
	{
		scope = 2;
		displayName = "Corporal Rank Insignia";
		hiddenSelectionsTextures[] = {"\BastionMod\BastionClothing\RankInsignia\data\rankinsignia_cpl_ca.paa"};
	};
	class BRP_RankInsignia_SGT: BRP_RankInsignia_base
	{
		scope = 2;
		displayName = "Sergeant Rank Insignia";
		hiddenSelectionsTextures[] = {"\BastionMod\BastionClothing\RankInsignia\data\rankinsignia_sgt_ca.paa"};
	};
	class BRP_RankInsignia_MSG: BRP_RankInsignia_base
	{
		scope = 2;
		displayName = "Master Sergeant Rank Insignia";
		hiddenSelectionsTextures[] = {"\BastionMod\BastionClothing\RankInsignia\data\rankinsignia_msg_ca.paa"};
	};
	class BRP_RankInsignia_LT: BRP_RankInsignia_base
	{
		scope = 2;
		displayName = "Lieutenant Rank Insignia";
		hiddenSelectionsTextures[] = {"\BastionMod\BastionClothing\RankInsignia\data\rankinsignia_lt_ca.paa"};
	};
	class BRP_RankInsignia_CPT: BRP_RankInsignia_base
	{
		scope = 2;
		displayName = "Captain Rank Insignia";
		hiddenSelectionsTextures[] = {"\BastionMod\BastionClothing\RankInsignia\data\rankinsignia_cpt_ca.paa"};
	};
	class BRP_RankInsignia_PRE: BRP_RankInsignia_base
	{
		scope = 2;
		displayName = "Prefect Rank Insignia";
		hiddenSelectionsTextures[] = {"\BastionMod\BastionClothing\RankInsignia\data\rankinsignia_pre_ca.paa"};
	};
*/
};