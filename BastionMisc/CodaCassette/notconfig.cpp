class CfgPatches
{
	class BRPRPRadio
	{
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data"
		};
	};
};
class CfgSlots
{
	class Slot_codacassette
	{
		name="coda_cassette";
		displayName="coda_cassette";
		ghostIcon="missing";
		show="true";
	};
};
class cfgVehicles
{
	class Inventory_Base;
	class Item_Base;
	class BRP_cassetteradio: Inventory_Base
	{
		scope=2;
		displayName="Radio";
		descriptionShort="A battery powered radio. Seems to be in working condition. Just needs a tape and battery.";
		model="\dz\gear\radio\unitra_wilga.p3d";
		animClass="Knife";
		weight=1700;
		itemSize[]={2,3};
		fragility=0.0099999998;
		absorbency=0.5;
		attachments[]=
		{
			"BatteryD",
			"coda_cassette"
		};
		oldpower=0;//What is this?
		repairableWithKits[]={5,7};
		repairCosts[]={30,25};
		class EnergyManager
		{
			hasIcon=1;
			autoSwitchOff=1;
			energyUsagePerSecond=0.02;
			attachmentAction=1;
			wetnessExposure=0.1;
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
								"DZ\gear\radio\data\unitra_wilga.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\radio\data\unitra_wilga.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\radio\data\unitra_wilga_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\radio\data\unitra_wilga_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\radio\data\unitra_wilga_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class MeleeModes
		{
			class Default
			{
				ammo="MeleeLightBlunt";
				range=1;
			};
			class Heavy
			{
				ammo="MeleeLightBlunt_Heavy";
				range=1;
			};
			class Sprint
			{
				ammo="MeleeLightBlunt_Heavy";
				range=2.8;
			};
		};
	};

	class BRP_cassette_base: Inventory_Base
	{
		scope=0;
		displayName="Cassette";
		descriptionShort="Cassette Description";
		model="\dz\gear\tools\cassette.p3d";
		inventorySlot[]=
		{
			"coda_cassette"
		};
		rotationFlags=17;
		weight=80;
		absorbency=0.5;
		itemSize[]={2,1};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=10;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\gear\tools\data\cassette.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\tools\data\cassette.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\tools\data\cassette_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\tools\data\cassette_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\tools\data\cassette_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class MeleeModes
		{
			class Default
			{
				ammo="MeleeLightBlunt";
				range=1;
			};
			class Heavy
			{
				ammo="MeleeLightBlunt_Heavy";
				range=1;
			};
			class Sprint
			{
				ammo="MeleeLightBlunt_Heavy";
				range=2.8;
			};
		};
	};
//These 4 songs are non copyright or royalty music
	class BRP_cassette_alanwalkerfade: BRP_cassette_base
	{
		scope=2;
		displayName="Alan Walker - Fade";
		descriptionShort="Alan Walker - Fade";
	};

	class BRP_cassette_darkmusicfatallullaby: BRP_cassette_base
	{
		scope=2;
		displayName="Dark Music - Fatal Lullaby";
		descriptionShort="Dark Music - Fatal Lullaby by Adrian von Ziegler";
	};

	class BRP_cassette_onlypianoloneliness: BRP_cassette_base
	{
		scope=2;
		displayName="Only Piano - Loneliness";
		descriptionShort="Only Piano - Loneliness by Adrian von Ziegler";
	};

	class BRP_cassette_cartoonwhywelose: BRP_cassette_base
	{
		scope=2;
		displayName="Cartoon - Why We Lose";
		descriptionShort="Cartoon - Why We Lose (feat. Coleman Trapp)";
	};

};
