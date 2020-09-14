class CfgPatches
{
	class Wetsuit
	{
		units[]=
		{};		
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
	class Clothing_Base;
	class Clothing: Clothing_Base {};
	class Wetsuit_Base: Clothing
	{
		scope=2;
		displayName="Wetsuit";
		descriptionShort="A neoprene garment worn to provide thermal protection while wet.";
		model="\BastionMod\BastionClothing\Wetsuit\wetsuit_g.p3d";
		inventorySlot="Body";
		simulation="clothing";
		vehicleClass="Clothing";
		itemInfo[]=
		{
			"Clothing",
			"Body"
		};
		weight=3600;
		itemSize[]={4,3};
		itemsCargoSize[]={0,0};
		quickBarBonus=1;
		ragQuantity=6;
		absorbency=1;
		heatIsolation=1.0;
		repairableWithKits[]={5,2};
		repairCosts[]={30,25};
		soundAttType="WoolShirt";
        hiddenSelections[]=
        {
			"camomale",
			"camofemale",
			"personality"
        };
		class ClothingTypes
		{
			male="\BastionMod\BastionClothing\Wetsuit\wetsuit_m.p3d";
			female="\BastionMod\BastionClothing\Wetsuit\wetsuit_f.p3d";
		};
       hiddenSelectionsTextures[]=
        {
            "\BastionMod\BastionClothing\Wetsuit\data\wetsuit_m_black_co.paa",
            "\BastionMod\BastionClothing\Wetsuit\data\wetsuit_f_black_co.paa",
            "\BastionMod\BastionClothing\Wetsuit\data\wetsuit_m_black_co.paa"
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
                        {1.0,{"BastionMod\BastionClothing\Wetsuit\data\wetsuit_m.rvmat", "BastionMod\BastionClothing\Wetsuit\data\wetsuit_f.rvmat", "BastionMod\BastionClothing\Wetsuit\data\wetsuit_m.rvmat"}},
                        {0.7,{"BastionMod\BastionClothing\Wetsuit\data\wetsuit_m.rvmat", "BastionMod\BastionClothing\Wetsuit\data\wetsuit_f.rvmat", "BastionMod\BastionClothing\Wetsuit\data\wetsuit_m.rvmat"}},
                        {0.5,{"BastionMod\BastionClothing\Wetsuit\data\wetsuit_m_damaged.rvmat", "BastionMod\BastionClothing\Wetsuit\data\wetsuit_f_damaged.rvmat", "BastionMod\BastionClothing\Wetsuit\data\wetsuit_m_damaged.rvmat"}},
                        {0.3,{"BastionMod\BastionClothing\Wetsuit\data\wetsuit_m_badlydamaged.rvmat", "BastionMod\BastionClothing\Wetsuit\data\wetsuit_f_badlydamaged.rvmat", "BastionMod\BastionClothing\Wetsuit\data\wetsuit_m_badlydamaged.rvmat"}},
                        {0.0,{"BastionMod\BastionClothing\Wetsuit\data\wetsuit_m_ruined.rvmat", "BastionMod\BastionClothing\Wetsuit\data\wetsuit_f_ruined.rvmat", "BastionMod\BastionClothing\Wetsuit\data\wetsuit_m_ruined.rvmat"}}};
                };
            };
			class GlobalArmor
			{
				class Projectile
				{
					Health=0.89999998;
					Blood=0.89999998;
					Shock=0.89999998;
				};
				class Melee
				{
					Health=0.89999998;
					Blood=0.89999998;
					Shock=0.89999998;
				};
				class Infected
				{
					Health=0.89999998;
					Blood=0.89999998;
					Shock=0.89999998;
				};
			};
        };	
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet="Shirt_pickup_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="Shirt_drop_SoundSet";
					id=898;

				};
			};
		};
	};
	class Invisible_Pants: Clothing_Base
	{
		scope = 2; // wont see this in game
		displayName="";
		descriptionShort="";
		model="BastionMod\BastionClothing\Wetsuit\invisible_pants.p3d";
		inventorySlot="Legs";
		simulation="clothing";
		itemInfo[]=
		{
			"Clothing",
			"Legs"
		};
		itemSize[]={3,2};
		weight=0;
	};
};