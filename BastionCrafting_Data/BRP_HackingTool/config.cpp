class CfgPatches
{
	class BRP_HackingTool
	{
		units[]=
		{
			"BRP_HackingTool"
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data"
		};
	};
	
};

class CfgVehicles
{		
	class Inventory_Base;
	
	class Book_Base;
	class ItemBook: Book_Base{};
	class BRP_HackingTool: ItemBook
	{
		scope=2;
		model="\BastionMod\BastionCrafting_Data\BRP_HackingTool\BRP_HackingTool.p3d";
		displayName="Hacking Tool";
		descriptionShort="A computer device, useful for a variety of purposes.";
		itemSize[]={2,2};
		weight = 500;
		rotationFlags=1;
		absorbency=0.89999998;
		physLayer="item_small";
		hiddenSelections[]=
		{
			"all"
		};
		hiddenSelectionsTextures[]=
		{
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
								"BastionMod\BastionCrafting_Data\BRP_Magazine\data\brp_magazine.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"BastionMod\BastionCrafting_Data\BRP_Magazine\data\brp_magazine.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"BastionMod\BastionCrafting_Data\BRP_Magazine\data\brp_magazine_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"BastionMod\BastionCrafting_Data\BRP_Magazine\data\brp_magazine_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"BastionMod\BastionCrafting_Data\BRP_Magazine\data\brp_magazine_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		
	};

	class BRP_HackingTool_Spec : BRP_HackingTool
	{
		scope=2;
		displayName="Advanced Hacking Tool";
	}
};