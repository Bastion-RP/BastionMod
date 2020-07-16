class CfgPatches
{
	class ISFShield
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data"
		};
		
	
	};
};

class cfgVehicles
{
	class Inventory_Base;
	class torch: Inventory_Base
	{
	};
	class BRP_ISFShield: torch
	{
		model="BastionMod\Shield\BRP_ISFShield.p3d";
		scope=2;
		displayName="ISFShield";
		descriptionShort="ISFShield";

		overrideDrawArea="8.0";
		rotationFlags=17;
		absorbency=0.5;
		isMeleeWeapon=1;

		canBeSplit=0;
		stackedUnit="";
		quantityBar=0;


		weight=90000;
		itemSize[]={5,10};
		attachments[]=
		{
			""
		};
		hiddenSelections[]=
		{
			""
		};
		hiddenSelectionsTextures[]=
		{
			"",
			""
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
							1,
							
							{
								"DZ\gear\crafting\data\torch.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\crafting\data\torch.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\crafting\data\torch_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\crafting\data\torch_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\crafting\data\torch_destruct.rvmat"
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
				range=1.6;
			};
			class Heavy
			{
				ammo="MeleeLightBlunt_Heavy";
				range=1.6;
			};
			class Sprint
			{
				ammo="MeleeLightBlunt_Heavy";
				range=2.2;
			};
			class Default_SwitchedOn
			{
				ammo="MeleeLightBluntShock";
				range=1.6;
			};
			class Heavy_SwitchedOn
			{
				ammo="MeleeLightBluntShock_Heavy";
				range=1.6;
			};
			class Sprint_SwitchedOn
			{
				ammo="MeleeLightBluntShock_Heavy";
				range=2.2;
			};
		};
		
		
	};
	
};


