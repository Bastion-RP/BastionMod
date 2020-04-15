class CfgPatches
{
	class NCC_Clothing
	{
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Characters","DZ_Characters_Vests","DZ_Characters_Pants","DZ_Characters_Tops","DZ_Characters_Shoes","DZ_Characters_Headgear","DZ_Data","DZ_Weapons_Optics","DZ_Weapons_Melee"};
		units[] = {"BastionRP_ISF_CarrierRig"};
	};
};
class CfgVehicles
{
	class PlateCarrierVest;
	class PlateCarrierPouches;
	class BastionRP_ISF_CarrierRig: PlateCarrierVest
	{
		scope = 2;
		displayName = "Rhino II Plate Carrier 'Big Rig'";
		descriptionShort = "A carrier rig specifically made to hold extra pouches for increased capacity out in the field without compromising protection";
		model = "\BastionMod\NCCUniform\isfplatecarrier\isfplatecarrier_g.p3d";
		attachments[] = 
		{
			"WalkieTalkie",
			"VestGrenadeA",
			"VestGrenadeB",
			"VestPouch",
			"VestHolster"
		};
		weight = 12000;		
		class ClothingTypes
		{
			male = "BastionMod\NCCUniform\isfplatecarrier\isfplatecarrier_m.p3d";
			female = "BastionMod\NCCUniform\isfplatecarrier\isfplatecarrier_m.p3d";
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = 
					{
						{
							1.0,
							{"BastionMod\NCCUniform\isfplatecarrier\data\isfplatecarrier.rvmat"}
						},
						{
							0.7,
							{"BastionMod\NCCUniform\isfplatecarrier\data\isfplatecarrier.rvmat"}
						},
						{
							0.5,
							{"BastionMod\NCCUniform\isfplatecarrier\data\isfplatecarrier_damage.rvmat"}
						},
						{
							0.3,
							{"BastionMod\NCCUniform\isfplatecarrier\data\isfplatecarrier_damage.rvmat"}
						},
						{
							0.0,
							{"BastionMod\NCCUniform\isfplatecarrier\data\isfplatecarrier_destruct.rvmat"}
						}
					};
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage = 0.4;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0.26;
					};
				};
				class Melee
				{
					class Health
					{
						damage = 0.25;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0.25;
					};
				};
				class Infected
				{
					class Health
					{
						damage = 0.25;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0.25;
					};
				};
			};
		};
	};
	class BastionRP_ISF_CarrierRigPouches: PlateCarrierPouches
	{
		scope=2;
		displayName="Rhino II Pouches";
		descriptionShort="$STR_CfgVehicles_CarrierPouches1";
		model="\BastionMod\NCCUniform\isfplatecarrier\isfplatecarrier_pouches.p3d";
		itemsCargoSize[] = {8,4};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=200;
					healthLevels[]=
					{
						
						{
							1.0,
							
							{
								"BastionMod\NCCUniform\isfplatecarrier\data\isfplatecarrier.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"BastionMod\NCCUniform\isfplatecarrier\data\isfplatecarrier.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"BastionMod\NCCUniform\isfplatecarrier\data\isfplatecarrier_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"BastionMod\NCCUniform\isfplatecarrier\data\isfplatecarrier_damage.rvmat"
							}
						},
						
						{
							0.0,
							
							{
								"BastionMod\NCCUniform\isfplatecarrier\data\isfplatecarrier_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};

	class PlateCarrierHolster;
	class BastionRP_ISF_CarrierRigHolster: PlateCarrierHolster
	{
		scope = 2;
		displayName="Rhino II Holster";
		visibilityModifier = 0.9;
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = 
		{
			"BastionMod\NCCUniform\isfplatecarrier\data\isfplatecarrier_holster_co.paa"
		};
	};
};

class CfgNonAIVehicles
{
	class ProxyAttachment;
	class Proxyisfplatecarrier_pouches: ProxyAttachment
	{
		scope = 2;
		inventorySlot[] = {"VestPouch"};
		model = "\BastionMod\NCCUniform\isfplatecarrier\isfplatecarrier_pouches.p3d";
	};
};
