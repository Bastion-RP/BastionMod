class CfgPatches
{
	class BRP_Magazine
	{
		units[]=
		{
			"BRP_Magazine"
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Gear_Books"
		};
	};
};

class CfgVehicles
{		
	class ItemBook;
	class BRP_Magazine: ItemBook
	{
		scope=0; //should be 0 because it's a base class for inheriting from it
		model="\BastionMod\BastionCrafting_Data\BRP_Magazine\BRP_Magazine.p3d"; //path to the model
		displayName="Crafted Magazine"; //name, actually
		descriptionShort="A Crafted Magazine to read"; //description
		itemSize[]={2,2}; //item size
		weight = 500; //weight? 
		rotationFlags=17; //how this item will be rotated on respawn and when it was dropped
		absorbency=0.9; //water absorbency
		physLayer="item_small"; // small = no collision
		hiddenSelections[]= // selection for retexturing
		{
			"all"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionCrafting_Data\BRP_Magazine\textures\brp_magazine_co.paa" // path to the texture
		};
		class DamageSystem //damage states
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
					healthLevels[]=
					{
						{1.0,{"BastionMod\BastionCrafting_Data\BRP_Magazine\data\brp_magazine.rvmat"}},
						{0.7,{"BastionMod\BastionCrafting_Data\BRP_Magazine\data\brp_magazine.rvmat"}},
						{0.5,{"BastionMod\BastionCrafting_Data\BRP_Magazine\data\brp_magazine_damage.rvmat"}},
						{0.3,{"BastionMod\BastionCrafting_Data\BRP_Magazine\data\brp_magazine_damage.rvmat"}},
						{0.0,{"BastionMod\BastionCrafting_Data\BRP_Magazine\data\brp_magazine_destruct.rvmat"}}
					};
				};
			};
		};
	};
	class BRP_ExapleMagazine: BRP_Magazine // we are inherit every parameter from our base class above, we don't need to fill every parameter now
	{
		scope=2; //2 because it's real item for gameplay
		displayName="Guide for Cipher"; //name, actually
		descriptionShort="Few steps about how to become cool modder."; //description
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionCrafting_Data\BRP_Magazine\textures\brp_NEWTEXTURE_co.paa" // path to the NEW texture
		};
	};	
};