class CfgMods
{
    class BastionBarrelFurniture_Data
    {
		type = "mod";
		author = "Chopper";
		name = "BastionBarrelFurniture_Data";
        dir = "BastionBarrelFurniture_Data";
        dependencies[]={};
    };
};

class CfgPatches
{
	class BastionBarrelFurniture_Data
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Gear_Containers",
			"DZ_Gear_Crafting",
			"DZ_Data"
		};
	};
};

class CfgVehicles
{
	class Inventory_Base;
	class Container_Base;
	class Barrel_ColorBase;
	class BarrelHoles_ColorBase;
	
	//============================================Barrel Seat==============================================>
	
	class BRP_BarrelChair_Avgas: Container_Base
	{
		scope=2;
		color="Avgas";
		displayName="Barrel Chair";
		descriptionShort="A comfy seat crafted from an oil barrel.";
		model="BastionMod\BastionBarrelFurniture_Data\BRP_BarrelChair\BRP_BarrelChair.p3d";
		heavyItem=1;
		weight=10000;
		itemSize[]={10,15};
		itemsCargoSize[]={10,8};
		physLayer="item_large";
		reversed=2;
		itemBehaviour=2;
		hiddenSelections[]=
		{
			"OilDrumSeat"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionBarrelFurniture_Data\data\BRP_BarrelChair_Avgas_co.paa"
		};
	};
	class BRP_BarrelChair_Green: BRP_BarrelChair_Avgas
	{
		scope=2;
		color="Green";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionBarrelFurniture_Data\data\BRP_BarrelChair_Green_co.paa"
		};
	};
	class BRP_BarrelChair_Blue: BRP_BarrelChair_Avgas
	{
		scope=2;
		color="Blue";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionBarrelFurniture_Data\data\BRP_BarrelChair_Blue_co.paa"
		};
	};
	class BRP_BarrelChair_Red: BRP_BarrelChair_Avgas
	{
		scope=2;
		color="Red";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionBarrelFurniture_Data\data\BRP_BarrelChair_Red_co.paa"
		};
	};
	class BRP_BarrelChair_Yellow: BRP_BarrelChair_Avgas
	{
		scope=2;
		color="Yellow";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionBarrelFurniture_Data\data\BRP_BarrelChair_Yellow_co.paa"
		};
	};
	class BRP_BarrelChair_Danmak: BRP_BarrelChair_Avgas
	{
		scope=2;
		color="Danmak";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionBarrelFurniture_Data\data\BRP_BarrelChair_Danmak_co.paa"
		};
	};
	
	//============================================Barrel Table=============================================>
	
	class BRP_BarrelTable_Danmak: Container_Base
	{
		scope=2;
		color="Danmak";
		displayName="Barrel Table";
		descriptionShort="A table crafted from an oil barrel.";
		model="BastionMod\BastionBarrelFurniture_Data\BRP_BarrelTable\BRP_BarrelTable.p3d";
		heavyItem=1;
		weight=10000;
		itemSize[]={10,15};
		itemsCargoSize[]={10,8};
		physLayer="item_large";
		itemBehaviour=2;
		hiddenSelections[]=
		{
			"OilDrumTable"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionBarrelFurniture_Data\data\BRP_BarrelTable_Danmak_ca.paa"
		};
	};
	class BRP_BarrelTable_Green: BRP_BarrelTable_Danmak
	{
		scope=2;
		color="Green";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionBarrelFurniture_Data\data\BRP_BarrelTable_Green_ca.paa"
		};
	};
	class BRP_BarrelTable_Blue: BRP_BarrelTable_Danmak
	{
		scope=2;
		color="Blue";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionBarrelFurniture_Data\data\BRP_BarrelTable_Blue_ca.paa"
		};
	};
	class BRP_BarrelTable_Red: BRP_BarrelTable_Danmak
	{
		scope=2;
		color="Red";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionBarrelFurniture_Data\data\BRP_BarrelTable_Red_ca.paa"
		};
	};
	class BRP_BarrelTable_Yellow: BRP_BarrelTable_Danmak
	{
		scope=2;
		color="Yellow";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionBarrelFurniture_Data\data\BRP_BarrelTable_Yellow_ca.paa"
		};
	};
	class BRP_BarrelTable_Avgas: BRP_BarrelTable_Danmak
	{
		scope=2;
		color="Avgas";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionBarrelFurniture_Data\data\BRP_BarrelTable_Avgas_ca.paa"
		};
	};
	
	//=========================================Barrel Table Cactus==========================================>
	
	class BRP_BarrelTableCactus: Inventory_Base
	{
		scope=2;
		displayName="Cactus";
		descriptionShort="A decorative table cactus.";
		model="BastionMod\BastionBarrelFurniture_Data\BRP_BarrelTableCactus\BRP_BarrelTableCactus.p3d";
		weight=100;
		itemSize[]={2,2};
		itemsCargoSize[]={1,1};
		itemBehaviour=2;
	};
	
	//==============================================BRP Barrel==============================================>	
	
	class BRP_Barrel_Danmak: Barrel_ColorBase
	{
		scope=2;
		color="Danmak";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionBarrelFurniture_Data\data\BRP_Barrel_Danmak_co.paa"
		};
		hologramMaterial="barrel";
		hologramMaterialPath="dz\gear\containers\data";
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
								"DZ\gear\containers\data\Barrel_yellow.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\containers\data\Barrel_yellow.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\containers\data\Barrel_yellow_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\containers\data\Barrel_yellow_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\containers\data\Barrel_yellow_destruct.rvmat"
							}
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
						damage=0;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0;
					};
				};
			};
		};
	};
	class BarrelHoles_Danmak: BarrelHoles_ColorBase
	{
		scope=2;
		color="Danmak";
		hiddenSelectionsTextures[]=
		{
			"\dz\gear\cooking\data\stoneground_co.paa",
			"BastionMod\BastionBarrelFurniture_Data\data\BRP_Barrel_Danmak_co.paa",
			"BastionMod\BastionBarrelFurniture_Data\data\BRP_Barrel_Danmak_co.paa"
		};
		hologramMaterial="Barrel";
		hologramMaterialPath="dz\gear\containers\data";
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
								"DZ\gear\cooking\data\Barrel_yellow_holes.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\cooking\data\Barrel_yellow_holes.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\cooking\data\Barrel_yellow_holes_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\cooking\data\Barrel_yellow_holes_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\cooking\data\Barrel_yellow_holes_destruct.rvmat"
							}
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
						damage=0;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0;
					};
				};
			};
		};
	};
	class BRP_Barrel_Avgas: Barrel_ColorBase
	{
		scope=2;
		color="Avgas";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionBarrelFurniture_Data\data\BRP_Barrel_Avgas_co.paa"
		};
		hologramMaterial="barrel";
		hologramMaterialPath="dz\gear\containers\data";
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
								"DZ\gear\containers\data\Barrel_red.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\containers\data\Barrel_red.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\containers\data\Barrel_red_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\containers\data\Barrel_red_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\containers\data\Barrel_red_destruct.rvmat"
							}
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
						damage=0;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0;
					};
				};
			};
		};
	};
	class BarrelHoles_Avgas: BarrelHoles_ColorBase
	{
		scope=2;
		color="Avgas";
		hiddenSelectionsTextures[]=
		{
			"\dz\gear\cooking\data\stoneground_co.paa",
			"BastionMod\BastionBarrelFurniture_Data\data\BRP_Barrel_Avgas_co.paa",
			"BastionMod\BastionBarrelFurniture_Data\data\BRP_Barrel_Avgas_co.paa"
		};
		hologramMaterial="Barrel";
		hologramMaterialPath="dz\gear\containers\data";
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
								"DZ\gear\cooking\data\Barrel_red_holes.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\cooking\data\Barrel_red_holes.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\cooking\data\Barrel_red_holes_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\cooking\data\Barrel_red_holes_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\cooking\data\Barrel_red_holes_destruct.rvmat"
							}
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
						damage=0;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0;
					};
				};
			};
		};
	};	
};
